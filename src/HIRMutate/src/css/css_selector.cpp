#include "css_selector.h"
#include "DomValue.h"
#include "serialize_variables.h"
#include <assert.h>

string HIRMutate::CSS::nth()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"even", "odd"};
        return CHOICE(strs);
    }
    else
        return Random::integer();
}

bool HIRMutate::CSS::CSSSelector::mutate(DOMContext *context)
{
    generate(context);
    return true;
}

void HIRMutate::CSS::CSSSelector::merge_fix(map<Object *, Object *> &merge_map) {}

void HIRMutate::CSS::CSSSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSSelector");
    stream->write_string(value);
}

void HIRMutate::CSS::CSSSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    if (stream->read_string() != "CSSSelector")
    {
        puts("CSSSelector::unserialize Error!");
        abort();
    }
    value = stream->read_string();
}

HIRMutate::CSS::CSSAtRuleSelector::CSSAtRuleSelector(const string &value)
{
    this->value = value;
}

void HIRMutate::CSS::CSSAtRuleSelector::generate(DOMContext *context) {}

bool HIRMutate::CSS::CSSAtRuleSelector::mutate(DOMContext *context)
{
    return false;
}

HIRMutate::CSS::CSSAtRuleSelector::operator string()
{
    string ans = "@";
    ans.append(value);
    return ans;
}

void HIRMutate::CSS::CSSAtRuleSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSAtRuleSelector");
    CSSSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSAtRuleSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
}

HIRMutate::CSS::CSSElementSelector::CSSElementSelector(vector<string> *scope)
{
    if (scope != nullptr)
    {
        set<string> st(scope->begin(), scope->end());
        this->scope = st;
        this->value = "";
    }
}

void HIRMutate::CSS::CSSElementSelector::generate(DOMContext *context)
{
    vector<string> scope_t;
    if (scope.size() != 0)
    {
        std::set_intersection(std::begin(context->in_tree_set), std::end(context->in_tree_set), std::begin(scope), std::end(scope), std::inserter(scope_t, std::begin(scope_t)));
    }
    if (scope.size() == 0)
    {
        scope_t.assign(context->in_tree_set.begin(), context->in_tree_set.end());
    }
    if (scope_t.size() == 0)
    {
        value = "";
    }
    else
    {
        string &elem = CHOICE_OBJ(scope_t);
        if (elem != "")
            value = DOC::tag_from_element(elem);
        else
            value = "";
    }
}

HIRMutate::CSS::CSSElementSelector::operator string()
{
    if (value == "")
    {
        return "*";
    }
    else
    {
        return value;
    }
}

void HIRMutate::CSS::CSSElementSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSElementSelector");
    CSSSelector::serialize(stream, context);
    stream->write_int(scope.size());
    std::for_each(scope.begin(), scope.end(),
                  [&stream](const string &val)
                  {
                      stream->write_string(val);
                  });
}

void HIRMutate::CSS::CSSElementSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
    int scope_size = stream->read_int();
    for (int i = 0; i < scope_size; i++)
    {
        scope.insert(scope.end(), stream->read_string());
    }
}

void HIRMutate::CSS::CSSClassSelector::generate(DOMContext *context)
{
    cla = context->get_token("class");
}

HIRMutate::CSS::CSSClassSelector::operator string()
{
    if (cla == "")
        return "*";
    string s = ".";
    s.append(cla);
    return s;
}

void HIRMutate::CSS::CSSClassSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSClassSelector");
    CSSSelector::serialize(stream, context);
    stream->write_string(cla);
}

void HIRMutate::CSS::CSSClassSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
    cla = stream->read_string();
}

HIRMutate::CSS::CSSIDSelector::CSSIDSelector(vector<string> *scope)
{
    if (scope != nullptr)
    {
        this->scope = *scope;
    }
    elem = nullptr;
}
void HIRMutate::CSS::CSSIDSelector::generate(DOMContext *context)
{
    vector<string> scope_t = scope;
    if (scope_t.size() == 0)
        scope_t = DOC::elements;
    elem = context->get_object(scope_t);
}

void HIRMutate::CSS::CSSIDSelector::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem != nullptr)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

HIRMutate::CSS::CSSIDSelector::operator string()
{
    if (elem == nullptr)
        return "*";
    string s = "#";
    s.append(elem->id);
    return s;
}

void HIRMutate::CSS::CSSIDSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSIDSelector");
    CSSSelector::serialize(stream, context);
    stream->write_int(scope.size());
    std::for_each(scope.begin(), scope.end(),
                  [&stream](string &val)
                  {
                      stream->write_string(val);
                  });
    if (elem != nullptr)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}

