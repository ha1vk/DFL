#include "svg_symbols.h"

namespace HIRMutate
{
    namespace DOC
    {
        namespace SVG
        {
            map<string, string> svg_elements;
            vector<string> svg_tags;
            vector<string> svg_elements_k;
            map<string, string> svg_tag_to_elem_map;
            vector<string> svg_animation_elements;
            vector<string> svg_paint_server_elements;
            vector<string> svg_text_content_elements;
            vector<string> svg_text_content_child_elements;
            vector<string> svg_shape_elements;
            vector<string> svg_container_elements;
            vector<string> svg_graphics_elements;
            vector<string> svg_establish_viewport_elements;
            vector<string> svg_gradient_elements;
            vector<string> svg_filter_primitives;
            vector<string> svg_markable_elements;
            vector<string> svg_descriptive_elements;
            vector<string> svg_structural_elements;
            vector<string> svg_light_sources;
            map<string, vector<string> > svg_child_elements;
            vector<string> svg_animatable_attributes;
            vector<string> svg_animatable_color_attributes;
            vector<string> svg_animatable_transform_attributes;
            vector<string> svg_animation_begin_events;
            vector<string> svg_ariable_elements;
        }
    }
}

void HIRMutate::DOC::SVG::initSym()
{
    SVG_ELEMENTS("SVGAElement", "a")
    SVG_ELEMENTS("SVGAltGlyphDefElement", "altGlyphDef")
    SVG_ELEMENTS("SVGAltGlyphElement", "altGlyph")
    SVG_ELEMENTS("SVGAltGlyphItemElement", "altGlyphItem")
    //SVG_ELEMENTS("SVGAnimateColorElement","animateColor")
    SVG_ELEMENTS("SVGAnimateElement", "animate")
    SVG_ELEMENTS("SVGAnimateMotionElement", "animateMotion")
    SVG_ELEMENTS("SVGAnimateTransformElement", "animateTransform")
    SVG_ELEMENTS("SVGCircleElement", "circle")
    SVG_ELEMENTS("SVGClipPathElement", "clipPath")
    //SVG_ELEMENTS("SVGColorProfileElement","color-profile")
    SVG_ELEMENTS("SVGCursorElement", "cursor")
    SVG_ELEMENTS("SVGDefsElement", "defs")
    SVG_ELEMENTS("SVGDescElement", "desc")
    SVG_ELEMENTS("SVGDiscardElement", "discard")
    SVG_ELEMENTS("SVGEllipseElement", "ellipse")
    SVG_ELEMENTS("SVGFEBlendElement", "feBlend")
    SVG_ELEMENTS("SVGFEColorMatrixElement", "feColorMatrix")
    SVG_ELEMENTS("SVGFEComponentTransferElement", "feComponentTransfer")
    SVG_ELEMENTS("SVGFECompositeElement", "feComposite")
    SVG_ELEMENTS("SVGFEConvolveMatrixElement", "feConvolveMatrix")
    SVG_ELEMENTS("SVGFEDiffuseLightingElement", "feDiffuseLighting")
    SVG_ELEMENTS("SVGFEDisplacementMapElement", "feDisplacementMap")
    SVG_ELEMENTS("SVGFEDistantLightElement", "feDistantLight")
    SVG_ELEMENTS("SVGFEDropShadowElement", "feDropShadow")
    SVG_ELEMENTS("SVGFEFloodElement", "feFlood")
    SVG_ELEMENTS("SVGFEFuncAElement", "feFuncA")
    SVG_ELEMENTS("SVGFEFuncBElement", "feFuncB")
    SVG_ELEMENTS("SVGFEFuncGElement", "feFuncG")
    SVG_ELEMENTS("SVGFEFuncRElement", "feFuncR")
    SVG_ELEMENTS("SVGFEGaussianBlurElement", "feGaussianBlur")
    SVG_ELEMENTS("SVGFEImageElement", "feImage")
    SVG_ELEMENTS("SVGFEMergeElement", "feMerge")
    SVG_ELEMENTS("SVGFEMergeNodeElement", "feMergeNode")
    SVG_ELEMENTS("SVGFEMorphologyElement", "feMorphology")
    SVG_ELEMENTS("SVGFEOffsetElement", "feOffset")
    SVG_ELEMENTS("SVGFEPointLightElement", "fePointLight")
    SVG_ELEMENTS("SVGFESpecularLightingElement", "feSpecularLighting")
    SVG_ELEMENTS("SVGFESpotLightElement", "feSpotLight")
    SVG_ELEMENTS("SVGFETileElement", "feTile")
    SVG_ELEMENTS("SVGFETurbulenceElement", "feTurbulence")
    SVG_ELEMENTS("SVGFilterElement", "filter")
    SVG_ELEMENTS("SVGFontElement", "font")
    SVG_ELEMENTS("SVGFontFaceElement", "font-face")
    SVG_ELEMENTS("SVGFontFaceFormatElement", "font-face-format")
    SVG_ELEMENTS("SVGFontFaceNameElement", "font-face-name")
    SVG_ELEMENTS("SVGFontFaceSrcElement", "font-face-src")
    SVG_ELEMENTS("SVGFontFaceUriElement", "font-face-uri")
    SVG_ELEMENTS("SVGForeignObjectElement", "foreignObject")
    SVG_ELEMENTS("SVGGElement", "g")
    SVG_ELEMENTS("SVGGlyphElement", "glyph")
    SVG_ELEMENTS("SVGGlyphRefElement", "glyphRef")
    //SVG_ELEMENTS("SVGHatchElement","hatch")
    //SVG_ELEMENTS("SVGHatchpathElement","hatchpath")
    SVG_ELEMENTS("SVGHKernElement", "hkern")
    SVG_ELEMENTS("SVGImageElement", "image")
    SVG_ELEMENTS("SVGLineElement", "line")
    SVG_ELEMENTS("SVGLinearGradientElement", "linearGradient")
    SVG_ELEMENTS("SVGMPathElement", "mpath")
    SVG_ELEMENTS("SVGMarkerElement", "marker")
    SVG_ELEMENTS("SVGMaskElement", "mask")
    SVG_ELEMENTS("SVGMetadataElement", "metadata")
    SVG_ELEMENTS("SVGMissingGlyphElement", "missing-glyph")
    SVG_ELEMENTS("SVGPathElement", "path")
    SVG_ELEMENTS("SVGPatternElement", "pattern")
    SVG_ELEMENTS("SVGPolygonElement", "polygon")
    SVG_ELEMENTS("SVGPolylineElement", "polyline")
    SVG_ELEMENTS("SVGRadialGradientElement", "radialGradient")
    SVG_ELEMENTS("SVGRectElement", "rect")
    //SVG_ELEMENTS("SVGScriptElement","script")
    SVG_ELEMENTS("SVGSVGElement", "svg")
    SVG_ELEMENTS("SVGSetElement", "set")
    //SVG_ELEMENTS("SVGSolidcolorElement","solidcolor")
    SVG_ELEMENTS("SVGStopElement", "stop")
    SVG_ELEMENTS("SVGStyleElement", "style")
    SVG_ELEMENTS("SVGSwitchElement", "switch")
    SVG_ELEMENTS("SVGSymbolElement", "symbol")
    SVG_ELEMENTS("SVGTRefElement", "tref")
    SVG_ELEMENTS("SVGTSpanElement", "tspan")
    SVG_ELEMENTS("SVGTextElement", "text")
    SVG_ELEMENTS("SVGTextPathElement", "textPath")
    SVG_ELEMENTS("SVGTitleElement", "title")
    SVG_ELEMENTS("SVGUseElement", "use")
    SVG_ELEMENTS("SVGVKernElement", "vkern")
    SVG_ELEMENTS("SVGViewElement", "view")

    SVG_ANIMATION_ELEMENTS("SVGAnimateElement")
    //SVG_ANIMATION_ELEMENTS("SVGAnimateColorElement")
    SVG_ANIMATION_ELEMENTS("SVGAnimateMotionElement")
    SVG_ANIMATION_ELEMENTS("SVGAnimateTransformElement")
    SVG_ANIMATION_ELEMENTS("SVGDiscardElement")
    SVG_ANIMATION_ELEMENTS("SVGSetElement")

    SVG_PAINT_SERVER_ELEMENTS("SVGLinearGradientElement")
    SVG_PAINT_SERVER_ELEMENTS("SVGRadialGradientElement")
    //SVG_PAINT_SERVER_ELEMENTS("SVGSolidcolorElement")
    SVG_PAINT_SERVER_ELEMENTS("SVGPatternElement")
    //SVG_PAINT_SERVER_ELEMENTS("SVGHatchElement"
    //mesh

    SVG_TEXT_CONTENT_ELEMENTS("SVGTextPathElement")
    SVG_TEXT_CONTENT_ELEMENTS("SVGTextElement")
    SVG_TEXT_CONTENT_ELEMENTS("SVGTSpanElement")
    SVG_TEXT_CONTENT_ELEMENTS("SVGTRefElement")
    SVG_TEXT_CONTENT_ELEMENTS("SVGAltGlyphElement")

    SVG_TEXT_CONTENT_CHILD_ELEMENTS("SVGTextPathElement")
    SVG_TEXT_CONTENT_CHILD_ELEMENTS("SVGTSpanElement")
    SVG_TEXT_CONTENT_CHILD_ELEMENTS("SVGTRefElement")
    SVG_TEXT_CONTENT_CHILD_ELEMENTS("SVGAltGlyphElement")

    SVG_SHAPE_ELEMENTS("SVGRectElement")
    SVG_SHAPE_ELEMENTS("SVGCircleElement")
    SVG_SHAPE_ELEMENTS("SVGEllipseElement")
    SVG_SHAPE_ELEMENTS("SVGLineElement")
    SVG_SHAPE_ELEMENTS("SVGPathElement")
    SVG_SHAPE_ELEMENTS("SVGPolylineElement")
    SVG_SHAPE_ELEMENTS("SVGPolygonElement")

    SVG_CONTAINER_ELEMENTS("SVGAElement")
    SVG_CONTAINER_ELEMENTS("SVGDefsElement")
    SVG_CONTAINER_ELEMENTS("SVGGElement")
    SVG_CONTAINER_ELEMENTS("SVGMarkerElement")
    SVG_CONTAINER_ELEMENTS("SVGMaskElement")
    SVG_CONTAINER_ELEMENTS("SVGMissingGlyphElement")
    SVG_CONTAINER_ELEMENTS("SVGPatternElement")
    //SVG_CONTAINER_ELEMENTS("SVGSVGElement")
    SVG_CONTAINER_ELEMENTS("SVGSwitchElement")
    SVG_CONTAINER_ELEMENTS("SVGSymbolElement")
    //use

    SVG_GRAPHICS_ELEMENTS("SVGCircleElement")
    SVG_GRAPHICS_ELEMENTS("SVGEllipseElement")
    SVG_GRAPHICS_ELEMENTS("SVGForeignObjectElement")
    SVG_GRAPHICS_ELEMENTS("SVGImageElement")
    SVG_GRAPHICS_ELEMENTS("SVGLineElement")
    SVG_GRAPHICS_ELEMENTS("SVGPathElement")
    SVG_GRAPHICS_ELEMENTS("SVGPolygonElement")
    SVG_GRAPHICS_ELEMENTS("SVGPolylineElement")
    SVG_GRAPHICS_ELEMENTS("SVGRectElement")
    SVG_GRAPHICS_ELEMENTS("SVGTextElement")
    // use

    //SVG_ESTABLISH_VIEWPORT_ELEMENTS("SVGSVGElement")
    SVG_ESTABLISH_VIEWPORT_ELEMENTS("SVGSymbolElement")
    SVG_ESTABLISH_VIEWPORT_ELEMENTS("SVGImageElement")
    SVG_ESTABLISH_VIEWPORT_ELEMENTS("SVGForeignObjectElement")

    SVG_GRADIENT_ELEMENTS("SVGLinearGradientElement")
    SVG_GRADIENT_ELEMENTS("SVGRadialGradientElement")
    //mesh

    SVG_FILTER_PRIMITIVES("SVGFEBlendElement")
    SVG_FILTER_PRIMITIVES("SVGFEColorMatrixElement")
    SVG_FILTER_PRIMITIVES("SVGFEComponentTransferElement")
    SVG_FILTER_PRIMITIVES("SVGFECompositeElement")
    SVG_FILTER_PRIMITIVES("SVGFEConvolveMatrixElement")
    SVG_FILTER_PRIMITIVES("SVGFEDiffuseLightingElement")
    SVG_FILTER_PRIMITIVES("SVGFEDisplacementMapElement")
    SVG_FILTER_PRIMITIVES("SVGFEDropShadowElement")
    SVG_FILTER_PRIMITIVES("SVGFEFloodElement")
    SVG_FILTER_PRIMITIVES("SVGFEGaussianBlurElement")
    SVG_FILTER_PRIMITIVES("SVGFEImageElement")
    SVG_FILTER_PRIMITIVES("SVGFEMergeElement")
    SVG_FILTER_PRIMITIVES("SVGFEMergeNodeElement")
    SVG_FILTER_PRIMITIVES("SVGFEMorphologyElement")
    SVG_FILTER_PRIMITIVES("SVGFEOffsetElement")
    SVG_FILTER_PRIMITIVES("SVGFESpecularLightingElement")
    SVG_FILTER_PRIMITIVES("SVGFETileElement")
    SVG_FILTER_PRIMITIVES("SVGFETurbulenceElement")

    SVG_MARKABLE_ELEMENTS("SVGLineElement")
    SVG_MARKABLE_ELEMENTS("SVGPathElement")
    SVG_MARKABLE_ELEMENTS("SVGPolylineElement")
    SVG_MARKABLE_ELEMENTS("SVGPolygonElement")

    //SVG_DESCRIPTIVE_ELEMENTS("SVGDescElement")
    //SVG_DESCRIPTIVE_ELEMENTS"SVGTitleElement")
    //SVG_DESCRIPTIVE_ELEMENTS"SVGMetadataElement"

    SVG_STRUCTURAL_ELEMENTS("SVGDefsElement")
    SVG_STRUCTURAL_ELEMENTS("SVGGElement")
    SVG_STRUCTURAL_ELEMENTS("SVGSVGElement")
    SVG_STRUCTURAL_ELEMENTS("SVGSymbolElement")
    SVG_STRUCTURAL_ELEMENTS("SVGUseElement")

    SVG_LIGHT_SOURCES("SVGFEDistantLightElement")
    SVG_LIGHT_SOURCES("SVGFEPointLightElement")
    SVG_LIGHT_SOURCES("SVGFESpotLightElement")

    SVG_CHILD_ELEMENTS_V("SVGAElement",
                         {
                             "SVGAElement",
                             "SVGAltGlyphDefElement",
                             "SVGClipPathElement",
                             "SVGCursorElement",
                             "SVGFilterElement",
                             "SVGFontElement",
                             "SVGFontFaceElement",
                             "SVGForeignObjectElement",
                             "SVGImageElement",
                             "SVGMarkerElement",
                             "SVGMaskElement",
                             //script
                             //style
                             "SVGSwitchElement",
                             "SVGTextElement",
                             "SVGViewElement",
                         })
    SVG_CHILD_ELEMENTS_I("SVGAElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGAElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGAElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGAElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGAElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGAltGlyphDefElement",
                         {"SVGGlyphRefElement",
                          "SVGAltGlyphItemElement"})

    SVG_CHILD_ELEMENTS_V("SVGAltGlyphElement", {})

    SVG_CHILD_ELEMENTS_V("SVGAltGlyphItemElement",
                         {"SVGGlyphRefElement"})

    //SVG_CHILD_ELEMENTS("SVGAnimateColorElement",
    //    svg_descriptive_elements)

    SVG_CHILD_ELEMENTS("SVGAnimateElement",
                       svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGAnimateMotionElement",
                         {"SVGMPathElement"})
    SVG_CHILD_ELEMENTS_I("SVGAnimateMotionElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS("SVGAnimateTransformElement",
                       svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGCircleElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement",
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGCircleElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGCircleElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGCircleElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGClipPathElement",
                         {
                             "SVGTextElement"
                             //use
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGClipPathElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGClipPathElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGClipPathElement", svg_shape_elements)

    //SVG_CHILD_ELEMENTS("SVGColorProfileElement",
    //   svg_descriptive_elements)

    SVG_CHILD_ELEMENTS("SVGCursorElement",
                       svg_descriptive_elements) //script

    SVG_CHILD_ELEMENTS_V("SVGDefsElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})

    SVG_CHILD_ELEMENTS_I("SVGDefsElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGDefsElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGDefsElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGDefsElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGDefsElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGDescElement", {})

    SVG_CHILD_ELEMENTS("SVGDiscardElement",
                       svg_descriptive_elements) //script

    SVG_CHILD_ELEMENTS_V("SVGEllipseElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement",
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGEllipseElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGEllipseElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGEllipseElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEBlendElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEBlendElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEColorMatrixElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEColorMatrixElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEComponentTransferElement",
                         {
                             "SVGFEFuncAElement",
                             "SVGFEFuncBElement",
                             "SVGFEFuncGElement",
                             "SVGFEFuncRElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEComponentTransferElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFECompositeElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFECompositeElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEConvolveMatrixElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEConvolveMatrixElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS("SVGFEDiffuseLightingElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGFEDiffuseLightingElement", svg_light_sources)

    SVG_CHILD_ELEMENTS_V("SVGFEDisplacementMapElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEDisplacementMapElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEDistantLightElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEDistantLightElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEDropShadowElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEDropShadowElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEFloodElement",
                         {
                             "SVGAnimateElement",
                             //"SVGAnimateColorElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEFloodElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEFuncAElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEFuncAElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEFuncBElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEFuncBElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEFuncGElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEFuncGElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEFuncRElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEFuncRElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEGaussianBlurElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEGaussianBlurElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEImageElement",
                         {
                             "SVGAnimateElement",
                             "SVGAnimateTransformElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEImageElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEMergeElement",
                         {
                             "SVGFEMergeNodeElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_V("SVGFEMergeElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEMergeNodeElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_V("SVGFEMergeNodeElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEMorphologyElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEMorphologyElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEOffsetElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEOffsetElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFEPointLightElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFEPointLightElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS("SVGFESpecularLightingElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGFESpecularLightingElement", svg_light_sources)

    SVG_CHILD_ELEMENTS_V("SVGFESpotLightElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFESpotLightElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFETileElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFETileElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFETurbulenceElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFETurbulenceElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFilterElement",
                         {
                             "SVGAnimateElement",
                             "SVGSetElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGFilterElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGFilterElement", svg_filter_primitives)

    SVG_CHILD_ELEMENTS_V("SVGForeignObjectElement", {})

    SVG_CHILD_ELEMENTS_V("SVGFontElement",
                         {"SVGFontFaceElement",
                          "SVGGlyphElement",
                          "SVGHKernElement",
                          "SVGMissingGlyphElement",
                          "SVGVKernElement"})
    SVG_CHILD_ELEMENTS_I("SVGFontElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFontFaceElement",
                         {"SVGFontFaceSrcElement"})
    SVG_CHILD_ELEMENTS_I("SVGFontFaceElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGFontFaceFormatElement", {})

    SVG_CHILD_ELEMENTS_V("SVGFontFaceNameElement", {})

    SVG_CHILD_ELEMENTS_V("SVGFontFaceSrcElement",
                         {"SVGFontFaceNameElement",
                          "SVGFontFaceUriElement"})

    SVG_CHILD_ELEMENTS_V("SVGFontFaceUriElement",
                         {"SVGFontFaceFormatElement"})

    SVG_CHILD_ELEMENTS_V("SVGGElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGGElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGGElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGGElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGGElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGGElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGGlyphElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGGlyphElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGGlyphElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGGlyphElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGGlyphElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGGlyphElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGGlyphRefElement", {})

    SVG_CHILD_ELEMENTS_V("SVGHKernElement", {})

    /*
     SVG_CHILD_ELEMENTS_V("SVGHatchElement",
        {
            "SVGHatchpathElement"
            //script
        })
        SVG_CHILD_ELEMENTS_I("SVGHatchElement",svg_animation_elements)
        SVG_CHILD_ELEMENTS_I("SVGHatchElement",svg_descriptive_elements)

     SVG_CHILD_ELEMENTS("SVGHatchpathElement",svg_animation_elements)
        SVG_CHILD_ELEMENTS_I("SVGHatchpathElement",svg_descriptive_elements)
        */

    SVG_CHILD_ELEMENTS_V("SVGImageElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGImageElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGImageElement", svg_descriptive_elements)
    //SVG_CHILD_ELEMENTS_I("SVGImageElement",svg_paint_server_elements) //structurally external elements

    SVG_CHILD_ELEMENTS_V("SVGLineElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGLineElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGLineElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGLineElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGLinearGradientElement",
                         {
                             "SVGAnimateElement",
                             "SVGAnimateTransformElement",
                             "SVGSetElement",
                             "SVGStopElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGLinearGradientElement", svg_descriptive_elements)
    //SVG_CHILD_ELEMENTS_V("SVGLinearGradientElement",svg_paint_server_elements)

    SVG_CHILD_ELEMENTS("SVGMPathElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGMarkerElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGMarkerElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGMarkerElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGMarkerElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGMarkerElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGMarkerElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGMaskElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGMaskElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGMaskElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGMaskElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGMaskElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGMaskElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGMetadataElement", {})

    SVG_CHILD_ELEMENTS_V("SVGMissingGlyphElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGMissingGlyphElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGMissingGlyphElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGMissingGlyphElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGMissingGlyphElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGMissingGlyphElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGPathElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGPathElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGPathElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGPathElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGPatternElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGPatternElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGPatternElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGPatternElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGPatternElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGPatternElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGPolygonElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement",
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGPolygonElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGPolygonElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGPolygonElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGPolylineElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGPolylineElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGPolylineElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGPolylineElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGRadialGradientElement",
                         {"SVGAnimateElement",
                          "SVGAnimateTransformElement",
                          "SVGSetElement",
                          "SVGStopElement"})
    SVG_CHILD_ELEMENTS_I("SVGRadialGradientElement", svg_descriptive_elements)
    //SVG_CHILD_ELEMENTS_I("SVGRadialGradientElement",svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGRectElement",
                         {
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGRectElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGRectElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGRectElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGSVGElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGSVGElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGSVGElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGSVGElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGSVGElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGSVGElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS("SVGSetElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGStyleElement", {})

    /*
     SVG_CHILD_ELEMENTS_V("SVGSolidcolorElement",
        {
            "SVGAnimateElement",
            //"SVGAnimateColorElement",
            "SVGSetElement"
            //script
        })
        SVG_CHILD_ELEMENTS_I("SVGSolidcolorElement",svg_paint_server_elements)
    */

    SVG_CHILD_ELEMENTS_V("SVGStopElement",
                         {"SVGAnimateElement",
                          //"SVGAnimateColorElement",
                          "SVGSetElement"})

    SVG_CHILD_ELEMENTS_V("SVGSwitchElement",
                         {"SVGAElement",
                          "SVGClipPathElement",
                          "SVGForeignObjectElement",
                          "SVGGElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          //"SVGSVGElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGUseElement"})
    SVG_CHILD_ELEMENTS_I("SVGSwitchElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGSwitchElement", svg_descriptive_elements)
    //SVG_CHILD_ELEMENTS_I("SVGSwitchElement",svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGSwitchElement", svg_shape_elements)

    SVG_CHILD_ELEMENTS_V("SVGSymbolElement",
                         {"SVGAElement",
                          "SVGAltGlyphDefElement",
                          "SVGClipPathElement",
                          //"SVGColorProfileElement",
                          "SVGCursorElement",
                          "SVGFilterElement",
                          "SVGFontElement",
                          "SVGFontFaceElement",
                          "SVGForeignObjectElement",
                          "SVGImageElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          //"SVGScriptElement",
                          "SVGStyleElement",
                          "SVGSwitchElement",
                          "SVGTextElement",
                          "SVGViewElement"})
    SVG_CHILD_ELEMENTS_I("SVGSymbolElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGSymbolElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGSymbolElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGSymbolElement", svg_shape_elements)
    SVG_CHILD_ELEMENTS_I("SVGSymbolElement", svg_structural_elements)

    SVG_CHILD_ELEMENTS_V("SVGTRefElement",
                         {"SVGAnimateElement",
                          //"SVGAnimateColorElement",
                          "SVGSetElement"})
    SVG_CHILD_ELEMENTS_I("SVGTRefElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGTSpanElement",
                         {
                             "SVGAElement",
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement",
                             //script
                         })
    SVG_CHILD_ELEMENTS_I("SVGTSpanElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGTSpanElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGTSpanElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGTSpanElement", svg_text_content_child_elements)

    SVG_CHILD_ELEMENTS_V("SVGTextElement",
                         {
                             "SVGAElement",
                             "SVGClipPathElement",
                             "SVGMarkerElement",
                             "SVGMaskElement"
                             // script
                         })
    SVG_CHILD_ELEMENTS_I("SVGTextElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGTextElement", svg_descriptive_elements)
    SVG_CHILD_ELEMENTS_I("SVGTextElement", svg_paint_server_elements)
    SVG_CHILD_ELEMENTS_I("SVGTextElement", svg_text_content_child_elements)

    SVG_CHILD_ELEMENTS_V("SVGTextPathElement",
                         {"SVGAElement",
                          "SVGAltGlyphElement",
                          "SVGAnimateElement",
                          //"SVGAnimateColorElement",
                          "SVGClipPathElement",
                          "SVGMarkerElement",
                          "SVGMaskElement",
                          "SVGSetElement",
                          "SVGTRefElement",
                          "SVGTSpanElement"})
    SVG_CHILD_ELEMENTS_I("SVGTextPathElement", svg_paint_server_elements)

    SVG_CHILD_ELEMENTS_V("SVGTitleElement", {})

    SVG_CHILD_ELEMENTS_V("SVGVKernElement", {})

    SVG_CHILD_ELEMENTS("SVGViewElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGViewElement", svg_descriptive_elements)

    SVG_CHILD_ELEMENTS_V("SVGUseElement",
                         {
                             "SVGClipPathElement",
                             "SVGMaskElement"
                             //script
                             //style
                         })
    SVG_CHILD_ELEMENTS_I("SVGUseElement", svg_animation_elements)
    SVG_CHILD_ELEMENTS_I("SVGUseElement", svg_descriptive_elements)

    SVG_ANIMATABLE_ATTRIBUTES("alignment-baseline")
    SVG_ANIMATABLE_ATTRIBUTES("amplitude")
    SVG_ANIMATABLE_ATTRIBUTES("azimuth")
    SVG_ANIMATABLE_ATTRIBUTES("baseFrequency")
    SVG_ANIMATABLE_ATTRIBUTES("baseline-shift")
    SVG_ANIMATABLE_ATTRIBUTES("bias")
    SVG_ANIMATABLE_ATTRIBUTES("cap-height")
    SVG_ANIMATABLE_ATTRIBUTES("clip")
    SVG_ANIMATABLE_ATTRIBUTES("clip-path")
    SVG_ANIMATABLE_ATTRIBUTES("clip-rule")
    SVG_ANIMATABLE_ATTRIBUTES("clipPathUnits")
    SVG_ANIMATABLE_ATTRIBUTES("color")
    SVG_ANIMATABLE_ATTRIBUTES("color-interpolation")
    SVG_ANIMATABLE_ATTRIBUTES("color-interpolation-filters")
    SVG_ANIMATABLE_ATTRIBUTES("color-profile")
    SVG_ANIMATABLE_ATTRIBUTES("color-rendering")
    SVG_ANIMATABLE_ATTRIBUTES("cursor")
    SVG_ANIMATABLE_ATTRIBUTES("cx")
    SVG_ANIMATABLE_ATTRIBUTES("cy")
    SVG_ANIMATABLE_ATTRIBUTES("d")
    SVG_ANIMATABLE_ATTRIBUTES("diffuseConstant")
    SVG_ANIMATABLE_ATTRIBUTES("direction")
    SVG_ANIMATABLE_ATTRIBUTES("display")
    SVG_ANIMATABLE_ATTRIBUTES("divisor")
    SVG_ANIMATABLE_ATTRIBUTES("dominant-baseline")
    SVG_ANIMATABLE_ATTRIBUTES("dx")
    SVG_ANIMATABLE_ATTRIBUTES("dy")
    SVG_ANIMATABLE_ATTRIBUTES("edgeMode")
    SVG_ANIMATABLE_ATTRIBUTES("elevation")
    SVG_ANIMATABLE_ATTRIBUTES("exponent")
    SVG_ANIMATABLE_ATTRIBUTES("fill")
    SVG_ANIMATABLE_ATTRIBUTES("fill-opacity")
    SVG_ANIMATABLE_ATTRIBUTES("fill-rule")
    SVG_ANIMATABLE_ATTRIBUTES("filter")
    SVG_ANIMATABLE_ATTRIBUTES("filterPrimitiveUnits")
    SVG_ANIMATABLE_ATTRIBUTES("filterRes")
    SVG_ANIMATABLE_ATTRIBUTES("filterUnits")
    SVG_ANIMATABLE_ATTRIBUTES("flood-color")
    SVG_ANIMATABLE_ATTRIBUTES("flood-opacity")
    SVG_ANIMATABLE_ATTRIBUTES("font-family")
    SVG_ANIMATABLE_ATTRIBUTES("font-size")
    SVG_ANIMATABLE_ATTRIBUTES("font-size-adjust")
    SVG_ANIMATABLE_ATTRIBUTES("font-stretch")
    SVG_ANIMATABLE_ATTRIBUTES("font-style")
    SVG_ANIMATABLE_ATTRIBUTES("font-variant")
    SVG_ANIMATABLE_ATTRIBUTES("font-weight")
    SVG_ANIMATABLE_ATTRIBUTES("glyphRef")
    SVG_ANIMATABLE_ATTRIBUTES("gradientTransform")
    SVG_ANIMATABLE_ATTRIBUTES("gradientUnits")
    SVG_ANIMATABLE_ATTRIBUTES("hatchContentUnits")
    SVG_ANIMATABLE_ATTRIBUTES("hatchUnits")
    SVG_ANIMATABLE_ATTRIBUTES("height")
    SVG_ANIMATABLE_ATTRIBUTES("hreflang")
    SVG_ANIMATABLE_ATTRIBUTES("image-rendering")
    SVG_ANIMATABLE_ATTRIBUTES("in")
    SVG_ANIMATABLE_ATTRIBUTES("in2")
    SVG_ANIMATABLE_ATTRIBUTES("intercept")
    SVG_ANIMATABLE_ATTRIBUTES("k1")
    SVG_ANIMATABLE_ATTRIBUTES("k2")
    SVG_ANIMATABLE_ATTRIBUTES("k3")
    SVG_ANIMATABLE_ATTRIBUTES("k4")
    SVG_ANIMATABLE_ATTRIBUTES("kernelMatrix")
    SVG_ANIMATABLE_ATTRIBUTES("kernelUnitLength")
    SVG_ANIMATABLE_ATTRIBUTES("kerning")
    SVG_ANIMATABLE_ATTRIBUTES("lengthAdjust")
    SVG_ANIMATABLE_ATTRIBUTES("letter-spacing")
    SVG_ANIMATABLE_ATTRIBUTES("lighting-color")
    SVG_ANIMATABLE_ATTRIBUTES("limitingConeAngle")
    SVG_ANIMATABLE_ATTRIBUTES("marker-end")
    SVG_ANIMATABLE_ATTRIBUTES("marker-mid")
    SVG_ANIMATABLE_ATTRIBUTES("marker-start")
    SVG_ANIMATABLE_ATTRIBUTES("markerHeight")
    SVG_ANIMATABLE_ATTRIBUTES("markerUnits")
    SVG_ANIMATABLE_ATTRIBUTES("markerWidth")
    SVG_ANIMATABLE_ATTRIBUTES("mask")
    SVG_ANIMATABLE_ATTRIBUTES("maskContentUnits")
    SVG_ANIMATABLE_ATTRIBUTES("maskUnits")
    SVG_ANIMATABLE_ATTRIBUTES("method")
    SVG_ANIMATABLE_ATTRIBUTES("mode")
    SVG_ANIMATABLE_ATTRIBUTES("name")
    SVG_ANIMATABLE_ATTRIBUTES("numOctaves")
    SVG_ANIMATABLE_ATTRIBUTES("offset")
    SVG_ANIMATABLE_ATTRIBUTES("opacity")
    SVG_ANIMATABLE_ATTRIBUTES("operator")
    SVG_ANIMATABLE_ATTRIBUTES("order")
    SVG_ANIMATABLE_ATTRIBUTES("orient")
    SVG_ANIMATABLE_ATTRIBUTES("orientation")
    SVG_ANIMATABLE_ATTRIBUTES("overflow")
    SVG_ANIMATABLE_ATTRIBUTES("pathLength")
    SVG_ANIMATABLE_ATTRIBUTES("patternContentUnits")
    SVG_ANIMATABLE_ATTRIBUTES("patternTransform")
    SVG_ANIMATABLE_ATTRIBUTES("patternUnits")
    SVG_ANIMATABLE_ATTRIBUTES("pitch")
    SVG_ANIMATABLE_ATTRIBUTES("pointer-events")
    SVG_ANIMATABLE_ATTRIBUTES("points")
    SVG_ANIMATABLE_ATTRIBUTES("pointsAtX")
    SVG_ANIMATABLE_ATTRIBUTES("pointsAtY")
    SVG_ANIMATABLE_ATTRIBUTES("pointsAtZ")
    SVG_ANIMATABLE_ATTRIBUTES("preserveAlpha")
    SVG_ANIMATABLE_ATTRIBUTES("preserveAspectRatio")
    SVG_ANIMATABLE_ATTRIBUTES("primitiveUnits")
    SVG_ANIMATABLE_ATTRIBUTES("r")
    SVG_ANIMATABLE_ATTRIBUTES("radius")
    SVG_ANIMATABLE_ATTRIBUTES("refX")
    SVG_ANIMATABLE_ATTRIBUTES("refY")
    SVG_ANIMATABLE_ATTRIBUTES("rendering-intent")
    SVG_ANIMATABLE_ATTRIBUTES("result")
    SVG_ANIMATABLE_ATTRIBUTES("rx")
    SVG_ANIMATABLE_ATTRIBUTES("ry")
    SVG_ANIMATABLE_ATTRIBUTES("scale")
    SVG_ANIMATABLE_ATTRIBUTES("seed")
    SVG_ANIMATABLE_ATTRIBUTES("shape-rendering")
    SVG_ANIMATABLE_ATTRIBUTES("side")
    SVG_ANIMATABLE_ATTRIBUTES("slope")
    SVG_ANIMATABLE_ATTRIBUTES("solid-color")
    SVG_ANIMATABLE_ATTRIBUTES("solid-opacity")
    SVG_ANIMATABLE_ATTRIBUTES("spacing")
    SVG_ANIMATABLE_ATTRIBUTES("specularConstant")
    SVG_ANIMATABLE_ATTRIBUTES("specularExponent")
    SVG_ANIMATABLE_ATTRIBUTES("spreadMethod")
    SVG_ANIMATABLE_ATTRIBUTES("startOffset")
    SVG_ANIMATABLE_ATTRIBUTES("stdDeviation")
    SVG_ANIMATABLE_ATTRIBUTES("stitchTiles")
    SVG_ANIMATABLE_ATTRIBUTES("stop-color")
    SVG_ANIMATABLE_ATTRIBUTES("stop-opacity")
    SVG_ANIMATABLE_ATTRIBUTES("stroke")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-dasharray")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-dashoffset")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-linecap")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-linejoin")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-miterlimit")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-opacity")
    SVG_ANIMATABLE_ATTRIBUTES("stroke-width")
    SVG_ANIMATABLE_ATTRIBUTES("surfaceScale")
    SVG_ANIMATABLE_ATTRIBUTES("tableValues")
    SVG_ANIMATABLE_ATTRIBUTES("target")
    SVG_ANIMATABLE_ATTRIBUTES("targetX")
    SVG_ANIMATABLE_ATTRIBUTES("targetY")
    SVG_ANIMATABLE_ATTRIBUTES("text-anchor")
    SVG_ANIMATABLE_ATTRIBUTES("text-decoration")
    SVG_ANIMATABLE_ATTRIBUTES("text-rendering")
    SVG_ANIMATABLE_ATTRIBUTES("textLength")
    SVG_ANIMATABLE_ATTRIBUTES("transform")
    SVG_ANIMATABLE_ATTRIBUTES("type")
    SVG_ANIMATABLE_ATTRIBUTES("vector-effect")
    SVG_ANIMATABLE_ATTRIBUTES("viewBox")
    SVG_ANIMATABLE_ATTRIBUTES("visibility")
    SVG_ANIMATABLE_ATTRIBUTES("width")
    SVG_ANIMATABLE_ATTRIBUTES("word-spacing")
    SVG_ANIMATABLE_ATTRIBUTES("writing-mode")
    SVG_ANIMATABLE_ATTRIBUTES("x")
    SVG_ANIMATABLE_ATTRIBUTES("x1")
    SVG_ANIMATABLE_ATTRIBUTES("x2")
    SVG_ANIMATABLE_ATTRIBUTES("xChannelSelector")
    SVG_ANIMATABLE_ATTRIBUTES("y")
    SVG_ANIMATABLE_ATTRIBUTES("y1")
    SVG_ANIMATABLE_ATTRIBUTES("y2")
    SVG_ANIMATABLE_ATTRIBUTES("yChannelSelector")
    SVG_ANIMATABLE_ATTRIBUTES("z")

    /*
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("fill")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("stroke")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("color")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("stop-color")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("flood-color")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("lighting-color")
    SVG_ANIMATABLE_COLOR_ATTRIBUTES("solid-color"
*/

    SVG_ANIMATABLE_TRANSFORM_ATTRIBUTES("transform")
    SVG_ANIMATABLE_TRANSFORM_ATTRIBUTES("gradientTransform")
    SVG_ANIMATABLE_TRANSFORM_ATTRIBUTES("patternTransform")

    SVG_ANIMATION_BEGIN_EVENTS("focus")
    SVG_ANIMATION_BEGIN_EVENTS("blur")
    SVG_ANIMATION_BEGIN_EVENTS("focusin")
    SVG_ANIMATION_BEGIN_EVENTS("focusout")
    SVG_ANIMATION_BEGIN_EVENTS("activate")
    SVG_ANIMATION_BEGIN_EVENTS("click")
    /*SVG_ANIMATION_BEGIN_EVENTS("beforeinput")
      SVG_ANIMATION_BEGIN_EVENTS("input")
      SVG_ANIMATION_BEGIN_EVENTS("keydown")
      SVG_ANIMATION_BEGIN_EVENTS("keyup")
      SVG_ANIMATION_BEGIN_EVENTS("compositionstart")
      SVG_ANIMATION_BEGIN_EVENTS("compositionupdate")
      SVG_ANIMATION_BEGIN_EVENTS("compositionend")*/
    SVG_ANIMATION_BEGIN_EVENTS("load")
    //SVG_ANIMATION_BEGIN_EVENTS("unload")
    // SVG_ANIMATION_BEGIN_EVENTS("abort")
    // SVG_ANIMATION_BEGIN_EVENTS("error")
    SVG_ANIMATION_BEGIN_EVENTS("select")
    // SVG_ANIMATION_BEGIN_EVENTS("resize")
    SVG_ANIMATION_BEGIN_EVENTS("scroll")
    // SVG_ANIMATION_BEGIN_EVENTS("beginEvent")
    // SVG_ANIMATION_BEGIN_EVENTS("endEvent")
    // SVG_ANIMATION_BEGIN_EVENTS("repeatEvent"

    SVG_ARIABLE_ELEMENTS("SVGAElement")
    SVG_ARIABLE_ELEMENTS("SVGCircleElement")
    SVG_ARIABLE_ELEMENTS("SVGCursorElement")
    SVG_ARIABLE_ELEMENTS("SVGDiscardElement")
    SVG_ARIABLE_ELEMENTS("SVGEllipseElement")
    SVG_ARIABLE_ELEMENTS("SVGForeignObjectElement")
    SVG_ARIABLE_ELEMENTS("SVGGElement")
    SVG_ARIABLE_ELEMENTS("SVGImageElement")
    SVG_ARIABLE_ELEMENTS("SVGLineElement")
    SVG_ARIABLE_ELEMENTS("SVGPathElement")
    SVG_ARIABLE_ELEMENTS("SVGPolygonElement")
    SVG_ARIABLE_ELEMENTS("SVGPolylineElement")
    SVG_ARIABLE_ELEMENTS("SVGRectElement")
    SVG_ARIABLE_ELEMENTS("SVGSVGElement")
    SVG_ARIABLE_ELEMENTS("SVGSwitchElement")
    SVG_ARIABLE_ELEMENTS("SVGSymbolElement")
    SVG_ARIABLE_ELEMENTS("SVGTSpanElement")
    SVG_ARIABLE_ELEMENTS("SVGTextElement")
    SVG_ARIABLE_ELEMENTS("SVGTextPathElement")
    SVG_ARIABLE_ELEMENTS("SVGViewElement")
}