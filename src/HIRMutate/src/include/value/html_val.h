#ifndef HM_HTML_VALUE_H
#define HM_HTML_VALUE_H

#include "Value.h"
#include "random.h"
#include "DomValue.h"
#include "object.h"
#include "docs.h"

using HIRMutate::VALUE::ConstValue;
using HIRMutate::VALUE::DynamicValue;
using HIRMutate::VALUE::StaticValue;

namespace HIRMutate
{
    namespace HTML
    {
        /*
* Static values
*/
        class ShapeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CoordsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        // <image>.href
        class ImageSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LangValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ReferrerPolicyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AcceptValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PreloadValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class VideoSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AudioSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FrameSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class SoundLoopValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class AutoCapitalizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class ButtonTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CaptionAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class VAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CommandTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class TrackSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MediaSrcValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class ImportanceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LoadingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class DirValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class DropZoneValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class InputModeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
        class FormEncTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class FormMethodValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ObjectAlignValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SizesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ScrollingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ImageDecodingValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class IntrinsicSizeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class InputTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AutoCompleteValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class InputCaptureValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class KeyTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class NumberingTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LinkAsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RelValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RevValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MarqueeBehaviorValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MarqueeDirectionValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MarqueeLoopValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MenuItemTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MetaSchemeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MenuTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ParamValueTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class WrapValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SrcSetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableFrameValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableRulesValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableScopeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TrackKindValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class UListTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class VideoControlsListValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TabIndexValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CharsetValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ClearValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        //ARIA
        class AriaAutocompleteValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaCheckedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaCurrentValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaDropeffectValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaExpandedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaGrabbedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaHaspopupValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaHiddenValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaInvalidValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaLabelValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaLiveValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaOrientationValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaPressedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaRelevantValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaSelectedValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AriaSortValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RoleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class DateTimeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ClassValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class PartValue : public StaticValue
        {
        public:
            void *getConstructor();
            //FIXME : multiple part names
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RadioGroupValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class TableAxisValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MediaTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CSSTypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MIMETypeValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class MediaQueryValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class NonceValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        /*
        *Dynamic values
        */
        class SlotValue : public DynamicValue
        {
        private:
            Object *slot;

        public:
            SlotValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UseMapValue : public DynamicValue
        {
        private:
            Object *umap;

        public:
            UseMapValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DummyUrlValue : public ConstValue
        {
        public:
            DummyUrlValue();
            void *getConstructor();
        };
        inline DummyUrlValue::DummyUrlValue() : ConstValue("x")
        {
        }
        class ElementIDValue : public DynamicValue
        {
        private:
            Object *elem;

        public:
            ElementIDValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class EventHandlerValue : public DynamicValue
        {
        private:
            Object *eh;

        public:
            EventHandlerValue();
            void *getConstructor();
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CallEventHandlerValue : public DynamicValue
        {
        private:
            Object *eh;

        public:
            CallEventHandlerValue();
            void *getConstructor();
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ContextMenuValue : public DynamicValue
        {
        private:
            Object *menu;

        public:
            ContextMenuValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FormValue : public DynamicValue
        {
        private:
            Object *form;

        public:
            FormValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ContentSelectValue : public DynamicValue
        {
        private:
            string cla;
            Object *elem;

        public:
            ContentSelectValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ListValue : public DynamicValue
        {
        private:
            Object *dl;

        public:
            ListValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class LabelForValue : public DynamicValue
        {
        private:
            Object *elem;

        public:
            LabelForValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class CommandValue : public DynamicValue
        {
        private:
            Object *command;

        public:
            CommandValue();
            void *getConstructor();
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ElementIDListValue : public DynamicValue
        {
        private:
            vector<Object *> elements;

        public:
            ElementIDListValue();
            void *getConstructor();
            void append_element(Context *context);
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableHeadersValue : public DynamicValue
        {
        private:
            vector<Object *> ths;

        public:
            TableHeadersValue();
            void *getConstructor();
            void append_th(Context *context);
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class TargetValue : public DynamicValue
        {
        private:
            Object *frame;

        public:
            TargetValue();
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