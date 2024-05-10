#ifndef HM_SVG_SYM_H
#define HM_SVG_SYM_H

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

#define SVG_ELEMENTS(k, v)       \
    svg_elements[k] = v;         \
    svg_tags.push_back(v);       \
    svg_elements_k.push_back(k); \
    svg_tag_to_elem_map[v] = k;

#define SVG_ANIMATION_ELEMENTS(v) svg_animation_elements.push_back(v);
#define SVG_PAINT_SERVER_ELEMENTS(v) svg_paint_server_elements.push_back(v);
#define SVG_TEXT_CONTENT_ELEMENTS(v) svg_text_content_elements.push_back(v);
#define SVG_TEXT_CONTENT_CHILD_ELEMENTS(v) svg_text_content_child_elements.push_back(v);
#define SVG_SHAPE_ELEMENTS(v) svg_shape_elements.push_back(v);
#define SVG_CONTAINER_ELEMENTS(v) svg_container_elements.push_back(v);
#define SVG_GRAPHICS_ELEMENTS(v) svg_graphics_elements.push_back(v);
#define SVG_ESTABLISH_VIEWPORT_ELEMENTS(v) svg_establish_viewport_elements.push_back(v);
#define SVG_GRADIENT_ELEMENTS(v) svg_gradient_elements.push_back(v);
#define SVG_FILTER_PRIMITIVES(v) svg_filter_primitives.push_back(v);
#define SVG_MARKABLE_ELEMENTS(v) svg_markable_elements.push_back(v);
#define SVG_DESCRIPTIVE_ELEMENTS(v) svg_descriptive_elements.push_back(v);
#define SVG_STRUCTURAL_ELEMENTS(v) svg_structural_elements.push_back(v);
#define SVG_LIGHT_SOURCES(v) svg_light_sources.push_back(v);
#define SVG_CHILD_ELEMENTS(k, v) svg_child_elements[k] = v;
//insert
#define SVG_CHILD_ELEMENTS_I(k, v) svg_child_elements[k].insert(svg_child_elements[k].end(), v.begin(), v.end());
#define SVG_CHILD_ELEMENTS_V(k, v...) SVG_CHILD_ELEMENTS(k, vector<string>(v))

#define SVG_ANIMATABLE_ATTRIBUTES(v) svg_animatable_attributes.push_back(v);
#define SVG_ANIMATABLE_COLOR_ATTRIBUTES(v) svg_animatable_color_attributes.push_back(v);
#define SVG_ANIMATABLE_TRANSFORM_ATTRIBUTES(v) svg_animatable_transform_attributes.push_back(v);
#define SVG_ANIMATION_BEGIN_EVENTS(v) svg_animation_begin_events.push_back(v);
#define SVG_ARIABLE_ELEMENTS(v) svg_ariable_elements.push_back(v);

namespace HIRMutate
{
    namespace DOC
    {
        namespace SVG
        {
            extern map<string, string> svg_elements;
            extern vector<string> svg_tags;
            extern vector<string> svg_elements_k;
            extern map<string, string> svg_tag_to_elem_map;
            extern vector<string> svg_animation_elements;
            extern vector<string> svg_paint_server_elements;
            extern vector<string> svg_text_content_elements;
            extern vector<string> svg_text_content_child_elements;
            extern vector<string> svg_shape_elements;
            extern vector<string> svg_container_elements;
            extern vector<string> svg_graphics_elements;
            extern vector<string> svg_establish_viewport_elements;
            extern vector<string> svg_gradient_elements;
            extern vector<string> svg_filter_primitives;
            extern vector<string> svg_markable_elements;
            extern vector<string> svg_descriptive_elements;
            extern vector<string> svg_structural_elements;
            extern vector<string> svg_light_sources;
            extern map<string, vector<string> > svg_child_elements;
            extern vector<string> svg_animatable_attributes;
            extern vector<string> svg_animatable_color_attributes;
            extern vector<string> svg_animatable_transform_attributes;
            extern vector<string> svg_animation_begin_events;
            extern vector<string> svg_ariable_elements;
            void initSym();
        }
    }
}
#endif