#include "css_var.h"
#include "css_val.h"
#include "common_val.h"
#include "serialize_variables.h"
#include <assert.h>

HIRMutate::CSS::CSSVariableDeclaration::CSSVariableDeclaration(const string &name, VALUE::Value *value)
{
    this->name = name;
    this->value = value;
#ifdef DEBUG_MEM
    std::cout << "CSSVariableDeclaration(" << name << ")" << std::endl;
#endif
}
HIRMutate::CSS::CSSVariableDeclaration::~CSSVariableDeclaration()
{
    if (value)
        delete value;
#ifdef DEBUG_MEM
    std::cout << "~CSSVariableDeclaration(" << name << ")" << std::endl;
#endif
}
bool HIRMutate::CSS::CSSVariableDeclaration::mutate(DOMContext *context)
{
    return value->mutate(context);
}

void HIRMutate::CSS::CSSVariableDeclaration::generate(DOMContext *context)
{
    value->generate(context);
}

void HIRMutate::CSS::CSSVariableDeclaration::merge_fix(map<Object *, Object *> &merge_map)
{
    value->merge_fix(merge_map);
}

HIRMutate::CSS::CSSVariableDeclaration::operator string()
{
    string ans = name;
    ans.append(": ");
    ans.append(value->getValue());
    return ans;
}

void HIRMutate::CSS::CSSVariableDeclaration::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(name);
    value->serialize(stream, context);
}

void HIRMutate::CSS::CSSVariableDeclaration::unserialize(UnSerializeStream *stream, Document *global_document)
{
    name = stream->read_string();
    if (value)
        delete value;
    value = value_classes[stream->read_string()](stream, global_document, nullptr);
}

HIRMutate::CSS::CSSVariables::CSSVariables()
{
    variables.push_back(new CSSVariableDeclaration("--css-color", new ColorValue()));
    variables.push_back(new CSSVariableDeclaration("--css-length", new COMMON::LengthValue()));
    variables.push_back(new CSSVariableDeclaration("--css-length-percent", new COMMON::LengthPercentageValue()));
    variables.push_back(new CSSVariableDeclaration("--css-line-width", new LineWidthValue()));
#ifdef DEBUG_MEM
    std::cout << "CSSVariables()" << std::endl;
#endif
}

HIRMutate::CSS::CSSVariables::~CSSVariables()
{
    std::for_each(variables.begin(), variables.end(),
                  [](CSSVariableDeclaration *var)
                  {
                      delete var;
                  });
#ifdef DEBUG_MEM
    std::cout << "~CSSVariables()" << std::endl;
#endif
}

bool HIRMutate::CSS::CSSVariables::mutate(DOMContext *context)
{
    CSSVariableDeclaration *var = CHOICE_OBJ(variables);
    return var->mutate(context);
}

void HIRMutate::CSS::CSSVariables::generate(DOMContext *context)
{
    std::for_each(variables.begin(), variables.end(),
                  [&context](CSSVariableDeclaration *var)
                  {
                      var->generate(context);
                  });
}

void HIRMutate::CSS::CSSVariables::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(variables.begin(), variables.end(),
                  [&merge_map](CSSVariableDeclaration *var)
                  {
                      var->merge_fix(merge_map);
                  });
}

HIRMutate::CSS::CSSVariables::operator string()
{
    string s = ":root {\n";
    std::for_each(variables.begin(), variables.end(),
                  [&s](CSSVariableDeclaration *var)
                  {
                      s.append("  ");
                      s.append(var->operator string());
                      s.append(";\n");
                  });
    s.append("}");
    return s;
}

void HIRMutate::CSS::CSSVariables::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSVariables");
    int len = variables.size();
    for (int i = 0; i < 4; i++)
    {
        variables[i]->serialize(stream, context);
    }
}

void HIRMutate::CSS::CSSVariables::unserialize(UnSerializeStream *stream, Document *global_document)
{
    if (stream->read_string() != "CSSVariables")
    {
        puts("CSSVariables::unserialize Error!");
        abort();
    }
    int len = variables.size();
    for (int i = 0; i < len; i++)
    {
        variables[i]->unserialize(stream, global_document);
    }
}