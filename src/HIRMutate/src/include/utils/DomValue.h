#ifndef HM_DOM_VALUE_H
#define HM_DOM_VALUE_H

#include <vector>
#include <string>

using std::string;
using std::vector;

namespace HIRMutate
{
    namespace DOMValue
    {
        /*Helper*/
        int list_size();
        /*
        * Basic
        */
        string boolean();
        string number_optional_number(bool issigned);
        string length(bool relative = false);
        string percentage();
        string length_percentage(bool relative = false);
        string number_percentage();
        string angle();
        string angle_nosuffix();
        string angle_percentage();
        string color();
        string index();
        /*
        * Url
        */
        string frame_url();
        string image_url();
        string video_url();
        string audio_url();
        string track_url();
        /*
        * Path
        */
        string move_to();
        string line_to();
        string bezier_curve();
        string arc_curve();
        string close_path();
        string path_cmd();
        string path();
        string position();
        /*
        * Transform
        */
        string matrix();
        string translate(bool svg = false);
        string translate_x();
        string translate_y();
        string scale();
        string scale_x();
        string scale_y();
        string rotate(bool svg = false);
        string skew(bool svg = false);
        string skew_x(bool svg = false);
        string skew_y(bool svg = false);
        string matrix3d();
        string translate3d();
        string translate_z();
        string scale3d();
        string scale_z();
        string rotate3d(bool svg = false);
        string rotate_x(bool svg = false);
        string rotate_y(bool svg = false);
        string rotate_z(bool svg = false);
        string perspective();
        /*
        * Language
        */
        string lang();

        /*
        * TIME
        */
        string clock_in_s();
        string clock_in_ms();
        string clock();
        /*
        * Shapes
        */
        string fill_rule();
        string border_radius();
        string shape_radius();
        string inset();
        string circle();
        string ellipse();
        string polygon();
        string path_shape();
        /*
        * Fonts
        */
        string font();
        /*
        * DateTime
        */
        string date_time();
        /*
        * Charset
        */
        string charset();
        /*
         * DOM Attribute Value
         */
        string auto_capitalize();
        string dir_();
        string tab_index();
        string drop_zone();
        string coords();
        string shape();
        string target();
        string preload();
        string track_kind();
        string clear();
        string form_enc_type();
        string form_method();
        string button_type();
        string align();
        string accept();
        string caption_align();
        string table_align();
        string valign();
        string vtt_cue_align();
        string input_mode();
        string play_state();
        string animation_direction();
        string animation_easing();
        string animation_fill_mode();

        /* iframe, image, object*/
        string object_align();
        string scrolling();
        string vtt_region_scroll();
        string table_frame();
        string table_rules();
        string wrap();
        string selection_direction();
        string select_mode();
        string numbering_type();
        string auto_complete();
        string key_type();
        string srcset();
        string meta_scheme();
        string text_track_mode();
        string vtt_cue_vertical();
        string param_value_type();
        string ulist_type();
        string link_as();
        string table_scope();
        string menu_type();
        string regex();
        string input_type();
        string menu_item_type();
        string marquee_behavior();
        string marquee_direction();
        string marquee_loop();
        string rel();
        string rev();
        string font_weight();
        string font_stretch_value();
        string font_stretch();
        string font_variant();
        string font_feature_settings();
        string single();
        string unicode_range();
        string media_query();
        string keyframe_name();
        string css_type();
        string media_type();
        string mime_type();
        string image_type();
    };
} // namespace HIRMutate

#endif