void HIRMutate::CSS::CSSIDSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
    int scope_size = stream->read_int();
    for (int i = 0; i < scope_size; i++)
    {
        scope.push_back(stream->read_string());
    }
    if (stream->peek() == "nullptr")
    {
        elem = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&elem, global_document);
    }
}

void HIRMutate::CSS::CSSUniversalSelector::generate(DOMContext *context)
{
}

bool HIRMutate::CSS::CSSUniversalSelector::mutate(DOMContext *context)
{
    return false;
}

HIRMutate::CSS::CSSUniversalSelector::operator string()
{
    return "*";
}

void HIRMutate::CSS::CSSUniversalSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSUniversalSelector");
    CSSSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSUniversalSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
}

HIRMutate::CSS::CSSSelector *HIRMutate::CSS::create_css_basic_selector(vector<string> *scope)
{
    int c = Random::selector(4);
    if (c == 0)
        return new CSSUniversalSelector();
    else if (c == 1)
    {
        return new CSSElementSelector(scope);
    }
    else if (c == 2)
        return new CSSClassSelector();
    else
        return new CSSIDSelector(scope);
}

HIRMutate::CSS::CSSPseudoClassSelector::CSSPseudoClassSelector(const string &name)
{
    this->name = name;
    this->base = nullptr;
#ifdef DEBUG_MEM
    std::cout << "CSSPseudoClassSelector(" << name << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSPseudoClassSelector::~CSSPseudoClassSelector()
{
    if (base)
        delete base;
#ifdef DEBUG_MEM
    std::cout << "~CSSPseudoClassSelector(" << name << ")" << std::endl;
#endif
}

void HIRMutate::CSS::CSSPseudoClassSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector();
    base->generate(context);
}

HIRMutate::CSS::CSSPseudoClassSelector::operator string()
{
    string ans = base->operator string();
    ans.append(":");
    ans.append(name);
    return ans;
}

void HIRMutate::CSS::CSSPseudoClassSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPseudoClassSelector");
    CSSSelector::serialize(stream, context);
    stream->write_string(name);
    base->serialize(stream, context);
}

void HIRMutate::CSS::CSSPseudoClassSelector::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "CSSPseudoClassSelector")
        {
            puts("CSSPseudoClassSelector::unserialize Error!");
            abort();
        }
    }
    CSSSelector::unserialize(stream, global_document);
    name = stream->read_string();
    base = css_selector_classes[stream->read_string()](stream, global_document);
}

HIRMutate::CSS::CSSActiveSelector::CSSActiveSelector() : CSSPseudoClassSelector("active")
{
}

HIRMutate::CSS::CSSAnyLinkSelector::CSSAnyLinkSelector() : CSSPseudoClassSelector("any-link")
{
}

void HIRMutate::CSS::CSSAnyLinkSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_link_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSAnyLinkSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSAnyLinkSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSAnyLinkSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSCheckedSelector::CSSCheckedSelector() : CSSPseudoClassSelector("checked") {}

void HIRMutate::CSS::CSSCheckedSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLOptionElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSCheckedSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSCheckedSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSCheckedSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSDefaultSelector::CSSDefaultSelector() : CSSPseudoClassSelector("default") {}

void HIRMutate::CSS::CSSDefaultSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLButtonElement", "HTMLOptionElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSDefaultSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSDefaultSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSDefaultSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSDefinedSelector::CSSDefinedSelector() : CSSPseudoClassSelector("defined") {}

HIRMutate::CSS::CSSDirSelector::CSSDirSelector() : CSSPseudoClassSelector("dir")
{
    arg = "";
}

void HIRMutate::CSS::CSSDirSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    static const char *strs[] = {"ltr", "rtl"};
    arg = CHOICE(strs);
}

HIRMutate::CSS::CSSDirSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(arg);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSDirSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSDirSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(arg);
}

void HIRMutate::CSS::CSSDirSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    arg = stream->read_string();
}

HIRMutate::CSS::CSSDisabledSelector::CSSDisabledSelector() : CSSPseudoClassSelector("disabled") {}

void HIRMutate::CSS::CSSDisabledSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLButtonElement", "HTMLInputElement", "HTMLSelectElement", "HTMLTextAreaElement",
                          "HTMLOptGroupElement", "HTMLOptionElement", "HTMLFieldSetElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSDisabledSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSDisabledSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSDisabledSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSEmptySelector::CSSEmptySelector() : CSSPseudoClassSelector("empty") {}

HIRMutate::CSS::CSSEnabledSelector::CSSEnabledSelector() : CSSPseudoClassSelector("enabled") {}

void HIRMutate::CSS::CSSEnabledSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLButtonElement", "HTMLInputElement", "HTMLSelectElement", "HTMLTextAreaElement",
                          "HTMLOptGroupElement", "HTMLOptionElement", "HTMLFieldSetElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSEnabledSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSEnabledSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSEnabledSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSFirstSelector::CSSFirstSelector() : CSSPseudoClassSelector("first") {}

void HIRMutate::CSS::CSSFirstSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSAtRuleSelector("page");
    base->generate(context);
}

void HIRMutate::CSS::CSSFirstSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSFirstSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSFirstSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSFirstChildSelector::CSSFirstChildSelector() : CSSPseudoClassSelector("first-child") {}

HIRMutate::CSS::CSSFirstOfTypeSelector::CSSFirstOfTypeSelector() : CSSPseudoClassSelector("first-of-type") {}

HIRMutate::CSS::CSSFullscreenSelector::CSSFullscreenSelector() : CSSPseudoClassSelector("fullscreen") {}

HIRMutate::CSS::CSSFutureSelector::CSSFutureSelector() : CSSPseudoClassSelector("future") {}

void HIRMutate::CSS::CSSFutureSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}

void HIRMutate::CSS::CSSFutureSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSFutureSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSFutureSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSFocusSelector::CSSFocusSelector() : CSSPseudoClassSelector("focus") {}
HIRMutate::CSS::CSSFocusWithinSelector::CSSFocusWithinSelector() : CSSPseudoClassSelector("focus-within") {}

HIRMutate::CSS::CSSHostSelector::CSSHostSelector() : CSSPseudoClassSelector("host") {}

void HIRMutate::CSS::CSSHostSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}

void HIRMutate::CSS::CSSHostSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSHostSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSHostSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSHoverSelector::CSSHoverSelector() : CSSPseudoClassSelector("hover") {}

HIRMutate::CSS::CSSIndeterminateSelector::CSSIndeterminateSelector() : CSSPseudoClassSelector("indeterminate") {}

void HIRMutate::CSS::CSSIndeterminateSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLProgressElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSIndeterminateSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSIndeterminateSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSIndeterminateSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSInRangeSelector::CSSInRangeSelector() : CSSPseudoClassSelector("in-range") {}

void HIRMutate::CSS::CSSInRangeSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_submittable_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSInRangeSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSInRangeSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSInRangeSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSInvalidSelector::CSSInvalidSelector() : CSSPseudoClassSelector("invalid") {}

void HIRMutate::CSS::CSSInvalidSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_submittable_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSInvalidSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSInvalidSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSInvalidSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSLangSelector::CSSLangSelector() : CSSPseudoClassSelector("lang")
{
    lang = "";
}

void HIRMutate::CSS::CSSLangSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    lang = DOMValue::lang();
}

HIRMutate::CSS::CSSLangSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(lang);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSLangSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLangSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(lang);
}
void HIRMutate::CSS::CSSLangSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    lang = stream->read_string();
}

HIRMutate::CSS::CSSLastChildSelector::CSSLastChildSelector() : CSSPseudoClassSelector("last-child") {}
HIRMutate::CSS::CSSLastOfTypeSelector::CSSLastOfTypeSelector() : CSSPseudoClassSelector("last-of-type") {}
HIRMutate::CSS::CSSLeftSelector::CSSLeftSelector() : CSSPseudoClassSelector("left") {}

void HIRMutate::CSS::CSSLeftSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSAtRuleSelector("page");
    base->generate(context);
}

void HIRMutate::CSS::CSSLeftSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLeftSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSLeftSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSLinkSelector::CSSLinkSelector() : CSSPseudoClassSelector("link") {}

void HIRMutate::CSS::CSSLinkSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_link_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSLinkSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLinkSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSLinkSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSNotSelector::CSSNotSelector() : CSSPseudoClassSelector("not")
{
    selector = nullptr;
#ifdef DEBUG_MEM
    std::cout << "CSSNotSelector()" << std::endl;
#endif
}

HIRMutate::CSS::CSSNotSelector::~CSSNotSelector()
{
    if (selector)
        delete selector;
#ifdef DEBUG_MEM
    std::cout << "~CSSNotSelector()" << std::endl;
#endif
}

void HIRMutate::CSS::CSSNotSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    if (selector)
    {
        delete selector;
    }
    selector = create_css_basic_selector();
    selector->generate(context);
}

HIRMutate::CSS::CSSNotSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(selector->operator string());
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSNotSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSNotSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    selector->serialize(stream, context);
}

void HIRMutate::CSS::CSSNotSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    selector = css_selector_classes[stream->read_string()](stream, global_document);
}

HIRMutate::CSS::CSSNthChildSelector::CSSNthChildSelector() : CSSPseudoClassSelector("nth-child")
{
    s_nth = "";
}

void HIRMutate::CSS::CSSNthChildSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    s_nth = nth();
}

HIRMutate::CSS::CSSNthChildSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(s_nth);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSNthChildSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSNthChildSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(s_nth);
}

void HIRMutate::CSS::CSSNthChildSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    s_nth = stream->read_string();
}

HIRMutate::CSS::CSSNthLastChildSelector::CSSNthLastChildSelector() : CSSPseudoClassSelector("nth-last-child")
{
    s_nth = "";
}

void HIRMutate::CSS::CSSNthLastChildSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    s_nth = nth();
}

HIRMutate::CSS::CSSNthLastChildSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(s_nth);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSNthLastChildSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSNthLastChildSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(s_nth);
}

void HIRMutate::CSS::CSSNthLastChildSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    s_nth = stream->read_string();
}

HIRMutate::CSS::CSSNthLastOfTypeSelector::CSSNthLastOfTypeSelector() : CSSPseudoClassSelector("nth-last-of-type")
{
    s_nth = "";
}

void HIRMutate::CSS::CSSNthLastOfTypeSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    s_nth = nth();
}

HIRMutate::CSS::CSSNthLastOfTypeSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(s_nth);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSNthLastOfTypeSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSNthLastOfTypeSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(s_nth);
}

void HIRMutate::CSS::CSSNthLastOfTypeSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    s_nth = stream->read_string();
}

HIRMutate::CSS::CSSNthOfTypeSelector::CSSNthOfTypeSelector() : CSSPseudoClassSelector("nth-of-type")
{
    s_nth = "";
}

void HIRMutate::CSS::CSSNthOfTypeSelector::generate(DOMContext *context)
{
    CSSPseudoClassSelector::generate(context);
    s_nth = nth();
}

HIRMutate::CSS::CSSNthOfTypeSelector::operator string()
{
    string s = CSSPseudoClassSelector::operator string();
    s.append("(");
    s.append(s_nth);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSNthOfTypeSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSNthOfTypeSelector");
    CSSPseudoClassSelector::serialize(stream, context);
    stream->write_string(s_nth);
}
void HIRMutate::CSS::CSSNthOfTypeSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
    s_nth = stream->read_string();
}
HIRMutate::CSS::CSSOnlyChildSelector::CSSOnlyChildSelector() : CSSPseudoClassSelector("only-child") {}
HIRMutate::CSS::CSSOnlyOfTypeSelector::CSSOnlyOfTypeSelector() : CSSPseudoClassSelector("only-of-type") {}

HIRMutate::CSS::CSSOptionalSelector::CSSOptionalSelector() : CSSPseudoClassSelector("optional") {}

void HIRMutate::CSS::CSSOptionalSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLSelectElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSOptionalSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSOptionalSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSOptionalSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSOutOfRangeSelector::CSSOutOfRangeSelector() : CSSPseudoClassSelector("out-of-range") {}

void HIRMutate::CSS::CSSOutOfRangeSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_submittable_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSOutOfRangeSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSOutOfRangeSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSOutOfRangeSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSPastSelector::CSSPastSelector() : CSSPseudoClassSelector("past") {}

void HIRMutate::CSS::CSSPastSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}

void HIRMutate::CSS::CSSPastSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPastSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSPastSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}
HIRMutate::CSS::CSSPlaceholderShownSelector::CSSPlaceholderShownSelector() : CSSPseudoClassSelector("placeholder-shown") {}

void HIRMutate::CSS::CSSPlaceholderShownSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}
void HIRMutate::CSS::CSSPlaceholderShownSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPlaceholderShownSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSPlaceholderShownSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}
HIRMutate::CSS::CSSReadOnlySelector::CSSReadOnlySelector() : CSSPseudoClassSelector("read-only") {}

void HIRMutate::CSS::CSSReadOnlySelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSReadOnlySelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSReadOnlySelector");
    CSSPseudoClassSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSReadOnlySelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSReadWriteSelector::CSSReadWriteSelector() : CSSPseudoClassSelector("read-write") {}

void HIRMutate::CSS::CSSReadWriteSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSReadWriteSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSReadWriteSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSReadWriteSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSRequiredSelector::CSSRequiredSelector() : CSSPseudoClassSelector("required") {}

void HIRMutate::CSS::CSSRequiredSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLSelectElement", "HTMLInputElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSRequiredSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSRequiredSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSRequiredSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSRightSelector::CSSRightSelector() : CSSPseudoClassSelector("right") {}

void HIRMutate::CSS::CSSRightSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSAtRuleSelector("page");
    base->generate(context);
}

void HIRMutate::CSS::CSSRightSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSRightSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSRightSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSRootSelector::CSSRootSelector() : CSSPseudoClassSelector("root") {}

void HIRMutate::CSS::CSSRootSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}
void HIRMutate::CSS::CSSRootSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSRootSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSRootSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSScopeSelector::CSSScopeSelector() : CSSPseudoClassSelector("scope") {}

void HIRMutate::CSS::CSSScopeSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}

void HIRMutate::CSS::CSSScopeSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSScopeSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSScopeSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSTargetSelector::CSSTargetSelector() : CSSPseudoClassSelector("target") {}

HIRMutate::CSS::CSSValidSelector::CSSValidSelector() : CSSPseudoClassSelector("valid") {}

void HIRMutate::CSS::CSSValidSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLButtonElement", "HTMLInputElement", "HTMLObjectElement",
                          "HTMLSelectElement", "HTMLTextAreaElement",
                          "HTMLFormElement", "HTMLFieldSetElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSValidSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSValidSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSValidSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSVisitedSelector::CSSVisitedSelector() : CSSPseudoClassSelector("visited") {}

void HIRMutate::CSS::CSSVisitedSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_link_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSVisitedSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSVisitedSelector");
    CSSPseudoClassSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSVisitedSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoClassSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSPseudoElementSelector::CSSPseudoElementSelector(const string &name)
{
    this->name = name;
    this->base = nullptr;
#ifdef DEBUG_MEM
    std::cout << "CSSPseudoElementSelector(" << name << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSPseudoElementSelector::~CSSPseudoElementSelector()
{
    if (base)
        delete base;
#ifdef DEBUG_MEM
    std::cout << "~CSSPseudoElementSelector(" << name << ")" << std::endl;
#endif
}

void HIRMutate::CSS::CSSPseudoElementSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector();
    base->generate(context);
}

HIRMutate::CSS::CSSPseudoElementSelector::operator string()
{
    string s = base->operator string();
    s.append("::");
    s.append(name);
    return s;
}

void HIRMutate::CSS::CSSPseudoElementSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPseudoElementSelector");
    CSSSelector::serialize(stream, context);
    stream->write_string(name);
    base->serialize(stream, context);
}

void HIRMutate::CSS::CSSPseudoElementSelector::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "CSSPseudoElementSelector")
        {
            puts("CSSPseudoElementSelector::unserialize Error!");
            abort();
        }
    }
    CSSSelector::unserialize(stream, global_document);
    name = stream->read_string();
    base = css_selector_classes[stream->read_string()](stream, global_document);
}

HIRMutate::CSS::CSSAfterSelector::CSSAfterSelector() : CSSPseudoElementSelector("after") {}
HIRMutate::CSS::CSSBeforeSelector::CSSBeforeSelector() : CSSPseudoElementSelector("before") {}
HIRMutate::CSS::CSSCueSelector::CSSCueSelector() : CSSPseudoElementSelector("cue") {}

void HIRMutate::CSS::CSSCueSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = new CSSUniversalSelector();
    base->generate(context);
}

void HIRMutate::CSS::CSSCueSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSCueSelector");
    CSSPseudoElementSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSCueSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSFirstLetterSelector::CSSFirstLetterSelector() : CSSPseudoElementSelector("first-letter") {}

void HIRMutate::CSS::CSSFirstLetterSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_block_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSFirstLetterSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSFirstLetterSelector");
    CSSPseudoElementSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSFirstLetterSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
}
HIRMutate::CSS::CSSFirstLineSelector::CSSFirstLineSelector() : CSSPseudoElementSelector("first-line") {}

void HIRMutate::CSS::CSSFirstLineSelector::generate(DOMContext *context)
{
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&DOC::html_block_elements);
    base->generate(context);
}

void HIRMutate::CSS::CSSFirstLineSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSFirstLineSelector");
    CSSPseudoElementSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSFirstLineSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
}
HIRMutate::CSS::CSSMarkerSelector::CSSMarkerSelector() : CSSPseudoElementSelector("marker") {}

void HIRMutate::CSS::CSSMarkerSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLLIElement", "HTMLSummaryElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSMarkerSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSMarkerSelector");
    CSSPseudoElementSelector::serialize(stream, context);
}
void HIRMutate::CSS::CSSMarkerSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
}
HIRMutate::CSS::CSSPartSelector::CSSPartSelector() : CSSPseudoElementSelector("part")
{
    part = "";
}

void HIRMutate::CSS::CSSPartSelector::generate(DOMContext *context)
{
    CSSPseudoElementSelector::generate(context);
    part = context->get_token("part");
}

HIRMutate::CSS::CSSPartSelector::operator string()
{
    string s = CSSPseudoElementSelector::operator string();
    s.append("(");
    s.append(part);
    s.append(")");
    return s;
}

void HIRMutate::CSS::CSSPartSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPartSelector");
    CSSPseudoElementSelector::serialize(stream, context);
    stream->write_string(part);
}
void HIRMutate::CSS::CSSPartSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
    part = stream->read_string();
}
HIRMutate::CSS::CSSPlaceholderSelector::CSSPlaceholderSelector() : CSSPseudoElementSelector("placeholder") {}

void HIRMutate::CSS::CSSPlaceholderSelector::generate(DOMContext *context)
{
    vector<string> vec = {"HTMLInputElement", "HTMLTextAreaElement"};
    if (base)
    {
        delete base;
    }
    base = create_css_basic_selector(&vec);
    base->generate(context);
}

void HIRMutate::CSS::CSSPlaceholderSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSPlaceholderSelector");
    CSSPseudoElementSelector::serialize(stream, context);
}

void HIRMutate::CSS::CSSPlaceholderSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSPseudoElementSelector::unserialize(stream, global_document, true);
}

HIRMutate::CSS::CSSSelectionSelector::CSSSelectionSelector() : CSSPseudoElementSelector("selection") {}

HIRMutate::CSS::CSSCombinator::CSSCombinator(const string &op)
{
    this->op = op;
    this->a = nullptr;
    this->b = nullptr;
#ifdef DEBUG_MEM
    std::cout << "CSSCombinator(" << op << ")" << std::endl;
#endif
}

HIRMutate::CSS::CSSCombinator::~CSSCombinator()
{
    if (a)
        delete a;
    if (b)
        delete b;
#ifdef DEBUG_MEM
    std::cout << "~CSSCombinator(" << op << ")" << std::endl;
#endif
}

void HIRMutate::CSS::CSSCombinator::generate(DOMContext *context)
{
    if (a)
        delete a;
    if (b)
        delete b;
    a = create_css_basic_selector();
    a->generate(context);
    b = create_css_basic_selector();
    b->generate(context);
}

bool HIRMutate::CSS::CSSCombinator::mutate(DOMContext *context)
{
    int c = Random::selector(4);
    if (c == 0)
        return a->mutate(context);
    else if (c == 1)
        return b->mutate(context);
    else if (c == 2)
    {
        bool ok = a->mutate(context);
        if (!ok)
        {
            ok = b->mutate(context);
        }
        return ok;
    }
    else
    {
        generate(context);
        return true;
    }
}

void HIRMutate::CSS::CSSCombinator::merge_fix(map<Object *, Object *> &merge_map)
{
    a->merge_fix(merge_map);
    b->merge_fix(merge_map);
}

HIRMutate::CSS::CSSCombinator::operator string()
{
    string s = a->operator string();
    s.append(op);
    s.append(b->operator string());
    return s;
}

void HIRMutate::CSS::CSSCombinator::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSCombinator");
    CSSSelector::serialize(stream, context);
    a->serialize(stream, context);
    b->serialize(stream, context);
    stream->write_string(op);
}

void HIRMutate::CSS::CSSCombinator::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "CSSCombinator")
        {
            puts("CSSCombinator::unserialize Error!");
            abort();
        }
    }
    CSSSelector::unserialize(stream, global_document);
    a = css_selector_classes[stream->read_string()](stream, global_document);
    b = css_selector_classes[stream->read_string()](stream, global_document);
    op = stream->read_string();
}

HIRMutate::CSS::CSSDescendantCombinator::CSSDescendantCombinator() : CSSCombinator(" ") {}
HIRMutate::CSS::CSSChildCombinator::CSSChildCombinator() : CSSCombinator(">") {}
HIRMutate::CSS::CSSGeneralSiblingCombinator::CSSGeneralSiblingCombinator() : CSSCombinator("~") {}
HIRMutate::CSS::CSSAdjacentSiblingCombinator::CSSAdjacentSiblingCombinator() : CSSCombinator("+") {}

namespace HIRMutate::CSS
{
    vector<CSSSelector *(*)(void)> css_basic_selectors;
    vector<CSSSelector *(*)(void)> css_special_selectors;
}

void HIRMutate::CSS::initSelector()
{
    // basic selectors
    CSS_BASIC_SELECTORS(CSSElementSelector)
    CSS_BASIC_SELECTORS(CSSClassSelector);
    CSS_BASIC_SELECTORS(CSSIDSelector)

    CSS_SPECIAL_SELECTORS(CSSUniversalSelector)

    // pseudo class selectors
    CSS_SPECIAL_SELECTORS(CSSActiveSelector)
    CSS_SPECIAL_SELECTORS(CSSAnyLinkSelector)
    CSS_SPECIAL_SELECTORS(CSSCheckedSelector)
    CSS_SPECIAL_SELECTORS(CSSDefaultSelector)
    CSS_SPECIAL_SELECTORS(CSSDefinedSelector)
    CSS_SPECIAL_SELECTORS(CSSDirSelector)
    CSS_SPECIAL_SELECTORS(CSSDisabledSelector)
    CSS_SPECIAL_SELECTORS(CSSEmptySelector)
    CSS_SPECIAL_SELECTORS(CSSEnabledSelector)
    // CSS_SPECIAL_SELECTORS(CSSFirstSelector,
    CSS_SPECIAL_SELECTORS(CSSFirstChildSelector)
    CSS_SPECIAL_SELECTORS(CSSFirstOfTypeSelector)
    CSS_SPECIAL_SELECTORS(CSSFullscreenSelector)
    // CSS_SPECIAL_SELECTORS(CSSFutureSelector)
    CSS_SPECIAL_SELECTORS(CSSFocusSelector)
    CSS_SPECIAL_SELECTORS(CSSFocusWithinSelector)
    CSS_SPECIAL_SELECTORS(CSSHostSelector)
    CSS_SPECIAL_SELECTORS(CSSHoverSelector)
    CSS_SPECIAL_SELECTORS(CSSIndeterminateSelector)
    CSS_SPECIAL_SELECTORS(CSSInRangeSelector)
    CSS_SPECIAL_SELECTORS(CSSInvalidSelector)
    // CSS_SPECIAL_SELECTORS(CSSLangSelector)
    CSS_SPECIAL_SELECTORS(CSSLastChildSelector)
    CSS_SPECIAL_SELECTORS(CSSLastOfTypeSelector)
    // CSS_SPECIAL_SELECTORS(CSSLeftSelector)
    CSS_SPECIAL_SELECTORS(CSSLinkSelector)
    CSS_SPECIAL_SELECTORS(CSSNotSelector)
    CSS_SPECIAL_SELECTORS(CSSNthChildSelector)
    CSS_SPECIAL_SELECTORS(CSSNthLastChildSelector)
    CSS_SPECIAL_SELECTORS(CSSNthLastOfTypeSelector)
    CSS_SPECIAL_SELECTORS(CSSNthOfTypeSelector)
    CSS_SPECIAL_SELECTORS(CSSOnlyChildSelector)
    CSS_SPECIAL_SELECTORS(CSSOnlyOfTypeSelector)
    CSS_SPECIAL_SELECTORS(CSSOptionalSelector)
    CSS_SPECIAL_SELECTORS(CSSOutOfRangeSelector)
    // CSS_SPECIAL_SELECTORS(CSSPastSelector)
    CSS_SPECIAL_SELECTORS(CSSPlaceholderShownSelector)
    CSS_SPECIAL_SELECTORS(CSSReadOnlySelector)
    CSS_SPECIAL_SELECTORS(CSSReadWriteSelector)
    CSS_SPECIAL_SELECTORS(CSSRequiredSelector)
    // CSS_SPECIAL_SELECTORS(CSSRightSelector)
    CSS_SPECIAL_SELECTORS(CSSRootSelector)
    CSS_SPECIAL_SELECTORS(CSSScopeSelector)
    CSS_SPECIAL_SELECTORS(CSSTargetSelector)
    CSS_SPECIAL_SELECTORS(CSSValidSelector)
    CSS_SPECIAL_SELECTORS(CSSVisitedSelector)

    // pseudo element selectors
    CSS_SPECIAL_SELECTORS(CSSAfterSelector)
    CSS_SPECIAL_SELECTORS(CSSBeforeSelector)
    CSS_SPECIAL_SELECTORS(CSSCueSelector)
    CSS_SPECIAL_SELECTORS(CSSFirstLetterSelector)
    CSS_SPECIAL_SELECTORS(CSSFirstLineSelector)
    CSS_SPECIAL_SELECTORS(CSSMarkerSelector)
    CSS_SPECIAL_SELECTORS(CSSPartSelector)
    CSS_SPECIAL_SELECTORS(CSSPlaceholderSelector)
    CSS_SPECIAL_SELECTORS(CSSSelectionSelector)

    // Combinators
    CSS_SPECIAL_SELECTORS(CSSDescendantCombinator)
    CSS_SPECIAL_SELECTORS(CSSChildCombinator)
    CSS_SPECIAL_SELECTORS(CSSGeneralSiblingCombinator)
    CSS_SPECIAL_SELECTORS(CSSAdjacentSiblingCombinator)
}

HIRMutate::CSS::CSSGroupSelector::CSSGroupSelector()
{
#ifdef DEBUG_MEM
    std::cout << "CSSGroupSelector()" << std::endl;
#endif
}
HIRMutate::CSS::CSSGroupSelector::~CSSGroupSelector()
{
#ifdef DEBUG_MEM
    std::cout << "~CSSGroupSelector()" << std::endl;
#endif
    std::for_each(selectors.begin(), selectors.end(),
                  [](CSSSelector *selector)
                  {
                      delete selector;
                  });
}
int HIRMutate::CSS::CSSGroupSelector::selector_count()
{
    return selectors.size();
}

bool HIRMutate::CSS::CSSGroupSelector::append(DOMContext *context)
{
    if (selectors.size() >= CSSConfig::max_css_selector_count)
        return false;
    CSSSelector *selector = create_css_simple_selector();
    selector->generate(context);
    selectors.push_back(selector);
    return true;
}

void HIRMutate::CSS::CSSGroupSelector::generate(DOMContext *context)
{
    append(context);
}

bool HIRMutate::CSS::CSSGroupSelector::mutate(DOMContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
    {
        // 1. mutate one
        CSSSelector *selector = CHOICE_OBJ(selectors);
        return selector->mutate(context);
    }
    else if (c == 1)
    {
        // 2. replace one
        if (selectors.size() == 0)
            return false;
        vector<CSSSelector *>::iterator it = selectors.begin() + Random::selector(selectors.size());
        CSSSelector *sel = *it;
        delete sel;
        selectors.erase(it);
        append(context);
        return true;
    }
    else
    {
        if (selectors.size() >= CSSConfig::max_css_selector_count)
            return false;
        append(context);
        return true;
    }
}

void HIRMutate::CSS::CSSGroupSelector::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(selectors.begin(), selectors.end(),
                  [&merge_map](CSSSelector *selector)
                  {
                      selector->merge_fix(merge_map);
                  });
}

HIRMutate::CSS::CSSGroupSelector::operator string()
{
    string ans = "";
    int len = selectors.size();
    for (int i = 0; i < len; i++)
    {
        ans.append(selectors[i]->operator string());
        if (i != len - 1)
        {
            ans.append(",");
        }
    }
    return ans;
}
void HIRMutate::CSS::CSSGroupSelector::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSGroupSelector");
    CSSSelector::serialize(stream, context);
    stream->write_int(selectors.size());
    std::for_each(selectors.begin(), selectors.end(),
                  [&stream, &context](CSSSelector *val)
                  {
                      val->serialize(stream, context);
                  });
}
void HIRMutate::CSS::CSSGroupSelector::unserialize(UnSerializeStream *stream, Document *global_document)
{
    CSSSelector::unserialize(stream, global_document);
    int n = stream->read_int();
    for (int i = 0; i < n; i++)
    {
        selectors.push_back(css_selector_classes[stream->read_string()](stream, global_document));
    }
}
HIRMutate::CSS::CSSSelector *HIRMutate::CSS::create_css_simple_selector()
{
    CSSSelector *(*selector)(void);
    if (Random::gbool())
        selector = CHOICE_OBJ(css_basic_selectors);
    else
        selector = CHOICE_OBJ(css_special_selectors);
    return selector();
}

HIRMutate::CSS::CSSGroupSelector *HIRMutate::CSS::create_css_selector()
{
    return new CSSGroupSelector();
}