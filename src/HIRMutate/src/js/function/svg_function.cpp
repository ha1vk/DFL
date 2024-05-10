#include "svg_function.h"
#include "js_function.h"
#include "random.h"
#include "html_arg.h"
#include "svg_arg.h"
#include "html_ret.h"
#include "svg_ret.h"
#include "html_function.h"
#include "serialize_variables.h"

HIRMutate::JS::GetItem::GetItem(Ret *ret, Arg *this_obj, Arg *selector) : API(ret, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::GetItem::~GetItem()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::GetItem::generate(JSContext *context)
{
    this_obj->generate(context);
    if (ret != nullptr)
        ret->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::GetItem::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::GetItem::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::GetItem::operator string()
{
    string ans = "";
    if (ret != nullptr)
    {
        ans.append("var ");
        ans.append(ret->operator string());
        ans.append(" = ");
    }
    ans.append(this_obj->operator string());
    ans.append(".getItem(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj->operator string());
    ans.append(".numberOfItems)");
    return ans;
}
void HIRMutate::JS::GetItem::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("GetItem");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::GetItem::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::GetItemTemplate::GetItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)()) : APITemplate(ret_class, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::GetItemTemplate::instantiate()
{
    Ret *ret = ret_class();
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new GetItem(ret, this_obj, selector);
}

bool HIRMutate::JS::GetItemTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::RemoveItem::RemoveItem(Arg *this_obj, Arg *selector) : API(nullptr, this_obj)
{
    this->selector = selector;
}
HIRMutate::JS::RemoveItem::~RemoveItem()
{
    if (selector)
        delete selector;
}
void HIRMutate::JS::RemoveItem::generate(JSContext *context)
{
    this_obj->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::RemoveItem::mutate(JSContext *context)
{
    if (Random::gbool())
        this_obj->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::RemoveItem::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::RemoveItem::operator string()
{
    string ans = this_obj->operator string();
    ans.append(".removeItem(");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj->operator string());
    ans.append(".numberOfItems)");
    return ans;
}
void HIRMutate::JS::RemoveItem::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RemoveItem");
    API::serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::RemoveItem::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::RemoveItemTemplate::RemoveItemTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::RemoveItemTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *selector = new RandomSelectorArg();
    return new RemoveItem(this_obj, selector);
}

bool HIRMutate::JS::RemoveItemTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::InsertItemBefore::InsertItemBefore(Arg *this_obj, Arg *arg, Arg *selector) : API(nullptr, this_obj)
{
    this->arg = arg;
    this->selector = selector;
}
HIRMutate::JS::InsertItemBefore::~InsertItemBefore()
{
    if (arg)
        delete arg;
    if (selector)
        delete selector;
}
void HIRMutate::JS::InsertItemBefore::generate(JSContext *context)
{
    this_obj->generate(context);
    arg->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::InsertItemBefore::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        arg->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::InsertItemBefore::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    arg->merge_fix(merge_map);
}

HIRMutate::JS::InsertItemBefore::operator string()
{
    string ans = this_obj->operator string();
    ans.append(".insertItemBefore(");
    ans.append(arg->operator string());
    ans.append(", ");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj->operator string());
    ans.append(".numberOfItems)");
    return ans;
}
void HIRMutate::JS::InsertItemBefore::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("InsertItemBefore");
    API::serialize(stream, context);
    arg->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::InsertItemBefore::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    arg = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::InsertItemBeforeTemplate::InsertItemBeforeTemplate(Arg *(*this_class)(), Arg *(*arg_class)()) : APITemplate(nullptr, this_class)
{
    this->arg_class = arg_class;
}

HIRMutate::JS::API *HIRMutate::JS::InsertItemBeforeTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *arg = arg_class();
    Arg *selector = new RandomSelectorArg();
    return new InsertItemBefore(this_obj, arg, selector);
}

bool HIRMutate::JS::InsertItemBeforeTemplate::satiable(JSContext *context)
{
    Arg *arg = arg_class();
    bool ans = is_satiable_arg(arg, context);
    delete arg;
    return ans;
}

HIRMutate::JS::ReplaceItem::ReplaceItem(Arg *this_obj, Arg *arg, Arg *selector) : API(nullptr, this_obj)
{
    this->arg = arg;
    this->selector = selector;
}
HIRMutate::JS::ReplaceItem::~ReplaceItem()
{
    if (arg)
        delete arg;
    if (selector)
        delete selector;
}
void HIRMutate::JS::ReplaceItem::generate(JSContext *context)
{
    this_obj->generate(context);
    arg->generate(context);
    selector->generate(context);
}

bool HIRMutate::JS::ReplaceItem::mutate(JSContext *context)
{
    int c = Random::selector(3);
    if (c == 0)
        this_obj->mutate(context);
    else if (c == 1)
        arg->mutate(context);
    else
        selector->mutate(context);
}

void HIRMutate::JS::ReplaceItem::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
    arg->merge_fix(merge_map);
}

HIRMutate::JS::ReplaceItem::operator string()
{
    string ans = this_obj->operator string();
    ans.append(".replaceItem(");
    ans.append(arg->operator string());
    ans.append(", ");
    ans.append(selector->operator string());
    ans.append(" % ");
    ans.append(this_obj->operator string());
    ans.append(".numberOfItems)");
    return ans;
}
void HIRMutate::JS::ReplaceItem::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ReplaceItem");
    API::serialize(stream, context);
    arg->serialize(stream, context);
    selector->serialize(stream, context);
}
void HIRMutate::JS::ReplaceItem::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    arg = arg_classes[stream->read_string()](stream, global_document, function);
    selector = arg_classes[stream->read_string()](stream, global_document, function);
}
HIRMutate::JS::ReplaceItemTemplate::ReplaceItemTemplate(Arg *(*this_class)(), Arg *(*arg_class)()) : APITemplate(nullptr, this_class)
{
    this->arg_class = arg_class;
}

HIRMutate::JS::API *HIRMutate::JS::ReplaceItemTemplate::instantiate()
{
    Arg *this_obj = this_class();
    Arg *arg = arg_class();
    Arg *selector = new RandomSelectorArg();
    return new ReplaceItem(this_obj, arg, selector);
}

bool HIRMutate::JS::ReplaceItemTemplate::satiable(JSContext *context)
{
    Arg *arg = arg_class();
    bool ans = is_satiable_arg(arg, context);
    delete arg;
    return ans;
}
namespace HIRMutate::JS
{
    map<string, Ret *(*)()> svg_element_rets;
}
void HIRMutate::JS::initSVGSym()
{
    SVG_ELEMENT_RETS("a", SVGAElementRet)
    SVG_ELEMENT_RETS("altGlyphDef", SVGAltGlyphDefElementRet);
    SVG_ELEMENT_RETS("altGlyph", SVGAltGlyphElementRet)
    SVG_ELEMENT_RETS("altGlyphItem", SVGAltGlyphItemElementRet)
    SVG_ELEMENT_RETS("animate", SVGAnimateElementRet)
    SVG_ELEMENT_RETS("animateMotion", SVGAnimateMotionElementRet)
    SVG_ELEMENT_RETS("animateTransform", SVGAnimateTransformElementRet)
    SVG_ELEMENT_RETS("circle", SVGCircleElementRet)
    SVG_ELEMENT_RETS("clipPath", SVGClipPathElementRet)
    SVG_ELEMENT_RETS("cursor", SVGCursorElementRet)
    SVG_ELEMENT_RETS("defs", SVGDefsElementRet)
    SVG_ELEMENT_RETS("desc", SVGDescElementRet)
    SVG_ELEMENT_RETS("discard", SVGDiscardElementRet)
    SVG_ELEMENT_RETS("ellipse", SVGEllipseElementRet)
    SVG_ELEMENT_RETS("feBlend", SVGFEBlendElementRet)
    SVG_ELEMENT_RETS("feColorMatrix", SVGFEColorMatrixElementRet)
    SVG_ELEMENT_RETS("feComponentTransfer", SVGFEComponentTransferElementRet)
    SVG_ELEMENT_RETS("feComposite", SVGFECompositeElementRet)
    SVG_ELEMENT_RETS("feConvolveMatrix", SVGFEConvolveMatrixElementRet)
    SVG_ELEMENT_RETS("feDiffuseLighting", SVGFEDiffuseLightingElementRet)
    SVG_ELEMENT_RETS("feDisplacementMap", SVGFEDisplacementMapElementRet)
    SVG_ELEMENT_RETS("feDistantLight", SVGFEDistantLightElementRet)
    SVG_ELEMENT_RETS("feDropShadow", SVGFEDropShadowElementRet)
    SVG_ELEMENT_RETS("feFlood", SVGFEFloodElementRet)
    SVG_ELEMENT_RETS("feFuncA", SVGFEFuncAElementRet)
    SVG_ELEMENT_RETS("feFuncB", SVGFEFuncBElementRet)
    SVG_ELEMENT_RETS("feFuncG", SVGFEFuncGElementRet)
    SVG_ELEMENT_RETS("feFuncR", SVGFEFuncRElementRet)
    SVG_ELEMENT_RETS("feGaussianBlur", SVGFEGaussianBlurElementRet)
    SVG_ELEMENT_RETS("feImage", SVGFEImageElementRet)
    SVG_ELEMENT_RETS("feMerge", SVGFEMergeElementRet)
    SVG_ELEMENT_RETS("feMergeNode", SVGFEMergeNodeElementRet)
    SVG_ELEMENT_RETS("feMorphology", SVGFEMorphologyElementRet)
    SVG_ELEMENT_RETS("feOffset", SVGFEOffsetElementRet)
    SVG_ELEMENT_RETS("fePointLight", SVGFEPointLightElementRet)
    SVG_ELEMENT_RETS("feSpecularLighting", SVGFESpecularLightingElementRet)
    SVG_ELEMENT_RETS("feSpotLight", SVGFESpotLightElementRet)
    SVG_ELEMENT_RETS("feTile", SVGFETileElementRet)
    SVG_ELEMENT_RETS("feTurbulence", SVGFETurbulenceElementRet)
    SVG_ELEMENT_RETS("filter", SVGFilterElementRet)
    SVG_ELEMENT_RETS("font", SVGFontElementRet)
    SVG_ELEMENT_RETS("font-face", SVGFontFaceElementRet)
    SVG_ELEMENT_RETS("font-face-format", SVGFontFaceFormatElementRet)
    SVG_ELEMENT_RETS("font-face-name", SVGFontFaceNameElementRet)
    SVG_ELEMENT_RETS("font-face-src", SVGFontFaceSrcElementRet)
    SVG_ELEMENT_RETS("font-face-uri", SVGFontFaceUriElementRet)
    SVG_ELEMENT_RETS("foreignObject", SVGForeignObjectElementRet)
    SVG_ELEMENT_RETS("g", SVGGElementRet)
    SVG_ELEMENT_RETS("glyph", SVGGlyphElementRet)
    SVG_ELEMENT_RETS("glyphRef", SVGGlyphRefElementRet)
    SVG_ELEMENT_RETS("hkern", SVGHKernElementRet)
    SVG_ELEMENT_RETS("image", SVGImageElementRet)
    SVG_ELEMENT_RETS("line", SVGLineElementRet)
    SVG_ELEMENT_RETS("linearGradient", SVGLinearGradientElementRet)
    SVG_ELEMENT_RETS("mpath", SVGMPathElementRet)
    SVG_ELEMENT_RETS("marker", SVGMarkerElementRet)
    SVG_ELEMENT_RETS("mask", SVGMaskElementRet)
    SVG_ELEMENT_RETS("metadata", SVGMetadataElementRet)
    SVG_ELEMENT_RETS("missing-glyph", SVGMissingGlyphElementRet)
    SVG_ELEMENT_RETS("path", SVGPathElementRet)
    SVG_ELEMENT_RETS("pattern", SVGPatternElementRet)
    SVG_ELEMENT_RETS("polygon", SVGPolygonElementRet)
    SVG_ELEMENT_RETS("polyline", SVGPolylineElementRet)
    SVG_ELEMENT_RETS("radialGradient", SVGRadialGradientElementRet)
    SVG_ELEMENT_RETS("rect", SVGRectElementRet)
    SVG_ELEMENT_RETS("svg", SVGSVGElementRet)
    SVG_ELEMENT_RETS("set", SVGSetElementRet)
    SVG_ELEMENT_RETS("stop", SVGStopElementRet)
    SVG_ELEMENT_RETS("style", SVGStyleElementRet)
    SVG_ELEMENT_RETS("switch", SVGSwitchElementRet)
    SVG_ELEMENT_RETS("symbol", SVGSymbolElementRet)
    SVG_ELEMENT_RETS("tref", SVGTRefElementRet)
    SVG_ELEMENT_RETS("tspan", SVGTSpanElementRet)
    SVG_ELEMENT_RETS("text", SVGTextElementRet)
    SVG_ELEMENT_RETS("textPath", SVGTextPathElementRet)
    SVG_ELEMENT_RETS("title", SVGTitleElementRet)
    SVG_ELEMENT_RETS("use", SVGUseElementRet)
    SVG_ELEMENT_RETS("vkern", SVGVKernElementRet)
    SVG_ELEMENT_RETS("view", SVGViewElementRet)
}

HIRMutate::JS::CreateElementNS::CreateElementNS(Arg *this_obj) : API(nullptr, this_obj)
{
}

void HIRMutate::JS::CreateElementNS::generate(JSContext *context)
{
    this_obj->generate(context);
    tag = CHOICE_OBJ(DOC::svg_tags);
    ret = (svg_element_rets[tag])();
    ret->generate(context);
}

bool HIRMutate::JS::CreateElementNS::mutate(JSContext *context)
{
    return false;
}

void HIRMutate::JS::CreateElementNS::merge_fix(map<Object *, Object *> &merge_map)
{
    this_obj->merge_fix(merge_map);
}

HIRMutate::JS::CreateElementNS::operator string()
{
    string ans = "var ";
    ans.append(ret->operator string());
    ans.append(" = ");
    ans.append(this_obj->operator string());
    ans.append(".createElementNS(\"http://www.w3.org/2000/svg\", \"");
    ans.append(tag);
    ans.append("\")");
    return ans;
}
void HIRMutate::JS::CreateElementNS::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CreateElementNS");
    API::serialize(stream, context);
    stream->write_string(tag);
}
void HIRMutate::JS::CreateElementNS::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    API::unserialize(stream, global_document, function);
    tag = stream->read_string();
}
HIRMutate::JS::CreateElementNSTemplate::CreateElementNSTemplate(Arg *(*this_class)()) : APITemplate(nullptr, this_class)
{
}

HIRMutate::JS::API *HIRMutate::JS::CreateElementNSTemplate::instantiate()
{
    return new CreateElementNS(this_class());
}

bool HIRMutate::JS::CreateElementNSTemplate::satiable(JSContext *context)
{
    return true;
}

HIRMutate::JS::FunctionTemplate::ptr instanceFunctionTemplate(HIRMutate::JS::Ret *(*ret_class)(), HIRMutate::JS::Arg *(*this_class)(), const string &method);
HIRMutate::JS::FunctionTemplate::ptr instanceFunctionTemplate(HIRMutate::JS::Ret *(*ret_class)(), HIRMutate::JS::Arg *(*this_class)(), const string &method, std::initializer_list<HIRMutate::JS::Arg *(*)()> args);

void HIRMutate::JS::initialize_svg_functions()
{
    //SVGAngle
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAngleArg), "convertToSpecifiedUnits", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAngleArg), "newValueSpecifiedUnits", {HANDLE_ARG(IntegerArg), HANDLE_ARG(FloatArg)}));

    //SVGAnimationElementArg
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "beginElement"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "beginElementAt", {HANDLE_ARG(ClockArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "endElement"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "endElementAt", {HANDLE_ARG(ClockArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "getCurrentTime"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "getSimpleDuration"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGAnimationElementArg), "getStartTime"));

    //SVGElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "after", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "after", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "append", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "append", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGCollectionRet), HANDLE_ARG(SVGElementArg), "getElementsByTagName", {HANDLE_ARG(SVGTagArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGCollectionRet), HANDLE_ARG(SVGElementArg), "getElementsByTagNameNS",
                                     {HANDLE_ARG(ConstStringArgSvg), HANDLE_ARG(SVGTagArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGCollectionRet), HANDLE_ARG(SVGElementArg), "getElementsByClassName", {HANDLE_ARG(ClassArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "querySelector", {HANDLE_ARG(SVGQuerySelectorArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGNodeListRet), HANDLE_ARG(SVGElementArg), "querySelectorAll", {HANDLE_ARG(SVGQuerySelectorArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "closest", {HANDLE_ARG(SVGQuerySelectorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "matches", {HANDLE_ARG(SVGQuerySelectorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "webkitMatchesSelector", {HANDLE_ARG(SVGQuerySelectorArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "appendChild", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(ShadowRootRet), HANDLE_ARG(SVGElementArg), "attachShadow", {HANDLE_ARG(ShadowRootInitArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "before", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "before", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "blur"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "compareDocumentPosition", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "contains", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "focus"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "hasAttributes"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "hasChildNodes"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "insertAdjacentElement", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "insertAdjacentText", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "insertAdjacentHTML", {HANDLE_ARG(InsertPositionArg), HANDLE_ARG(StringArg)}));
    add_api(std::make_shared<InsertBeforeTemplate>(HANDLE_ARG(SVGElementArg), HANDLE_ARG(SVGElementArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "insertBefore", {HANDLE_ARG(SVGElementArg), HANDLE_ARG(NullArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "isDefaultNamespace", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "isEqualNode", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "isSameNode", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "lookupNamespaceURI", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "lookupPrefix", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "normalize"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "prepend", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "prepend", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "remove"));
    add_api(std::make_shared<RemoveChildTemplate>(HANDLE_ARG(SVGElementArg)));
    add_api(std::make_shared<ReplaceChildTemplate>(HANDLE_ARG(SVGElementArg), HANDLE_ARG(SVGElementArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "replaceWith", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "replaceWith", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "requestPointerLock"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectListRet), HANDLE_ARG(SVGElementArg), "getClientRects"));
    add_api(instanceFunctionTemplate(HANDLE_RET(DOMRectRet), HANDLE_ARG(SVGElementArg), "getBoundingClientRect"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scroll"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scroll", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scroll", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollIntoView", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollIntoView", {HANDLE_ARG(ScrollIntoViewOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollIntoViewIfNeeded", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollTo"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollTo", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollTo", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollBy"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollBy", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "scrollBy", {HANDLE_ARG(ScrollToOptionsArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "setPointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "releasePointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGElementArg), "hasPointerCapture", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "cloneNode", {HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "getRootNode"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "getRootNode", {HANDLE_ARG(GetRootNodeOptionsArg)}));

    //SVGFEDropShadowElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGFEDropShadowElementArg), "setStdDeviation", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));

    //SVGFEGaussianBlurElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGFEGaussianBlurElementArg), "setStdDeviation", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));

    //SVGFEMorphologyElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGFEMorphologyElementArg), "setRadius", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));

    //SVGGeometryElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGGeometryElementArg), "isPointInFill", {HANDLE_ARG(SVGPointArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGGeometryElementArg), "isPointInStroke", {HANDLE_ARG(SVGPointArg)}));

    //SVGLength
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthArg), "convertToSpecifiedUnits", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthArg), "newValueSpecifiedUnits", {HANDLE_ARG(IntegerArg), HANDLE_ARG(FloatArg)}));

    //SVGLengthList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "appendItem", {HANDLE_ARG(SVGLengthArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "initialize", {HANDLE_ARG(SVGLengthArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "insertItemBefore", {HANDLE_ARG(SVGLengthArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGLengthListArg), HANDLE_ARG(SVGLengthArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGLengthListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGLengthListArg), "replaceItem", {HANDLE_ARG(SVGLengthArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGLengthListArg), HANDLE_ARG(SVGLengthArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGLengthRet), HANDLE_ARG(SVGLengthListArg), "getItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<GetItemTemplate>(HANDLE_RET(SVGLengthRet), HANDLE_ARG(SVGLengthListArg)));

    //SVGMarkerElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGMarkerElementArg), "setOrientToAngle", {HANDLE_ARG(SVGAngleArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGMarkerElementArg), "setOrientToAuto"));

    //SVGNumberList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "appendItem", {HANDLE_ARG(SVGNumberArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "initialize", {HANDLE_ARG(SVGNumberArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "insertItemBefore", {HANDLE_ARG(SVGNumberArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGNumberListArg), HANDLE_ARG(SVGNumberArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGNumberListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGNumberListArg), "replaceItem", {HANDLE_ARG(SVGNumberArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGNumberListArg), HANDLE_ARG(SVGNumberArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGNumberRet), HANDLE_ARG(SVGNumberListArg), "getItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<GetItemTemplate>(HANDLE_RET(SVGNumberRet), HANDLE_ARG(SVGNumberListArg)));

    //SVGPathSegList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "appendItem", {HANDLE_ARG(SVGPathSegArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "initialize", {HANDLE_ARG(SVGPathSegArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "insertItemBefore", {HANDLE_ARG(SVGPathSegArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGPathSegListArg), HANDLE_ARG(SVGPathSegArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGPathSegListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathSegListArg), "replaceItem", {HANDLE_ARG(SVGPathSegArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGPathSegListArg), HANDLE_ARG(SVGPathSegArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegRet), HANDLE_ARG(SVGPathSegListArg), "getItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<GetItemTemplate>(HANDLE_RET(SVGPathSegRet), HANDLE_ARG(SVGPathSegListArg)));

    //SVGPointList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "appendItem", {HANDLE_ARG(SVGPointArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "initialize", {HANDLE_ARG(SVGPointArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "insertItemBefore", {HANDLE_ARG(SVGPointArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGPointListArg), HANDLE_ARG(SVGPointArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGPointListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPointListArg), "replaceItem", {HANDLE_ARG(SVGPointArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGPointListArg), HANDLE_ARG(SVGPointArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGPointListArg), "getItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<GetItemTemplate>(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGPointListArg)));

    //SVGSVGElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "animationsPaused"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "checkEnclosure", {HANDLE_ARG(SVGElementArg), HANDLE_ARG(SVGRectArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "checkIntersection", {HANDLE_ARG(SVGElementArg), HANDLE_ARG(SVGRectArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "deselectAll"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "forceRedraw"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "getCurrentTime"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "pauseAnimations"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "setCurrentTime", {HANDLE_ARG(ClockArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "unsuspendRedrawAll"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "unpauseAnimations"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGSVGElementArg), "unsuspendRedraw", {HANDLE_ARG(SuspendHandleIDArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGNodeListRet), HANDLE_ARG(SVGSVGElementArg), "getEnclosureList", {HANDLE_ARG(SVGRectArg), HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGNodeListRet), HANDLE_ARG(SVGSVGElementArg), "getIntersectionList", {HANDLE_ARG(SVGRectArg), HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGNumberRet), HANDLE_ARG(SVGSVGElementArg), "createSVGNumber"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGLengthRet), HANDLE_ARG(SVGSVGElementArg), "createSVGLength"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGAngleRet), HANDLE_ARG(SVGSVGElementArg), "createSVGAngle"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGSVGElementArg), "createSVGPoint"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGSVGElementArg), "createSVGMatrix"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGSVGElementArg), "createSVGRect"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGSVGElementArg), "createSVGTransform"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGSVGElementArg), "createSVGTransformFromMatrix", {HANDLE_ARG(SVGMatrixArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SuspendHandleIDRet), HANDLE_ARG(SVGSVGElementArg), "suspendRedraw", {HANDLE_ARG(ClockInMsArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGSVGElementArg), "getElementById", {HANDLE_ARG(SVGElementIDArg)}));

    //SVGStringList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "appendItem", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "initialize", {HANDLE_ARG(StringArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "insertItemBefore", {HANDLE_ARG(StringArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGStringListArg), HANDLE_ARG(StringArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGStringListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "replaceItem", {HANDLE_ARG(StringArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGStringListArg), HANDLE_ARG(StringArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGStringListArg), "getItem", {HANDLE_ARG(IndexArg)}));

    //SVGTextContentElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "getCharNumAtPosition", {HANDLE_ARG(SVGPointArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "getComputedTextLength"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "getNumberOfChars"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "getRotationOfChar", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "getSubStringLength", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTextContentElementArg), "selectSubString", {HANDLE_ARG(IntegerArg), HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGTextContentElementArg), "getEndPositionOfChar", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGTextContentElementArg), "getStartPositionOfChar", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGTextContentElementArg), "getExtentOfChar", {HANDLE_ARG(IntegerArg)}));

    //SVGTransform
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setMatrix", {HANDLE_ARG(SVGMatrixArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setRotate", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setScale", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setSkewX", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setSkewY", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformArg), "setTranslate", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));

    //SVGTransformList
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformListArg), "appendItem", {HANDLE_ARG(SVGTransformArg)}));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformListArg), "clear"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformListArg), "insertItemBefore", {HANDLE_ARG(SVGTransformArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<InsertItemBeforeTemplate>(HANDLE_ARG(SVGTransformListArg), HANDLE_ARG(SVGTransformArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformListArg), "removeItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<RemoveItemTemplate>(HANDLE_ARG(SVGTransformListArg)));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGTransformListArg), "replaceItem", {HANDLE_ARG(SVGTransformArg), HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ReplaceItemTemplate>(HANDLE_ARG(SVGTransformListArg), HANDLE_ARG(SVGTransformArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGTransformListArg), "consolidate"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGTransformListArg), "createSVGTransformFromMatrix", {HANDLE_ARG(SVGMatrixArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGTransformListArg), "getItem", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<GetItemTemplate>(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGTransformListArg)));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGTransformRet), HANDLE_ARG(SVGTransformListArg), "initialize", {HANDLE_ARG(SVGTransformArg)}));

    //SVGNodeList
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGNodeListArg), "item", {HANDLE_ARG(IndexArg)}));
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGNodeListArg)));

    //SVGGraphicsElement
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGGraphicsElementArg), "getCTM"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGGraphicsElementArg), "getScreenCTM"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGGraphicsElementArg), "getTransformToElement"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGGraphicsElementArg), "getTransformToElement", {HANDLE_ARG(SVGElementArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGGraphicsElementArg), "getBBox"));

    //SVGMatrix
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "flipX"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "flipY"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "inverse"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "multiply", {HANDLE_ARG(SVGMatrixArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "rotate", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "rotateFromVector", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "scale", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "scaleNonUniform", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "skewX", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "skewY", {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGMatrixArg), "translate", {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));

    //SVGPathElement
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathElementArg), "getTotalLength"));
    add_api(instanceFunctionTemplate(nullptr, HANDLE_ARG(SVGPathElementArg), "getPathSegAtLength", {HANDLE_ARG(IntegerArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegArcAbsRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegArcAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegArcRelRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegArcRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(BooleanArg), HANDLE_ARG(BooleanArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegClosePathRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegClosePath"));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoCubicAbsRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegCurvetoCubicAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoCubicRelRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegCurvetoCubicRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoCubicSmoothAbsRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoCubicSmoothAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoCubicSmoothRelRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoCubicSmoothRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoQuadraticAbsRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoQuadraticAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoQuadraticRelRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoQuadraticRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoQuadraticSmoothAbsRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoQuadraticSmoothAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegCurvetoQuadraticSmoothRelRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegCurvetoQuadraticSmoothRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoAbsRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegLinetoAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoHorizontalAbsRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegLinetoHorizontalAbs",
                                     {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoHorizontalRelRet), HANDLE_ARG(SVGPathElementArg),
                                     "createSVGPathSegLinetoHorizontalRel",
                                     {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoRelRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegLinetoRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoVerticalAbsRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegLinetoVerticalAbs",
                                     {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegLinetoVerticalRelRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegLinetoVerticalRel",
                                     {HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegMovetoAbsRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegMovetoAbs",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPathSegMovetoRelRet), HANDLE_ARG(SVGPathElementArg), "createSVGPathSegMovetoRel",
                                     {HANDLE_ARG(FloatArg), HANDLE_ARG(FloatArg)}));
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGPathElementArg), "getPointAtLength", {HANDLE_ARG(IntegerArg)}));

    //SVGPoint
    add_api(instanceFunctionTemplate(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGPointArg), "matrixTransform", {HANDLE_ARG(SVGMatrixArg)}));

    //SVGCollection
    add_api(std::make_shared<ListItemTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGCollectionArg)));

    /*
    *Document
    */
    //createElementNS
    add_api(std::make_shared<CreateElementNSTemplate>(HANDLE_ARG(DocumentArg)));

    //setAttribute
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAltGlyphDefElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAltGlyphElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAltGlyphItemElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAnimateColorElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAnimateElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAnimateMotionElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGAnimateTransformElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGCircleElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGClipPathElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGColorProfileElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGCursorElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGDefsElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGDescElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGDiscardElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGEllipseElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEBlendElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEColorMatrixElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEComponentTransferElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFECompositeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEConvolveMatrixElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEDiffuseLightingElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEDisplacementMapElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEDistantLightElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEDropShadowElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEFloodElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEFuncAElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEFuncBElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEFuncGElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEFuncRElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEGaussianBlurElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEImageElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEMergeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEMergeNodeElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEMorphologyElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEOffsetElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFEPointLightElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFESpecularLightingElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFESpotLightElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFETileElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFETurbulenceElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFilterElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontFaceElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontFaceFormatElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontFaceNameElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontFaceSrcElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGFontFaceUriElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGForeignObjectElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGGElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGGlyphElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGGlyphRefElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGHKernElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGHatchElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGHatchpathElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGImageElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGLineElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGLinearGradientElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGMPathElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGMarkerElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGMaskElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGMetadataElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGMissingGlyphElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGPathElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGPatternElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGPolygonElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGPolylineElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGRadialGradientElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGRectElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGSVGElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGScriptElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGSetElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGSolidcolorElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGStopElementArg)));
    //add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGStyleElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGSwitchElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGSymbolElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGTRefElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGTSpanElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGTextElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGTextPathElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGTitleElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGUseElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGVKernElementArg)));
    add_api(std::make_shared<SetAttributeTemplate>(HANDLE_ARG(SVGViewElementArg)));
}