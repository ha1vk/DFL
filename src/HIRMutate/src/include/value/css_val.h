#ifndef HM_CSS_VALUE_H
#define HM_CSS_VALUE_H

#include <string>
#include "Random.h"
#include "DomValue.h"
#include "Value.h"
#include "docs.h"
#include "Context.h"

using HIRMutate::VALUE::DynamicValue;
using HIRMutate::VALUE::StaticValue;
using std::string;

namespace HIRMutate
{
    namespace CSS
    {
        string cat(vector<string> &values);
        /*
        * CSS value generators
        */
        string geometry_box();

        string shape_box();

        string blur();

        string brightness();

        string contrast();

        string drop_shadow();
        string grayscale();

        string hue_rotate();

        string invert();

        string opacity();

        string saturate();
        string sepia();

        string filter_function();

        string alpha();

        string repeat();
        string step_position();

        string step_timing_function();

        string line_width();

        string line_height();
        string line_style();

        string side_or_corner();
        string linear_color_stop();
        string angular_color_stop();
        string color_stop_list();
        string angular_color_stop_list();

        string _linear_gradient();

        string linear_gradient();

        string repeating_linear_gradient();

        string ending_shape();
        string radial_gradient_size();

        string _radial_gradient();

        string radial_gradient();

        string repeating_radial_gradient();

        string conic_gradient();
        string image();
        string column_width();

        string column_count();

        string flex_basis();

        string quote();

        string leader();

        string flex_direction();

        string flex_wrap();
        string flex();

        string track_breadth();

        string inflexible_breadth();

        string track_size();

        // TODO: > 1
        string track_repeat();

        // TODO: > 1
        string fixed_repeat();

        string auto_repeat();

        string fixed_size();

        string track();

        string fixed();

        string track_list();

        string auto_track_list();

        string explicit_track_list();

        string baseline_position();

        string overflow_position();
        string self_position();
        string location();

        string basic_shape();

        /*
* CSS variables
*/
        class CSSColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *content);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CSSLineWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CSSLengthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CSSLengthPercentageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        /*
* Static CSS values
*/
        class ColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LineWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ImageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RadiusValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LineStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LocationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class BottomValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //opacity
        class OpacityValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-app-region
        class WebkitAppRegionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //appearance
        class AppearanceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-color-correction
        class WebkitColorCorrectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-flow-from
        class WebkitFlowFromValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-flow-into
        class WebkitFlowIntoValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-font-smoothing
        class WebkitFontSmoothingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-hyphenate-character
        class WebkitHyphenateCharacterValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string webkit_margin_collapse();

        //-webkit-margin-after-collapse
        class WebkitMarginAfterCollapseValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-margin-collapse
        class WebkitMarginCollapseValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-marquee-speed
        class WebkitMarqueeSpeedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-mask-box-image
        class WebkitMaskBoxImageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // mask
        string mask_repeat_style();
        string mask_composite();

        string mask_mode();
        string mask_clip();
        string mask_position();

        //mask-clip
        class MaskClipValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-composite
        class MaskCompositeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-origin
        class MaskOriginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-position
        class MaskPositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-repeat
        class MaskRepeatValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-source-type
        class MaskSourceTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-mask-repeat-x/y
        class WebkitMaskRepeatXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //mask-size
        class MaskSizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-nbsp-mode
        class WebkitNbspModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-overflow-scrolling
        class WebkitOverflowScrollingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-print-color-adjust
        class WebkitPrintColorAdjustValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-rtl-ordering
        class WebkitRtlOrderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-ruby-position
        class WebkitRubyPositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-text-combine
        class WebkitTextCombineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string text_emphasis_style();

        //text-emphasis
        class TextEmphasisValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //text-emphasis-position
        class TextEmphasisPositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //text-emphasis-style
        class TextEmphasisStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-text-security
        class WebkitTextSecurityValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-text-stroke
        class WebkitTextStrokeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-text-stroke-color
        class WebkitTextStrokeColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-text-stroke-width
        class WebkitTextStrokeWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-user-drag
        class WebkitUserDragValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-user-modify
        class WebkitUserModifyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //-webkit-wrap-flow
        class WebkitWrapFlowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // align-content
        class AlignContentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //align-items
        class AlignItemsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //align-self
        class AlignSelfValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // all
        class AllValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string animation_name(Context *context);

        string animation_duration();

        string single0();
        string animation_timing_function();

        string animation_delay();
        string animation_direction();

        string animation_iteration_count();
        string animation_fill_mode();
        //animation-delay
        class AnimationDelayValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-direction
        class AnimationDirectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-duration
        class AnimationDurationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-fill-mode
        class AnimationFillModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-iteration-count
        class AnimationIterationCountValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-play-state
        class AnimationPlayStateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //animation-timing-function
        class AnimationTimingFunctionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //backface-visibility
        class BackfaceVisibilityValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string background_clip();

        string background_origin();

        string single1();

        string background_size();

        string background_attachment();
        string background_repeat();

        string background_position();

        //background
        class BackgroundValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-attachment
        class BackgroundAttachmentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string blend_mode();
        //mode / mix-blend-mode in SVG
        class BlendModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-blend-mode
        class BackgroundBlendModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-clip
        class BackgroundClipValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-origin
        class BackgroundOriginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-position
        class BackgroundPositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-position-x
        class BackgroundPositionXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-position-y
        class BackgroundPositionYValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-repeat
        class BackgroundRepeatValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-repeat-x
        class BackgroundRepeatXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //background-size
        class BackgroundSizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string border_style();

        string border_color();

        //border / column-rule
        class BorderValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        //border-bottom
        class LineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // border-collapse
        class BorderCollapseValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string border_image_slice();

        string border_image_width();

        string border_image_outset();

        string border_image_repeat();

        //border-image
        class BorderImageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-image-outset
        class BorderImageOutsetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-image-repeat
        class BorderImageRepeatValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-image-slice
        class BorderImageSliceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-image-width
        class BorderImageWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-radius
        class BorderRadiusValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-spacing
        class BorderSpacingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // border-style
        class BorderStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //border-width
        class BorderWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-align
        class BoxAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-decoration-break
        class BoxDecorationBreakValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //box-direction
        class BoxDirectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-lines
        class BoxLinesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-orient
        class BoxOrientValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-pack
        class BoxPackValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //box-reflect
        class BoxReflectValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-shadow
        class BoxShadowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // box-sizing
        class BoxSizingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // page
        class PageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // break-after
        class BreakValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // break-inside
        class BreakInsideValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // caption-side
        class CaptionSideValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // clear
        class ClearValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // clip
        class ClipValue : public StaticValue
        {
        private:
            string edge();

        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-break-after
        class ColumnBreakAfterValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-count
        class ColumnCountValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-fill
        class ColumnFillValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-gap
        class ColumnGapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-span
        class ColumnSpanValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // column-width
        class ColumnWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //columns
        class ColumnsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // contain
        class ContainValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // content
        class ContentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string cursor_fallback();

        // direction
        class DirectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // display
        class DisplayValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // empty-cells
        class EmptyCellsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // flex
        class FlexValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //flex-basis
        class FlexBasisValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // flex-direction
        class FlexDirectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // flex-flow
        class FlexFlowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // flex-wrap
        class FlexWrapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // float
        class FloatValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string font_style();

        string font_size();

        string font_family();

        // font
        class FontValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-family
        class FontFamilyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-feature-settings
        class FontFeatureSettingsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-smooth
        class FontSmoothValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-kerning
        class FontKerningValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-size
        class FontSizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-size-adjust
        class FontSizeAdjustValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-stretch
        class FontStretchValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-style
        class FontStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-variant
        class FontVariantValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-variant-caps
        class FontVariantCapsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-variant-ligatures
        class FontVariantLigaturesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-weight
        class FontWeightValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string grid_template_rows();

        string grid_template();
        string grid_auto_rows();

        // grid
        class GridValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string grid_line();

        // grid-area
        class GridAreaValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-auto-rows, columns
        class GridAutoRowsColumnsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-auto-flow
        class GridAutoFlowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-row, column
        // TODO: custom-ident
        class GridRowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-column-end
        class GridLineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-column-gap
        class GridLineGapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-gap
        class GridGapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-template
        class GridTemplateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-template-areas
        class GridTemplateAreasValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // grid-template-columns
        class GridTemplateRowsColumnsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // height / width
        class HeightValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // hyphens
        class HyphensValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //image-orientation
        class ImageOrientationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // image-rendering
        class ImageRenderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // isolation
        class IsolationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // justify-content
        class JustifyContentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // justify-items
        class JustifyItemsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //justify-self
        class JustifySelfValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // kerning
        class KerningValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //letter-spacing
        class LetterSpacingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // line-break
        class LineBreakValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class WebKitLocaleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //line-height
        class LineHeightValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string list_style_image();

        string list_style_type();

        string list_style_position();

        // list-style
        class ListStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //list-style-image
        class ListStyleImageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // list-style-position
        class ListStylePositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //list-style-type
        class ListStyleTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // margin
        class MarginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //max-zoom
        class MaxZoomValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // object-fit
        class ObjectFitValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string offset_rotate();

        string offset_anchor();

        //offset-anchor
        class OffsetAnchorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // offset-position
        class OffsetPositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // offset-rotate/ion
        class OffsetRotateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string outline_color();

        string outline_style();

        // outline
        class OutlineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //outline-color
        class OutlineColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // outline-style
        class OutlineStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string overflow();

        //overflow
        class OverflowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // overflow-anchor
        class OverflowAnchorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //overflow-wrap
        class OverflowWrapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //overflow-x
        class OverflowXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //padding
        class PaddingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //perspective
        class PerspectiveValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // perspective-origin
        class PerspectiveOriginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // pointer-events
        class PointerEventsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // position
        class PositionWayValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // prince-hyphens
        class PrinceHyphensValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // quotes
        class QuotesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //resize
        class ResizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // rotate
        class RotateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        // scale
        class ScaleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-behavior
        class ScrollBehaviorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-snap-coordinate
        class ScrollSnapCoordinateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-snap-points-x
        class ScrollSnapPointsXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-snap-type
        class ScrollSnapTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // shape-image-threshold
        class ShapeImageThresholdValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // shape-outside
        class ShapeOutsideValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // table-layout
        class TableLayoutValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-align
        class TextAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-align-last
        class TextAlignLastValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-combine-upright
        class TextCombineUprightValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string text_decoration_line();

