#include "html_val.h"
#include "serialize_variables.h"

void HIRMutate::HTML::ShapeValue::generate(Context *context)
{
    value = DOMValue::shape();
}

void HIRMutate::HTML::CoordsValue::generate(Context *context)
{
    value = DOMValue::coords();
}

void HIRMutate::HTML::ImageSrcValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::image_url();
    else
        value = "x";
}

void HIRMutate::HTML::LangValue::generate(Context *context)
{
    value = DOMValue::lang();
}

void HIRMutate::HTML::ReferrerPolicyValue::generate(Context *context)
{
    static const char *strs[] = {"no-referrer", "no-referrer-when-downgrade", "same-origin", "origin",
                                 "strict-origin", "origin-when-cross-origin", "strict-origin-when-cross-origin",
                                 "unsafe-url"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AcceptValue::generate(Context *context)
{
    value = DOMValue::accept();
}

void HIRMutate::HTML::PreloadValue::generate(Context *context)
{
    value = DOMValue::preload();
}

void HIRMutate::HTML::VideoSrcValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::video_url();
    else
        value = "x";
}

void HIRMutate::HTML::AudioSrcValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::audio_url();
    else
        value = "x";
}

void HIRMutate::HTML::FrameSrcValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::frame_url();
    else
        value = "x";
}

void HIRMutate::HTML::SoundLoopValue::generate(Context *context)
{
    if (Random::gbool())
        value = "infinite";
    else
        value = Random::integer();
}

void HIRMutate::HTML::AutoCapitalizeValue::generate(Context *context)
{
    value = DOMValue::auto_capitalize();
}

void HIRMutate::HTML::ButtonTypeValue::generate(Context *context)
{
    value = DOMValue::button_type();
}

void HIRMutate::HTML::CaptionAlignValue::generate(Context *context)
{
    value = DOMValue::caption_align();
}

void HIRMutate::HTML::TableAlignValue::generate(Context *context)
{
    value = DOMValue::table_align();
}

void HIRMutate::HTML::VAlignValue::generate(Context *context)
{
    value = DOMValue::valign();
}

