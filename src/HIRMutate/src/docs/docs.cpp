#include "docs.h"
#include "html_symbols.h"
#include "svg_symbols.h"
#include "hierarchy.h"
#include "css_symbols.h"
#include <algorithm>
#include <assert.h>

namespace HIRMutate
{
    namespace DOC
    {
        vector<string> &html_tags = HIRMutate::DOC::HTML::html_tags;
        vector<string> &html_elements = HIRMutate::DOC::HTML::html_elements;
        vector<string> &html_general_child_elements = HIRMutate::DOC::HTML::html_general_child_elements;
        vector<string> &html_other_child_elements = HIRMutate::DOC::HTML::html_other_child_elements;
        map<string, vector<string> > &html_child_elements = HIRMutate::DOC::HTML::html_child_elements;
        vector<string> &html_labelable_elements = HIRMutate::DOC::HTML::html_labelable_elements;
        map<string, string> &html_elem_to_tag_map = HIRMutate::DOC::HTML::html_element_map;
        map<string, string> &html_tag_to_elem_map = HIRMutate::DOC::HTML::html_tag_to_elem_map;
        vector<string> &html_block_elements = HIRMutate::DOC::HTML::block_elements;
        vector<string> &html_link_elements = HIRMutate::DOC::HTML::link_elements;
        vector<string> &html_submittable_elements = HIRMutate::DOC::HTML::submittable_elements;

        //SVG
        vector<string> &svg_tags = HIRMutate::DOC::SVG::svg_tags;
        vector<string> &svg_elements = HIRMutate::DOC::SVG::svg_elements_k;
        map<string, vector<string> > &svg_child_elements = HIRMutate::DOC::SVG::svg_child_elements;
        vector<string> &svg_animation_elements = HIRMutate::DOC::SVG::svg_animation_elements;
        vector<string> &svg_paint_server_elements = HIRMutate::DOC::SVG::svg_paint_server_elements;
        vector<string> &svg_shape_elements = HIRMutate::DOC::SVG::svg_shape_elements;
        vector<string> svg_gradient_elements = {"SVGLinearGradientElement", "SVGRadialGradientElement"};
        vector<string> &svg_text_content_elements = HIRMutate::DOC::SVG::svg_text_content_elements;
        vector<string> &svg_filter_primitives = HIRMutate::DOC::SVG::svg_filter_primitives;

        map<string, string> &svg_elem_to_tag_map = HIRMutate::DOC::SVG::svg_elements;
        map<string, string> &svg_tag_to_elem_map = HIRMutate::DOC::SVG::svg_tag_to_elem_map;

        vector<string> &svg_animation_begin_events = HIRMutate::DOC::SVG::svg_animation_begin_events;
        vector<string> &svg_animatable_attributes = HIRMutate::DOC::SVG::svg_animatable_attributes;
        vector<string> &svg_animatable_transform_attributes = HIRMutate::DOC::SVG::svg_animatable_transform_attributes;

        vector<string> &svg_ariable_elements = HIRMutate::DOC::SVG::svg_ariable_elements;

        vector<string> elements;

        vector<string> image_elements = {"HTMLImageElement", "SVGImageElement"};

        //CSS
        vector<string> &css_animatable_properties = DOC::CSS::css_animatable_properties;

        //Event
        //TODO: composition events
        vector<string> text_events = {"textInput"};
        vector<string> base_ui_events = {"load", "unload", "abort", "error", "select"};
        vector<string> mouse_events = {"click", "mousedown", "mouseup", "mouseover", "mousemove", "mouseout"};
        vector<string> focus_events = {"blur", "focus", "focusin", "focusout"};
        vector<string> wheel_events = {"wheel"};
        vector<string> input_events = {"beforeinput", "input"};
        vector<string> keyboard_events = {"keydown", "keyup", "keypress"};
        vector<string> composition_events = {"compositionstart", "compositionupdate", "compositionend"};
        vector<string> ui_events;
        vector<string> mutation_events = {"DOMSubtreeModified", "DOMNodeInserted", "DOMNodeRemoved", "DOMAttrModified", "DOMCharacterDataModified"};

    }
}

