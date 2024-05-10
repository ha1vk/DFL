#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "random.h"
#include "DomValue.h"
#include "docs.h"

#include "api.h"
#include "html_function.h"
#include "js_property.h"
#include "html_arg.h"
#include "js_function.h"
#include "document_html.h"
#include "html_attr.h"
#include "svg_attr.h"
#include "serializestream.h"
#include "unserializestream.h"
#include "serialize_variables.h"
#include "malloc.h"

using namespace HIRMutate;
using namespace HIRMutate::JS;
using std::cout;
using std::endl;

void random_test()
{
    HIRMutate::Random::init();
    printf("test for gbool...\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::gbool() << " ";
    }
    printf("\ntest for range(0,20)\n");
    for (int i = 0; i < 20; i++)
    {
        cout << HIRMutate::Random::range(0, 20) << " ";
    }
    printf("\ntest for gstring\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::gstring() << endl;
    }
    printf("test for gchar\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::gchar() << " ";
    }
    printf("\ntest for integer\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::integer() << " ";
    }
    printf("\ntest for signed_integer\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::signed_integer() << " ";
    }
    printf("\ntest for number\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::number() << " ";
    }
    printf("\ntest for signed_number\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::signed_number() << " ";
    }
    printf("\ntest for selectors\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::selectors(10) << endl;
    }
    printf("\ntest for hex_digits\n");
    for (int i = 0; i < 10; i++)
    {
        cout << HIRMutate::Random::hex_digits(10) << endl;
    }
}

void DomValueTest()
{
    HIRMutate::Random::init();
    using namespace HIRMutate::DOMValue;
    cout << list_size() << endl;
    /*
        * Basic
        */
    cout << boolean() << endl;
    cout << number_optional_number(false) << endl;
    cout << length(false) << endl;
    cout << percentage() << endl;
    cout << length_percentage(false) << endl;
    cout << number_percentage() << endl;
    cout << angle() << endl;
    cout << angle_percentage() << endl;
    cout << color() << endl;
    cout << index() << endl;
    /*
        * Url
        */
    cout << frame_url() << endl;
    cout << image_url() << endl;
    cout << video_url() << endl;
    cout << audio_url() << endl;
    cout << track_url() << endl;
    /*
        * Path
        */
    cout << move_to() << endl;
    cout << line_to() << endl;
    cout << bezier_curve() << endl;
    cout << arc_curve() << endl;
    cout << close_path() << endl;
    cout << path_cmd() << endl;
    cout << path() << endl;
    cout << position() << endl;
    /*
        * Transform
        */
    cout << matrix() << endl;
    cout << translate() << endl;
    cout << translate_x() << endl;
    cout << translate_y() << endl;
    cout << scale() << endl;
    cout << scale_x() << endl;
    cout << scale_y() << endl;
    cout << rotate() << endl;
    cout << skew() << endl;
    cout << skew_x() << endl;
    cout << skew_y() << endl;
    cout << matrix3d() << endl;
    cout << translate3d() << endl;
    cout << translate_z() << endl;
    cout << scale3d() << endl;
    cout << scale_z() << endl;
    cout << rotate3d() << endl;
    cout << rotate_x() << endl;
    cout << rotate_y() << endl;
    cout << rotate_z() << endl;
    cout << perspective() << endl;
    /*
        * Language
        */
    cout << lang() << endl;

    /*
        * TIME
        */
    cout << clock_in_s() << endl;
    cout << clock_in_ms() << endl;
    cout << HIRMutate::DOMValue::clock() << endl;
    /*
        * Shapes
        */
    cout << fill_rule() << endl;
    cout << border_radius() << endl;
    cout << shape_radius() << endl;
    cout << inset() << endl;
    cout << circle() << endl;
    cout << ellipse() << endl;
    cout << polygon() << endl;
    cout << path_shape() << endl;
    /*
        * Fonts
        */
    cout << font() << endl;
    /*
        * DateTime
        */
    cout << date_time() << endl;
    /*
        * Charset
        */
    cout << charset() << endl;
    /*
         * DOM Attribute Value
         */
    cout << auto_capitalize() << endl;
    cout << dir_() << endl;
    cout << tab_index() << endl;
    cout << drop_zone() << endl;
    cout << coords() << endl;
    cout << shape() << endl;
    cout << target() << endl;
    cout << preload() << endl;
    cout << track_kind() << endl;
    cout << clear() << endl;
    cout << form_enc_type() << endl;
    cout << form_method() << endl;
    cout << button_type() << endl;
    cout << align() << endl;
    cout << accept() << endl;
    cout << caption_align() << endl;
    cout << table_align() << endl;
    cout << valign() << endl;
    cout << vtt_cue_align() << endl;
    cout << input_mode() << endl;
    cout << play_state() << endl;
    cout << animation_direction() << endl;
    cout << animation_easing() << endl;
    cout << animation_fill_mode() << endl;

    /* iframe, image, object*/
    cout << object_align() << endl;
    cout << scrolling() << endl;
    cout << vtt_region_scroll() << endl;
    cout << table_frame() << endl;
    cout << table_rules() << endl;
    cout << wrap() << endl;
    cout << selection_direction() << endl;
    cout << select_mode() << endl;
    cout << numbering_type() << endl;
    cout << auto_complete() << endl;
    cout << key_type() << endl;
    cout << srcset() << endl;
    cout << meta_scheme() << endl;
    cout << text_track_mode() << endl;
    cout << vtt_cue_vertical() << endl;
    cout << param_value_type() << endl;
    cout << ulist_type() << endl;
    cout << link_as() << endl;
    cout << table_scope() << endl;
    cout << menu_type() << endl;
    cout << regex() << endl;
    cout << input_type() << endl;
    cout << menu_item_type() << endl;
    cout << marquee_behavior() << endl;
    cout << marquee_direction() << endl;
    cout << marquee_loop() << endl;
    cout << rel() << endl;
    cout << rev() << endl;
    cout << font_weight() << endl;
    cout << font_stretch_value() << endl;
    cout << font_stretch() << endl;
    cout << font_variant() << endl;
    cout << font_feature_settings() << endl;
    cout << single() << endl;
    cout << unicode_range() << endl;
    cout << media_query() << endl;
    cout << keyframe_name() << endl;
    cout << css_type() << endl;
    cout << media_type() << endl;
    cout << mime_type() << endl;
    cout << image_type() << endl;
}

void printMapVec(map<string, vector<string> > &eles)
{
    std::for_each(eles.begin(), eles.end(),
                  [](map<string, vector<string> >::reference i)
                  {
                      printf("==========%s============\n", i.first.c_str());
                      vector<string> &v = i.second;
                      std::for_each(v.begin(), v.end(),
                                    [](string &val)
                                    {
                                        printf("%s\n", val.c_str());
                                    });
                      printf("\n");
                  });
}

void printMap(map<string, string> &eles)
{
    std::for_each(eles.begin(), eles.end(),
                  [](map<string, string>::reference i)
                  {
                      printf("%s : %s\n", i.first.c_str(), i.second.c_str());
                  });
}
void printVec(vector<string> &v)
{
    std::for_each(v.begin(), v.end(),
                  [](string &val)
                  {
                      printf("%s\n", val.c_str());
                  });
}
void testHTMLSym()
{
    HIRMutate::DOC::init();
    vector<string> &html_tags = DOC::html_tags;
    cout << "+++++++++++++++++++++++++++test for html_tags+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_tags);
    vector<string> &html_elements = DOC::html_elements;
    cout << "+++++++++++++++++++++++++++test for html_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_elements);
    vector<string> &html_general_child_elements = DOC::html_general_child_elements;
    cout << "+++++++++++++++++++++++++++test for html_general_child_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_general_child_elements);
    vector<string> &html_other_child_elements = DOC::html_other_child_elements;
    cout << "+++++++++++++++++++++++++++test for html_other_child_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_other_child_elements);
    map<string, vector<string> > &html_child_elements = DOC::html_child_elements;
    cout << "+++++++++++++++++++++++++++test for html_child_elements+++++++++++++++++++++++++++++++++" << endl;
    printMapVec(html_child_elements);
    vector<string> &html_labelable_elements = DOC::html_labelable_elements;
    cout << "+++++++++++++++++++++++++++test for html_labelable_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_labelable_elements);
    map<string, string> &html_elem_to_tag_map = DOC::html_elem_to_tag_map;
    cout << "+++++++++++++++++++++++++++test for html_elem_to_tag_map+++++++++++++++++++++++++++++++++" << endl;
    printMap(html_elem_to_tag_map);
    map<string, string> &html_tag_to_elem_map = DOC::html_tag_to_elem_map;
    cout << "+++++++++++++++++++++++++++test for html_tag_to_elem_map+++++++++++++++++++++++++++++++++" << endl;
    printMap(html_tag_to_elem_map);
    vector<string> &html_block_elements = DOC::html_block_elements;
    cout << "+++++++++++++++++++++++++++test for html_block_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_block_elements);
    vector<string> &html_link_elements = DOC::html_link_elements;
    cout << "+++++++++++++++++++++++++++test for html_link_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_link_elements);
    vector<string> &html_submittable_elements = DOC::html_submittable_elements;
    cout << "+++++++++++++++++++++++++++test for html_submittable_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(html_submittable_elements);

    //SVG
    vector<string> &svg_tags = DOC::svg_tags;
    cout << "+++++++++++++++++++++++++++test for svg_tags+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_tags);
    vector<string> &svg_elements = DOC::svg_elements;
    cout << "+++++++++++++++++++++++++++test for svg_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_elements);
    map<string, vector<string> > &svg_child_elements = DOC::svg_child_elements;
    cout << "+++++++++++++++++++++++++++test for svg_child_elements+++++++++++++++++++++++++++++++++" << endl;
    printMapVec(svg_child_elements);
    vector<string> &svg_animation_elements = DOC::svg_animation_elements;
    cout << "+++++++++++++++++++++++++++test for svg_animation_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_animation_elements);
    vector<string> &svg_paint_server_elements = DOC::svg_paint_server_elements;
    cout << "+++++++++++++++++++++++++++test for svg_paint_server_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_paint_server_elements);
    vector<string> &svg_shape_elements = DOC::svg_shape_elements;
    cout << "+++++++++++++++++++++++++++test for svg_shape_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_shape_elements);
    vector<string> &svg_gradient_elements = DOC::svg_gradient_elements;
    cout << "+++++++++++++++++++++++++++test for svg_gradient_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_gradient_elements);
    vector<string> &svg_text_content_elements = DOC::svg_text_content_elements;
    cout << "+++++++++++++++++++++++++++test for svg_text_content_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_text_content_elements);
    vector<string> &svg_filter_primitives = DOC::svg_filter_primitives;
    cout << "+++++++++++++++++++++++++++test for svg_filter_primitives+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_filter_primitives);

    map<string, string> &svg_elem_to_tag_map = DOC::svg_elem_to_tag_map;
    cout << "+++++++++++++++++++++++++++test for svg_elem_to_tag_map+++++++++++++++++++++++++++++++++" << endl;
    printMap(svg_elem_to_tag_map);
    map<string, string> &svg_tag_to_elem_map = DOC::svg_tag_to_elem_map;
    cout << "+++++++++++++++++++++++++++test for svg_tag_to_elem_map+++++++++++++++++++++++++++++++++" << endl;
    printMap(svg_tag_to_elem_map);

    vector<string> &svg_animation_begin_events = DOC::svg_animation_begin_events;
    cout << "+++++++++++++++++++++++++++test for svg_animation_begin_events+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_animation_begin_events);
    vector<string> &svg_animatable_attributes = DOC::svg_animatable_attributes;
    cout << "+++++++++++++++++++++++++++test for svg_animatable_attributes+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_animatable_attributes);
    vector<string> &svg_animatable_transform_attributes = DOC::svg_animatable_transform_attributes;
    cout << "+++++++++++++++++++++++++++test for svg_animatable_transform_attributes+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_animatable_transform_attributes);

    vector<string> &svg_ariable_elements = DOC::svg_ariable_elements;
    cout << "+++++++++++++++++++++++++++test for svg_ariable_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(svg_ariable_elements);

    vector<string> &elements = DOC::elements;
    cout << "+++++++++++++++++++++++++++test for elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(elements);

    vector<string> &image_elements = DOC::image_elements;
    cout << "+++++++++++++++++++++++++++test for image_elements+++++++++++++++++++++++++++++++++" << endl;
    printVec(image_elements);
}

