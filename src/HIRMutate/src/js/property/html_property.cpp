#include "html_property.h"
#include "js_property.h"
#include "html_ret.h"
#include "html_arg.h"
#include "serialize_variables.h"

HIRMutate::JS::ArrayLoadIndex::ArrayLoadIndex(Ret *ret, Arg *this_obj, Arg *selector) : API(ret, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::ArrayLoadIndex::~ArrayLoadIndex()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::ArrayLoadIndex::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
    if (ret != nullptr)
        ret->generate(context);
}

bool HIRMutate::JS::ArrayLoadIndex::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ArrayLoadIndex::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::ArrayLoadIndex::operator string()
{
    string lhs = "";
    if (ret != nullptr)
    {
        lhs.append("var ");
        lhs.append(ret->operator string());
        lhs.append(" = ");
    }
    lhs.append(this_obj->operator string());
    lhs.append("[");
    lhs.append(selector->operator string());
    lhs.append(" % ");
    lhs.append(this_obj->operator string());
    lhs.append(".length]");
    return lhs;
}
void HIRMutate::JS::ArrayLoadIndex::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ArrayLoadIndex");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ArrayLoadIndex::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ArrayLoadIndexTemplate::ArrayLoadIndexTemplate(Ret *(*ret_class)(), Arg *(*this_class)()) : APITemplate(ret_class, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::ArrayLoadIndexTemplate::instantiate()
{
    Ret *ret = nullptr;
    if (ret_class != nullptr)
    {
        ret = ret_class();
    }
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new ArrayLoadIndex(ret, this_obj, selector);
}

bool HIRMutate::JS::ArrayLoadIndexTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::ArrayStoreIndex::ArrayStoreIndex(Arg *value, Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->value = value;
    this->selector = selector;
}
HIRMutate::JS::ArrayStoreIndex::~ArrayStoreIndex()
{
    if (value)
        delete value;
    if (selector)
        delete selector;
}
void HIRMutate::JS::ArrayStoreIndex::generate(JSContext *context)
{
    this_obj->generate(context);
    value->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::ArrayStoreIndex::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        value->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ArrayStoreIndex::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    value->merge_fix(merge_map);
}

HIRMutate::JS::ArrayStoreIndex::operator string()
{
    string s = this_obj->operator string();
    s.append("[");
    s.append(selector->operator string());
    s.append(" % (");
    s.append(this_obj->operator string());
    s.append(".length + 1)] = ");
    s.append(value->operator string());
    return s;
}
void HIRMutate::JS::ArrayStoreIndex::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ArrayStoreIndex");
    API::serialize(stream, context);
    value->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ArrayStoreIndex::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    value = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ArrayStoreIndexTemplate::ArrayStoreIndexTemplate(Arg *(*value_class)(), Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
    this->value_class = value_class;
}

HIRMutate::JS::API *HIRMutate::JS::ArrayStoreIndexTemplate::instantiate()
{
    Arg *value = value_class();
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new ArrayStoreIndex(value, this_obj, selector);
}

bool HIRMutate::JS::ArrayStoreIndexTemplate::satiable(JSContext *context)
{
    Arg *value = value_class();
    bool res = is_satiable_arg(value, context);
    delete value;
    return res;
}

HIRMutate::JS::DOMStringMapStoreIndex::DOMStringMapStoreIndex(Arg *value, Arg *this_obj, Arg *index) : API(nullptr, this_obj)
{
    this->value = value;
    this->index = index;
}
HIRMutate::JS::DOMStringMapStoreIndex::~DOMStringMapStoreIndex()
{
    if (value)
        delete value;
    if (index)
        delete index;
}
void HIRMutate::JS::DOMStringMapStoreIndex::generate(JSContext *context)
{
    this_obj->generate(context);
    value->generate(context);
    index->generate(context);
}

bool HIRMutate::JS::DOMStringMapStoreIndex::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        return this_obj->mutate(context);
    else if (c == 1)
        return value->mutate(context);
    else
        return index->mutate(context);
}

void HIRMutate::JS::DOMStringMapStoreIndex::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::DOMStringMapStoreIndex::operator string()
{
    string s = this_obj->operator string();
    s.append("[");
    s.append(index->operator string());
    s.append("] = ");
    s.append(value->operator string());
    return s;
}
void HIRMutate::JS::DOMStringMapStoreIndex::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DOMStringMapStoreIndex");
    API::serialize(stream, context);
    value->serialize(stream, context);
    index->serialize(stream, context);
}
void HIRMutate::JS::DOMStringMapStoreIndex::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    value = arg_classes[stream->read_string()](stream, global_document, function);
    index = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::DOMStringMapStoreIndexTemplate::DOMStringMapStoreIndexTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}
HIRMutate::JS::API *HIRMutate::JS::DOMStringMapStoreIndexTemplate::instantiate()
{
    Arg *index = new StringArg();
    Arg *value = new StringArg();
    Arg *this_obj = this_class();
    return new DOMStringMapStoreIndex(value, this_obj, index);
}

bool HIRMutate::JS::DOMStringMapStoreIndexTemplate::satiable(JSContext *context)
{
    return true;
}

void HIRMutate::JS::initialize_html_properties()
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CSS
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // StyleSheet
    // FIXME: We do not support write .disabled.
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "href"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "ownerNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "parentStyleSheet"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "title"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MediaListRet), HANDLE_ARG(StyleSheetArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleSheetArg), "disabled"));

    // CSSStyleSheet
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleSheetArg), "ownerRule"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleRuleListRet), HANDLE_ARG(CSSStyleSheetArg), "cssRules"));

    // CSSKeyframesSheet
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSKeyframesRuleListRet), HANDLE_ARG(CSSKeyframesSheetArg), "cssRules"));

    // CSSRule
    // WARN: .cssText is implemented in child classes.
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSRuleArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSRuleArg), "parentRule"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSRuleArg), "parentStyleSheet"));

    // CSSStyleRuleList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(CSSStyleRuleRet), HANDLE_ARG(CSSStyleRuleListArg)));

    // CSSStyleRule
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleRuleArg), "cssText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSStyleRuleValueArg), HANDLE_ARG(CSSStyleRuleArg), "cssText"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleRuleArg), "selectorText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSSelectorValueArg), HANDLE_ARG(CSSStyleRuleArg), "selectorText"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleDeclarationRet), HANDLE_ARG(CSSStyleRuleArg), "style"));

    // CSSStyleDeclaration
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleDeclarationArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleRuleRet), HANDLE_ARG(CSSStyleDeclarationArg), "parentRule"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleDeclarationArg), "cssFloat"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSFloatArg), HANDLE_ARG(CSSStyleDeclarationArg), "cssFloat"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSStyleDeclarationArg), "cssText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSStyleDeclarationValueArg), HANDLE_ARG(CSSStyleDeclarationArg), "cssText"));

    // CSSKeyframesRuleList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(CSSKeyframesRuleRet), HANDLE_ARG(CSSKeyframesRuleListArg)));

    // CSSKeyframesRule
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSKeyframesRuleArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSKeyframeRuleListRet), HANDLE_ARG(CSSKeyframesRuleArg), "cssRules"));

    // CSSKeyframeRuleList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(CSSKeyframeRuleRet), HANDLE_ARG(CSSKeyframeRuleListArg)));

    // CSSKeyframeRule
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSKeyframeRuleArg), "keyText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSKeyframeNameArg), HANDLE_ARG(CSSKeyframeRuleArg), "keyText"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CSSKeyframeRuleArg), "cssText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSKeyframeRuleValueArg), HANDLE_ARG(CSSKeyframeRuleArg), "cssText"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleDeclarationRet), HANDLE_ARG(CSSKeyframeRuleArg), "style"));

    // MediaQueryList
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaQueryListArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaQueryListArg), "matches"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(MediaQueryListArg), "onchange"));

    // MediaList
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaListArg), "mediaText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaQueryArg), HANDLE_ARG(MediaListArg), "mediaText"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaListArg), "length"));

    // StyleMedia
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StyleMediaArg), "type"));

    // FontFaceSet
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceSetArg), "size"));
    // add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceSetArg), "ready"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceSetArg), "status")); // FontFaceSetLoadStatus
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(FontFaceSetArg), "onloading"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(FontFaceSetArg), "onloadingdone"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(FontFaceSetArg), "onloadingerror"));

    // FontFace
    // add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "loaded"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "status")); // FontFaceLoadStatus
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "family"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontArg), HANDLE_ARG(FontFaceArg), "family"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "style"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSStyleDeclarationValueArg), HANDLE_ARG(FontFaceArg), "style"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "weight"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontWeightArg), HANDLE_ARG(FontFaceArg), "weight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "stretch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontStretchArg), HANDLE_ARG(FontFaceArg), "stretch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "unicodeRange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(UnicodeRangeArg), HANDLE_ARG(FontFaceArg), "unicodeRange"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "variant"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontVariantArg), HANDLE_ARG(FontFaceArg), "variant"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(FontFaceArg), "featureSettings"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontFeatureSettingsArg), HANDLE_ARG(FontFaceArg), "featureSettings"));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // DOM
    // TODO: HTMLBaseElement, HTMLBodyElement, HTMLScriptElement
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // DocumentOrShadowRoot
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentOrShadowRootArg), "pointerLockElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentOrShadowRootArg), "activeElement"));

    // Window
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "top"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "self"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(WindowArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "event"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "window"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "frames"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "opener"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "closed"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(WindowArg), "parent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(WindowArg), "document"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(nullptr, HANDLE_ARG(WindowArg)));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "status"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(WindowArg), "status"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "defaultStatus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(WindowArg), "defaultStatus"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "locationbar"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "menubar"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "personalbar"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "scrollbars"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "statusbar"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(BarPropRet), HANDLE_ARG(WindowArg), "toolbar"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ScreenRet), HANDLE_ARG(WindowArg), "screen"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(VisualViewportRet), HANDLE_ARG(WindowArg), "visualViewport"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HistoryRet), HANDLE_ARG(WindowArg), "history"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(WindowArg), "frameElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NavigatorRet), HANDLE_ARG(WindowArg), "navigator"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ApplicationCacheRet), HANDLE_ARG(WindowArg), "applicationCache"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CustomElementRegistryRet), HANDLE_ARG(WindowArg), "customElements"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NavigatorRet), HANDLE_ARG(WindowArg), "clientInformation"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(StyleMediaRet), HANDLE_ARG(WindowArg), "styleMedia"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "innerWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "innerHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "scrollX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "pageXOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "scrollY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "pageYOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "screenX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "screenY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "outerWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "outerHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "devicePixelRatio"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "offscreenBuffering"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "screenLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "screenTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "orientation"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "isSecureContext"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "webkitURL"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "WebKitTransitionEvent"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "WebKitAnimationEvent"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WindowArg), "WebKitMutationObserver"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onanimationend"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onanimationiteration"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onanimationstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onorientationchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onsearch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "ontransitionend"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onwebkitanimationend"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onwebkitanimationiteration"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onwebkitanimationstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onwebkittransitionend"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(WindowArg), "onwheel"));

    // NodeList
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NodeListArg), "length"));

    // Attr
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "namespaceURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "prefix"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "localName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "specified"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(AttrArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "nodeValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(AttrArg), "nodeValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AttrArg), "textContent"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(AttrArg), "textContent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(AttrArg), "ownerElement"));

    // NamedNodeMap
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NamedNodeMapArg), "length"));
    add_api(std::make_shared<DOMStringMapStoreIndexTemplate>(HANDLE_ARG(NamedNodeMapArg)));

    // Document
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "domain"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "applets"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "scripts"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "referrer"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(DocumentArg), "defaultView"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "currentScript"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "documentElement"));
    // add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "body"));
    // add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "head"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(FontFaceSetRet), HANDLE_ARG(DocumentArg), "fonts"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "designMode"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DesignModeArg), HANDLE_ARG(DocumentArg), "designMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLAllCollectionRet), HANDLE_ARG(DocumentArg), "all"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentTimelineRet), HANDLE_ARG(DocumentArg), "timeline"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(FontFaceSetRet), HANDLE_ARG(DocumentArg), "fonts"));
    // add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "rootScroller"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "scrollingElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "images"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "embeds"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "plugins"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "links"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "forms"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(DocumentArg), "anchors"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentTypeRet), HANDLE_ARG(DocumentArg), "doctype"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMImplementationRet), HANDLE_ARG(DocumentArg), "implementation"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "title"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(DocumentArg), "title"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "dir"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DirArg), HANDLE_ARG(DocumentArg), "dir"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "fgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(DocumentArg), "fgColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "linkColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(DocumentArg), "linkColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "vlinkColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(DocumentArg), "vlinkColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "alinkColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(DocumentArg), "alinkColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "bgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(DocumentArg), "bgColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "xmlEncoding"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "xmlVersion"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(DocumentArg), "xmlVersion"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "xmlStandalone"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(DocumentArg), "xmlStandalone"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "cookie"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(DocumentArg), "cookie"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "URL"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "documentURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "origin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "suborigin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "compatMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "characterSet"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "charset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "inputEncoding"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "contentType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "lastModified"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "readyState"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "hidden"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "webkitHidden"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "visibilityState"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "webkitVisibilityState"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "webkitIsFullScreen"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "fullscreenEnabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentArg), "webkitFullscreenEnabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "fullscreenElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "webkitCurrentFullScreenElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(DocumentArg), "webkitFullscreenElement"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onreadystatechange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onsearch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onselectionchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onselectstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onfullscreenchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onfullscreenerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onwebkitfullscreenchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onwebkitfullscreenerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onpointerlockchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onpointerlockerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onsecuritypolicyviolation"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(DocumentArg), "onwheel"));

    // DocumentType
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentTypeArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentTypeArg), "publicId"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DocumentTypeArg), "systemId"));

    // ShadowRoot
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ShadowRootArg), "mode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ShadowRootArg), "delegatesFocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ShadowRootArg), "host"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ShadowRootRet), HANDLE_ARG(ShadowRootArg), "olderShadowRoot"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLStringRet), HANDLE_ARG(ShadowRootArg), "innerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLStringArg), HANDLE_ARG(ShadowRootArg), "innerHTML"));

    // ProcessingInstruction
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ProcessingInstructionArg), "target"));

    // Element
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "nodeType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "nodeName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "baseURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "isConnected"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(ElementArg), "ownerDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NamedNodeMapRet), HANDLE_ARG(ElementArg), "attributes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleDeclarationRet), HANDLE_ARG(ElementArg), "style"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "parentNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "parentElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NodeListRet), HANDLE_ARG(ElementArg), "childNodes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "firstChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "lastChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "previousSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "nextSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "nodeValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(ElementArg), "nodeValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "textContent"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(ElementArg), "textContent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(ElementArg), "children"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "firstElementChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "lastElementChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "childElementCount"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "namespaceURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "prefix"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "localName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "tagName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(ElementArg), "classList"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "className"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClassArg), HANDLE_ARG(ElementArg), "className"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLStringRet), HANDLE_ARG(ElementArg), "innerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(ElementArg), "innerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLStringArg), HANDLE_ARG(ElementArg), "innerHTML"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLStringRet), HANDLE_ARG(ElementArg), "outerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(ElementArg), "outerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLStringArg), HANDLE_ARG(ElementArg), "outerHTML"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ShadowRootRet), HANDLE_ARG(ElementArg), "shadowRoot"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "slot"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SlotArg), HANDLE_ARG(ElementArg), "slot"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLSlotElementRet), HANDLE_ARG(ElementArg), "assignedSlot"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "scrollTop"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(ElementArg), "scrollTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "scrollLeft"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(ElementArg), "scrollLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "scrollWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "scrollHeight")); // https://bugs.chromium.org/p/project-zero/issues/detail?id=1525
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "clientTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "clientLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "clientWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "clientHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "computedRole"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ElementArg), "computedName"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "previousElementSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementArg), "nextElementSibling"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "onwheel"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "onsearch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "onbeforeload"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "onselectstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "ongotpointercapture"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ElementArg), "onlostpointercapture"));

    // CharacterData
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CharacterDataArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CharacterDataArg), "data"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(CharacterDataArg), "data"));

    // NodeIterator
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(NodeIteratorArg), "root"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(NodeIteratorArg), "referenceNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NodeIteratorArg), "pointerBeforeReferenceNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NodeIteratorArg), "whatToShow"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NodeFilterRet), HANDLE_ARG(NodeIteratorArg), "filter"));

    // TreeWalker
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "root"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TreeWalkerArg), "whatToShow"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NodeFilterRet), HANDLE_ARG(TreeWalkerArg), "filter"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(TreeWalkerArg), "currentNode"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(TreeWalkerArg), "currentNode"));

    // Text
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextArg), "wholeText"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLSlotElementRet), HANDLE_ARG(TextArg), "assignedSlot"));

    // TimeRanges
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TimeRangesArg), "length"));

    // Selection
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(SelectionArg), "anchorNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "anchorOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(SelectionArg), "focusNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "focusOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "isCollapsed"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "rangeCount"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(SelectionArg), "baseNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "baseOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(SelectionArg), "extentNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SelectionArg), "extentOffset"));

    // HTMLAllCollection
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAllCollectionArg), "length"));

    // HTMLOptionsCollection
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionsCollectionArg), "length"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLOptionsCollectionArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionsCollectionArg), "selectedIndex"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IndexArg), HANDLE_ARG(HTMLOptionsCollectionArg), "selectedIndex"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(HTMLOptionElementRet), HANDLE_ARG(HTMLOptionsCollectionArg)));
    add_api(std::make_shared<ArrayStoreIndexTemplate>(HANDLE_ARG(HTMLOptionElementArg), HANDLE_ARG(HTMLOptionsCollectionArg)));

    // HTMLElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleDeclarationRet), HANDLE_ARG(HTMLElementArg), "style"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "accessKey"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharArg), HANDLE_ARG(HTMLElementArg), "accessKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "autocapitalize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AutoCapitalizeArg), HANDLE_ARG(HTMLElementArg), "autocapitalize"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "autocorrect"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLElementArg), "autocorrect"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "contentEditable"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ContentEditableArg), HANDLE_ARG(HTMLElementArg), "contentEditable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "dir"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DirArg), HANDLE_ARG(ElementArg), "dir"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "draggable"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLElementArg), "draggable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "hidden"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLElementArg), "hidden"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "innerText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLElementArg), "innerText"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "isContentEditable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "lang"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LangArg), HANDLE_ARG(HTMLElementArg), "lang"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "outerText"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLElementArg), "outerText"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "spellcheck"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLElementArg), "spellcheck"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "tabIndex"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TabIndexArg), HANDLE_ARG(HTMLElementArg), "tabIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "title"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLElementArg), "title"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "translate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLElementArg), "translate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "webkitdropzone"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DropZoneArg), HANDLE_ARG(HTMLElementArg), "webkitdropzone"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLMenuElementRet), HANDLE_ARG(HTMLElementArg), "contextMenu"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLMenuElementArg), HANDLE_ARG(HTMLElementArg), "contextMenu"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLElementRet), HANDLE_ARG(HTMLElementArg), "offsetParent"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "offsetTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "offsetLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "offsetWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLElementArg), "offsetHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMStringMapRet), HANDLE_ARG(HTMLElementArg), "dataset"));

    // HTMLAnchorElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MIMETypeArg), HANDLE_ARG(HTMLAnchorElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "download"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "referrerPolicy"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "charset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharsetArg), HANDLE_ARG(HTMLAnchorElementArg), "charset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "coords"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CoordsArg), HANDLE_ARG(HTMLAnchorElementArg), "coords"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "shape"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ShapeArg), HANDLE_ARG(HTMLAnchorElementArg), "shape"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "target"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLAnchorElementArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "text"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLAnchorElementArg), "text"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "ping"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLAnchorElementArg), "ping"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "rel"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RelArg), HANDLE_ARG(HTMLAnchorElementArg), "rel"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "href"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLAnchorElementArg), "href"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "hreflang"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LangArg), HANDLE_ARG(HTMLAnchorElementArg), "hreflang"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAnchorElementArg), "rev"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RevArg), HANDLE_ARG(HTMLAnchorElementArg), "rev"));

    // HTMLAreaElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "alt"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLAreaElementArg), "alt"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "coords"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CoordsArg), HANDLE_ARG(HTMLAreaElementArg), "coords"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "noHref"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLAreaElementArg), "noHref"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "shape"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ShapeArg), HANDLE_ARG(HTMLAreaElementArg), "shape"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "target"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLAreaElementArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "href"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLAreaElementArg), "href"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "ping"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLAreaElementArg), "ping"));

    // HTMLMediaElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitKeys"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "crossOrigin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "autoplay"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "autoplay"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "controls"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "controls"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "currentTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockArg), HANDLE_ARG(HTMLMediaElementArg), "currentTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "defaultPlaybackRate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMediaElementArg), "defaultPlaybackRate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "loop"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "loop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "muted"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "muted"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "playbackRate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMediaElementArg), "playbackRate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "preload"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(PreloadArg), HANDLE_ARG(HTMLMediaElementArg), "preload"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaSrcArg), HANDLE_ARG(HTMLMediaElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "volume"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VolumeArg), HANDLE_ARG(HTMLMediaElementArg), "volume"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TimeRangesRet), HANDLE_ARG(HTMLMediaElementArg), "buffered"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "currentSrc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "duration"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "ended"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MediaErrorRet), HANDLE_ARG(HTMLMediaElementArg), "error"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "networkState"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "paused"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TimeRangesRet), HANDLE_ARG(HTMLMediaElementArg), "played"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "readyState"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TimeRangesRet), HANDLE_ARG(HTMLMediaElementArg), "seekable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "seeking"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "startTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(AudioTrackListRet), HANDLE_ARG(HTMLMediaElementArg), "audioTracks"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MediaControllerRet), HANDLE_ARG(HTMLMediaElementArg), "controller"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaControllerArg), HANDLE_ARG(HTMLMediaElementArg), "controller"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "defaultMuted"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "defaultMuted"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "kind"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TrackKindArg), HANDLE_ARG(HTMLMediaElementArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "mediaGroup"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaGroupArg), HANDLE_ARG(HTMLMediaElementArg), "mediaGroup"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MediaSessionRet), HANDLE_ARG(HTMLMediaElementArg), "session"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaSessionArg), HANDLE_ARG(HTMLMediaElementArg), "session"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MediaStreamRet), HANDLE_ARG(HTMLMediaElementArg), "srcObject"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaStreamArg), HANDLE_ARG(HTMLMediaElementArg), "srcObject"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackListRet), HANDLE_ARG(HTMLMediaElementArg), "textTracks"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(VideoTrackListRet), HANDLE_ARG(HTMLMediaElementArg), "videoTracks"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitClosedCaptionsVisible"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "webkitClosedCaptionsVisible"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitCurrentPlaybackTargetIsWireless"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitHasClosedCaptions"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitPreservesPitch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMediaElementArg), "webkitPreservesPitch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitAudioDecodedByteCount"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMediaElementArg), "webkitVideoDecodedByteCount"));

    // HTMLBRElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLBRElementArg), "clear"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClearArg), HANDLE_ARG(HTMLBRElementArg), "clear"));

    // HTMLButtonElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "formAction"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "autofocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLButtonElementArg), "autofocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLButtonElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLButtonElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "formEnctype"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormEncTypeArg), HANDLE_ARG(HTMLButtonElementArg), "formEnctype"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "formMethod"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormMethodArg), HANDLE_ARG(HTMLButtonElementArg), "formMethod"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "formNoValidate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLButtonElementArg), "formNoValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "formTarget"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLButtonElementArg), "formTarget"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLButtonElementArg), "labels"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLButtonElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ButtonTypeArg), HANDLE_ARG(HTMLButtonElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLButtonElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLButtonElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLButtonElementArg), "willValidate"));

    // HTMLDListElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDListElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDListElementArg), "compact"));

    // HTMLDataElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDataElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLDataElementArg), "value"));

    // HTMLDetailsElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDetailsElementArg), "open"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDetailsElementArg), "open"));

    // HTMLDirectoryElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDirectoryElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDirectoryElementArg), "compact"));

    // HTMLDivElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDivElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AlignArg), HANDLE_ARG(HTMLDivElementArg), "align"));

    // HTMLIFrameElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(HTMLIFrameElementArg), "sandbox"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(HTMLIFrameElementArg), "contentDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(HTMLIFrameElementArg), "contentWindow"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "getSVGDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "referrerPolicy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(HTMLIFrameElementArg), "permissions"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "csp"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FrameSrcArg), HANDLE_ARG(HTMLIFrameElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "srcdoc"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLIFrameElementArg), "srcdoc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "allowFullscreen"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLIFrameElementArg), "allowFullscreen"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLIFrameElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLIFrameElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ObjectAlignArg), HANDLE_ARG(HTMLIFrameElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "scrolling"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ScrollingArg), HANDLE_ARG(HTMLIFrameElementArg), "scrolling"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "frameBorder"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLIFrameElementArg), "frameBorder"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "longDesc"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLIFrameElementArg), "longDesc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "marginHeight"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLIFrameElementArg), "marginHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLIFrameElementArg), "marginWidth"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLIFrameElementArg), "marginWidth"));

    // HTMLTableElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableCaptionElementRet), HANDLE_ARG(HTMLTableElementArg), "caption"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLTableCaptionElementArg), HANDLE_ARG(HTMLTableElementArg), "caption"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableElementArg), "tHead"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLTableSectionElementArg), HANDLE_ARG(HTMLTableElementArg), "tHead"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableSectionElementRet), HANDLE_ARG(HTMLTableElementArg), "tFoot"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(HTMLTableSectionElementArg), HANDLE_ARG(HTMLTableElementArg), "tFoot"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableSectionsCollectionRet), HANDLE_ARG(HTMLTableElementArg), "tBodies"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableRowsCollectionRet), HANDLE_ARG(HTMLTableElementArg), "rows"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AlignArg), HANDLE_ARG(HTMLTableElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "border"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableElementArg), "border"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "frame"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableFrameArg), HANDLE_ARG(HTMLTableElementArg), "frame"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "rules"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableRulesArg), HANDLE_ARG(HTMLTableElementArg), "rules"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "summary"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTableElementArg), "summary"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "bgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLTableElementArg), "bgColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "cellPadding"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableElementArg), "cellPadding"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableElementArg), "cellSpacing"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableElementArg), "cellSpacing"));

    // HTMLFrameElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(HTMLFrameElementArg), "contentWindow"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(HTMLFrameElementArg), "contentDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "longDesc"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLFrameElementArg), "longDesc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "scrolling"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ScrollingArg), HANDLE_ARG(HTMLFrameElementArg), "scrolling"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FrameSrcArg), HANDLE_ARG(HTMLFrameElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "frameBorder"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFrameElementArg), "frameBorder"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "noResize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLFrameElementArg), "noResize"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "marginHeight"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFrameElementArg), "marginHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameElementArg), "marginWidth"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFrameElementArg), "marginWidth"));

    // HTMLTableColElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "span"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableColElementArg), "span"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableAlignArg), HANDLE_ARG(HTMLTableColElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "ch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharArg), HANDLE_ARG(HTMLTableColElementArg), "ch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "chOff"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableColElementArg), "chOff"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "vAlign"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VAlignArg), HANDLE_ARG(HTMLTableColElementArg), "vAlign"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableColElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableColElementArg), "width"));

    // HTMLDialogElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDialogElementArg), "open"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDialogElementArg), "open"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDialogElementArg), "returnValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLDialogElementArg), "returnValue"));

    // HTMLTextAreaElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "dirName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "autofocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTextAreaElementArg), "autofocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "cols"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "cols"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTextAreaElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLTextAreaElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "inputMode"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(InputModeArg), HANDLE_ARG(HTMLTextAreaElementArg), "inputMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "maxLength"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "maxLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "minLength"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "minLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "placeholder"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTextAreaElementArg), "placeholder"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "readOnly"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTextAreaElementArg), "readOnly"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "required"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTextAreaElementArg), "required"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "rows"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "rows"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "wrap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(WrapArg), HANDLE_ARG(HTMLTextAreaElementArg), "wrap"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "defaultValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTextAreaElementArg), "defaultValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTextAreaElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "textLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLTextAreaElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLTextAreaElementArg), "labels"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "selectionStart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "selectionStart"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "selectionEnd"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTextAreaElementArg), "selectionEnd"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "selectionDirection"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SelectionDirectionArg), HANDLE_ARG(HTMLTextAreaElementArg), "selectionDirection"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTextAreaElementArg), "autocapitalize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AutoCapitalizeArg), HANDLE_ARG(HTMLTextAreaElementArg), "autocapitalize"));

    // HTMLOListElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOListElementArg), "reversed"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOListElementArg), "reversed"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOListElementArg), "start"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLOListElementArg), "start"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOListElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(NumberingTypeArg), HANDLE_ARG(HTMLOListElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOListElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOListElementArg), "compact"));

    // HTMLProgressElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLProgressElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLProgressElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLProgressElementArg), "max"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLProgressElementArg), "max"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLProgressElementArg), "position"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLProgressElementArg), "labels"));

    // HTMLQuoteElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLQuoteElementArg), "cite"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLQuoteElementArg), "cite"));

    // HTMLFormElement
    // TODO: action
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "encoding"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "acceptCharset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharsetArg), HANDLE_ARG(HTMLFormElementArg), "acceptCharset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "autocomplete"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AutoCompleteArg), HANDLE_ARG(HTMLFormElementArg), "autocomplete"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "enctype"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormEncTypeArg), HANDLE_ARG(HTMLFormElementArg), "enctype"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "method"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormMethodArg), HANDLE_ARG(HTMLFormElementArg), "method"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "noValidate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLFormElementArg), "noValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "target"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLFormElementArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(HTMLFormElementArg), "elements")); // HTMLFormControlsCollection
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(HTMLFormElementArg)));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFormElementArg), "length"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(HTMLElementRet), HANDLE_ARG(HTMLFormElementArg)));

    // HTMLHeadingElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHeadingElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AlignArg), HANDLE_ARG(HTMLHeadingElementArg), "align"));

    // HTMLLegendElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLLegendElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLegendElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CaptionAlignArg), HANDLE_ARG(HTMLLegendElementArg), "align"));

    // HTMLSlotElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSlotElementArg), "name"));

    // HTMLPreElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLPreElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLPreElementArg), "width"));

    // HTMLKeygenElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "autofocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLKeygenElementArg), "autofocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "challenge"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLKeygenElementArg), "challenge"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLKeygenElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLKeygenElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "keytype"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(KeyTypeArg), HANDLE_ARG(HTMLKeygenElementArg), "keytype"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLKeygenElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLKeygenElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLKeygenElementArg), "labels"));

    // HTMLSourceElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSourceElementArg), "sizes"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSourceElementArg), "media"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaQueryArg), HANDLE_ARG(HTMLSourceElementArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSourceElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaTypeArg), HANDLE_ARG(HTMLSourceElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSourceElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaSrcArg), HANDLE_ARG(HTMLSourceElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSourceElementArg), "srcset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SrcSetArg), HANDLE_ARG(HTMLSourceElementArg), "srcset"));

    // HTMLMetaElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMetaElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMetaElementArg), "httpEquiv"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMetaElementArg), "content"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLMetaElementArg), "content"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMetaElementArg), "scheme"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MetaSchemeArg), HANDLE_ARG(HTMLMetaElementArg), "scheme"));

    // HTMLTableRowElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "rowIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "sectionRowIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableCellsCollectionRet), HANDLE_ARG(HTMLTableRowElementArg), "cells"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableAlignArg), HANDLE_ARG(HTMLTableRowElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "ch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharArg), HANDLE_ARG(HTMLTableRowElementArg), "ch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "chOff"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableRowElementArg), "chOff"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "vAlign"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VAlignArg), HANDLE_ARG(HTMLTableRowElementArg), "vAlign"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableRowElementArg), "bgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLTableRowElementArg), "bgColor"));

    // HTMLTableCaptionElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCaptionElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CaptionAlignArg), HANDLE_ARG(HTMLTableCaptionElementArg), "align"));

    // HTMLFrameSetElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameSetElementArg), "cols"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFrameSetElementArg), "cols"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFrameSetElementArg), "rows"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFrameSetElementArg), "rows"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onblur"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onfocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onload"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onresize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onscroll"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLFrameSetElementArg), "onorientationchange"));

    // HTMLModElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLModElementArg), "cite"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLModElementArg), "cite"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLModElementArg), "dateTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DateTimeArg), HANDLE_ARG(HTMLModElementArg), "dateTime"));

    // HTMLParagraphElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLParagraphElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AlignArg), HANDLE_ARG(HTMLParagraphElementArg), "align"));

    // HTMLObjectElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "code"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "codeBase"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "codeType"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(HTMLObjectElementArg), "contentWindow"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(HTMLObjectElementArg), "contentDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaTypeArg), HANDLE_ARG(HTMLObjectElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "data"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLObjectElementArg), "data"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "useMap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(UseMapArg), HANDLE_ARG(HTMLObjectElementArg), "useMap"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLObjectElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLObjectElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLObjectElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLObjectElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ObjectAlignArg), HANDLE_ARG(HTMLObjectElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "archive"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLObjectElementArg), "archive"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "declare"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLObjectElementArg), "declare"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "hspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLObjectElementArg), "hspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "standby"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLObjectElementArg), "standby"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "vspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLObjectElementArg), "vspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLObjectElementArg), "border"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLObjectElementArg), "border"));

    // HTMLSelectElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "autofocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLSelectElementArg), "autofocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLSelectElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLSelectElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "multiple"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLSelectElementArg), "multiple"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "required"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLSelectElementArg), "required"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "size"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLSelectElementArg), "size"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLOptionsCollectionRet), HANDLE_ARG(HTMLSelectElementArg), "options"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "length"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLSelectElementArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLOptionsCollectionRet), HANDLE_ARG(HTMLSelectElementArg), "selectedOptions"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "selectedIndex"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IndexArg), HANDLE_ARG(HTMLSelectElementArg), "selectedIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLSelectElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLSelectElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLSelectElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLSelectElementArg), "labels"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(HTMLOptionElementRet), HANDLE_ARG(HTMLSelectElementArg)));

    // HTMLDirectoryElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDirectoryElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDirectoryElementArg), "compact"));

    // HTMLParamElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLParamElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLParamElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLParamElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLParamElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLParamElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLParamElementArg), "valueType"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ParamValueTypeArg), HANDLE_ARG(HTMLParamElementArg), "valueType"));

    // HTMLDataListElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLOptionsCollectionRet), HANDLE_ARG(HTMLDataListElementArg), "options"));

    // HTMLHRElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHRElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AlignArg), HANDLE_ARG(HTMLHRElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHRElementArg), "color"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLHRElementArg), "color"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHRElementArg), "noShade"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLHRElementArg), "noShade"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHRElementArg), "size"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLHRElementArg), "size"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLHRElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLHRElementArg), "width"));

    // HTMLLinkElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "integrity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "crossOrigin"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(HTMLLinkElementArg), "sizes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(HTMLLinkElementArg), "relList"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MIMETypeArg), HANDLE_ARG(HTMLLinkElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLLinkElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "href"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DummyUrlArg), HANDLE_ARG(HTMLLinkElementArg), "href"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "rel"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RelArg), HANDLE_ARG(HTMLLinkElementArg), "rel"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "rev"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RevArg), HANDLE_ARG(HTMLLinkElementArg), "rev"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "media"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaQueryArg), HANDLE_ARG(HTMLLinkElementArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "hreflang"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LangArg), HANDLE_ARG(HTMLLinkElementArg), "hreflang"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "as"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LinkAsArg), HANDLE_ARG(HTMLLinkElementArg), "as"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLinkElementArg), "charset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharsetArg), HANDLE_ARG(HTMLLinkElementArg), "charset"));

    // HTMLScriptElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "nonce"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "charset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "integrity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "crossOrigin"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharsetArg), HANDLE_ARG(HTMLScriptElementArg), "charset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "async"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLScriptElementArg), "async"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "defer"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLScriptElementArg), "defer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLScriptElementArg), "text"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLScriptElementArg), "text"));

    // HTMLStyleElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLStyleElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLStyleElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLStyleElementArg), "media"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaQueryArg), HANDLE_ARG(HTMLStyleElementArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLStyleElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSTypeArg), HANDLE_ARG(HTMLStyleElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleSheetRet), HANDLE_ARG(HTMLStyleElementArg), "sheet"));

    // HTMLCanvasElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLCanvasElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLCanvasElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLCanvasElementArg), "height"));

    // HTMLDListElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLDListElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLDListElementArg), "compact"));

    // HTMLOutputElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(HTMLOutputElementArg), "htmlFor"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLOutputElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOutputElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "defaultValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOutputElementArg), "defaultValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLOutputElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOutputElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLOutputElementArg), "labels"));

    // HTMLTrackElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "kind"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TrackKindArg), HANDLE_ARG(HTMLTrackElementArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TrackSrcArg), HANDLE_ARG(HTMLTrackElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "srclang"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LangArg), HANDLE_ARG(HTMLTrackElementArg), "srclang"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "label"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTrackElementArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "default"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTrackElementArg), "default"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTrackElementArg), "readyState"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackRet), HANDLE_ARG(HTMLTrackElementArg), "track"));

    // HTMLUListElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLUListElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLUListElementArg), "compact"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLUListElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(UListTypeArg), HANDLE_ARG(HTMLUListElementArg), "type"));

    // HTMLAreaElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "ping"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "download"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "referrerPolicy"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "alt"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLAreaElementArg), "alt"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "coords"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CoordsArg), HANDLE_ARG(HTMLAreaElementArg), "coords"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "shape"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ShapeArg), HANDLE_ARG(HTMLAreaElementArg), "shape"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "target"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLAreaElementArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "rel"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RelArg), HANDLE_ARG(HTMLAreaElementArg), "rel"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLAreaElementArg), "noHref"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLAreaElementArg), "noHref"));

    // HTMLLabelElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLLabelElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLElementRet), HANDLE_ARG(HTMLLabelElementArg), "control"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLabelElementArg), "htmlFor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LabelForArg), HANDLE_ARG(HTMLLabelElementArg), "htmlFor"));

    // HTMLMapElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMapElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLAreasCollectionRet), HANDLE_ARG(HTMLMapElementArg), "areas"));

    // HTMLVideoElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLVideoElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLVideoElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "videoWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "videoHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "poster"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ImageSrcArg), HANDLE_ARG(HTMLVideoElementArg), "poster"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitSupportsFullscreen"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitDisplayingFullscreen"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitDecodedFrameCount"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLVideoElementArg), "webkitDroppedFrameCount"));

    // HTMLTableSectionElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLTableRowsCollectionRet), HANDLE_ARG(HTMLTableSectionElementArg), "rows"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableSectionElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableAlignArg), HANDLE_ARG(HTMLTableSectionElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableSectionElementArg), "ch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharArg), HANDLE_ARG(HTMLTableSectionElementArg), "ch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableSectionElementArg), "chOff"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableSectionElementArg), "chOff"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableSectionElementArg), "vAlign"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VAlignArg), HANDLE_ARG(HTMLTableSectionElementArg), "vAlign"));

    // HTMLFieldSetElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLFieldSetElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLFieldSetElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLFieldSetElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLCollectionRet), HANDLE_ARG(HTMLFieldSetElementArg), "elements")); // HTMLFormControlsCollection
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLFieldSetElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFieldSetElementArg), "validationMessage"));

    // HTMLTableCellElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "colSpan"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableCellElementArg), "colSpan"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "rowSpan"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableCellElementArg), "rowSpan"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "headers"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableHeadersArg), HANDLE_ARG(HTMLTableCellElementArg), "headers"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "cellIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableAlignArg), HANDLE_ARG(HTMLTableCellElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "axis"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableAxisArg), HANDLE_ARG(HTMLTableCellElementArg), "axis"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableCellElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLTableCellElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "ch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CharArg), HANDLE_ARG(HTMLTableCellElementArg), "ch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "chOff"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLTableCellElementArg), "chOff"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "noWrap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLTableCellElementArg), "noWrap"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "vAlign"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VAlignArg), HANDLE_ARG(HTMLTableCellElementArg), "vAlign"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "bgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLTableCellElementArg), "bgColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "abbr"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTableCellElementArg), "abbr"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTableCellElementArg), "scope"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TableScopeArg), HANDLE_ARG(HTMLTableCellElementArg), "scope"));

    // HTMLFontElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFontElementArg), "color"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLFontElementArg), "color"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFontElementArg), "face"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FontArg), HANDLE_ARG(HTMLFontElementArg), "face"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLFontElementArg), "size"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLFontElementArg), "size"));

    // HTMLOptionElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOptionElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLOptionElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "label"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOptionElementArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "defaultSelected"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOptionElementArg), "defaultSelected"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "selected"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOptionElementArg), "selected"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOptionElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "text"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOptionElementArg), "text"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptionElementArg), "index"));

    // HTMLMenuElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MenuTypeArg), HANDLE_ARG(HTMLMenuElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuElementArg), "label"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLMenuElementArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuElementArg), "compact"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMenuElementArg), "compact"));

    // HTMLMeterElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "min"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "min"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "max"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "max"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "low"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "low"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "high"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "high"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMeterElementArg), "optimum"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLMeterElementArg), "optimum"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLMeterElementArg), "labels"));

    // HTMLEmbedElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaTypeArg), HANDLE_ARG(HTMLEmbedElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLEmbedElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaSrcArg), HANDLE_ARG(HTMLEmbedElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLEmbedElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLEmbedElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLEmbedElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ObjectAlignArg), HANDLE_ARG(HTMLEmbedElementArg), "align"));

    // HTMLTitleElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTitleElementArg), "text"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLTitleElementArg), "text"));

    // HTMLInputElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "dirName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "formAction"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AcceptArg), HANDLE_ARG(HTMLInputElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "accept"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AcceptArg), HANDLE_ARG(HTMLInputElementArg), "accept"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "alt"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLInputElementArg), "alt"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "autocomplete"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AutoCompleteArg), HANDLE_ARG(HTMLInputElementArg), "autocomplete"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "autofocus"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "autofocus"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "defaultChecked"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "defaultChecked"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "checked"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "checked"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLFormElementRet), HANDLE_ARG(HTMLInputElementArg), "form"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "formEnctype"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormEncTypeArg), HANDLE_ARG(HTMLInputElementArg), "formEnctype"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "formMethod"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FormMethodArg), HANDLE_ARG(HTMLInputElementArg), "formMethod"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "formNoValidate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "formNoValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "formTarget"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TargetArg), HANDLE_ARG(HTMLInputElementArg), "formTarget"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "indeterminate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "indeterminate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "inputMode"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(InputModeArg), HANDLE_ARG(HTMLInputElementArg), "inputMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLElementRet), HANDLE_ARG(HTMLInputElementArg), "list"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "max"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "max"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "maxLength"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "maxLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "min"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "min"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "minLength"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "minLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "multiple"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "multiple"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "pattern"));
    add_api(std::make_shared<StorePropertyTemplate>((HANDLE_ARG(RegexArg)), HANDLE_ARG(HTMLInputElementArg), "pattern"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "placeholder"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLInputElementArg), "placeholder"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "readOnly"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "readOnly"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "required"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "required"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "size"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "size"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ImageSrcArg), HANDLE_ARG(HTMLInputElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "step"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "step"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(InputTypeArg), HANDLE_ARG(HTMLInputElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "defaultValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLInputElementArg), "defaultValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLInputElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "valueAsDate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DateTimeArg), HANDLE_ARG(HTMLInputElementArg), "valueAsDate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "valueAsNumber"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(HTMLInputElementArg), "valueAsNumber"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "willValidate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ValidityStateRet), HANDLE_ARG(HTMLInputElementArg), "validity"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "validationMessage"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLLabelElementListRet), HANDLE_ARG(HTMLInputElementArg), "labels"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "selectionStart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "selectionStart"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "selectionEnd"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLInputElementArg), "selectionEnd"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "selectionDirection"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SelectionDirectionArg), HANDLE_ARG(HTMLInputElementArg), "selectionDirection"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ObjectAlignArg), HANDLE_ARG(HTMLInputElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "useMap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(UseMapArg), HANDLE_ARG(HTMLInputElementArg), "useMap"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "autocapitalize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AutoCapitalizeArg), HANDLE_ARG(HTMLInputElementArg), "autocapitalize"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "capture"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "capture"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "webkitdirectory"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "webkitdirectory"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLInputElementArg), "incremental"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLInputElementArg), "incremental"));

    // HTMLMenuItemElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MenuItemTypeArg), HANDLE_ARG(HTMLMenuItemElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "label"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLMenuItemElementArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "icon"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ImageSrcArg), HANDLE_ARG(HTMLMenuItemElementArg), "icon"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMenuItemElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "checked"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMenuItemElementArg), "checked"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "radiogroup"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(RadioGroupArg), HANDLE_ARG(HTMLMenuItemElementArg), "radiogroup"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMenuItemElementArg), "default"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMenuItemElementArg), "default"));

    // HTMLTimeElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLTimeElementArg), "dateTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DateTimeArg), HANDLE_ARG(HTMLTimeElementArg), "dateTime"));

    // HTMLMarqueeElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "behavior"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MarqueeBehaviorArg), HANDLE_ARG(HTMLMarqueeElementArg), "behavior"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "bgColor"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ColorArg), HANDLE_ARG(HTMLMarqueeElementArg), "bgColor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "direction"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MarqueeDirectionArg), HANDLE_ARG(HTMLMarqueeElementArg), "direction"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLMarqueeElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "hspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLMarqueeElementArg), "hspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "loop"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MarqueeLoopArg), HANDLE_ARG(HTMLMarqueeElementArg), "loop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "scrollAmount"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLMarqueeElementArg), "scrollAmount"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "scrollDelay"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(HTMLMarqueeElementArg), "scrollDelay"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "trueSpeed"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLMarqueeElementArg), "trueSpeed"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "vspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLMarqueeElementArg), "vspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLMarqueeElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(LengthPercentageArg), HANDLE_ARG(HTMLMarqueeElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLMarqueeElementArg), "onstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLMarqueeElementArg), "onbounce"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(HTMLMarqueeElementArg), "onfinish"));

    // HTMLTemplateElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentFragmentRet), HANDLE_ARG(HTMLTemplateElementArg), "content"));

    // HTMLLIElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLIElementArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLLIElementArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLLIElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(NumberingTypeArg), HANDLE_ARG(HTMLLIElementArg), "type"));

    // HTMLImageElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "sizes"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "crossOrigin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "referrerPolicy"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "name"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLImageElementArg), "name"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "alt"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLImageElementArg), "alt"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "src"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ImageSrcArg), HANDLE_ARG(HTMLImageElementArg), "src"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "srcset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SrcSetArg), HANDLE_ARG(HTMLImageElementArg), "srcset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "useMap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(UseMapArg), HANDLE_ARG(HTMLImageElementArg), "useMap"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "isMap"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLImageElementArg), "isMap"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLImageElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLImageElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "naturalWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "naturalHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "complete"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "currentSrc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "lowsrc"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ImageSrcArg), HANDLE_ARG(HTMLImageElementArg), "lowsrc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ObjectAlignArg), HANDLE_ARG(HTMLImageElementArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "hspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLImageElementArg), "hspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "vspace"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLImageElementArg), "vspace"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "longDesc"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLImageElementArg), "longDesc"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "border"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(HTMLImageElementArg), "border"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLImageElementArg), "y"));

    // HTMLOptGroupElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptGroupElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(HTMLOptGroupElementArg), "disabled"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLOptGroupElementArg), "label"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(HTMLOptGroupElementArg), "label"));

    // HTMLContentElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HTMLContentElementArg), "select"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ContentSelectArg), HANDLE_ARG(HTMLContentElementArg), "select"));

    // ElementList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(ElementListArg)));
    add_api(std::make_shared<ArrayStoreIndexTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(ElementListArg)));

    // HTMLElementList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(HTMLElementRet), HANDLE_ARG(HTMLElementListArg)));
    add_api(std::make_shared<ArrayStoreIndexTemplate>(HANDLE_ARG(HTMLElementArg), HANDLE_ARG(HTMLElementListArg)));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Web Media
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // AudioTrackList
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AudioTrackListArg), "onchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AudioTrackListArg), "onaddtrack"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AudioTrackListArg), "onremovetrack"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(AudioTrackRet), HANDLE_ARG(AudioTrackListArg)));

    // AudioTrack
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AudioTrackArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AudioTrackArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AudioTrackArg), "language"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AudioTrackArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AudioTrackArg), "enabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(AudioTrackArg), "enabled"));

    // VideoTrackList
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackListArg), "selectedIndex"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(VideoTrackListArg), "onchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(VideoTrackListArg), "onaddtrack"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(VideoTrackListArg), "onremovetrack"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(VideoTrackRet), HANDLE_ARG(VideoTrackListArg)));

    // VideoTrack
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackArg), "language"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VideoTrackArg), "selected"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(VideoTrackArg), "selected"));

    // TextTrackList
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackListArg), "onchange"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackListArg), "onaddtrack"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackListArg), "onremovetrack"));
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(TextTrackRet), HANDLE_ARG(TextTrackListArg)));

    // TextTrackCueList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(TextTrackCueRet), HANDLE_ARG(TextTrackCueListArg)));

    // TextTrackCue
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackRet), HANDLE_ARG(TextTrackCueArg), "track"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackCueArg), "id"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(TextTrackCueArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackCueArg), "startTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockArg), HANDLE_ARG(TextTrackCueArg), "startTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackCueArg), "endTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockArg), HANDLE_ARG(TextTrackCueArg), "endTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackCueArg), "pauseOnExit"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(TextTrackCueArg), "pauseOnExit"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackCueArg), "onenter"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackCueArg), "onexit"));

    // TextTrack
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackArg), "label"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackArg), "language"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextTrackArg), "mode"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TextTrackModeArg), HANDLE_ARG(TextTrackArg), "mode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackCueListRet), HANDLE_ARG(TextTrackArg), "cues"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackCueListRet), HANDLE_ARG(TextTrackArg), "activeCues"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(TextTrackArg), "oncuechange"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(VTTRegionListRet), HANDLE_ARG(TextTrackArg), "regions"));

    // VTTRegionList
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionListArg), "length"));

    // VTTRegion
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "id"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(VTTRegionArg), "id"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(VTTRegionArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(VTTRegionArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "regionAnchorX"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(VTTRegionArg), "regionAnchorX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "regionAnchorY"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(VTTRegionArg), "regionAnchorY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "viewportAnchorX"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(VTTRegionArg), "viewportAnchorX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "viewportAnchorY"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(VTTRegionArg), "viewportAnchorY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTRegionArg), "scroll"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VTTRegionScrollArg), HANDLE_ARG(VTTRegionArg), "scroll"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(TextTrackRet), HANDLE_ARG(VTTRegionArg), "track"));

    // VTTCue
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "regionId"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(VTTCueArg), "regionId"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "vertical"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VTTCueVerticalArg), HANDLE_ARG(VTTCueArg), "vertical"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "snapToLines"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(VTTCueArg), "snapToLines"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "line"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VTTCueLineArg), HANDLE_ARG(VTTCueArg), "line"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "position"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VTTCuePositionArg), HANDLE_ARG(VTTCueArg), "position"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "size"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(VTTCueArg), "size"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(VTTCueAlignArg), HANDLE_ARG(VTTCueArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VTTCueArg), "text"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(VTTCueArg), "text"));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Web Animations
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Animations
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(AnimationRet), HANDLE_ARG(AnimationsArg)));
    add_api(std::make_shared<ArrayStoreIndexTemplate>(HANDLE_ARG(AnimationArg), HANDLE_ARG(AnimationsArg)));

    // Animation
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(AnimationEffectReadOnlyRet), HANDLE_ARG(AnimationArg), "effect"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AnimationEffectReadOnlyArg), HANDLE_ARG(AnimationArg), "effect"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(AnimationTimelineRet), HANDLE_ARG(AnimationArg), "timeline"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "startTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationArg), "startTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "currentTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationArg), "currentTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "playbackRate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(AnimationArg), "playbackRate"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "playState"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(PlayStateArg), HANDLE_ARG(AnimationArg), "playState"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AnimationArg), "onfinish"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(AnimationArg), "oncancel"));
    // add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "finished"));
    // add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationArg), "ready"));

    // AnimationTimeline
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationTimelineArg), "currentTime"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationTimelineArg), "currentTime"));

    // AnimationEffectReadOnly
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(AnimationEffectTimingReadOnlyRet), HANDLE_ARG(AnimationEffectReadOnlyArg), "timing"));

    // AnimationEffectTimingReadOnly
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "delay"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "endDelay"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "fill"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "iterationStart"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "iterations"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "duration"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "direction"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEffectTimingReadOnlyArg), "easing"));

    // AnimationEffectTiming
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationEffectTimingArg), "delay"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationEffectTimingArg), "endDelay"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AnimationFillArg), HANDLE_ARG(AnimationEffectTimingArg), "fill"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(AnimationEffectTimingArg), "iterationStart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(AnimationEffectTimingArg), "iterations"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClockInMsArg), HANDLE_ARG(AnimationEffectTimingArg), "duration"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AnimationDirectionArg), HANDLE_ARG(AnimationEffectTimingArg), "direction"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(AnimationEasingArg), HANDLE_ARG(AnimationEffectTimingArg), "easing"));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Event
    // TODO: TouchEvent, RelatedEvent, FontFaceSetLoadEvent, TrackEvent
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // DataTransfer
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DataTransferArg), "types"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DataTransferArg), "dropEffect"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(DropEffectArg), HANDLE_ARG(DataTransferArg), "dropEffect"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DataTransferArg), "effectAllowed"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EffectAllowedArg), HANDLE_ARG(DataTransferArg), "effectAllowed"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DataTransferItemListRet), HANDLE_ARG(DataTransferArg), "items"));

    // DataTransferItemList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(DataTransferItemRet), HANDLE_ARG(DataTransferItemListArg)));

    // DataTransferItem
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DataTransferItemArg), "kind"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DataTransferItemArg), "type"));

    // ResourceProgressEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ResourceProgressEventArg), "url"));

    // TextEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TextEventArg), "data"));

    // ClipboardEvent
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DataTransferRet), HANDLE_ARG(ClipboardEventArg), "clipboardData"));

    // ProgressEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ProgressEventArg), "lengthComputable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ProgressEventArg), "loaded"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ProgressEventArg), "total"));

    // WheelEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "deltaX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "deltaY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "deltaZ"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "deltaMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "wheelDeltaX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "wheelDeltaY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(WheelEventArg), "wheelDelta"));

    // HashChangeEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HashChangeEventArg), "oldURL"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HashChangeEventArg), "newURL"));

    // MouseEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "screenX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "screenY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "clientX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "clientY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "ctrlKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "shiftKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "altKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "metaKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "button"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "buttons"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "pageX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "pageY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "offsetX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "offsetY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "movementX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "movementY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "region"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MouseEventArg), "fromElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MouseEventArg), "toElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetsRet), HANDLE_ARG(MouseEventArg), "relatedTarget"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "which"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "layerX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MouseEventArg), "layerY"));

    // FocusEvent
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(FocusEventArg), "relatedTarget"));

    // TransitionEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TransitionEventArg), "propertyName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TransitionEventArg), "elapsedTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(TransitionEventArg), "pseudoElement"));

    // AnimationPlaybackEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationPlaybackEventArg), "currentTime"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationPlaybackEventArg), "timelineTime"));

    // PopStateEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PopStateEventArg), "state"));

    // DragEvent
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DataTransferRet), HANDLE_ARG(DragEventArg), "dataTransfer"));

    // Event
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "eventPhase"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "bubbles"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "cancelable"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "defaultPrevented"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "composed"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "isTrusted"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "timeStamp"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "returnValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(EventArg), "returnValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(EventArg), "cancelBubble"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(EventArg), "cancelBubble"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(EventArg), "path"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(EventArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(EventArg), "currentTarget"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(EventArg), "srcElement"));

    // InputDeviceCapabilities
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(InputDeviceCapabilitiesArg), "firesTouchEvents"));

    // UIEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(UIEventArg), "detail"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(UIEventArg), "which"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(WindowRet), HANDLE_ARG(UIEventArg), "view"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(InputDeviceCapabilitiesRet), HANDLE_ARG(UIEventArg), "sourceCapabilities"));

    // CompositionEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CompositionEventArg), "data"));

    // InputEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(InputEventArg), "inputType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(InputEventArg), "data"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DataTransferRet), HANDLE_ARG(InputEventArg), "dataTransfer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(InputEventArg), "isComposing"));

    // PageTransitionEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PageTransitionEventArg), "persisted"));

    // StaticRanges
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(StaticRangeRet), HANDLE_ARG(StaticRangesArg)));
    add_api(std::make_shared<ArrayStoreIndexTemplate>(HANDLE_ARG(StaticRangeArg), HANDLE_ARG(StaticRangesArg)));

    // StaticRange
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StaticRangeArg), "collapsed"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(StaticRangeArg), "endContainer"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(StaticRangeArg), "endContainer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StaticRangeArg), "endOffset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(StaticRangeArg), "endOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(StaticRangeArg), "startContainer"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ElementArg), HANDLE_ARG(StaticRangeArg), "startContainer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(StaticRangeArg), "startOffset"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(StaticRangeArg), "startOffset"));

    // PointerEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "pointerId"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "pressure"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "tiltX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "tiltY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "pointerType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PointerEventArg), "isPrimary"));

    // PromiseRejectionEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PromiseRejectionEventArg), "promise"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(PromiseRejectionEventArg), "reason"));

    // MessageEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MessageEventArg), "data"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MessageEventArg), "origin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MessageEventArg), "lastEventId"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(EventTargetRet), HANDLE_ARG(MessageEventArg), "source"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MessagePortRet), HANDLE_ARG(MessageEventArg), "ports"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MessageEventArg), "suborigin"));

    // MutationEvent
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MutationEventArg), "relatedNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationEventArg), "prevValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationEventArg), "newValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationEventArg), "attrName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationEventArg), "attrChange"));

    // AnimationEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEventArg), "animationName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(AnimationEventArg), "elapsedTime"));

    // ErrorEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ErrorEventArg), "message"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ErrorEventArg), "filename"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ErrorEventArg), "lineno"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ErrorEventArg), "colno"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ErrorEventArg), "error"));

    // KeyboardEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "key"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "code"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "location"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "ctrlKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "shiftKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "altKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "metaKey"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "repeat"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "charCode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "keyCode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(KeyboardEventArg), "which"));

    // CustomEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(CustomEventArg), "detail"));

    // ApplicationCacheErrorEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ApplicationCacheErrorEventArg), "reason"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ApplicationCacheErrorEventArg), "url"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ApplicationCacheErrorEventArg), "status"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ApplicationCacheErrorEventArg), "message"));

    // SecurityPolicyViolationEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "documentURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "referrer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "blockedURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "violatedDirective"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "effectiveDirective"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "originalPolicy"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "sourceFile"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "statusCode"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "lineNumber"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SecurityPolicyViolationEventArg), "columnNumber"));

    // BeforeUnloadEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(BeforeUnloadEventArg), "returnValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(BeforeUnloadEventArg), "returnValue"));

    // MediaQueryListEvent
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaQueryListEventArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaQueryListEventArg), "matches"));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Misc
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // XPathResult
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "resultType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "numberValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "stringValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "booleanValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(XPathResultArg), "singleNodeValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "invalidIteratorState"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(XPathResultArg), "snapshotLength"));

    // ApplicationCache
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ApplicationCacheArg), "status"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onchecking"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onnoupdate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "ondownloading"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onprogress"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onupdateready"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "oncached"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(ApplicationCacheArg), "onobsolete"));

    // BarProp
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(BarPropArg), "visible"));

    // Screen
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "availWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "availHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "colorDepth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "pixelDepth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "availLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ScreenArg), "availTop"));

    // History
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HistoryArg), "state"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HistoryArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(HistoryArg), "scrollRestoration"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ScrollRestorationArg), HANDLE_ARG(HistoryArg), "scrollRestoration"));

    // VisualViewport
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "scrollLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "scrollTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "pageX"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "pageY"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "clientWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "clientHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(VisualViewportArg), "scale"));

    // MessageChannel
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MessagePortRet), HANDLE_ARG(MessageChannelArg), "port1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(MessagePortRet), HANDLE_ARG(MessageChannelArg), "port2"));

    // MessagePort
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(MessagePortArg), "onmessage"));

    // ValidityState
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "valueMissing"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "typeMismatch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "patternMismatch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "tooLong"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "tooShort"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "rangeUnderflow"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "rangeOverflow"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "stepMismatch"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "badInput"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "customError"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(ValidityStateArg), "valid"));

    // Navigator
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "vendor"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "vendorSub"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "productSub"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "maxTouchPoints"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "appCodeName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "appName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "appVersion"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "platform"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "product"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "userAgent"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "language"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "languages"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(NavigatorArg), "onLine"));

    // MediaError
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MediaErrorArg), "code"));

    // Range
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(RangeArg), "collapsed"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(RangeArg), "commonAncestorContainer"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(RangeArg), "endContainer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(RangeArg), "endOffset"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(RangeArg), "startContainer"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(RangeArg), "startOffset"));

    // MutationRecords
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(MutationRecordRet), HANDLE_ARG(MutationRecordsArg)));

    // MutationRecord
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationRecordArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationRecordArg), "oldValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationRecordArg), "attributeName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(MutationRecordArg), "attributeNamespace"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MutationRecordArg), "target"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NodeListRet), HANDLE_ARG(MutationRecordArg), "addedNodes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(NodeListRet), HANDLE_ARG(MutationRecordArg), "removedNodes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MutationRecordArg), "previousSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ElementRet), HANDLE_ARG(MutationRecordArg), "nextSibling"));

    // DOMRect
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "top"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "top"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "right"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "right"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "bottom"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "bottom"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMRectArg), "left"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(DOMRectArg), "left"));

    // DOMRectList
    add_api(std::make_shared<ArrayLoadIndexTemplate>(HANDLE_RET(DOMRectRet), HANDLE_ARG(DOMRectListArg)));

    // URL
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "href"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "href"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "origin"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "protocol"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "protocol"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "username"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "username"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "password"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "password"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "host"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "host"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "hostname"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "hostname"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "port"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "port"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "pathname"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "pathname"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "search"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "search"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(URLArg), "hash"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(URLArg), "hash"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(URLSearchParamsRet), HANDLE_ARG(URLArg), "searchParams"));

    // DOMTokenList
    // FIXME: set value
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMTokenListArg), "length"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(DOMTokenListArg), "value"));
}