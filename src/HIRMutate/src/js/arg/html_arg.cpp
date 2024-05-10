#include "html_arg.h"
#include "DomValue.h"
#include "object.h"
#include "serialize_variables.h"

void HIRMutate::JS::ShadowRootInitArg::generate(JSContext *context)
{
    static const char *strs[] = {"open", "closed"};
    value = "{mode: \"";
    value.append(CHOICE(strs));
    value.append("\", delegatesFocus: ");
    value.append(DOMValue::boolean());
    value.append("}");
}

void HIRMutate::JS::ShadowRootInitArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ShadowRootInitArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::ShadowRootInitArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MutationObserverInitArg::generate(JSContext *context)
{
    value = "{ attributeOldValue: ";
    value.append(DOMValue::boolean());
    value.append(", attributes: ");
    value.append(DOMValue::boolean());
    value.append(", characterData: ");
    value.append(DOMValue::boolean());
    value.append(", characterDataOldValue: ");
    value.append(DOMValue::boolean());
    value.append(", childList: ");
    value.append(DOMValue::boolean());
    value.append(", subtree: ");
    value.append(DOMValue::boolean());
    value.append("}");
}

void HIRMutate::JS::MutationObserverInitArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MutationObserverInitArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::MutationObserverInitArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ScrollToOptionsArg::generate(JSContext *context)
{
    static const char *strs[] = {"auto", "smooth"};
    value = "{ top: ";
    value.append(Random::number());
    value.append(", left: ");
    value.append(Random::number());
    value.append(", behavior: \"");
    value.append(CHOICE(strs));
    value.append("\"}");
}

void HIRMutate::JS::ScrollToOptionsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ScrollToOptionsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::ScrollToOptionsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ScrollIntoViewOptionsArg::generate(JSContext *context)
{
    static const char *strs0[] = {"auto", "smooth"};
    static const char *strs1[] = {"start", "center", "end", "nearest"};
    value = "{behavior: \"";
    value.append(CHOICE(strs0));
    value.append("\", block: \"");
    value.append(CHOICE(strs1));
    value.append("\", inline: \"");
    value.append(CHOICE(strs1));
    value.append("\"}");
}

void HIRMutate::JS::ScrollIntoViewOptionsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ScrollIntoViewOptionsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::ScrollIntoViewOptionsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FontArg::generate(JSContext *context)
{
    value = DOMValue::font();
}

void HIRMutate::JS::FontArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FontArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FontArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::HeadingArg::generate(JSContext *context)
{
    value = "H";
    value.append(Random::range_s(1, 6));
}

void HIRMutate::JS::HeadingArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("HeadingArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::HeadingArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::InsertPositionArg::InsertPositionArg() : StringSetArg(vector<string>({"beforebegin", "afterbegin", "beforeend", "afterend"}))
{
}

HIRMutate::JS::DesignModeArg::DesignModeArg() : StringSetArg(vector<string>({"on", "off"}))
{
}

void HIRMutate::JS::AutoCapitalizeArg::generate(JSContext *context)
{
    value = DOMValue::auto_capitalize();
}

void HIRMutate::JS::AutoCapitalizeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AutoCapitalizeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AutoCapitalizeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ContentEditableArg::generate(JSContext *context)
{
    value = DOMValue::boolean();
}

void HIRMutate::JS::ContentEditableArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ContentEditableArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ContentEditableArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::DirArg::generate(JSContext *context)
{
    value = DOMValue::dir_();
}

void HIRMutate::JS::DirArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DirArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::DirArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::LangArg::generate(JSContext *context)
{
    value = DOMValue::lang();
}

void HIRMutate::JS::LangArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("LangArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::LangArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TabIndexArg::generate(JSContext *context)
{
    value = DOMValue::tab_index();
}

void HIRMutate::JS::TabIndexArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TabIndexArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::TabIndexArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::DropZoneArg::generate(JSContext *context)
{
    value = DOMValue::drop_zone();
}

void HIRMutate::JS::DropZoneArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DropZoneArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::DropZoneArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CharsetArg::generate(JSContext *context)
{
    value = DOMValue::charset();
}

void HIRMutate::JS::CharsetArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CharsetArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CharsetArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CoordsArg::generate(JSContext *context)
{
    value = DOMValue::coords();
}
void HIRMutate::JS::CoordsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CoordsArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CoordsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ShapeArg::generate(JSContext *context)
{
    value = DOMValue::shape();
}
void HIRMutate::JS::ShapeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ShapeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ShapeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TargetArg::generate(JSContext *context)
{
    value = DOMValue::target();
}
void HIRMutate::JS::TargetArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TargetArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TargetArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::PreloadArg::generate(JSContext *context)
{
    value = DOMValue::preload();
}

void HIRMutate::JS::PreloadArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("PreloadArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::PreloadArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MediaSrcArg::generate(JSContext *context)
{
    int c = Random::selector(4);
    if (c == 0)
        value = "x";
    else if (c == 1)
        value = DOMValue::image_url();
    else if (c == 2)
        value = DOMValue::audio_url();
    else
        value = DOMValue::video_url();
}

void HIRMutate::JS::MediaSrcArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MediaSrcArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MediaSrcArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TrackSrcArg::generate(JSContext *context)
{
    if (Random::gbool())
        value = "x";
    else
        value = DOMValue::track_url();
}

void HIRMutate::JS::TrackSrcArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TrackSrcArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TrackSrcArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VolumeArg::generate(JSContext *context)
{
    value = Random::float01();
}

void HIRMutate::JS::VolumeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VolumeArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::VolumeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ClearArg::generate(JSContext *context)
{
    value = DOMValue::clear();
}

void HIRMutate::JS::ClearArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ClearArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ClearArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TrackKindArg::generate(JSContext *context)
{
    value = DOMValue::track_kind();
}
void HIRMutate::JS::TrackKindArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TrackKindArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TrackKindArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FormEncTypeArg::generate(JSContext *context)
{
    value = DOMValue::form_enc_type();
}
void HIRMutate::JS::FormEncTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FormEncTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FormEncTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FormMethodArg::generate(JSContext *context)
{
    value = DOMValue::form_method();
}
void HIRMutate::JS::FormMethodArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FormMethodArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FormMethodArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ButtonTypeArg::generate(JSContext *context)
{
    value = DOMValue::button_type();
}
void HIRMutate::JS::ButtonTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ButtonTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ButtonTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AlignArg::generate(JSContext *context)
{
    value = DOMValue::align();
}
void HIRMutate::JS::AlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::WhatToShowArg::generate(JSContext *context)
{
    static const char *strs[] = {"-1", "1", "2", "4", "8", "16", "32", "64", "128", "256", "512", "1024", "2048"};
    value = CHOICE(strs);
}
void HIRMutate::JS::WhatToShowArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("WhatToShowArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::WhatToShowArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::PlayStateArg::generate(JSContext *context)
{
    value = DOMValue::play_state();
}
void HIRMutate::JS::PlayStateArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("PlayStateArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::PlayStateArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AnimateOptionsArg::generate(JSContext *context)
{
    value = "{ delay: ";
    value.append(DOMValue::clock_in_ms());
    value.append(", direction: \"");
    value.append(DOMValue::animation_direction());
    value.append("\", duration: ");
    value.append(DOMValue::clock_in_ms());
    value.append(", easing: \"");
    value.append(DOMValue::animation_easing());
    value.append("\", endDelay: ");
    value.append(DOMValue::clock_in_ms());
    value.append(", fill: \"");
    value.append(DOMValue::animation_fill_mode());
    value.append("\", iterationStart: ");
    value.append(Random::number());
    value.append(", iterations: ");
    value.append(Random::integer());
    value.append(" }");
}
void HIRMutate::JS::AnimateOptionsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AnimateOptionsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::AnimateOptionsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AnimationDirectionArg::generate(JSContext *context)
{
    value = DOMValue::animation_direction();
}
void HIRMutate::JS::AnimationDirectionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AnimationDirectionArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AnimationDirectionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AnimationEasingArg::generate(JSContext *context)
{
    value = DOMValue::animation_easing();
}
void HIRMutate::JS::AnimationEasingArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AnimationEasingArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AnimationEasingArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AnimationFillArg::generate(JSContext *context)
{
    value = DOMValue::animation_fill_mode();
}
void HIRMutate::JS::AnimationFillArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AnimationFillArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AnimationFillArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AssignedNodesOptionArg::generate(JSContext *context)
{
    value = "{ flatten: ";
    value.append(DOMValue::boolean());
    value.append(" }");
}
void HIRMutate::JS::AssignedNodesOptionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AssignedNodesOptionArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::AssignedNodesOptionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AddEventListenerOptionsArg::generate(JSContext *context)
{
    value = "{ capture: ";
    value.append(DOMValue::boolean());
    value.append(", once: ");
    value.append(DOMValue::boolean());
    value.append(", passive: ");
    value.append(DOMValue::boolean());
    value.append(" }");
}
void HIRMutate::JS::AddEventListenerOptionsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AddEventListenerOptionsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::AddEventListenerOptionsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ObjectAlignArg::generate(JSContext *context)
{
    value = DOMValue::object_align();
}
void HIRMutate::JS::ObjectAlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ObjectAlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ObjectAlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ScrollingArg::generate(JSContext *context)
{
    value = DOMValue::scrolling();
}
void HIRMutate::JS::ScrollingArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ScrollingArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ScrollingArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TableFrameArg::generate(JSContext *context)
{
    value = DOMValue::table_frame();
}
void HIRMutate::JS::TableFrameArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableFrameArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TableFrameArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TableRulesArg::generate(JSContext *context)
{
    value = DOMValue::table_rules();
}
void HIRMutate::JS::TableRulesArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableRulesArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TableRulesArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TableAlignArg::generate(JSContext *context)
{
    value = DOMValue::table_align();
}
void HIRMutate::JS::TableAlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableAlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TableAlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VAlignArg::generate(JSContext *context)
{
    value = DOMValue::valign();
}
void HIRMutate::JS::VAlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VAlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VAlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::InputModeArg::generate(JSContext *context)
{
    value = DOMValue::input_mode();
}
void HIRMutate::JS::InputModeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("InputModeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::InputModeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::WrapArg::generate(JSContext *context)
{
    value = DOMValue::wrap();
}
void HIRMutate::JS::WrapArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("WrapArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::WrapArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SelectionDirectionArg::generate(JSContext *context)
{
    value = DOMValue::selection_direction();
}
void HIRMutate::JS::SelectionDirectionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SelectionDirectionArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SelectionDirectionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SelectModeArg::generate(JSContext *context)
{
    value = DOMValue::select_mode();
}
void HIRMutate::JS::SelectModeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SelectModeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SelectModeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::NumberingTypeArg::generate(JSContext *context)
{
    value = DOMValue::numbering_type();
}
void HIRMutate::JS::NumberingTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("NumberingTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::NumberingTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AutoCompleteArg::generate(JSContext *context)
{
    value = DOMValue::auto_complete();
}
void HIRMutate::JS::AutoCompleteArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AutoCompleteArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AutoCompleteArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CaptionAlignArg::generate(JSContext *context)
{
    value = DOMValue::caption_align();
}
void HIRMutate::JS::CaptionAlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CaptionAlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CaptionAlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::KeyTypeArg::generate(JSContext *context)
{
    value = DOMValue::key_type();
}
void HIRMutate::JS::KeyTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("KeyTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::KeyTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ImageSrcArg::generate(JSContext *context)
{
    if (Random::gbool())
        value = DOMValue::image_url();
    else
        value = "x";
}
void HIRMutate::JS::ImageSrcArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ImageSrcArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ImageSrcArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SrcSetArg::generate(JSContext *context)
{
    value = DOMValue::srcset();
}
void HIRMutate::JS::SrcSetArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SrcSetArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SrcSetArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MetaSchemeArg::generate(JSContext *context)
{
    value = DOMValue::meta_scheme();
}
void HIRMutate::JS::MetaSchemeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MetaSchemeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MetaSchemeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TextTrackModeArg::generate(JSContext *context)
{
    value = DOMValue::text_track_mode();
}
void HIRMutate::JS::TextTrackModeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TextTrackModeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TextTrackModeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VTTRegionScrollArg::generate(JSContext *context)
{
    value = DOMValue::vtt_region_scroll();
}
void HIRMutate::JS::VTTRegionScrollArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VTTRegionScrollArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VTTRegionScrollArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VTTCueVerticalArg::generate(JSContext *context)
{
    value = DOMValue::vtt_cue_vertical();
}
void HIRMutate::JS::VTTCueVerticalArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VTTCueVerticalArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VTTCueVerticalArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VTTCueLineArg::generate(JSContext *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = Random::number();
}
void HIRMutate::JS::VTTCueLineArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VTTCueLineArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VTTCueLineArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VTTCuePositionArg::generate(JSContext *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = Random::number();
}
void HIRMutate::JS::VTTCuePositionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VTTCuePositionArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VTTCuePositionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::VTTCueAlignArg::generate(JSContext *context)
{
    value = DOMValue::vtt_cue_align();
}
void HIRMutate::JS::VTTCueAlignArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("VTTCueAlignArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::VTTCueAlignArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::DateTimeArg::generate(JSContext *context)
{
    value = DOMValue::date_time();
}
void HIRMutate::JS::DateTimeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DateTimeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::DateTimeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ParamValueTypeArg::generate(JSContext *context)
{
    value = DOMValue::param_value_type();
}
void HIRMutate::JS::ParamValueTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ParamValueTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ParamValueTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::LinkAsArg::generate(JSContext *context)
{
    value = DOMValue::link_as();
}
void HIRMutate::JS::LinkAsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("LinkAsArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::LinkAsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::UListTypeArg::generate(JSContext *context)
{
    value = DOMValue::ulist_type();
}
void HIRMutate::JS::UListTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("UListTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::UListTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TableScopeArg::generate(JSContext *context)
{
    value = DOMValue::table_scope();
}
void HIRMutate::JS::TableScopeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableScopeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TableScopeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MenuTypeArg::generate(JSContext *context)
{
    value = DOMValue::menu_type();
}
void HIRMutate::JS::MenuTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MenuTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MenuTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::AcceptArg::generate(JSContext *context)
{
    value = DOMValue::accept();
}
void HIRMutate::JS::AcceptArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("AcceptArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::AcceptArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::InputTypeArg::generate(JSContext *context)
{
    value = DOMValue::input_type();
}
void HIRMutate::JS::InputTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("InputTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::InputTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MenuItemTypeArg::generate(JSContext *context)
{
    value = DOMValue::menu_item_type();
}
void HIRMutate::JS::MenuItemTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MenuItemTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MenuItemTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MarqueeBehaviorArg::generate(JSContext *context)
{
    value = DOMValue::marquee_behavior();
}
void HIRMutate::JS::MarqueeBehaviorArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MarqueeBehaviorArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MarqueeBehaviorArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MarqueeDirectionArg::generate(JSContext *context)
{
    value = DOMValue::marquee_direction();
}
void HIRMutate::JS::MarqueeDirectionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MarqueeDirectionArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MarqueeDirectionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MarqueeLoopArg::generate(JSContext *context)
{
    value = DOMValue::marquee_loop();
}
void HIRMutate::JS::MarqueeLoopArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MarqueeLoopArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MarqueeLoopArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SelectionModifyAlterArg::generate(JSContext *context)
{
    static const char *strs[] = {"move", "extend"};
    value = CHOICE(strs);
}
void HIRMutate::JS::SelectionModifyAlterArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SelectionModifyAlterArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SelectionModifyAlterArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SelectionModifyDirectionArg::generate(JSContext *context)
{
    static const char *strs[] = {"forward", "backward", "left", "right"};
    value = CHOICE(strs);
}
void HIRMutate::JS::SelectionModifyDirectionArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SelectionModifyDirectionArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SelectionModifyDirectionArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::SelectionModifyGranularityArg::generate(JSContext *context)
{
    static const char *strs[] = {"character", "word", "sentence", "line", "paragraph",
                                 "lineboundary", "sentenceboundary", "paragraphboundary",
                                 "documentboundary"};
    value = CHOICE(strs);
}
void HIRMutate::JS::SelectionModifyGranularityArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SelectionModifyGranularityArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SelectionModifyGranularityArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::GetRootNodeOptionsArg::generate(JSContext *context)
{
    value = "{ composed: ";
    value.append(DOMValue::boolean());
    value.append(" }");
}
void HIRMutate::JS::GetRootNodeOptionsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("GetRootNodeOptionsArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::GetRootNodeOptionsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::RangeCompareArg::generate(JSContext *context)
{
    static const char *strs[] = {"Range.END_TO_END",
                                 "Range.END_TO_START",
                                 "Range.START_TO_END",
                                 "Range.START_TO_START"};
    value = CHOICE(strs);
}
void HIRMutate::JS::RangeCompareArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RangeCompareArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::RangeCompareArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CSSFloatArg::generate(JSContext *context)
{
    static const char *strs[] = {"left", "right", "none", "initial", "inherit"};
    value = CHOICE(strs);
}
void HIRMutate::JS::CSSFloatArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSFloatArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CSSFloatArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ContentTypeArg::generate(JSContext *context)
{
    static const char *strs[] = {"text/html", "application/xml", "image/svg+xml"};
    value = CHOICE(strs);
}
void HIRMutate::JS::ContentTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ContentTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ContentTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::RelArg::generate(JSContext *context)
{
    value = DOMValue::rel();
}
void HIRMutate::JS::RelArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RelArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::RelArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::RevArg::generate(JSContext *context)
{
    value = DOMValue::rev();
}
void HIRMutate::JS::RevArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RevArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::RevArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FrameSrcArg::generate(JSContext *context)
{
    if (Random::gbool())
        value = "x";
    else
        value = DOMValue::frame_url();
}
void HIRMutate::JS::FrameSrcArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FrameSrcArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FrameSrcArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MediaQueryArg::generate(JSContext *context)
{
    value = DOMValue::media_query();
}
void HIRMutate::JS::MediaQueryArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MediaQueryArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MediaQueryArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ImageTypeArg::generate(JSContext *context)
{
    value = DOMValue::image_type();
}
void HIRMutate::JS::ImageTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ImageTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ImageTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MediaTypeArg::generate(JSContext *context)
{
    value = DOMValue::media_type();
}
void HIRMutate::JS::MediaTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MediaTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MediaTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MIMETypeArg::generate(JSContext *context)
{
    value = DOMValue::mime_type();
}
void HIRMutate::JS::MIMETypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MIMETypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MIMETypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CSSTypeArg::generate(JSContext *context)
{
    value = DOMValue::css_type();
}
void HIRMutate::JS::CSSTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CSSTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::DropEffectArg::generate(JSContext *context)
{
    static const char *strs[] = {"none", "copy", "link", "move"};
    value = CHOICE(strs);
}
void HIRMutate::JS::DropEffectArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("DropEffectArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::DropEffectArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::EffectAllowedArg::generate(JSContext *context)
{
    static const char *strs[] = {"none", "copy", "copyLink", "copyMove", "link",
                                 "linkMove", "move", "all", "uninitialized"};
    value = CHOICE(strs);
}
void HIRMutate::JS::EffectAllowedArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("EffectAllowedArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::EffectAllowedArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FontWeightArg::generate(JSContext *context)
{
    value = DOMValue::font_weight();
}
void HIRMutate::JS::FontWeightArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FontWeightArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FontWeightArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FontStretchArg::generate(JSContext *context)
{
    value = DOMValue::font_stretch();
}
void HIRMutate::JS::FontStretchArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FontStretchArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FontStretchArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FontVariantArg::generate(JSContext *context)
{
    value = DOMValue::font_variant();
}
void HIRMutate::JS::FontVariantArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FontVariantArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FontVariantArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::FontFeatureSettingsArg::generate(JSContext *context)
{
    value = DOMValue::font_feature_settings();
}
void HIRMutate::JS::FontFeatureSettingsArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("FontFeatureSettingsArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::FontFeatureSettingsArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::UnicodeRangeArg::generate(JSContext *context)
{
    value = DOMValue::unicode_range();
}
void HIRMutate::JS::UnicodeRangeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("UnicodeRangeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::UnicodeRangeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ScrollRestorationArg::generate(JSContext *context)
{
    static const char *strs[] = {"auto", "manual"};
    value = CHOICE(strs);
}
void HIRMutate::JS::ScrollRestorationArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ScrollRestorationArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ScrollRestorationArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::HistoryStateArg::generate(JSContext *context)
{
    value = "{ \"";
    value.append(Random::gstring());
    value.append("\": \"");
    value.append(Random::gstring());
    value.append("\" }");
}
void HIRMutate::JS::HistoryStateArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("HistoryStateArg");
    ValueArg::serialize(stream, context);
}
void HIRMutate::JS::HistoryStateArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    ValueArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CSSPropertyNameArg::generate(JSContext *context)
{
    value = CSS::get_css_property_name();
}
void HIRMutate::JS::CSSPropertyNameArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSPropertyNameArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CSSPropertyNameArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CustomElementNameArg::generate(JSContext *context)
{
    static const char *strs[] = {"a", "b", "c"};
    value = "custom-";
    value.append(CHOICE(strs));
}
void HIRMutate::JS::CustomElementNameArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CustomElementNameArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CustomElementNameArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
/*
        * Context-aware arg
        */
void HIRMutate::JS::MediaGroupArg::generate(JSContext *context)
{
    value = context->global_context->get_token("mediagroup");
}
void HIRMutate::JS::MediaGroupArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MediaGroupArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MediaGroupArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TagArg::generate(JSContext *context)
{
    vector<string> vec;
    vec.assign(context->global_context->in_tree_set.begin(), context->global_context->in_tree_set.end());
    vec.push_back("HTMLBodyElement");
    string &elem = CHOICE_OBJ(vec);
    value = DOC::tag_from_element(elem);
}
void HIRMutate::JS::TagArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TagArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TagArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::HTMLTagArg::generate(JSContext *context)
{
    vector<string> vec;
    std::for_each(context->global_context->in_tree_set.begin(), context->global_context->in_tree_set.end(),
                  [&vec](const string &e)
                  {
                      if (DOC::is_html_element(e))
                      {
                          vec.push_back(e);
                      }
                  });
    vec.push_back("HTMLBodyElement");
    string &elem = CHOICE_OBJ(vec);
    value = DOC::tag_from_element(elem);
}
void HIRMutate::JS::HTMLTagArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("HTMLTagArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::HTMLTagArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::ClassArg::generate(JSContext *context)
{
    value = context->global_context->get_token("class");
}
void HIRMutate::JS::ClassArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ClassArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::ClassArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}

HIRMutate::JS::KeyFramesArg::KeyFramesArg()
{
#ifdef DEBUG_MEM
    std::cout << "KeyFramesArg()" << std::endl;
#endif
}
HIRMutate::JS::KeyFramesArg::~KeyFramesArg()
{
#ifdef DEBUG_MEM
    std::cout << "~KeyFramesArg()" << std::endl;
#endif
    std::for_each(props.begin(), props.end(),
                  [](map<string, vector<Value *> >::reference i)
                  {
                      vector<Value *> &vec = i.second;
                      std::for_each(vec.begin(), vec.end(),
                                    [](Value *value)
                                    {
                                        delete value;
                                    });
                  });
}

bool HIRMutate::JS::KeyFramesArg::is_object()
{
    return false;
}

void HIRMutate::JS::KeyFramesArg::append_prop(JSContext *context)
{
    Value *(*value_class)(void);
    string prop;
    while (true)
    {
        std::pair<string, Value *(*)(void)> p = CSS::get_css_property(true);
        if (props.find(p.first) == props.end())
        {
            value_class = p.second;
            prop = p.first;
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        Value *value = value_class();
        value->generate(context);
        props[prop].push_back(value);
    }
    prop_keys.push_back(prop);
}

void HIRMutate::JS::KeyFramesArg::generate(JSContext *context)
{
    append_prop(context);
}

bool HIRMutate::JS::KeyFramesArg::mutate(JSContext *context)
{
    if (prop_keys.size() == 0)
    {
        append_prop(context);
        return true;
    }
    
    int c = Random::selector(4);
    string prop;
    if (c == 0)
    {
        prop = CHOICE_OBJ(prop_keys);
        Value *(*value_class)(void) = (Value * (*)(void)) CSS::get_css_property_value(prop);
        Value *value = value_class();
        value->generate(context);
        props[prop].push_back(value);
        return true;
    }
    else if (c == 1)
    {
        prop = CHOICE_OBJ(prop_keys);
        vector<Value *> &values = props[prop];
        Value *value = CHOICE_OBJ(values);
        return value->mutate(context);
    }
    else if (c == 2)
    {
        append_prop(context);
        return true;
    }
    else
    {
        // 3. replace property
        prop = CHOICE_OBJ(prop_keys);
        vector<Value *> vec = props[prop];
        std::for_each(vec.begin(), vec.end(),
                      [](Value *val)
                      {
                          delete val;
                      });
        props.erase(prop);
        append_prop(context);
        return true;
    }
}

void HIRMutate::JS::KeyFramesArg::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(props.begin(), props.end(),
                  [&merge_map](map<string, vector<Value *> >::reference i)
                  {
                      vector<Value *> &vec = i.second;
                      std::for_each(vec.begin(), vec.end(),
                                    [&merge_map](Value *value)
                                    {
                                        value->merge_fix(merge_map);
                                    });
                  });
}

HIRMutate::JS::KeyFramesArg::operator string()
{
    string s = "{ ";
    std::for_each(props.begin(), props.end(),
                  [&s](map<string, vector<Value *> >::reference i)
                  {
                      s.append("\"");
                      s.append(i.first);
                      s.append("\": [");
                      vector<Value *> &vec = i.second;
                      std::for_each(vec.begin(), vec.end(),
                                    [&s](Value *value)
                                    {
                                        s.append("\"");
                                        s.append(value->getValue());
                                        s.append("\"");
                                        s.append(",");
                                    });
                      s.append("], ");
                  });

    s.append(" }");
    return s;
}

void HIRMutate::JS::KeyFramesArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("KeyFramesArg");
    Arg::serialize(stream, context);
    stream->write_int(props.size());
    std::for_each(props.begin(), props.end(),
                  [&stream, &context](map<string, vector<Value *> >::reference i)
                  {
                      stream->write_string(i.first);
                      vector<Value *> &vec = i.second;
                      stream->write_int(vec.size());
                      std::for_each(vec.begin(), vec.end(),
                                    [&stream, &context](Value *val)
                                    {
                                        val->serialize(stream, context);
                                    });
                  });
}
void HIRMutate::JS::KeyFramesArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    int prop_size = stream->read_int();
    for (int i = 0; i < prop_size; i++)
    {
        string key = stream->read_string();
        int vec_sz = stream->read_int();
        for (int j = 0; j < vec_sz; j++)
        {
            Value *val = value_classes[stream->read_string()](stream, global_document, function);
            props[key].push_back(val);
        }
    }
}
void HIRMutate::JS::TableAxisArg::generate(JSContext *context)
{
    value = context->global_context->get_token("axis");
}

void HIRMutate::JS::TableAxisArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableAxisArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TableAxisArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::RadioGroupArg::generate(JSContext *context)
{
    value = context->global_context->get_token("radiogroup");
}

void HIRMutate::JS::RadioGroupArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("RadioGroupArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::RadioGroupArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::XPathArg::generate(JSContext *context)
{
    vector<string> vec;
    vec.assign(context->global_context->in_tree_set.begin(), context->global_context->in_tree_set.end());
    vec.push_back("HTMLBodyElement");
    string &elem = CHOICE_OBJ(vec);
    value = "//";
    value.append(DOC::tag_from_element(elem));
}
void HIRMutate::JS::XPathArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("XPathArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::XPathArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::TextEventTypeArg::generate(JSContext *context)
{
    static const char *strs[] = {"textInput", "foo"};
    value = CHOICE(strs);
}
void HIRMutate::JS::TextEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TextEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::TextEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MouseEventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::mouse_events;
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::MouseEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MouseEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MouseEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::CompositionEventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::composition_events;
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::CompositionEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CompositionEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CompositionEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::UIEventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::ui_events;
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::UIEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("UIEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::UIEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MessageEventTypeArg::generate(JSContext *context)
{
    static const char *strs[] = {"message", "foo"};
    value = CHOICE(strs);
}
void HIRMutate::JS::MessageEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MessageEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MessageEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::EventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::ui_events;
    vec.insert(vec.end(), DOC::mutation_events.begin(), DOC::mutation_events.end());
    vec.push_back("textInput");
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::EventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("EventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::EventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::MutationEventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::mutation_events;
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::MutationEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("MutationEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::MutationEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
void HIRMutate::JS::KeyboardEventTypeArg::generate(JSContext *context)
{
    vector<string> vec = DOC::keyboard_events;
    vec.push_back("foo");
    value = CHOICE_OBJ(vec);
}
void HIRMutate::JS::KeyboardEventTypeArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("KeyboardEventTypeArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::KeyboardEventTypeArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
/*
        * Dynamic arg
        */
HIRMutate::JS::SlotArg::SlotArg()
{
    slot = nullptr;
}
bool HIRMutate::JS::SlotArg::is_object()
{
    return false;
}

void HIRMutate::JS::SlotArg::generate(JSContext *context)
{
    slot = context->global_context->get_object("HTMLSlotElement");
}

void HIRMutate::JS::SlotArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (slot != nullptr)
    {
        if (merge_map.find(slot) != merge_map.end())
            slot = merge_map[slot];
    }
}

HIRMutate::JS::SlotArg::operator string()
{
    string s = "\"";
    if (slot == nullptr)
        s.append("foo");
    else
        s.append(slot->id);
    s.append("\"");
    return s;
}

void HIRMutate::JS::SlotArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SlotArg");
    Arg::serialize(stream, context);
    if (slot != nullptr)
        slot->serialize_weak(stream, ((JSContext *)context)->global_context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::JS::SlotArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        slot = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&slot, global_document);
    }
}
HIRMutate::JS::UseMapArg::UseMapArg()
{
    m_map = nullptr;
}
bool HIRMutate::JS::UseMapArg::is_object()
{
    return false;
}

void HIRMutate::JS::UseMapArg::generate(JSContext *context)
{
    m_map = context->global_context->get_object("HTMLMapElement");
}

void HIRMutate::JS::UseMapArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (m_map != nullptr)
    {
        if (merge_map.find(m_map) != merge_map.end())
            m_map = merge_map[m_map];
    }
}

HIRMutate::JS::UseMapArg::operator string()
{
    string s = "\"";
    if (m_map == nullptr)
        s.append("#foo");
    else
    {
        s.append("#");
        s.append(m_map->id);
    }
    s.append("\"");
    return s;
}

void HIRMutate::JS::UseMapArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("UseMapArg");
    Arg::serialize(stream, context);
    if (m_map != nullptr)
        m_map->serialize_weak(stream, ((JSContext *)context)->global_context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::JS::UseMapArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        m_map = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&m_map, global_document);
    }
}
HIRMutate::JS::ContentSelectArg::ContentSelectArg()
{
    elem = nullptr;
}
bool HIRMutate::JS::ContentSelectArg::is_object()
{
    return false;
}

void HIRMutate::JS::ContentSelectArg::generate(JSContext *context)
{
    if (Random::gbool())
    {
        cla = context->global_context->get_token("class");
        elem = nullptr;
    }
    else
    {
        cla = "";
        elem = context->global_context->get_object(DOC::elements);
    }
}

void HIRMutate::JS::ContentSelectArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem != nullptr)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

HIRMutate::JS::ContentSelectArg::operator string()
{
    string s = "\"";
    if (cla != "")
    {
        s.append(".");
        s.append(cla);
    }
    else if (elem != nullptr)
    {
        s.append("#");
        s.append(elem->id);
    }
    else
        s.append("#foo");
    s.append("\"");
    return s;
}
void HIRMutate::JS::ContentSelectArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("ContentSelectArg");
    Arg::serialize(stream, context);
    if (elem != nullptr)
        elem->serialize_weak(stream, ((JSContext *)context)->global_context);
    else
        stream->write_string("nullptr");
    stream->write_string(cla);
}

void HIRMutate::JS::ContentSelectArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        elem = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&elem, global_document);
    }
    cla = stream->read_string();
}

HIRMutate::JS::LabelForArg::LabelForArg()
{
    elem = nullptr;
}
bool HIRMutate::JS::LabelForArg::is_object()
{
    return false;
}

void HIRMutate::JS::LabelForArg::generate(JSContext *context)
{
    elem = context->global_context->get_object(DOC::html_labelable_elements);
}

void HIRMutate::JS::LabelForArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem != nullptr)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

HIRMutate::JS::LabelForArg::operator string()
{
    string s = "\"";
    if (elem != nullptr)
        s.append(elem->id);
    else
        s.append("foo");
    s.append("\"");
    return s;
}
void HIRMutate::JS::LabelForArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("LabelForArg");
    Arg::serialize(stream, context);
    if (elem != nullptr)
        elem->serialize_weak(stream, ((JSContext *)context)->global_context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::JS::LabelForArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
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
bool HIRMutate::JS::TableHeadersArg::is_object()
{
    return false;
}

void HIRMutate::JS::TableHeadersArg::append_th(JSContext *context)
{
    Object *elem = context->global_context->get_object("HTMLTableHeaderCellElement");
    if (elem != nullptr && find(ths.begin(), ths.end(), elem) == ths.end())
        ths.push_back(elem);
}

void HIRMutate::JS::TableHeadersArg::generate(JSContext *context)
{
    append_th(context);
}

bool HIRMutate::JS::TableHeadersArg::mutate(JSContext *context)
{
    if (ths.size() == 0 || Random::gbool())
    {
        //1. add one
        append_th(context);
    }
    else
    {
        // 2. replace one
        ths.erase(ths.begin() + Random::selector(ths.size()));
        append_th(context);
    }
    return true;
}

void HIRMutate::JS::TableHeadersArg::merge_fix(map<Object *, Object *> &merge_map)
{
    int len = ths.size();
    for (int i = 0; i < len; i++)
    {
        if (ths[i] != nullptr)
        {
            Object *o = ths[i];
            if (merge_map.find(o) != merge_map.end())
                ths[i] = merge_map[o];
        }
    }
}

HIRMutate::JS::TableHeadersArg::operator string()
{
    string s = "\"";
    int len = ths.size();
    for (int i = 0; i < len; i++)
    {
        Object *o = ths[i];
        if (o != nullptr)
        {
            s.append(o->id);
            if (i != len - 1)
            {
                s.append(" ");
            }
        }
    }
    s.append("\"");
    return s;
}
void HIRMutate::JS::TableHeadersArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("TableHeadersArg");
    Arg::serialize(stream, context);
    stream->write_int(ths.size());
    std::for_each(ths.begin(), ths.end(),
                  [&stream, context](Object *val)
                  {
                      val->serialize_weak(stream, ((JSContext *)context)->global_context);
                  });
}
void HIRMutate::JS::TableHeadersArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    int ths_size = stream->read_int();
    ths.resize(ths_size);
    for (int i = 0; i < ths_size; i++)
    {
        stream->read_obj_ref((size_t)&ths[i], global_document);
    }
}
HIRMutate::JS::CSSSelectorValueArg::CSSSelectorValueArg()
{
    selector = nullptr;
}

HIRMutate::JS::CSSSelectorValueArg::~CSSSelectorValueArg()
{
    if (selector)
        delete selector;
}

bool HIRMutate::JS::CSSSelectorValueArg::is_object()
{
    return false;
}

void HIRMutate::JS::CSSSelectorValueArg::generate(JSContext *context)
{
    if (selector)
        delete selector;
    selector = CSS::create_css_selector();
    selector->generate(context->global_context);
}

bool HIRMutate::JS::CSSSelectorValueArg::mutate(JSContext *context)
{
    if (Random::gbool())
    {
        // 1. mutate selector value
        return selector->mutate(context->global_context);
    }
    else
    {
        //2. change to another selector
        generate(context);
        return true;
    }
}

void HIRMutate::JS::CSSSelectorValueArg::merge_fix(map<Object *, Object *> &merge_map)
{
    selector->merge_fix(merge_map);
}

HIRMutate::JS::CSSSelectorValueArg::operator string()
{
    string ans = "\"";
    ans.append(selector->operator string());
    ans.append("\"");
    return ans;
}
void HIRMutate::JS::CSSSelectorValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSSelectorValueArg");
    Arg::serialize(stream, context);
    selector->serialize(stream, context->global_context);
}
void HIRMutate::JS::CSSSelectorValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    CSS::CSSGroupSelector *selector = new CSS::CSSGroupSelector();
    stream->skip_string();
    selector->unserialize(stream, global_document);
    this->selector = selector;
}
HIRMutate::JS::CSSStyleDeclarationValueArg::CSSStyleDeclarationValueArg()
{
    style_declaration = new CSS::CSSStyleDeclaration();
}
HIRMutate::JS::CSSStyleDeclarationValueArg::~CSSStyleDeclarationValueArg()
{
    delete style_declaration;
}
bool HIRMutate::JS::CSSStyleDeclarationValueArg::is_object()
{
    return false;
}

void HIRMutate::JS::CSSStyleDeclarationValueArg::generate(JSContext *context)
{
    style_declaration->generate(context->global_context);
    for (int i = 0; i < CSSConfig::max_css_internal_decl_count - 1; i++)
        style_declaration->append(context->global_context);
}

bool HIRMutate::JS::CSSStyleDeclarationValueArg::mutate(JSContext *context)
{
    return style_declaration->mutate(context->global_context);
}

void HIRMutate::JS::CSSStyleDeclarationValueArg::merge_fix(map<Object *, Object *> &merge_map)
{
    style_declaration->merge_fix(merge_map);
}

HIRMutate::JS::CSSStyleDeclarationValueArg::operator string()
{
    string ans = "\"";
    ans.append(style_declaration->getValue());
    ans.append("\"");
    return ans;
}
void HIRMutate::JS::CSSStyleDeclarationValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSStyleDeclarationValueArg");
    Arg::serialize(stream, context);
    style_declaration->serialize(stream, context->global_context);
}
void HIRMutate::JS::CSSStyleDeclarationValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    style_declaration->unserialize(stream, global_document);
}
HIRMutate::JS::CSSStyleRuleValueArg::CSSStyleRuleValueArg()
{
    rule = new CSS::CSSStyleRule();
}
HIRMutate::JS::CSSStyleRuleValueArg::~CSSStyleRuleValueArg()
{
    delete rule;
}
bool HIRMutate::JS::CSSStyleRuleValueArg::is_object()
{
    return false;
}

void HIRMutate::JS::CSSStyleRuleValueArg::generate(JSContext *context)
{
    rule->generate(context->global_context);
    for (int i = 0; i < CSSConfig::max_css_internal_decl_count - 1; i++)
        rule->append_decl(context->global_context);
}

bool HIRMutate::JS::CSSStyleRuleValueArg::mutate(JSContext *context)
{
    return rule->mutate(context->global_context);
}

void HIRMutate::JS::CSSStyleRuleValueArg::merge_fix(map<Object *, Object *> &merge_map)
{
    rule->merge_fix(merge_map);
}

HIRMutate::JS::CSSStyleRuleValueArg::operator string()
{
    string ans = "\"";
    ans.append(rule->operator string());
    ans.append("\"");
    return ans;
}
void HIRMutate::JS::CSSStyleRuleValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSStyleRuleValueArg");
    Arg::serialize(stream, context);
    rule->serialize(stream, context->global_context);
}
void HIRMutate::JS::CSSStyleRuleValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    rule->unserialize(stream, global_document);
}
HIRMutate::JS::CSSStyleRuleValueTextArg::CSSStyleRuleValueTextArg()
{
    rule = new CSS::CSSStyleRule();
}
HIRMutate::JS::CSSStyleRuleValueTextArg::~CSSStyleRuleValueTextArg()
{
    delete rule;
}
bool HIRMutate::JS::CSSStyleRuleValueTextArg::is_object()
{
    return false;
}

void HIRMutate::JS::CSSStyleRuleValueTextArg::generate(JSContext *context)
{
    rule->generate(context->global_context);
    for (int i = 0; i < CSSConfig::max_css_internal_decl_count - 1; i++)
        rule->append_decl(context->global_context);
}

bool HIRMutate::JS::CSSStyleRuleValueTextArg::mutate(JSContext *context)
{
    return rule->mutate(context->global_context);
}

void HIRMutate::JS::CSSStyleRuleValueTextArg::merge_fix(map<Object *, Object *> &merge_map)
{
    rule->merge_fix(merge_map);
}

HIRMutate::JS::CSSStyleRuleValueTextArg::operator string()
{
    string ans = "document.createTextNode(";
    ans.append("\"");
    ans.append(rule->operator string());
    ans.append("\"");
    ans.append(")");
    return ans;
}
void HIRMutate::JS::CSSStyleRuleValueTextArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSStyleRuleValueTextArg");
    Arg::serialize(stream, context);
    rule->serialize(stream, context->global_context);
}
void HIRMutate::JS::CSSStyleRuleValueTextArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    rule->unserialize(stream, global_document);
}
void HIRMutate::JS::CSSKeyframeNameArg::generate(JSContext *context)
{
    value = DOMValue::keyframe_name();
}
void HIRMutate::JS::CSSKeyframeNameArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSKeyframeNameArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::CSSKeyframeNameArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::CSSKeyframeRuleValueArg::CSSKeyframeRuleValueArg(bool is_serialize)
{
    if (!is_serialize)
    {
        string n = DOMValue::keyframe_name();
        keyframe_rule = new CSS::CSSKeyframeRule(n);
    }
}
HIRMutate::JS::CSSKeyframeRuleValueArg::~CSSKeyframeRuleValueArg()
{
    delete keyframe_rule;
}
bool HIRMutate::JS::CSSKeyframeRuleValueArg::is_object()
{
    return false;
}

bool HIRMutate::JS::CSSKeyframeRuleValueArg::mutate(JSContext *context)
{
    if (Random::selector(5) == 0)
    {
        keyframe_rule->name = DOMValue::keyframe_name();
        return true;
    }
    else
        return keyframe_rule->mutate(context->global_context);
}

void HIRMutate::JS::CSSKeyframeRuleValueArg::generate(JSContext *context)
{
    keyframe_rule->generate(context->global_context);
}

void HIRMutate::JS::CSSKeyframeRuleValueArg::merge_fix(map<Object *, Object *> &merge_map)
{
    keyframe_rule->merge_fix(merge_map);
}

HIRMutate::JS::CSSKeyframeRuleValueArg::operator string()
{
    string ans = "\"";
    ans.append(keyframe_rule->operator string());
    ans.append("\"");
    return ans;
}
void HIRMutate::JS::CSSKeyframeRuleValueArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("CSSKeyframeRuleValueArg");
    Arg::serialize(stream, context);
    keyframe_rule->serialize(stream, context->global_context);
}
void HIRMutate::JS::CSSKeyframeRuleValueArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    keyframe_rule = new CSS::CSSKeyframeRule();
    keyframe_rule->unserialize(stream, global_document);
}