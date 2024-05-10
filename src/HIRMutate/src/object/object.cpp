#include "object.h"
#include "assert.h"
#include "serialize_variables.h"

HIRMutate::Element::Element(const string &name) : Object(name)
{
    tag = "";
    parent = nullptr;
    tree_depth = -1;
    ahead_text = "";
    last_text = "";
#ifdef DEBUG_MEM
    std::cout << "Element(" << name << ")" << std::endl;
#endif
}
HIRMutate::Element::~Element()
{
    std::for_each(attributes.begin(), attributes.end(),
                  [](map<string, Attribute::Attribute *>::reference i)
                  {
                      Attribute::Attribute *attr = i.second;
                      delete attr;
                  });
    std::for_each(children.begin(), children.end(),
                  [](Element *e)
                  {
                      delete e;
                  });
#ifdef DEBUG_MEM
    std::cout << "~Element(" << name << ")" << std::endl;
#endif
}
int HIRMutate::Element::children_count()
{
    return children.size();
}

bool HIRMutate::Element::is_element()
{
    return true;
}

bool HIRMutate::Element::is_in_tree()
{
    return tree_depth != -1;
}

bool HIRMutate::Element::is_empty()
{
    return children_count() == 0;
}

int HIRMutate::Element::attribute_count()
{
    return attributes.size();
}

string HIRMutate::Element::additional_label()
{
    return "";
}

bool HIRMutate::Element::has_attribute(const string &name)
{
    return attributes.find(name) != attributes.end();
}
HIRMutate::Attribute::Attribute *HIRMutate::Element::get_attribute(const string &name)
{
    return attributes[name];
}

void HIRMutate::Element::add_attribute(Attribute::Attribute *attr)
{
    attributes[attr->name] = attr;
    attribute_names.push_back(attr->name);
}

void HIRMutate::Element::del_attribute(const string &name)
{
    delete attributes[name];
    attributes.erase(name);
    auto pos = find(attribute_names.begin(), attribute_names.end(), name);
    attribute_names.erase(pos);
}
void HIRMutate::Element::add_child(Element *child)
{
    //always insert into a random location :)
    int index = Random::selector(children.size() + 1);
    child->parent = this;
    child->tree_depth = tree_depth + 1;
    children.insert(children.begin() + index, child);
}

bool HIRMutate::Element::mutate_text()
{
    printf("NotImplementedError\n");
    return false;
}

HIRMutate::Attribute::Attribute *HIRMutate::Element::generate_attribute(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template)
{
    Attribute::Attribute *attr = a_template->instantiate();
    attr->generate(context);
    return attr;
}

void HIRMutate::Element::generate_mandatory_attributes(DOMContext *context)
{
    if (Attribute::mandatory_attributes.find(name) != Attribute::mandatory_attributes.end())
    {
        vector<Attribute::AttributeTemplate::ptr> &templates = Attribute::mandatory_attributes[name];

        std::for_each(templates.begin(), templates.end(),
                      [&context, this](Attribute::AttributeTemplate::ptr &a_template)
                      {
                          if (!has_attribute(a_template->attr))
                          {
                              Attribute::Attribute *attr = this->generate_attribute(context, a_template);
                              if (attr != nullptr)
                              {
                                  add_attribute(attr);
                                  attr->mandatory = true;
                              }
                          }
                      });
    }
}

/*
* For dumb fuzz
*/
void HIRMutate::Element::generate_attributes(DOMContext *context)
{
    int avail_attr_count = Attribute::get_attribute_count(name);
    int total_count;
    if (avail_attr_count >= 20)
        total_count = TreeConfig::max_attribute_count;
    else if (avail_attr_count >= 10)
        total_count = Random::range(5, avail_attr_count);
    else if (avail_attr_count >= 1)
        total_count = Random::range(1, avail_attr_count);
    else
        total_count = 0;
    for (int i = 0; i < total_count; i++)
        append_attribute(context);
}

/*
* For cov fuzz
*/
bool HIRMutate::Element::append_attribute(DOMContext *context)
{
    if (attribute_count() >= TreeConfig::max_attribute_count)
        return false;

    vector<Attribute::AttributeTemplate::ptr> &templates = Attribute::get_attribute_templates(name);
    if (templates.size() == 0)
    {
        return false;
    }
    //assert(templates.size() > 0);

    int trial = 0;
    while (trial < 10)
    {
        Attribute::AttributeTemplate::ptr a_template = CHOICE_OBJ(templates);
        if (!has_attribute(a_template->attr))
        {
            Attribute::Attribute *attr = generate_attribute(context, a_template);
            if (attr != nullptr)
            {
                add_attribute(attr);
                return true;
            }
        }
        trial++;
    }
    return false;
}

bool HIRMutate::Element::mutate_attribute(DOMContext *context)
{
    if (attribute_count() == 0)
        return false;

    int trial = 0;
    while (trial < attribute_count())
    {
        string &name = CHOICE_OBJ(attribute_names);
        Attribute::Attribute *attribute = attributes[name];
        if (!attribute->mandatory)
        {
            attribute->mutate(context);
            return true;
        }
        trial++;
    }
    return false;
}

bool HIRMutate::Element::replace_attribute(DOMContext *context)
{
    if (attribute_count() == 0)
        return false;

    int trial = 0;
    while (trial < attribute_count())
    {
        string &name = CHOICE_OBJ(attribute_names);
        Attribute::Attribute *attribute = attributes[name];
        if (!attribute->mandatory)
        {
            del_attribute(name);
            return append_attribute(context);
        }
        trial += 1;
    }
    return false;
}

void HIRMutate::Element::merge_attributes(Element *other)
{
    std::for_each(other->attributes.begin(), other->attributes.end(),
                  [this](map<string, Attribute::Attribute *>::reference i)
                  {
                      const string &name = i.first;
                      if (!this->has_attribute(name))
                      {
                          this->add_attribute(i.second);
                      }
                  });
}

void HIRMutate::Element::fix_depth()
{
    if (parent != nullptr)
        tree_depth = parent->tree_depth + 1;
}

void HIRMutate::Element::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(attributes.begin(), attributes.end(),
                  [&merge_map](map<string, Attribute::Attribute *>::reference i)
                  {
                      Attribute::Attribute *attr = i.second;
                      attr->merge_fix(merge_map);
                  });
}

HIRMutate::Element::operator string()
{
    string s = "";
    if (ahead_text != "")
    {
        s.append(ahead_text);
        s.append("\n");
    }
    s.append("<");
    s.append(tag);
    s.append(" id=\"");
    s.append(id);
    s.append("\"");
    s.append(additional_label());
    std::for_each(attributes.begin(), attributes.end(),
                  [&s](map<string, Attribute::Attribute *>::reference i)
                  {
                      Attribute::Attribute *attr = i.second;
                      string attr_str = attr->operator string();
                      s.append(" ");
                      s.append(attr_str);
                  });

    if (DOC::is_html_empty_element(name))
    {
        s.append("/>");
        //assert(children_count == 0 && text == "")
        return s;
    }

    s.append(">\n");

    std::for_each(children.begin(), children.end(),
                  [&s](Element *e)
                  {
                      s.append(e->operator string());
                      s.append("\n");
                  });

    if (last_text != "")
    {
        s.append(last_text);
        s.append("\n");
    }
    s.append("</");
    s.append(tag);
    s.append(">");
    return s;
}

void HIRMutate::Object::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("Object");
    stream->write_string(id);
    stream->write_string(name);
}

void HIRMutate::Object::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "Object")
        {
            puts("Object::unserialize Error!");
            abort();
        }
    }
    id = stream->read_string();
    name = stream->read_string();
}

void HIRMutate::Object::serialize_weak(SerializeStream *stream, Context *context)
{
    std::pair<string, int> position = context->find_obj_in_pool(this);
    assert(position.second != -1);
    stream->write_string(position.first);
    stream->write_int(position.second);
}

void HIRMutate::Element::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("Element");
    Object::serialize(stream, context);
    stream->write_int(attributes.size());
    std::for_each(attributes.begin(), attributes.end(),
                  [&stream, &context](map<string, Attribute::Attribute *>::reference i)
                  {
                      stream->write_string(i.first);
                      i.second->serialize(stream, context);
                  });
    /*std::for_each(attribute_names.begin(), attribute_names.end(),
                  [&stream](string &val)
                  {
                      stream->write_string(val);
                  });*/
    stream->write_string(tag);
    if (parent != nullptr)
        parent->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
    stream->write_string(ahead_text);
    stream->write_string(last_text);
    stream->write_int(tree_depth);
    stream->write_int(children.size());
    std::for_each(children.begin(), children.end(),
                  [&stream, &context](Element *val)
                  {
                      val->serialize_weak(stream, context);
                  });
}

void HIRMutate::Element::unserialize(UnSerializeStream *stream, Document *global_document)
{
    if (stream->read_string() != "Element")
    {
        puts("Element::unserialize Error!");
        abort();
    }
    Object::unserialize(stream, global_document, true);
    int attr_size = stream->read_int();
    for (int i = 0; i < attr_size; i++)
    {
        string attr_name = stream->read_string();
        Attribute::Attribute *attr = new Attribute::Attribute();
        attr->unserialize(stream, global_document);
        attributes[attr_name] = attr;
        attribute_names.push_back(attr_name);
    }
    tag = stream->read_string();
    if (stream->peek() == "nullptr")
    {
        parent = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&parent, global_document);
    }
    ahead_text = stream->read_string();
    last_text = stream->read_string();
    tree_depth = stream->read_int();
    int children_size = stream->read_int();
    children.resize(children_size);
    for (int i = 0; i < children_size; i++)
    {
        stream->read_obj_ref((size_t)&children[i], global_document);
    }
}