#include "svg_attr.h"
#include "html_val.h"
#include "svg_val.h"
#include "common_val.h"
#include "css_val.h"
#include "Value.h"
#include "css_declaration.h"

using namespace HIRMutate::HTML;
using namespace HIRMutate::SVG;
using namespace HIRMutate::COMMON;

void HIRMutate::Attribute::SVG::initialize_svg_attributes()
{
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "href", HANDLE(DummyUrlValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "target", HANDLE(TargetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "x", HANDLE(AltGlyphXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "y", HANDLE(AltGlyphXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "dx", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "dy", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "xlink:href", HANDLE(AltGlyphXlinkHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "glyphRef", HANDLE(GlyphRefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "format", HANDLE(FormatValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "rotate", HANDLE(RotateValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "accumulate", HANDLE(AccumulateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "additive", HANDLE(AdditiveValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "begin", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "by", nullptr)); // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "calcMode", HANDLE(CalcModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "dur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "end", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "fill", HANDLE(AnimateFillValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "from", nullptr));       // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "keySplines", nullptr)); // TODO: KeySplinesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "keyTimes", nullptr));   // TODO: KeyTimesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "max", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "min", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "repeatCount", HANDLE(RepeatCountValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "repeatDur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "restart", HANDLE(RestartValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "to", nullptr));     // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "values", nullptr)); // TODO: AnimationValuesValue

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "accumulate", HANDLE(AccumulateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "additive", HANDLE(AdditiveValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "begin", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "by", nullptr)); // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "calcMode", HANDLE(CalcModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "dur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "end", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "fill", HANDLE(AnimateFillValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "from", nullptr));       // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "keyPoints", nullptr));  // TODO: KeyPointsValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "keySplines", nullptr)); // TODO: KeySplinesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "keyTimes", nullptr));   // TODO: KeyTimesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "max", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "min", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "path", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "repeatCount", HANDLE(RepeatCountValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "repeatDur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "restart", HANDLE(RestartValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "rotate", HANDLE(RotateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "to", nullptr));     // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "values", nullptr)); // TODO: AnimationValuesValue

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "accumulate", HANDLE(AccumulateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "additive", HANDLE(AdditiveValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "begin", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "by", nullptr)); // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "calcMode", HANDLE(CalcModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "dur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "end", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "fill", HANDLE(AnimateFillValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "from", nullptr));       // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "keySplines", nullptr)); // TODO: KeySplinesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "keyTimes", nullptr));   // TODO: KeyTimesValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "max", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "min", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "repeatCount", HANDLE(RepeatCountValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "repeatDur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "restart", HANDLE(RestartValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "to", nullptr));     // TODO: FromValue
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "values", nullptr)); // TODO: AnimationValuesValue

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "cx", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "cy", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "r", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "clipPathUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "href", HANDLE(CursorHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGDiscardElement", "begin", HANDLE(BeginValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "cx", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "cy", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "rx", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "ry", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "in2", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "mode", HANDLE(CSS::BlendModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "type", HANDLE(FeColorMatrixTypeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "values", HANDLE(FeColorMatrixValuesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "in2", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "k1", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "k2", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "k3", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "k4", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "operator", HANDLE(FeCompositeOperatorValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "bias", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "divisor", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "edgeMode", HANDLE(EdgeModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "kernelMatrix", HANDLE(KernelMatrixValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "kernelUnitLength", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "order", HANDLE(OrderValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "preserveAlpha", HANDLE(BooleanValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "targetX", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "targetY", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "diffuseConstant", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "kernelUnitLength", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "surfaceScale", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "in2", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "scale", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "xChannelSelector", HANDLE(RGBAValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "yChannelSelector", HANDLE(RGBAValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDistantLightElement", "azimuth", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDistantLightElement", "elevation", HANDLE(IntegerValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "dx", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "dy", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "stdDeviation", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "amplitude", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "exponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "intercept", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "offset", HANDLE(OffsetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "slope", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "tableValues", HANDLE(TableValuesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "type", HANDLE(FeFuncTypeValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "amplitude", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "exponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "intercept", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "offset", HANDLE(OffsetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "slope", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "tableValues", HANDLE(TableValuesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "type", HANDLE(FeFuncTypeValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "amplitude", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "exponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "intercept", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "offset", HANDLE(OffsetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "slope", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "tableValues", HANDLE(TableValuesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "type", HANDLE(FeFuncTypeValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "amplitude", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "exponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "intercept", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "offset", HANDLE(OffsetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "slope", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "tableValues", HANDLE(TableValuesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "type", HANDLE(FeFuncTypeValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "edgeMode", HANDLE(EdgeModeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "stdDeviation", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "y", HANDLE(LengthPercentageValue)));

    // add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "crossorigin", CrossoriginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "href", HANDLE(FeImageHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeNodeElement", "in", HANDLE(InValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "operator", HANDLE(FeMorphologyOperatorValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "radius", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "dx", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "dy", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEPointLightElement", "x", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEPointLightElement", "y", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFEPointLightElement", "z", HANDLE(NumberValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "kernelUnitLength", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "specularConstant", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "specularExponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "surfaceScale", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "limitingConeAngle", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "pointsAtX", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "pointsAtY", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "pointsAtZ", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "specularExponent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "x", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "y", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "z", HANDLE(NumberValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "in", HANDLE(InValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "baseFrequency", HANDLE(NumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "numOctaves", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "seed", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "stitchTiles", HANDLE(StitchTilesValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "type", HANDLE(FeTurbulenceValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "filterRes", HANDLE(SignedNumberOptionalNumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "filterUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "primitiveUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "horiz-adv-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "horiz-origin-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "horiz-origin-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "vert-adv-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "vert-origin-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "vert-origin-y", HANDLE(IntegerValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "accent-height", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "alphabetic", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "ascent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "bbox", HANDLE(BBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "cap-height", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "descent", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "hanging", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "ideographic", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "mathematical", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "overline-position", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "overline-thickness", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "panose-1", HANDLE(PanoseValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "slope", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "stemh", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "stemv", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "strikethrough-position", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "strikethrough-thickness", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "underline-position", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "underline-thickness", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "unicode-range", HANDLE(UnicodeRangeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "units-per-em", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "v-alphabetic", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "v-hanging", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "v-ideographic", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "v-mathematical", HANDLE(SignedIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "x-height", HANDLE(IntegerValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceFormatElement", "string", HANDLE(FormatValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceNameElement", "name", HANDLE(NameValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceUriElement", "xlink:href", HANDLE(FontFaceUriXlinkHrefValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "color-rendering", HANDLE(RenderingValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "cursor", HANDLE(CSS::CursorValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "display", HANDLE(CSS::DisplayValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "filter", HANDLE(CSS::FilterValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "mask", HANDLE(CSS::MaskValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "transform", HANDLE(TransformValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "arabic-form", HANDLE(ArabicFormValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "d", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "horiz-adv-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "lang", HANDLE(LangValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "orientation", HANDLE(OrientationValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "unicode", HANDLE(UnicodeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "vert-adv-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "vert-origin-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "vert-origin-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "dx", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "dy", HANDLE(FilterDxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "format", HANDLE(FormatValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "glyphRef", HANDLE(GlyphRefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "x", HANDLE(NumberValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "xlink:href", HANDLE(GlyphRefXlinkHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "y", HANDLE(NumberValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "g1", HANDLE(GValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "g2", HANDLE(GValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "k", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "u1", HANDLE(UValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "u2", HANDLE(UValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "hatchContentUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "hatchUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "pitch", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "rotate", HANDLE(RotateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "y", HANDLE(LengthPercentageValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "d", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "offset", HANDLE(OffsetValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "href", HANDLE(ImageHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    // add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "crossorigin", HANDLE(CrossoriginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "x1", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "x2", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "y1", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "y2", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "gradientTransform", HANDLE(TransformValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "gradientUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "href", HANDLE(GradientHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "spreadMethod", HANDLE(SpreadMethodValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "x1", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "x2", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "y1", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "y2", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMPathElement", "href", HANDLE(PathHrefValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "refX", HANDLE(MarkerRefXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "refY", HANDLE(MarkerRefXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "markerHeight", HANDLE(LengthPercentageIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "markerUnits", HANDLE(MarkerUnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "markerWidth", HANDLE(LengthPercentageIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "viewBox", HANDLE(ViewBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "orient", HANDLE(OrientValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "maskContentUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "maskUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "d", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "horiz-adv-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "vert-adv-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "vert-origin-x", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "vert-origin-y", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "d", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "pathLength", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "points", HANDLE(PointsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "points", HANDLE(PointsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "href", HANDLE(GradientHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "cx", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "cy", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "fr", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "fx", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "fy", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "r", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "gradientTransform", HANDLE(TransformValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "gradientUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "spreadMethod", HANDLE(SpreadMethodValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "rx", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "ry", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "height", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "width", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "viewBox", HANDLE(ViewBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "zoomAndPan", HANDLE(ZoomAndPanValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "baseProfile", HANDLE(BaseProfileValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "type", HANDLE(CSSTypeValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "media", HANDLE(MediaQueryValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "title", HANDLE(StringValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "x", HANDLE(TextXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "y", HANDLE(TextXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "dx", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "dy", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "rotate", HANDLE(RotateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "textLength", HANDLE(LengthPercentageIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "lengthAdjust", HANDLE(LengthAdjustValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "patternContentUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "patternTransform", HANDLE(TransformValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "patternUnits", HANDLE(UnitsValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "height", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "width", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "x", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "y", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "viewBox", HANDLE(ViewBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "transform", HANDLE(TransformValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "href", HANDLE(PatternHrefValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "begin", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "dur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "end", HANDLE(BeginValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "fill", HANDLE(AnimateFillValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "max", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "min", HANDLE(ClockValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "repeatCount", HANDLE(RepeatCountValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "repeatDur", HANDLE(DurValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "restart", HANDLE(RestartValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "to", nullptr)); // TODO: FromValue

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "offset", HANDLE(OffsetValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "path", HANDLE(PathValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "refX", HANDLE(SymbolRefXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "refY", HANDLE(SymbolRefXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "viewBox", HANDLE(ViewBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "xlink:href", HANDLE(TRefXlinkHrefValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "x", HANDLE(TextXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "y", HANDLE(TextXValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "dx", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "dy", HANDLE(DxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "rotate", HANDLE(RotateValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "textLength", HANDLE(LengthPercentageIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "lengthAdjust", HANDLE(LengthAdjustValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "href", HANDLE(PathHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "startOffset", HANDLE(LengthPercentageIntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "lengthAdjust", HANDLE(LengthAdjustValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "method", HANDLE(MethodValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "path", HANDLE(PathValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "side", HANDLE(SideValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "spacing", HANDLE(SpacingValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "textLength", HANDLE(LengthPercentageIntegerValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "x", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "y", HANDLE(LengthPercentageValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "width", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "height", HANDLE(LengthValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "href", HANDLE(UseHrefValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "transform", HANDLE(TransformValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "g1", HANDLE(GValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "g2", HANDLE(GValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "k", HANDLE(IntegerValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "u1", HANDLE(UValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "u2", HANDLE(UValue)));

    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "preserveAspectRatio", HANDLE(PreserveAspectRatioValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "viewBox", HANDLE(ViewBoxValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "viewTarget", HANDLE(SVGElementIDValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "zoomAndPan", HANDLE(ZoomAndPanValue)));
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "transform", HANDLE(TransformValue)));

    // presentation attributes
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "alignment-baseline", HANDLE(AlignmentBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "baseline-shift", HANDLE(BaselineShiftValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "word-spacing", HANDLE(WordSpacingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "color-rendering", HANDLE(RenderingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "clip-path", HANDLE(CSS::ClipPathValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "lighting-color", HANDLE(CSS::ColorValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "flood-color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "flood-opacity", HANDLE(CSS::OpacityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "flood-color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "flood-opacity", HANDLE(CSS::OpacityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeNodeElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "lighting-color", HANDLE(CSS::ColorValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "color-interpolation-filters", HANDLE(ColorInterpolationFiltersValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "visibility", HANDLE(CSS::VisibilityValue)));

    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "overflow", HANDLE(OverflowValue)));
    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "transform", HANDLE(TransformValue)));

    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "transform", HANDLE(TransformValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "color-profile", HANDLE(ColorProfileValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "marker-end", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "marker-mid", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "marker-start", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "color-rendering", HANDLE(RenderingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "marker-end", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "marker-mid", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "marker-start", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "marker-end", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "marker-mid", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "marker-start", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "marker-end", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "marker-mid", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "marker-start", HANDLE(MarkerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "color-rendering", HANDLE(RenderingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "image-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "visibility", HANDLE(CSS::VisibilityValue)));

    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "color", HANDLE(CSS::ColorValue)));
    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "solid-color", HANDLE(CSS::ColorValue)));
    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "solid-opacity", HANDLE(CSS::OpacityValue)));
    // add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "transform", HANDLE(TransformValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "stop-color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "stop-opacity", HANDLE(CSS::OpacityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "visibility", HANDLE(CSS::VisibilityValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "clip", HANDLE(CSS::ClipValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "enable-background", HANDLE(EnableBackgroundValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "overflow", HANDLE(OverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "pointer-events", HANDLE(PointerEventsValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "alignment-baseline", HANDLE(AlignmentBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "baseline-shift", HANDLE(BaselineShiftValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "word-spacing", HANDLE(WordSpacingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "alignment-baseline", HANDLE(AlignmentBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "baseline-shift", HANDLE(BaselineShiftValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "word-spacing", HANDLE(WordSpacingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "inline-size", HANDLE(LengthPercentageIntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "shape-inside", HANDLE(CSS::ShapeOutsideValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "shape-margin", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "shape-outside", HANDLE(CSS::ShapeOutsideValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "shape-padding", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "text-overflow", HANDLE(TextOverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "text-rendering", HANDLE(CSS::TextRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "word-spacing", HANDLE(WordSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "writing-mode", HANDLE(CSS::WritingModeValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "alignment-baseline", HANDLE(AlignmentBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "baseline-shift", HANDLE(BaselineShiftValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "word-spacing", HANDLE(WordSpacingValue)));

    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "buffered-rendering", HANDLE(BufferedRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "clip-path", HANDLE(CSS::ClipPathValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "clip-rule", HANDLE(ClipRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "color-interpolation", HANDLE(ColorInterpolationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "color-rendering", HANDLE(RenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "color", HANDLE(CSS::ColorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "cursor", HANDLE(CSS::CursorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "direction", HANDLE(CSS::DirectionValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "display", HANDLE(CSS::DisplayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "dominant-baseline", HANDLE(DominantBaselineValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "fill", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "fill-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "fill-rule", HANDLE(FillRuleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "filter", HANDLE(CSS::FilterValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-family", HANDLE(CSS::FontFamilyValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-size", HANDLE(CSS::FontSizeValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-size-adjust", HANDLE(CSS::FontSizeAdjustValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-stretch", HANDLE(CSS::FontStretchValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-style", HANDLE(CSS::FontStyleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-variant", HANDLE(CSS::FontVariantValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "font-weight", HANDLE(CSS::FontWeightValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "glyph-orientation-horizontal", HANDLE(AngleValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "glyph-orientation-vertical", HANDLE(GlyphOrientationVerticalValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "inline-size", HANDLE(LengthPercentageIntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "kerning", HANDLE(KerningValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "letter-spacing", HANDLE(CSS::LetterSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "mask", HANDLE(CSS::MaskValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "paint-order", HANDLE(PaintOrderValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "pointer-events", HANDLE(PointerEventsValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "shape-inside", HANDLE(CSS::ShapeOutsideValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "shape-margin", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "shape-outside", HANDLE(CSS::ShapeOutsideValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "shape-padding", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "shape-rendering", HANDLE(ShapeRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke", HANDLE(FillValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-dasharray", HANDLE(StrokeDasharrayValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-dashoffset", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-linecap", HANDLE(StrokeLinecapValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-linejoin", HANDLE(StrokeLinejoinValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-miterlimit", HANDLE(IntegerValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-opacity", HANDLE(CSS::OpacityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "stroke-width", HANDLE(LengthPercentageValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "text-anchor", HANDLE(TextAnchorValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "text-decoration", HANDLE(CSS::TextDecorationValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "text-overflow", HANDLE(TextOverflowValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "text-rendering", HANDLE(CSS::TextRenderingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "unicode-bidi", HANDLE(CSS::UnicodeBidiValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "vector-effect", HANDLE(VectorEffectValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "visibility", HANDLE(CSS::VisibilityValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "white-space", HANDLE(WhiteSpaceValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "word-spacing", HANDLE(WordSpacingValue)));
    add_presentation_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "writing-mode", HANDLE(CSS::WritingModeValue)));

    // global attributes
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphDefElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphItemElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGClipPathElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDescElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDescElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDescElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDiscardElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDistantLightElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncAElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncBElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncGElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEFuncRElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeNodeElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFEPointLightElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFESpotLightElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFilterElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceFormatElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceNameElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceSrcElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGFontFaceUriElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGlyphRefElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHKernElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMPathElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMaskElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMetadataElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMissingGlyphElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStyleElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTitleElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTitleElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTitleElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "class", HANDLE(ClassValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "style", HANDLE(CSS::CSSStyleDeclarationValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGUseElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGVKernElement", "tabindex", HANDLE(TabIndexValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "tabindex", HANDLE(TabIndexValue)));

    // Events
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAltGlyphElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "onbegin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "onend", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "onrepeat", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "onbegin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "onend", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "onrepeat", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateMotionElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "onbegin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "onend", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "onrepeat", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCircleElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGCursorElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDefsElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGDescElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGDescElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGEllipseElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGForeignObjectElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGGElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGHatchpathElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGImageElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLineElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGLinearGradientElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMPathElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGMPathElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGMarkerElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGMetadataElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGMetadataElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPathElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGPatternElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolygonElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGPolylineElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGRadialGradientElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGRectElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onabort", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onerror", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onresize", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onscroll", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onunload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onzoom", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "onbegin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "onend", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "onrepeat", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGSolidcolorElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGStopElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSwitchElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGSymbolElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTRefElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTSpanElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "onactivate", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "onfocusin", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTextPathElement", "onfocusout", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGTitleElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGTitleElement", "onload", HANDLE(CallEventHandlerValue)));
    add_global_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "onclick", HANDLE(CallEventHandlerValue)));
    // add_global_attribute(std::make_shared<AttributeTemplate>("SVGViewElement", "onload", HANDLE(CallEventHandlerValue)));

    // FIXME: temporarily include them for setAttribute
    // Example: https://bugs.chromium.org/p/project-zero/issues/detail?id=1596
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "attributeName", nullptr));          // TODO: attribute name value
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "attributeName", nullptr)); // TODO: attribute
    add_regular_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "attributeName", nullptr));              // TODO: attribute name value
    // add_regular_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "type", HANDLE(AnimateTransformTypeValue)));

    std::for_each(DOC::svg_ariable_elements.begin(), DOC::svg_ariable_elements.end(),
                  [](string &elem)
                  {
                      std::for_each(aria_attribute_values.begin(), aria_attribute_values.end(),
                                    [&elem](map<string, Value *(*)(void)>::reference e)
                                    {
                                        add_aria_attribute(std::make_shared<AttributeTemplate>(elem.c_str(), e.first.c_str(), e.second));
                                    });
                  });

    // mandatory
    add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGSVGElement", "xmlns", HANDLE(XMLNSValue)));
    add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGAnimateElement", "attributeName", nullptr));          // TODO: attribute name value
    add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "attributeName", nullptr)); // TODO: attribute
    add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGSetElement", "attributeName", nullptr));              // TODO: attribute name value
    add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGAnimateTransformElement", "type", HANDLE(AnimateTransformTypeValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGGlyphElement", "glyph-name", GlyphNameValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEBlendElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEColorMatrixElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEComponentTransferElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFECompositeElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEConvolveMatrixElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEDiffuseLightingElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEDisplacementMapElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEDropShadowElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEFloodElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEGaussianBlurElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEImageElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEMergeElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEMorphologyElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFEOffsetElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFESpecularLightingElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFETileElement", "result", ResultValue)));
    // add_mandatory_attribute(std::make_shared<AttributeTemplate>("SVGFETurbulenceElement", "result", ResultValue)));
}