void HIRMutate::DOC::init()
{
    DOC::HTML::initSym();
    DOC::SVG::initSym();
    DOC::CSS::initSym();
    DOC::HIERARCHY::initSym();
    elements = html_elements;
    elements.insert(elements.end(), svg_elements.begin(), svg_elements.end());

    ui_events = base_ui_events;
    ui_events.insert(ui_events.end(), mouse_events.begin(), mouse_events.end());
    ui_events.insert(ui_events.end(), focus_events.begin(), focus_events.end());
    ui_events.insert(ui_events.end(), wheel_events.begin(), wheel_events.end());
    ui_events.insert(ui_events.end(), input_events.begin(), input_events.end());
    ui_events.insert(ui_events.end(), keyboard_events.begin(), keyboard_events.end());
    ui_events.insert(ui_events.end(), composition_events.begin(), composition_events.end());
}

vector<string> HIRMutate::DOC::get_object_ancestors(const string &name)
{
    vector<string> vec;
    vec.push_back(name);
    map<string, vector<string> > &OFFSPRINGS = HIRMutate::DOC::HIERARCHY::offsprings;
    if (OFFSPRINGS.find(name) != OFFSPRINGS.end())
    {
        vector<string> &v = OFFSPRINGS[name];
        vec.insert(vec.end(), v.begin(), v.end());
    }
    return vec;
}

vector<string> HIRMutate::DOC::get_object_offsprings(const string &name)
{
    vector<string> vec;
    vec.push_back(name);
    map<string, vector<string> > &ANCESTORS = HIRMutate::DOC::HIERARCHY::ancestors;
    if (ANCESTORS.find(name) != ANCESTORS.end())
    {
        vector<string> &v = ANCESTORS[name];
        vec.insert(vec.end(), v.begin(), v.end());
    }
    return vec;
}

string HIRMutate::DOC::tag_from_element(const string &elem)
{
    if (find(svg_elements.begin(), svg_elements.end(), elem) != svg_elements.end())
        return svg_tag_from_element(elem);
    else if (find(html_elements.begin(), html_elements.end(), elem) != html_elements.end())
        return html_tag_from_element(elem);
    else
    {
        puts("DOC::tag_from_element Error!");
        abort();
    }
}

string HIRMutate::DOC::html_tag_from_element(const string &elem)
{
    return html_elem_to_tag_map[elem];
}

bool HIRMutate::DOC::is_html_text_element(const string &elem)
{
    return find(DOC::HTML::html_text_elements.begin(), DOC::HTML::html_text_elements.end(), elem) != DOC::HTML::html_text_elements.end();
}

bool HIRMutate::DOC::is_html_element(const string &elem)
{
    return find(html_elements.begin(), html_elements.end(), elem) != html_elements.end();
}

bool HIRMutate::DOC::is_svg_element(const string &elem)
{
    return find(svg_elements.begin(), svg_elements.end(), elem) != svg_elements.end();
}

string HIRMutate::DOC::svg_tag_from_element(const string &elem)
{
    return svg_elem_to_tag_map[elem];
}

bool HIRMutate::DOC::is_svg_text_element(const string &elem)
{
    return find(DOC::SVG::svg_descriptive_elements.begin(), DOC::SVG::svg_descriptive_elements.end(), elem) != DOC::SVG::svg_descriptive_elements.end() || find(DOC::SVG::svg_text_content_elements.begin(), DOC::SVG::svg_text_content_elements.end(), elem) != DOC::SVG::svg_text_content_elements.end();
}

bool HIRMutate::DOC::is_html_empty_element(const string &elem)
{
    return find(DOC::HTML::html_empty_elements.begin(), DOC::HTML::html_empty_elements.end(), elem) != DOC::HTML::html_empty_elements.end();
}

bool HIRMutate::DOC::is_html_raw_text_element(const string &elem)
{
    return find(DOC::HTML::html_raw_text_elements.begin(), DOC::HTML::html_raw_text_elements.end(), elem) != DOC::HTML::html_raw_text_elements.end();
}