#include "dom_tree.h"
#include "attribute.h"
#include "serialize_variables.h"

namespace HIRMutate
{
    vector<string> merge_blacklist;
}
void HIRMutate::initMerge_blacklist()
{
    MERGE_BLACKLIST("SVGAnimateElement")
    MERGE_BLACKLIST("SVGAnimateMotionElement");
    MERGE_BLACKLIST("SVGAnimateTransformElement")
    MERGE_BLACKLIST("SVGSetElement")
}

HIRMutate::DOMTree::DOMTree(int max_element_count)
{
    root_svg = nullptr;
    element_count = 0;
    this->max_element_count = max_element_count;
#ifdef DEBUG_MEM
    std::cout << "DOMTree(" << max_element_count << ")" << std::endl;
#endif
}

HIRMutate::DOMTree::~DOMTree()
{
#ifdef DEBUG_MEM
    std::cout << "~DOMTree(" << max_element_count << ")" << std::endl;
#endif
    std::for_each(root_elements.begin(), root_elements.end(),
                  [](Element *elem)
                  {
                      delete elem;
                  });
}

vector<HIRMutate::Element *> HIRMutate::DOMTree::get_elements()
{
    vector<Element *> elements = root_elements;
    std::for_each(root_elements.begin(), root_elements.end(),
                  [&elements, this](Element *elem)
                  {
                      this->get_child(elem, elements);
                  });

    return elements;
}

bool HIRMutate::DOMTree::full()
{
    return element_count >= max_element_count;
}

void HIRMutate::DOMTree::add_root_element(Element *element)
{
    int index = Random::selector(root_elements.size() + 1);
    root_elements.insert(root_elements.begin() + index, element);
    element->tree_depth = 0;
}

void HIRMutate::DOMTree::add_root_svg_element(DOMContext *context)
{
    SVGElement *svg = (SVGElement *)Factory::create_object("SVGSVGElement");
    add_root_element(svg);
    init_element(context, svg);
    root_svg = svg;
}

void HIRMutate::DOMTree::init_element(DOMContext *context, Element *element)
{
    context->add_object(element);
    element->generate_mandatory_attributes(context);
    element_count += 1;
}

/*
* For dumb fuzz
*/
void HIRMutate::DOMTree::generate_html_elements(DOMContext *context, int count)
{
    for (int i = 0; i < count; i++)
    {
        HTMLElement *element = (HTMLElement *)insert_root_element(context);
        element->generate_text();
    }
}

void HIRMutate::DOMTree::generate_svg_elements(DOMContext *context, int count)
{
    add_root_svg_element(context);
    for (int i = 0; i < count; i++)
    {
        SVGElement *child = (SVGElement *)(root_svg->insert_child());
        if (child != nullptr)
        {
            init_element(context, child);
            child->generate_text();
        }
    }
}

void HIRMutate::DOMTree::generate_nodes(DOMContext *context)
{
    if (Random::gbool())
        generate_html_elements(context, TreeConfig::root_element_count);
    else
    {
        generate_html_elements(context, TreeConfig::root_element_count);
        generate_svg_elements(context, TreeConfig::root_element_count);
    }

    for (int i = 0; i < max_element_count; i++)
    {
        Element *element = insert_element(context);
        if (element != nullptr)
            element->generate_text();
    }
}

void HIRMutate::DOMTree::generate_attributes(DOMContext *context)
{
    vector<HIRMutate::Element *> elements = this->get_elements();
    std::for_each(elements.begin(), elements.end(),
                  [&context](Element *element)
                  {
                      element->generate_attributes(context);
                  });
}

/*
* For cov fuzz
*/
// T1
HIRMutate::Element *HIRMutate::DOMTree::insert_element(DOMContext *context)
{
    if (full())
        return nullptr;

    vector<Element *> parents;
    vector<HIRMutate::Element *> elements = this->get_elements();
    std::for_each(elements.begin(), elements.end(),
                  [&parents](Element *element)
                  {
                      if (element->tree_depth < TreeConfig::max_depth)
                      {
                          parents.push_back(element);
                      }
                  });
    int trial = 0;
    while (trial < parents.size())
    {
        Element *parent = CHOICE_OBJ(parents);
        Element *child = parent->insert_child();
        if (child != nullptr)
        {
            init_element(context, child);
            return child;
        }
        trial++;
    }
    return nullptr;
}

// T2
HIRMutate::Element *HIRMutate::DOMTree::insert_root_element(DOMContext *context)
{
    if (full())
        return nullptr;
    string name;
    if (Random::selector(5) > 0)
        name = CHOICE_OBJ(DOC::html_general_child_elements);
    else
        name = CHOICE_OBJ(DOC::html_other_child_elements);
    Element *child = (Element *)Factory::create_object(name);
    if (child != nullptr)
    {
        add_root_element(child);
        init_element(context, child);
        return child;
    }
    else
    {
        return nullptr;
    }
}

// T3
bool HIRMutate::DOMTree::append_attribute(DOMContext *context)
{

    if (element_count == 0)
        return false;
    vector<HIRMutate::Element *> elements = this->get_elements();
    int trial = 0;
    while (trial < element_count)
    {
        Element *element = CHOICE_OBJ(elements);
        if (Attribute::get_attribute_count(element->name) > 0 && element->append_attribute(context))
            return true;
        trial++;
    }
    return false;
}

// T4
bool HIRMutate::DOMTree::mutate_attribute(DOMContext *context)
{
    if (element_count == 0)
        return false;
    vector<HIRMutate::Element *> elements = this->get_elements();
    int trial = 0;
    while (trial < element_count)
    {
        Element *element = CHOICE_OBJ(elements);
        if (element->mutate_attribute(context))
            return true;
        trial++;
    }
    return false;
}

// T5
bool HIRMutate::DOMTree::replace_attribute(DOMContext *context)
{
    if (element_count == 0)
        return false;
    vector<HIRMutate::Element *> elements = this->get_elements();
    int trial = 0;
    while (trial < element_count)
    {
        Element *element = CHOICE_OBJ(elements);
        if (element->replace_attribute(context))
            return true;
        trial++;
    }
    return false;
}

// T6
bool HIRMutate::DOMTree::mutate_text()
{
    if (element_count == 0)
        return false;
    vector<HIRMutate::Element *> elements = this->get_elements();
    int trial = 0;
    while (trial < element_count)
    {
        Element *element = CHOICE_OBJ(elements);
        if (element->mutate_text())
            return true;
        trial++;
    }
    return false;
}

bool HIRMutate::DOMTree::allow_merge()
{
    return element_count <= max_element_count;
}

void HIRMutate::DOMTree::get_child(Element *element, vector<Element *> &all_childs)
{
    std::for_each(element->children.begin(), element->children.end(),
                  [&all_childs, this](Element *child)
                  {
                      all_childs.push_back(child);
                      this->get_child(child, all_childs);
                  });
}

void HIRMutate::DOMTree::do_merge(Element *element, DOMContext *context, Element *other_element, map<Object *, Object *> &merge_map, vector<Object *> &merge_map_values, vector<Element *> &merge_inserts)
{
    // 1. merge two roots
    merge_map[other_element] = element;
    element->merge_attributes(other_element);

    // 2. try to merge children
    std::for_each(other_element->children.begin(), other_element->children.end(),
                  [&element, &merge_map_values, &merge_inserts, &context, &merge_map, this](Element *other_child)
                  {
                      // 2.1 find the children with the same name
                      bool ok = false;
                      if (find(merge_blacklist.begin(), merge_blacklist.end(), other_child->name) == merge_blacklist.end())
                      {
                          std::for_each(element->children.begin(), element->children.end(),
                                        [&ok, &merge_map_values, &merge_inserts, &other_child, &context, &merge_map, this](Element *child)
                                        {
                                            if (find(merge_map_values.begin(), merge_map_values.end(), child) == merge_map_values.end() && find(merge_inserts.begin(), merge_inserts.end(), child) == merge_inserts.end() && child->name == other_child->name)
                                            {
                                                this->do_merge(child, context, other_child, merge_map, merge_map_values, merge_inserts);
                                                ok = true;
                                            }
                                        });
                      }

                      if (!ok)
                      {
                          // 2.2 fail to find, directly insert
                          element->add_child(other_child);
                          vector<Element *> all_childs;
                          get_child(other_child, all_childs);
                          std::for_each(all_childs.begin(), all_childs.end(),
                                        [&merge_inserts, &context, this](Element *other_offspring)
                                        {
                                            merge_inserts.push_back(other_offspring);
                                            other_offspring->id = "";
                                            other_offspring->fix_depth();
                                            context->add_object(other_offspring);
                                            this->element_count++;
                                        });
                      }
                  });
}

vector<HIRMutate::Element *> HIRMutate::DOMTree::merge(DOMContext *context, DOMTree *other, map<Object *, Object *> &merge_map)
{
    vector<Element *> merge_inserts;
    vector<HIRMutate::Element *> elements = this->get_elements();
    vector<Object *> merge_map_values;
    std::for_each(merge_map.begin(), merge_map.end(),
                  [&merge_map_values](map<Object *, Object *>::reference i)
                  {
                      merge_map_values.push_back(i.second);
                  });
    std::for_each(other->root_elements.begin(), other->root_elements.end(),
                  [this, &elements, &merge_map_values, &merge_inserts, &context, &merge_map](Element *other_root_element)
                  {
                      bool ok = false;
                      if (find(merge_blacklist.begin(), merge_blacklist.end(), other_root_element->name) == merge_blacklist.end())
                      {
                          std::for_each(elements.begin(), elements.end(),
                                        [&ok, this, &merge_map_values, &merge_inserts, &other_root_element, &context, &merge_map](Element *element)
                                        {
                                            if (find(merge_map_values.begin(), merge_map_values.end(), element) == merge_map_values.end() && find(merge_inserts.begin(), merge_inserts.end(), element) == merge_inserts.end() && element->name == other_root_element->name)
                                            {
                                                this->do_merge(element, context, other_root_element, merge_map, merge_map_values, merge_inserts);
                                                ok = true;
                                            }
                                        });
                      }
                      if (!ok)
                      {
                          // fail to find, directly insert
                          add_root_element(other_root_element);
                          vector<HIRMutate::Element *> all_childs;
                          this->get_child(other_root_element, all_childs);
                          std::for_each(all_childs.begin(), all_childs.end(),
                                        [&merge_inserts, this, &context](Element *other_offspring)
                                        {
                                            merge_inserts.push_back(other_offspring);
                                            other_offspring->id = "";
                                            other_offspring->fix_depth();
                                            context->add_object(other_offspring);
                                            this->element_count++;
                                        });
                      }
                  });

    return merge_inserts;
}

HIRMutate::DOMTree::operator string()
{
    string s = "";
    std::for_each(root_elements.begin(), root_elements.end(),
                  [&s](Element *element)
                  {
                      s.append(element->operator string());
                      s.append("\n");
                  });
    return s;
}

//序列化
void HIRMutate::DOMTree::serialize(SerializeStream *stream, Context *context)
{
    stream->write_int(element_count);
    stream->write_int(max_element_count);
    stream->write_int(root_elements.size());
    std::for_each(root_elements.begin(), root_elements.end(),
                  [&stream, &context](Element *elem)
                  {
                      elem->serialize_weak(stream, context);
                  });
    if (root_svg != nullptr)
        root_svg->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}

void HIRMutate::DOMTree::unserialize(UnSerializeStream *stream, Document *global_document)
{
    element_count = stream->read_int();
    max_element_count = stream->read_int();
    int re_size = stream->read_int();
    root_elements.resize(re_size);
    for (int i = 0; i < re_size; i++)
    {
        stream->read_obj_ref((size_t)&root_elements[i], global_document);
    }
    if (stream->peek() == "nullptr")
    {
        root_svg = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&root_svg, global_document);
    }
}