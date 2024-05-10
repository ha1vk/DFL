#include "svg_obj.h"
#include <assert.h>
#include "serialize_variables.h"

int max(int a, int b)
{
    return a > b ? a : b;
}

HIRMutate::SVGElement::SVGElement(const string &name) : Element(name)
{
    tag = DOC::svg_tag_from_element(name);
}

HIRMutate::Element *HIRMutate::SVGElement::create(const string &name)
{
    if (name == "SVGAnimateElement" || name == "SVGAnimateMotionElement" || name == "SVGAnimateTransformElement" || name == "SVGSetElement")
        return new SVGAnimationElement(name);
    else if (find(DOC::svg_filter_primitives.begin(), DOC::svg_filter_primitives.end(), name) != DOC::svg_filter_primitives.end())
        return new SVGFilterPrimitive(name);
    else if (name == "SVGForeignObjectElement")
        return new SVGForeignObjectElement(name);
    else if (name == "SVGGlyphElement")
        return new SVGGlyphElement(name);
    else
        return new SVGElement(name);
}

HIRMutate::Element *HIRMutate::SVGElement::generate_child(const string &child_name)
{
    Element *child = SVGElement::create(child_name);
    add_child(child);
    return child;
}

void HIRMutate::SVGElement::generate_text()
{
    if (DOC::is_svg_text_element(name) && Random::selector(5) == 0)
        last_text = Random::gstring();
    if (parent == nullptr || DOC::is_svg_text_element(parent->name) && Random::selector(5) == 0)
        ahead_text = Random::gstring();
}

bool HIRMutate::SVGElement::mutate_text()
{
    if (Random::gbool())
    {
        if (DOC::is_svg_text_element(name))
        {
            last_text = Random::gstring();
            return true;
        }
        return false;
    }
    else
    {
        if (parent == nullptr || DOC::is_svg_text_element(parent->name))
        {
            ahead_text = Random::gstring();
            return true;
        }
        return false;
    }
}

HIRMutate::Element *HIRMutate::SVGElement::insert_child()
{
    vector<string> &children = DOC::svg_child_elements[name];

    if (children.size() == 0)
        return nullptr;

    string &child = CHOICE_OBJ(children);
    return generate_child(child);
}
void HIRMutate::SVGElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGElement");
    Element::serialize(stream, context);
}
void HIRMutate::SVGElement::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "SVGElement")
        {
            puts("SVGElement::unserialize Error!");
            abort();
        }
    }
    Element::unserialize(stream, global_document);
}
HIRMutate::SVGAnimationElement::SVGAnimationElement(const string &name) : SVGElement(name)
{
    value_class = nullptr;
    value_count = 0;
    type = "";

    if (name == "SVGAnimateMotionElement")
        value_class = HANDLE(SVG::CoordinateValue);
    if (name != "SVGSetElement")
    {
        if (Random::gbool())
            value_count = max(1, DOMValue::list_size());
    }
}

// SVGSetElement / SVGAnimateElement / SVGAnimateTransformElement
// FIXME: Now only mutate parent node
// FIXME: Now do not change mandatory attribute values when generating setAttribute()
HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_attribute_name(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    if (parent == nullptr)
        return nullptr;

    if (has_attribute("attributeName"))
    {
        Attribute::Attribute *exist = get_attribute("attributeName");
        Attribute::Attribute *attr = new Attribute::Attribute(name, "attributeName", new ConstValue(exist->value->getValue()));
        return attr;
    }

    Attribute::Attribute *attr = a_template->instantiate();
    Attribute::AttributeTemplate::ptr b_template;
    if (name == "SVGAnimateTransformElement")
        b_template = Attribute::get_svg_animatable_transform_attribute(parent->name);
    else
        b_template = Attribute::get_svg_animatable_attribute(parent->name);

    // setup value class
    if (name == "SVGAnimateElement" || name == "SVGSetElement")
        value_class = b_template->valueInstance;

    delete attr->value;
    attr->value = new ConstValue(b_template->attr);
    attr->generate(context);
    return attr;
}

// SVGAnimateTransformElement
HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_type(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    if (has_attribute("type"))
    {
        Attribute::Attribute *exist = get_attribute("type");
        Attribute::Attribute *attr = new Attribute::Attribute(name, "type", new ConstValue(exist->value->getValue()));
        return attr;
    }

    Attribute::Attribute *attr = a_template->instantiate();
    attr->generate(context);
    type = attr->value->getValue();
    if (type == "translate")
        value_class = HANDLE(SVG::TransformTranslateValue);
    else if (type == "scale")
        value_class = HANDLE(SVG::TransformScaleValue);
    else if (type == "rotate")
        value_class = HANDLE(SVG::TransformRotateValue);
    else
        value_class = HANDLE(SVG::TransformSkewXValue);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_value(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    Attribute::Attribute *attr = nullptr;
    if (value_class == nullptr)
        return attr;
    attr = a_template->instantiate();
    delete attr->value;
    attr->value = new SVG::FromValue(value_class);
    attr->generate(context);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_values(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{

    if (value_class == nullptr || value_count == 0)
        return nullptr;
    Attribute::Attribute *attr = a_template->instantiate();
    delete attr->value;
    attr->value = new SVG::AnimationValuesValue(value_class, value_count);
    attr->generate(context);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_key_splines(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    int value_count = this->value_count;
    if (value_count == 0)
        value_count = 2;
    Attribute::Attribute *attr = a_template->instantiate();
    delete attr->value;
    attr->value = new SVG::KeySplinesValue(value_count);
    attr->generate(context);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_key_points(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    int value_count = this->value_count;
    if (value_count == 0)
        value_count = 2;
    Attribute::Attribute *attr = a_template->instantiate();
    delete attr->value;
    attr->value = new SVG::KeyPointsValue(value_count);
    attr->generate(context);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_key_times(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    int value_count = this->value_count;
    if (value_count == 0)
        value_count = 2;
    Attribute::Attribute *attr = a_template->instantiate();
    delete attr->value;
    attr->value = new SVG::KeyTimesValue(value_count);
    attr->generate(context);
    return attr;
}

HIRMutate::Attribute::Attribute *HIRMutate::SVGAnimationElement::generate_attribute(DOMContext *context, HIRMutate::Attribute::AttributeTemplate::ptr &a_template)
{
    string attr_name = a_template->attr;
    if (attr_name == "attributeName")
        return generate_attribute_name(context, a_template);
    else if (attr_name == "type")
        return generate_type(context, a_template);
    else if (attr_name == "from" || attr_name == "to" || attr_name == "by")
        return generate_value(context, a_template);
    else if (attr_name == "values")
        return generate_values(context, a_template);
    else if (attr_name == "keySplines")
        return generate_key_splines(context, a_template);
    else if (attr_name == "keyTimes")
        return generate_key_times(context, a_template);
    else if (attr_name == "keyPoints")
        return generate_key_points(context, a_template);
    else
        return SVGElement::generate_attribute(context, a_template);
}

void HIRMutate::SVGAnimationElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGAnimationElement");
    SVGElement::serialize(stream, context);
    stream->write_int(value_count);
    stream->write_string(type);
    //for value_class
    if (value_class != nullptr)
    {
        Value *tmp = value_class();
        tmp->serialize(stream, context);
        delete tmp;
    }
    else
    {
        stream->write_string("nullptr");
    }
}
void HIRMutate::SVGAnimationElement::unserialize(UnSerializeStream *stream, Document *global_document)
{
    SVGElement::unserialize(stream, global_document, true);
    value_count = stream->read_int();
    type = stream->read_string();
    if (stream->peek() != "nullptr")
    {
        Value *tmp = value_classes[stream->read_string()](stream, global_document,nullptr);
        value_class = (Value * (*)(void)) tmp->getConstructor();
        delete tmp;
    }
    else
    {
        value_class = nullptr;
        stream->skip_string();
    }
}
HIRMutate::SVGFilterPrimitive::SVGFilterPrimitive(const string &name) : SVGElement(name)
{
}
string HIRMutate::SVGFilterPrimitive::additional_label()
{
    string ans = " result=\"";
    ans.append(id);
    ans.append("\"");
    return ans;
}
void HIRMutate::SVGFilterPrimitive::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGFilterPrimitive");
    SVGElement::serialize(stream, context);
}
void HIRMutate::SVGFilterPrimitive::unserialize(UnSerializeStream *stream, Document *global_document)
{
    SVGElement::unserialize(stream, global_document, true);
}
HIRMutate::SVGForeignObjectElement::SVGForeignObjectElement(const string &name) : SVGElement(name)
{
}

HIRMutate::Element *HIRMutate::SVGForeignObjectElement::generate_child(const string &child_name)
{
    Element *child = HTMLElement::create(child_name);
    add_child(child);
    return child;
}

HIRMutate::Element *HIRMutate::SVGForeignObjectElement::insert_child()
{
    string child_name;
    if (Random::selector(5) > 0)
        child_name = CHOICE_OBJ(DOC::html_general_child_elements);
    else
        child_name = CHOICE_OBJ(DOC::html_other_child_elements);
    return generate_child(child_name);
}

HIRMutate::SVGForeignObjectElement::operator string()
{
    string s = "<";
    s.append(tag);
    s.append(" id=\"");
    s.append(id);
    s.append("\"");

    std::for_each(attributes.begin(), attributes.end(),
                  [&s](map<string, Attribute::Attribute *>::reference i)
                  {
                      Attribute::Attribute *attr = i.second;
                      string attr_str = attr->operator string();
                      s.append(" ");
                      s.append(attr_str);
                  });

    if (children_count() == 0)
        s.append("/>");
    else
    {
        s.append(">\n");
        s.append("<body xmlns=\"http://www.w3.org/1999/xhtml\">\n");
        std::for_each(children.begin(), children.end(),
                      [&s](Element *e)
                      {
                          s.append(e->operator string());
                          s.append("\n");
                      });
        s.append("</body>\n");
        s.append("</");
        s.append(tag);
        s.append(">");
    }
    return s;
}
void HIRMutate::SVGForeignObjectElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGForeignObjectElement");
    SVGElement::serialize(stream, context);
}
void HIRMutate::SVGForeignObjectElement::unserialize(UnSerializeStream *stream, Document *global_document)
{
    SVGElement::unserialize(stream, global_document, true);
}
HIRMutate::SVGGlyphElement::SVGGlyphElement(const string &name) : SVGElement(name)
{
}

string HIRMutate::SVGGlyphElement::additional_label()
{
    string ans = " glyph-name=\"";
    ans.append(id);
    ans.append("\"");
    return ans;
}
void HIRMutate::SVGGlyphElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGGlyphElement");
    SVGElement::serialize(stream, context);
}
void HIRMutate::SVGGlyphElement::unserialize(UnSerializeStream *stream, Document *global_document)
{
    SVGElement::unserialize(stream, global_document, true);
}
