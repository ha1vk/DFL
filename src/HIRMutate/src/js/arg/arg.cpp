#include "arg.h"
#include "assert.h"
#include "serialize_variables.h"

bool HIRMutate::JS::Arg::mutate(JSContext *context)
{
    generate(context);
    return true;
}

void HIRMutate::JS::Arg::merge_fix(map<Object *, Object *> &merge_map)
{
}

void HIRMutate::JS::Arg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string(name);
}

void HIRMutate::JS::Arg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    name = stream->read_string();
}

HIRMutate::JS::ObjectArg::ObjectArg()
{
    name = "Object";
    obj = nullptr;
}

HIRMutate::JS::ObjectArg::ObjectArg(const char *name)
{
    this->name = name;
    obj = nullptr;
}

bool HIRMutate::JS::ObjectArg::is_object()
{
    return true;
}

void HIRMutate::JS::ObjectArg::generate(JSContext *context)
{
    obj = context->get_offspring(name);
    //assert(obj != nullptr);
}

void HIRMutate::JS::ObjectArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (obj != nullptr)
    {
        if (merge_map.find(obj) != merge_map.end())
        {
            obj = merge_map[obj];
        }
    }
}

HIRMutate::JS::ObjectArg::operator string()
{
    if (obj == nullptr)
        return "foo";
    return obj->id;
}

void HIRMutate::JS::ObjectArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ObjectArg");
    Arg::serialize(stream, context);
    if (obj != nullptr)
    {
        if (context->find_obj_in_pool(obj).second == -1)
        { //该obj来源于DOMContext
            stream->write_string("from DOMContext");
            obj->serialize_weak(stream, ((JSContext *)context)->global_context);
        }
        else
        {
            stream->write_string("from JSContext");
            obj->serialize_weak(stream, context);
        }
    }
    else
        stream->write_string("nullptr");
}

void HIRMutate::JS::ObjectArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "ObjectArg")
        {
            puts("ObjectArg::unserialize Error!");
            abort();
        }
    }
    Arg::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        obj = nullptr;
        stream->skip_string();
    }
    else
    {
        string where = stream->read_string();
        if (where == "from JSContext")
        {
            stream->read_obj_ref_in_js_context((size_t)&obj, function);
        }
        else
        {
            stream->read_obj_ref((size_t)&obj, global_document);
        }
    }
}

HIRMutate::JS::DummyArg::DummyArg() : ObjectArg("Dummy")
{
}

HIRMutate::JS::ValueArg::ValueArg()
{
}

bool HIRMutate::JS::ValueArg::is_object()
{
    return false;
}

HIRMutate::JS::ValueArg::operator string()
{
    return value;
}

void HIRMutate::JS::ValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ValueArg");
    Arg::serialize(stream, context);
    stream->write_string(value);
}

void HIRMutate::JS::ValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "ValueArg")
        {
            puts("ValueArg::unserialize Error!");
            abort();
        }
    }
    Arg::unserialize(stream, global_document, function);
    value = stream->read_string();
}

HIRMutate::JS::ConstValueArg::ConstValueArg(const string &value)
{
    this->value = value;
}

void HIRMutate::JS::ConstValueArg::generate(JSContext *context)
{
}

void HIRMutate::JS::ConstValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ConstValueArg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::ConstValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}

HIRMutate::JS::StringSetArg::StringSetArg(const vector<string> &strings)
{
    this->strings = strings;
}

void HIRMutate::JS::StringSetArg::generate(JSContext *context)
{
    if (strings.size() > 0)
        value = CHOICE_OBJ(strings);
    else
        value = Random::gstring();
}

HIRMutate::JS::StringSetArg::operator string()
{
    string ans = "\"";
    ans.append(value);
    ans.append("\"");
    return ans;
}

void HIRMutate::JS::StringSetArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("StringSetArg");
    ValueArg::serialize(stream, context);
    stream->write_int(strings.size());
    std::for_each(strings.begin(), strings.end(),
                  [&stream](string &val)
                  {
                      stream->write_string(val);
                  });
}

void HIRMutate::JS::StringSetArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "StringSetArg")
        {
            puts("StringSetArg::unserialize Error!");
            abort();
        }
    }
    ValueArg::unserialize(stream, global_document, function, true);
    int strings_len = stream->read_int();
    for (int i = 0; i < strings_len; i++)
    {
        strings.push_back(stream->read_string());
    }
}