        string text_decoration_style();
        string text_decoration_thickness();

        //text-decoration
        class TextDecorationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-decoration-line
        class TextDecorationLineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-decoration-skip
        class TextDecorationSkipValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //text-decoration-style
        class TextDecorationStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-decoration-thickness
        class TextDecorationThicknessValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-indent
        class TextIndentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-justify
        class TextJustifyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-orientation
        class TextOrientationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-overflow
        class TextOverflowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-rendering
        class TextRenderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //text-shadow
        class TextShadowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-transform
        class TextTransformValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string text_underline_position();
        string text_underline_mode();

        string text_underline_style();

        string text_underline_width();

        // text-underline
        class TextUnderlineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-underline-mode
        class TextUnderlineModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-underline-style
        class TextUnderlineStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-underline-width
        class TextUnderlineWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-underline-offset
        class TextUnderlineOffsetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // text-underline-position
        class TextUnderlinePositionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // touch-action
        class TouchActionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string css_transform();
        // transform
        class TransformValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // transform-origin
        class TransformOriginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // transform-style
        class TransformStyleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string transition_property();

        string transition();

        // transition
        class TransitionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // transition-property
        class TransitionPropertyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // transition-timing-function
        class TransitionTimingFunctionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // translate
        class TranslateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // unicode-bidi
        class UnicodeBidiValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // user-select
        class UserSelectValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // user-zoom
        class UserZoomValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // vertical-align
        class VerticalAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // visibility
        class VisibilityValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // white-space
        class WhiteSpaceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // will-change
        class WillChangeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // word-break
        class WordBreakValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        //word-spacing
        class WordSpacingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // writing-mode
        class WritingModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // z-index
        class ZIndexValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // zoom
        class ZoomValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // -webkit-text-decorations-in-effect
        class WebkitTextDecorationInEffectValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //caret-color
        class CaretColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // font-variation-settings
        class FontVariationSettingsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // inset
        class InsetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // inset-block
        class InsetBlockValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // inset-inline
        class InsetInlineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // mask-border (border-image)
        class MaskBorderValue : public StaticValue
        {
        public:
            void *getConstructor();
            static string mask_border_mode();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MaskBorderModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-margin
        class ScrollMarginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-margin-block
        class ScrollMarginBlockValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-margin-inline
        class ScrollMarginInlineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string single_scroll_padding();

        // scroll-padding
        class ScrollPaddingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-padding-block
        class ScrollPaddingBlockValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-padding-block-start/end
        // scroll-padding-inline-start/end
        // scroll-padding-bottom/top/left/right
        class ScrollPaddingLineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scroll-padding-inline
        class ScrollPaddingInlineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // scrollbar-color
        class ScrollbarColorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // animation: https://developer.mozilla.org/en-US/docs/Web/CSS/animation
        class AnimationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // animation-name
        class AnimationNameValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //counter - increment
        class CounterIncrementValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CursorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        /*
    * Dynamic CSS values
    */
        class ClipPathValue : public DynamicValue
        {
        private:
            Object *clip_path;
            void generate_dynamic(Context *context);
            void generate_static();

        public:
            ClipPathValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class OffsetValue : public DynamicValue
        {
        private:
            Object *path;
            string path_value;
            string position;
            string distance;
            string rotate;
            string anchor;
            void generate_static_path();
            void generate_dynamic_path(Context *context);
            void generate_path(Context *context);
            void generate_position();
            void generate_distance();
            void generate_rotate();
            string generate_anchor();

        public:
            OffsetValue();
            void *getConstructor();
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        // offset-path
        class OffsetPathValue : public DynamicValue
        {
        private:
            Object *path;
            void generate_static();
            void generate_dynamic(Context *context);

        public:
            OffsetPathValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        // filter
        class FilterValue : public DynamicValue
        {
        private:
            Object *filter;
            string filter_value;
            void generate_static();
            void generate_dynamic(Context *context);

        public:
            FilterValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MaskValue : public DynamicValue
        {
        private:
            Object *mask;
            string image_value;
            string position;
            string repeat;
            string origin;
            string clip;
            string composite;
            string mode;

            void generate_mask_static();
            void generate_mask_dynamic(Context *context);
            void generate_mask(Context *context);
            void generate_position();
            void generate_repeat();
            void generate_origin();
            void generate_clip();
            void generate_composite();
            void generate_mode();

        public:
            MaskValue();
            void *getConstructor();
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        // mask-image
        class MaskImageValue : public DynamicValue
        {
        private:
            Object *mask;
            string image_value;
            void generate_static();
            void generate_dynamic(Context *context);

        public:
            MaskImageValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif