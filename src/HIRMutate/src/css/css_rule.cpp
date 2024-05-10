#include "css_rule.h"
#include "DomValue.h"

HIRMutate::CSS::CSSStyleRule::CSSStyleRule()
{
    selector = create_css_selector();
    declaration = new CSSStyleDeclaration();
#ifdef DEBUG_MEM
    std::cout << "CSSStyleRule()" << std::endl;
#endif
}

HIRMutate::CSS::CSSStyleRule::~CSSStyleRule()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSStyleRule()" << std::endl;
#endif
    delete selector;
    delete declaration;
}

void HIRMutate::CSS::CSSStyleRule::generate(DOMContext *context)
{
    selector->generate(context);
    declaration->generate(context);
}

void HIRMutate::CSS::CSSStyleRule::append_selector(DOMContext *context)
{
    selector->append(context);
}

void HIRMutate::CSS::CSSStyleRule::append_decl(DOMContext *context)
{
    declaration->append(context);
}

bool HIRMutate::CSS::CSSStyleRule::mutate(DOMContext *context)
{
    int c = Random::selector(10);
    if (c == 0)
    {
        selector->append(context);
        return true;
    }
    else if (c == 1 || c == 2)
        return selector->mutate(context);
    else
        return declaration->mutate(context);
}

void HIRMutate::CSS::CSSStyleRule::merge_fix(map<Object *, Object *> &merge_map)
{
    selector->merge_fix(merge_map);
    declaration->merge_fix(merge_map);
}

HIRMutate::CSS::CSSStyleRule::operator string()
{
    string ans = selector->operator string();
    ans.append("{ ");
    ans.append(declaration->getValue());
    ans.append(" }");
    return ans;
}

HIRMutate::CSS::CSSKeyframeRule::CSSKeyframeRule(const string &name)
{
    this->name = name;
    declaration = new CSSStyleDeclaration(true);
#ifdef DEBUG_MEM
    std::cout << "CSSKeyframeRule(" << name << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSKeyframeRule::~CSSKeyframeRule()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSKeyframeRule(" << name << ")" << std::endl;
#endif
    delete declaration;
}

void HIRMutate::CSS::CSSKeyframeRule::generate(DOMContext *context)
{
    declaration->generate(context);
}

bool HIRMutate::CSS::CSSKeyframeRule::mutate(DOMContext *context)
{
    return declaration->mutate(context);
}

void HIRMutate::CSS::CSSKeyframeRule::merge(CSSKeyframeRule *other)
{
    declaration->merge(other->declaration);
}

void HIRMutate::CSS::CSSKeyframeRule::merge_fix(map<Object *, Object *> &merge_map)
{
    declaration->merge_fix(merge_map);
}

HIRMutate::CSS::CSSKeyframeRule::operator string()
{
    string ans = name;
    ans.append("{ ");
    ans.append(declaration->getValue());
    ans.append(" }");
    return ans;
}

HIRMutate::CSS::CSSKeyframesRule::CSSKeyframesRule(const string &name)
{
    this->name = name;
#ifdef DEBUG_MEM
    std::cout << "CSSKeyframesRule(" << name << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSKeyframesRule::~CSSKeyframesRule()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSKeyframesRule(" << name << ")" << std::endl;
#endif
    std::for_each(keyframe_rules.begin(), keyframe_rules.end(),
                  [](map<string, CSSKeyframeRule *>::reference i)
                  {
                      delete i.second;
                  });
}

string HIRMutate::CSS::CSSKeyframesRule::generate_keyframe_name()
{
    string name;
    while (true)
    {
        name = DOMValue::keyframe_name();
        if (keyframe_rules.find(name) == keyframe_rules.end())
            break;
    }
    return name;
}

void HIRMutate::CSS::CSSKeyframesRule::append_keyframe_rule(DOMContext *context)
{
    string keyframe_name = generate_keyframe_name();
    CSSKeyframeRule *keyframe_rule = new CSSKeyframeRule(keyframe_name);
    keyframe_rule->generate(context);
    keyframe_rules[keyframe_name] = keyframe_rule;
}

bool HIRMutate::CSS::CSSKeyframesRule::mutate(DOMContext *context)
{
    if (keyframe_rules.size() < CSSConfig::max_css_keyframe_count && Random::selector(3) == 0)
    {
        append_keyframe_rule(context);
        return true;
    }
    else
    {
        map<string, CSSKeyframeRule *>::iterator it = keyframe_rules.begin();
        int n = Random::selector(keyframe_rules.size());
        for (int i = 0; i < n; i++)
        {
            it++;
        }
        map<string, CSSKeyframeRule *>::reference i = *it;
        const string &keyframe_name = i.first;
        CSSKeyframeRule *keyframe_rule = i.second;
        if (Random::selector(5) == 0)
        {
            keyframe_rules.erase(keyframe_name);
            string name = generate_keyframe_name();
            keyframe_rules[name] = keyframe_rule;
            keyframe_rule->name = name;
            return true;
        }
        else
            return keyframe_rule->mutate(context);
    }
}
void HIRMutate::CSS::CSSKeyframesRule::generate(DOMContext *context)
{
    append_keyframe_rule(context);
}

void HIRMutate::CSS::CSSKeyframesRule::merge(CSSKeyframesRule *other)
{
    std::for_each(other->keyframe_rules.begin(), other->keyframe_rules.end(),
                  [this](map<string, CSSKeyframeRule *>::reference i)
                  {
                      const string &name = i.first;
                      if (this->keyframe_rules.find(name) != this->keyframe_rules.end())
                      {
                          this->keyframe_rules[name]->merge((i.second));
                      }
                      else
                      {
                          this->keyframe_rules[name] = i.second;
                      }
                  });
}

void HIRMutate::CSS::CSSKeyframesRule::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(keyframe_rules.begin(), keyframe_rules.end(),
                  [&merge_map](map<string, CSSKeyframeRule *>::reference i)
                  {
                      i.second->merge_fix(merge_map);
                  });
}

HIRMutate::CSS::CSSKeyframesRule::operator string()
{
    string s = "@keyframes ";
    s.append(name);
    s.append("{\n");
    std::for_each(keyframe_rules.begin(), keyframe_rules.end(),
                  [&s](map<string, CSSKeyframeRule *>::reference i)
                  {
                      s.append("  ");
                      s.append(i.second->operator string());
                      s.append("\n");
                  });
    s.append("}");
    return s;
}

HIRMutate::CSS::CSSStyleRule *HIRMutate::CSS::create_css_style_rule()
{
    return new CSSStyleRule();
}

HIRMutate::CSS::CSSKeyframesRule *HIRMutate::CSS::create_css_keyframes_rule(const string &name)
{
    return new CSSKeyframesRule(name);
}

void HIRMutate::CSS::CSSStyleRule::serialize(SerializeStream *stream, Context *context)
{
    selector->serialize(stream, context);
    declaration->serialize(stream, context);
}

void HIRMutate::CSS::CSSStyleRule::unserialize(UnSerializeStream *stream, Document *global_document)
{
    stream->skip_string();
    selector->unserialize(stream, global_document);
    declaration->unserialize(stream, global_document);
}

void HIRMutate::CSS::CSSKeyframeRule::serialize(SerializeStream *stream, Context *context)
{
    declaration->serialize(stream, context);
    stream->write_string(name);
}

void HIRMutate::CSS::CSSKeyframeRule::unserialize(UnSerializeStream *stream, Document *global_document)
{
    declaration = new CSSStyleDeclaration();
    declaration->unserialize(stream, global_document);
    name = stream->read_string();
}

void HIRMutate::CSS::CSSKeyframesRule::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(name);
    stream->write_int(keyframe_rules.size());
    std::for_each(keyframe_rules.begin(), keyframe_rules.end(),
                  [&stream, &context](map<string, CSSKeyframeRule *>::reference i)
                  {
                      stream->write_string(i.first);
                      i.second->serialize(stream, context);
                  });
}

void HIRMutate::CSS::CSSKeyframesRule::unserialize(UnSerializeStream *stream, Document *global_document)
{
    name = stream->read_string();
    int k_l = stream->read_int();
    for (int i = 0; i < k_l; i++)
    {
        string key = stream->read_string();
        CSSKeyframeRule *kfr = new CSSKeyframeRule();
        kfr->unserialize(stream, global_document);
        keyframe_rules[key] = kfr;
    }
}