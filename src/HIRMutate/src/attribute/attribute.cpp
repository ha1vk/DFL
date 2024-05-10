#include "attribute.h"
#include "html_attr.h"
#include "svg_attr.h"
#include "serialize_variables.h"

namespace HIRMutate::Attribute
{
    map<string, vector<AttributeTemplate::ptr> > regular_attributes;
    map<string, vector<AttributeTemplate::ptr> > presentation_attributes;
    map<string, vector<AttributeTemplate::ptr> > global_attributes;
    map<string, vector<AttributeTemplate::ptr> > aria_attributes;
    map<string, vector<AttributeTemplate::ptr> > mandatory_attributes;

    map<string, vector<AttributeTemplate::ptr> > svg_animatable_regular_attributes;
    map<string, vector<AttributeTemplate::ptr> > svg_animatable_presentation_attributes;
    map<string, vector<AttributeTemplate::ptr> > svg_animatable_transform_attributes;

    map<string, int> attributes_count;
    vector<AttributeTemplate::ptr> empty;
    int attribute_types[] = {
        REGULAR,
        PRESENTATION,
        GLOBAL,
        ARIA};
}

using HIRMutate::Attribute::Attribute;
using HIRMutate::Attribute::AttributeTemplate;
using HIRMutate::VALUE::Value;

HIRMutate::Attribute::Attribute::Attribute(const string &elem, const string &name, Value *value)
{
    this->elem = elem;
    this->name = name;
    this->value = value;
    this->mandatory = false;
#ifdef DEBUG_MEM
    std::cout << "Attribute(" << name << ")" << std::endl;
#endif
}

HIRMutate::Attribute::Attribute::~Attribute()
{
    if (value)
    {
        delete value;
    }
#ifdef DEBUG_MEM
    std::cout << "~Attribute(" << name << ")" << std::endl;
#endif
}

void HIRMutate::Attribute::Attribute::generate(DOMContext *context)
{
    if (value)
        value->generate(context);
}

void HIRMutate::Attribute::Attribute::mutate(DOMContext *context)
{
    if (value)
        value->mutate(context);
}

void HIRMutate::Attribute::Attribute::merge_fix(map<Object *, Object *> &merge_map)
{
    if (value)
        value->merge_fix(merge_map);
}

HIRMutate::Attribute::Attribute::operator string()
{
    if (name == "")
    {
        return "";
    }
    string ans = name;
    ans.append("=\"");
    if (value)
        ans.append(value->getValue());
    ans.append("\"");
    return ans;
}

//序列化
void HIRMutate::Attribute::Attribute::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(elem);
    stream->write_string(name);
    stream->write_byte(mandatory);
    if (value)
        value->serialize(stream, context);
    else
        stream->write_string("nullptr");
}

//反序列化
void HIRMutate::Attribute::Attribute::unserialize(UnSerializeStream *stream, Document *global_document)
{
    elem = stream->read_string();
    name = stream->read_string();
    mandatory = stream->read_byte();
    if (stream->peek() == "nullptr")
    {
        value = nullptr;
    }
    else
    {
        value = value_classes[stream->read_string()](stream, global_document,nullptr);
    }
}

HIRMutate::Attribute::AttributeTemplate::AttributeTemplate(const char *elem, const char *attr, Value *(*valueInstance)(void))
{
    this->elem = elem;
    this->attr = attr;
    this->valueInstance = valueInstance;
#ifdef DEBUG_MEM
    std::cout << "AttributeTemplate(" << elem << ")" << std::endl;
#endif
}

Attribute *HIRMutate::Attribute::AttributeTemplate::instantiate()
{
    Value *value = nullptr;
    if (valueInstance != nullptr)
        value = valueInstance();
    return new Attribute(elem, attr, value);
}
HIRMutate::Attribute::AttributeTemplate::~AttributeTemplate()
{
#ifdef DEBUG_MEM
    std::cout << "~AttributeTemplate(" << elem << ")" << std::endl;
#endif
}

vector<AttributeTemplate::ptr> &HIRMutate::Attribute::get_attribute_templates(const string &name, bool include_aria)
{
    vector<int> weight = {0, 0, 0, 0};
    //std::cout << "get_attribute_templates name=" << name << std::endl;
    if (regular_attributes.find(name) != regular_attributes.end())
    {
        weight[0] = TreeConfig::attribute_weight["regular"] * regular_attributes[name].size();
    }
    if (presentation_attributes.find(name) != presentation_attributes.end())
    {
        weight[1] = TreeConfig::attribute_weight["presentation"] * presentation_attributes[name].size();
    }
    if (global_attributes.find(name) != global_attributes.end())
    {
        weight[2] = TreeConfig::attribute_weight["global"] * global_attributes[name].size();
    }
    if (aria_attributes.find(name) != aria_attributes.end() && include_aria)
    {
        weight[3] = TreeConfig::attribute_weight["aria"] * aria_attributes[name].size();
    }

    if ((weight[0] | weight[1] | weight[2] | weight[3]) == 0)
    {
        return empty;
    }
    int selector = CHOICE_W(attribute_types, weight);

    if (selector == REGULAR)
        return regular_attributes[name];
    else if (selector == PRESENTATION)
        return presentation_attributes[name];
    else if (selector == GLOBAL)
        return global_attributes[name];
    else
        return aria_attributes[name];
}

int HIRMutate::Attribute::get_attribute_count(const string &elem)
{
    //map的特性，key不存在的话就是value类型的默认值，因此无需检查是否存在key
    return attributes_count[elem];
}

void HIRMutate::Attribute::update_attribute_count(const string &elem)
{
    attributes_count[elem]++;
}

void HIRMutate::Attribute::add_regular_attribute(const AttributeTemplate::ptr &at)
{
    const string &elem = at->elem;
    regular_attributes[elem].push_back(at);
    update_svg_animatable_attribute(at, true);
    update_attribute_count(elem);
}

void HIRMutate::Attribute::add_presentation_attribute(const AttributeTemplate::ptr &at)
{
    const string &elem = at->elem;
    presentation_attributes[elem].push_back(at);
    update_svg_animatable_attribute(at, false);
    update_attribute_count(elem);
}

void HIRMutate::Attribute::add_global_attribute(const AttributeTemplate::ptr &at)
{
    const string &elem = at->elem;
    global_attributes[elem].push_back(at);
    update_attribute_count(elem);
}

void HIRMutate::Attribute::add_aria_attribute(const AttributeTemplate::ptr &at)
{
    const string &elem = at->elem;
    aria_attributes[elem].push_back(at);
}

void HIRMutate::Attribute::add_mandatory_attribute(const AttributeTemplate::ptr &at)
{
    const string &elem = at->elem;
    mandatory_attributes[elem].push_back(at);
}

void HIRMutate::Attribute::update_svg_animatable_attribute(const AttributeTemplate::ptr &at, bool is_regular)
{
    const string &elem = at->elem;
    if (DOC::is_svg_element(elem))
    {
        if (find(DOC::svg_animatable_attributes.begin(), DOC::svg_animatable_attributes.end(), at->attr) != DOC::svg_animatable_attributes.end())
        {
            if (is_regular)
            {
                svg_animatable_regular_attributes[elem].push_back(at);
            }
            else
            {
                svg_animatable_presentation_attributes[elem].push_back(at);
            }
        }
        if (find(DOC::svg_animatable_transform_attributes.begin(), DOC::svg_animatable_transform_attributes.end(), at->attr) != DOC::svg_animatable_transform_attributes.end())
        {
            svg_animatable_transform_attributes[elem].push_back(at);
        }
    }
}
AttributeTemplate::ptr &HIRMutate::Attribute::get_svg_animatable_attribute(const string &elem)
{
    bool has_regular = svg_animatable_regular_attributes.find(elem) != svg_animatable_regular_attributes.end();
    bool has_presentation = svg_animatable_presentation_attributes.find(elem) != svg_animatable_presentation_attributes.end();

    if ((!has_presentation) || (has_regular && Random::gbool()))
        return CHOICE_OBJ(svg_animatable_regular_attributes[elem]);
    else
        return CHOICE_OBJ(svg_animatable_presentation_attributes[elem]);
}

AttributeTemplate::ptr &HIRMutate::Attribute::get_svg_animatable_transform_attribute(const string &elem)
{
    return CHOICE_OBJ(svg_animatable_transform_attributes[elem]);
}

void HIRMutate::Attribute::print_attribute_count()
{
    std::for_each(attributes_count.begin(), attributes_count.end(),
                  [](map<string, int>::reference i)
                  {
                      printf("%s : %d\n", i.first.c_str(), i.second);
                  });
}
//初始化属性符号表
void HIRMutate::Attribute::init()
{
    HTML::initialize_html_attributes();
    SVG::initialize_svg_attributes();
}