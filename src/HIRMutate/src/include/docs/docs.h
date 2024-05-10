#ifndef HM_DOCS_H
#define HM_DOCS_H

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

namespace HIRMutate
{
    namespace DOC
    {
        extern vector<string> &html_tags;
        extern vector<string> &html_elements;
        extern vector<string> &html_general_child_elements;
        extern vector<string> &html_other_child_elements;
        extern map<string, vector<string> > &html_child_elements;
        extern vector<string> &html_labelable_elements;
        extern map<string, string> &html_elem_to_tag_map;
        extern map<string, string> &html_tag_to_elem_map;
        extern vector<string> &html_block_elements;
        extern vector<string> &html_link_elements;
        extern vector<string> &html_submittable_elements;

        //SVG
        extern vector<string> &svg_tags;
        extern vector<string> &svg_elements;
        extern map<string, vector<string> > &svg_child_elements;
        extern vector<string> &svg_animation_elements;
        extern vector<string> &svg_paint_server_elements;
        extern vector<string> &svg_shape_elements;
        extern vector<string> svg_gradient_elements;
        extern vector<string> &svg_text_content_elements;
        extern vector<string> &svg_filter_primitives;
        extern map<string, string> &svg_elem_to_tag_map;
        extern map<string, string> &svg_tag_to_elem_map;
        extern vector<string> &svg_animation_begin_events;
        extern vector<string> &svg_animatable_attributes;
        extern vector<string> &svg_animatable_transform_attributes;
        extern vector<string> &svg_ariable_elements;
        extern vector<string> elements;
        extern vector<string> image_elements;
        //CSS
        extern vector<string> &css_animatable_properties;

        //Event
        //TODO: composition events
        extern vector<string> text_events;
        extern vector<string> base_ui_events;
        extern vector<string> mouse_events;
        extern vector<string> focus_events;
        extern vector<string> wheel_events;
        extern vector<string> input_events;
        extern vector<string> keyboard_events;
        extern vector<string> composition_events;
        extern vector<string> ui_events;
        extern vector<string> mutation_events;

        void init();
        vector<string> get_object_ancestors(const string &name);
        vector<string> get_object_offsprings(const string &name);
        string tag_from_element(const string &elem);
        string html_tag_from_element(const string &elem);
        bool is_html_text_element(const string &elem);
        bool is_html_element(const string &elem);
        bool is_svg_element(const string &elem);
        string svg_tag_from_element(const string &elem);
        bool is_svg_text_element(const string &elem);
        bool is_html_empty_element(const string &elem);
        bool is_html_raw_text_element(const string &elem);
    }
}
#endif