void HIRMutate::HTML::CommandTypeValue::generate(Context *context)
{
    static const char *strs[] = {"command", "checkbox", "radio"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::TrackSrcValue::generate(Context *context)
{
    if (Random::gbool())
        value = "x";
    else
        value = DOMValue::track_url();
}

void HIRMutate::HTML::MediaSrcValue::generate(Context *context)
{
    int c = Random::selector(4);
    switch (c)
    {
    case 0:
        value = "x";
        break;
    case 1:
        value = DOMValue::image_url();
        break;
    case 2:
        value = DOMValue::audio_url();
        break;
    default:
        value = DOMValue::video_url();
        break;
    }
}

void HIRMutate::HTML::ImportanceValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "low", "high"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::LoadingValue::generate(Context *context)
{
    static const char *strs[] = {"eager", "lazy"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::DirValue::generate(Context *context)
{
    value = DOMValue::dir_();
}

void HIRMutate::HTML::DropZoneValue::generate(Context *context)
{
    value = DOMValue::drop_zone();
}

void HIRMutate::HTML::InputModeValue::generate(Context *context)
{
    value = DOMValue::input_mode();
}

void HIRMutate::HTML::FormEncTypeValue::generate(Context *context)
{
    value = DOMValue::form_enc_type();
}

void HIRMutate::HTML::FormMethodValue::generate(Context *context)
{
    value = DOMValue::form_method();
}

void HIRMutate::HTML::AlignValue::generate(Context *context)
{
    value = DOMValue::align();
}

void HIRMutate::HTML::ObjectAlignValue::generate(Context *context)
{
    value = DOMValue::object_align();
}

void HIRMutate::HTML::SizesValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = Random::integer();
    value.append("x");
    value.append(Random::integer());
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(Random::integer());
        value.append("x");
        value.append(Random::integer());
    }
}

void HIRMutate::HTML::ScrollingValue::generate(Context *context)
{
    value = DOMValue::scrolling();
}

void HIRMutate::HTML::ImageDecodingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "sync", "async"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::IntrinsicSizeValue::generate(Context *context)
{
    value = Random::integer();
    value.append(" x ");
    value.append(Random::integer());
}

void HIRMutate::HTML::InputTypeValue::generate(Context *context)
{
    value = DOMValue::input_type();
}

void HIRMutate::HTML::AutoCompleteValue::generate(Context *context)
{
    value = DOMValue::auto_complete();
}

void HIRMutate::HTML::InputCaptureValue::generate(Context *context)
{
    static const char *strs[] = {"user", "environment"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::KeyTypeValue::generate(Context *context)
{
    value = DOMValue::key_type();
}

void HIRMutate::HTML::NumberingTypeValue::generate(Context *context)
{
    value = DOMValue::numbering_type();
}

void HIRMutate::HTML::LinkAsValue::generate(Context *context)
{
    value = DOMValue::link_as();
}

void HIRMutate::HTML::RelValue::generate(Context *context)
{
    value = DOMValue::rel();
}

void HIRMutate::HTML::RevValue::generate(Context *context)
{
    value = DOMValue::rev();
}

void HIRMutate::HTML::MarqueeBehaviorValue::generate(Context *context)
{
    value = DOMValue::marquee_behavior();
}

void HIRMutate::HTML::MarqueeDirectionValue::generate(Context *context)
{
    value = DOMValue::marquee_direction();
}

void HIRMutate::HTML::MarqueeLoopValue::generate(Context *context)
{
    value = DOMValue::marquee_loop();
}

void HIRMutate::HTML::MenuItemTypeValue::generate(Context *context)
{
    value = DOMValue::menu_item_type();
}

void HIRMutate::HTML::MetaSchemeValue::generate(Context *context)
{
    value = DOMValue::meta_scheme();
}

void HIRMutate::HTML::MenuTypeValue::generate(Context *context)
{
    value = DOMValue::menu_type();
}

void HIRMutate::HTML::ParamValueTypeValue::generate(Context *context)
{
    value = DOMValue::param_value_type();
}

void HIRMutate::HTML::WrapValue::generate(Context *context)
{
    value = DOMValue::wrap();
}

void HIRMutate::HTML::SrcSetValue::generate(Context *context)
{
    value = DOMValue::srcset();
}

void HIRMutate::HTML::TableFrameValue::generate(Context *context)
{
    value = DOMValue::table_frame();
}

void HIRMutate::HTML::TableRulesValue::generate(Context *context)
{
    value = DOMValue::table_rules();
}

void HIRMutate::HTML::TableScopeValue::generate(Context *context)
{
    value = DOMValue::table_scope();
}

void HIRMutate::HTML::TrackKindValue::generate(Context *context)
{
    value = DOMValue::track_kind();
}

void HIRMutate::HTML::UListTypeValue::generate(Context *context)
{
    value = DOMValue::ulist_type();
}

void HIRMutate::HTML::VideoControlsListValue::generate(Context *context)
{
    static const char *strs[] = {"nodownload", "nofullscreen", "noremoteplayback"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::TabIndexValue::generate(Context *context)
{
    value = DOMValue::tab_index();
}

void HIRMutate::HTML::CharsetValue::generate(Context *context)
{
    value = DOMValue::charset();
}

void HIRMutate::HTML::ClearValue::generate(Context *context)
{
    value = DOMValue::clear();
}

//ARIA

void HIRMutate::HTML::AriaAutocompleteValue::generate(Context *context)
{
    static const char *strs[] = {"inline", "list", "both"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaCheckedValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false", "mixed", "undefined"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaCurrentValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false", "page", "step", "location", "date", "time"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaDropeffectValue::generate(Context *context)
{
    static const char *strs[] = {"copy", "execute", "link", "move", "popup"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaExpandedValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaGrabbedValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaHaspopupValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false", "menu", "listbox", "tree", "grid", "dialog"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaHiddenValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaInvalidValue::generate(Context *context)
{
    static const char *strs[] = {"true", "false", "grammar", "spelling"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaLabelValue::generate(Context *context)
{
    static const char *strs[] = {"", "face", "left-eye", "right-eye", "nose", "smile"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaLiveValue::generate(Context *context)
{
    static const char *strs[] = {"assertive", "off", "polite"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaOrientationValue::generate(Context *context)
{
    static const char *strs[] = {"horizontal", "vertical"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaPressedValue::generate(Context *context)
{
    static const char *strs[] = {"false", "mixed", "true"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaRelevantValue::generate(Context *context)
{
    static const char *strs[] = {"additions", "additions text", "all", "removals", "text"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaSelectedValue::generate(Context *context)
{
    static const char *strs[] = {"false", "true"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::AriaSortValue::generate(Context *context)
{
    static const char *strs[] = {"ascending", "descending", "other"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::RoleValue::generate(Context *context)
{
    static const char *strs[] = {"treegrid", "checkbox", "radiogroup", "text", "menuitemcheckbox", "spinbutton", "radio", "slider", "tab",
                                 "listbox", "checkbox", "textbox", "group", "log", "img", "combobox", "columnheader", "tooltip", "note",
                                 "application", "listitem", "row", "presentation", "menuitem", "searchbox", "treeitem", "status", "main",
                                 "rowheader", "option", "form", "complementary", "gridcell", "contentinfo", "alert", "alertdialog",
                                 "link", "article", "banner", "toolbar", "menuitemradio", "definition", "search", "dom", "tree",
                                 "marquee", "menubar", "button", "list", "timer", "progressbar", "scrollbar", "separator", "math", "dialog",
                                 "menu", "directory", "grid", "tablist", "region", "navigation", "heading", "tabpanel", "unknown"};
    value = CHOICE(strs);
}

void HIRMutate::HTML::DateTimeValue::generate(Context *context)
{
    value = DOMValue::date_time();
}

void HIRMutate::HTML::ClassValue::generate(Context *context)
{
    value = ((DOMContext *)context)->get_token("class");
}

//FIXME : multiple part names
void HIRMutate::HTML::PartValue::generate(Context *context)
{
    value = ((DOMContext *)context)->get_token("part");
}

void HIRMutate::HTML::RadioGroupValue::generate(Context *context)
{
    value = ((DOMContext *)context)->get_token("radiogroup");
}

void HIRMutate::HTML::TableAxisValue::generate(Context *context)
{
    value = ((DOMContext *)context)->get_token("axis");
}

void HIRMutate::HTML::MediaTypeValue::generate(Context *context)
{
    value = DOMValue::media_type();
}

void HIRMutate::HTML::CSSTypeValue::generate(Context *context)
{
    value = DOMValue::css_type();
}

void HIRMutate::HTML::MIMETypeValue::generate(Context *context)
{
    value = DOMValue::mime_type();
}

void HIRMutate::HTML::MediaQueryValue::generate(Context *context)
{
    value = DOMValue::media_query();
}

void HIRMutate::HTML::NonceValue::generate(Context *context)
{
    static const char *strs[] = {"A", "B", "C"};
    value = CHOICE(strs);
}

/*
*Dynamic values
*/

HIRMutate::HTML::SlotValue::SlotValue() : DynamicValue()
{
    slot = nullptr;
}

void HIRMutate::HTML::SlotValue::generate(Context *context)
{
    slot = context->get_object("HTMLSlotElement");
}

void HIRMutate::HTML::SlotValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (slot)
    {
        if (merge_map.find(slot) != merge_map.end())
            slot = merge_map[slot];
    }
}
string HIRMutate::HTML::SlotValue::getValue()
{
    if (slot == nullptr)
        return "foo";
    return slot->id;
}

HIRMutate::HTML::UseMapValue::UseMapValue() : DynamicValue()
{
    umap = nullptr;
}

void HIRMutate::HTML::UseMapValue::generate(Context *context)
{
    this->umap = context->get_object("HTMLMapElement");
}

void HIRMutate::HTML::UseMapValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (umap)
    {
        if (merge_map.find(umap) != merge_map.end())
            umap = merge_map[umap];
    }
}

string HIRMutate::HTML::UseMapValue::getValue()
{
    if (umap == nullptr)
        return "#foo";
    string ans;
    ans.append("#");
    ans.append(umap->id);
    return ans;
}

HIRMutate::HTML::ElementIDValue::ElementIDValue() : DynamicValue()
{
    this->elem = nullptr;
}

void HIRMutate::HTML::ElementIDValue::generate(Context *context)
{
    this->elem = context->get_object(DOC::elements);
}

void HIRMutate::HTML::ElementIDValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

string HIRMutate::HTML::ElementIDValue::getValue()
{
    if (this->elem == nullptr)
        return "foo";
    return this->elem->id;
}

HIRMutate::HTML::EventHandlerValue::EventHandlerValue() : DynamicValue()
{
    this->eh = nullptr;
}

void HIRMutate::HTML::EventHandlerValue::generate(Context *context)
{
    this->eh = context->get_object("EventHandler");
}

bool HIRMutate::HTML::EventHandlerValue::mutate(Context *context)
{
    return false;
}

void HIRMutate::HTML::EventHandlerValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (eh)
    {
        if (merge_map.find(eh) != merge_map.end())
            eh = merge_map[eh];
    }
}
string HIRMutate::HTML::EventHandlerValue::getValue()
{
    if (this->eh == nullptr)
    {
        return "evfoo";
    }
    return eh->id;
}

HIRMutate::HTML::CallEventHandlerValue::CallEventHandlerValue() : DynamicValue()
{
    this->eh = nullptr;
}

void HIRMutate::HTML::CallEventHandlerValue::generate(Context *context)
{
    this->eh = context->get_object("EventHandler");
}

bool HIRMutate::HTML::CallEventHandlerValue::mutate(Context *context)
{
    return false;
}

void HIRMutate::HTML::CallEventHandlerValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (eh)
    {
        if (merge_map.find(eh) != merge_map.end())
            eh = merge_map[eh];
    }
}

string HIRMutate::HTML::CallEventHandlerValue::getValue()
{
    if (this->eh == nullptr)
        return "ehfoo";
    string ans = eh->id;
    ans.append("()");
    return ans;
}

HIRMutate::HTML::ContextMenuValue::ContextMenuValue() : DynamicValue()
{
    this->menu = nullptr;
}

void HIRMutate::HTML::ContextMenuValue::generate(Context *context)
{
    this->menu = context->get_object("HTMLMenuElement");
}
void HIRMutate::HTML::ContextMenuValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (menu)
    {
        if (merge_map.find(menu) != merge_map.end())
            menu = merge_map[menu];
    }
}

string HIRMutate::HTML::ContextMenuValue::getValue()
{
    if (this->menu == nullptr)
        return "foo";
    return this->menu->id;
}

HIRMutate::HTML::FormValue::FormValue() : DynamicValue()
{
    this->form = nullptr;
}
void HIRMutate::HTML::FormValue::generate(Context *context)
{
    this->form = context->get_object("HTMLFormElement");
}
void HIRMutate::HTML::FormValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (form)
    {
        if (merge_map.find(form) != merge_map.end())
            form = merge_map[form];
    }
}

string HIRMutate::HTML::FormValue::getValue()
{
    if (this->form == nullptr)
        return "foo";
    return this->form->id;
}

HIRMutate::HTML::ContentSelectValue::ContentSelectValue() : DynamicValue()
{
    this->elem = nullptr;
}
void HIRMutate::HTML::ContentSelectValue::generate(Context *context)
{
    if (Random::gbool())
    {
        this->cla = ((DOMContext *)context)->get_token("class");
    }
    else
    {
        this->elem = context->get_object(DOC::elements);
    }
}

void HIRMutate::HTML::ContentSelectValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

string HIRMutate::HTML::ContentSelectValue::getValue()
{
    string ans;
    if (this->cla == "")
    {
        ans = ".";
        ans.append(cla);
    }
    else if (this->elem)
    {
        ans = "#";
        ans.append(elem->id);
    }
    else
    {
        ans = "#foo";
    }
    return ans;
}

HIRMutate::HTML::ListValue::ListValue() : DynamicValue()
{
    this->dl = nullptr;
}

void HIRMutate::HTML::ListValue::generate(Context *context)
{
    this->dl = context->get_object("HTMLDataListElement");
}

void HIRMutate::HTML::ListValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (dl)
    {
        if (merge_map.find(dl) != merge_map.end())
            dl = merge_map[dl];
    }
}

string HIRMutate::HTML::ListValue::getValue()
{
    if (this->dl == nullptr)
        return "foo";
    return this->dl->id;
}

HIRMutate::HTML::LabelForValue::LabelForValue() : DynamicValue()
{
    this->elem = nullptr;
}

void HIRMutate::HTML::LabelForValue::generate(Context *context)
{
    this->elem = context->get_object(DOC::html_labelable_elements);
}

void HIRMutate::HTML::LabelForValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

string HIRMutate::HTML::LabelForValue::getValue()
{
    if (this->elem == nullptr)
        return "foo";
    return this->elem->id;
}

HIRMutate::HTML::CommandValue::CommandValue() : DynamicValue()
{
    this->command = nullptr;
}

void HIRMutate::HTML::CommandValue::generate(Context *context)
{
    this->command = context->get_object("HTMLCommandElement");
}

void HIRMutate::HTML::CommandValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (command)
    {
        if (merge_map.find(command) != merge_map.end())
            command = merge_map[command];
    }
}

string HIRMutate::HTML::CommandValue::getValue()
{
    if (this->command == nullptr)
        return "foo";
    return this->command->id;
}

HIRMutate::HTML::ElementIDListValue::ElementIDListValue() : DynamicValue(){

                                                            };

void HIRMutate::HTML::ElementIDListValue::append_element(Context *context)
{
    Object *element = context->get_object(DOC::elements);
    if (element != nullptr && find(elements.begin(), elements.end(), element) == elements.end())
    {
        elements.push_back(element);
    }
}

void HIRMutate::HTML::ElementIDListValue::generate(Context *context)
{
    append_element(context);
}

bool HIRMutate::HTML::ElementIDListValue::mutate(Context *context)
{
    if (this->elements.size() == 0 || Random::gbool())
    {
        //1. add one
        append_element(context);
    }
    else
    {
        // 2. replace one
        elements.erase(elements.begin() + Random::selector(this->elements.size()));
        append_element(context);
    }
    return true;
}
void HIRMutate::HTML::ElementIDListValue::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(elements.begin(), elements.end(),
                  [&merge_map](Object *&obj)
                  {
                      if (merge_map.find(obj) != merge_map.end())
                      {
                          obj = merge_map[obj];
                      }
                  });
}
string HIRMutate::HTML::ElementIDListValue::getValue()
{
    string ans = "";
    std::for_each(elements.begin(), elements.end(),
                  [&ans](Object *obj)
                  {
                      ans.append(obj->id);
                      ans.append(" ");
                  });
    return ans;
}

HIRMutate::HTML::TableHeadersValue::TableHeadersValue()
{
}

void HIRMutate::HTML::TableHeadersValue::append_th(Context *context)
{
    Object *elem = context->get_object("HTMLTableHeaderCellElement");
    if (elem != nullptr && find(ths.begin(), ths.end(), elem) == ths.end())
        ths.push_back(elem);
}

void HIRMutate::HTML::TableHeadersValue::generate(Context *context)
{
    append_th(context);
}

bool HIRMutate::HTML::TableHeadersValue::mutate(Context *context)
{
    if (ths.size() == 0 or Random::gbool())
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

void HIRMutate::HTML::TableHeadersValue::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(ths.begin(), ths.end(),
                  [&merge_map](Object *&obj)
                  {
                      if (merge_map.find(obj) != merge_map.end())
                      {
                          obj = merge_map[obj];
                      }
                  });
}

string HIRMutate::HTML::TableHeadersValue::getValue()
{
    string ans = "";
    std::for_each(ths.begin(), ths.end(),
                  [&ans](Object *obj)
                  {
                      ans.append(obj->id);
                      ans.append(" ");
                  });
    return ans;
}

HIRMutate::HTML::TargetValue::TargetValue() : DynamicValue()
{
    this->frame = nullptr;
}
void HIRMutate::HTML::TargetValue::generate(Context *context)
{
    vector<string> vec;
    vec.push_back("HTMLFrameElement");
    vec.push_back("HTMLIFrameElement");
    frame = context->get_object(vec);
}
void HIRMutate::HTML::TargetValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (frame)
    {
        if (merge_map.find(frame) != merge_map.end())
            frame = merge_map[frame];
    }
}

string HIRMutate::HTML::TargetValue::getValue()
{
    if (frame == nullptr)
        return "foo";
    return frame->id;
}

//序列化
void HIRMutate::HTML::ShapeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ShapeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::CoordsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CoordsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ImageSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::LangValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LangValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ReferrerPolicyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ReferrerPolicyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AcceptValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AcceptValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::PreloadValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PreloadValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::VideoSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VideoSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AudioSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AudioSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::FrameSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FrameSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::SoundLoopValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SoundLoopValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AutoCapitalizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AutoCapitalizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ButtonTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ButtonTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::CaptionAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CaptionAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TableAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::VAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::CommandTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CommandTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TrackSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TrackSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MediaSrcValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MediaSrcValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ImportanceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImportanceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::LoadingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LoadingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::DirValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DirValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::DropZoneValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DropZoneValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::InputModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InputModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::FormEncTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FormEncTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::FormMethodValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FormMethodValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ObjectAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ObjectAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::SizesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SizesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ScrollingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ImageDecodingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageDecodingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::IntrinsicSizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("IntrinsicSizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::InputTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InputTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AutoCompleteValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AutoCompleteValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::InputCaptureValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InputCaptureValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::KeyTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("KeyTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::NumberingTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("NumberingTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::LinkAsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LinkAsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::RelValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RelValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::RevValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RevValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MarqueeBehaviorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarqueeBehaviorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MarqueeDirectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarqueeDirectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MarqueeLoopValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarqueeLoopValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MenuItemTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MenuItemTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MetaSchemeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MetaSchemeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MenuTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MenuTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ParamValueTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ParamValueTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::WrapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WrapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::SrcSetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SrcSetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TableFrameValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableFrameValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TableRulesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableRulesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TableScopeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableScopeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TrackKindValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TrackKindValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::UListTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UListTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::VideoControlsListValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VideoControlsListValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TabIndexValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TabIndexValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::CharsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CharsetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ClearValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HTML::ClearValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaAutocompleteValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaAutocompleteValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaCheckedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaCheckedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaCurrentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaCurrentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaDropeffectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaDropeffectValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaExpandedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaExpandedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaGrabbedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaGrabbedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaHaspopupValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaHaspopupValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaHiddenValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaHiddenValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaInvalidValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaInvalidValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaLabelValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaLabelValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaLiveValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaLiveValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaOrientationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaOrientationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaPressedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaPressedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaRelevantValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaRelevantValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaSelectedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaSelectedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::AriaSortValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AriaSortValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::RoleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RoleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::DateTimeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DateTimeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::ClassValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClassValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::PartValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PartValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::RadioGroupValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RadioGroupValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::TableAxisValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableAxisValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MediaTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MediaTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::CSSTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MIMETypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MIMETypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::MediaQueryValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MediaQueryValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::NonceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("NonceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::HTML::SlotValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SlotValue");
    DynamicValue::serialize(stream, context);
    if (slot)
        slot->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::SlotValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
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
void HIRMutate::HTML::UseMapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UseMapValue");
    DynamicValue::serialize(stream, context);
    if (umap)
        umap->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::UseMapValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        umap = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&umap, global_document);
    }
}
void HIRMutate::HTML::ElementIDValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ElementIDValue");
    DynamicValue::serialize(stream, context);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::ElementIDValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
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
void HIRMutate::HTML::EventHandlerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("EventHandlerValue");
    DynamicValue::serialize(stream, context);
    if (eh)
        eh->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::EventHandlerValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        eh = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&eh, global_document);
    }
}
void HIRMutate::HTML::CallEventHandlerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CallEventHandlerValue");
    DynamicValue::serialize(stream, context);
    if (eh)
        eh->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::CallEventHandlerValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        eh = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&eh, global_document);
    }
}
void HIRMutate::HTML::ContextMenuValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ContextMenuValue");
    DynamicValue::serialize(stream, context);
    if (menu)
        menu->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::ContextMenuValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        menu = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&menu, global_document);
    }
}
void HIRMutate::HTML::FormValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FormValue");
    DynamicValue::serialize(stream, context);
    if (form)
        form->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::FormValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        form = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&form, global_document);
    }
}
void HIRMutate::HTML::ContentSelectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ContentSelectValue");
    DynamicValue::serialize(stream, context);
    stream->write_string(cla);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::ContentSelectValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    cla = stream->read_string();
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
void HIRMutate::HTML::ListValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ListValue");
    DynamicValue::serialize(stream, context);
    if (dl)
        dl->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::ListValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        dl = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&dl, global_document);
    }
}
void HIRMutate::HTML::LabelForValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LabelForValue");
    DynamicValue::serialize(stream, context);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::LabelForValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
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
void HIRMutate::HTML::CommandValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CommandValue");
    DynamicValue::serialize(stream, context);
    if (command)
        command->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::CommandValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        command = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&command, global_document);
    }
}
void HIRMutate::HTML::ElementIDListValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ElementIDListValue");
    DynamicValue::serialize(stream, context);
    stream->write_int(elements.size());
    std::for_each(elements.begin(), elements.end(),
                  [&stream, &context](Object *obj)
                  {
                      obj->serialize_weak(stream, context);
                  });
}
void HIRMutate::HTML::ElementIDListValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    int ele_n = stream->read_int();
    for (int i = 0; i < ele_n; i++)
    {
        elements.push_back(nullptr);
        stream->read_obj_ref((size_t)&elements[i], global_document);
    }
}
void HIRMutate::HTML::TableHeadersValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableHeadersValue");
    DynamicValue::serialize(stream, context);
    stream->write_int(ths.size());
    std::for_each(ths.begin(), ths.end(),
                  [&stream, &context](Object *obj)
                  {
                      obj->serialize_weak(stream, context);
                  });
}
void HIRMutate::HTML::TableHeadersValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    int ths_n = stream->read_int();
    for (int i = 0; i < ths_n; i++)
    {
        ths.push_back(nullptr);
        stream->read_obj_ref((size_t)&ths[i], global_document);
    }
}
void HIRMutate::HTML::TargetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TargetValue");
    DynamicValue::serialize(stream, context);
    if (frame)
        frame->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::HTML::TargetValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        frame = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&frame, global_document);
    }
}

