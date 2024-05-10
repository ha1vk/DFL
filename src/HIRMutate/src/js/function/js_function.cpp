#include "js_function.h"
#include "js_property.h"
#include "serialize_variables.h"

HIRMutate::JS::CallFunction::CallFunction(Ret *ret, Arg *arg0, const string &method, vector<Arg *> args) : API(ret, arg0)
{
    this->method = method;
    this->args = args;
}

HIRMutate::JS::CallFunction::~CallFunction()
{
    std::for_each(args.begin(), args.end(),
                  [](Arg *arg)
                  {
                      delete arg;
                  });
}

void HIRMutate::JS::CallFunction::generate(JSContext *context)
{
    this_obj->generate(context);
    std::for_each(args.begin(), args.end(),
                  [&context](Arg *arg)
                  {
                      arg->generate(context);
                  });
    if (ret != nullptr)
    {
        ret->generate(context);
    }
}
bool HIRMutate::JS::CallFunction::mutate(JSContext *context)
{
    int c = Random::selector(1 + args.size());
    if (c == 0)
    {
        return this_obj->mutate(context);
    }
    else
    {
        Arg *arg = CHOICE_OBJ(args);
        return arg->mutate(context);
    }
}

void HIRMutate::JS::CallFunction::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    std::for_each(args.begin(), args.end(),
                  [&merge_map](Arg *arg)
                  {
                      arg->merge_fix(merge_map);
                  });
}

HIRMutate::JS::CallFunction::operator string()
{
    string ans = "";
    if (ret != nullptr)
    {
        ans.append("var ");
        ans.append(ret->operator string());
        ans.append(" = ");
    }
    ans.append(this_obj->operator string());
    ans.append(".");
    ans.append(method);
    ans.append("(");
    int len = args.size();
    for (int i = 0; i < len; i++)
    {
        Arg *arg = args[i];
        ans.append(arg->operator string());
        if (i != len - 1)
        {
            ans.append(",");
        }
    }
    ans.append(")");
    return ans;
}
void HIRMutate::JS::CallFunction::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CallFunction");
    API::serialize(stream, context);
    stream->write_string(method);
    stream->write_int(args.size());
    std::for_each(args.begin(), args.end(),
                  [&stream, &context](Arg *arg)
                  {
                      arg->serialize(stream, context);
                  });
}
void HIRMutate::JS::CallFunction::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    method = stream->read_string();
    int arg_count = stream->read_int();
    for (int i = 0; i < arg_count; i++)
    {
        Arg *a = arg_classes[stream->read_string()](stream, global_document, function);
        args.push_back(a);
    }
}
HIRMutate::JS::FunctionTemplate::FunctionTemplate(Ret *(*ret_class)(), Arg *(*this_class)(), const string &method, vector<Arg *(*)()> arg_classes) : APITemplate(ret_class, this_class)
{
    this->method = method;
    this->arg_classes = arg_classes;
}

HIRMutate::JS::API *HIRMutate::JS::FunctionTemplate::instantiate()
{
    vector<Arg *> args;

    std::for_each(arg_classes.begin(), arg_classes.end(),
                  [&args](Arg *(*arg_class)())
                  {
                      args.push_back(arg_class());
                  });

    Ret *ret = nullptr;
    if (ret_class != nullptr)
    {
        ret = ret_class();
    }
    Arg *this_obj = this_class();
    return new CallFunction(ret, this_obj, method, args);
}

bool HIRMutate::JS::FunctionTemplate::satiable(JSContext *context)
{
    std::for_each(arg_classes.begin(), arg_classes.end(),
                  [&context](Arg *(*arg_class)())
                  {
                      Arg *arg = arg_class();
                      if (!is_satiable_arg(arg, context))
                      {
                          delete arg;
                          return false;
                      }
                      delete arg;
                  });
    return true;
}

HIRMutate::JS::Construct::Construct(Ret *ret, const string &ctor, vector<Arg *> args) : API(ret, nullptr)
{
    this->ctor = ctor;
    this->args = args;
}
HIRMutate::JS::Construct::~Construct()
{
    std::for_each(args.begin(), args.end(),
                  [](Arg *arg)
                  {
                      delete arg;
                  });
}
void HIRMutate::JS::Construct::generate(JSContext *context)
{
    std::for_each(args.begin(), args.end(),
                  [&context](Arg *arg)
                  {
                      arg->generate(context);
                  });
    ret->generate(context);
}

bool HIRMutate::JS::Construct::mutate(JSContext *context)
{
    if (args.size() == 0)
    {
        return false;
    }

    Arg *arg = CHOICE_OBJ(args);
    return arg->mutate(context);
}

void HIRMutate::JS::Construct::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(args.begin(), args.end(),
                  [&merge_map](Arg *arg)
                  {
                      arg->merge_fix(merge_map);
                  });
}

