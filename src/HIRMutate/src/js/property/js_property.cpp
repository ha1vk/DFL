#include "js_property.h"
#include "assert.h"
#include "serialize_variables.h"

HIRMutate::JS::LoadProperty::LoadProperty(Ret *ret, Arg *this_obj, string &prop) : API(ret, this_obj)
{
    this->prop = prop;
}

void HIRMutate::JS::LoadProperty::generate(JSContext *context)
{
    this_obj->generate(context);
    if (ret != nullptr)
        ret->generate(context);
}

bool HIRMutate::JS::LoadProperty::mutate(JSContext *context)
{
    return this_obj->mutate(context);
}

void HIRMutate::JS::LoadProperty::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::LoadProperty::operator string()
{
    string ans;
    if (ret == nullptr)
    {
        ans = this_obj->operator string();
        ans.append(".");
        ans.append(prop);
        return ans;
    }
    else
    {
        ans = "var ";
        ans.append(ret->operator string());
        ans.append(" = ");
        ans.append(this_obj->operator string());
        ans.append(".");
        ans.append(prop);
        return ans;
    }
}
void HIRMutate::JS::LoadProperty::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("LoadProperty");
    API::serialize(stream, context);
    stream->write_string(prop);
}

void HIRMutate::JS::LoadProperty::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    prop = stream->read_string();
}

HIRMutate::JS::StoreProperty::StoreProperty(Arg *value, Arg *this_obj, string &prop) : API(nullptr, this_obj)
{
    this->value = value;
    this->prop = prop;
}
HIRMutate::JS::StoreProperty::~StoreProperty()
{
    if (value)
        delete value;
}
void HIRMutate::JS::StoreProperty::generate(JSContext *context)
{
    this_obj->generate(context);
    value->generate(context);
}

bool HIRMutate::JS::StoreProperty::mutate(JSContext *context)
{
    if (Random::gbool())
        return this_obj->mutate(context);
    else
        return value->mutate(context);
}

void HIRMutate::JS::StoreProperty::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    value->merge_fix(merge_map);
}

HIRMutate::JS::StoreProperty::operator string()
{
    string ans = this_obj->operator string();
    ans.append(".");
    ans.append(prop);
    ans.append(" = ");
    ans.append(value->operator string());
    return ans;
}
void HIRMutate::JS::StoreProperty::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("StoreProperty");
    API::serialize(stream, context);
    stream->write_string(prop);
    value->serialize(stream, context);
}
void HIRMutate::JS::StoreProperty::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    prop = stream->read_string();
    value = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::LoadPropertyTemplate::LoadPropertyTemplate(Ret *(*ret_class)(), Arg *(*this_class)(), const string &prop) : APITemplate(ret_class, this_class)
{
    this->prop = prop;
}

HIRMutate::JS::API *HIRMutate::JS::LoadPropertyTemplate::instantiate()
{
    Ret *ret = nullptr;
    if (ret_class != nullptr)
    {
        ret = ret_class();
    }
    Arg *this_obj = this_class();
    return new LoadProperty(ret, this_obj, prop);
}

bool HIRMutate::JS::LoadPropertyTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::StorePropertyTemplate::StorePropertyTemplate(Arg *(*value_class)(), Arg *(*this_class)(), const string &prop) : APITemplate(nullptr, this_class)
{
    this->value_class = value_class;
    this->prop = prop;
}

HIRMutate::JS::API *HIRMutate::JS::StorePropertyTemplate::instantiate()
{
    if (value_class == nullptr)
    {
        puts("StorePropertyTemplate::instantiate Error!");
        abort();
    }
    Arg *value = value_class();
    Arg *this_obj = this_class();
    return new StoreProperty(value, this_obj, prop);
}

bool HIRMutate::JS::StorePropertyTemplate::satiable(JSContext *context)
{
    Arg *arg = value_class();
    bool res = is_satiable_arg(arg, context);
    delete arg;
    return res;
}