void initGlobalSym()
{
    Random::init();
    Config::init();
    //顺序不能变
    DOC::init();
    CSS::init();
    Attribute::init();
    JS::initSym();
    initMerge_blacklist();
    initClasses();
}
void generate_one()
{
    HIRMutate::Document::ptr document = std::make_shared<HIRMutate::Document>(Random::range(TreeConfig::min_element_count, TreeConfig::max_element_count));
    document->generate_nodes();
    document->generate_attributes();
    document->generate_css_rules();
    document->generate_js_functions();
    string s = document->operator string();
    std::ofstream of("/home/aimadmin/lab/hir/dfl_output/run.html");
    of << s << endl;
    of.close();
    /*SerializeStream *stream = new SerializeStream();
    document->serialize(stream);
    stream->write_to_file("1.obj");
    delete stream;*/
}

void unserialize()
{
    HIRMutate::Document::ptr document = std::make_shared<HIRMutate::Document>();
    UnSerializeStream *stream = new UnSerializeStream("1.obj");
    document->unserialize(stream);
    delete stream;
    string s = document->operator string();
    /*std::ofstream of("uns.html");
    of << s << endl;
    of.close();*/
    /*SerializeStream *stream1 = new SerializeStream();
    document->serialize(stream1);
    stream1->write_to_file("2.obj");
    delete stream1;*/
    //getchar();
}

/* Prototypes for our hooks.  */
static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void my_free_hook(void *, const void *);
static void *(*old_malloc_hook)(size_t, const void *);
static void (*old_free_hook)(void *, const void *);

map<size_t, bool> mem;

static void
my_init(void)
{
    old_malloc_hook = __malloc_hook;
    old_free_hook = __free_hook;
    __malloc_hook = my_malloc_hook;
    __free_hook = my_free_hook;
}

static void *
my_malloc_hook(size_t size, const void *caller)
{
    void *result;
    /* Restore all old hooks */
    __malloc_hook = old_malloc_hook;
    __free_hook = old_free_hook;
    /* Call recursively */
    result = malloc(size);
    mem[(size_t)result] = 1;
    /* Save underlying hooks */
    old_malloc_hook = __malloc_hook;
    old_free_hook = __free_hook;
    /* printf might call malloc, so protect it too. */
    //printf("malloc (%u) returns %p\n", (unsigned int)size, result);
    /* Restore our own hooks */
    __malloc_hook = my_malloc_hook;
    __free_hook = my_free_hook;
    return result;
}

static void
my_free_hook(void *ptr, const void *caller)
{
    mem.erase((size_t)ptr);
    /* Restore all old hooks */
    __malloc_hook = old_malloc_hook;
    __free_hook = old_free_hook;
    /* Call recursively */
    free(ptr);
    /* Save underlying hooks */
    old_malloc_hook = __malloc_hook;
    old_free_hook = __free_hook;
    /* printf might call free, so protect it too. */
    //printf("freed pointer %p\n", ptr);
    /* Restore our own hooks */
    __malloc_hook = my_malloc_hook;
    __free_hook = my_free_hook;
}

int main(int argc,char *argv[])
{
    //andom_test();
    /*for (int i=0;i<1000;i++) {
    DomValueTest();
    }*/
    //testHTMLSym();
    initGlobalSym();
    //getchar();
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        generate_one();
        //unserialize();
    }
    /*std::for_each(mem.begin(), mem.end(),
                  [](map<size_t, bool>::reference i)
                  {
                      printf("0x%lx\n", i.first);
                  });*/
    //getchar();
    return 0;
}