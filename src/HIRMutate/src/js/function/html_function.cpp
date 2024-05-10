#include "object.h"
#include "attribute.h"
#include "js_property.h"
#include "arg.h"
#include "html_ret.h"
#include "html_function.h"
#include "js_function.h"
#include "assert.h"
#include "string.h"
#include "serialize_variables.h"

HIRMutate::JS::RemoveAttribute::RemoveAttribute(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::RemoveAttribute::~RemoveAttribute()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::RemoveAttribute::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::RemoveAttribute::mutate(JSContext *context)
{
    if (Random::gbool())
        selector->mutate(context);
    else
        this_obj->mutate(context);
}

void HIRMutate::JS::RemoveAttribute::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::RemoveAttribute::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".removeAttribute(");
    ans.append(this_obj_str);
    ans.append(".attributes[");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".attributes.length].name)");
    return ans;
}
void HIRMutate::JS::RemoveAttribute::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RemoveAttribute");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::RemoveAttribute::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::RemoveAttributeTemplate::RemoveAttributeTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::RemoveAttributeTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new RemoveAttribute(this_obj, selector);
}

bool HIRMutate::JS::RemoveAttributeTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::InsertBefore::InsertBefore(Arg *this_obj, Arg *new_node, Arg *selector) : API(nullptr, this_obj)
{
    this->new_node = new_node;
    this->selector = selector;
}
HIRMutate::JS::InsertBefore::~InsertBefore()
{
    if (new_node)
        delete new_node;
    if (selector)
        delete selector;
}
void HIRMutate::JS::InsertBefore::generate(JSContext *context)
{
    this_obj->generate(context);
    new_node->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::InsertBefore::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        new_node->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::InsertBefore::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    new_node->merge_fix(merge_map);
}

HIRMutate::JS::InsertBefore::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".insertBefore(");
    ans.append(new_node->operator string());
    ans.append(", ");
    ans.append(this_obj_str);
    ans.append(".childNodes[");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".childNodes.length])");
    return ans;
}
void HIRMutate::JS::InsertBefore::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("InsertBefore");
    API::serialize(stream, context);
    new_node->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::InsertBefore::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    new_node = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::InsertBeforeTemplate::InsertBeforeTemplate(Arg *(*this_class)(), Arg *(*new_node_class)()) : APITemplate(nullptr, this_class)
{
    this->new_node_class = new_node_class;
}

HIRMutate::JS::API *HIRMutate::JS::InsertBeforeTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *new_node_obj = new_node_class();
    Arg *selector = new RandomSelectorArg();
    return new InsertBefore(this_obj, new_node_obj, selector);
}

bool HIRMutate::JS::InsertBeforeTemplate::satiable(JSContext *context)
{
    Arg *new_node_obj = new_node_class();
    bool ans = is_satiable_arg(new_node_obj, context);
    delete new_node_obj;
    return ans;
}

HIRMutate::JS::RemoveChild::RemoveChild(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::RemoveChild::~RemoveChild()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::RemoveChild::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::RemoveChild::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::RemoveChild::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::RemoveChild::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".removeChild(");
    ans.append(this_obj_str);
    ans.append(".childNodes[");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".childNodes.length])");
    return ans;
}
void HIRMutate::JS::RemoveChild::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RemoveChild");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::RemoveChild::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::RemoveChildTemplate::RemoveChildTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::RemoveChildTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new RemoveChild(this_obj, selector);
}

bool HIRMutate::JS::RemoveChildTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::ReplaceChild::ReplaceChild(Arg *this_obj, Arg *new_node, Arg *selector) : API(nullptr, this_obj)
{
    this->new_node = new_node;
    this->selector = selector;
}
HIRMutate::JS::ReplaceChild::~ReplaceChild()
{
    if (new_node)
        delete new_node;
    if (selector)
        delete selector;
}
void HIRMutate::JS::ReplaceChild::generate(JSContext *context)
{
    this_obj->generate(context);
    new_node->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::ReplaceChild::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        new_node->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ReplaceChild::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    new_node->merge_fix(merge_map);
}

HIRMutate::JS::ReplaceChild::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".replaceChild(");
    ans.append(new_node->operator string());
    ans.append(", ");
    ans.append(this_obj_str);
    ans.append(".childNodes[");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".childNodes.length])");
    return ans;
}
void HIRMutate::JS::ReplaceChild::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ReplaceChild");
    API::serialize(stream, context);
    new_node->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ReplaceChild::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    new_node = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ReplaceChildTemplate::ReplaceChildTemplate(Arg *(*this_class)(), Arg *(*new_node_class)()) : APITemplate(nullptr, this_class)
{
    this->new_node_class = new_node_class;
}

HIRMutate::JS::API *HIRMutate::JS::ReplaceChildTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *new_node = new_node_class();
    Arg *selector = new RandomSelectorArg();
    return new ReplaceChild(this_obj, new_node, selector);
}

bool HIRMutate::JS::ReplaceChildTemplate::satiable(JSContext *context)
{
    Arg *new_node = new_node_class();
    bool ans = is_satiable_arg(new_node, context);
    delete new_node;
    return ans;
}

HIRMutate::JS::ListRemove::ListRemove(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::ListRemove::~ListRemove()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::ListRemove::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::ListRemove::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ListRemove::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::ListRemove::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".remove(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".length)");
    return ans;
}
void HIRMutate::JS::ListRemove::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ListRemove");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ListRemove::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ListRemoveTemplate::ListRemoveTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}
HIRMutate::JS::API *HIRMutate::JS::ListRemoveTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new ListRemove(this_obj, selector);
}

bool HIRMutate::JS::ListRemoveTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::ListItem::ListItem(Ret *ret, Arg *this_obj, Arg *selector) : API(ret, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::ListItem::~ListItem()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::ListItem::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
    if (ret != nullptr)
    {
        ret->generate(context);
    }
}

bool HIRMutate::JS::ListItem::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ListItem::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::ListItem::operator string()
{
    string ans = "";
    if (ret != nullptr)
    {
        ans.append("var ");
        ans.append(ret->operator string());
        ans.append(" = ");
    }
    string this_obj_str = this_obj->operator string();
    ans.append(this_obj_str);
    ans.append(".item(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".length)");
    return ans;
}
void HIRMutate::JS::ListItem::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ListItem");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ListItem::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ListItemTemplate::ListItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)()) : APITemplate(ret_class, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::ListItemTemplate::instantiate()
{
    Ret *ret = nullptr;
    if (ret_class != nullptr)
    {
        ret = ret_class();
    }
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new ListItem(ret, this_obj, selector);
}

bool HIRMutate::JS::ListItemTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::ListAdd::ListAdd(Arg *this_obj, Arg *item, Arg *selector) : API(nullptr, this_obj)
{
    this->item = item;
    this->selector = selector;
}
HIRMutate::JS::ListAdd::~ListAdd()
{
    if (item)
        delete item;
    if (selector)
        delete selector;
}
void HIRMutate::JS::ListAdd::generate(JSContext *context)
{
    this_obj->generate(context);
    item->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::ListAdd::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        selector->mutate(context);
    else
        item->mutate(context);
}

void HIRMutate::JS::ListAdd::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    item->merge_fix(merge_map);
}

HIRMutate::JS::ListAdd::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".add(");
    ans.append(item->operator string());
    ans.append(", ");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".length)");
    return ans;
}
void HIRMutate::JS::ListAdd::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ListAdd");
    API::serialize(stream, context);
    item->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ListAdd::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    item = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ListAddTemplate::ListAddTemplate(Arg *(*this_class)(), Arg *(*item_class)()) : APITemplate(nullptr, this_class)
{
    this->item_class = item_class;
}

HIRMutate::JS::API *HIRMutate::JS::ListAddTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *item = item_class();
    Arg *selector = new RandomSelectorArg();
    return new ListAdd(this_obj, item, selector);
}

bool HIRMutate::JS::ListAddTemplate::satiable(JSContext *context)
{
    Arg *item = item_class();
    bool ans = is_satiable_arg(item, context);
    delete item;
    return ans;
}

HIRMutate::JS::SnapshotItem::SnapshotItem(Ret *ret, Arg *this_obj, Arg *selector) : API(ret, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::SnapshotItem::~SnapshotItem()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::SnapshotItem::generate(JSContext *context)
{
    this_obj->generate(context);
    ret->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::SnapshotItem::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::SnapshotItem::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::SnapshotItem::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = ");
    ans.append(this_obj_str);
    ans.append(".snapshotItem(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".snapshotLength)");
    return ans;
}
void HIRMutate::JS::SnapshotItem::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SnapshotItem");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::SnapshotItem::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::SnapshotItemTemplate::SnapshotItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)()) : APITemplate(ret_class, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::SnapshotItemTemplate::instantiate()
{
    Ret *ret = ret_class();
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new SnapshotItem(ret, this_obj, selector);
}

bool HIRMutate::JS::SnapshotItemTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::TableSectionDeleteRow::TableSectionDeleteRow(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::TableSectionDeleteRow::~TableSectionDeleteRow()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::TableSectionDeleteRow::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::TableSectionDeleteRow::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::TableSectionDeleteRow::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::TableSectionDeleteRow::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".deleteRow(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".rows.length)");
    return ans;
}
void HIRMutate::JS::TableSectionDeleteRow::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableSectionDeleteRow");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::TableSectionDeleteRow::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::TableSectionDeleteRowTemplate::TableSectionDeleteRowTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::TableSectionDeleteRowTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new TableSectionDeleteRow(this_obj, selector);
}

bool HIRMutate::JS::TableSectionDeleteRowTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::SetAttribute::SetAttribute(ObjectArg *this_obj) : API(nullptr, this_obj)
{
    attr = nullptr;
}
HIRMutate::JS::SetAttribute::~SetAttribute()
{
    if (attr)
    {
        delete attr;
        attr = nullptr;
    }
}
void HIRMutate::JS::SetAttribute::generate_attr(DOMContext *context)
{
    if (attr)
    {
        delete attr;
        attr = nullptr;
    }
    ObjectArg *thiz_obj = (ObjectArg *)this_obj;
    if (thiz_obj->obj == nullptr)
    {
        return;
    }
    Element *element = (Element *)(thiz_obj->obj);
    vector<Attribute::AttributeTemplate::ptr> &templates = Attribute::get_attribute_templates(element->name, true);
    //assert(templates.size() > 0);
    if (templates.size() == 0)
    {
        return;
    }

    while (true)
    {
        Attribute::AttributeTemplate::ptr &m_template = CHOICE_OBJ(templates);
        attr = element->generate_attribute(context, m_template);
        if (attr != nullptr)
            break;
    }
}

void HIRMutate::JS::SetAttribute::generate(JSContext *context)
{
    this_obj->generate(context);
    generate_attr(context->global_context);
}

bool HIRMutate::JS::SetAttribute::mutate(JSContext *context)
{
    int c;
m_start:
    c = Random::selector(3);
    if (c == 0)
    {
        if (attr)
            attr->mutate(context->global_context);
        else
            goto m_start;
    }
    else if (c == 1)
        generate_attr(context->global_context);
    else
        generate(context);
}

void HIRMutate::JS::SetAttribute::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    attr->merge_fix(merge_map);
}

HIRMutate::JS::SetAttribute::operator string()
{
    if (attr == nullptr)
    {
        return "";
    }
    string ns = "";
    const char *name_str = attr->name.c_str();
    if (strstr(name_str, "xlink") == name_str)
        ns = "http://www.w3.org/1999/xlink";
    else if (strstr(name_str, "xml") == name_str)
        ns = "http://www.w3.org/XML/1998/namespace";
    string method;
    if (ns == "")
    {
        method = "setAttribute";
    }
    else
    {
        method = "setAttributeNS";
    }

    string ans = this_obj->operator string();
    ans.append(".");
    ans.append(method);
    ans.append("(");
    if (ns != "")
    {
        ans.append("\"");
        ans.append(ns);
        ans.append("\"");
        ans.append(",");
    }
    ans.append("\"");
    ans.append(name_str);
    ans.append("\"");
    ans.append(",");

    ans.append("\"");
    if (attr->value)
        ans.append(attr->value->getValue());
    ans.append("\"");

    ans.append(")");
    return ans;
}
void HIRMutate::JS::SetAttribute::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SetAttribute");
    API::serialize(stream, context);
    if (attr)
        attr->serialize(stream, context->global_context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::JS::SetAttribute::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        attr = nullptr;
        stream->skip_string();
    }
    else
    {
        attr = new Attribute::Attribute();
        attr->unserialize(stream, global_document);
    }
}
HIRMutate::JS::SetAttributeTemplate::SetAttributeTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
    /*if get_attribute_count(this.name) <= 0:
            print(this.name)
            assert False*/
}

HIRMutate::JS::API *HIRMutate::JS::SetAttributeTemplate::instantiate()
{
    Arg *this_obj = this_class();
    return new SetAttribute((ObjectArg *)this_obj);
}

bool HIRMutate::JS::SetAttributeTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::SetProperty::SetProperty(Arg *this_obj) : API(nullptr, this_obj)
{
    decl = nullptr;
}
HIRMutate::JS::SetProperty::~SetProperty()
{
    if (decl)
        delete decl;
}
void HIRMutate::JS::SetProperty::generate_decl(DOMContext *context)
{
    if (decl)
        delete decl;
    decl = CSS::create_css_declaration();
    decl->generate(context);
}

void HIRMutate::JS::SetProperty::generate(JSContext *context)
{
    this_obj->generate(context);
    generate_decl(context->global_context);
}

bool HIRMutate::JS::SetProperty::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        decl->mutate(context->global_context);
    else if (c == 1)
        generate_decl(context->global_context);
    else
        generate(context);
}

void HIRMutate::JS::SetProperty::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    decl->merge_fix(merge_map);
}

HIRMutate::JS::SetProperty::operator string()
{
    string ans = this_obj->operator string();
    ans.append(".setProperty(\"");
    ans.append(decl->prop);
    ans.append("\", \"");
    ans.append(decl->value->getValue());
    ans.append("\")");
    return ans;
}
void HIRMutate::JS::SetProperty::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SetProperty");
    API::serialize(stream, context);
    decl->serialize(stream, context->global_context);
}
void HIRMutate::JS::SetProperty::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    decl = new CSS::CSSDeclaration();
    decl->unserialize(stream, global_document);
}
HIRMutate::JS::SetPropertyTemplate::SetPropertyTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::SetPropertyTemplate::instantiate()
{
    Arg *this_obj = this_class();
    return new SetProperty(this_obj);
}

bool HIRMutate::JS::SetPropertyTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::RemoveProperty::RemoveProperty(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::RemoveProperty::~RemoveProperty()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::RemoveProperty::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::RemoveProperty::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::RemoveProperty::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::RemoveProperty::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".removeProperty(");
    ans.append(this_obj_str);
    ans.append(".item(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".length))");
    return ans;
}
void HIRMutate::JS::RemoveProperty::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RemoveProperty");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::RemoveProperty::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::RemovePropertyTemplate::RemovePropertyTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::RemovePropertyTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new RemoveProperty(this_obj, selector);
}

bool HIRMutate::JS::RemovePropertyTemplate::satiable(JSContext *context)
{
    return true;
}

namespace HIRMutate::JS
{
    map<string, Ret *(*)()> interesting_html_element_rets;
    vector<string> interesting_html_element_tag;
    map<string, Ret *(*)()> html_element_rets;
    map<string, Ret *(*)()> html_event_rets;
}

void HIRMutate::JS::initHTMLSym()
{
    INTERESTING_HTML_ELEMENT_RETS("a", HTMLAnchorElementRet)
    INTERESTING_HTML_ELEMENT_RETS("area", HTMLAreaElementRet);
    INTERESTING_HTML_ELEMENT_RETS("button", HTMLButtonElementRet)
    INTERESTING_HTML_ELEMENT_RETS("canvas", HTMLCanvasElementRet)
    INTERESTING_HTML_ELEMENT_RETS("caption", HTMLTableCaptionElementRet)
    INTERESTING_HTML_ELEMENT_RETS("col", HTMLTableColElementRet)
    INTERESTING_HTML_ELEMENT_RETS("colgroup", HTMLTableColGroupElementRet)
    INTERESTING_HTML_ELEMENT_RETS("data", HTMLDataElementRet)
    INTERESTING_HTML_ELEMENT_RETS("datalist", HTMLDataListElementRet)
    INTERESTING_HTML_ELEMENT_RETS("dd", HTMLDDElementRet)
    INTERESTING_HTML_ELEMENT_RETS("details", HTMLDetailsElementRet)
    INTERESTING_HTML_ELEMENT_RETS("dialog", HTMLDialogElementRet)
    INTERESTING_HTML_ELEMENT_RETS("div", HTMLDivElementRet)
    INTERESTING_HTML_ELEMENT_RETS("dl", HTMLDListElementRet)
    INTERESTING_HTML_ELEMENT_RETS("dt", HTMLDTElementRet)
    INTERESTING_HTML_ELEMENT_RETS("embed", HTMLEmbedElementRet)
    INTERESTING_HTML_ELEMENT_RETS("fieldset", HTMLFieldSetElementRet)
    INTERESTING_HTML_ELEMENT_RETS("form", HTMLFormElementRet)
    INTERESTING_HTML_ELEMENT_RETS("h1", HTMLHeading1ElementRet)
    INTERESTING_HTML_ELEMENT_RETS("iframe", HTMLIFrameElementRet)
    INTERESTING_HTML_ELEMENT_RETS("img", HTMLImageElementRet)
    INTERESTING_HTML_ELEMENT_RETS("input", HTMLInputElementRet)
    INTERESTING_HTML_ELEMENT_RETS("label", HTMLLabelElementRet)
    INTERESTING_HTML_ELEMENT_RETS("map", HTMLMapElementRet)
    INTERESTING_HTML_ELEMENT_RETS("marquee", HTMLMarqueeElementRet)
    INTERESTING_HTML_ELEMENT_RETS("menu", HTMLMenuElementRet)
    INTERESTING_HTML_ELEMENT_RETS("menuitem", HTMLMenuItemElementRet)
    INTERESTING_HTML_ELEMENT_RETS("object", HTMLObjectElementRet)
    INTERESTING_HTML_ELEMENT_RETS("ol", HTMLOListElementRet)
    INTERESTING_HTML_ELEMENT_RETS("optgroup", HTMLOptGroupElementRet)
    INTERESTING_HTML_ELEMENT_RETS("option", HTMLOptionElementRet)
    INTERESTING_HTML_ELEMENT_RETS("output", HTMLOutputElementRet)
    INTERESTING_HTML_ELEMENT_RETS("p", HTMLParagraphElementRet)
    INTERESTING_HTML_ELEMENT_RETS("param", HTMLParamElementRet)
    INTERESTING_HTML_ELEMENT_RETS("script", HTMLScriptElementRet)
    INTERESTING_HTML_ELEMENT_RETS("section", HTMLSectionElementRet)
    INTERESTING_HTML_ELEMENT_RETS("select", HTMLSelectElementRet)
    INTERESTING_HTML_ELEMENT_RETS("shadow", HTMLShadowElementRet)
    INTERESTING_HTML_ELEMENT_RETS("span", HTMLSpanElementRet)
    INTERESTING_HTML_ELEMENT_RETS("style", HTMLStyleElementRet)
    INTERESTING_HTML_ELEMENT_RETS("summary", HTMLSummaryElementRet)
    INTERESTING_HTML_ELEMENT_RETS("table", HTMLTableElementRet)
    INTERESTING_HTML_ELEMENT_RETS("tbody", HTMLTBodyElementRet)
    INTERESTING_HTML_ELEMENT_RETS("td", HTMLTableDataCellElementRet)
    INTERESTING_HTML_ELEMENT_RETS("template", HTMLTemplateElementRet)
    INTERESTING_HTML_ELEMENT_RETS("textarea", HTMLTextAreaElementRet)
    INTERESTING_HTML_ELEMENT_RETS("tfoot", HTMLTFootElementRet)
    INTERESTING_HTML_ELEMENT_RETS("th", HTMLTableHeaderCellElementRet)
    INTERESTING_HTML_ELEMENT_RETS("thead", HTMLTHeadElementRet)
    INTERESTING_HTML_ELEMENT_RETS("tr", HTMLTableRowElementRet)
    INTERESTING_HTML_ELEMENT_RETS("track", HTMLTrackElementRet)
    INTERESTING_HTML_ELEMENT_RETS("ul", HTMLUListElementRet)

    HTML_ELEMENT_RETS("a", HTMLAnchorElementRet)
    HTML_ELEMENT_RETS("abbr", HTMLAbbrElementRet)
    HTML_ELEMENT_RETS("acronym", HTMLAcronymElementRet)
    HTML_ELEMENT_RETS("address", HTMLAddressElementRet)
    HTML_ELEMENT_RETS("area", HTMLAreaElementRet)
    HTML_ELEMENT_RETS("article", HTMLArticleElementRet)
    HTML_ELEMENT_RETS("aside", HTMLAsideElementRet)
    HTML_ELEMENT_RETS("audio", HTMLAudioElementRet)
    HTML_ELEMENT_RETS("b", HTMLBElementRet)
    HTML_ELEMENT_RETS("basefont", HTMLBaseFontElementRet)
    HTML_ELEMENT_RETS("bdi", HTMLBDIElementRet)
    HTML_ELEMENT_RETS("bdo", HTMLBDOElementRet)
    HTML_ELEMENT_RETS("bgsound", HTMLBgSoundElementRet)
    HTML_ELEMENT_RETS("big", HTMLBigElementRet)
    HTML_ELEMENT_RETS("blockquote", HTMLBlockQuoteElementRet)
    HTML_ELEMENT_RETS("br", HTMLBRElementRet)
    HTML_ELEMENT_RETS("button", HTMLButtonElementRet)
    HTML_ELEMENT_RETS("canvas", HTMLCanvasElementRet)
    HTML_ELEMENT_RETS("caption", HTMLTableCaptionElementRet)
    HTML_ELEMENT_RETS("center", HTMLCenterElementRet)
    HTML_ELEMENT_RETS("cite", HTMLCiteElementRet)
    HTML_ELEMENT_RETS("code", HTMLCodeElementRet)
    HTML_ELEMENT_RETS("col", HTMLTableColElementRet)
    HTML_ELEMENT_RETS("colgroup", HTMLTableColGroupElementRet)
    HTML_ELEMENT_RETS("command", HTMLCommandElementRet)
    HTML_ELEMENT_RETS("content", HTMLContentElementRet)
    HTML_ELEMENT_RETS("data", HTMLDataElementRet)
    HTML_ELEMENT_RETS("datalist", HTMLDataListElementRet)
    HTML_ELEMENT_RETS("dd", HTMLDDElementRet)
    HTML_ELEMENT_RETS("del", HTMLDelElementRet)
    HTML_ELEMENT_RETS("details", HTMLDetailsElementRet)
    HTML_ELEMENT_RETS("dfn", HTMLDFNElementRet)
    HTML_ELEMENT_RETS("dialog", HTMLDialogElementRet)
    HTML_ELEMENT_RETS("dir", HTMLDirectoryElementRet)
    HTML_ELEMENT_RETS("div", HTMLDivElementRet)
    HTML_ELEMENT_RETS("dl", HTMLDListElementRet)
    HTML_ELEMENT_RETS("dt", HTMLDTElementRet)
    HTML_ELEMENT_RETS("em", HTMLEMElementRet)
    HTML_ELEMENT_RETS("embed", HTMLEmbedElementRet)
    HTML_ELEMENT_RETS("fieldset", HTMLFieldSetElementRet)
    HTML_ELEMENT_RETS("figcaption", HTMLFigCaptionElementRet)
    HTML_ELEMENT_RETS("figure", HTMLFigureElementRet)
    HTML_ELEMENT_RETS("font", HTMLFontElementRet)
    HTML_ELEMENT_RETS("footer", HTMLFooterElementRet)
    HTML_ELEMENT_RETS("form", HTMLFormElementRet)
    HTML_ELEMENT_RETS("frame", HTMLFrameElementRet)
    HTML_ELEMENT_RETS("frameset", HTMLFrameSetElementRet)
    HTML_ELEMENT_RETS("h1", HTMLHeading1ElementRet)
    HTML_ELEMENT_RETS("h2", HTMLHeading2ElementRet)
    HTML_ELEMENT_RETS("h3", HTMLHeading3ElementRet)
    HTML_ELEMENT_RETS("h4", HTMLHeading4ElementRet)
    HTML_ELEMENT_RETS("h5", HTMLHeading5ElementRet)
    HTML_ELEMENT_RETS("h6", HTMLHeading6ElementRet)
    HTML_ELEMENT_RETS("header", HTMLHeaderElementRet)
    HTML_ELEMENT_RETS("hgroup", HTMLHGroupElementRet)
    HTML_ELEMENT_RETS("hr", HTMLHRElementRet)
    HTML_ELEMENT_RETS("i", HTMLIElementRet)
    HTML_ELEMENT_RETS("iframe", HTMLIFrameElementRet)
    HTML_ELEMENT_RETS("img", HTMLImageElementRet)
    HTML_ELEMENT_RETS("input", HTMLInputElementRet)
    HTML_ELEMENT_RETS("ins", HTMLInsElementRet)
    HTML_ELEMENT_RETS("isindex", HTMLIsIndexElementRet)
    HTML_ELEMENT_RETS("kbd", HTMLKBDElementRet)
    HTML_ELEMENT_RETS("keygen", HTMLKeygenElementRet)
    HTML_ELEMENT_RETS("label", HTMLLabelElementRet)
    HTML_ELEMENT_RETS("legend", HTMLLegendElementRet)
    HTML_ELEMENT_RETS("li", HTMLLIElementRet)
    HTML_ELEMENT_RETS("link", HTMLLinkElementRet)
    HTML_ELEMENT_RETS("listing", HTMLListingElementRet)
    HTML_ELEMENT_RETS("main", HTMLMainElementRet)
    HTML_ELEMENT_RETS("map", HTMLMapElementRet)
    HTML_ELEMENT_RETS("mark", HTMLMarkElementRet)
    HTML_ELEMENT_RETS("marquee", HTMLMarqueeElementRet)
    HTML_ELEMENT_RETS("menu", HTMLMenuElementRet)
    HTML_ELEMENT_RETS("menuitem", HTMLMenuItemElementRet)
    HTML_ELEMENT_RETS("meta", HTMLMetaElementRet)
    HTML_ELEMENT_RETS("meter", HTMLMeterElementRet)
    HTML_ELEMENT_RETS("nav", HTMLNavElementRet)
    HTML_ELEMENT_RETS("object", HTMLObjectElementRet)
    HTML_ELEMENT_RETS("ol", HTMLOListElementRet)
    HTML_ELEMENT_RETS("optgroup", HTMLOptGroupElementRet)
    HTML_ELEMENT_RETS("option", HTMLOptionElementRet)
    HTML_ELEMENT_RETS("output", HTMLOutputElementRet)
    HTML_ELEMENT_RETS("p", HTMLParagraphElementRet)
    HTML_ELEMENT_RETS("param", HTMLParamElementRet)
    HTML_ELEMENT_RETS("picture", HTMLPictureElementRet)
    //HTML_ELEMENT_RETS("plaintext", HTMLPlainTextElementRet)
    HTML_ELEMENT_RETS("pre", HTMLPreElementRet)
    HTML_ELEMENT_RETS("progress", HTMLProgressElementRet)
    HTML_ELEMENT_RETS("q", HTMLQElementRet)
    HTML_ELEMENT_RETS("rp", HTMLRPElementRet)
    HTML_ELEMENT_RETS("rt", HTMLRTElementRet)
    HTML_ELEMENT_RETS("ruby", HTMLRubyElementRet)
    HTML_ELEMENT_RETS("s", HTMLSElementRet)
    HTML_ELEMENT_RETS("samp", HTMLSampElementRet)
    HTML_ELEMENT_RETS("script", HTMLScriptElementRet)
    HTML_ELEMENT_RETS("section", HTMLSectionElementRet)
    HTML_ELEMENT_RETS("select", HTMLSelectElementRet)
    HTML_ELEMENT_RETS("shadow", HTMLShadowElementRet)
    HTML_ELEMENT_RETS("slot", HTMLSlotElementRet)
    HTML_ELEMENT_RETS("small", HTMLSmallElementRet)
    HTML_ELEMENT_RETS("source", HTMLSourceElementRet)
    HTML_ELEMENT_RETS("span", HTMLSpanElementRet)
    HTML_ELEMENT_RETS("strike", HTMLStrikeElementRet)
    HTML_ELEMENT_RETS("strong", HTMLStrongElementRet)
    HTML_ELEMENT_RETS("style", HTMLStyleElementRet)
    HTML_ELEMENT_RETS("sub", HTMLSubElementRet)
    HTML_ELEMENT_RETS("summary", HTMLSummaryElementRet)
    HTML_ELEMENT_RETS("sup", HTMLSupElementRet)
    HTML_ELEMENT_RETS("table", HTMLTableElementRet)
    HTML_ELEMENT_RETS("tbody", HTMLTBodyElementRet)
    HTML_ELEMENT_RETS("td", HTMLTableDataCellElementRet)
    HTML_ELEMENT_RETS("template", HTMLTemplateElementRet)
    HTML_ELEMENT_RETS("textarea", HTMLTextAreaElementRet)
    HTML_ELEMENT_RETS("tfoot", HTMLTFootElementRet)
    HTML_ELEMENT_RETS("th", HTMLTableHeaderCellElementRet)
    HTML_ELEMENT_RETS("thead", HTMLTHeadElementRet)
    HTML_ELEMENT_RETS("time", HTMLTimeElementRet)
    HTML_ELEMENT_RETS("title", HTMLTitleElementRet)
    HTML_ELEMENT_RETS("tr", HTMLTableRowElementRet)
    HTML_ELEMENT_RETS("track", HTMLTrackElementRet)
    HTML_ELEMENT_RETS("tt", HTMLTTElementRet)
    HTML_ELEMENT_RETS("u", HTMLUElementRet)
    HTML_ELEMENT_RETS("ul", HTMLUListElementRet)
    HTML_ELEMENT_RETS("var", HTMLVarElementRet)
    HTML_ELEMENT_RETS("video", HTMLVideoElementRet)
    HTML_ELEMENT_RETS("wbr", HTMLWBRElementRet)
    HTML_ELEMENT_RETS("xmp", HTMLXMPElementRet)

    HTML_EVENT_RETS("InputEvent", InputEventRet)
    HTML_EVENT_RETS("PointerEvent", PointerEventRet)
    HTML_EVENT_RETS("ClipboardEvent", ClipboardEventRet)
    HTML_EVENT_RETS("DragEvent", DragEventRet)
    HTML_EVENT_RETS("ApplicationCacheErrorEvent", ApplicationCacheErrorEventRet)
    HTML_EVENT_RETS("AnimationEvent", AnimationEventRet)
    HTML_EVENT_RETS("MediaQueryListEvent", MediaQueryListEventRet)
    HTML_EVENT_RETS("PromiseRejectionEvent", PromiseRejectionEventRet)
    HTML_EVENT_RETS("AnimationPlaybackEvent", AnimationPlaybackEventRet)
    HTML_EVENT_RETS("BeforeLoadEvent", EventRet)
    HTML_EVENT_RETS("BeforeUnloadEvent", BeforeUnloadEventRet)
    HTML_EVENT_RETS("CompositionEvent", CompositionEventRet)
    HTML_EVENT_RETS("CustomEvent", CustomEventRet)
    HTML_EVENT_RETS("ErrorEvent", ErrorEventRet)
    HTML_EVENT_RETS("FocusEvent", FocusEventRet)
    HTML_EVENT_RETS("HashChangeEvent", HashChangeEventRet)
    HTML_EVENT_RETS("KeyboardEvent", KeyboardEventRet)
    HTML_EVENT_RETS("MessageEvent", MessageEventRet)
    HTML_EVENT_RETS("MouseEvent", MouseEventRet)
    HTML_EVENT_RETS("MutationEvent", MutationEventRet)
    HTML_EVENT_RETS("OverflowEvent", EventRet)
    HTML_EVENT_RETS("PopStateEvent", PopStateEventRet)
    HTML_EVENT_RETS("ProgressEvent", ProgressEventRet)
    HTML_EVENT_RETS("ResourceProgressEvent", ResourceProgressEventRet)
    HTML_EVENT_RETS("SecurityPolicyViolationEvent", SecurityPolicyViolationEventRet)
    HTML_EVENT_RETS("TextEvent", TextEventRet)
    HTML_EVENT_RETS("TransitionEvent", TransitionEventRet)
    HTML_EVENT_RETS("UIEvent", UIEventRet)
    HTML_EVENT_RETS("WebKitAnimationEvent", EventRet)
    HTML_EVENT_RETS("WheelEvent", WheelEventRet)
    HTML_EVENT_RETS("TrackEvent", EventRet)
    HTML_EVENT_RETS("SVGZoomEvent", EventRet)
    HTML_EVENT_RETS("Events", EventRet)
    HTML_EVENT_RETS("HTMLEvents", EventRet)
    HTML_EVENT_RETS("KeyboardEvents", KeyboardEventRet)
    HTML_EVENT_RETS("MouseEvents", MouseEventRet)
    HTML_EVENT_RETS("MutationEvents", MutationEventRet)
    HTML_EVENT_RETS("OrientationEvent", EventRet)
    HTML_EVENT_RETS("SVGEvents", EventRet)
    HTML_EVENT_RETS("SVGZoomEvents", EventRet)
    HTML_EVENT_RETS("UIEvents", UIEventRet)
    HTML_EVENT_RETS("Event", EventRet)
}

HIRMutate::JS::CreateInterestingElement::CreateInterestingElement(Arg *this_obj) : API(nullptr, this_obj)
{
}

void HIRMutate::JS::CreateInterestingElement::generate(JSContext *context)
{
    if (ret)
        delete ret;
    this_obj->generate(context);
    tag = CHOICE_OBJ(interesting_html_element_tag);
    ret = (interesting_html_element_rets[tag])();
    ret->generate(context);
}

bool HIRMutate::JS::CreateInterestingElement::mutate(JSContext *context)
{
}

void HIRMutate::JS::CreateInterestingElement::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::CreateInterestingElement::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = ");
    ans.append(this_obj->operator string());
    ans.append(".createElement(\"");
    ans.append(tag);
    ans.append("\")");
    return ans;
}
void HIRMutate::JS::CreateInterestingElement::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CreateInterestingElement");
    API::serialize(stream, context);
    stream->write_string(tag);
}
void HIRMutate::JS::CreateInterestingElement::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    tag = stream->read_string();
}
HIRMutate::JS::CreateInterestingElementTemplate::CreateInterestingElementTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::CreateInterestingElementTemplate::instantiate()
{
    Arg *this_obj = this_class();
    return new CreateInterestingElement(this_obj);
}

bool HIRMutate::JS::CreateInterestingElementTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::API *HIRMutate::JS::create_interesting_html_element(JSContext *context)
{
    API *api = new CreateInterestingElement(HANDLE_ARG(DocumentArg)());
    api->generate(context);
    return api;
}

HIRMutate::JS::CreateElement::CreateElement(Arg *this_obj) : API(nullptr, this_obj)
{
}

void HIRMutate::JS::CreateElement::generate(JSContext *context)
{
    this_obj->generate(context);
    while (true)
    {
        tag = CHOICE_OBJ(DOC::html_tags);
        if (html_element_rets.find(tag) != html_element_rets.end())
        {
            if (ret)
            {
                delete ret;
            }
            ret = (html_element_rets[tag])();
            break;
        }
    }
    ret->generate(context);
}

bool HIRMutate::JS::CreateElement::mutate(JSContext *context)
{
}

void HIRMutate::JS::CreateElement::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::CreateElement::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = ");
    ans.append(this_obj->operator string());
    ans.append(".createElement(\"");
    ans.append(tag);
    ans.append("\")");
    return ans;
}
void HIRMutate::JS::CreateElement::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CreateElement");
    API::serialize(stream, context);
    stream->write_string(tag);
}
void HIRMutate::JS::CreateElement::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    tag = stream->read_string();
}
HIRMutate::JS::CreateElementTemplate::CreateElementTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::CreateElementTemplate::instantiate()
{
    Arg *arg = this_class();
    return new CreateElement(arg);
}

bool HIRMutate::JS::CreateElementTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::API *HIRMutate::JS::create_html_element(JSContext *context)
{
    API *api = new CreateElement(HANDLE_ARG(DocumentArg)());
    api->generate(context);
    return api;
}

HIRMutate::JS::CreateEvent::CreateEvent(Arg *this_obj) : API(nullptr, this_obj)
{
}

void HIRMutate::JS::CreateEvent::generate(JSContext *context)
{
    this_obj->generate(context);
    int idx = Random::selector(html_event_rets.size());
    map<string, Ret *(*)()>::iterator it = html_event_rets.begin();
    for (int i = 0; i < idx; i++)
    {
        it++;
    }
    const std::pair<string, Ret *(*)()> &p = *it;
    event_type = p.first;
    Ret *(*event_class)() = p.second;
    if (ret)
    {
        delete ret;
    }
    ret = event_class();
    ret->generate(context);
}

bool HIRMutate::JS::CreateEvent::mutate(JSContext *context)
{
    return false;
}

void HIRMutate::JS::CreateEvent::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::CreateEvent::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = ");
    ans.append(this_obj->operator string());
    ans.append(".createEvent(\"");
    ans.append(event_type);
    ans.append("\")");
    return ans;
}
void HIRMutate::JS::CreateEvent::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CreateEvent");
    API::serialize(stream, context);
    stream->write_string(event_type);
}
void HIRMutate::JS::CreateEvent::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    event_type = stream->read_string();
}
HIRMutate::JS::CreateEventTemplate::CreateEventTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class) {}

HIRMutate::JS::API *HIRMutate::JS::CreateEventTemplate::instantiate()
{
    Arg *this_obj = this_class();
    return new CreateEvent(this_obj);
}

bool HIRMutate::JS::CreateEventTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::DocumentAppendChild::DocumentAppendChild(Arg *this_obj, Arg *element, Arg *selector) : API(nullptr, this_obj)
{
    this->element = element;
    this->selector = selector;
}
HIRMutate::JS::DocumentAppendChild::~DocumentAppendChild()
{
    if (element)
        delete element;
    if (selector)
        delete selector;
}
void HIRMutate::JS::DocumentAppendChild::generate(JSContext *context)
{
    this_obj->generate(context);
    element->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::DocumentAppendChild::mutate(JSContext *context)
{
    if (Random::gbool())
        selector->mutate(context);
    else
        element->mutate(context);
}

void HIRMutate::JS::DocumentAppendChild::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    element->merge_fix(merge_map);
}

HIRMutate::JS::DocumentAppendChild::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".all[");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".all.length].appendChild(");
    ans.append(element->operator string());
    ans.append(")");
    return ans;
}
void HIRMutate::JS::DocumentAppendChild::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DocumentAppendChild");
    API::serialize(stream, context);
    element->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::DocumentAppendChild::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    element = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::DocumentAppendChildTemplate::DocumentAppendChildTemplate(Arg *(*this_class)(), Arg *(*element_class)()) : APITemplate(nullptr, this_class)
{
    this->element_class = element_class;
}

HIRMutate::JS::API *HIRMutate::JS::DocumentAppendChildTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *element = element_class();
    Arg *selector = new RandomSelectorArg();
    return new DocumentAppendChild(this_obj, element, selector);
}

bool HIRMutate::JS::DocumentAppendChildTemplate::satiable(JSContext *context)
{
    Arg *element = element_class();
    bool ans = is_satiable_arg(element, context);
    delete element;
    return ans;
}