void HIRMutate::JS::Float01Arg::generate(JSContext *context)
{
    value = Random::float01();
}

void HIRMutate::JS::Float01Arg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("Float01Arg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::Float01Arg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::FloatArg::generate(JSContext *context)
{
    value = Random::number();
}

void HIRMutate::JS::FloatArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FloatArg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::FloatArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::StringArg::generate(JSContext *context)
{
    value = Random::gstring();
}

HIRMutate::JS::StringArg::operator string()
{
    string ans = "\"";
    ans.append(value);
    ans.append("\"");
    return ans;
}

void HIRMutate::JS::StringArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("StringArg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::StringArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "StringArg")
        {
            puts("StringArg::unserialize Error!");
            abort();
        }
    }
    ValueArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::StringArrayArg::generate(JSContext *context)
{
    value = "[\"";
    value.append(Random::gstring());
    value.append("\"]");
}

void HIRMutate::JS::StringArrayArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("StringArrayArg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::StringArrayArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::FloatStringArg::generate(JSContext *context)
{
    value = Random::number();
}

void HIRMutate::JS::FloatStringArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FloatStringArg");
    StringArg::serialize(stream, context);
}

void HIRMutate::JS::FloatStringArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::LengthPercentageArg::generate(JSContext *context)
{
    value = DOMValue::length_percentage();
}

void HIRMutate::JS::LengthPercentageArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("LengthPercentageArg");
    StringArg::serialize(stream, context);
}

void HIRMutate::JS::LengthPercentageArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::CharArg::generate(JSContext *context)
{
    value = Random::gchar();
}

void HIRMutate::JS::CharArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CharArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CharArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ColorArg::generate(JSContext *context)
{
    value = DOMValue::color();
}

void HIRMutate::JS::ColorArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ColorArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ColorArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::ConstStringArg::ConstStringArg(const string &value)
{
    this->value = value;
}

void HIRMutate::JS::ConstStringArg::generate(JSContext *context)
{
    if (value == "")
        value = Random::gstring();
}

void HIRMutate::JS::ConstStringArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ConstStringArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ConstStringArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::DoNothingArg::generate(JSContext *context)
{
    value = "doNothing";
}

void HIRMutate::JS::DoNothingArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DoNothingArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::DoNothingArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::BooleanArg::generate(JSContext *context)
{
    value = DOMValue::boolean();
}

void HIRMutate::JS::BooleanArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("BooleanArg");
    ValueArg::serialize(stream, context);
}

void HIRMutate::JS::BooleanArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}

void HIRMutate::JS::IntegerArg::generate(JSContext *context)
{
    value = Random::integer();
}

void HIRMutate::JS::IntegerArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("IntegerArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::IntegerArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::RangedIntegerArg::RangedIntegerArg(int low, int high)
{
    this->low = low;
    this->high = high;
}

void HIRMutate::JS::RangedIntegerArg::generate(JSContext *context)
{
    value = Random::range_s(low, high);
}

void HIRMutate::JS::RangedIntegerArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RangedIntegerArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::RangedIntegerArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::RandomSelectorArg::RandomSelectorArg() : RangedIntegerArg(0, 100)
{
}

void HIRMutate::JS::NullArg::generate(JSContext *context)
{
}

HIRMutate::JS::NullArg::operator string()
{
    return "null";
}

void HIRMutate::JS::NullArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("NullArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::NullArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::IndexArg::generate(JSContext *context)
{
    value = DOMValue::index();
}

void HIRMutate::JS::IndexArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("IndexArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::IndexArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
// ENUM
void HIRMutate::JS::EnumArg::generate(JSContext *context)
{
    value = Random::range_s(0, 16);
}
void HIRMutate::JS::EnumArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("EnumArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::EnumArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ClockArg::generate(JSContext *context)
{
    value = DOMValue::clock_in_s();
}
void HIRMutate::JS::ClockArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ClockArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::ClockArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ClockInMsArg::generate(JSContext *context)
{
    value = DOMValue::clock_in_ms();
}
void HIRMutate::JS::ClockInMsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ClockInMsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::ClockInMsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::RegexArg::generate(JSContext *context)
{
    value = DOMValue::regex();
}

void HIRMutate::JS::RegexArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RegexArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::RegexArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}