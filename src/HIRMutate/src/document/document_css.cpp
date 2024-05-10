#include "document_css.h"
#include "config.h"

HIRMutate::Document_CSS::Document_CSS()
{
    this->css_variables = nullptr;
#ifdef DEBUG_MEM
    std::cout << "Document_CSS()" << std::endl;
#endif
}

HIRMutate::Document_CSS::~Document_CSS()
{
#ifdef DEBUG_MEM
    std::cout << "~Document_CSS()" << std::endl;
#endif
    if (css_variables)
    {
        delete css_variables;
    }
    std::for_each(css_style_rules.begin(), css_style_rules.end(),
                  [&](CSS::CSSStyleRule *rule)
                  {
                      delete rule;
                  });
    std::for_each(css_keyframes_rules.begin(), css_keyframes_rules.end(),
                  [&](CSS::CSSKeyframesRule *rule)
                  {
                      delete rule;
                  });
}

void HIRMutate::Document_CSS::init_keyframes(DOMContext *context)
{
    //add @keyframes
    vector<string> keyframes = context->get_tokens("keyframes");
    std::for_each(keyframes.begin(), keyframes.end(),
                  [&context, this](string &kf)
                  {
                      CSS::CSSKeyframesRule *kf_rule = CSS::create_css_keyframes_rule(kf);
                      kf_rule->generate(context);
                      this->css_keyframes_rules.push_back(kf_rule);
                  });
}

void HIRMutate::Document_CSS::init_css_variables(DOMContext *context)
{
    if (css_variables)
    {
        delete css_variables;
    }
    css_variables = new CSS::CSSVariables();
    css_variables->generate(context);
}

/*
        * For dumb fuzz
        */
void HIRMutate::Document_CSS::generate_css_rules(DOMContext *context)
{
    for (int i = 0; i < CSSConfig::max_css_count; i++)
    {
        append_css_style_rule(context);
    }

    std::for_each(css_style_rules.begin(), css_style_rules.end(),
                  [&context](CSS::CSSStyleRule *rule)
                  {
                      int l = Random::range(0, CSSConfig::max_css_selector_count - 1);
                      for (int i = 0; i < l; i++)
                      {
                          rule->append_selector(context);
                      }
                      for (int i = 0; i < CSSConfig::max_css_decl_count - 1; i++)
                      {
                          rule->append_decl(context);
                      }
                  });

    std::for_each(css_keyframes_rules.begin(), css_keyframes_rules.end(),
                  [&context](CSS::CSSKeyframesRule *rule)
                  {
                      int l = Random::range(1, CSSConfig::max_css_keyframe_count);
                      for (int i = 0; i < l; i++)
                      {
                          rule->append_keyframe_rule(context);
                      }
                  });
}

/*
        * For cov fuzz
        */
bool HIRMutate::Document_CSS::append_css_style_rule(DOMContext *context)
{
    if (css_style_rules.size() >= CSSConfig::max_css_count)
        return false;
    CSS::CSSStyleRule *css_rule = CSS::create_css_style_rule();
    css_rule->generate(context);
    css_style_rules.push_back(css_rule);
    return true;
}

bool HIRMutate::Document_CSS::replace_css_style_rule(DOMContext *context)
{
    int count = css_style_rules.size();
    if (count == 0)
        return false;
    css_style_rules.erase(css_style_rules.begin() + Random::selector(count));
    return append_css_style_rule(context);
}

bool HIRMutate::Document_CSS::mutate_css_style_rule(DOMContext *context)
{
    int count = css_style_rules.size();
    if (count == 0)
        return false;
    int trial = 0;
    while (trial < count)
    {
        CSS::CSSStyleRule *rule = CHOICE_OBJ(css_style_rules);
        if (rule->mutate(context))
            return true;
        trial++;
    }
    return false;
}

bool HIRMutate::Document_CSS::mutate_css_keyframes_rule(DOMContext *context)
{
    int count = css_keyframes_rules.size();
    if (count == 0)
        return false;

    int trial = 0;
    while (trial < count)
    {
        CSS::CSSKeyframesRule *rule = CHOICE_OBJ(css_keyframes_rules);
        if (rule->mutate(context))
            return true;
        trial++;
    }
    return false;
}

bool HIRMutate::Document_CSS::mutate_css_variable(DOMContext *context)
{
    return css_variables->mutate(context);
}

bool HIRMutate::Document_CSS::allow_merge()
{
    return css_style_rules.size() <= CSSConfig::max_css_count;
}

void HIRMutate::Document_CSS::merge(Document_CSS *other, map<Object *, Object *> &merge_map)
{
    std::for_each(other->css_style_rules.begin(), other->css_style_rules.end(),
                  [&merge_map](CSS::CSSStyleRule *rule)
                  {
                      rule->merge_fix(merge_map);
                  });
    std::for_each(other->css_keyframes_rules.begin(), other->css_keyframes_rules.end(),
                  [&merge_map](CSS::CSSKeyframesRule *rule)
                  {
                      rule->merge_fix(merge_map);
                  });

    css_style_rules.insert(css_style_rules.end(), other->css_style_rules.begin(), other->css_style_rules.end());

    int len = css_keyframes_rules.size();
    for (int i = 0; i < len; i++)
    {
        css_keyframes_rules[i]->merge(other->css_keyframes_rules[i]);
    }
}

HIRMutate::Document_CSS::operator string()
{
    string s = "<style>\n";
    std::for_each(css_style_rules.begin(), css_style_rules.end(),
                  [&s](CSS::CSSStyleRule *rule)
                  {
                      s.append(rule->operator string());
                      s.append("\n");
                  });
    s.append("</style>\n\n");
    s.append("<style>\n");
    std::for_each(css_keyframes_rules.begin(), css_keyframes_rules.end(),
                  [&s](CSS::CSSKeyframesRule *rule)
                  {
                      s.append(rule->operator string());
                      s.append("\n");
                  });
    s.append("</style>\n\n");
    s.append("<style>\n");
    s.append(css_variables->operator string());
    s.append("\n");
    s.append("</style>\n");
    return s;
}

void HIRMutate::Document_CSS::serialize(SerializeStream *stream, Context *context)
{
    css_variables->serialize(stream, context);
    stream->write_int(css_style_rules.size());
    std::for_each(css_style_rules.begin(), css_style_rules.end(),
                  [&stream, &context](CSS::CSSStyleRule *val)
                  {
                      val->serialize(stream, context);
                  });
    stream->write_int(css_keyframes_rules.size());
    std::for_each(css_keyframes_rules.begin(), css_keyframes_rules.end(),
                  [&stream, &context](CSS::CSSKeyframesRule *val)
                  {
                      val->serialize(stream, context);
                  });
}

void HIRMutate::Document_CSS::unserialize(UnSerializeStream *stream, Document *global_document)
{
    css_variables = new CSS::CSSVariables();
    css_variables->unserialize(stream, global_document);
    int csr_size = stream->read_int();
    for (int i = 0; i < csr_size; i++)
    {
        CSS::CSSStyleRule *csr = new CSS::CSSStyleRule();
        csr->unserialize(stream, global_document);
        css_style_rules.push_back(csr);
    }
    int ckr_size = stream->read_int();
    for (int i = 0; i < ckr_size; i++)
    {
        CSS::CSSKeyframesRule *ckr = new CSS::CSSKeyframesRule();
        ckr->unserialize(stream, global_document);
        css_keyframes_rules.push_back(ckr);
    }
}
