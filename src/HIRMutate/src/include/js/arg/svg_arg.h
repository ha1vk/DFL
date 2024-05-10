#ifndef HM_JS_SVG_ARG_H
#define HM_JS_SVG_ARG_H

#include "arg.h"
#include "DomValue.h"
#include "css_selector.h"

namespace HIRMutate
{
    namespace JS
    {
        /*
        * SVG Elements
        */
        class SVGCollectionArg : public ObjectArg
        {
        public:
            SVGCollectionArg() : ObjectArg("SVGCollection") {}
        };

        class SVGElementArg : public ObjectArg
        {
        public:
            SVGElementArg() : ObjectArg("SVGElement") {}
        };

        class SVGGraphicsElementArg : public ObjectArg
        {
        public:
            SVGGraphicsElementArg() : ObjectArg("SVGGraphicsElement") {}
        };

        class SVGTextContentElementArg : public ObjectArg
        {
        public:
            SVGTextContentElementArg() : ObjectArg("SVGTextContentElement") {}
        };

        class SVGTextPositioningElementArg : public ObjectArg
        {
        public:
            SVGTextPositioningElementArg() : ObjectArg("SVGTextPositioningElement") {}
        };

        class SVGGradientElementArg : public ObjectArg
        {
        public:
            SVGGradientElementArg() : ObjectArg("SVGGradientElement") {}
        };

        class SVGGeometryElementArg : public ObjectArg
        {
        public:
            SVGGeometryElementArg() : ObjectArg("SVGGeometryElement") {}
        };

        class SVGAnimationElementArg : public ObjectArg
        {
        public:
            SVGAnimationElementArg() : ObjectArg("SVGAnimationElement") {}
        };

        class SVGComponentTransferFunctionElementArg : public ObjectArg
        {
        public:
            SVGComponentTransferFunctionElementArg() : ObjectArg("SVGComponentTransferFunctionElement") {}
        };

        class SVGFEPointLightElementArg : public ObjectArg
        {
        public:
            SVGFEPointLightElementArg() : ObjectArg("SVGFEPointLightElement") {}
        };

        class SVGAElementArg : public ObjectArg
        {
        public:
            SVGAElementArg() : ObjectArg("SVGAElement") {}
        };

        class SVGTextPathElementArg : public ObjectArg
        {
        public:
            SVGTextPathElementArg() : ObjectArg("SVGTextPathElement") {}
        };

        class SVGLinearGradientElementArg : public ObjectArg
        {
        public:
            SVGLinearGradientElementArg() : ObjectArg("SVGLinearGradientElement") {}
        };

        class SVGTSpanElementArg : public ObjectArg
        {
        public:
            SVGTSpanElementArg() : ObjectArg("SVGTSpanElement") {}
        };

        // deprecated
        class SVGFontFaceUriElementArg : public ObjectArg
        {
        public:
            SVGFontFaceUriElementArg() : ObjectArg("SVGFontFaceUriElement") {}
        };

        class SVGTRefElementArg : public ObjectArg
        {
        public:
            SVGTRefElementArg() : ObjectArg("SVGTRefElement") {}
        };

        class SVGFETileElementArg : public ObjectArg
        {
        public:
            SVGFETileElementArg() : ObjectArg("SVGFETileElement") {}
        };

        class SVGMPathElementArg : public ObjectArg
        {
        public:
            SVGMPathElementArg() : ObjectArg("SVGMPathElement") {}
        };

        class SVGFEDisplacementMapElementArg : public ObjectArg
        {
        public:
            SVGFEDisplacementMapElementArg() : ObjectArg("SVGFEDisplacementMapElement") {}
        };

        class SVGFontFaceFormatElementArg : public ObjectArg
        {
        public:
            SVGFontFaceFormatElementArg() : ObjectArg("SVGFontFaceFormatElement") {}
        };

        class SVGStyleElementArg : public ObjectArg
        {
        public:
            SVGStyleElementArg() : ObjectArg("SVGStyleElement") {}
        };

        class SVGFEConvolveMatrixElementArg : public ObjectArg
        {
        public:
            SVGFEConvolveMatrixElementArg() : ObjectArg("SVGFEConvolveMatrixElement") {}
        };

        class SVGHatchElementArg : public ObjectArg
        {
        public:
            SVGHatchElementArg() : ObjectArg("SVGHatchElement") {}
        };

        class SVGFEDiffuseLightingElementArg : public ObjectArg
        {
        public:
            SVGFEDiffuseLightingElementArg() : ObjectArg("SVGFEDiffuseLightingElement") {}
        };

        class SVGDiscardElementArg : public ObjectArg
        {
        public:
            SVGDiscardElementArg() : ObjectArg("SVGDiscardElement") {}
        };

        class SVGHatchpathElementArg : public ObjectArg
        {
        public:
            SVGHatchpathElementArg() : ObjectArg("SVGHatchpathElement") {}
        };

        // deprecated
        class SVGGlyphElementArg : public ObjectArg
        {
        public:
            SVGGlyphElementArg() : ObjectArg("SVGGlyphElement") {}
        };

        // deprecated
        class SVGMissingGlyphElementArg : public ObjectArg
        {
        public:
            SVGMissingGlyphElementArg() : ObjectArg("SVGMissingGlyphElement") {}
        };

        // deprecated
        class SVGAltGlyphItemElementArg : public ObjectArg
        {
        public:
            SVGAltGlyphItemElementArg() : ObjectArg("SVGAltGlyphItemElement") {}
        };

        class SVGPolylineElementArg : public ObjectArg
        {
        public:
            SVGPolylineElementArg() : ObjectArg("SVGPolylineElement") {}
        };

        class SVGViewElementArg : public ObjectArg
        {
        public:
            SVGViewElementArg() : ObjectArg("SVGViewElement") {}
        };

        class SVGAnimateElementArg : public ObjectArg
        {
        public:
            SVGAnimateElementArg() : ObjectArg("SVGAnimateElement") {}
        };

        class SVGFESpecularLightingElementArg : public ObjectArg
        {
        public:
            SVGFESpecularLightingElementArg() : ObjectArg("SVGFESpecularLightingElement") {}
        };

        class SVGAltGlyphElementArg : public ObjectArg
        {
        public:
            SVGAltGlyphElementArg() : ObjectArg("SVGAltGlyphElement") {}
        };

        class SVGTextElementArg : public ObjectArg
        {
        public:
            SVGTextElementArg() : ObjectArg("SVGTextElement") {}
        };

        class SVGFEMorphologyElementArg : public ObjectArg
        {
        public:
            SVGFEMorphologyElementArg() : ObjectArg("SVGFEMorphologyElement") {}
        };

        class SVGImageElementArg : public ObjectArg
        {
        public:
            SVGImageElementArg() : ObjectArg("SVGImageElement") {}
        };

        class SVGAnimateTransformElementArg : public ObjectArg
        {
        public:
            SVGAnimateTransformElementArg() : ObjectArg("SVGAnimateTransformElement") {}
        };

        class SVGEllipseElementArg : public ObjectArg
        {
        public:
            SVGEllipseElementArg() : ObjectArg("SVGEllipseElement") {}
        };

        class SVGFontFaceSrcElementArg : public ObjectArg
        {
        public:
            SVGFontFaceSrcElementArg() : ObjectArg("SVGFontFaceSrcElement") {}
        };

        class SVGDescElementArg : public ObjectArg
        {
        public:
            SVGDescElementArg() : ObjectArg("SVGDescElement") {}
        };

        class SVGDefsElementArg : public ObjectArg
        {
        public:
            SVGDefsElementArg() : ObjectArg("SVGDefsElement") {}
        };

        // deprecated
        class SVGFontFaceElementArg : public ObjectArg
        {
        public:
            SVGFontFaceElementArg() : ObjectArg("SVGFontFaceElement") {}
        };

        class SVGGElementArg : public ObjectArg
        {
        public:
            SVGGElementArg() : ObjectArg("SVGGElement") {}
        };

        // deprecated
        class SVGAltGlyphDefElementArg : public ObjectArg
        {
        public:
            SVGAltGlyphDefElementArg() : ObjectArg("SVGAltGlyphDefElement") {}
        };

        class SVGSwitchElementArg : public ObjectArg
        {
        public:
            SVGSwitchElementArg() : ObjectArg("SVGSwitchElement") {}
        };

        class SVGGlyphRefElementArg : public ObjectArg
        {
        public:
            SVGGlyphRefElementArg() : ObjectArg("SVGGlyphRefElement") {}
        };

        class SVGCircleElementArg : public ObjectArg
        {
        public:
            SVGCircleElementArg() : ObjectArg("SVGCircleElement") {}
        };

