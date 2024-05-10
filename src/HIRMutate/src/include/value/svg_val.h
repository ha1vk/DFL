#ifndef HM_SVG_VALUE_H
#define HM_SVG_VALUE_H

#include <string>
#include "random.h"
#include "DomValue.h"
#include "Value.h"
#include "docs.h"
#include "Context.h"

using HIRMutate::VALUE::ConstValue;
using HIRMutate::VALUE::DynamicValue;
using HIRMutate::VALUE::StaticValue;
using HIRMutate::VALUE::Value;
using std::string;

namespace HIRMutate
{
    namespace SVG
    {
        /*
    * SVG value generators
    */
        string coordinate();

        string points();

        /*
        * SVG static values
        */
        class XMLNSValue : public ConstValue
        {
        public:
            XMLNSValue() : ConstValue("http://www.w3.org/2000/svg")
            {
            }
            void *getConstructor();
        };
        // SVG Presentation Attributes
        class AlignmentBaselineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ClipRuleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ColorInterpolationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RenderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class EnableBackgroundValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class GlyphRefValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class UValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class UnicodeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //glyph-orientation-vertical
        class GlyphOrientationVerticalValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class NameValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OffsetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OverflowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeMorphologyOperatorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeCompositeOperatorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OrderValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PointerEventsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ShapeRenderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AnimateFillValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class StrokeDasharrayValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class StrokeLinecapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class StrokeLinejoinValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TextAnchorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class VectorEffectValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class WordSpacingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FilterDxValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class DxValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FormatValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AutoWidthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class BBoxValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OrientValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PanoseValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PointsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PreserveAspectRatioValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        // FIXME: SVG 1.1 only
        class MarkerRefXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //FIXME: SVG 1.1 only
        class SymbolRefXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableValuesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class UnicodeRangeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ViewBoxValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AltGlyphXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TextXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SpacingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MethodValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SideValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class UnitsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OrientationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AltValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ArabicFormValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class BaseProfileValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class EdgeModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LengthAdjustValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MarkerUnitsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SpreadMethodValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class StitchTilesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RenderingIntentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RGBAValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ZoomAndPanValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class DurValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RestartValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RepeatCountValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class AdditiveValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AccumulateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CalcModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RotateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AnimateTransformTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeColorMatrixTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeFuncTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeTurbulenceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //type = "translate"
        class TransformTranslateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //type = "scale"
        class TransformScaleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //type = "rotate"
        class TransformRotateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //type = "skewX" / "skewY"
        class TransformSkewXValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CoordinateValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PathValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class BufferedRenderingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //baseline-shift
        class BaselineShiftValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //color-interpolation-filters
        class ColorInterpolationFiltersValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //color-profile
        class ColorProfileValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //dominant-baseline
        class DominantBaselineValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //fill-rule
        class FillRuleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //kerning
        class KerningValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PaintOrderValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ImageHrefValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class WhiteSpaceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TextOverflowValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CrossoriginValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        string svg_transform();

        class TransformValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class KeySplinesValue : public StaticValue
        {
        private:
            int value_count;

        public:
            KeySplinesValue() {}
            KeySplinesValue(int value_count);
            string control_point();
            //TODO : maybe need fix
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class KeyPointsValue : public StaticValue
        {
        private:
            int value_count;

        public:
            KeyPointsValue() {}
            KeyPointsValue(int value_count);
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class KeyTimesValue : public StaticValue
        {
        private:
            int value_count;

        public:
            KeyTimesValue() {}
            KeyTimesValue(int value_count);
            string linear_time_list(int num);

            string discrete_time_list(int num);

            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class KernelMatrixValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FeColorMatrixValuesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        /*
* Dynamic values
*/
        class SVGElementIDValue : public DynamicValue
        {
        private:
            Object *elem;

        public:
            SVGElementIDValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FillValue : public DynamicValue
        {
        private:
            string fill_value;
            Object *paint_server;
            string color;

        public:
            FillValue();
            void *getConstructor();
            void generate_static();
            void generate_dynamic(Context *context);
            void generate(Context *context);

            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class BeginValue : public DynamicValue
        {
        private:
            string abs;
            Object *elem;
            string action;
            string repeat_num;
            string event;

        public:
            BeginValue();
            void *getConstructor();
            void generate_abs();

            void generate_rel1(Context *context);
            void generate_rel2(Context *context);

            void generate(Context *context);

            void merge_fix(map<Object *, Object *> &merge_map);

            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        //marker-start/mid/end
        class MarkerValue : public DynamicValue
        {
        private:
            Object *marker;

        public:
            MarkerValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class PatternHrefValue : public DynamicValue
        {
        private:
            Object *pattern;

        public:
            PatternHrefValue();
            void *getConstructor();
            void generate(Context *context);

            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class FeImageHrefValue : public DynamicValue
        {
        private:
            Object *image;

        public:
            FeImageHrefValue();
            void *getConstructor();
            void generate_static();
            void generate_dynamic(Context *context);
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UseHrefValue : public DynamicValue
        {
        private:
            Object *elem;

        public:
            UseHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class GradientHrefValue : public DynamicValue
        {
        private:
            Object *gradient;

        public:
            GradientHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class PathHrefValue : public DynamicValue
        {
        private:
            Object *path;

        public:
            PathHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CursorHrefValue : public DynamicValue
        {
        private:
            Object *image;

        public:
            CursorHrefValue();
            void *getConstructor();
            void generate_static();
            void generate_dynamic(Context *context);
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TRefXlinkHrefValue : public DynamicValue
        {
        private:
            Object *text;

        public:
            TRefXlinkHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class GlyphRefXlinkHrefValue : public DynamicValue
        {
        private:
            Object *glyph;

        public:
            GlyphRefXlinkHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AltGlyphXlinkHrefValue : public DynamicValue
        {
        private:
            Object *glyph;

        public:
            AltGlyphXlinkHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontFaceUriXlinkHrefValue : public DynamicValue
        {
        private:
            Object *font;

        public:
            FontFaceUriXlinkHrefValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class GValue : public DynamicValue
        {
        private:
            Object *glyph;

        public:
            GValue();
            void generate(Context *context);
            void *getConstructor();
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InValue : public DynamicValue
        {
        private:
            Object *filter_primitive;

        public:
            InValue();
            void *getConstructor();
            void generate_static();
            void generate_dynamic(Context *context);
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        /*
* Animation values
*/
        class FromValue : public DynamicValue
        {
        private:
            Value *(*value_class)(void);
            Value *value_obj;

        public:
            FromValue() {}
            FromValue(Value *(*value_class)(void));
            ~FromValue();
            void *getConstructor() { return nullptr; }
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AnimationValuesValue : public DynamicValue
        {
        private:
            Value *(*value_class)(void);
            int value_count;
            vector<Value *> value_objs;

        public:
            AnimationValuesValue() {}
            AnimationValuesValue(Value *(*value_class)(void), int value_count);
            ~AnimationValuesValue();
            void *getConstructor() { return nullptr; }
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif