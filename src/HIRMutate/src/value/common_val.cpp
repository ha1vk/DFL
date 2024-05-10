#include "common_val.h"

void HIRMutate::COMMON::EmptyValue::generate(Context *context)
{
    value = "";
}
void HIRMutate::COMMON::EmptyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("EmptyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::COMMON::YesOrNoValue::generate(Context *context)
{
    if (Random::gbool())
    {
        value = "yes";
    }
    else
    {
        value = "no";
    }
}
void HIRMutate::COMMON::YesOrNoValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("YesOrNoValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::BooleanValue::generate(Context *context)
{
    value = DOMValue::boolean();
}
void HIRMutate::COMMON::BooleanValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BooleanValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::StringValue::generate(Context *context)
{
    value = Random::gstring();
}
void HIRMutate::COMMON::StringValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("StringValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::COMMON::IntegerValue::generate(Context *context)
{
    value = Random::integer();
}
void HIRMutate::COMMON::IntegerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("IntegerValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::IntegerLengthValue::generate(Context *context)
{
    if (Random::gbool())
        value = Random::integer();
    else
        value = DOMValue::length();
}
void HIRMutate::COMMON::IntegerLengthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("IntegerLengthValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::SignedIntegerValue::generate(Context *context)
{
    value = Random::signed_integer();
}
void HIRMutate::COMMON::SignedIntegerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SignedIntegerValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::NumberValue::generate(Context *context)
{
    value = Random::number();
}
void HIRMutate::COMMON::NumberValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("NumberValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::NumberOptionalNumberValue::generate(Context *context)
{
    value = DOMValue::number_optional_number(false);
}
void HIRMutate::COMMON::NumberOptionalNumberValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("NumberOptionalNumberValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::SignedNumberOptionalNumberValue::generate(Context *context)
{
    value = DOMValue::number_optional_number(true);
}
void HIRMutate::COMMON::SignedNumberOptionalNumberValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SignedNumberOptionalNumberValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::LengthValue::generate(Context *context)
{
    value = DOMValue::length();
}
void HIRMutate::COMMON::LengthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LengthValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::LengthPercentageValue::generate(Context *context)
{
    value = DOMValue::length_percentage();
}
void HIRMutate::COMMON::LengthPercentageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LengthPercentageValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::LengthPercentageIntegerValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::length_percentage();
    else
        value = Random::integer();
}
void HIRMutate::COMMON::LengthPercentageIntegerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LengthPercentageIntegerValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::AngleValue::generate(Context *context)
{
    value = DOMValue::angle();
}
void HIRMutate::COMMON::AngleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AngleValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::IndexValue::generate(Context *context)
{
    value = DOMValue::index();
}
void HIRMutate::COMMON::IndexValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("IndexValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::ClockValue::generate(Context *context)
{
    value = DOMValue::clock();
}
void HIRMutate::COMMON::ClockValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClockValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::CharValue::generate(Context *context)
{
    value = Random::gchar();
}
void HIRMutate::COMMON::CharValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CharValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::OnOrOffValue::generate(Context *context)
{
    if (Random::gbool())
    {
        value = "on";
    }
    else
    {
        value = "off";
    }
}
void HIRMutate::COMMON::OnOrOffValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OnOrOffValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::RegexValue::generate(Context *context)
{
    value = DOMValue::regex();
}
void HIRMutate::COMMON::RegexValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RegexValue");
    StaticValue::serialize(stream, context);
}
void HIRMutate::COMMON::ClockInMsValue::generate(Context *context)
{
    value = DOMValue::clock_in_ms();
}
void HIRMutate::COMMON::ClockInMsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClockInMsValue");
    StaticValue::serialize(stream, context);
}

void *HIRMutate::COMMON::EmptyValue::getConstructor()
{
    return HANDLE_VOID(EmptyValue);
}
void *HIRMutate::COMMON::YesOrNoValue::getConstructor()
{
    return HANDLE_VOID(YesOrNoValue);
}
void *HIRMutate::COMMON::BooleanValue::getConstructor()
{
    return HANDLE_VOID(BooleanValue);
}
void *HIRMutate::COMMON::StringValue::getConstructor()
{
    return HANDLE_VOID(StringValue);
}
void *HIRMutate::COMMON::IntegerValue::getConstructor()
{
    return HANDLE_VOID(IntegerValue);
}
void *HIRMutate::COMMON::IntegerLengthValue::getConstructor()
{
    return HANDLE_VOID(IntegerLengthValue);
}
void *HIRMutate::COMMON::SignedIntegerValue::getConstructor()
{
    return HANDLE_VOID(SignedIntegerValue);
}
void *HIRMutate::COMMON::NumberValue::getConstructor()
{
    return HANDLE_VOID(NumberValue);
}
void *HIRMutate::COMMON::NumberOptionalNumberValue::getConstructor()
{
    return HANDLE_VOID(NumberOptionalNumberValue);
}
void *HIRMutate::COMMON::SignedNumberOptionalNumberValue::getConstructor()
{
    return HANDLE_VOID(SignedNumberOptionalNumberValue);
}
void *HIRMutate::COMMON::LengthValue::getConstructor()
{
    return HANDLE_VOID(LengthValue);
}
void *HIRMutate::COMMON::LengthPercentageValue::getConstructor()
{
    return HANDLE_VOID(LengthPercentageValue);
}
void *HIRMutate::COMMON::LengthPercentageIntegerValue::getConstructor()
{
    return HANDLE_VOID(LengthPercentageIntegerValue);
}
void *HIRMutate::COMMON::AngleValue::getConstructor()
{
    return HANDLE_VOID(AngleValue);
}
void *HIRMutate::COMMON::IndexValue::getConstructor()
{
    return HANDLE_VOID(IndexValue);
}
void *HIRMutate::COMMON::ClockValue::getConstructor()
{
    return HANDLE_VOID(ClockValue);
}
void *HIRMutate::COMMON::CharValue::getConstructor()
{
    return HANDLE_VOID(CharValue);
}
void *HIRMutate::COMMON::OnOrOffValue::getConstructor()
{
    return HANDLE_VOID(OnOrOffValue);
}
void *HIRMutate::COMMON::RegexValue::getConstructor()
{
    return HANDLE_VOID(RegexValue);
}
void *HIRMutate::COMMON::ClockInMsValue::getConstructor()
{
    return HANDLE_VOID(ClockInMsValue);
}