        class SVGSymbolElementArg : public ObjectArg
        {
        public:
            SVGSymbolElementArg() : ObjectArg("SVGSymbolElement") {}
        };

        // deprecated
        class SVGVKernElementArg : public ObjectArg
        {
        public:
            SVGVKernElementArg() : ObjectArg("SVGVKernElement") {}
        };

        class SVGFilterElementArg : public ObjectArg
        {
        public:
            SVGFilterElementArg() : ObjectArg("SVGFilterElement") {}
        };

        class SVGFEColorMatrixElementArg : public ObjectArg
        {
        public:
            SVGFEColorMatrixElementArg() : ObjectArg("SVGFEColorMatrixElement") {}
        };

        class SVGHKernElementArg : public ObjectArg
        {
        public:
            SVGHKernElementArg() : ObjectArg("SVGHKernElement") {}
        };

        class SVGRadialGradientElementArg : public ObjectArg
        {
        public:
            SVGRadialGradientElementArg() : ObjectArg("SVGRadialGradientElement") {}
        };

        class SVGFETurbulenceElementArg : public ObjectArg
        {
        public:
            SVGFETurbulenceElementArg() : ObjectArg("SVGFETurbulenceElement") {}
        };

        class SVGPolygonElementArg : public ObjectArg
        {
        public:
            SVGPolygonElementArg() : ObjectArg("SVGPolygonElement") {}
        };

        class SVGScriptElementArg : public ObjectArg
        {
        public:
            SVGScriptElementArg() : ObjectArg("SVGScriptElement") {}
        };

        class SVGFEFuncRElementArg : public ObjectArg
        {
        public:
            SVGFEFuncRElementArg() : ObjectArg("SVGFEFuncRElement") {}
        };

        class SVGFEFloodElementArg : public ObjectArg
        {
        public:
            SVGFEFloodElementArg() : ObjectArg("SVGFEFloodElement") {}
        };

        class SVGSolidcolorElementArg : public ObjectArg
        {
        public:
            SVGSolidcolorElementArg() : ObjectArg("SVGSolidcolorElement") {}
        };

        class SVGTitleElementArg : public ObjectArg
        {
        public:
            SVGTitleElementArg() : ObjectArg("SVGTitleElement") {}
        };

        class SVGPatternElementArg : public ObjectArg
        {
        public:
            SVGPatternElementArg() : ObjectArg("SVGPatternElement") {}
        };

        class SVGFEMergeNodeElementArg : public ObjectArg
        {
        public:
            SVGFEMergeNodeElementArg() : ObjectArg("SVGFEMergeNodeElement") {}
        };

        class SVGUseElementArg : public ObjectArg
        {
        public:
            SVGUseElementArg() : ObjectArg("SVGUseElement") {}
        };

        class SVGFEMergeElementArg : public ObjectArg
        {
        public:
            SVGFEMergeElementArg() : ObjectArg("SVGFEMergeElement") {}
        };

        class SVGSetElementArg : public ObjectArg
        {
        public:
            SVGSetElementArg() : ObjectArg("SVGSetElement") {}
        };

        class SVGSVGElementArg : public ObjectArg
        {
        public:
            SVGSVGElementArg() : ObjectArg("SVGSVGElement") {}
        };

        class SVGCursorElementArg : public ObjectArg
        {
        public:
            SVGCursorElementArg() : ObjectArg("SVGCursorElement") {}
        };

        class SVGFEDistantLightElementArg : public ObjectArg
        {
        public:
            SVGFEDistantLightElementArg() : ObjectArg("SVGFEDistantLightElement") {}
        };

        class SVGFEFuncGElementArg : public ObjectArg
        {
        public:
            SVGFEFuncGElementArg() : ObjectArg("SVGFEFuncGElement") {}
        };

        class SVGStopElementArg : public ObjectArg
        {
        public:
            SVGStopElementArg() : ObjectArg("SVGStopElement") {}
        };

        class SVGFESpotLightElementArg : public ObjectArg
        {
        public:
            SVGFESpotLightElementArg() : ObjectArg("SVGFESpotLightElement") {}
        };

        class SVGMarkerElementArg : public ObjectArg
        {
        public:
            SVGMarkerElementArg() : ObjectArg("SVGMarkerElement") {}
        };

        class SVGFECompositeElementArg : public ObjectArg
        {
        public:
            SVGFECompositeElementArg() : ObjectArg("SVGFECompositeElement") {}
        };

        class SVGFEFuncBElementArg : public ObjectArg
        {
        public:
            SVGFEFuncBElementArg() : ObjectArg("SVGFEFuncBElement") {}
        };

        class SVGMaskElementArg : public ObjectArg
        {
        public:
            SVGMaskElementArg() : ObjectArg("SVGMaskElement") {}
        };

        class SVGRectElementArg : public ObjectArg
        {
        public:
            SVGRectElementArg() : ObjectArg("SVGRectElement") {}
        };

        class SVGMetadataElementArg : public ObjectArg
        {
        public:
            SVGMetadataElementArg() : ObjectArg("SVGMetadataElement") {}
        };

        // deprecated
        class SVGFontFaceNameElementArg : public ObjectArg
        {
        public:
            SVGFontFaceNameElementArg() : ObjectArg("SVGFontFaceNameElement") {}
        };

        // deprecated
        class SVGAnimateColorElementArg : public ObjectArg
        {
        public:
            SVGAnimateColorElementArg() : ObjectArg("SVGAnimateColorElement") {}
        };

        class SVGFEGaussianBlurElementArg : public ObjectArg
        {
        public:
            SVGFEGaussianBlurElementArg() : ObjectArg("SVGFEGaussianBlurElement") {}
        };

        class SVGFEImageElementArg : public ObjectArg
        {
        public:
            SVGFEImageElementArg() : ObjectArg("SVGFEImageElement") {}
        };

        class SVGFEFuncAElementArg : public ObjectArg
        {
        public:
            SVGFEFuncAElementArg() : ObjectArg("SVGFEFuncAElement") {}
        };

        class SVGForeignObjectElementArg : public ObjectArg
        {
        public:
            SVGForeignObjectElementArg() : ObjectArg("SVGForeignObjectElement") {}
        };

        // deprecated
        class SVGFontElementArg : public ObjectArg
        {
        public:
            SVGFontElementArg() : ObjectArg("SVGFontElement") {}
        };

        class SVGClipPathElementArg : public ObjectArg
        {
        public:
            SVGClipPathElementArg() : ObjectArg("SVGClipPathElement") {}
        };

        class SVGLineElementArg : public ObjectArg
        {
        public:
            SVGLineElementArg() : ObjectArg("SVGLineElement") {}
        };

        class SVGColorProfileElementArg : public ObjectArg
        {
        public:
            SVGColorProfileElementArg() : ObjectArg("SVGColorProfileElement") {}
        };

        class SVGAnimateMotionElementArg : public ObjectArg
        {
        public:
            SVGAnimateMotionElementArg() : ObjectArg("SVGAnimateMotionElement") {}
        };

        class SVGFEComponentTransferElementArg : public ObjectArg
        {
        public:
            SVGFEComponentTransferElementArg() : ObjectArg("SVGFEComponentTransferElement") {}
        };

        class SVGFEBlendElementArg : public ObjectArg
        {
        public:
            SVGFEBlendElementArg() : ObjectArg("SVGFEBlendElement") {}
        };

        class SVGFEOffsetElementArg : public ObjectArg
        {
        public:
            SVGFEOffsetElementArg() : ObjectArg("SVGFEOffsetElement") {}
        };

        class SVGFEDropShadowElementArg : public ObjectArg
        {
        public:
            SVGFEDropShadowElementArg() : ObjectArg("SVGFEDropShadowElement") {}
        };

        class SVGPathElementArg : public ObjectArg
        {
        public:
            SVGPathElementArg() : ObjectArg("SVGPathElement") {}
        };

        /*
        * SVG interfaces 
        */
        class SVGFilterPrimitiveStandardAttributesArg : public ObjectArg
        {
        public:
            SVGFilterPrimitiveStandardAttributesArg() : ObjectArg("SVGFilterPrimitiveStandardAttributes") {}
        };

        class SVGFitToViewBoxArg : public ObjectArg
        {
        public:
            SVGFitToViewBoxArg() : ObjectArg("SVGFitToViewBox") {}
        };

        class SVGViewSpecArg : public ObjectArg
        {
        public:
            SVGViewSpecArg() : ObjectArg("SVGViewSpec") {}
        };

        /*
        * SVG objects
        */
        class SVGAnimatedStringArg : public ObjectArg
        {
        public:
            SVGAnimatedStringArg() : ObjectArg("SVGAnimatedString") {}
        };

        class SVGAnimatedLengthListArg : public ObjectArg
        {
        public:
            SVGAnimatedLengthListArg() : ObjectArg("SVGAnimatedLengthList") {}
        };

        class SuspendHandleIDArg : public ObjectArg
        {
        public:
            SuspendHandleIDArg() : ObjectArg("SuspendHandleID") {}
        };

        class SVGAnimatedAngleArg : public ObjectArg
        {
        public:
            SVGAnimatedAngleArg() : ObjectArg("SVGAnimatedAngle") {}
        };

        class SVGPathSegCurvetoCubicSmoothAbsArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoCubicSmoothAbsArg() : ObjectArg("SVGPathSegCurvetoCubicSmoothAbs") {}
        };

        class SVGPathSegMovetoAbsArg : public ObjectArg
        {
        public:
            SVGPathSegMovetoAbsArg() : ObjectArg("SVGPathSegMovetoAbs") {}
        };

        class SVGLengthListArg : public ObjectArg
        {
        public:
            SVGLengthListArg() : ObjectArg("SVGLengthList") {}
        };

        class SVGAnimatedRectArg : public ObjectArg
        {
        public:
            SVGAnimatedRectArg() : ObjectArg("SVGAnimatedRect") {}
        };

        class SVGPathSegArg : public ObjectArg
        {
        public:
            SVGPathSegArg() : ObjectArg("SVGPathSeg") {}
        };

        class SVGAngleArg : public ObjectArg
        {
        public:
            SVGAngleArg() : ObjectArg("SVGAngle") {}
        };

        class SVGPathSegArcRelArg : public ObjectArg
        {
        public:
            SVGPathSegArcRelArg() : ObjectArg("SVGPathSegArcRel") {}
        };

        class SVGPathSegCurvetoQuadraticAbsArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoQuadraticAbsArg() : ObjectArg("SVGPathSegCurvetoQuadraticAbs") {}
        };

        class SVGPathSegLinetoAbsArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoAbsArg() : ObjectArg("SVGPathSegLinetoAbs") {}
        };

        class SVGPathSegLinetoVerticalRelArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoVerticalRelArg() : ObjectArg("SVGPathSegLinetoVerticalRel") {}
        };

        class SVGPathSegCurvetoQuadraticSmoothRelArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoQuadraticSmoothRelArg() : ObjectArg("SVGPathSegCurvetoQuadraticSmoothRel") {}
        };

        class SVGPathSegCurvetoQuadraticSmoothAbsArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoQuadraticSmoothAbsArg() : ObjectArg("SVGPathSegCurvetoQuadraticSmoothAbs") {}
        };

        class SVGPathSegListArg : public ObjectArg
        {
        public:
            SVGPathSegListArg() : ObjectArg("SVGPathSegList") {}
        };

        class SVGAnimatedLengthArg : public ObjectArg
        {
        public:
            SVGAnimatedLengthArg() : ObjectArg("SVGAnimatedLength") {}
        };

        class SVGMatrixArg : public ObjectArg
        {
        public:
            SVGMatrixArg() : ObjectArg("SVGMatrix") {}
        };

        class SVGLengthArg : public ObjectArg
        {
        public:
            SVGLengthArg() : ObjectArg("SVGLength") {}
        };

        class SVGNumberListArg : public ObjectArg
        {
        public:
            SVGNumberListArg() : ObjectArg("SVGNumberList") {}
        };

        class SVGPreserveAspectRatioArg : public ObjectArg
        {
        public:
            SVGPreserveAspectRatioArg() : ObjectArg("SVGPreserveAspectRatio") {}
        };

        class SVGURIReferenceArg : public ObjectArg
        {
        public:
            SVGURIReferenceArg() : ObjectArg("SVGURIReference") {}
        };

        class SVGPathSegLinetoVerticalAbsArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoVerticalAbsArg() : ObjectArg("SVGPathSegLinetoVerticalAbs") {}
        };

        class SVGTransformArg : public ObjectArg
        {
        public:
            SVGTransformArg() : ObjectArg("SVGTransform") {}
        };

        class SVGAnimatedTransformListArg : public ObjectArg
        {
        public:
            SVGAnimatedTransformListArg() : ObjectArg("SVGAnimatedTransformList") {}
        };

        class SVGPathSegLinetoRelArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoRelArg() : ObjectArg("SVGPathSegLinetoRel") {}
        };

        class SVGPathSegLinetoHorizontalRelArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoHorizontalRelArg() : ObjectArg("SVGPathSegLinetoHorizontalRel") {}
        };

        class SVGNodeListArg : public ObjectArg
        {
        public:
            SVGNodeListArg() : ObjectArg("SVGNodeList") {}
        };
        class SVGPathSegMovetoRelArg : public ObjectArg
        {
        public:
            SVGPathSegMovetoRelArg() : ObjectArg("SVGPathSegMovetoRel") {}
        };

        class SVGPointListArg : public ObjectArg
        {
        public:
            SVGPointListArg() : ObjectArg("SVGPointList") {}
        };

        class SVGTransformListArg : public ObjectArg
        {
        public:
            SVGTransformListArg() : ObjectArg("SVGTransformList") {}
        };

        class SVGAnimatedEnumerationArg : public ObjectArg
        {
        public:
            SVGAnimatedEnumerationArg() : ObjectArg("SVGAnimatedEnumeration") {}
        };

        class SVGAnimatedPreserveAspectRatioArg : public ObjectArg
        {
        public:
            SVGAnimatedPreserveAspectRatioArg() : ObjectArg("SVGAnimatedPreserveAspectRatio") {}
        };

        class SVGPointArg : public ObjectArg
        {
        public:
            SVGPointArg() : ObjectArg("SVGPoint") {}
        };

        class SVGStringListArg : public ObjectArg
        {
        public:
            SVGStringListArg() : ObjectArg("SVGStringList") {}
        };

        class SVGAnimatedNumberArg : public ObjectArg
        {
        public:
            SVGAnimatedNumberArg() : ObjectArg("SVGAnimatedNumber") {}
        };

        class SVGPathSegClosePathArg : public ObjectArg
        {
        public:
            SVGPathSegClosePathArg() : ObjectArg("SVGPathSegClosePath") {}
        };

        class SVGPathSegCurvetoQuadraticRelArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoQuadraticRelArg() : ObjectArg("SVGPathSegCurvetoQuadraticRel") {}
        };

        class SVGAnimatedIntegerArg : public ObjectArg
        {
        public:
            SVGAnimatedIntegerArg() : ObjectArg("SVGAnimatedInteger") {}
        };

        class SVGNumberArg : public ObjectArg
        {
        public:
            SVGNumberArg() : ObjectArg("SVGNumber") {}
        };

        class SVGPathSegLinetoHorizontalAbsArg : public ObjectArg
        {
        public:
            SVGPathSegLinetoHorizontalAbsArg() : ObjectArg("SVGPathSegLinetoHorizontalAbs") {}
        };

        class SVGAnimatedNumberListArg : public ObjectArg
        {
        public:
            SVGAnimatedNumberListArg() : ObjectArg("SVGAnimatedNumberList") {}
        };

        class SVGPathSegArcAbsArg : public ObjectArg
        {
        public:
            SVGPathSegArcAbsArg() : ObjectArg("SVGPathSegArcAbs") {}
        };

        class SVGPathSegCurvetoCubicAbsArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoCubicAbsArg() : ObjectArg("SVGPathSegCurvetoCubicAbs") {}
        };

        class SVGPathSegCurvetoCubicSmoothRelArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoCubicSmoothRelArg() : ObjectArg("SVGPathSegCurvetoCubicSmoothRel") {}
        };

        class SVGPathSegCurvetoCubicRelArg : public ObjectArg
        {
        public:
            SVGPathSegCurvetoCubicRelArg() : ObjectArg("SVGPathSegCurvetoCubicRel") {}
        };

        class SVGRectArg : public ObjectArg
        {
        public:
            SVGRectArg() : ObjectArg("SVGRect") {}
        };

        class SVGHTMLStringArg : public ObjectArg
        {
        public:
            SVGHTMLStringArg() : ObjectArg("SVGHTMLString") {}
        };

        class SVGAnimatedBooleanArg : public ObjectArg
        {
        public:
            SVGAnimatedBooleanArg() : ObjectArg("SVGAnimatedBoolean") {}
        };

        class SVGQuerySelectorArg : public Arg
        {
        private:
            CSS::CSSSelector *selector;

        public:
            SVGQuerySelectorArg();
            virtual ~SVGQuerySelectorArg();
            bool is_object();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SVGTagArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SVGElementIDArg : public Arg
        {
        private:
            Object *elem;

        public:
            SVGElementIDArg();
            bool is_object();
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif
