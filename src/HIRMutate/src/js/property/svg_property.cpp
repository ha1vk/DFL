#include "svg_property.h"
#include "js_property.h"
#include "svg_arg.h"
#include "ret.h"
#include "arg.h"
#include "html_arg.h"
#include "html_ret.h"
#include "svg_ret.h"

void HIRMutate::JS::initialize_svg_properties()
{
    // TODO: SVGScriptElement

    // SVGElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "tabIndex"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(TabIndexArg), HANDLE_ARG(SVGElementArg), "tabIndex"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(CSSStyleDeclarationRet), HANDLE_ARG(SVGElementArg), "style"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(HTMLSlotElementRet), HANDLE_ARG(SVGElementArg), "assignedSlot"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMStringMapRet), HANDLE_ARG(SVGElementArg), "dataset"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "attributes"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "baseURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "childElementCount"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGCollectionRet), HANDLE_ARG(SVGElementArg), "children"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "clientHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "clientLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "clientTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "clientWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "computedName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "computedRole"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "isConnected"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "localName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "namespaceURI"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DocumentRet), HANDLE_ARG(SVGElementArg), "ownerDocument"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "nodeName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "nodeType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "prefix"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "scrollHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "scrollWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "tagName"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "className"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(ClassArg), HANDLE_ARG(SVGElementArg), "className"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(DOMTokenListRet), HANDLE_ARG(SVGElementArg), "classList"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(ShadowRootRet), HANDLE_ARG(SVGElementArg), "shadowRoot"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGHTMLStringRet), HANDLE_ARG(SVGElementArg), "innerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGElementArg), "innerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SVGHTMLStringArg), HANDLE_ARG(SVGElementArg), "innerHTML"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGHTMLStringRet), HANDLE_ARG(SVGElementArg), "outerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGElementArg), "outerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SVGHTMLStringArg), HANDLE_ARG(SVGElementArg), "outerHTML"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "ongotpointercapture"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onlostpointercapture"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "firstChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "firstElementChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "lastChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "lastElementChild"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "nextElementSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "nextSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "parentElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "parentNode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "previousElementSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGElementArg), "previousSibling"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGNodeListRet), HANDLE_ARG(SVGElementArg), "childNodes"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGSVGElementRet), HANDLE_ARG(SVGElementArg), "ownerSVGElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGSVGElementRet), HANDLE_ARG(SVGElementArg), "viewportElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "scrollLeft"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGElementArg), "scrollLeft"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "scrollTop"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGElementArg), "scrollTop"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "nodeValue"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGElementArg), "nodeValue"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "slot"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(SlotArg), HANDLE_ARG(SVGElementArg), "slot"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGElementArg), "textContent"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGElementArg), "textContent"));

    // SVGStyleElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGStyleElementArg), "type"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(CSSTypeArg), HANDLE_ARG(SVGStyleElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGStyleElementArg), "media"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(MediaQueryArg), HANDLE_ARG(SVGStyleElementArg), "media"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGStyleElementArg), "title"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGStyleElementArg), "title"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGStyleElementArg), "disabled"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGStyleElementArg), "disabled"));

    // SVGViewSpec
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGViewSpecArg), "viewTarget"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGTransformListRet), HANDLE_ARG(SVGViewSpecArg), "transform"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGViewSpecArg), "zoomAndPan"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(SVGViewSpecArg), "zoomAndPan"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGViewSpecArg), "preserveAspectRatioString"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGViewSpecArg), "transformString"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGViewSpecArg), "viewBoxString"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGViewSpecArg), "viewTargetString"));

    // SVGAnimatedAngle
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAngleRet), HANDLE_ARG(SVGAnimatedAngleArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAngleRet), HANDLE_ARG(SVGAnimatedAngleArg), "baseVal"));

    // SVGMarkerElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedAngleRet), HANDLE_ARG(SVGMarkerElementArg), "orientAngle"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGMarkerElementArg), "markerUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGMarkerElementArg), "orientType"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMarkerElementArg), "markerHeight"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMarkerElementArg), "markerWidth"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMarkerElementArg), "refX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMarkerElementArg), "refY"));

    // SVGClipPathElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGClipPathElementArg), "clipPathUnits"));

    // SVGComponentTransferFunctionElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "amplitude"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "exponent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "intercept"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "offset"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg), "slope"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberListRet), HANDLE_ARG(SVGComponentTransferFunctionElementArg),
                                                   "tableValues"));

    // SVGFEBlendElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEBlendElementArg), "mode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEBlendElementArg), "in1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEBlendElementArg), "in2"));

    // SVGFEColorMatrixElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEColorMatrixElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberListRet), HANDLE_ARG(SVGFEColorMatrixElementArg), "values"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberListRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "kernelMatrix"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEColorMatrixElementArg), "in1"));

    // SVGFECompositeElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFECompositeElementArg), "operator"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFECompositeElementArg), "k1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFECompositeElementArg), "k2"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFECompositeElementArg), "k3"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFECompositeElementArg), "k4"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFECompositeElementArg), "in1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFECompositeElementArg), "in2"));

    // SVGFEConvolveMatrixElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "edgeMode"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "orderX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "orderY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "targetX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "targetY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "bias"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "divisor"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "kernelUnitLengthX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "kernelUnitLengthY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "in1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedBooleanRet), HANDLE_ARG(SVGFEConvolveMatrixElementArg), "preserveAlpha"));

    // SVGFEDisplacementMapElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEDisplacementMapElementArg), "xChannelSelector"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEDisplacementMapElementArg), "yChannelSelector"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDisplacementMapElementArg), "scale"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEDisplacementMapElementArg), "in1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEDisplacementMapElementArg), "in2"));

    // SVGFEMorphologyElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFEMorphologyElementArg), "operator"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEMorphologyElementArg), "radiusX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEMorphologyElementArg), "radiusY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEMorphologyElementArg), "in1"));

    // SVGFETurbulenceElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFETurbulenceElementArg), "stitchTiles"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFETurbulenceElementArg), "type"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFETurbulenceElementArg), "numOctaves"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFETurbulenceElementArg), "baseFrequencyX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFETurbulenceElementArg), "baseFrequencyY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFETurbulenceElementArg), "seed"));

    // SVGFilterElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFilterElementArg), "filterUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGFilterElementArg), "primitiveUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFilterElementArg), "filterResX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedIntegerRet), HANDLE_ARG(SVGFilterElementArg), "filterResY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterElementArg), "y"));

    // SVGGradientElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGGradientElementArg), "gradientUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGGradientElementArg), "spreadMethod"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedTransformListRet), HANDLE_ARG(SVGGradientElementArg), "gradientTransform"));

    // SVGMaskElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGMaskElementArg), "maskContentUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGMaskElementArg), "maskUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMaskElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMaskElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMaskElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGMaskElementArg), "y"));

    // SVGPatternElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGPatternElementArg), "patternContentUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGPatternElementArg), "patternUnits"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGPatternElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGPatternElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGPatternElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGPatternElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedTransformListRet), HANDLE_ARG(SVGPatternElementArg), "patternTransform"));

    // SVGTextContentElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGTextContentElementArg), "lengthAdjust"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGTextContentElementArg), "textLength"));

    // SVGTextPathElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGTextPathElementArg), "method"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedEnumerationRet), HANDLE_ARG(SVGTextPathElementArg), "spacing"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGTextPathElementArg), "startOffset"));

    // SVGCircleElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGCircleElementArg), "cx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGCircleElementArg), "cy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGCircleElementArg), "r"));

    // SVGCursorElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGCursorElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGCursorElementArg), "y"));

    // SVGEllipseElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGEllipseElementArg), "cx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGEllipseElementArg), "cy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGEllipseElementArg), "rx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGEllipseElementArg), "ry"));

    // SVGFilterPrimitiveStandardAttributes
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterPrimitiveStandardAttributesArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterPrimitiveStandardAttributesArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterPrimitiveStandardAttributesArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGFilterPrimitiveStandardAttributesArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFilterPrimitiveStandardAttributesArg), "result"));

    // SVGForeignObjectElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGForeignObjectElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGForeignObjectElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGForeignObjectElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGForeignObjectElementArg), "y"));

    // SVGImageElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGImageElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGImageElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGImageElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGImageElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedPreserveAspectRatioRet), HANDLE_ARG(SVGImageElementArg), "preserveAspectRatio"));

    // SVGLineElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLineElementArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLineElementArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLineElementArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLineElementArg), "y2"));

    // SVGLinearGradientElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLinearGradientElementArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLinearGradientElementArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLinearGradientElementArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGLinearGradientElementArg), "y2"));

    // SVGRadialGradientElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "cx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "cy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "fr"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "fx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "fy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRadialGradientElementArg), "r"));

    // SVGRectElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "rx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "ry"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGRectElementArg), "y"));

    // SVGSVGElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGSVGElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGSVGElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGSVGElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGSVGElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPointRet), HANDLE_ARG(SVGSVGElementArg), "currentTranslate"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGSVGElementArg), "viewport"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGSVGElementArg), "useCurrentView"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGViewSpecRet), HANDLE_ARG(SVGSVGElementArg), "currentView"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGSVGElementArg), "currentScale"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGSVGElementArg), "currentScale"));

    // SVGUseElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGUseElementArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGUseElementArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGUseElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthRet), HANDLE_ARG(SVGUseElementArg), "y"));

    // SVGTextPositioningElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthListRet), HANDLE_ARG(SVGTextPositioningElementArg), "dx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthListRet), HANDLE_ARG(SVGTextPositioningElementArg), "dy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthListRet), HANDLE_ARG(SVGTextPositioningElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedLengthListRet), HANDLE_ARG(SVGTextPositioningElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberListRet), HANDLE_ARG(SVGTextPositioningElementArg), "rotate"));

    // SVGFEDiffuseLightingElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDiffuseLightingElementArg), "diffuseConstant"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDiffuseLightingElementArg), "kernelUnitLengthX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDiffuseLightingElementArg), "kernelUnitLengthY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDiffuseLightingElementArg), "surfaceScale"));

    // SVGFEDistantLightElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDistantLightElementArg), "azimuth"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDistantLightElementArg), "elevation"));

    // SVGFEDropShadowElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDropShadowElementArg), "dx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDropShadowElementArg), "dy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDropShadowElementArg), "stdDeviationX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEDropShadowElementArg), "stdDeviationY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEDropShadowElementArg), "in1"));

    // SVGFEGaussianBlurElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEGaussianBlurElementArg), "stdDeviationX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEGaussianBlurElementArg), "stdDeviationY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEGaussianBlurElementArg), "in1"));

    // SVGFEOffsetElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEOffsetElementArg), "dx"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEOffsetElementArg), "dy"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEOffsetElementArg), "in1"));

    // SVGFEPointLightElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEPointLightElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEPointLightElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFEPointLightElementArg), "z"));

    // SVGFESpecularLightingElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "kernelUnitLengthX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "kernelUnitLengthY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "specularConstant"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "specularExponent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "surfaceScale"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFESpecularLightingElementArg), "in1"));

    // SVGFESpotLightElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "limitingConeAngle"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "pointsAtX"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "pointsAtY"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "pointsAtZ"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "specularExponent"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGFESpotLightElementArg), "z"));

    // SVGPathElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGPathElementArg), "pathLength"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPathSegListRet), HANDLE_ARG(SVGPathElementArg), "animatedNormalizedPathSegList"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPathSegListRet), HANDLE_ARG(SVGPathElementArg), "animatedPathSegList"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPathSegListRet), HANDLE_ARG(SVGPathElementArg), "pathSegList"));

    // SVGStopElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedNumberRet), HANDLE_ARG(SVGStopElementArg), "offset"));

    // SVGFEImageElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedPreserveAspectRatioRet), HANDLE_ARG(SVGFEImageElementArg), "preserveAspectRatio"));

    // SVGFitToViewBox
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedPreserveAspectRatioRet), HANDLE_ARG(SVGFitToViewBoxArg), "preserveAspectRatio"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedRectRet), HANDLE_ARG(SVGFitToViewBoxArg), "viewBox"));

    // SVGAElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGAElementArg), "target"));

    // SVGFEComponentTransferElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEComponentTransferElementArg), "in1"));

    // SVGFEDiffuseLightingElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEDiffuseLightingElementArg), "in1"));

    // SVGFEMergeNodeElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFEMergeNodeElementArg), "in1"));

    // SVGFETileElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedStringRet), HANDLE_ARG(SVGFETileElementArg), "in1"));

    // SVGAnimationElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGElementRet), HANDLE_ARG(SVGAnimationElementArg), "targetElement"));

    // SVGAnimatedLength
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGLengthRet), HANDLE_ARG(SVGAnimatedLengthArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGLengthRet), HANDLE_ARG(SVGAnimatedLengthArg), "baseVal"));

    // SVGAnimatedLengthList
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGLengthListRet), HANDLE_ARG(SVGAnimatedLengthListArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGLengthListRet), HANDLE_ARG(SVGAnimatedLengthListArg), "baseVal"));

    // SVGTransform
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGMatrixRet), HANDLE_ARG(SVGTransformArg), "matrix"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGTransformArg), "angle"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGTransformArg), "type"));

    // SVGAnimatedNumberList
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGNumberListRet), HANDLE_ARG(SVGAnimatedNumberListArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGNumberListRet), HANDLE_ARG(SVGAnimatedNumberListArg), "baseVal"));

    // SVGAnimatedNumber
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedNumberArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedNumberArg), "baseVal"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGAnimatedNumberArg), "baseVal"));

    // SVGPolygonElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPointListRet), HANDLE_ARG(SVGPolygonElementArg), "animatedPoints"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPointListRet), HANDLE_ARG(SVGPolygonElementArg), "points"));

    // SVGPolylineElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPointListRet), HANDLE_ARG(SVGPolylineElementArg), "animatedPoints"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPointListRet), HANDLE_ARG(SVGPolylineElementArg), "points"));

    // SVGAnimatedPreserveAspectRatio
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPreserveAspectRatioRet), HANDLE_ARG(SVGAnimatedPreserveAspectRatioArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGPreserveAspectRatioRet), HANDLE_ARG(SVGAnimatedPreserveAspectRatioArg), "baseVal"));

    // SVGAnimatedRect
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGAnimatedRectArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGRectRet), HANDLE_ARG(SVGAnimatedRectArg), "baseVal"));

    // SVGGraphicsElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGAnimatedTransformListRet), HANDLE_ARG(SVGGraphicsElementArg), "transform"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGSVGElementRet), HANDLE_ARG(SVGGraphicsElementArg), "farthestViewportElement"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGSVGElementRet), HANDLE_ARG(SVGGraphicsElementArg), "nearestViewportElement"));

    // SVGViewElement
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGStringListRet), HANDLE_ARG(SVGViewElementArg), "viewTarget"));

    // SVGAnimatedTransformList
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGTransformListRet), HANDLE_ARG(SVGAnimatedTransformListArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(HANDLE_RET(SVGTransformListRet), HANDLE_ARG(SVGAnimatedTransformListArg), "baseVal"));

    // SVGAnimatedBoolean
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedBooleanArg), "baseVal"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGAnimatedBooleanArg), "baseVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedBooleanArg), "animVal"));

    // SVGAnimatedEnumeration
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedEnumerationArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedEnumerationArg), "baseVal"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EnumArg), HANDLE_ARG(SVGAnimatedEnumerationArg), "baseVal"));

    // SVGAngle
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAngleArg), "unitType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAngleArg), "valueAsString"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatStringArg), HANDLE_ARG(SVGAngleArg), "valueAsString"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAngleArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGAngleArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAngleArg), "valueInSpecifiedUnits"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGAngleArg), "valueInSpecifiedUnits"));

    // SVGPathSeg*
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "largeArcFlag"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGPathSegArcAbsArg), "largeArcFlag"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "sweepFlag"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGPathSegArcAbsArg), "sweepFlag"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "largeArcFlag"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGPathSegArcRelArg), "largeArcFlag"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "sweepFlag"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(BooleanArg), HANDLE_ARG(SVGPathSegArcRelArg), "sweepFlag"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "angle"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcAbsArg), "angle"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "r1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcAbsArg), "r1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "r2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcAbsArg), "r2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "angle"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcRelArg), "angle"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "r1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcRelArg), "r1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "r2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcRelArg), "r2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegArcRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegArcRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicAbsArg), "y2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicRelArg), "y2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "x2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "y2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothAbsArg), "y2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "x2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "x2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "y2"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoCubicSmoothRelArg), "y2"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "x1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "y1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticAbsArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "x1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "x1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "y1"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticRelArg), "y1"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegCurvetoQuadraticSmoothRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoHorizontalAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoHorizontalRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoRelArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoVerticalAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoVerticalAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegLinetoVerticalRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegLinetoVerticalRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegMovetoAbsArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegMovetoAbsArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegMovetoAbsArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegMovetoAbsArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegMovetoRelArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegMovetoRelArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPathSegMovetoRelArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPathSegMovetoRelArg), "y"));

    // SVGGlyphRefElement
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "dx"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGGlyphRefElementArg), "dx"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "dy"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGGlyphRefElementArg), "dy"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGGlyphRefElementArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGGlyphRefElementArg), "y"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "format"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGGlyphRefElementArg), "format"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGGlyphRefElementArg), "glyphRef"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGGlyphRefElementArg), "glyphRef"));

    // SVGLength
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGLengthArg), "unitType"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGLengthArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGLengthArg), "value"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGLengthArg), "valueAsString"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatStringArg), HANDLE_ARG(SVGLengthArg), "valueAsString"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGLengthArg), "valueInSpecifiedUnits"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGLengthArg), "valueInSpecifiedUnits"));

    // SVGMatrix
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "a"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "a"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "b"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "b"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "c"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "c"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "d"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "d"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "e"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "e"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGMatrixArg), "f"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGMatrixArg), "f"));

    // SVGPoint
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPointArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPointArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPointArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGPointArg), "y"));

    // SVGRect
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGRectArg), "height"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGRectArg), "height"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGRectArg), "width"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGRectArg), "width"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGRectArg), "x"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGRectArg), "x"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGRectArg), "y"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGRectArg), "y"));

    // SVGAnimatedInteger
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedIntegerArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedIntegerArg), "baseVal"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(SVGAnimatedIntegerArg), "baseVal"));

    // SVGPreserveAspectRatio
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPreserveAspectRatioArg), "align"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(SVGPreserveAspectRatioArg), "align"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGPreserveAspectRatioArg), "meetOrSlice"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(IntegerArg), HANDLE_ARG(SVGPreserveAspectRatioArg), "meetOrSlice"));

    // SVGAnimatedString
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedStringArg), "animVal"));
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGAnimatedStringArg), "baseVal"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(StringArg), HANDLE_ARG(SVGAnimatedStringArg), "baseVal"));

    // SVGNumber
    add_api(std::make_shared<LoadPropertyTemplate>(nullptr, HANDLE_ARG(SVGNumberArg), "value"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(FloatArg), HANDLE_ARG(SVGNumberArg), "value"));

    // Event
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGAnimationElementArg), "onbegin"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGAnimationElementArg), "onend"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGAnimationElementArg), "onrepeat"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGSVGElementArg), "onerror"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGSVGElementArg), "onresize"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGSVGElementArg), "onscroll"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onsearch"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onwheel"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onselectstart"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onactivate"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onfocusin"));
    add_api(std::make_shared<StorePropertyTemplate>(HANDLE_ARG(EventHandlerArg), HANDLE_ARG(SVGElementArg), "onfocusout"));
}