void *HIRMutate::HTML::ShapeValue::getConstructor()
{
    return HANDLE_VOID(ShapeValue);
}
void *HIRMutate::HTML::CoordsValue::getConstructor()
{
    return HANDLE_VOID(CoordsValue);
}
void *HIRMutate::HTML::ImageSrcValue::getConstructor()
{
    return HANDLE_VOID(ImageSrcValue);
}
void *HIRMutate::HTML::LangValue::getConstructor()
{
    return HANDLE_VOID(LangValue);
}
void *HIRMutate::HTML::ReferrerPolicyValue::getConstructor()
{
    return HANDLE_VOID(ReferrerPolicyValue);
}
void *HIRMutate::HTML::AcceptValue::getConstructor()
{
    return HANDLE_VOID(AcceptValue);
}
void *HIRMutate::HTML::PreloadValue::getConstructor()
{
    return HANDLE_VOID(PreloadValue);
}
void *HIRMutate::HTML::VideoSrcValue::getConstructor()
{
    return HANDLE_VOID(VideoSrcValue);
}
void *HIRMutate::HTML::AudioSrcValue::getConstructor()
{
    return HANDLE_VOID(AudioSrcValue);
}
void *HIRMutate::HTML::FrameSrcValue::getConstructor()
{
    return HANDLE_VOID(FrameSrcValue);
}
void *HIRMutate::HTML::SoundLoopValue::getConstructor()
{
    return HANDLE_VOID(SoundLoopValue);
}
void *HIRMutate::HTML::AutoCapitalizeValue::getConstructor()
{
    return HANDLE_VOID(AutoCapitalizeValue);
}
void *HIRMutate::HTML::ButtonTypeValue::getConstructor()
{
    return HANDLE_VOID(ButtonTypeValue);
}
void *HIRMutate::HTML::CaptionAlignValue::getConstructor()
{
    return HANDLE_VOID(CaptionAlignValue);
}
void *HIRMutate::HTML::TableAlignValue::getConstructor()
{
    return HANDLE_VOID(TableAlignValue);
}
void *HIRMutate::HTML::VAlignValue::getConstructor()
{
    return HANDLE_VOID(VAlignValue);
}
void *HIRMutate::HTML::CommandTypeValue::getConstructor()
{
    return HANDLE_VOID(CommandTypeValue);
}
void *HIRMutate::HTML::TrackSrcValue::getConstructor()
{
    return HANDLE_VOID(TrackSrcValue);
}
void *HIRMutate::HTML::MediaSrcValue::getConstructor()
{
    return HANDLE_VOID(MediaSrcValue);
}
void *HIRMutate::HTML::ImportanceValue::getConstructor()
{
    return HANDLE_VOID(ImportanceValue);
}
void *HIRMutate::HTML::LoadingValue::getConstructor()
{
    return HANDLE_VOID(LoadingValue);
}
void *HIRMutate::HTML::DirValue::getConstructor()
{
    return HANDLE_VOID(DirValue);
}
void *HIRMutate::HTML::DropZoneValue::getConstructor()
{
    return HANDLE_VOID(DropZoneValue);
}
void *HIRMutate::HTML::InputModeValue::getConstructor()
{
    return HANDLE_VOID(InputModeValue);
}
void *HIRMutate::HTML::FormEncTypeValue::getConstructor()
{
    return HANDLE_VOID(FormEncTypeValue);
}
void *HIRMutate::HTML::FormMethodValue::getConstructor()
{
    return HANDLE_VOID(FormMethodValue);
}
void *HIRMutate::HTML::AlignValue::getConstructor()
{
    return HANDLE_VOID(AlignValue);
}
void *HIRMutate::HTML::ObjectAlignValue::getConstructor()
{
    return HANDLE_VOID(ObjectAlignValue);
}
void *HIRMutate::HTML::SizesValue::getConstructor()
{
    return HANDLE_VOID(SizesValue);
}
void *HIRMutate::HTML::ScrollingValue::getConstructor()
{
    return HANDLE_VOID(ScrollingValue);
}
void *HIRMutate::HTML::ImageDecodingValue::getConstructor()
{
    return HANDLE_VOID(ImageDecodingValue);
}
void *HIRMutate::HTML::IntrinsicSizeValue::getConstructor()
{
    return HANDLE_VOID(IntrinsicSizeValue);
}
void *HIRMutate::HTML::InputTypeValue::getConstructor()
{
    return HANDLE_VOID(InputTypeValue);
}
void *HIRMutate::HTML::AutoCompleteValue::getConstructor()
{
    return HANDLE_VOID(AutoCompleteValue);
}
void *HIRMutate::HTML::InputCaptureValue::getConstructor()
{
    return HANDLE_VOID(InputCaptureValue);
}
void *HIRMutate::HTML::KeyTypeValue::getConstructor()
{
    return HANDLE_VOID(KeyTypeValue);
}
void *HIRMutate::HTML::NumberingTypeValue::getConstructor()
{
    return HANDLE_VOID(NumberingTypeValue);
}
void *HIRMutate::HTML::LinkAsValue::getConstructor()
{
    return HANDLE_VOID(LinkAsValue);
}
void *HIRMutate::HTML::RelValue::getConstructor()
{
    return HANDLE_VOID(RelValue);
}
void *HIRMutate::HTML::RevValue::getConstructor()
{
    return HANDLE_VOID(RevValue);
}
void *HIRMutate::HTML::MarqueeBehaviorValue::getConstructor()
{
    return HANDLE_VOID(MarqueeBehaviorValue);
}
void *HIRMutate::HTML::MarqueeDirectionValue::getConstructor()
{
    return HANDLE_VOID(MarqueeDirectionValue);
}
void *HIRMutate::HTML::MarqueeLoopValue::getConstructor()
{
    return HANDLE_VOID(MarqueeLoopValue);
}
void *HIRMutate::HTML::MenuItemTypeValue::getConstructor()
{
    return HANDLE_VOID(MenuItemTypeValue);
}
void *HIRMutate::HTML::MetaSchemeValue::getConstructor()
{
    return HANDLE_VOID(MetaSchemeValue);
}
void *HIRMutate::HTML::MenuTypeValue::getConstructor()
{
    return HANDLE_VOID(MenuTypeValue);
}
void *HIRMutate::HTML::ParamValueTypeValue::getConstructor()
{
    return HANDLE_VOID(ParamValueTypeValue);
}
void *HIRMutate::HTML::WrapValue::getConstructor()
{
    return HANDLE_VOID(WrapValue);
}
void *HIRMutate::HTML::SrcSetValue::getConstructor()
{
    return HANDLE_VOID(SrcSetValue);
}
void *HIRMutate::HTML::TableFrameValue::getConstructor()
{
    return HANDLE_VOID(TableFrameValue);
}
void *HIRMutate::HTML::TableRulesValue::getConstructor()
{
    return HANDLE_VOID(TableRulesValue);
}
void *HIRMutate::HTML::TableScopeValue::getConstructor()
{
    return HANDLE_VOID(TableScopeValue);
}
void *HIRMutate::HTML::TrackKindValue::getConstructor()
{
    return HANDLE_VOID(TrackKindValue);
}
void *HIRMutate::HTML::UListTypeValue::getConstructor()
{
    return HANDLE_VOID(UListTypeValue);
}
void *HIRMutate::HTML::VideoControlsListValue::getConstructor()
{
    return HANDLE_VOID(VideoControlsListValue);
}
void *HIRMutate::HTML::TabIndexValue::getConstructor()
{
    return HANDLE_VOID(TabIndexValue);
}
void *HIRMutate::HTML::CharsetValue::getConstructor()
{
    return HANDLE_VOID(CharsetValue);
}
void *HIRMutate::HTML::ClearValue::getConstructor()
{
    return HANDLE_VOID(ClearValue);
}
void *HIRMutate::HTML::AriaAutocompleteValue::getConstructor()
{
    return HANDLE_VOID(AriaAutocompleteValue);
}
void *HIRMutate::HTML::AriaCheckedValue::getConstructor()
{
    return HANDLE_VOID(AriaCheckedValue);
}
void *HIRMutate::HTML::AriaCurrentValue::getConstructor()
{
    return HANDLE_VOID(AriaCurrentValue);
}
void *HIRMutate::HTML::AriaDropeffectValue::getConstructor()
{
    return HANDLE_VOID(AriaDropeffectValue);
}
void *HIRMutate::HTML::AriaExpandedValue::getConstructor()
{
    return HANDLE_VOID(AriaExpandedValue);
}
void *HIRMutate::HTML::AriaGrabbedValue::getConstructor()
{
    return HANDLE_VOID(AriaGrabbedValue);
}
void *HIRMutate::HTML::AriaHaspopupValue::getConstructor()
{
    return HANDLE_VOID(AriaHaspopupValue);
}
void *HIRMutate::HTML::AriaHiddenValue::getConstructor()
{
    return HANDLE_VOID(AriaHiddenValue);
}
void *HIRMutate::HTML::AriaInvalidValue::getConstructor()
{
    return HANDLE_VOID(AriaInvalidValue);
}
void *HIRMutate::HTML::AriaLabelValue::getConstructor()
{
    return HANDLE_VOID(AriaLabelValue);
}
void *HIRMutate::HTML::AriaLiveValue::getConstructor()
{
    return HANDLE_VOID(AriaLiveValue);
}
void *HIRMutate::HTML::AriaOrientationValue::getConstructor()
{
    return HANDLE_VOID(AriaOrientationValue);
}
void *HIRMutate::HTML::AriaPressedValue::getConstructor()
{
    return HANDLE_VOID(AriaPressedValue);
}
void *HIRMutate::HTML::AriaRelevantValue::getConstructor()
{
    return HANDLE_VOID(AriaRelevantValue);
}
void *HIRMutate::HTML::AriaSelectedValue::getConstructor()
{
    return HANDLE_VOID(AriaSelectedValue);
}
void *HIRMutate::HTML::AriaSortValue::getConstructor()
{
    return HANDLE_VOID(AriaSortValue);
}
void *HIRMutate::HTML::RoleValue::getConstructor()
{
    return HANDLE_VOID(RoleValue);
}
void *HIRMutate::HTML::DateTimeValue::getConstructor()
{
    return HANDLE_VOID(DateTimeValue);
}
void *HIRMutate::HTML::ClassValue::getConstructor()
{
    return HANDLE_VOID(ClassValue);
}
void *HIRMutate::HTML::PartValue::getConstructor()
{
    return HANDLE_VOID(PartValue);
}
void *HIRMutate::HTML::RadioGroupValue::getConstructor()
{
    return HANDLE_VOID(RadioGroupValue);
}
void *HIRMutate::HTML::TableAxisValue::getConstructor()
{
    return HANDLE_VOID(TableAxisValue);
}
void *HIRMutate::HTML::MediaTypeValue::getConstructor()
{
    return HANDLE_VOID(MediaTypeValue);
}
void *HIRMutate::HTML::CSSTypeValue::getConstructor()
{
    return HANDLE_VOID(CSSTypeValue);
}
void *HIRMutate::HTML::MIMETypeValue::getConstructor()
{
    return HANDLE_VOID(MIMETypeValue);
}
void *HIRMutate::HTML::MediaQueryValue::getConstructor()
{
    return HANDLE_VOID(MediaQueryValue);
}
void *HIRMutate::HTML::NonceValue::getConstructor()
{
    return HANDLE_VOID(NonceValue);
}
void *HIRMutate::HTML::SlotValue::getConstructor()
{
    return HANDLE_VOID(SlotValue);
}
void *HIRMutate::HTML::UseMapValue::getConstructor()
{
    return HANDLE_VOID(UseMapValue);
}
void *HIRMutate::HTML::DummyUrlValue::getConstructor()
{
    return HANDLE_VOID(DummyUrlValue);
}
void *HIRMutate::HTML::ElementIDValue::getConstructor()
{
    return HANDLE_VOID(ElementIDValue);
}
void *HIRMutate::HTML::EventHandlerValue::getConstructor()
{
    return HANDLE_VOID(EventHandlerValue);
}
void *HIRMutate::HTML::CallEventHandlerValue::getConstructor()
{
    return HANDLE_VOID(CallEventHandlerValue);
}
void *HIRMutate::HTML::ContextMenuValue::getConstructor()
{
    return HANDLE_VOID(ContextMenuValue);
}
void *HIRMutate::HTML::FormValue::getConstructor()
{
    return HANDLE_VOID(FormValue);
}
void *HIRMutate::HTML::ContentSelectValue::getConstructor()
{
    return HANDLE_VOID(ContentSelectValue);
}
void *HIRMutate::HTML::ListValue::getConstructor()
{
    return HANDLE_VOID(ListValue);
}
void *HIRMutate::HTML::LabelForValue::getConstructor()
{
    return HANDLE_VOID(LabelForValue);
}
void *HIRMutate::HTML::CommandValue::getConstructor()
{
    return HANDLE_VOID(CommandValue);
}
void *HIRMutate::HTML::ElementIDListValue::getConstructor()
{
    return HANDLE_VOID(ElementIDListValue);
}
void *HIRMutate::HTML::TableHeadersValue::getConstructor()
{
    return HANDLE_VOID(TableHeadersValue);
}
void *HIRMutate::HTML::TargetValue::getConstructor()
{
    return HANDLE_VOID(TargetValue);
}