HIRMutate::JS::DeleteRule::DeleteRule(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::DeleteRule::~DeleteRule()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::DeleteRule::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::DeleteRule::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::DeleteRule::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::DeleteRule::operator string()
{
    string this_obj_str = this_obj->operator string();
    string ans = this_obj_str;
    ans.append(".deleteRule(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj_str);
    ans.append(".cssRules.length)");
    return ans;
}
void HIRMutate::JS::DeleteRule::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DeleteRule");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::DeleteRule::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::DeleteRuleTemplate::DeleteRuleTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::DeleteRuleTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new DeleteRule(this_obj, selector);
}

bool HIRMutate::JS::DeleteRuleTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::FunctionTemplate::ptr instanceFunctionTemplate(HIRMutate::JS::Ret *(*ret_class)(), HIRMutate::JS::Arg *(*this_class)(), const string &method, std::initializer_list<HIRMutate::JS::Arg *(*)()> args)
{
    vector<HIRMutate::JS::Arg *(*)()> arg_classes;
    for (auto ptr = args.begin(); ptr != args.end(); ptr++)
    {
        arg_classes.push_back(*ptr);
    }

    HIRMutate::JS::FunctionTemplate::ptr obj = std::make_shared<HIRMutate::JS::FunctionTemplate>(ret_class, this_class, method, arg_classes);
    return obj;
}

HIRMutate::JS::FunctionTemplate::ptr instanceFunctionTemplate(HIRMutate::JS::Ret *(*ret_class)(), HIRMutate::JS::Arg *(*this_class)(), const string &method)
{
    vector<HIRMutate::JS::Arg *(*)()> arg_classes;
    HIRMutate::JS::FunctionTemplate::ptr obj = std::make_shared<HIRMutate::JS::FunctionTemplate>(ret_class, this_class, method, arg_classes);
    return obj;
}

HIRMutate::JS::ConstructTemplate::ptr instanceConstructTemplate(HIRMutate::JS::Ret *(*ret_class)(), const string &ctor, std::initializer_list<HIRMutate::JS::Arg *(*)()> args)
{
    vector<HIRMutate::JS::Arg *(*)()> arg_classes;
    for (auto ptr = args.begin(); ptr != args.end(); ptr++)
    {
        arg_classes.push_back(*ptr);
    }

    HIRMutate::JS::ConstructTemplate::ptr obj = std::make_shared<HIRMutate::JS::ConstructTemplate>(ret_class, ctor, arg_classes);
    return obj;
}
HIRMutate::JS::ConstructTemplate::ptr instanceConstructTemplate(HIRMutate::JS::Ret *(*ret_class)(), const string &ctor)
{
    vector<HIRMutate::JS::Arg *(*)()> arg_classes;

    HIRMutate::JS::ConstructTemplate::ptr obj = std::make_shared<HIRMutate::JS::ConstructTemplate>(ret_class, ctor, arg_classes);
    return obj;
}
HIRMutate::JS::ConstructObjectTemplate::ptr instanceConstructObjectTemplate(HIRMutate::JS::Ret *(*ret_class)(), map<string, HIRMutate::JS::Arg *(*)()> &shape_classes)
{
    HIRMutate::JS::ConstructObjectTemplate::ptr obj = std::make_shared<HIRMutate::JS::ConstructObjectTemplate>(ret_class, shape_classes);
    return obj;
}

#define ConstStringArgClass(name)                                     \
    class ConstStringArg##name : public HIRMutate::JS::ConstStringArg \
    {                                                                 \
    public:                                                           \
        ConstStringArg##name() : ConstStringArg(#name) {}             \
    };

#define HANDLE_CONST_STRING_ARG(name) HANDLE_ARG(ConstStringArg##name)

//classes for ConstStringArg
ConstStringArgClass(backColor);
ConstStringArgClass(false);
ConstStringArgClass(bold);
ConstStringArgClass(contentReadOnly);
ConstStringArgClass(createLink);
ConstStringArgClass(decreaseFontSize);
ConstStringArgClass(delete);
ConstStringArgClass(enableInlineTableEditing);
ConstStringArgClass(enableObjectResizing);
ConstStringArgClass(fontName);
ConstStringArgClass(fontSize);
ConstStringArgClass(foreColor);
ConstStringArgClass(formatBlock);
ConstStringArgClass(forwardDelete);
ConstStringArgClass(heading);
ConstStringArgClass(hiliteColor);
ConstStringArgClass(increaseFontSize);
ConstStringArgClass(indent);
ConstStringArgClass(insertBrOnReturn);
ConstStringArgClass(insertHorizontalRule);
ConstStringArgClass(insertHTML);
ConstStringArgClass(insertImage);
ConstStringArgClass(insertOrderedList);
ConstStringArgClass(insertUnorderedList);
ConstStringArgClass(insertParagraph);
ConstStringArgClass(insertText);
ConstStringArgClass(italic);
ConstStringArgClass(justifyCenter);
ConstStringArgClass(justifyFull);
ConstStringArgClass(justifyLeft);
ConstStringArgClass(justifyRight);
ConstStringArgClass(outdent);
ConstStringArgClass(redo);
ConstStringArgClass(removeFormat);
ConstStringArgClass(selectAll);
ConstStringArgClass(strikeThrough);
ConstStringArgClass(subscript);
ConstStringArgClass(superscript);
ConstStringArgClass(underline);
ConstStringArgClass(undo);
ConstStringArgClass(unlink);
ConstStringArgClass(useCSS);
ConstStringArgClass(styleWithCSS);
ConstStringArgClass(DOMAttrModified);
ConstStringArgClass(DOMCharacterDataModified);
ConstStringArgClass(DOMNodeInserted);
ConstStringArgClass(DOMNodeInsertedIntoDocument);
ConstStringArgClass(DOMNodeRemoved);
ConstStringArgClass(DOMNodeRemovedFromDocument);
ConstStringArgClass(DOMSubtreeModified);

void HIRMutate::JS::initialize_html_functions()
{
    /*
    * CSS
    */
    // CSSStyleDeclaration
    add_api(std::make_shared<SetPropertyTemplate>(HANDLE_ARG(CSSStyleDeclarationArg)));
    add_api(std::make_shared<RemovePropertyTemplate>(HANDLE_ARG(CSSStyleDeclarationArg)));
    add_api(std::make_shared<ListItemTemplate>(nullptr, HANDLE_ARG(CSSStyleDeclarationArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSStyleDeclarationArg), "getPropertyValue", {HANDLE_ARG(CSSPropertyNameArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSStyleDeclarationArg), "getPropertyPriority", {HANDLE_ARG(CSSPropertyNameArg)}));

    // CSSStyleSheet
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSStyleSheetArg), "insertRule", {HANDLE_ARG(CSSStyleRuleValueArg)}));
    add_api(std::make_shared<DeleteRuleTemplate>(HANDLE_ARG(CSSStyleSheetArg)));

    // CSSKeyframesSheet
    add_api(std::make_shared<DeleteRuleTemplate>(HANDLE_ARG(CSSKeyframesSheetArg)));

    // CSSKeyframesRule
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSKeyframesRuleArg), "appendRule", {HANDLE_ARG(CSSKeyframeRuleValueArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSKeyframesRuleArg), "deleteRule", {HANDLE_ARG(CSSKeyframeNameArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CSSKeyframesRuleArg), "findRule", {HANDLE_ARG(CSSKeyframeNameArg)}));

    // FontFaceSet
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FontFaceSetArg), "load", {HANDLE_ARG(FontArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FontFaceSetArg), "load", {HANDLE_ARG(FontArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FontFaceSetArg), "check", {HANDLE_ARG(FontArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FontFaceSetArg), "check", {HANDLE_ARG(FontArg), HANDLE_ARG(StringArg)}));

    // FontFace
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FontFaceArg), "load"));

    // DocumentOrShadowRoot
    add_api(instanceFunctionTemplate(HANDLE_RET(SelectionRet), HANDLE_ARG(DocumentOrShadowRootArg), "getSelection"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentOrShadowRootArg), "elementFromPoint", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementListRet), HANDLE_ARG(DocumentOrShadowRootArg), "elementsFromPoint",
                                     {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));

    // History
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HistoryArg), "pushState", {HANDLE_ARG(HistoryStateArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HistoryArg), "replaceState", {HANDLE_ARG(HistoryStateArg), HANDLE_ARG(StringArg)}));

    // Window
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "stop"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "focus"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "blur"));
    add_api(instanceFunctionTemplate(HANDLE_RET(RequestIDRet), HANDLE_ARG(WindowArg), "requestAnimationFrame", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(RequestIDRet), HANDLE_ARG(WindowArg), "webkitRequestAnimationFrame", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "cancelAnimationFrame", {HANDLE_ARG(RequestIDArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "webkitCancelAnimationFrame", {HANDLE_ARG(RequestIDArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "webkitCancelRequestAnimationFrame", {HANDLE_ARG(RequestIDArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "getComputedStyle", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "moveTo", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "moveBy", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "resizeTo", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "resizeBy", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scroll"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scroll", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scroll", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollTo"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollTo", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollTo", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollBy"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollBy", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "scrollBy", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SelectionRet), HANDLE_ARG(WindowArg), "getSelection"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "find", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "find", {HANDLE_ARG(StringArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "btoa", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "atob", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "postMessage", {HANDLE_ARG(StringArg), HANDLE_ARG(ConstStringArgStar)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "captureEvents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "releaseEvents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(WindowArg), "getComputedStyle", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(MediaQueryListRet), HANDLE_ARG(WindowArg), "matchMedia", {HANDLE_ARG(MediaQueryArg)}));

    // MessagePort
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MessagePortArg), "postMessage", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MessagePortArg), "start"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MessagePortArg), "close"));

    // MediaQueryList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MediaQueryListArg), "addListener", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MediaQueryListArg), "removeListener", {HANDLE_ARG(EventHandlerArg)}));

    // MediaList
    add_api(std::make_shared<ListItemTemplate>(nullptr, HANDLE_ARG(MediaListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MediaListArg), "appendMedium", {HANDLE_ARG(MediaQueryArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MediaListArg), "deleteMedium", {HANDLE_ARG(MediaQueryArg)}));

    // StyleMedia
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(StyleMediaArg), "matchMedium", {HANDLE_ARG(MediaQueryArg)}));

    // Navigator
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(NavigatorArg), "sendBeacon", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));

    // Document
    add_api(std::make_shared<DocumentAppendChildTemplate>(HANDLE_ARG(DocumentArg), HANDLE_ARG(ElementArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(backColor), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(ColorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(bold), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(contentReadOnly), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(createLink), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(DummyUrlArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(decreaseFontSize), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(delete), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(enableInlineTableEditing), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(enableObjectResizing), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(fontName), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(FontArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(fontSize), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(foreColor), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(ColorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(formatBlock), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(forwardDelete), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(heading), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(HeadingArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(hiliteColor), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(ColorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(increaseFontSize), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(indent), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertBrOnReturn), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertHorizontalRule), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertHTML), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(HTMLStringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertHTML), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertImage), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(ImageSrcArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertOrderedList), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertUnorderedList), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    // add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", { HANDLE_CONST_STRING_ARG(insertParagraph),
    //                         HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg) } ));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(insertText), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(italic), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(justifyCenter), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(justifyFull), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(justifyLeft), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(justifyRight), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(outdent), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(redo), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(removeFormat), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(selectAll), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(strikeThrough), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(subscript), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(superscript), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(underline), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(undo), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(unlink), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(useCSS), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "execCommand", {HANDLE_CONST_STRING_ARG(styleWithCSS), HANDLE_CONST_STRING_ARG(false), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "queryCommandEnabled", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "queryCommandIndeterm", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "queryCommandState", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "queryCommandSupported", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "queryCommandValue", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "exitPointerLock"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "getElementsByTagName", {HANDLE_ARG(TagArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "getElementsByTagNameNS",
                                     {HANDLE_ARG(ConstStringArgXhtml), HANDLE_ARG(HTMLTagArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "getElementsByClassName", {HANDLE_ARG(ClassArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(DocumentArg), "createDocumentFragment"));
    add_api(instanceFunctionTemplate(HANDLE_RET(TextRet), HANDLE_ARG(DocumentArg), "createTextNode", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(CommentRet), HANDLE_ARG(DocumentArg), "createComment", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(DocumentArg), "createRange"));
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeIteratorRet), HANDLE_ARG(DocumentArg), "createNodeIterator", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeIteratorRet), HANDLE_ARG(DocumentArg), "createNodeIterator", {HANDLE_ARG(ElementArg), HANDLE_ARG(WhatToShowArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(TreeWalkerRet), HANDLE_ARG(DocumentArg), "createTreeWalker", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(TreeWalkerRet), HANDLE_ARG(DocumentArg), "createTreeWalker", {HANDLE_ARG(ElementArg), HANDLE_ARG(WhatToShowArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(ProcessingInstructionRet), HANDLE_ARG(DocumentArg), "createProcessingInstruction", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(DocumentArg), "caretRangeFromPoint"));
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(DocumentArg), "caretRangeFromPoint", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "captureEvents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "releaseEvents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "webkitCancelFullScreen"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "webkitExitFullscreen"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "querySelector", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeListRet), HANDLE_ARG(DocumentArg), "querySelectorAll", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathExpressionRet), HANDLE_ARG(DocumentArg), "createExpression", {HANDLE_ARG(XPathArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathExpressionRet), HANDLE_ARG(DocumentArg), "createExpression", {HANDLE_ARG(XPathArg), HANDLE_ARG(XPathNSResolverArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathNSResolverRet), HANDLE_ARG(DocumentArg), "createNSResolver", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(DocumentArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(DocumentArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(ElementArg), HANDLE_ARG(NullArg), HANDLE_ARG(XPathResultTypeArg), HANDLE_ARG(XPathResultArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(DocumentArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(DocumentArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(DocumentArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(DocumentArg), HANDLE_ARG(NullArg), HANDLE_ARG(XPathResultTypeArg), HANDLE_ARG(XPathResultArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DocumentArg), "hasFocus"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "importNode", {HANDLE_ARG(ElementArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "adoptNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(AttrRet), HANDLE_ARG(DocumentArg), "createAttribute", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(AttrRet), HANDLE_ARG(DocumentArg), "createAttributeNS",
                                     {HANDLE_ARG(ConstStringArgXhtml), HANDLE_ARG(StringArg)}));

    // DOMImplementation
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMImplementationArg), "createDocumentType", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMImplementationArg), "createDocument", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentRet), HANDLE_ARG(DOMImplementationArg), "createHTMLDocument", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMImplementationArg), "hasFeature"));

    // NamedNodeMap
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(AttrRet), HANDLE_ARG(NamedNodeMapArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(NamedNodeMapArg), "setNamedItem", {HANDLE_ARG(AttrArg)}));

    // EventTarget
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventTargetArg), "addEventListener", {HANDLE_ARG(EventTypeArg), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventTargetArg), "addEventListener", {HANDLE_ARG(EventTypeArg), HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AddEventListenerOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventTargetArg), "removeEventListener", {HANDLE_ARG(EventTypeArg), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventTargetArg), "dispatchEvent", {HANDLE_ARG(EventArg)}));

    // Element
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "click"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "blur"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "focus"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "setPointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "releasePointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "hasPointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "requestPointerLock"));
    // DOM event listeners
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMAttrModified), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMCharacterDataModified), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMNodeInserted), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMNodeInsertedIntoDocument), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMNodeRemoved), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMNodeRemovedFromDocument), HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "addEventListener", {HANDLE_CONST_STRING_ARG(DOMSubtreeModified), HANDLE_ARG(EventHandlerArg)}));
    add_api(std::make_shared<RemoveAttributeTemplate>(HANDLE_ARG(ElementArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(AnimationRet), HANDLE_ARG(ElementArg), "animate", {HANDLE_ARG(KeyFramesArg), HANDLE_ARG(ClockInMsArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(AnimationRet), HANDLE_ARG(ElementArg), "animate", {HANDLE_ARG(KeyFramesArg), HANDLE_ARG(AnimateOptionsArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(AnimationsRet), HANDLE_ARG(ElementArg), "getAnimations"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "querySelector", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeListRet), HANDLE_ARG(ElementArg), "querySelectorAll", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(std::make_shared<InsertBeforeTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(ElementArg)));
    add_api(std::make_shared<RemoveChildTemplate>(HANDLE_ARG(ElementArg)));
    add_api(std::make_shared<ReplaceChildTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(ElementArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "hasChildNodes"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "getRootNode"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "getRootNode", {HANDLE_ARG(GetRootNodeOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "normalize"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "cloneNode", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "isEqualNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "isSameNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "compareDocumentPosition", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "lookupPrefix", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "lookupNamespaceURI", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "isDefaultNamespace", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "contains", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "appendChild", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "before", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "before", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "after", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "after", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "replaceWith", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "replaceWith", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "remove"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "prepend", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "prepend", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "append", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "append", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "hasAttributes"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "closest", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "matches", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "webkitMatchesSelector", {HANDLE_ARG(CSSSelectorValueArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(ElementArg), "getElementsByTagName", {HANDLE_ARG(TagArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(ElementArg), "getElementsByClassName", {HANDLE_ARG(ClassArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "insertAdjacentElement", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "insertAdjacentText", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "insertAdjacentHTML", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(HTMLStringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectListRet), HANDLE_ARG(ElementArg), "getClientRects"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectRet), HANDLE_ARG(ElementArg), "getBoundingClientRect"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollIntoView"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollIntoView", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scroll"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scroll", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scroll", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollTo"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollTo", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollTo", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollBy"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollBy", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollBy", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    // add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "setApplyScroll", {HANDLE_ARG(EventHandlerArg),
    //                         HANDLE_CONST_STRING_ARG(disable-native-scroll"));)
    // add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "setDistributeScroll", {HANDLE_ARG(EventHandlerArg),
    //                         HANDLE_CONST_STRING_ARG(disable-native-scroll"));)
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollIntoViewIfNeeded"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "scrollIntoViewIfNeeded", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ElementArg), "webkitRequestFullScreen"));

    // ShadowHost
    add_api(instanceFunctionTemplate(HANDLE_RET(ShadowRootRet), HANDLE_ARG(ShadowHostArg), "attachShadow", {HANDLE_ARG(ShadowRootInitArg)}));

    // CharacterData
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CharacterDataArg), "substringData", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CharacterDataArg), "appendData", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CharacterDataArg), "insertData", {HANDLE_ARG(IntegerArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CharacterDataArg), "deleteData", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CharacterDataArg), "replaceData", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(StringArg)}));

    // NodeIterator
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(NodeIteratorArg), "nextNode"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(NodeIteratorArg), "previousNode"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(NodeIteratorArg), "detach"));

    // NodeFilter
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(NodeFilterArg), "acceptNode"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(NodeFilterArg), "acceptNode", {HANDLE_ARG(ElementArg)}));

    // TreeWalker
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "parentNode"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "firstChild"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "lastChild"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "previousSibling"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "nextSibling"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "previousNode"));
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "nextNode"));

    // Text
    add_api(instanceFunctionTemplate(HANDLE_RET(TextRet), HANDLE_ARG(TextArg), "splitText", {HANDLE_ARG(IntegerArg)}));

    // TimeRanges
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TimeRangesArg), "start", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TimeRangesArg), "end", {HANDLE_ARG(IntegerArg)}));

    // Selection
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(SelectionArg), "getRangeAt", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "addRange", {HANDLE_ARG(RangeArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "removeAllRanges"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "empty"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "collapse", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "collapse", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "setPosition", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "setPosition", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "collapseToStart"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "collapseToEnd"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "extend", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "extend", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "setBaseAndExtent", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "selectAllChildren", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "deleteFromDocument"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "containsNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "containsNode", {HANDLE_ARG(ElementArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "modify"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "modify", {HANDLE_ARG(SelectionModifyAlterArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "modify", {HANDLE_ARG(SelectionModifyAlterArg), HANDLE_ARG(SelectionModifyDirectionArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SelectionArg), "modify", {HANDLE_ARG(SelectionModifyAlterArg), HANDLE_ARG(SelectionModifyDirectionArg), HANDLE_ARG(SelectionModifyGranularityArg)}));

    // NodeList
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(NodeListArg)));

    // HTMLCollection
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(HTMLCollectionArg)));

    // HTMLAllCollection
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(HTMLAllCollectionArg)));

    // HTMLOptionsCollection
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLOptionElementRet), HANDLE_ARG(HTMLOptionsCollectionArg)));
    add_api(std::make_shared<ListAddTemplate>(HANDLE_ARG(HTMLOptionsCollectionArg), HANDLE_ARG(HTMLOptionElementArg)));
    add_api(std::make_shared<ListAddTemplate>(HANDLE_ARG(HTMLOptionsCollectionArg), HANDLE_ARG(HTMLOptGroupElementArg)));
    add_api(std::make_shared<ListRemoveTemplate>(HANDLE_ARG(HTMLOptionsCollectionArg)));

    // HTMLAreasCollection
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLAreaElementRet), HANDLE_ARG(HTMLAreasCollectionArg)));

    // LabelElementList
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLLabelElementRet), HANDLE_ARG(HTMLLabelElementListArg)));

    //AnimationTimeline
    add_api(instanceFunctionTemplate(HANDLE_RET(AnimationsRet), HANDLE_ARG(AnimationTimelineArg), "getAnimations"));

    //Animation
    add_api(instanceConstructTemplate(HANDLE_RET(AnimationRet), "Animation", {HANDLE_ARG(KeyframeEffectArg)}));
    add_api(instanceConstructTemplate(HANDLE_RET(AnimationRet), "Animation", {HANDLE_ARG(KeyframeEffectArg), HANDLE_ARG(AnimationTimelineArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationArg), "finish"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationArg), "play"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationArg), "pause"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationArg), "reverse"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationArg), "cancel"));

    //AnimationEffectReadOnly
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(AnimationEffectReadOnlyArg), "getComputedTiming"));

    //KeyframeEffect
    add_api(instanceConstructTemplate(HANDLE_RET(KeyframeEffectRet), "KeyframeEffect", {HANDLE_ARG(ElementArg), HANDLE_ARG(KeyFramesArg)}));
    add_api(instanceConstructTemplate(HANDLE_RET(KeyframeEffectRet), "KeyframeEffect", {HANDLE_ARG(ElementArg), HANDLE_ARG(KeyFramesArg), HANDLE_ARG(ClockInMsArg)}));
    add_api(instanceConstructTemplate(HANDLE_RET(KeyframeEffectRet), "KeyframeEffect", {HANDLE_ARG(ElementArg), HANDLE_ARG(KeyFramesArg), HANDLE_ARG(AnimateOptionsArg)}));

    //TextTrack
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TextTrackArg), "addCue", {HANDLE_ARG(TextTrackCueArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TextTrackArg), "removeCue", {HANDLE_ARG(TextTrackCueArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TextTrackArg), "addRegion", {HANDLE_ARG(VTTRegionArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TextTrackArg), "removeRegion", {HANDLE_ARG(VTTRegionArg)}));

    //VTTRegionList
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(VTTRegionRet), HANDLE_ARG(VTTRegionListArg)));

    //VTTCue
    add_api(instanceConstructTemplate(HANDLE_RET(VTTCueRet), "VTTCue", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(VTTCueArg), "getCueAsHTML"));

    //HTMLMediaElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "load"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "pause"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "play"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "canPlayType", {HANDLE_ARG(MediaTypeArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(TextTrackRet), HANDLE_ARG(HTMLMediaElementArg), "addTextTrack", {HANDLE_ARG(TrackKindArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(TextTrackRet), HANDLE_ARG(HTMLMediaElementArg), "addTextTrack", {HANDLE_ARG(TrackKindArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(TextTrackRet), HANDLE_ARG(HTMLMediaElementArg), "addTextTrack", {HANDLE_ARG(TrackKindArg), HANDLE_ARG(StringArg), HANDLE_ARG(LangArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "fastSeek", {HANDLE_ARG(ClockArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "getStartDate"));
    add_api(instanceFunctionTemplate(HANDLE_RET(VideoPlaybackQualityRet), HANDLE_ARG(HTMLMediaElementArg), "getVideoPlaybackQuality"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitShowPlaybackTargetPicker"));

    //HTMLButtonElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLButtonElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLButtonElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLButtonElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLTableElement
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableCaptionElementRet), HANDLE_ARG(HTMLTableElementArg), "createCaption"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTableElementArg), "deleteCaption"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableElementArg), "createTHead"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTableElementArg), "deleteTHead"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableElementArg), "createTFoot"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTableElementArg), "deleteTFoot"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableElementArg), "createTBody"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableRowElementRet), HANDLE_ARG(HTMLTableElementArg), "insertRow"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableRowElementRet), HANDLE_ARG(HTMLTableElementArg), "insertRow", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTableElementArg), "deleteRow", {HANDLE_ARG(IntegerArg)}));

    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableSectionsCollectionArg)));
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLTableRowElementRet), HANDLE_ARG(HTMLTableRowsCollectionArg)));

    //HTMLDialogElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLDialogElementArg), "show"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLDialogElementArg), "showModal"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLDialogElementArg), "close"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLDialogElementArg), "close", {HANDLE_ARG(StringArg)}));

    //HTMLTextAreaElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "select"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setRangeText", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setRangeText", {HANDLE_ARG(StringArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setRangeText", {HANDLE_ARG(StringArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(SelectModeArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setSelectionRange", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "setSelectionRange", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(SelectionDirectionArg)}));

    //HTMLFormElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFormElementArg), "submit"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFormElementArg), "reset"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFormElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFormElementArg), "reportValidity"));

    //HTMLSlotElement
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLElementListRet), HANDLE_ARG(HTMLSlotElementArg), "assignedNodes"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLElementListRet), HANDLE_ARG(HTMLSlotElementArg), "assignedNodes", {HANDLE_ARG(AssignedNodesOptionArg)}));

    //HTMLKeygenElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLTableRowElement
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableCellElementRet), HANDLE_ARG(HTMLTableRowElementArg), "insertCell"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableCellElementRet), HANDLE_ARG(HTMLTableRowElementArg), "insertCell", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "deleteCell", {HANDLE_ARG(IntegerArg)}));

    //HTMLTableCellElements
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(HTMLTableCellElementRet), HANDLE_ARG(HTMLTableCellsCollectionArg)));

    //HTMLObjectElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLObjectElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLObjectElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLObjectElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLSelectElement
    add_api(std::make_shared<ListAddTemplate>(HANDLE_ARG(HTMLSelectElementArg), HANDLE_ARG(HTMLOptionElementArg)));
    add_api(std::make_shared<ListAddTemplate>(HANDLE_ARG(HTMLSelectElementArg), HANDLE_ARG(HTMLOptGroupElementArg)));
    add_api(std::make_shared<ListRemoveTemplate>(HANDLE_ARG(HTMLSelectElementArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLSelectElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLSelectElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLSelectElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLCanvasElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "toDataURL"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "toDataURL", {HANDLE_ARG(ImageTypeArg), HANDLE_ARG(Float01Arg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "toBlob", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "toBlob", {HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ImageTypeArg), HANDLE_ARG(Float01Arg)}));

    //HTMLOutputElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLOutputElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLOutputElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLOutputElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLVideoElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitEnterFullscreen"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitExitFullscreen"));

    //HTMLTableSectionElement
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableRowElementRet), HANDLE_ARG(HTMLTableSectionElementArg), "insertRow"));
    add_api(instanceFunctionTemplate(HANDLE_RET(HTMLTableRowElementRet), HANDLE_ARG(HTMLTableSectionElementArg), "insertRow", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<TableSectionDeleteRowTemplate>(HANDLE_ARG(HTMLTableSectionElementArg)));

    //HTMLFieldSetElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));

    //HTMLShadowElement
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeListRet), HANDLE_ARG(HTMLShadowElementArg), "getDistributedNodes"));

    //HTMLInputElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "stepUp"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "stepUp", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "stepDown"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "stepDown", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "checkValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "reportValidity"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setCustomValidity", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "select"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setRangeText", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setRangeText", {HANDLE_ARG(StringArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setRangeText", {HANDLE_ARG(StringArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(SelectModeArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setSelectionRange"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setSelectionRange", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setSelectionRange", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLInputElementArg), "setSelectionRange", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(SelectionDirectionArg)}));

    //HTMLMarqueeElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "start"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "stop"));

    //HTMLContentElement
    add_api(instanceFunctionTemplate(HANDLE_RET(NodeListRet), HANDLE_ARG(HTMLContentElementArg), "getDistributedNodes"));

    //HTMLStyleElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(HTMLStyleElementArg), "appendChild", {HANDLE_ARG(CSSStyleRuleValueTextArg)}));

    //createElement
    add_api(std::make_shared<CreateElementTemplate>(HANDLE_ARG(DocumentArg)));
    add_api(std::make_shared<CreateInterestingElementTemplate>(HANDLE_ARG(DocumentArg)));

    //setAttribute
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAbbrElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAcronymElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAddressElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAnchorElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAreaElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLArticleElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAsideElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLAudioElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBDIElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBDOElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBRElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBaseFontElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBgSoundElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBigElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLBlockQuoteElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLButtonElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLCanvasElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLCenterElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLCiteElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLCodeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLCommandElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLContentElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDDElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDFNElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDListElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDTElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDataElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDataListElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDelElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDetailsElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDialogElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDirectoryElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLDivElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLEMElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLEmbedElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFieldSetElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFigCaptionElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFigureElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFontElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFooterElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFormElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFrameElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLFrameSetElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHGroupElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHRElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeaderElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading1ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading2ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading3ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading4ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading5ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLHeading6ElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLIElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLIFrameElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLImageElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLInputElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLInsElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLIsIndexElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLKBDElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLKeygenElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLLIElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLLabelElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLLegendElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLLinkElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLListingElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMainElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMapElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMarkElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMarqueeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMenuElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMenuItemElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMetaElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLMeterElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLNavElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLOListElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLObjectElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLOptGroupElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLOptionElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLOutputElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLParagraphElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLParamElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLPictureElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLPlainTextElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLPreElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLProgressElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLQElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLRPElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLRTElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLRubyElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSampElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSectionElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSelectElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLShadowElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSlotElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSmallElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSourceElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSpanElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLStrikeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLStrongElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSubElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSummaryElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLSupElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTBodyElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTFootElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTHeadElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTTElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableCaptionElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableColElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableColGroupElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableDataCellElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableHeaderCellElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTableRowElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTemplateElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTextAreaElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTimeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTitleElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLTrackElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLUElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLUListElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLVarElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLVideoElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLWBRElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(HTMLXMPElementArg)));

    /*
    *Event
    #*/
    //createEvent
    add_api(std::make_shared<CreateEventTemplate>(HANDLE_ARG(DocumentArg)));

    //DataTransfer
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferArg), "setDragImage", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferArg), "getData", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferArg), "setData", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferArg), "clearData"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferArg), "clearData", {HANDLE_ARG(StringArg)}));

    //DataTransferItemList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferItemListArg), "add", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(std::make_shared<ListRemoveTemplate>(HANDLE_ARG(DataTransferItemListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferItemListArg), "clear"));

    //DataTransferItem
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DataTransferItemArg), "getAsString", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(BlobRet), HANDLE_ARG(DataTransferItemArg), "getAsFile"));

    //Event
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventArg), "stopPropagation"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventArg), "stopImmediatePropagation"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventArg), "preventDefault"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(EventArg), "initEvent", {HANDLE_ARG(EventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(EventTargetsRet), HANDLE_ARG(EventArg), "composedPath"));

    //UIEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(UIEventArg), "initUIEvent", {HANDLE_ARG(UIEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(WindowArg), HANDLE_ARG(StringArg)}));

    //CompositionEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CompositionEventArg), "initCompositionEvent", {HANDLE_ARG(CompositionEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(WindowArg), HANDLE_ARG(StringArg)}));

    //TextEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(TextEventArg), "initTextEvent", {HANDLE_ARG(TextEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(WindowArg), HANDLE_ARG(StringArg)}));

    //MouseEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MouseEventArg), "getModifierState", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MouseEventArg), "initMouseEvent", {HANDLE_ARG(MouseEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(WindowArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(MouseButtonTypeArg), HANDLE_ARG(EventTargetArg)}));

    //StaticRange
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(StaticRangeArg), "setStart", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(StaticRangeArg), "setEnd", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(StaticRangeArg), "toRange"));

    //InputEvent
    add_api(instanceFunctionTemplate(HANDLE_RET(StaticRangesRet), HANDLE_ARG(InputEventArg), "getTargetRanges"));

    //MessageEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MessageEventArg), "initMessageEvent", {HANDLE_ARG(MessageEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(WindowArg)})); //FIXME: message port

    //MutationEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MutationEventArg), "initMutationEvent", {HANDLE_ARG(MutationEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(ElementArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(AttrChangeTypeArg)}));

    //KeyboardEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(KeyboardEventArg), "getModifierState", {HANDLE_ARG(CharArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(KeyboardEventArg), "initKeyboardEvent", {HANDLE_ARG(KeyboardEventTypeArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(WindowArg), HANDLE_ARG(CharArg), HANDLE_ARG(CharArg), HANDLE_ARG(KeyLocationTypeArg), HANDLE_ARG(StringArg), HANDLE_ARG(BooleanArg)}));

    //CustomEvent
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CustomEventArg), "initCustomEvent", {HANDLE_ARG(StringArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(StringArg)}));

    /*
    *Web Animations
    */

    map<string, HIRMutate::JS::Arg *(*)()> shape_classes;
    shape_classes["delay"] = HANDLE_ARG(ClockInMsArg);
    shape_classes["direction"] = HANDLE_ARG(AnimationDirectionArg);
    shape_classes["duration"] = HANDLE_ARG(ClockInMsArg);
    shape_classes["easing"] = HANDLE_ARG(AnimationEasingArg);
    shape_classes["endDelay"] = HANDLE_ARG(ClockInMsArg);
    shape_classes["fill"] = HANDLE_ARG(AnimationFillArg);
    shape_classes["iterationStart"] = HANDLE_ARG(FloatArg);
    shape_classes["iterations"] = HANDLE_ARG(IntegerArg);
    //AnimationEffectTiming
    add_api(instanceConstructObjectTemplate(HANDLE_RET(AnimationEffectTimingRet), shape_classes));

    /*
    *Misc
    */
    //Range
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(RangeArg), "cloneContents"));
    add_api(instanceFunctionTemplate(HANDLE_RET(RangeRet), HANDLE_ARG(RangeArg), "cloneRange"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "collapse", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "compareBoundaryPoints", {HANDLE_ARG(RangeCompareArg), HANDLE_ARG(RangeArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "compareNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "comparePoint", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(RangeArg), "createContextualFragment", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "deleteContents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "detach"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(RangeArg), "extractContents"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "expand"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "expand", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectRet), HANDLE_ARG(RangeArg), "getBoundingClientRect"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectListRet), HANDLE_ARG(RangeArg), "getClientRects"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "insertNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "intersectsNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "isPointInRange", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "selectNode", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "selectNodeContents", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setEnd", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setEndAfter", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setEndBefore", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setStart", {HANDLE_ARG(ElementArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setStartAfter", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "setStartBefore", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(RangeArg), "surroundContents", {HANDLE_ARG(ElementArg)}));

    //ApplicationCache
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ApplicationCacheArg), "update"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ApplicationCacheArg), "abort"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(ApplicationCacheArg), "swapCache"));

    //XPathEvaluator
    //|evaluate| is a bit different from domato.
    add_api(instanceConstructTemplate(HANDLE_RET(XPathEvaluatorRet), "XPathEvaluator"));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathExpressionRet), HANDLE_ARG(XPathEvaluatorArg), "createExpression", {HANDLE_ARG(XPathArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathExpressionRet), HANDLE_ARG(XPathEvaluatorArg), "createExpression", {HANDLE_ARG(XPathArg), HANDLE_ARG(XPathNSResolverArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathNSResolverRet), HANDLE_ARG(XPathEvaluatorArg), "createNSResolver", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathEvaluatorArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathEvaluatorArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(ElementArg), HANDLE_ARG(NullArg), HANDLE_ARG(XPathResultTypeArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathEvaluatorArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(DocumentArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathEvaluatorArg), "evaluate", {HANDLE_ARG(XPathArg), HANDLE_ARG(DocumentArg), HANDLE_ARG(NullArg), HANDLE_ARG(XPathResultTypeArg)}));

    //XPathResult
    add_api(instanceFunctionTemplate(HANDLE_RET(ElementRet), HANDLE_ARG(XPathResultArg), "iterateNext"));
    add_api(std::make_shared<SnapshotItemTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(XPathResultArg)));

    //XMLSerializer
    add_api(instanceConstructTemplate(HANDLE_RET(XMLSerializerRet), "XMLSerializer"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XMLSerializerArg), "serializeToString", {HANDLE_ARG(ElementArg)}));

    //DOMParser
    add_api(instanceConstructTemplate(HANDLE_RET(DOMParserRet), "DOMParser"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentRet), HANDLE_ARG(DOMParserArg), "parseFromString", {HANDLE_ARG(ConstStringEmpty), HANDLE_ARG(ConstStringTextOrHtml)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentRet), HANDLE_ARG(DOMParserArg), "parseFromString", {HANDLE_ARG(HTMLStringArg), HANDLE_ARG(ContentTypeArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(DocumentRet), HANDLE_ARG(DOMParserArg), "parseFromString", {HANDLE_ARG(HTMLStringArg), HANDLE_ARG(ConstStringTextOrHtml)}));

    //XPathNSResolver
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XPathNSResolverArg), "lookupNamespaceURI"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XPathNSResolverArg), "lookupNamespaceURI", {HANDLE_ARG(StringArg)}));

    //XPathExpression
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathExpressionArg), "evaluate", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(XPathResultRet), HANDLE_ARG(XPathExpressionArg), "evaluate", {HANDLE_ARG(ElementArg), HANDLE_ARG(XPathResultTypeArg), HANDLE_ARG(XPathResultArg)}));

    //XSLTProcessor
    add_api(instanceConstructTemplate(HANDLE_RET(XSLTProcessorRet), "XSLTProcessor"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "importStylesheet", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "transformToFragment", {HANDLE_ARG(ElementArg), HANDLE_ARG(DocumentArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "transformToDocument", {HANDLE_ARG(ElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "setParameter", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "getParameter", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "removeParameter", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "clearParameters"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(XSLTProcessorArg), "reset"));

    //CustomElementRegistry
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CustomElementRegistryArg), "define", {HANDLE_ARG(CustomElementNameArg), HANDLE_ARG(DoNothingArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CustomElementRegistryArg), "get", {HANDLE_ARG(CustomElementNameArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(CustomElementRegistryArg), "whenDefined", {HANDLE_ARG(CustomElementNameArg)}));

    //MutationObserver
    add_api(instanceConstructTemplate(HANDLE_RET(MutationObserverRet), "MutationObserver", {HANDLE_ARG(EventHandlerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MutationObserverArg), "observe", {HANDLE_ARG(ElementArg), HANDLE_ARG(MutationObserverInitArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(MutationObserverArg), "disconnect"));
    add_api(instanceFunctionTemplate(HANDLE_RET(MutationRecordsRet), HANDLE_ARG(MutationObserverArg), "takeRecords"));

    //MessageChannel
    add_api(instanceConstructTemplate(HANDLE_RET(MessageChannelRet), "MessageChannel"));

    //URL
    add_api(instanceConstructTemplate(HANDLE_RET(URLRet), "URL", {HANDLE_ARG(ConstStringURLFOO)}));

    //FormData
    add_api(instanceConstructTemplate(HANDLE_RET(FormDataRet), "FormData"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "append", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "append", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "delete", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "has", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "get", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "getAll", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "set", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(FormDataArg), "set", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));

    //URLSearchParams
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "set", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "append", {HANDLE_ARG(StringArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "delete", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "has", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "get", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(URLSearchParamsArg), "getAll", {HANDLE_ARG(StringArg)}));

    //DOMTokenList
    add_api(std::make_shared<ListItemTemplate>(nullptr, HANDLE_ARG(DOMTokenListArg)));
    add_api(std::make_shared<ListRemoveTemplate>(HANDLE_ARG(DOMTokenListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMTokenListArg), "add", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMTokenListArg), "contains", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMTokenListArg), "supports", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(DOMTokenListArg), "toggle", {HANDLE_ARG(StringArg), HANDLE_ARG(BooleanArg)}));
}