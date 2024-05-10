#include "ret.h"
#include "assert.h"
#include "serialize_variables.h"

HIRMutate::JS::Ret::Ret()
{
    name = "Object";
    obj = nullptr;
}
HIRMutate::JS::Ret::Ret(const string &name)
{
    this->name = name;
    obj = nullptr;
}
HIRMutate::JS::Ret::~Ret()
{
    //obj在这里为弱引用，不应该随着Ret的消失而消失
}

void HIRMutate::JS::Ret::generate(JSContext *context)
{
    obj = context->create_object(name);
    context->set_object_to_be_handled(obj);
}

void HIRMutate::JS::Ret::merge_fix(JSContext *context)
{
    obj->id = "";
    context->add_object(obj, true);
}

HIRMutate::JS::Ret::operator string()
{
    assert(obj != nullptr);
    return obj->id;
}

void HIRMutate::JS::Ret::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("Ret");
    stream->write_string(name);
    obj->serialize_weak(stream, context);
}

void HIRMutate::JS::Ret::unserialize(UnSerializeStream *stream, Function *function)
{
    name = stream->read_string();
    stream->read_obj_ref_in_js_context((size_t)&obj, function);
}