HIRMutate::JS::Construct::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = new ");
    ans.append(ctor);
    ans.append("(");
    int len = args.size();
    for (int i = 0; i < len; i++)
    {
        Arg *arg = args[i];
        ans.append(arg->operator string());
        if (i != len - 1)
        {
            ans.append(",");
        }
    }
    ans.append(")");
    return ans;
}
void HIRMutate::JS::Construct::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("Construct");
    API::serialize(stream, context);
    stream->write_string(ctor);
    stream->write_int(args.size());
    std::for_each(args.begin(), args.end(),
                  [&stream, &context](Arg *arg)
                  {
                      arg->serialize(stream, context);
                  });
}
void HIRMutate::JS::Construct::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    ctor = stream->read_string();
    int arg_count = stream->read_int();
    for (int i = 0; i < arg_count; i++)
    {
        Arg *a = arg_classes[stream->read_string()](stream, global_document, function);
        args.push_back(a);
    }
}
HIRMutate::JS::ConstructTemplate::ConstructTemplate(Ret *(*ret_class)(), const string &ctor, vector<Arg *(*)()> arg_classes) : APITemplate(ret_class, HANDLE_ARG(DummyArg))
{
    this->ctor = ctor;
    this->arg_classes = arg_classes;
}

HIRMutate::JS::API *HIRMutate::JS::ConstructTemplate::instantiate()
{
    vector<Arg *> args;
    std::for_each(arg_classes.begin(), arg_classes.end(),
                  [&args](Arg *(*arg_class)())
                  {
                      args.push_back(arg_class());
                  });
    Ret *ret = ret_class();
    return new Construct(ret, ctor, args);
}

bool HIRMutate::JS::ConstructTemplate::satiable(JSContext *context)
{
    std::for_each(arg_classes.begin(), arg_classes.end(),
                  [&context](Arg *(*arg_class)())
                  {
                      Arg *arg = arg_class();
                      if (!is_satiable_arg(arg, context))
                      {
                          delete arg;
                          return false;
                      }
                      delete arg;
                  });
    return true;
}

HIRMutate::JS::ConstructObject::ConstructObject(Ret *ret, map<string, Arg *> &shape) : API(ret, nullptr)
{
    this->shape = shape;
}
HIRMutate::JS::ConstructObject::~ConstructObject()
{
    std::for_each(shape.begin(), shape.end(),
                  [](map<string, Arg *>::reference i)
                  {
                      delete i.second;
                  });
}
void HIRMutate::JS::ConstructObject::generate(JSContext *context)
{
    std::for_each(shape.begin(), shape.end(),
                  [&context](map<string, Arg *>::reference i)
                  {
                      i.second->generate(context);
                  });
    ret->generate(context);
}

bool HIRMutate::JS::ConstructObject::mutate(JSContext *context)
{
    int len = shape.size();
    if (len == 0)
    {
        return false;
    }
    int idx = Random::selector(len);
    map<string, Arg *>::iterator it = shape.begin();
    for (int i = 0; i < idx; i++)
    {
        it++;
    }
    const std::pair<string, Arg *> &item = *it;
    Arg *value = item.second;
    return value->mutate(context);
}

void HIRMutate::JS::ConstructObject::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(shape.begin(), shape.end(),
                  [&merge_map](map<string, Arg *>::reference i)
                  {
                      i.second->merge_fix(merge_map);
                  });
}

HIRMutate::JS::ConstructObject::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = { ");
    int len = shape.size();
    int i = 0;
    std::for_each(shape.begin(), shape.end(),
                  [&ans, &i, &len](map<string, Arg *>::reference elem)
                  {
                      ans.append(elem.first);
                      ans.append(": ");
                      ans.append(elem.second->operator string());
                      i++;
                      if (i != len)
                      {
                          ans.append(",");
                      }
                  });
    ans.append("}");
    return ans;
}

void HIRMutate::JS::ConstructObject::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ConstructObject");
    API::serialize(stream, context);
    stream->write_int(shape.size());
    std::for_each(shape.begin(), shape.end(),
                  [&stream, &context](map<string, Arg *>::reference elem)
                  {
                      stream->write_string(elem.first);
                      elem.second->serialize(stream, context);
                  });
}
void HIRMutate::JS::ConstructObject::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    int s_s = stream->read_int();
    for (int i = 0; i < s_s; i++)
    {
        string key = stream->read_string();
        Arg *a = arg_classes[stream->read_string()](stream, global_document, function);
        shape[key] = a;
    }
}
HIRMutate::JS::ConstructObjectTemplate::ConstructObjectTemplate(Ret *(*ret_class)(), map<string, Arg *(*)()> &shape_classes) : APITemplate(ret_class, HANDLE_ARG(DummyArg))
{
    this->shape_classes = shape_classes;
}

HIRMutate::JS::API *HIRMutate::JS::ConstructObjectTemplate::instantiate()
{
    map<string, Arg *> shape;
    std::for_each(shape_classes.begin(), shape_classes.end(),
                  [&shape](map<string, Arg *(*)()>::reference i)
                  {
                      shape[i.first] = i.second();
                  });
    Ret *ret = ret_class();
    return new ConstructObject(ret, shape);
}

bool HIRMutate::JS::ConstructObjectTemplate::satiable(JSContext *context)
{
    std::for_each(shape_classes.begin(), shape_classes.end(),
                  [&context](map<string, Arg *(*)()>::reference i)
                  {
                      Arg *arg = i.second();
                      if (!is_satiable_arg(arg, context))
                      {
                          delete arg;
                          return false;
                      }
                      delete arg;
                  });
    return true;
}