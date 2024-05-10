#include "Value.h"

bool HIRMutate::VALUE::Value::mutate(Context *context)
{
    generate(context);
    return true;
}

string HIRMutate::VALUE::Value::getValue()
{
    return value;
}

void HIRMutate::VALUE::Value::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(value);
}
void HIRMutate::VALUE::Value::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    value = stream->read_string();
}
void HIRMutate::VALUE::StaticValue::serialize(SerializeStream *stream, Context *context)
{
    Value::serialize(stream, context);
}
void *HIRMutate::VALUE::StaticValue::getConstructor()
{
    return HANDLE_VOID(StaticValue);
}

HIRMutate::VALUE::ConstValue::ConstValue(string val)
{
    this->value = val;
}

void *HIRMutate::VALUE::ConstValue::getConstructor()
{
    return HANDLE_VOID(ConstValue);
}

bool HIRMutate::VALUE::ConstValue::mutate(Context *context)
{
    return false;
}
void HIRMutate::VALUE::ConstValue::generate(Context *context)
{
}

void HIRMutate::VALUE::ConstValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ConstValue");
    StaticValue::serialize(stream, context);
}

HIRMutate::VALUE::DynamicValue::DynamicValue()
{
}
HIRMutate::VALUE::DynamicValue::DynamicValue(string val)
{
    this->value = val;
}

void HIRMutate::VALUE::DynamicValue::serialize(SerializeStream *stream, Context *context)
{
    Value::serialize(stream, context);
}