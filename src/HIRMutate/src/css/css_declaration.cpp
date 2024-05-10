#include "css_declaration.h"
#include "serialize_variables.h"

HIRMutate::CSS::CSSDeclaration::CSSDeclaration(const string &prop, Value *value)
{
    this->prop = prop;
    this->value = value;
#ifdef DEBUG_MEM
    std::cout << "CSSDeclaration(" << prop << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSDeclaration::~CSSDeclaration()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSDeclaration(" << prop << ")" << std::endl;
#endif
    if (value != nullptr)
    {
        delete value;
    }
}

void HIRMutate::CSS::CSSDeclaration::generate(DOMContext *context)
{
    value->generate(context);
}

bool HIRMutate::CSS::CSSDeclaration::mutate(DOMContext *context)
{
    return value->mutate(context);
}

void HIRMutate::CSS::CSSDeclaration::merge_fix(map<Object *, Object *> &merge_map)
{
    value->merge_fix(merge_map);
}

string HIRMutate::CSS::CSSDeclaration::getValue()
{
    string ans = prop;
    ans.append(": ");
    ans.append(value->getValue());
    return ans;
}

HIRMutate::CSS::CSSDeclaration *HIRMutate::CSS::create_css_declaration(bool animatable)
{
    std::pair<string, Value *(*)(void)> p = get_css_property(animatable);
    return new CSSDeclaration(p.first, p.second());
}

HIRMutate::CSS::CSSStyleDeclaration::CSSStyleDeclaration(bool animate)
{
    this->animate = animate;
#ifdef DEBUG_MEM
    std::cout << "CSSStyleDeclaration(" << animate << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSStyleDeclaration::~CSSStyleDeclaration()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSStyleDeclaration(" << animate << ")" << std::endl;
#endif
    std::for_each(declarations.begin(), declarations.end(),
                  [](CSSDeclaration *decl)
                  {
                      delete decl;
                  });
}

bool HIRMutate::CSS::CSSStyleDeclaration::append(DOMContext *context)
{
    if (declarations.size() >= CSSConfig::max_css_decl_count)
        return false;
    CSSDeclaration *decl = create_css_declaration(animate);
    decl->generate(context);
    declarations.push_back(decl);
    return true;
}

bool HIRMutate::CSS::CSSStyleDeclaration::mutate(DOMContext *context)
{
    int c = Random::selector(4);
    if (c == 0 || declarations.size() == 0)
        return append(context);
    else if (c == 1)
    { //随机删除一个属性
        vector<CSSDeclaration *>::iterator it = declarations.begin() + Random::selector(declarations.size());
        CSSDeclaration *decl = *it;
        delete decl;
        declarations.erase(it);
        return append(context);
    }
    else
    { //随机对一个属性进行变异
        CSSDeclaration *decl = CHOICE_OBJ(declarations);
        return decl->mutate(context);
    }
}

void HIRMutate::CSS::CSSStyleDeclaration::generate(DOMContext *context)
{
    append(context);
}

//合并另一个CSS的所有属性
void HIRMutate::CSS::CSSStyleDeclaration::merge(CSSStyleDeclaration *other)
{
    declarations.insert(declarations.end(), other->declarations.begin(), other->declarations.end());
}

void HIRMutate::CSS::CSSStyleDeclaration::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(declarations.begin(), declarations.end(),
                  [&merge_map](CSSDeclaration *decl)
                  {
                      decl->merge_fix(merge_map);
                  });
}

string HIRMutate::CSS::CSSStyleDeclaration::getValue()
{
    string ans = "";
    int len = declarations.size();
    for (int i = 0; i < len; i++)
    {
        ans.append(declarations[i]->getValue());
        if (i != len - 1)
        {
            ans.append(";");
        }
    }
    return ans;
}

HIRMutate::CSS::CSSStyleDeclarationValue::CSSStyleDeclarationValue()
{
    style_declaration = new CSSStyleDeclaration();
#ifdef DEBUG_MEM
    std::cout << "CSSStyleDeclarationValue()" << std::endl;
#endif
}

HIRMutate::CSS::CSSStyleDeclarationValue::~CSSStyleDeclarationValue()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSStyleDeclarationValue()" << std::endl;
#endif
    delete style_declaration;
}

void HIRMutate::CSS::CSSStyleDeclarationValue::generate(Context *context)
{
    DOMContext *ctx = (DOMContext *)context;
    style_declaration->generate(ctx);
    for (int i = 0; i < CSSConfig::max_css_internal_decl_count - 1; i++)
    {
        style_declaration->append(ctx);
    }
}

bool HIRMutate::CSS::CSSStyleDeclarationValue::mutate(Context *context)
{
    return style_declaration->mutate((DOMContext *)context);
}

void HIRMutate::CSS::CSSStyleDeclarationValue::merge_fix(map<Object *, Object *> &merge_map)
{
    style_declaration->merge_fix(merge_map);
}

string HIRMutate::CSS::CSSStyleDeclarationValue::getValue()
{
    return style_declaration->getValue();
}

void HIRMutate::CSS::CSSDeclaration::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(prop);
    value->serialize(stream, context);
}

void HIRMutate::CSS::CSSDeclaration::unserialize(UnSerializeStream *stream, Document *global_document)
{
    prop = stream->read_string();
    value = value_classes[stream->read_string()](stream, global_document, nullptr);
}

void HIRMutate::CSS::CSSStyleDeclaration::serialize(SerializeStream *stream, Context *context)
{
    stream->write_byte(animate);
    stream->write_int(declarations.size());
    std::for_each(declarations.begin(), declarations.end(),
                  [&stream, &context](CSSDeclaration *decl)
                  {
                      decl->serialize(stream, context);
                  });
}

void HIRMutate::CSS::CSSStyleDeclaration::unserialize(UnSerializeStream *stream, Document *global_document)
{
    animate = stream->read_byte();
    int d_s = stream->read_int();
    for (int i = 0; i < d_s; i++)
    {
        CSSDeclaration *decl = new CSSDeclaration();
        decl->unserialize(stream, global_document);
        declarations.push_back(decl);
    }
}

void *HIRMutate::CSS::CSSStyleDeclarationValue::getConstructor()
{
    return HANDLE_VOID(CSSStyleDeclarationValue);
}

void HIRMutate::CSS::CSSStyleDeclarationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSStyleDeclarationValue");
    DynamicValue::serialize(stream, context);
    style_declaration->serialize(stream, context);
}

void HIRMutate::CSS::CSSStyleDeclarationValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    style_declaration->unserialize(stream, global_document);
}