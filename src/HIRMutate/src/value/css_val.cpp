#include "css_val.h"
#include "config.h"
#include "serialize_variables.h"

string HIRMutate::CSS::cat(vector<string> &values)
{
    string ans = "";
    int len = values.size();
    for (int i = 0; i < len; i++)
    {
        ans.append(values[i]);
        if (i != len - 1)
        {
            ans.append(" ");
        }
    }
    return ans;
}
/*
* CSS value generators
*/
string HIRMutate::CSS::geometry_box()
{
    static const char *strs[] = {"margin-box", "border-box", "padding-box", "content-box", "fill-box", "stroke-box", "view-box"};
    return CHOICE(strs);
}

string HIRMutate::CSS::shape_box()
{
    static const char *strs[] = {"border-box", "padding-box", "content-box", "margin-box"};
    return CHOICE(strs);
}

string HIRMutate::CSS::blur()
{
    string ans = "blur(";
    ans.append(DOMValue::length());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::brightness()
{
    string ans = "brightness(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::contrast()
{
    string ans = "contrast(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::drop_shadow()
{
    int num = Random::range(2, 3);
    string ans = "drop-shadow(";
    ans.append(DOMValue::length());
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(DOMValue::length());
    }
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append(DOMValue::color());
    }
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::grayscale()
{
    string ans = "grayscale(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::hue_rotate()
{
    string ans = "hue-rotate(";
    ans.append(DOMValue::angle());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::invert()
{
    string ans = "invert(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::opacity()
{
    string ans = "opacity(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::saturate()
{
    string ans = "saturate(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}
string HIRMutate::CSS::sepia()
{
    string ans = "sepia(";
    ans.append(DOMValue::number_percentage());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::filter_function()
{
    int c = Random::selector(10);
    if (c == 0)
        return blur();
    else if (c == 1)
        return brightness();
    else if (c == 2)
        return contrast();
    else if (c == 3)
        return drop_shadow();
    else if (c == 4)
        return grayscale();
    else if (c == 5)
        return hue_rotate();
    else if (c == 6)
        return invert();
    else if (c == 7)
        return opacity();
    else if (c == 8)
        return saturate();
    else
        return sepia();
}

string HIRMutate::CSS::alpha()
{
    if (Random::gbool())
        return Random::float01();
    else
        return DOMValue::percentage();
}

string HIRMutate::CSS::repeat()
{
    static const char *strs[] = {"repeat", "space", "round", "no-repeat"};
    return CHOICE(strs);
}

string HIRMutate::CSS::step_position()
{
    static const char *strs[] = {"jump-start", "jump-end", "jump-none", "jump-both", "start", "end"};
    return CHOICE(strs);
}

string HIRMutate::CSS::step_timing_function()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"step-start", "step-end"};
        return CHOICE(strs);
    }
    else
    {
        string ans = "steps(";
        ans.append(Random::integer());
        if (Random::gbool())
        {
            ans.append(",");
            ans.append(step_position());
        }
        ans.append(")");
        return ans;
    }
}

string HIRMutate::CSS::line_width()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"thin", "medium", "thick"};
        return CHOICE(strs);
    }
    else
        return DOMValue::length();
}

string HIRMutate::CSS::line_height()
{
    int c = Random::selector(4);
    if (c == 0)
        return "normal";
    else if (c == 1)
        return Random::number();
    else if (c == 2)
        return DOMValue::length();
    else
        return DOMValue::percentage();
}
string HIRMutate::CSS::line_style()
{
    static const char *strs[] = {"hidden", "dotted", "dashed", "solid", "double", "groove", "ridge", "inset", "outset"};
    return CHOICE(strs);
}

string HIRMutate::CSS::side_or_corner()
{
    int c = Random::selector(3);
    static const char *strs0[] = {"left", "right"};
    static const char *strs1[] = {"top", "bottom"};
    if (c == 0)
    {
        return CHOICE(strs0);
    }
    else if (c == 1)
    {

        return CHOICE(strs1);
    }
    else
    {
        string ans = CHOICE(strs0);
        ans.append(" ");
        ans.append(CHOICE(strs1));
        return ans;
    }
}

string HIRMutate::CSS::linear_color_stop()
{
    string ans = DOMValue::color();
    if (Random::gbool())
    {
        int num = Random::range(1, 2);
        for (int i = 0; i < num; i++)
        {
            ans.append(" ");
            ans.append(DOMValue::length_percentage());
        }
    }
    return ans;
}

string HIRMutate::CSS::angular_color_stop()
{
    string ans = DOMValue::color();
    if (Random::gbool())
    {
        int num = Random::range(1, 2);
        for (int i = 0; i < num; i++)
        {
            ans.append(" ");
            ans.append(DOMValue::angle_percentage());
        }
    }
    return ans;
}

string HIRMutate::CSS::color_stop_list()
{
    return linear_color_stop();
}

string HIRMutate::CSS::angular_color_stop_list()
{
    return angular_color_stop();
}

string HIRMutate::CSS::_linear_gradient()
{
    vector<string> values;
    if (Random::gbool())
    {
        if (Random::gbool())
            values.push_back(DOMValue::angle());
        else
        {
            values.push_back("to");
            values.push_back(side_or_corner());
        }
    }

    string _color_stop_list = color_stop_list();
    string value;
    int len = values.size();
    if (len > 0)
    {
        value = values[0];
        for (int i = 1; i < len; i++)
        {
            value.append(" ");
            value.append(values[i]);
        }
        value.append(",");
        value.append(_color_stop_list);
    }
    else
        value = _color_stop_list;
    return value;
}

string HIRMutate::CSS::linear_gradient()
{
    string ans = "linear-gradient(";
    ans.append(_linear_gradient());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::repeating_linear_gradient()
{
    string ans = "repeating-linear-gradient(";
    ans.append(_linear_gradient());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::ending_shape()
{
    static const char *strs[] = {"circle", "ellipse"};
    return CHOICE(strs);
}

string HIRMutate::CSS::radial_gradient_size()
{
    int c = Random::selector(3);
    if (c == 0)
    {
        static const char *strs[] = {"closest-side", "farthest-side", "closest-corner", "farthest-corner"};
        return CHOICE(strs);
    }
    else if (c == 1)
        return DOMValue::length();
    else
        return DOMValue::length_percentage() + " " + DOMValue::length_percentage();
}

string HIRMutate::CSS::_radial_gradient()
{
    vector<string> values;
    if (Random::gbool())
    {
        string selectors = Random::selectors(2);
        if (selectors[0])
            values.push_back(ending_shape());
        if (selectors[1])
            values.push_back(radial_gradient_size());
    }
    if (Random::gbool())
    {
        values.push_back("at");
        values.push_back(DOMValue::position());
    }

    string _color_stop_list = color_stop_list();
    int len = values.size();
    string ans;
    if (len > 0)
    {
        ans = values[0];
        for (int i = 1; i < len; i++)
        {
            ans.append(" ");
            ans.append(values[i]);
        }
        ans.append(",");
        ans.append(_color_stop_list);
    }
    else
        ans = _color_stop_list;
    return ans;
}

string HIRMutate::CSS::radial_gradient()
{
    string ans = "radial-gradient(";
    ans.append(_radial_gradient());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::repeating_radial_gradient()
{
    string ans = "repeating-radial-gradient(";
    ans.append(_radial_gradient());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::conic_gradient()
{
    vector<string> values;
    if (Random::gbool())
    {
        values.push_back("from");
        values.push_back(DOMValue::angle());
    }
    if (Random::gbool())
    {
        values.push_back("at");
        values.push_back(DOMValue::position());
    }

    string _angular_color_stop_list = angular_color_stop_list();
    int len = values.size();
    string ans;
    if (len > 0)
    {
        ans = values[0];
        for (int i = 1; i < len; i++)
        {
            ans.append(" ");
            ans.append(values[i]);
        }
        ans.append(",");
        ans.append(_angular_color_stop_list);
    }
    else
        ans = _angular_color_stop_list;
    string value = "conic-gradient(";
    value.append(ans);
    value.append(")");
    return value;
}

string HIRMutate::CSS::image()
{
    int c = Random::selector(6);
    if (c == 0)
    {
        string ans = "url(";
        ans.append(DOMValue::image_url());
        ans.append(")");
        return ans;
    }
    else if (c == 1)
        return linear_gradient();
    else if (c == 2)
        return repeating_linear_gradient();
    else if (c == 3)
        return radial_gradient();
    else if (c == 4)
        return repeating_radial_gradient();
    else
        return conic_gradient();
}

string HIRMutate::CSS::column_width()
{
    if (Random::gbool())
        return DOMValue::length();
    else
        return "auto";
}

string HIRMutate::CSS::column_count()
{
    if (Random::gbool())
        return Random::integer();
    else
        return "auto";
}

string HIRMutate::CSS::flex_basis()
{
    if (Random::gbool())
        return DOMValue::length_percentage();
    else
        return "auto";
}

string HIRMutate::CSS::quote()
{
    static const char *strs[] = {"open-quote", "close-quote", "no-open-quote", "no-close-quote"};
    return CHOICE(strs);
}

string HIRMutate::CSS::leader()
{
    string leader_type;
    if (Random::gbool())
    {
        static const char *strs[] = {"dotted", "solid", "space"};
        leader_type = CHOICE(strs);
    }
    else
        leader_type = Random::gstring();
    string ans = "leader(";
    ans.append(leader_type);
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::flex_direction()
{
    static const char *strs[] = {"row", "row-reverse", "column", "column-reverse"};
    return CHOICE(strs);
}

string HIRMutate::CSS::flex_wrap()
{
    static const char *strs[] = {"nowrap", "wrap", "wrap-reverse"};
    return CHOICE(strs);
}

string HIRMutate::CSS::flex()
{
    string ans = Random::number();
    ans.append("fr");
    return ans;
}

string HIRMutate::CSS::track_breadth()
{
    int c = Random::selector(3);
    if (c == 0)
    {
        static const char *strs[] = {"auto", "min-content", "max-content"};
        return CHOICE(strs);
    }
    else if (c == 1)
        return flex();
    else
        return DOMValue::length_percentage();
}

string HIRMutate::CSS::inflexible_breadth()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "min-content", "max-content"};
        return CHOICE(strs);
    }
    else
        return DOMValue::length_percentage();
}

string HIRMutate::CSS::track_size()
{
    int c = Random::selector(3);
    if (c == 0)
        return track_breadth();
    else if (c == 1)
    {
        string ans = "minmax(";
        ans.append(inflexible_breadth());
        ans.append(", ");
        ans.append(track_breadth());
        ans.append(")");
        return ans;
    }
    else
    {
        string ans = "fit-content(";
        ans.append(DOMValue::length_percentage());
        ans.append(")");
        return ans;
    }
}

// TODO: > 1
string HIRMutate::CSS::track_repeat()
{
    string ans = "repeat(";
    ans.append(Random::integer());
    ans.append(", ");
    ans.append(track_size());
    ans.append(")");
    return ans;
}

// TODO: > 1
string HIRMutate::CSS::fixed_repeat()
{
    string ans = "repeat(";
    ans.append(Random::integer());
    ans.append(", ");
    ans.append(fixed_size());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::auto_repeat()
{
    static const char *strs[] = {"auto-fill", "auto-fit"};
    string ans = "repeat(";
    ans.append(CHOICE(strs));
    ans.append(", ");
    ans.append(fixed_size());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::fixed_size()
{
    int c = Random::selector(3);
    if (c == 0)
        return DOMValue::length_percentage();
    else if (c == 1)
    {
        string ans = "minmax(";
        ans.append(inflexible_breadth());
        ans.append(", ");
        ans.append(track_breadth());
        ans.append(")");
        return ans;
    }
    else
    {
        string ans = "fit-content(";
        ans.append(DOMValue::length_percentage());
        ans.append(")");
        return ans;
    }
}

string HIRMutate::CSS::track()
{
    if (Random::gbool())
        return track_size();
    else
        return track_repeat();
}

string HIRMutate::CSS::fixed()
{
    if (Random::gbool())
        return fixed_size();
    else
        return fixed_repeat();
}

string HIRMutate::CSS::track_list()
{
    int num = Random::range(1, 2);
    string ans = track();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(track());
    }
    return ans;
}

string HIRMutate::CSS::auto_track_list()
{
    int num = Random::range(0, 1);
    vector<string> values;
    for (int i = 0; i < num; i++)
    {
        values.push_back(fixed());
    }
    values.push_back(auto_repeat());
    num = Random::range(0, 1);
    for (int i = 0; i < num; i++)
    {
        values.push_back(fixed());
    }
    int len = values.size();
    string ans = values[0];
    for (int i = 1; i < len; i++)
    {
        ans.append(" ");
        ans.append(values[i]);
    }
    return ans;
}

string HIRMutate::CSS::explicit_track_list()
{
    int num = Random::range(1, 2);
    string ans = track_size();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(track_size());
    }
    return ans;
}

string HIRMutate::CSS::baseline_position()
{
    string ans = "";
    if (Random::gbool())
    {
        static const char *strs[] = {"first", "last"};
        ans.append(CHOICE(strs));
        ans.append(" ");
    }
    ans.append("baseline");
    return ans;
}

string HIRMutate::CSS::overflow_position()
{
    static const char *strs[] = {"unsafe", "safe"};
    return CHOICE(strs);
}

string HIRMutate::CSS::self_position()
{
    static const char *strs[] = {"center", "start", "end", "self-start", "self-end", "flex-start", "flex-end"};
    return CHOICE(strs);
}

string HIRMutate::CSS::location()
{
    int c = Random::selector(3);
    if (c == 0)
        return DOMValue::length();
    else if (c == 1)
        return DOMValue::percentage();
    else
        return "auto";
}

string HIRMutate::CSS::basic_shape()
{
    int c = Random::selector(5);
    if (c == 0)
        return DOMValue::inset();
    else if (c == 1)
        return DOMValue::circle();
    else if (c == 2)
        return DOMValue::ellipse();
    else if (c == 3)
        return DOMValue::polygon();
    else
        return DOMValue::path_shape();
}

/*
* CSS variables
*/

void HIRMutate::CSS::CSSColorValue::generate(Context *content)
{
    if (Random::selector(CSSConfig::use_css_var) == 0)
        value = "var(--css-color)";
    else
        value = DOMValue::color();
}

void HIRMutate::CSS::CSSLineWidthValue::generate(Context *context)
{
    if (Random::selector(CSSConfig::use_css_var) == 0)
        value = "var(--css-line-width)";
    else
        value = line_width();
}

void HIRMutate::CSS::CSSLengthValue::generate(Context *context)
{
    if (Random::selector(CSSConfig::use_css_var) == 0)
        value = "var(--css-length)";
    else
        value = DOMValue::length();
}

void HIRMutate::CSS::CSSLengthPercentageValue::generate(Context *context)
{
    if (Random::selector(CSSConfig::use_css_var) == 0)
        value = "var(--css-length-percent)";
    else
        value = DOMValue::length_percentage();
}

/*
* Static CSS values
*/
void HIRMutate::CSS::ColorValue::generate(Context *context)
{
    value = DOMValue::color();
}

void HIRMutate::CSS::LineWidthValue::generate(Context *context)
{
    value = line_width();
}

void HIRMutate::CSS::ImageValue::generate(Context *context)
{
    value = image();
}

void HIRMutate::CSS::RadiusValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = DOMValue::length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length_percentage());
    }
}

void HIRMutate::CSS::LineStyleValue::generate(Context *context)
{
    value = line_style();
}

void HIRMutate::CSS::LocationValue::generate(Context *context)
{
    value = location();
}

void HIRMutate::CSS::BottomValue::generate(Context *context)
{
    if (Random::selector(5) == 0)
        value = "auto";
    else
        value = DOMValue::length_percentage(true);
}

//opacity

void HIRMutate::CSS::OpacityValue::generate(Context *context)
{
    value = alpha();
}

// -webkit-app-region

void HIRMutate::CSS::WebkitAppRegionValue::generate(Context *context)
{
    static const char *strs[] = {"drag", "no-drag"};
    value = CHOICE(strs);
}

//appearance
void HIRMutate::CSS::AppearanceValue::generate(Context *context)
{
    static const char *strs[] = {"searchfield-cancel-button", "radio", "relevancy-level-indicator",
                                 "push-button", "media-controls-background", "button", "media-sliderthumb",
                                 "media-volume-sliderthumb", "media-play-button", "sliderthumb-vertical",
                                 "menulist-button", "slider-vertical", "slider-horizontal", "textarea",
                                 "square-button", "sliderthumb-horizontal", "discrete-capacity-level-indicator",
                                 "media-volume-slider-container", "media-volume-slider-mute-button", "textfield",
                                 "caps-lock-indicator", "progress-bar", "meter"};
    value = CHOICE(strs);
}

//-webkit-color-correction
void HIRMutate::CSS::WebkitColorCorrectionValue::generate(Context *context)
{
    static const char *strs[] = {"sRGB", "default"};
    value = CHOICE(strs);
}

// -webkit-flow-from
void HIRMutate::CSS::WebkitFlowFromValue::generate(Context *context)
{
    value = "flow0";
}

// -webkit-flow-into
void HIRMutate::CSS::WebkitFlowIntoValue::generate(Context *context)
{
    value = "flow0";
}

// -webkit-font-smoothing
void HIRMutate::CSS::WebkitFontSmoothingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "antialiased", "subpixel-antialiased", "none"};
    value = CHOICE(strs);
}

// -webkit-hyphenate-character
void HIRMutate::CSS::WebkitHyphenateCharacterValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "floating", "'-'"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::webkit_margin_collapse()
{
    static const char *strs[] = {"collapse", "separate", "discard"};
    return CHOICE(strs);
}

//-webkit-margin-after-collapse

void HIRMutate::CSS::WebkitMarginAfterCollapseValue::generate(Context *context)
{
    value = webkit_margin_collapse();
}

//-webkit-margin-collapse

void HIRMutate::CSS::WebkitMarginCollapseValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = webkit_margin_collapse();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(webkit_margin_collapse());
    }
}

//-webkit-marquee-speed

void HIRMutate::CSS::WebkitMarqueeSpeedValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"fast", "inherit", "normal", "slow"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::clock_in_ms();
}

// -webkit-mask-box-image

void HIRMutate::CSS::WebkitMaskBoxImageValue::generate(Context *context)
{
    vector<string> values;
    string selectors = Random::selectors(2);
    if (selectors[0])
        values.push_back(image());
    if (selectors[1])
    {
        for (int i = 0; i < 4; i++)
        {
            values.push_back(DOMValue::length_percentage());
        }
        for (int i = 0; i < 2; i++)
        {
            values.push_back(border_image_repeat());
        }
    }
    value = "";
    int len = values.size();
    for (int i = 0; i < len; i++)
    {
        value.append(values[i]);
        if (i != len - 1)
        {
            value.append(" ");
        }
    }
}

// mask
string HIRMutate::CSS::mask_repeat_style()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"repeat-x", "repeat-y"};
        return CHOICE(strs);
    }
    else
    {
        int num = Random::range(1, 2);
        string ans = repeat();
        for (int i = 0; i < num - 1; i++)
        {
            ans.append(" ");
            ans.append(repeat());
        }
        return ans;
    }
}

string HIRMutate::CSS::mask_composite()
{
    static const char *strs[] = {"add", "subtract", "intersect", "exclude"};
    return CHOICE(strs);
}

string HIRMutate::CSS::mask_mode()
{
    static const char *strs[] = {"alpha", "luminance", "match-source"};
    return CHOICE(strs);
}

string HIRMutate::CSS::mask_clip()
{
    if (Random::gbool())
        return geometry_box();
    else
        return "no-clip";
}

string HIRMutate::CSS::mask_position()
{
    int num = Random::range(1, 2);
    string ans = DOMValue::position();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(DOMValue::position());
    }
    return ans;
}

//mask-clip

void HIRMutate::CSS::MaskClipValue::generate(Context *context)
{
    value = mask_clip();
}

//mask-composite

void HIRMutate::CSS::MaskCompositeValue::generate(Context *context)
{
    value = mask_composite();
}

//mask-origin
void HIRMutate::CSS::MaskOriginValue::generate(Context *context)
{
    value = geometry_box();
}

//mask-position
void HIRMutate::CSS::MaskPositionValue::generate(Context *context)
{
    value = mask_position();
}

//mask-repeat
void HIRMutate::CSS::MaskRepeatValue::generate(Context *context)
{
    value = mask_repeat_style();
}

//mask-source-type

void HIRMutate::CSS::MaskSourceTypeValue::generate(Context *context)
{
    value = mask_mode();
}

//-webkit-mask-repeat-x/y
void HIRMutate::CSS::WebkitMaskRepeatXValue::generate(Context *context)
{
    value = repeat();
}

//mask-size
void HIRMutate::CSS::MaskSizeValue::generate(Context *context)
{
    value = background_size();
}

//-webkit-nbsp-mode
void HIRMutate::CSS::WebkitNbspModeValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "space"};
    value = CHOICE(strs);
}

//-webkit-overflow-scrolling
void HIRMutate::CSS::WebkitOverflowScrollingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "touch"};
    value = CHOICE(strs);
}

//-webkit-print-color-adjust
void HIRMutate::CSS::WebkitPrintColorAdjustValue::generate(Context *context)
{
    static const char *strs[] = {"economy", "exact"};
    value = CHOICE(strs);
}

//-webkit-rtl-ordering
void HIRMutate::CSS::WebkitRtlOrderingValue::generate(Context *context)
{
    static const char *strs[] = {"logical", "visual"};
    value = CHOICE(strs);
}

//-webkit-ruby-position
void HIRMutate::CSS::WebkitRubyPositionValue::generate(Context *context)
{
    static const char *strs[] = {"before", "after", "inter-character"};
    value = CHOICE(strs);
}

//-webkit-text-combine

void HIRMutate::CSS::WebkitTextCombineValue::generate(Context *context)
{
    static const char *strs[] = {"horizontal", "none"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::text_emphasis_style()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"*", "@", "x", "\\25B2"};
        string ans = "'";
        ans.append(CHOICE(strs));
        ans.append("'");
        return ans;
    }
    else
    {
        string selectors = Random::selectors(2);
        vector<string> values;
        if (selectors[0])
        {
            static const char *strs[] = {"filled", "open"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[1])
        {
            static const char *strs[] = {"dot", "circle", "double-circle", "triangle", "sesame"};
            values.push_back(CHOICE(strs));
        }
        return cat(values);
    }
}

//text-emphasis
void HIRMutate::CSS::TextEmphasisValue::generate(Context *context)
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
        values.push_back(text_emphasis_style());
    if (selectors[1])
        values.push_back(DOMValue::color());
    value = cat(values);
}

//text-emphasis-position
void HIRMutate::CSS::TextEmphasisPositionValue::generate(Context *context)
{
    static const char *strs0[] = {"over", "under"};
    static const char *strs1[] = {"right", "left"};
    value = CHOICE(strs0);
    value.append(" ");
    value.append(CHOICE(strs1));
}

//text-emphasis-style
void HIRMutate::CSS::TextEmphasisStyleValue::generate(Context *context)
{
    value = text_emphasis_style();
}

//-webkit-text-security

void HIRMutate::CSS::WebkitTextSecurityValue::generate(Context *context)
{
    static const char *strs[] = {"circle", "disc", "square", "none", "not-secure"};
    value = CHOICE(strs);
}

//-webkit-text-stroke
void HIRMutate::CSS::WebkitTextStrokeValue::generate(Context *context)
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
        values.push_back(DOMValue::length());
    if (selectors[1])
        values.push_back(DOMValue::color());
    value = cat(values);
}

//-webkit-text-stroke-color

void HIRMutate::CSS::WebkitTextStrokeColorValue::generate(Context *context)
{
    value = DOMValue::color();
}

//-webkit-text-stroke-width
void HIRMutate::CSS::WebkitTextStrokeWidthValue::generate(Context *context)
{
    value = DOMValue::length();
}

//-webkit-user-drag
void HIRMutate::CSS::WebkitUserDragValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "element", "none"};
    value = CHOICE(strs);
}

//-webkit-user-modify
void HIRMutate::CSS::WebkitUserModifyValue::generate(Context *context)
{
    static const char *strs[] = {"read-only", "read-write", "read-write-plaintext-only", "write-only"};
    value = CHOICE(strs);
}

//-webkit-wrap-flow
void HIRMutate::CSS::WebkitWrapFlowValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "both", "start", "end", "maximum", "clear"};
    value = CHOICE(strs);
}

// align-content
void HIRMutate::CSS::AlignContentValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
        value = "normal";
    else if (c == 1)
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"first", "last"};
            values.push_back(CHOICE(strs));
        }
        values.push_back("baseline");
        value = cat(values);
    }
    else if (c == 2)
    {
        static const char *strs[] = {"space-between", "space-around", "space-evenly", "stretch"};
        value = CHOICE(strs);
    }
    else
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"unsafe", "safe"};
            values.push_back(CHOICE(strs));
        }
        static const char *strs[] = {"center", "start", "end", "flex-start", "flex-end"};
        values.push_back(CHOICE(strs));
        value = cat(values);
    }
}

//align-items
void HIRMutate::CSS::AlignItemsValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
        value = "normal";
    else if (c == 1)
        value = "stretch";
    else if (c == 2)
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"first", "last"};
            values.push_back(CHOICE(strs));
        }
        values.push_back("baseline");
        value = cat(values);
    }
    else
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"unsafe", "safe"};
            values.push_back(CHOICE(strs));
        }
        static const char *strs[] = {"center", "start", "end", "flex-start", "flex-end", "self-start", "self-end"};
        values.push_back(CHOICE(strs));
        value = cat(values);
    }
}

//align-self

void HIRMutate::CSS::AlignSelfValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
    {
        static const char *strs[] = {"auto", "normal"};
        value = CHOICE(strs);
    }
    else if (c == 1)
        value = "stretch";
    else if (c == 2)
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"first", "last"};
            values.push_back(CHOICE(strs));
        }
        values.push_back("baseline");
        value = cat(values);
    }
    else
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"unsafe", "safe"};
            values.push_back(CHOICE(strs));
        }
        static const char *strs[] = {"center", "start", "end", "flex-start", "flex-end", "self-start", "self-end"};
        values.push_back(CHOICE(strs));
        value = cat(values);
    }
}

// all
void HIRMutate::CSS::AllValue::generate(Context *context)
{
    value = "revert";
}

string HIRMutate::CSS::animation_name(Context *context)
{
    int count = Random::range(1, 2);
    string ans = ((DOMContext *)context)->get_token("keyframes");
    for (int i = 0; i < count - 1; i++)
    {
        ans.append(",");
        ans.append(((DOMContext *)context)->get_token("keyframes"));
    }
    return ans;
}

string HIRMutate::CSS::animation_duration()
{
    return DOMValue::clock();
}

string HIRMutate::CSS::single0()
{
    if (Random::gbool())

        return DOMValue::animation_easing();
    else
        return step_timing_function();
}
string HIRMutate::CSS::animation_timing_function()
{
    int count = Random::range(1, 2);
    string ans = single0();
    for (int i = 0; i < count - 1; i++)
    {
        ans.append(",");
        ans.append(single0());
    }
    return ans;
}

string HIRMutate::CSS::animation_delay()
{
    string value = DOMValue::clock();
    if (Random::gbool())
        value = "-" + value;
    return value;
}

string HIRMutate::CSS::animation_direction()
{
    int count = Random::range(1, 2);
    string ans = DOMValue::animation_direction();
    for (int i = 0; i < count - 1; i++)
    {
        ans.append(",");
        ans.append(DOMValue::animation_direction());
    }
    return ans;
}

string HIRMutate::CSS::animation_iteration_count()
{
    if (Random::gbool())
        return "infinite";
    else
        return Random::number();
}

string HIRMutate::CSS::animation_fill_mode()
{
    int count = Random::range(1, 2);
    string ans = DOMValue::animation_fill_mode();
    for (int i = 0; i < count - 1; i++)
    {
        ans.append(",");
        ans.append(DOMValue::animation_fill_mode());
    }
    return ans;
}

//animation-delay
void HIRMutate::CSS::AnimationDelayValue::generate(Context *context)
{
    value = animation_delay();
}

//animation-direction

void HIRMutate::CSS::AnimationDirectionValue::generate(Context *context)
{
    value = animation_direction();
}

//animation-duration

void HIRMutate::CSS::AnimationDurationValue::generate(Context *context)
{
    value = animation_duration();
}

//animation-fill-mode

void HIRMutate::CSS::AnimationFillModeValue::generate(Context *context)
{
    value = animation_fill_mode();
}

//animation-iteration-count

void HIRMutate::CSS::AnimationIterationCountValue::generate(Context *context)
{
    value = animation_iteration_count();
}

//animation-play-state

void HIRMutate::CSS::AnimationPlayStateValue::generate(Context *context)
{
    value = DOMValue::play_state();
}

//animation-timing-function

void HIRMutate::CSS::AnimationTimingFunctionValue::generate(Context *context)
{
    value = animation_timing_function();
}

//backface-visibility

void HIRMutate::CSS::BackfaceVisibilityValue::generate(Context *context)
{
    static const char *strs[] = {"visible", "hidden"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::background_clip()
{
    int num = Random::range(1, 2);
    static const char *strs[] = {"border-box", "padding-box", "content-box", "text"};
    string ans = CHOICE(strs);
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(CHOICE(strs));
    }
    return ans;
}

string HIRMutate::CSS::background_origin()
{
    int num = Random::range(1, 2);
    static const char *strs[] = {"border-box", "padding-box", "content-box"};
    string ans = CHOICE(strs);
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(CHOICE(strs));
    }
    return ans;
}

string HIRMutate::CSS::single1()
{
    if (Random::gbool())
        return "auto";
    else
        return DOMValue::length_percentage();
}

string HIRMutate::CSS::background_size()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"cover", "contain", "auto"};
        return CHOICE(strs);
    }
    else
    {
        int num = Random::range(1, 2);
        string ans = single1();
        for (int i = 0; i < num - 1; i++)
        {
            ans.append(" ");
            ans.append(single1());
        }
        return ans;
    }
};

string HIRMutate::CSS::background_attachment()
{
    static const char *strs[] = {"scroll", "fixed", "local"};
    return CHOICE(strs);
}

string HIRMutate::CSS::background_repeat()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"repeat-x", "repeat-y"};
        return CHOICE(strs);
    }
    else
    {
        int num = Random::range(1, 2);
        static const char *strs[] = {"repeat", "space", "round", "no-repeat"};
        string ans = CHOICE(strs);
        for (int i = 0; i < num - 1; i++)
        {
            ans.append(" ");
            ans.append(CHOICE(strs));
        }
        return ans;
    }
}

string HIRMutate::CSS::background_position()
{
    int c = Random::selector(3);
    if (c == 0)
    {
        if (Random::gbool())
        {
            static const char *strs[] = {"left", "center", "right", "top", "bottom"};
            return CHOICE(strs);
        }
        else
            return DOMValue::length_percentage();
    }
    else if (c == 1)
    {
        vector<string> values;
        if (Random::gbool())
        {
            if (Random::gbool())
            {
                static const char *strs[] = {"left", "center", "right"};
                values.push_back(CHOICE(strs));
            }
            else
                values.push_back(DOMValue::length_percentage());
        }
        else
        {
            if (Random::gbool())
            {
                static const char *strs[] = {"top", "center", "bottom"};
                values.push_back(CHOICE(strs));
            }
            else
                values.push_back(DOMValue::length_percentage());
        }
        return cat(values);
    }
    else
    {
        vector<string> values;
        if (Random::gbool())
        {
            values.push_back("center");
        }
        else
        {
            static const char *strs[] = {"left", "right"};
            values.push_back(CHOICE(strs));
            if (Random::gbool())
                values.push_back(DOMValue::length_percentage());
        }
        if (Random::gbool())
            values.push_back("center");
        else
        {
            static const char *strs[] = {"top", "bottom"};
            values.push_back(CHOICE(strs));
            if (Random::gbool())
                values.push_back(DOMValue::length_percentage());
        }
        return cat(values);
    }
}

//background

void HIRMutate::CSS::BackgroundValue::generate(Context *context)
{
    string selectors = Random::selectors(7);
    vector<string> values;
    if (selectors[0])
        values.push_back(DOMValue::color());
    if (selectors[1])
        values.push_back(image());
    if (selectors[2])
    {
        values.push_back(background_position());
        if (Random::gbool())
        {
            values.push_back("/");
            values.push_back(background_size());
        }
    }
    if (selectors[3])
        values.push_back(background_repeat());
    if (selectors[4])
        values.push_back(background_attachment());
    if (selectors[5])
        values.push_back(background_origin());
    if (selectors[6])
        values.push_back(background_clip());
    value = cat(values);
}

//background-attachment

void HIRMutate::CSS::BackgroundAttachmentValue::generate(Context *context)
{
    value = background_attachment();
}

string HIRMutate::CSS::blend_mode()
{
    static const char *strs[] = {"normal", "multiply", "screen", "overlay", "darken", "lighten", "color-dodge", "color-burn", "hard-light",
                                 "soft-light", "difference", "exclusion", "hue", "saturation", "color", "luminosity"};
    return CHOICE(strs);
}

//mode / mix-blend-mode in SVG

void HIRMutate::CSS::BlendModeValue::generate(Context *context)
{
    value = blend_mode();
}

//background-blend-mode
void HIRMutate::CSS::BackgroundBlendModeValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = blend_mode();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(",");
        value.append(blend_mode());
    }
}

//background-clip
void HIRMutate::CSS::BackgroundClipValue::generate(Context *context)
{
    value = background_clip();
}

//background-origin
void HIRMutate::CSS::BackgroundOriginValue::generate(Context *context)
{
    value = background_origin();
}

//background-position
void HIRMutate::CSS::BackgroundPositionValue::generate(Context *context)
{
    value = background_position();
}

//background-position-x
void HIRMutate::CSS::BackgroundPositionXValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "center";
    else if (c == 1)
    {
        static const char *strs[] = {"left", "right", "x-start", "x-end"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length_percentage();
}

//background-position-y

void HIRMutate::CSS::BackgroundPositionYValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "center";
    else if (c == 1)
    {
        static const char *strs[] = {"left", "right", "y-start", "y-end"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length_percentage();
}

//background-repeat
void HIRMutate::CSS::BackgroundRepeatValue::generate(Context *context)
{
    value = background_repeat();
}

//background-repeat-x

void HIRMutate::CSS::BackgroundRepeatXValue::generate(Context *context)
{
    value = repeat();
}

//background-size

void HIRMutate::CSS::BackgroundSizeValue::generate(Context *context)
{
    value = background_size();
}

string HIRMutate::CSS::border_style()
{
    static const char *strs[] = {"hidden", "dotted", "dashed", "solid", "double", "groove", "ridge",
                                 "inset", "outset"};
    return CHOICE(strs);
}

string HIRMutate::CSS::border_color()
{
    int num = Random::range(1, 4);
    string ans = DOMValue::color();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(DOMValue::color());
    }
    return ans;
}

//border / column-rule
void HIRMutate::CSS::BorderValue::generate(Context *context)
{
    string selectors = Random::selectors(3);
    vector<string> values;
    if (selectors[0])
        values.push_back(line_width());
    if (selectors[1])
        values.push_back(border_style());
    if (selectors[2])
        values.push_back(DOMValue::color());
    value = cat(values);
}

//border-bottom
void HIRMutate::CSS::LineValue::generate(Context *context)
{
    string selectors = Random::selectors(3);
    vector<string> values;
    if (selectors[0])
        values.push_back(line_width());
    if (selectors[1])
        values.push_back(line_style());
    if (selectors[2])
        values.push_back(DOMValue::color());
    value = cat(values);
}

// border-collapse
void HIRMutate::CSS::BorderCollapseValue::generate(Context *context)
{
    static const char *strs[] = {"collapse", "separate"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::border_image_slice()
{
    int num = Random::range(1, 4);
    string ans = DOMValue::number_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(DOMValue::number_percentage());
    }
    if (Random::gbool())
        ans.append(" fill");
    return ans;
}

string HIRMutate::CSS::border_image_width()
{
    int num = Random::range(1, 4);
    vector<string> values;
    for (int i = 0; i < num; i++)
    {
        int c = Random::selector(3);
        if (c == 0)
            values.push_back(DOMValue::length_percentage());
        else if (c == 1)
            values.push_back(Random::number());
        else
            values.push_back("auto");
    }
    return cat(values);
}

string HIRMutate::CSS::border_image_outset()
{
    int num = Random::range(1, 4);
    vector<string> values;
    for (int i = 0; i < num; i++)
    {
        if (Random::gbool())
            values.push_back(DOMValue::length());
        else
            values.push_back(Random::number());
    }
    return cat(values);
}

string HIRMutate::CSS::border_image_repeat()
{
    int num = Random::range(1, 2);
    static const char *strs[] = {"stretch", "repeat", "round", "space"};
    string ans = CHOICE(strs);
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(CHOICE(strs));
    }
    return ans;
}

//border-image
void HIRMutate::CSS::BorderImageValue::generate(Context *context)
{
    vector<string> values;
    string selectors = Random::selectors(3);
    if (selectors[0])
        values.push_back(image());
    if (selectors[1])
    {
        values.push_back(border_image_slice());
        if (Random::gbool())
        {
            values.push_back("/");
            values.push_back(border_image_width());
        }
        else
        {
            if (Random::gbool())
            {
                values.push_back("/");
                values.push_back(border_image_width());
            }
            values.push_back("/");
            values.push_back(border_image_outset());
        }
    }
    if (selectors[2])
        values.push_back(border_image_repeat());
    value = cat(values);
}

//border-image-outset
void HIRMutate::CSS::BorderImageOutsetValue::generate(Context *context)
{
    value = border_image_outset();
}

//border-image-repeat
void HIRMutate::CSS::BorderImageRepeatValue::generate(Context *context)
{
    value = border_image_repeat();
}

//border-image-slice
void HIRMutate::CSS::BorderImageSliceValue::generate(Context *context)
{
    value = border_image_slice();
}

//border-image-width
void HIRMutate::CSS::BorderImageWidthValue::generate(Context *context)
{
    value = border_image_width();
}

//border-radius
void HIRMutate::CSS::BorderRadiusValue::generate(Context *context)
{
    if (Random::selector(5) == 0)
        value = "inherit";
    else
        value = DOMValue::border_radius();
}

//border-spacing
void HIRMutate::CSS::BorderSpacingValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
}

// border-style
void HIRMutate::CSS::BorderStyleValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = border_style();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(border_style());
    }
}

//border-width
void HIRMutate::CSS::BorderWidthValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = line_width();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(line_width());
    }
}

// box-align
void HIRMutate::CSS::BoxAlignValue::generate(Context *context)
{
    static const char *strs[] = {"start", "center", "end", "baseline", "stretch"};
    value = CHOICE(strs);
}

// box-decoration-break
void HIRMutate::CSS::BoxDecorationBreakValue::generate(Context *context)
{
    static const char *strs[] = {"slice", "clone"};
    value = CHOICE(strs);
}

//box-direction
void HIRMutate::CSS::BoxDirectionValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "reverse", "inherit"};
    value = CHOICE(strs);
}

// box-lines
void HIRMutate::CSS::BoxLinesValue::generate(Context *context)
{
    static const char *strs[] = {"single", "multiple"};
    value = CHOICE(strs);
}

// box-orient
void HIRMutate::CSS::BoxOrientValue::generate(Context *context)
{
    static const char *strs[] = {"horizontal", "vertical", "inline-axis", "block-axis", "inherit"};
    value = CHOICE(strs);
}

// box-pack
void HIRMutate::CSS::BoxPackValue::generate(Context *context)
{
    static const char *strs[] = {"start", "center", "end", "justify"};
    value = CHOICE(strs);
}

//box-reflect
void HIRMutate::CSS::BoxReflectValue::generate(Context *context)
{
    string selectors = Random::selectors(3);
    vector<string> values;
    if (selectors[0])
    {
        static const char *strs[] = {"above", "below", "right", "left"};
        values.push_back(CHOICE(strs));
    }
    if (selectors[1])
        values.push_back(DOMValue::length());
    if (selectors[2])
        values.push_back(image());
    value = cat(values);
}

// box-shadow
void HIRMutate::CSS::BoxShadowValue::generate(Context *context)
{
    int num = Random::range(2, 4);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
    if (Random::gbool())
        value.append(" inset");
    if (Random::gbool())
    {
        value.append(" ");
        value.append(DOMValue::color());
    }
}

// box-sizing
void HIRMutate::CSS::BoxSizingValue::generate(Context *context)
{
    static const char *strs[] = {"content-box", "border-box", "padding-box"};
    value = CHOICE(strs);
}

// page
void HIRMutate::CSS::PageValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"Rotated", "Auto", "Auto Rotated"};
        value = CHOICE(strs);
    }
    else
    {
        value = Random::integer();
        value.append("cm");
    }
}

// break-after
void HIRMutate::CSS::BreakValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "avoid", "always", "all", "avoid-page", "page", "left", "right", "recto",
                                 "verso", "avoid-column", "column", "avoid-region", "region"};
    value = CHOICE(strs);
}

// break-inside
void HIRMutate::CSS::BreakInsideValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "avoid", "avoid-page", "avoid-column", "avoid-region"};
    value = CHOICE(strs);
}

// caption-side
void HIRMutate::CSS::CaptionSideValue::generate(Context *context)
{
    static const char *strs[] = {"top", "bottom", "block-start", "block-end", "inline-start", "inline-end"};
    value = CHOICE(strs);
}

// clear
void HIRMutate::CSS::ClearValue::generate(Context *context)
{
    static const char *strs[] = {"left", "right", "both", "inline-start", "inline-end"};
    value = CHOICE(strs);
}

// clip

string HIRMutate::CSS::ClipValue::edge()
{
    if (Random::gbool())
        return "auto";
    else
        return DOMValue::length();
}
void HIRMutate::CSS::ClipValue::generate(Context *context)
{

    if (Random::selector(5) == 0)
        value = "auto";
    else
    {
        value = "rect(";
        value.append(edge());
        for (int i = 0; i < 3; i++)
        {
            value.append(",");
            value.append(edge());
        }
        value.append(")");
    }
}

// column-break-after
void HIRMutate::CSS::ColumnBreakAfterValue::generate(Context *context)
{
    static const char *strs[] = {"always", "auto", "avoid"};
    value = CHOICE(strs);
}

// column-count
void HIRMutate::CSS::ColumnCountValue::generate(Context *context)
{
    value = column_count();
}

// column-fill
void HIRMutate::CSS::ColumnFillValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "balance", "balance-all"};
    value = CHOICE(strs);
}

// column-gap
void HIRMutate::CSS::ColumnGapValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"initial", "normal"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length_percentage();
}

// column-span
void HIRMutate::CSS::ColumnSpanValue::generate(Context *context)
{
    value = "all";
}

// column-width
void HIRMutate::CSS::ColumnWidthValue::generate(Context *context)
{
    value = column_width();
}

//columns
void HIRMutate::CSS::ColumnsValue::generate(Context *context)
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
        values.push_back(column_width());
    if (selectors[1])
        values.push_back(column_count());
    value = cat(values);
}

// contain
void HIRMutate::CSS::ContainValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"strict", "content"};
        value = CHOICE(strs);
    }
    else
    {
        string selectors = Random::selectors(4);
        vector<string> values;
        if (selectors[0])
            values.push_back("size");
        if (selectors[1])
            values.push_back("layout");
        if (selectors[2])
            values.push_back("style");
        if (selectors[3])
            values.push_back("paint");
        value = cat(values);
    }
}

// content
void HIRMutate::CSS::ContentValue::generate(Context *context)
{
    int c = Random::selector(7);
    if (c == 0)
    {
        static const char *strs[] = {"normal", "contents"};
        value = CHOICE(strs);
    }
    else if (c == 1)
        value = "'foo'";
    else if (c == 2)
        value = quote();
    else if (c == 3)
        value = leader();
    else if (c == 4)
    {
        static const char *strs[] = {"disc", "circle", "decimal", "lower-alpha", "upper-alpha",
                                     "lower-latin", "upper-latin", "lower-roman", "upper-roman"};
        value = "counter(";
        value.append(((DOMContext *)context)->get_token("counter"));
        value.append(", ");
        value.append(CHOICE(strs));
        value.append(")");
    }
    else if (c == 5)
    {
        static const char *strs[] = {"disc", "circle", "decimal", "lower-alpha", "upper-alpha",
                                     "lower-latin", "upper-latin", "lower-roman", "upper-roman"};
        value = "counters(";
        value.append(((DOMContext *)context)->get_token("counter"));
        value.append(", '.', ");
        value.append(CHOICE(strs));
        value.append(")");
    }
    else
        value = image();
}

string HIRMutate::CSS::cursor_fallback()
{
    static const char *strs[] = {"auto", "default", "context-menu", "help", "pointer", "progress", "wait", "cell", "crosshair",
                                 "text", "vertical-text", "alias", "copy", "move", "no-drop", "not-allowed", "e-resize", "n-resize",
                                 "ne-resize", "nw-resize", "s-resize", "se-resize", "sw-resize", "w-resize", "ew-resize", "ns-resize",
                                 "nesw-resize", "nwse-resize", "col-resize", "row-resize", "all-scroll", "zoom-in", "zoom-out", "grab",
                                 "grabbing"};
    return CHOICE(strs);
}

// direction
void HIRMutate::CSS::DirectionValue::generate(Context *context)
{
    static const char *strs[] = {"ltr", "rtl"};
    value = CHOICE(strs);
}

// display
void HIRMutate::CSS::DisplayValue::generate(Context *context)
{
    int c = Random::selector(5);
    vector<string> values;
    if (c == 0)
    {
        string selectors = Random::selectors(2);
        if (selectors[0])
        {
            static const char *strs[] = {"block", "inline", "run-in"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[1])
        {
            static const char *strs[] = {"flow", "flow-root", "table", "flex", "grid", "ruby"};
            values.push_back(CHOICE(strs));
        }
        value = cat(values);
    }
    else if (c == 1)
    {
        values.push_back("list-item");
        if (Random::gbool())
        {
            static const char *strs[] = {"block", "inline", "run-in"};
            values.push_back(CHOICE(strs));
        }
        if (Random::gbool())
        {
            static const char *strs[] = {"flow", "flow-root"};
            values.push_back(CHOICE(strs));
        }
        value = cat(values);
    }
    else if (c == 2)
    {
        static const char *strs[] = {"table-row-group", "table-header-group", "table-footer-group", "table-row",
                                     "table-cell", "table-column-group", "table-column", "table-caption"};
        value = CHOICE(strs);
    }
    else if (c == 3)
        value = "contents";
    else
    {
        static const char *strs[] = {"inline-block", "inline-list-item", "inline-table", "inline-flex", "inline-grid"};
        value = CHOICE(strs);
    }
}

// empty-cells
void HIRMutate::CSS::EmptyCellsValue::generate(Context *context)
{
    static const char *strs[] = {"show", "hide"};
    value = CHOICE(strs);
}

// flex
void HIRMutate::CSS::FlexValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
    {
        if (Random::gbool())
            value = "auto";
        else
            value = Random::number();
    }
    else if (c == 1)
        value = Random::number() + " " + flex_basis();
    else
        value = Random::number() + " " + Random::number() + flex_basis();
}

//flex-basis
void HIRMutate::CSS::FlexBasisValue::generate(Context *context)
{
    value = flex_basis();
}

// flex-direction
void HIRMutate::CSS::FlexDirectionValue::generate(Context *context)
{
    value = flex_direction();
}

// flex-flow
void HIRMutate::CSS::FlexFlowValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = flex_direction();
    else if (c == 1)
        value = flex_wrap();
    else
        value = flex_direction() + " " + flex_wrap();
}

// flex-wrap
void HIRMutate::CSS::FlexWrapValue::generate(Context *context)
{
    value = flex_wrap();
}

// float
void HIRMutate::CSS::FloatValue::generate(Context *context)
{
    static const char *strs[] = {"left", "right", "inline-start", "inline-end", "none"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::font_style()
{
    static const char *strs[] = {"normal", "italic", "oblique"};
    return CHOICE(strs);
}

string HIRMutate::CSS::font_size()
{
    int c = Random::selector(3);
    if (c == 0)
    {
        static const char *strs[] = {"xx-small", "x-small", "small", "medium", "large", "x-large", "xx-large"};
        return CHOICE(strs);
    }
    else if (c == 1)
    {
        static const char *strs[] = {"larger", "smaller"};
        return CHOICE(strs);
    }
    else
        return DOMValue::length_percentage(true);
}

string HIRMutate::CSS::font_family()
{
    static const char *strs[] = {"monospace",
                                 "Consolas",
                                 "'Liberation Mono'",
                                 "Menlo",
                                 "Courier",
                                 "sans-serif",
                                 "system-ui",
                                 "Times",
                                 "'Courier New'",
                                 "Arial",
                                 "Helvetica",
                                 "'Comic Sans MS'",
                                 "serif",
                                 "Verdana",
                                 "'Times New Roman'"};
    int num = Random::range(1, 2);
    string ans = CHOICE(strs);
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(CHOICE(strs));
    }
    return ans;
}

// font
void HIRMutate::CSS::FontValue::generate(Context *context)
{
    if (Random::selector(5) == 0)
    {
        static const char *strs[] = {"initial", "caption", "icon", "menu", "message-box",
                                     "small-caption", "status-bar"};
        value = CHOICE(strs);
    }
    else
    {
        string selectors = Random::selectors(4);
        vector<string> values;
        if (selectors[0])
            values.push_back(font_style());
        if (selectors[1])
            values.push_back(DOMValue::font_variant());
        if (selectors[2])
            values.push_back(DOMValue::font_weight());
        if (selectors[3])
            values.push_back(DOMValue::font_stretch());

        string size = font_size();
        if (Random::gbool())
            size += " / " + line_height();
        values.push_back(size);
        values.push_back(font_family());
        value = cat(values);
    }
}

// font-family
void HIRMutate::CSS::FontFamilyValue::generate(Context *context)
{
    value = font_family();
}

// font-feature-settings
void HIRMutate::CSS::FontFeatureSettingsValue::generate(Context *context)
{
    value = DOMValue::font_feature_settings();
}

// font-smooth
void HIRMutate::CSS::FontSmoothValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "never", "always"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length();
}

// font-kerning
void HIRMutate::CSS::FontKerningValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "normal"};
    value = CHOICE(strs);
}

// font-size
void HIRMutate::CSS::FontSizeValue::generate(Context *context)
{
    if (Random::selector(10) == 0)
        value = "inherit";
    else
        value = font_size();
}

// font-size-adjust
void HIRMutate::CSS::FontSizeAdjustValue::generate(Context *context)
{
    value = Random::number();
}

// font-stretch
void HIRMutate::CSS::FontStretchValue::generate(Context *context)
{
    value = DOMValue::font_stretch();
}

// font-style
void HIRMutate::CSS::FontStyleValue::generate(Context *context)
{
    if (Random::selector(5) == 0)
        value = "inherit";
    else
        value = font_style();
}

// font-variant
void HIRMutate::CSS::FontVariantValue::generate(Context *context)
{
    value = DOMValue::font_variant();
}

// font-variant-caps
void HIRMutate::CSS::FontVariantCapsValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "small-caps", "all-small-caps", "petite-caps", "all-petite-caps", "unicase", "titling-caps"};
    value = CHOICE(strs);
}

// font-variant-ligatures
void HIRMutate::CSS::FontVariantLigaturesValue::generate(Context *context)
{
    if (Random::selector(5) == 0)
        value = "normal";
    else
    {
        string selectors = Random::selectors(4);
        vector<string> values;
        if (selectors[0])
        {
            static const char *strs[] = {"common-ligatures", "no-common-ligatures"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[1])
        {
            static const char *strs[] = {"discretionary-ligatures", "no-discretionary-ligatures"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[2])
        {
            static const char *strs[] = {"historical-ligatures", "no-historical-ligatures"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[3])
        {
            static const char *strs[] = {"contextual", "no-contextual"};
            values.push_back(CHOICE(strs));
        }
        value = cat(values);
    }
}

// font-weight
void HIRMutate::CSS::FontWeightValue::generate(Context *context)
{
    value = DOMValue::font_weight();
}

string HIRMutate::CSS::grid_template_rows()
{
    if (Random::selector(5) == 0)
        return "auto";
    else
    {
        if (Random::gbool())
            return track_list();
        else
            return auto_track_list();
    }
}

string HIRMutate::CSS::grid_template()
{
    return grid_template_rows() + " / " + grid_template_rows();
}

string HIRMutate::CSS::grid_auto_rows()
{
    int num = Random::range(1, 2);
    string ans = track_size();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(track_size());
    }
    return ans;
}

// grid
void HIRMutate::CSS::GridValue::generate(Context *context)
{
    int c = Random::selector(3);
    vector<string> values;
    if (c == 0)
        value = grid_template();
    else if (c == 1)
    {
        values.push_back(grid_template_rows());
        values.push_back("/");
        values.push_back("auto-flow");
        if (Random::gbool())
            values.push_back("dense");
        if (Random::gbool())
            values.push_back(grid_auto_rows());
        value = cat(values);
    }
    else
    {
        values.push_back("auto-flow");
        if (Random::gbool())
            values.push_back("dense");
        if (Random::gbool())
            values.push_back(grid_auto_rows());
        values.push_back("/");
        values.push_back(grid_template_rows());
        value = cat(values);
    }
}

string HIRMutate::CSS::grid_line()
{
    int c = Random::selector(4);
    static const char *strs[] = {"a", "b", "c"};
    if (c == 0)
        return "auto";
    else if (c == 1)
    {
        return CHOICE(strs);
    }
    else if (c == 2)
    {
        string s = Random::integer();
        if (Random::gbool())
        {
            s.append(" ");
            s.append(CHOICE(strs));
        }
        return s;
    }
    else
    {
        string s = "span";
        if (Random::gbool())
        {
            if (Random::gbool())
                s += " " + Random::integer();
            else
            {
                s.append(" ");
                s.append(CHOICE(strs));
            }
        }
        return s;
    }
}

// grid-area
void HIRMutate::CSS::GridAreaValue::generate(Context *context)
{
    value = grid_line();
    int num = Random::range(0, 3);
    for (int i = 0; i < num; i++)
    {
        value.append(" / ");
        value.append(grid_line());
    }
}

// grid-auto-rows, columns
void HIRMutate::CSS::GridAutoRowsColumnsValue::generate(Context *context)
{
    value = grid_auto_rows();
}

// grid-auto-flow
void HIRMutate::CSS::GridAutoFlowValue::generate(Context *context)
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
    {
        static const char *strs[] = {"row", "column"};
        values.push_back(CHOICE(strs));
    }
    if (selectors[1])
        values.push_back("dense");
    value = cat(values);
}

// grid-row, column
// TODO: custom-ident
void HIRMutate::CSS::GridRowValue::generate(Context *context)
{
    value = grid_line();
    if (Random::gbool())
    {
        value.append(" / ");
        value.append(grid_line());
    }
}

// grid-column-end
void HIRMutate::CSS::GridLineValue::generate(Context *context)
{
    value = grid_line();
}

// grid-column-gap
void HIRMutate::CSS::GridLineGapValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"normal", "inherit"};
        value = CHOICE(strs);
    }
    else
    {
        value = DOMValue::length_percentage(true);
    }
}

// grid-gap
void HIRMutate::CSS::GridGapValue::generate(Context *context)
{
    value = DOMValue::length_percentage();
    if (Random::gbool())
        value += " " + DOMValue::length_percentage();
}

// grid-template
void HIRMutate::CSS::GridTemplateValue::generate(Context *context)
{
    value = grid_template();
}

// grid-template-areas
void HIRMutate::CSS::GridTemplateAreasValue::generate(Context *context)
{
    static const char *strs[] = {"'a'", "'b'", "'c'",
                                 "'a b'", "'a a'", "'b c'",
                                 "'a a .'", "'a b b'",
                                 "'a b b' 'a c c'"};
    value = CHOICE(strs);
}

// grid-template-columns
void HIRMutate::CSS::GridTemplateRowsColumnsValue::generate(Context *context)
{
    value = grid_template_rows();
}

// height / width
void HIRMutate::CSS::HeightValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
        value = DOMValue::length_percentage(true);
    else if (c == 1)
    {
        value = "fit-content(";
        value.append(DOMValue::length_percentage(true));
        value.append(")");
    }
    else if (c == 2)
    {
        static const char *strs[] = {"min-content", "max-content", "auto"};
        value = CHOICE(strs);
    }
    else
        value = "auto";
}

// hyphens
void HIRMutate::CSS::HyphensValue::generate(Context *context)
{
    static const char *strs[] = {"manual", "auto", "none"};
    value = CHOICE(strs);
}

//image-orientation
void HIRMutate::CSS::ImageOrientationValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "from-image";
    else if (c == 1)
        value = DOMValue::angle();
    else
    {
        value = "flip";
        if (Random::gbool())
            value = DOMValue::angle() + " " + value;
    }
}

// image-rendering
void HIRMutate::CSS::ImageRenderingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "smooth", "high-quality", "crisp-edges", "pixelated",
                                 "-webkit-optimize-contrast"};
    value = CHOICE(strs);
}

// isolation
void HIRMutate::CSS::IsolationValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "isolate"};
    value = CHOICE(strs);
}

// justify-content
void HIRMutate::CSS::JustifyContentValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "normal";
    else if (c == 1)
    {
        static const char *strs[] = {"space-between", "space-around", "space-evenly", "stretch"};
        value = CHOICE(strs);
    }
    else
    {
        static const char *strs[] = {"center", "start", "end", "flex-start", "flex-end", "left", "right"};
        value = CHOICE(strs);
        if (Random::gbool())
        {
            static const char *strs[] = {"unsafe", "safe"};
            value = CHOICE(strs);
            value.append(" ");
            value.append(value);
        }
    }
}

// justify-items
void HIRMutate::CSS::JustifyItemsValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
    {
        static const char *strs[] = {"normal", "stretch", "legacy"};
        value = CHOICE(strs);
    }
    else if (c == 1)
    {
        static const char *strs[] = {"left", "right", "center"};
        value = "legacy ";
        value.append(CHOICE(strs));
    }
    else if (c == 2)
        value = baseline_position();
    else
    {

        if (Random::gbool())
            value = self_position();
        else
        {
            static const char *strs[] = {"left", "right"};
            value = CHOICE(strs);
        }
        if (Random::gbool())
            value = overflow_position() + " " + value;
    }
}

//justify-self
void HIRMutate::CSS::JustifySelfValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
    {
        static const char *strs[] = {"normal", "stretch", "auto"};
        value = CHOICE(strs);
    }
    else if (c == 1)
        value = baseline_position();
    else
    {
        if (Random::gbool())
            value = self_position();
        else
        {
            static const char *strs[] = {"left", "right"};
            value = CHOICE(strs);
        }
        if (Random::gbool())
            value = overflow_position() + " " + value;
    }
}

// kerning
void HIRMutate::CSS::KerningValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "normal"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length();
}
//letter-spacing
void HIRMutate::CSS::LetterSpacingValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::length();
    else
        value = "normal";
}

// line-break
void HIRMutate::CSS::LineBreakValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "loose", "normal", "strict", "anywhere",
                                 "after-white-space", "before-white-space"};
    value = CHOICE(strs);
}

void HIRMutate::CSS::WebKitLocaleValue::generate(Context *context)
{
    value = "'zh_CN'";
}

//line-height
void HIRMutate::CSS::LineHeightValue::generate(Context *context)
{
    int c = Random::selector(4);
    if (c == 0)
        value = "normal";
    else if (c == 1)
        value = Random::number();
    else if (c == 2)
        value = DOMValue::length(true);
    else
        value = DOMValue::percentage();
}

string HIRMutate::CSS::list_style_image()
{
    string ans = "url(";
    ans.append(DOMValue::image_url());
    ans.append(")");
    return ans;
}

string HIRMutate::CSS::list_style_type()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"disc", "disclosure-open", "disclosure-closed"};
        return CHOICE(strs);
    }
    else
    {
        static const char *strs[] = {"circle", "square", "decimal", "cjk-decimal", "decimal-leading-zero", "lower-roman", "upper-roman",
                                     "lower-greek", "lower-alpha", "lower-latin", "upper-alpha", "upper-latin", "arabic-indic", "armenian",
                                     "bengali", "cambodian", "cjk-earthly-branch", "cjk-heavenly-stem", "cjk-ideographic", "devanagari",
                                     "ethiopic-numeric", "georgian", "gujarati", "gurmukhi", "hebrew", "hiragana", "hiragana-iroha",
                                     "japanese-formal", "japanese-informal", "kannada", "katakana", "katakana-iroha", "khmer",
                                     "korean-hangul-formal", "korean-hanja-formal", "korean-hanja-informal", "lao", "lower-armenian",
                                     "malayalam", "mongolian", "myanmar", "oriya", "persian", "simp-chinese-formal",
                                     "simp-chinese-informal", "tamil", "telugu", "thai", "tibetan", "trad-chinese-formal",
                                     "trad-chinese-informal", "upper-armenian"};
        return CHOICE(strs);
    }
};

string HIRMutate::CSS::list_style_position()
{
    static const char *strs[] = {"inside", "outside"};
    return CHOICE(strs);
}

// list-style
void HIRMutate::CSS::ListStyleValue::generate(Context *context)
{
    if (Random::selector(10) == 0)
        value = "inherit";
    else
    {
        string selectors = Random::selectors(3);
        vector<string> values;
        if (selectors[0])
            values.push_back(list_style_image());
        if (selectors[1])
            values.push_back(list_style_position());
        if (selectors[2])
            values.push_back(list_style_type());
        value = cat(values);
    }
}

//list-style-image
void HIRMutate::CSS::ListStyleImageValue::generate(Context *context)
{
    value = list_style_image();
}

// list-style-position
void HIRMutate::CSS::ListStylePositionValue::generate(Context *context)
{
    value = list_style_position();
}

//list-style-type
void HIRMutate::CSS::ListStyleTypeValue::generate(Context *context)
{
    value = list_style_type();
}

// margin
void HIRMutate::CSS::MarginValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = "";
    for (int i = 0; i < num; i++)
    {
        if (Random::gbool())
            value.append(DOMValue::length_percentage());
        else
            value.append("auto");
        if (i != num - 1)
        {
            value.append(" ");
        }
    }
}

//max-zoom
void HIRMutate::CSS::MaxZoomValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::number_percentage();
}

// object-fit
void HIRMutate::CSS::ObjectFitValue::generate(Context *context)
{
    static const char *strs[] = {"fill", "contain", "cover", "scale-down"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::offset_rotate()
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
    {
        static const char *strs[] = {"auto", "reverse"};
        values.push_back(CHOICE(strs));
    }
    if (selectors[1])
        values.push_back(DOMValue::angle());
    return cat(values);
}

string HIRMutate::CSS::offset_anchor()
{
    if (Random::gbool())
        return "auto";
    else
        return DOMValue::position();
}

//offset-anchor
void HIRMutate::CSS::OffsetAnchorValue::generate(Context *context)
{
    value = offset_anchor();
}

// offset-position
void HIRMutate::CSS::OffsetPositionValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::position();
}

// offset-rotate/ion
void HIRMutate::CSS::OffsetRotateValue::generate(Context *context)
{
    value = offset_rotate();
}

string HIRMutate::CSS::outline_color()
{
    if (Random::gbool())
        return DOMValue::color();
    else
        return "invert";
}

string HIRMutate::CSS::outline_style()
{
    if (Random::gbool())
        return border_style();
    else
        return "auto";
}

// outline
void HIRMutate::CSS::OutlineValue::generate(Context *context)
{
    string selectors = Random::selectors(3);
    vector<string> values;
    if (selectors[0])
        values.push_back(outline_color());
    if (selectors[1])
        values.push_back(outline_style());
    if (selectors[2])
        values.push_back(line_width());
    value = cat(values);
}

//outline-color
void HIRMutate::CSS::OutlineColorValue::generate(Context *context)
{
    value = outline_color();
}

// outline-style
void HIRMutate::CSS::OutlineStyleValue::generate(Context *context)
{
    value = outline_style();
}

string HIRMutate::CSS::overflow()
{
    static const char *strs[] = {"visible", "hidden", "clip", "scroll", "auto"
                                                                        "-webkit-paged-x",
                                 "-webkit-paged-y"};
    return CHOICE(strs);
}

//overflow
void HIRMutate::CSS::OverflowValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = overflow();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(overflow());
    }
}

// overflow-anchor
void HIRMutate::CSS::OverflowAnchorValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "none"};
    value = CHOICE(strs);
}

//overflow-wrap
void HIRMutate::CSS::OverflowWrapValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "break-word", "anywhere"};
    value = CHOICE(strs);
}

//overflow-x
void HIRMutate::CSS::OverflowXValue::generate(Context *context)
{
    value = overflow();
}

//padding
void HIRMutate::CSS::PaddingValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = DOMValue::length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length_percentage());
    }
}

//perspective
void HIRMutate::CSS::PerspectiveValue::generate(Context *context)
{
    value = DOMValue::length();
}

// perspective-origin
void HIRMutate::CSS::PerspectiveOriginValue::generate(Context *context)
{
    vector<string> values;
    string selectors = Random::selectors(2);
    if (selectors[0])
    {
        if (Random::gbool())
            values.push_back(DOMValue::length_percentage());
        else
        {
            static const char *strs[] = {"left", "center", "right"};
            values.push_back(CHOICE(strs));
        }
    }
    if (selectors[1])
    {
        if (Random::gbool())
            values.push_back(DOMValue::length_percentage());
        else
        {
            static const char *strs[] = {"top", "center", "bottom"};
            values.push_back(CHOICE(strs));
        }
    }
    value = cat(values);
}

// pointer-events
void HIRMutate::CSS::PointerEventsValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "none"};
    value = CHOICE(strs);
}

void HIRMutate::CSS::PositionValue::generate(Context *context)
{
    value = DOMValue::position();
}

// position
void HIRMutate::CSS::PositionWayValue::generate(Context *context)
{
    static const char *strs[] = {"static", "relative", "absolute", "sticky", "fixed"};
    value = CHOICE(strs);
}

// prince-hyphens
void HIRMutate::CSS::PrinceHyphensValue::generate(Context *context)
{
    value = "auto";
}

// quotes
void HIRMutate::CSS::QuotesValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "none", "initial"};
        value = CHOICE(strs);
    }
    else
    {
        static const char *strs[] = {
            "'{' '}'",
            "'A' 'B' 'C' 'D'",
            "'-' '-'",
            "'(' ')' '[' ']'",
            "'a' 'b' 'c' 'd'",
            "'a' 'b'",
            "'a' 'v' 'b' 'u'",
        };
        value = CHOICE(strs);
    }
}

//resize
void HIRMutate::CSS::ResizeValue::generate(Context *context)
{
    static const char *strs[] = {"both", "horizontal", "vertical", "block", "inline"};
    value = CHOICE(strs);
}

// rotate
void HIRMutate::CSS::RotateValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::angle();
    else
    {
        int c = Random::selector(4);
        if (c == 0)
            value = "x";
        else if (c == 1)
            value = "y";
        else if (c == 2)
            value = "z";
        else
        {
            value = Random::integer();
            for (int i = 0; i < 2; i++)
            {
                value.append(" ");
                value.append(Random::integer());
            }
        }
        value += " " + DOMValue::angle();
    }
}
// scale
void HIRMutate::CSS::ScaleValue::generate(Context *context)
{
    int num = Random::range(1, 3);
    value = Random::number();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(Random::number());
    }
}

// scroll-behavior
void HIRMutate::CSS::ScrollBehaviorValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "smooth"};
    value = CHOICE(strs);
}

// scroll-snap-coordinate
void HIRMutate::CSS::ScrollSnapCoordinateValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = DOMValue::position();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(",");
        value.append(DOMValue::position());
    }
}

// scroll-snap-points-x
void HIRMutate::CSS::ScrollSnapPointsXValue::generate(Context *context)
{
    value = "repeat(";
    value.append(DOMValue::length_percentage());
    value.append(")");
}

// scroll-snap-type
void HIRMutate::CSS::ScrollSnapTypeValue::generate(Context *context)
{
    static const char *strs0[] = {"x", "y", "block", "inline", "both"};
    static const char *strs1[] = {"mandatory", "proximity"};
    value = CHOICE(strs0);
    if (Random::gbool())
    {
        value.append(" ");
        value.append(CHOICE(strs1));
    }
}

// shape-image-threshold
void HIRMutate::CSS::ShapeImageThresholdValue::generate(Context *context)
{
    value = alpha();
}

// shape-outside
void HIRMutate::CSS::ShapeOutsideValue::generate(Context *context)
{
    if (Random::gbool())
    {
        string selectors = Random::selectors(2);
        vector<string> values;
        if (selectors[0])
            values.push_back(shape_box());
        if (selectors[1])
            values.push_back(basic_shape());
        value = cat(values);
    }
    else
        value = image();
}

// table-layout
void HIRMutate::CSS::TableLayoutValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "fixed"};
    value = CHOICE(strs);
}

// text-align
void HIRMutate::CSS::TextAlignValue::generate(Context *context)
{
    static const char *strs[] = {"start", "end", "left", "right", "center", "justify", "match-parent"};
    value = CHOICE(strs);
}

// text-align-last
void HIRMutate::CSS::TextAlignLastValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "start", "end", "left", "right", "center", "justify"};
    value = CHOICE(strs);
}

// text-combine-upright
void HIRMutate::CSS::TextCombineUprightValue::generate(Context *context)
{
    if (Random::gbool())
        value = "all";
    else
    {
        value = "digits";
        if (Random::gbool())
        {
            value.append(" ");
            value.append(Random::integer());
        }
    }
}

string HIRMutate::CSS::text_decoration_line()
{
    string selectors = Random::selectors(4);
    vector<string> values;
    if (selectors[0])
        values.push_back("underline");
    if (selectors[1])
        values.push_back("overline");
    if (selectors[2])
        values.push_back("line-through");
    if (selectors[3])
        values.push_back("blink");
    return cat(values);
}

string HIRMutate::CSS::text_decoration_style()
{
    static const char *strs[] = {"solid", "double", "dotted", "dashed", "wavy"};
    return CHOICE(strs);
}

string HIRMutate::CSS::text_decoration_thickness()
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "from-font"};
        return CHOICE(strs);
    }
    else
        return DOMValue::length();
}

//text-decoration
void HIRMutate::CSS::TextDecorationValue::generate(Context *context)
{
    string selectors = Random::selectors(4);
    vector<string> values;
    if (selectors[0])
        values.push_back(text_decoration_line());
    if (selectors[1])
        values.push_back(DOMValue::color());
    if (selectors[2])
        values.push_back(text_decoration_style());
    if (selectors[3])
        values.push_back(text_decoration_thickness());
    value = cat(values);
}

// text-decoration-line
void HIRMutate::CSS::TextDecorationLineValue::generate(Context *context)
{
    value = text_decoration_line();
}

// text-decoration-skip
void HIRMutate::CSS::TextDecorationSkipValue::generate(Context *context)
{
    string selectors = Random::selectors(4);
    vector<string> values;
    if (selectors[0])
        values.push_back("objects");
    if (selectors[1])
    {
        int c = Random::selector(3);
        if (c == 0)
            values.push_back("spaces");
        else if (c == 1)
            values.push_back("leading-spaces");
        else
            values.push_back("trailing-spaces");
    }
    if (selectors[2])
        values.push_back("edges");
    if (selectors[3])
        values.push_back("box-decoration");
    value = cat(values);
}

//text-decoration-style
void HIRMutate::CSS::TextDecorationStyleValue::generate(Context *context)
{
    value = text_decoration_style();
}

// text-decoration-thickness
void HIRMutate::CSS::TextDecorationThicknessValue::generate(Context *context)
{
    value = text_decoration_thickness();
}

// text-indent
void HIRMutate::CSS::TextIndentValue::generate(Context *context)
{
    value = DOMValue::length_percentage(true);
    if (Random::gbool())
        value.append(" hanging");
    if (Random::gbool())
        value.append(" each-line");
}

// text-justify
void HIRMutate::CSS::TextJustifyValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "inter-character", "inter-word", "distribute"};
    value = CHOICE(strs);
}

// text-orientation
void HIRMutate::CSS::TextOrientationValue::generate(Context *context)
{
    static const char *strs[] = {"inherit", "initial", "mixed", "upright", "sideways", "sideways-right"};
    value = CHOICE(strs);
}

// text-overflow
void HIRMutate::CSS::TextOverflowValue::generate(Context *context)
{
    static const char *strs[] = {"clip", "ellipsis"};
    value = CHOICE(strs);
}

// text-rendering
void HIRMutate::CSS::TextRenderingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "optimizeSpeed", "optimizeLegibility", "geometricPrecision"};
    value = CHOICE(strs);
}

//text-shadow
void HIRMutate::CSS::TextShadowValue::generate(Context *context)
{
    if (Random::selector(10) == 0)
        value = "inherit";
    else
    {
        string selectors = Random::selectors(4);
        vector<string> values;
        if (selectors[0])
            values.push_back(DOMValue::color());
        if (selectors[1])
            values.push_back(DOMValue::length());
        if (selectors[2])
            values.push_back(DOMValue::length());
        if (selectors[3])
            values.push_back(DOMValue::length());
        value = cat(values);
    }
}

// text-transform
void HIRMutate::CSS::TextTransformValue::generate(Context *context)
{
    static const char *strs[] = {"none", "capitalize", "uppercase", "lowercase", "full-width", "full-size-kana"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::text_underline_position()
{
    static const char *strs[] = {"auto", "before-edge", "alphabetic", "after-edge"};
    return CHOICE(strs);
}

string HIRMutate::CSS::text_underline_mode()
{
    static const char *strs[] = {"continuous", "skip-white-space"};
    return CHOICE(strs);
}

string HIRMutate::CSS::text_underline_style()
{
    static const char *strs[] = {"solid", "double", "dotted", "dashed", "dot-dash", "dot-dot-dash", "wave"};
    return CHOICE(strs);
}

string HIRMutate::CSS::text_underline_width()
{
    int c = Random::selector(6);
    if (c == 0)
        return "auto";
    else if (c == 1)
        return "normal";
    else if (c == 2)
        return Random::number();
    else if (c == 3)
        return DOMValue::length();
    else if (c == 4)
        return DOMValue::percentage();
    else
    {
        static const char *strs[] = {"thin", "medium", "thick"};
        return CHOICE(strs);
    }
}

// text-underline
void HIRMutate::CSS::TextUnderlineValue::generate(Context *context)
{
    string selectors = Random::selectors(4);
    vector<string> values;
    if (selectors[0])
        values.push_back(text_underline_style());
    if (selectors[1])
        values.push_back(DOMValue::color());
    if (selectors[2])
        values.push_back(text_underline_mode());
    if (selectors[3])
        values.push_back(text_underline_position());
    value = cat(values);
}

// text-underline-mode
void HIRMutate::CSS::TextUnderlineModeValue::generate(Context *context)
{
    value = text_underline_mode();
}

// text-underline-style
void HIRMutate::CSS::TextUnderlineStyleValue::generate(Context *context)
{
    value = text_underline_style();
}

// text-underline-width
void HIRMutate::CSS::TextUnderlineWidthValue::generate(Context *context)
{
    value = text_underline_width();
}

// text-underline-offset
void HIRMutate::CSS::TextUnderlineOffsetValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::length();
}

// text-underline-position
void HIRMutate::CSS::TextUnderlinePositionValue::generate(Context *context)
{
    value = text_underline_position();
}

// touch-action
void HIRMutate::CSS::TouchActionValue::generate(Context *context)
{
    if (Random::gbool())
    {
        string selectors = Random::selectors(3);
        vector<string> values;
        if (selectors[0])
        {
            static const char *strs[] = {"pan-x", "pan-left", "pan-right"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[1])
        {
            static const char *strs[] = {"pan-y", "pan-up", "pan-down"};
            values.push_back(CHOICE(strs));
        }
        if (selectors[2])
            values.push_back("pinch-zoom");
        value = cat(values);
    }
    else
    {
        static const char *strs[] = {"auto", "manipulation"};
        value = CHOICE(strs);
    }
}

string HIRMutate::CSS::css_transform()
{
    int c = Random::selector(21);
    if (c == 0)
        return DOMValue::matrix();
    else if (c == 1)
        return DOMValue::translate();
    else if (c == 2)
        return DOMValue::translate_x();
    else if (c == 3)
        return DOMValue::translate_y();
    else if (c == 4)
        return DOMValue::scale();
    else if (c == 5)
        return DOMValue::scale_x();
    else if (c == 6)
        return DOMValue::scale_y();
    else if (c == 7)
        return DOMValue::rotate();
    else if (c == 8)
        return DOMValue::skew();
    else if (c == 9)
        return DOMValue::skew_x();
    else if (c == 10)
        return DOMValue::skew_y();
    else if (c == 11)
        return DOMValue::matrix3d();
    else if (c == 12)
        return DOMValue::translate3d();
    else if (c == 13)
        return DOMValue::translate_z();
    else if (c == 14)
        return DOMValue::scale3d();
    else if (c == 15)
        return DOMValue::scale_z();
    else if (c == 16)
        return DOMValue::rotate3d();
    else if (c == 17)
        return DOMValue::rotate_x();
    else if (c == 18)
        return DOMValue::rotate_y();
    else if (c == 19)
        return DOMValue::rotate_z();
    else
        return DOMValue::perspective();
}
// transform
void HIRMutate::CSS::TransformValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = css_transform();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(css_transform());
    }
}

// transform-origin
void HIRMutate::CSS::TransformOriginValue::generate(Context *context)
{
    if (Random::gbool())
    {
        if (Random::gbool())
        {
            static const char *strs[] = {"left", "center", "right", "top", "bottom"};
            value = CHOICE(strs);
        }
        else
            value = DOMValue::length_percentage();
    }
    else
    {
        vector<string> values;
        if (Random::gbool())
        {
            static const char *strs[] = {"left", "center", "right"};
            values.push_back(CHOICE(strs));
        }
        else
            values.push_back(DOMValue::length_percentage());
        if (Random::gbool())
        {
            static const char *strs[] = {"top", "center", "bottom"};
            values.push_back(CHOICE(strs));
        }
        else
            values.push_back(DOMValue::length_percentage());
        if (Random::gbool())
            values.push_back(DOMValue::length());
        value = cat(values);
    }
}

// transform-style
void HIRMutate::CSS::TransformStyleValue::generate(Context *context)
{
    static const char *strs[] = {"flat", "preserve-3d"};
    value = CHOICE(strs);
}

string HIRMutate::CSS::transition_property()
{
    if (Random::gbool())
        return "all";
    else
        return CHOICE_OBJ(DOC::css_animatable_properties);
}

string HIRMutate::CSS::transition()
{
    string selectors = Random::selectors(3);
    string value = transition_property();
    if (selectors[0])
    {
        value.append(" ");
        value.append(DOMValue::clock());
    }
    if (selectors[1])
    {
        value.append(" ");
        value.append(animation_timing_function());
    }
    if (selectors[2])
    {
        value.append(" ");
        value.append(DOMValue::clock());
    }
    return value;
}

// transition
void HIRMutate::CSS::TransitionValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = transition();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(",");
        value.append(transition());
    }
}
// transition-property
void HIRMutate::CSS::TransitionPropertyValue::generate(Context *context)
{
    value = transition_property();
}

// transition-timing-function
void HIRMutate::CSS::TransitionTimingFunctionValue::generate(Context *context)
{
    value = animation_timing_function();
}

// translate
void HIRMutate::CSS::TranslateValue::generate(Context *context)
{
    string selectors = Random::selectors(2);
    vector<string> values;
    if (selectors[0])
        values.push_back(DOMValue::length_percentage());
    if (selectors[1])
    {
        values.push_back(DOMValue::length_percentage());
        if (Random::gbool())
            values.push_back(DOMValue::length());
    }
    value = cat(values);
}

// unicode-bidi
void HIRMutate::CSS::UnicodeBidiValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "embed", "isolate", "bidi-override", "isolate-override", "plaintext"};
    value = CHOICE(strs);
}

// user-select
void HIRMutate::CSS::UserSelectValue::generate(Context *context)
{
    static const char *strs[] = {"all", "element", "elements", "text", "toggle"};
    value = CHOICE(strs);
}

// user-zoom
void HIRMutate::CSS::UserZoomValue::generate(Context *context)
{
    static const char *strs[] = {"zoom", "fixed"};
    value = CHOICE(strs);
}

// vertical-align
void HIRMutate::CSS::VerticalAlignValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"baseline", "sub", "super", "text-top", "text-bottom", "middle", "top",
                                     "bottom"};
        value = CHOICE(strs);
    }
    else
        value = DOMValue::length_percentage(true);
}

// visibility
void HIRMutate::CSS::VisibilityValue::generate(Context *context)
{
    static const char *strs[] = {"visible", "hidden", "collapse"};
    value = CHOICE(strs);
}

// white-space
void HIRMutate::CSS::WhiteSpaceValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "pre", "nowrap", "pre-wrap", "pre-line"};
    value = CHOICE(strs);
}

// will-change
void HIRMutate::CSS::WillChangeValue::generate(Context *context)
{
    if (Random::selector(10) == 0)
        value = "auto";
    else
    {
        int num = Random::range(1, 2);
        static const char *strs[] = {"scroll-position", "contents"};
        for (int i = 0; i < num; i++)
        {
            if (Random::gbool())
                value.append(CHOICE(strs));
            else
                value.append(CHOICE_OBJ(DOC::css_animatable_properties));
            if (i != num - 1)
            {
                value.append(",");
            }
        }
    }
}

// word-break
void HIRMutate::CSS::WordBreakValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "break-all", "keep-all", "break-word"};
    value = CHOICE(strs);
}
//word-spacing
void HIRMutate::CSS::WordSpacingValue::generate(Context *context)
{
    if (Random::gbool())
        value = "normal";
    else
        value = DOMValue::length_percentage();
}

// writing-mode
void HIRMutate::CSS::WritingModeValue::generate(Context *context)
{
    static const char *strs[] = {"horizontal-tb", "vertical-rl", "vertical-lr", "sideways-rl", "sideways-lr", "lr", "lr-tb", "rl", "tb",
                                 "tb-rl"};
    value = CHOICE(strs);
}

// z-index
void HIRMutate::CSS::ZIndexValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = Random::integer();
}

// zoom
void HIRMutate::CSS::ZoomValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "normal";
    else if (c == 1)
        value = "reset";
    else
        value = DOMValue::number_percentage();
}

// -webkit-text-decorations-in-effect
void HIRMutate::CSS::WebkitTextDecorationInEffectValue::generate(Context *context)
{
    value = "underline";
}

//caret-color
void HIRMutate::CSS::CaretColorValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::color();
}

// font-variation-settings
void HIRMutate::CSS::FontVariationSettingsValue::generate(Context *context)
{
    if (Random::gbool())
        value = "normal";
    else
    {
        static const char *strs[] = {"XHGT", "wght", "wdth", "slnt", "ital", "opsz"};
        value = CHOICE(strs);
        value.append(" ");
        value.append(Random::number());
    }
}

// inset
void HIRMutate::CSS::InsetValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = location();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(location());
    }
}

// inset-block
void HIRMutate::CSS::InsetBlockValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = location();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(location());
    }
}

// inset-inline
void HIRMutate::CSS::InsetInlineValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = location();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(location());
    }
}

// mask-border (border-image)
string HIRMutate::CSS::MaskBorderValue::mask_border_mode()
{
    static const char *strs[] = {"luminance", "alpha"};
    return CHOICE(strs);
}

void HIRMutate::CSS::MaskBorderValue::generate(Context *context)
{
    string selectors = Random::selectors(5);
    vector<string> values;
    if (selectors[0])
        values.push_back(image());
    if (selectors[1])
        values.push_back(border_image_slice());
    if (selectors[2])
    {
        values.push_back("/");
        values.push_back(border_image_width());
        if (Random::gbool())
        {
            values.push_back("/");
            values.push_back(border_image_outset());
        }
    }
    if (selectors[3])
        values.push_back(border_image_repeat());
    if (selectors[4])
        values.push_back(MaskBorderValue::mask_border_mode());
    value = cat(values);
}
void HIRMutate::CSS::MaskBorderModeValue::generate(Context *context)
{
    value = MaskBorderValue::mask_border_mode();
}

// scroll-margin
void HIRMutate::CSS::ScrollMarginValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
}

// scroll-margin-block
void HIRMutate::CSS::ScrollMarginBlockValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
}

// scroll-margin-inline
void HIRMutate::CSS::ScrollMarginInlineValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
}

string HIRMutate::CSS::single_scroll_padding()
{
    if (Random::gbool())
        return "auto";
    else
        return DOMValue::length_percentage();
}

// scroll-padding
void HIRMutate::CSS::ScrollPaddingValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = single_scroll_padding();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(single_scroll_padding());
    }
}

// scroll-padding-block
void HIRMutate::CSS::ScrollPaddingBlockValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = single_scroll_padding();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(single_scroll_padding());
    }
}

// scroll-padding-block-start/end
// scroll-padding-inline-start/end
// scroll-padding-bottom/top/left/right
void HIRMutate::CSS::ScrollPaddingLineValue::generate(Context *context)
{
    value = single_scroll_padding();
}

// scroll-padding-inline
void HIRMutate::CSS::ScrollPaddingInlineValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = single_scroll_padding();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(single_scroll_padding());
    }
}

// scrollbar-color
void HIRMutate::CSS::ScrollbarColorValue::generate(Context *context)
{
    if (Random::gbool())
    {
        static const char *strs[] = {"auto", "dark", "light"};
        value = CHOICE(strs);
    }
    else
    {
        value = DOMValue::color();
        value.append(" ");
        value.append(DOMValue::color());
    }
}

// animation: https://developer.mozilla.org/en-US/docs/Web/CSS/animation
void HIRMutate::CSS::AnimationValue::generate(Context *context)
{
    vector<string> values;
    values.push_back(animation_name(context));
    string c = Random::selectors(7);
    if (c[0])
        values.push_back(animation_duration());
    if (c[1])
        values.push_back(animation_timing_function());
    if (c[2])
        values.push_back(animation_delay());
    if (c[3])
        values.push_back(animation_iteration_count());
    if (c[4])
        values.push_back(animation_direction());
    if (c[5])
        values.push_back(animation_fill_mode());
    if (c[6])
        values.push_back(DOMValue::play_state());
    value = cat(values);
}

// animation-name
void HIRMutate::CSS::AnimationNameValue::generate(Context *context)
{
    value = animation_name(context);
}

//counter - increment
void HIRMutate::CSS::CounterIncrementValue::generate(Context *context)
{
    value = ((DOMContext *)context)->get_token("counter");
    if (Random::gbool())
        value += " " + Random::integer();
}

void HIRMutate::CSS::CursorValue::generate(Context *context)
{
    if (Random::gbool())
        value = cursor_fallback();
    else
    {
        value = "url(";
        value.append(DOMValue::image_url());
        value.append(")");
    }
}

/*
    * Dynamic CSS values
    */
HIRMutate::CSS::ClipPathValue::ClipPathValue()
{
    clip_path = nullptr;
}
void HIRMutate::CSS::ClipPathValue::generate_dynamic(Context *context)
{
    value = "";
    clip_path = context->get_object("SVGClipPathElement");
    if (clip_path == nullptr)
        generate_static();
}

void HIRMutate::CSS::ClipPathValue::generate_static()
{
    if (clip_path)
    {
        clip_path = nullptr;
    }
    value = basic_shape();
    if (Random::gbool())
        value += " " + geometry_box();
}

void HIRMutate::CSS::ClipPathValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::CSS::ClipPathValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (clip_path != nullptr)
    {
        if (merge_map.find(clip_path) != merge_map.end())
            clip_path = merge_map[clip_path];
    }
}

string HIRMutate::CSS::ClipPathValue::getValue()
{
    if (clip_path != nullptr)
    {
        string ans = "url(#";
        ans.append(clip_path->id);
        ans.append(")");
        return ans;
    }
    else
        return value;
}
HIRMutate::CSS::OffsetValue::OffsetValue()
{
    path = nullptr;
}
void HIRMutate::CSS::OffsetValue::generate_static_path()
{
    if (path)
    {
        path = nullptr;
    }
    int c = Random::selector(3);
    if (c == 0)
    {
        string s = DOMValue::angle();
        if (Random::gbool())
            s += " " + radial_gradient_size();
        if (Random::gbool())
            s += " contain";

        path_value = "ray(";
        path_value.append(s);
        path_value.append(")");
    }
    else if (c == 1)
    {
        path_value = "path('";
        path_value.append(DOMValue::path());
        path_value.append("')");
    }
    else
    {
        path_value = basic_shape();
        if (Random::gbool())
            path_value += " " + geometry_box();
    }
}

void HIRMutate::CSS::OffsetValue::generate_dynamic_path(Context *context)
{
    path_value = "";
    path = context->get_object(DOC::svg_shape_elements);
    if (path == nullptr)
        generate_static_path();
}
void HIRMutate::CSS::OffsetValue::generate_path(Context *context)
{
    if (Random::gbool())
        generate_static_path();
    else
        generate_dynamic_path(context);
}

void HIRMutate::CSS::OffsetValue::generate_position()
{
    if (Random::gbool())
        position = DOMValue::position();
    else
        position = "";
}

void HIRMutate::CSS::OffsetValue::generate_distance()
{
    if (Random::gbool())
        distance = DOMValue::length_percentage();
    else
        distance = "";
}

void HIRMutate::CSS::OffsetValue::generate_rotate()
{
    if (Random::gbool())
        rotate = offset_rotate();
    else
        rotate = "";
}

string HIRMutate::CSS::OffsetValue::generate_anchor()
{
    if (Random::gbool())
        anchor = offset_anchor();
    else
        anchor = "";
}

void HIRMutate::CSS::OffsetValue::generate(Context *context)
{
    generate_position();
    generate_path(context);
    if (Random::gbool())
    {
        generate_distance();
        generate_rotate();
    }
    generate_anchor();
}

bool HIRMutate::CSS::OffsetValue::mutate(Context *context)
{
    int c = Random::selector(5);
    if (c == 0)
        generate_position();
    else if (c == 1)
        generate_path(context);
    else if (c == 2)
        generate_distance();
    else if (c == 3)
        generate_rotate();
    else
        generate_anchor();
    return true;
}

void HIRMutate::CSS::OffsetValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (path != nullptr)
    {
        if (merge_map.find(path) != merge_map.end())
            path = merge_map[path];
    }
}

string HIRMutate::CSS::OffsetValue::getValue()
{
    vector<string> values;
    if (position != "")
        values.push_back(position);
    if (path != nullptr)
    {
        string ans = "url(#";
        ans.append(path->id);
        ans.append(")");
        values.push_back(ans);
    }
    else
        values.push_back(path_value);
    if (distance != "")
        values.push_back(distance);
    if (rotate != "")
        values.push_back(rotate);
    if (anchor != "")
    {
        values.push_back("/");
        values.push_back(anchor);
    }
    return cat(values);
}

// offset-path
void HIRMutate::CSS::OffsetPathValue::generate_static()
{
    path = nullptr;
    int c = Random::selector(3);
    string s = "";
    if (c == 0)
    {
        s = DOMValue::angle();
        if (Random::gbool())
            s += " " + radial_gradient_size();
        if (Random::gbool())
            s += " contain";
        value = "ray(";
        value.append(s);
        value.append(")");
    }
    else if (c == 1)
    {
        value = "path('";
        value.append(DOMValue::path());
        value.append("')");
    }
    else
    {
        value = basic_shape();
        if (Random::gbool())
            value += " " + geometry_box();
    }
}
HIRMutate::CSS::OffsetPathValue::OffsetPathValue()
{
    path = nullptr;
}
void HIRMutate::CSS::OffsetPathValue::generate_dynamic(Context *context)
{
    value = "";
    path = context->get_object(DOC::svg_shape_elements);
    if (path == nullptr)
        generate_static();
}

void HIRMutate::CSS::OffsetPathValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::CSS::OffsetPathValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (path != nullptr)
    {
        if (merge_map.find(path) != merge_map.end())
            path = merge_map[path];
    }
}

string HIRMutate::CSS::OffsetPathValue::getValue()
{
    if (path)
    {
        string ans = "url(";
        ans.append(path->id);
        ans.append(")");
        return ans;
    }
    return value;
}

// filter

HIRMutate::CSS::FilterValue::FilterValue()
{
    filter = nullptr;
}
void HIRMutate::CSS::FilterValue::generate_static()
{
    filter = nullptr;
    int num = Random::range(1, 2);
    filter_value = filter_function();
    for (int i = 0; i < num - 1; i++)
    {
        filter_value.append(" ");
        filter_value.append(filter_function());
    }
}

void HIRMutate::CSS::FilterValue::generate_dynamic(Context *context)
{
    filter_value = "";
    filter = context->get_object("SVGFilterElement");
    if (filter == nullptr)
        generate_static();
}

void HIRMutate::CSS::FilterValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::CSS::FilterValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (filter != nullptr)
    {
        if (merge_map.find(filter) != merge_map.end())
            filter = merge_map[filter];
    }
}

string HIRMutate::CSS::FilterValue::getValue()
{
    if (filter)
    {
        string ans = "url(#";
        ans.append(filter->id);
        ans.append(")");
        return ans;
    }
    else
        return filter_value;
}

HIRMutate::CSS::MaskValue::MaskValue()
{
    mask = nullptr;
}
void HIRMutate::CSS::MaskValue::generate_mask_static()
{
    mask = nullptr;
    image_value = image();
}

void HIRMutate::CSS::MaskValue::generate_mask_dynamic(Context *context)
{
    image_value = "";
    mask = context->get_object("SVGMaskElement");
    if (mask == nullptr)
        generate_mask_static();
}

void HIRMutate::CSS::MaskValue::generate_mask(Context *context)
{
    if (Random::gbool())
        generate_mask_static();
    else
        generate_mask_dynamic(context);
}

void HIRMutate::CSS::MaskValue::generate_position()
{
    if (Random::gbool())
        position = "";
    else
    {
        position = DOMValue::position();
        if (Random::gbool())
            position += " / " + background_size();
    }
}

void HIRMutate::CSS::MaskValue::generate_repeat()
{
    if (Random::gbool())
        repeat = mask_repeat_style();
    else
        repeat = "";
}

void HIRMutate::CSS::MaskValue::generate_origin()
{
    if (Random::gbool())
        origin = geometry_box();
    else
        origin = "";
}

void HIRMutate::CSS::MaskValue::generate_clip()
{
    if (Random::gbool())
        clip = mask_clip();
    else
        clip = "";
}

void HIRMutate::CSS::MaskValue::generate_composite()
{
    if (Random::gbool())
        composite = mask_composite();
    else
        composite = "";
}

void HIRMutate::CSS::MaskValue::generate_mode()
{
    if (Random::gbool())
        mode = mask_mode();
    else
        mode = "";
}

void HIRMutate::CSS::MaskValue::generate(Context *context)
{
    generate_mask(context);
    generate_position();
    generate_repeat();
    generate_origin();
    generate_clip();
    generate_composite();
    generate_mode();
}

bool HIRMutate::CSS::MaskValue::mutate(Context *context)
{
    int c = Random::selector(7);
    if (c == 0)
        generate_mask(context);
    else if (c == 1)
        generate_position();
    else if (c == 2)
        generate_repeat();
    else if (c == 3)
        generate_origin();
    else if (c == 4)
        generate_clip();
    else if (c == 5)
        generate_composite();
    else
        generate_mode();
    return true;
}

void HIRMutate::CSS::MaskValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (mask)
    {
        if (merge_map.find(mask) != merge_map.end())
            mask = merge_map[mask];
    }
}

string HIRMutate::CSS::MaskValue::getValue()
{
    vector<string> values;
    if (mask)
    {
        string ans = "url(#";
        ans.append(mask->id);
        ans.append(")");
        values.push_back(ans);
    }
    else
        values.push_back(image_value);
    if (position != "")
        values.push_back(position);
    if (repeat != "")
        values.push_back(repeat);
    if (origin != "")
        values.push_back(origin);
    if (clip != "")
        values.push_back(clip);
    if (composite != "")
        values.push_back(composite);
    if (mode != "")
        values.push_back(mode);
    return cat(values);
}

// mask-image
HIRMutate::CSS::MaskImageValue::MaskImageValue()
{
    mask = nullptr;
}
void HIRMutate::CSS::MaskImageValue::generate_static()
{
    mask = nullptr;
    image_value = image();
}

void HIRMutate::CSS::MaskImageValue::generate_dynamic(Context *context)
{
    image_value = "";
    mask = context->get_object("SVGMaskElement");
    if (mask == nullptr)
        generate_static();
}

void HIRMutate::CSS::MaskImageValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::CSS::MaskImageValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (mask)
    {
        if (merge_map.find(mask) != merge_map.end())
            mask = merge_map[mask];
    }
}

string HIRMutate::CSS::MaskImageValue::getValue()
{
    if (mask)
    {
        string ans = "url(#";
        ans.append(mask->id);
        ans.append(")");
        return ans;
    }
    else
        return image_value;
}

//序列化
void HIRMutate::CSS::CSSColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CSSLineWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLineWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CSSLengthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLengthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CSSLengthPercentageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSSLengthPercentageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LineWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LineWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ImageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::RadiusValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RadiusValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LineStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LineStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LocationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LocationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BottomValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BottomValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OpacityValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OpacityValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitAppRegionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitAppRegionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AppearanceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AppearanceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitColorCorrectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitColorCorrectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitFlowFromValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitFlowFromValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitFlowIntoValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitFlowIntoValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitFontSmoothingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitFontSmoothingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitHyphenateCharacterValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitHyphenateCharacterValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitMarginAfterCollapseValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitMarginAfterCollapseValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitMarginCollapseValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitMarginCollapseValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitMarqueeSpeedValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitMarqueeSpeedValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitMaskBoxImageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitMaskBoxImageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskClipValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskClipValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskCompositeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskCompositeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskOriginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskOriginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskPositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskPositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskRepeatValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskRepeatValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskSourceTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskSourceTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitMaskRepeatXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitMaskRepeatXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskSizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskSizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitNbspModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitNbspModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitOverflowScrollingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitOverflowScrollingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitPrintColorAdjustValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitPrintColorAdjustValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitRtlOrderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitRtlOrderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitRubyPositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitRubyPositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextCombineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextCombineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextEmphasisValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextEmphasisValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextEmphasisPositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextEmphasisPositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextEmphasisStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextEmphasisStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextSecurityValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextSecurityValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextStrokeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextStrokeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextStrokeColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextStrokeColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextStrokeWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextStrokeWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitUserDragValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitUserDragValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitUserModifyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitUserModifyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitWrapFlowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitWrapFlowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AlignContentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AlignContentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AlignItemsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AlignItemsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AlignSelfValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AlignSelfValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AllValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AllValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationDelayValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationDelayValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationDirectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationDirectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationDurationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationDurationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationFillModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationFillModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationIterationCountValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationIterationCountValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationPlayStateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationPlayStateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationTimingFunctionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationTimingFunctionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackfaceVisibilityValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackfaceVisibilityValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundAttachmentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundAttachmentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BlendModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BlendModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundBlendModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundBlendModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundClipValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundClipValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundOriginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundOriginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundPositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundPositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundPositionXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundPositionXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundPositionYValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundPositionYValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundRepeatValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundRepeatValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundRepeatXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundRepeatXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BackgroundSizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BackgroundSizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderCollapseValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderCollapseValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderImageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderImageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderImageOutsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderImageOutsetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderImageRepeatValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderImageRepeatValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderImageSliceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderImageSliceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderImageWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderImageWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderRadiusValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderRadiusValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderSpacingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderSpacingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BorderWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BorderWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxDecorationBreakValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxDecorationBreakValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxDirectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxDirectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxLinesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxLinesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxOrientValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxOrientValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxPackValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxPackValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxReflectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxReflectValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxShadowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxShadowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BoxSizingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BoxSizingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BreakValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BreakValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::BreakInsideValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BreakInsideValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CaptionSideValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CaptionSideValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ClearValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::ClearValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ClipValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClipValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnBreakAfterValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnBreakAfterValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnCountValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnCountValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnFillValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnFillValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnGapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnGapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnSpanValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnSpanValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ColumnsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColumnsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ContainValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ContainValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ContentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ContentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::DirectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DirectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::DisplayValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DisplayValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::EmptyCellsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("EmptyCellsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FlexValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FlexValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FlexBasisValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FlexBasisValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FlexDirectionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FlexDirectionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FlexFlowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FlexFlowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FlexWrapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FlexWrapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FloatValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FloatValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontFamilyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontFamilyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontFeatureSettingsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontFeatureSettingsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontSmoothValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontSmoothValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontKerningValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontKerningValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontSizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontSizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontSizeAdjustValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontSizeAdjustValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontStretchValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontStretchValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontVariantValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontVariantValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontVariantCapsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontVariantCapsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontVariantLigaturesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontVariantLigaturesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontWeightValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontWeightValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridAreaValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridAreaValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridAutoRowsColumnsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridAutoRowsColumnsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridAutoFlowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridAutoFlowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridRowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridRowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridLineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridLineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridLineGapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridLineGapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridGapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridGapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridTemplateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridTemplateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridTemplateAreasValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridTemplateAreasValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::GridTemplateRowsColumnsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GridTemplateRowsColumnsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::HeightValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HeightValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::HyphensValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HyphensValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ImageOrientationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageOrientationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ImageRenderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageRenderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::IsolationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("IsolationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::JustifyContentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("JustifyContentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::JustifyItemsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("JustifyItemsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::JustifySelfValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("JustifySelfValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::KerningValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::KerningValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LetterSpacingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LetterSpacingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LineBreakValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LineBreakValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebKitLocaleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebKitLocaleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::LineHeightValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LineHeightValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ListStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ListStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ListStyleImageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ListStyleImageValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ListStylePositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ListStylePositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ListStyleTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ListStyleTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MarginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaxZoomValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaxZoomValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ObjectFitValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ObjectFitValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OffsetAnchorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OffsetAnchorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OffsetPositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OffsetPositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OffsetRotateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OffsetRotateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OutlineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OutlineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OutlineColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OutlineColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OutlineStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OutlineStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OverflowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::OverflowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OverflowAnchorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OverflowAnchorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OverflowWrapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OverflowWrapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::OverflowXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OverflowXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PaddingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PaddingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PerspectiveValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PerspectiveValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PerspectiveOriginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PerspectiveOriginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PointerEventsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::PointerEventsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PositionWayValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PositionWayValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::PrinceHyphensValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PrinceHyphensValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::QuotesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("QuotesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ResizeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ResizeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::RotateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::RotateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScaleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScaleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollBehaviorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollBehaviorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollSnapCoordinateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollSnapCoordinateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollSnapPointsXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollSnapPointsXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollSnapTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollSnapTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ShapeImageThresholdValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ShapeImageThresholdValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ShapeOutsideValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ShapeOutsideValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TableLayoutValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableLayoutValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextAlignLastValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextAlignLastValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextCombineUprightValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextCombineUprightValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextDecorationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextDecorationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextDecorationLineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextDecorationLineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextDecorationSkipValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextDecorationSkipValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextDecorationStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextDecorationStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextDecorationThicknessValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextDecorationThicknessValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextIndentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextIndentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextJustifyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextJustifyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextOrientationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextOrientationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextOverflowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::TextOverflowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextRenderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextRenderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextShadowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextShadowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextTransformValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextTransformValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlineModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlineModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlineStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlineStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlineWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlineWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlineOffsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlineOffsetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TextUnderlinePositionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextUnderlinePositionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TouchActionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TouchActionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransformValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::TransformValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransformOriginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformOriginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransformStyleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformStyleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransitionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransitionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransitionPropertyValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransitionPropertyValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TransitionTimingFunctionValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransitionTimingFunctionValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::TranslateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TranslateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::UnicodeBidiValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UnicodeBidiValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::UserSelectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UserSelectValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::UserZoomValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UserZoomValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::VerticalAlignValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VerticalAlignValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::VisibilityValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VisibilityValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WhiteSpaceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::WhiteSpaceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WillChangeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WillChangeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WordBreakValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WordBreakValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WordSpacingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::WordSpacingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WritingModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WritingModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ZIndexValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ZIndexValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ZoomValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ZoomValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::WebkitTextDecorationInEffectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("WebkitTextDecorationInEffectValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CaretColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CaretColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::FontVariationSettingsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontVariationSettingsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::InsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InsetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::InsetBlockValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InsetBlockValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::InsetInlineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InsetInlineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskBorderValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskBorderValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::MaskBorderModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskBorderModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollMarginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollMarginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollMarginBlockValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollMarginBlockValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollMarginInlineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollMarginInlineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollPaddingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollPaddingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollPaddingBlockValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollPaddingBlockValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollPaddingLineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollPaddingLineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollPaddingInlineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollPaddingInlineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ScrollbarColorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ScrollbarColorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::AnimationNameValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationNameValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CounterIncrementValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CounterIncrementValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::CursorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CursorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::CSS::ClipPathValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClipPathValue");
    DynamicValue::serialize(stream, context);
    if (clip_path)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        clip_path->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
}
void HIRMutate::CSS::ClipPathValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        clip_path = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&clip_path, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&clip_path, function);
    }
}
void HIRMutate::CSS::OffsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CSS::OffsetValue");
    DynamicValue::serialize(stream, context);

    if (path)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        path->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
    stream->write_string(path_value);
    stream->write_string(position);
    stream->write_string(distance);
    stream->write_string(rotate);
    stream->write_string(anchor);
}
void HIRMutate::CSS::OffsetValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        path = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&path, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&path, function);
    }
    path_value = stream->read_string();
    position = stream->read_string();
    distance = stream->read_string();
    rotate = stream->read_string();
    anchor = stream->read_string();
}
void HIRMutate::CSS::OffsetPathValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OffsetPathValue");
    DynamicValue::serialize(stream, context);
    if (path)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        path->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
}
void HIRMutate::CSS::OffsetPathValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        path = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&path, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&path, function);
    }
}
void HIRMutate::CSS::FilterValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FilterValue");
    DynamicValue::serialize(stream, context);
    if (filter)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        filter->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
    stream->write_string(filter_value);
}
void HIRMutate::CSS::FilterValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        filter = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&filter, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&filter, function);
    }
    filter_value = stream->read_string();
}
void HIRMutate::CSS::MaskValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskValue");
    DynamicValue::serialize(stream, context);
    if (mask)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        mask->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
    stream->write_string(image_value);
    stream->write_string(position);
    stream->write_string(repeat);
    stream->write_string(origin);
    stream->write_string(clip);
    stream->write_string(composite);
    stream->write_string(mode);
}
void HIRMutate::CSS::MaskValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        mask = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&mask, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&mask, function);
    }
    image_value = stream->read_string();
    position = stream->read_string();
    repeat = stream->read_string();
    origin = stream->read_string();
    clip = stream->read_string();
    composite = stream->read_string();
    mode = stream->read_string();
}
void HIRMutate::CSS::MaskImageValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MaskImageValue");
    DynamicValue::serialize(stream, context);
    if (mask)
    {
        DOMContext *ctx = dynamic_cast<DOMContext *>(context);
        if (ctx != nullptr)
        {
            stream->write_string("from DOMContext");
        }
        else
        {
            stream->write_string("from JSContext");
        }
        mask->serialize_weak(stream, context);
    }
    else
        stream->write_string("nullptr");
    stream->write_string(image_value);
}
void HIRMutate::CSS::MaskImageValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        mask = nullptr;
        stream->skip_string();
    }
    else
    {
        if (stream->read_string() == "from DOMContext")
            stream->read_obj_ref((size_t)&mask, global_document);
        else
            stream->read_obj_ref_in_js_context((size_t)&mask, function);
    }
    image_value = stream->read_string();
}

void *HIRMutate::CSS::CSSColorValue::getConstructor()
{
    return HANDLE_VOID(CSSColorValue);
}
void *HIRMutate::CSS::CSSLineWidthValue::getConstructor()
{
    return HANDLE_VOID(CSSLineWidthValue);
}
void *HIRMutate::CSS::CSSLengthValue::getConstructor()
{
    return HANDLE_VOID(CSSLengthValue);
}
void *HIRMutate::CSS::CSSLengthPercentageValue::getConstructor()
{
    return HANDLE_VOID(CSSLengthPercentageValue);
}
void *HIRMutate::CSS::ColorValue::getConstructor()
{
    return HANDLE_VOID(ColorValue);
}
void *HIRMutate::CSS::LineWidthValue::getConstructor()
{
    return HANDLE_VOID(LineWidthValue);
}
void *HIRMutate::CSS::ImageValue::getConstructor()
{
    return HANDLE_VOID(ImageValue);
}
void *HIRMutate::CSS::RadiusValue::getConstructor()
{
    return HANDLE_VOID(RadiusValue);
}
void *HIRMutate::CSS::LineStyleValue::getConstructor()
{
    return HANDLE_VOID(LineStyleValue);
}
void *HIRMutate::CSS::LocationValue::getConstructor()
{
    return HANDLE_VOID(LocationValue);
}
void *HIRMutate::CSS::BottomValue::getConstructor()
{
    return HANDLE_VOID(BottomValue);
}
void *HIRMutate::CSS::OpacityValue::getConstructor()
{
    return HANDLE_VOID(OpacityValue);
}
void *HIRMutate::CSS::WebkitAppRegionValue::getConstructor()
{
    return HANDLE_VOID(WebkitAppRegionValue);
}
void *HIRMutate::CSS::AppearanceValue::getConstructor()
{
    return HANDLE_VOID(AppearanceValue);
}
void *HIRMutate::CSS::WebkitColorCorrectionValue::getConstructor()
{
    return HANDLE_VOID(WebkitColorCorrectionValue);
}
void *HIRMutate::CSS::WebkitFlowFromValue::getConstructor()
{
    return HANDLE_VOID(WebkitFlowFromValue);
}
void *HIRMutate::CSS::WebkitFlowIntoValue::getConstructor()
{
    return HANDLE_VOID(WebkitFlowIntoValue);
}
void *HIRMutate::CSS::WebkitFontSmoothingValue::getConstructor()
{
    return HANDLE_VOID(WebkitFontSmoothingValue);
}
void *HIRMutate::CSS::WebkitHyphenateCharacterValue::getConstructor()
{
    return HANDLE_VOID(WebkitHyphenateCharacterValue);
}
void *HIRMutate::CSS::WebkitMarginAfterCollapseValue::getConstructor()
{
    return HANDLE_VOID(WebkitMarginAfterCollapseValue);
}
void *HIRMutate::CSS::WebkitMarginCollapseValue::getConstructor()
{
    return HANDLE_VOID(WebkitMarginCollapseValue);
}
void *HIRMutate::CSS::WebkitMarqueeSpeedValue::getConstructor()
{
    return HANDLE_VOID(WebkitMarqueeSpeedValue);
}
void *HIRMutate::CSS::WebkitMaskBoxImageValue::getConstructor()
{
    return HANDLE_VOID(WebkitMaskBoxImageValue);
}
void *HIRMutate::CSS::MaskClipValue::getConstructor()
{
    return HANDLE_VOID(MaskClipValue);
}
void *HIRMutate::CSS::MaskCompositeValue::getConstructor()
{
    return HANDLE_VOID(MaskCompositeValue);
}
void *HIRMutate::CSS::MaskOriginValue::getConstructor()
{
    return HANDLE_VOID(MaskOriginValue);
}
void *HIRMutate::CSS::MaskPositionValue::getConstructor()
{
    return HANDLE_VOID(MaskPositionValue);
}
void *HIRMutate::CSS::MaskRepeatValue::getConstructor()
{
    return HANDLE_VOID(MaskRepeatValue);
}
void *HIRMutate::CSS::MaskSourceTypeValue::getConstructor()
{
    return HANDLE_VOID(MaskSourceTypeValue);
}
void *HIRMutate::CSS::WebkitMaskRepeatXValue::getConstructor()
{
    return HANDLE_VOID(WebkitMaskRepeatXValue);
}
void *HIRMutate::CSS::MaskSizeValue::getConstructor()
{
    return HANDLE_VOID(MaskSizeValue);
}
void *HIRMutate::CSS::WebkitNbspModeValue::getConstructor()
{
    return HANDLE_VOID(WebkitNbspModeValue);
}
void *HIRMutate::CSS::WebkitOverflowScrollingValue::getConstructor()
{
    return HANDLE_VOID(WebkitOverflowScrollingValue);
}
void *HIRMutate::CSS::WebkitPrintColorAdjustValue::getConstructor()
{
    return HANDLE_VOID(WebkitPrintColorAdjustValue);
}
void *HIRMutate::CSS::WebkitRtlOrderingValue::getConstructor()
{
    return HANDLE_VOID(WebkitRtlOrderingValue);
}
void *HIRMutate::CSS::WebkitRubyPositionValue::getConstructor()
{
    return HANDLE_VOID(WebkitRubyPositionValue);
}
void *HIRMutate::CSS::WebkitTextCombineValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextCombineValue);
}
void *HIRMutate::CSS::TextEmphasisValue::getConstructor()
{
    return HANDLE_VOID(TextEmphasisValue);
}
void *HIRMutate::CSS::TextEmphasisPositionValue::getConstructor()
{
    return HANDLE_VOID(TextEmphasisPositionValue);
}
void *HIRMutate::CSS::TextEmphasisStyleValue::getConstructor()
{
    return HANDLE_VOID(TextEmphasisStyleValue);
}
void *HIRMutate::CSS::WebkitTextSecurityValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextSecurityValue);
}
void *HIRMutate::CSS::WebkitTextStrokeValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextStrokeValue);
}
void *HIRMutate::CSS::WebkitTextStrokeColorValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextStrokeColorValue);
}
void *HIRMutate::CSS::WebkitTextStrokeWidthValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextStrokeWidthValue);
}
void *HIRMutate::CSS::WebkitUserDragValue::getConstructor()
{
    return HANDLE_VOID(WebkitUserDragValue);
}
void *HIRMutate::CSS::WebkitUserModifyValue::getConstructor()
{
    return HANDLE_VOID(WebkitUserModifyValue);
}
void *HIRMutate::CSS::WebkitWrapFlowValue::getConstructor()
{
    return HANDLE_VOID(WebkitWrapFlowValue);
}
void *HIRMutate::CSS::AlignContentValue::getConstructor()
{
    return HANDLE_VOID(AlignContentValue);
}
void *HIRMutate::CSS::AlignItemsValue::getConstructor()
{
    return HANDLE_VOID(AlignItemsValue);
}
void *HIRMutate::CSS::AlignSelfValue::getConstructor()
{
    return HANDLE_VOID(AlignSelfValue);
}
void *HIRMutate::CSS::AllValue::getConstructor()
{
    return HANDLE_VOID(AllValue);
}
void *HIRMutate::CSS::AnimationDelayValue::getConstructor()
{
    return HANDLE_VOID(AnimationDelayValue);
}
void *HIRMutate::CSS::AnimationDirectionValue::getConstructor()
{
    return HANDLE_VOID(AnimationDirectionValue);
}
void *HIRMutate::CSS::AnimationDurationValue::getConstructor()
{
    return HANDLE_VOID(AnimationDurationValue);
}
void *HIRMutate::CSS::AnimationFillModeValue::getConstructor()
{
    return HANDLE_VOID(AnimationFillModeValue);
}
void *HIRMutate::CSS::AnimationIterationCountValue::getConstructor()
{
    return HANDLE_VOID(AnimationIterationCountValue);
}
void *HIRMutate::CSS::AnimationPlayStateValue::getConstructor()
{
    return HANDLE_VOID(AnimationPlayStateValue);
}
void *HIRMutate::CSS::AnimationTimingFunctionValue::getConstructor()
{
    return HANDLE_VOID(AnimationTimingFunctionValue);
}
void *HIRMutate::CSS::BackfaceVisibilityValue::getConstructor()
{
    return HANDLE_VOID(BackfaceVisibilityValue);
}
void *HIRMutate::CSS::BackgroundValue::getConstructor()
{
    return HANDLE_VOID(BackgroundValue);
}
void *HIRMutate::CSS::BackgroundAttachmentValue::getConstructor()
{
    return HANDLE_VOID(BackgroundAttachmentValue);
}
void *HIRMutate::CSS::BlendModeValue::getConstructor()
{
    return HANDLE_VOID(BlendModeValue);
}
void *HIRMutate::CSS::BackgroundBlendModeValue::getConstructor()
{
    return HANDLE_VOID(BackgroundBlendModeValue);
}
void *HIRMutate::CSS::BackgroundClipValue::getConstructor()
{
    return HANDLE_VOID(BackgroundClipValue);
}
void *HIRMutate::CSS::BackgroundOriginValue::getConstructor()
{
    return HANDLE_VOID(BackgroundOriginValue);
}
void *HIRMutate::CSS::BackgroundPositionValue::getConstructor()
{
    return HANDLE_VOID(BackgroundPositionValue);
}
void *HIRMutate::CSS::BackgroundPositionXValue::getConstructor()
{
    return HANDLE_VOID(BackgroundPositionXValue);
}
void *HIRMutate::CSS::BackgroundPositionYValue::getConstructor()
{
    return HANDLE_VOID(BackgroundPositionYValue);
}
void *HIRMutate::CSS::BackgroundRepeatValue::getConstructor()
{
    return HANDLE_VOID(BackgroundRepeatValue);
}
void *HIRMutate::CSS::BackgroundRepeatXValue::getConstructor()
{
    return HANDLE_VOID(BackgroundRepeatXValue);
}
void *HIRMutate::CSS::BackgroundSizeValue::getConstructor()
{
    return HANDLE_VOID(BackgroundSizeValue);
}
void *HIRMutate::CSS::BorderValue::getConstructor()
{
    return HANDLE_VOID(BorderValue);
}
void *HIRMutate::CSS::LineValue::getConstructor()
{
    return HANDLE_VOID(LineValue);
}
void *HIRMutate::CSS::BorderCollapseValue::getConstructor()
{
    return HANDLE_VOID(BorderCollapseValue);
}
void *HIRMutate::CSS::BorderImageValue::getConstructor()
{
    return HANDLE_VOID(BorderImageValue);
}
void *HIRMutate::CSS::BorderImageOutsetValue::getConstructor()
{
    return HANDLE_VOID(BorderImageOutsetValue);
}
void *HIRMutate::CSS::BorderImageRepeatValue::getConstructor()
{
    return HANDLE_VOID(BorderImageRepeatValue);
}
void *HIRMutate::CSS::BorderImageSliceValue::getConstructor()
{
    return HANDLE_VOID(BorderImageSliceValue);
}
void *HIRMutate::CSS::BorderImageWidthValue::getConstructor()
{
    return HANDLE_VOID(BorderImageWidthValue);
}
void *HIRMutate::CSS::BorderRadiusValue::getConstructor()
{
    return HANDLE_VOID(BorderRadiusValue);
}
void *HIRMutate::CSS::BorderSpacingValue::getConstructor()
{
    return HANDLE_VOID(BorderSpacingValue);
}
void *HIRMutate::CSS::BorderStyleValue::getConstructor()
{
    return HANDLE_VOID(BorderStyleValue);
}
void *HIRMutate::CSS::BorderWidthValue::getConstructor()
{
    return HANDLE_VOID(BorderWidthValue);
}
void *HIRMutate::CSS::BoxAlignValue::getConstructor()
{
    return HANDLE_VOID(BoxAlignValue);
}
void *HIRMutate::CSS::BoxDecorationBreakValue::getConstructor()
{
    return HANDLE_VOID(BoxDecorationBreakValue);
}
void *HIRMutate::CSS::BoxDirectionValue::getConstructor()
{
    return HANDLE_VOID(BoxDirectionValue);
}
void *HIRMutate::CSS::BoxLinesValue::getConstructor()
{
    return HANDLE_VOID(BoxLinesValue);
}
void *HIRMutate::CSS::BoxOrientValue::getConstructor()
{
    return HANDLE_VOID(BoxOrientValue);
}
void *HIRMutate::CSS::BoxPackValue::getConstructor()
{
    return HANDLE_VOID(BoxPackValue);
}
void *HIRMutate::CSS::BoxReflectValue::getConstructor()
{
    return HANDLE_VOID(BoxReflectValue);
}
void *HIRMutate::CSS::BoxShadowValue::getConstructor()
{
    return HANDLE_VOID(BoxShadowValue);
}
void *HIRMutate::CSS::BoxSizingValue::getConstructor()
{
    return HANDLE_VOID(BoxSizingValue);
}
void *HIRMutate::CSS::PageValue::getConstructor()
{
    return HANDLE_VOID(PageValue);
}
void *HIRMutate::CSS::BreakValue::getConstructor()
{
    return HANDLE_VOID(BreakValue);
}
void *HIRMutate::CSS::BreakInsideValue::getConstructor()
{
    return HANDLE_VOID(BreakInsideValue);
}
void *HIRMutate::CSS::CaptionSideValue::getConstructor()
{
    return HANDLE_VOID(CaptionSideValue);
}
void *HIRMutate::CSS::ClearValue::getConstructor()
{
    return HANDLE_VOID(ClearValue);
}
void *HIRMutate::CSS::ClipValue::getConstructor()
{
    return HANDLE_VOID(ClipValue);
}
void *HIRMutate::CSS::ColumnBreakAfterValue::getConstructor()
{
    return HANDLE_VOID(ColumnBreakAfterValue);
}
void *HIRMutate::CSS::ColumnCountValue::getConstructor()
{
    return HANDLE_VOID(ColumnCountValue);
}
void *HIRMutate::CSS::ColumnFillValue::getConstructor()
{
    return HANDLE_VOID(ColumnFillValue);
}
void *HIRMutate::CSS::ColumnGapValue::getConstructor()
{
    return HANDLE_VOID(ColumnGapValue);
}
void *HIRMutate::CSS::ColumnSpanValue::getConstructor()
{
    return HANDLE_VOID(ColumnSpanValue);
}
void *HIRMutate::CSS::ColumnWidthValue::getConstructor()
{
    return HANDLE_VOID(ColumnWidthValue);
}
void *HIRMutate::CSS::ColumnsValue::getConstructor()
{
    return HANDLE_VOID(ColumnsValue);
}
void *HIRMutate::CSS::ContainValue::getConstructor()
{
    return HANDLE_VOID(ContainValue);
}
void *HIRMutate::CSS::ContentValue::getConstructor()
{
    return HANDLE_VOID(ContentValue);
}
void *HIRMutate::CSS::DirectionValue::getConstructor()
{
    return HANDLE_VOID(DirectionValue);
}
void *HIRMutate::CSS::DisplayValue::getConstructor()
{
    return HANDLE_VOID(DisplayValue);
}
void *HIRMutate::CSS::EmptyCellsValue::getConstructor()
{
    return HANDLE_VOID(EmptyCellsValue);
}
void *HIRMutate::CSS::FlexValue::getConstructor()
{
    return HANDLE_VOID(FlexValue);
}
void *HIRMutate::CSS::FlexBasisValue::getConstructor()
{
    return HANDLE_VOID(FlexBasisValue);
}
void *HIRMutate::CSS::FlexDirectionValue::getConstructor()
{
    return HANDLE_VOID(FlexDirectionValue);
}
void *HIRMutate::CSS::FlexFlowValue::getConstructor()
{
    return HANDLE_VOID(FlexFlowValue);
}
void *HIRMutate::CSS::FlexWrapValue::getConstructor()
{
    return HANDLE_VOID(FlexWrapValue);
}
void *HIRMutate::CSS::FloatValue::getConstructor()
{
    return HANDLE_VOID(FloatValue);
}
void *HIRMutate::CSS::FontValue::getConstructor()
{
    return HANDLE_VOID(FontValue);
}
void *HIRMutate::CSS::FontFamilyValue::getConstructor()
{
    return HANDLE_VOID(FontFamilyValue);
}
void *HIRMutate::CSS::FontFeatureSettingsValue::getConstructor()
{
    return HANDLE_VOID(FontFeatureSettingsValue);
}
void *HIRMutate::CSS::FontSmoothValue::getConstructor()
{
    return HANDLE_VOID(FontSmoothValue);
}
void *HIRMutate::CSS::FontKerningValue::getConstructor()
{
    return HANDLE_VOID(FontKerningValue);
}
void *HIRMutate::CSS::FontSizeValue::getConstructor()
{
    return HANDLE_VOID(FontSizeValue);
}
void *HIRMutate::CSS::FontSizeAdjustValue::getConstructor()
{
    return HANDLE_VOID(FontSizeAdjustValue);
}
void *HIRMutate::CSS::FontStretchValue::getConstructor()
{
    return HANDLE_VOID(FontStretchValue);
}
void *HIRMutate::CSS::FontStyleValue::getConstructor()
{
    return HANDLE_VOID(FontStyleValue);
}
void *HIRMutate::CSS::FontVariantValue::getConstructor()
{
    return HANDLE_VOID(FontVariantValue);
}
void *HIRMutate::CSS::FontVariantCapsValue::getConstructor()
{
    return HANDLE_VOID(FontVariantCapsValue);
}
void *HIRMutate::CSS::FontVariantLigaturesValue::getConstructor()
{
    return HANDLE_VOID(FontVariantLigaturesValue);
}
void *HIRMutate::CSS::FontWeightValue::getConstructor()
{
    return HANDLE_VOID(FontWeightValue);
}
void *HIRMutate::CSS::GridValue::getConstructor()
{
    return HANDLE_VOID(GridValue);
}
void *HIRMutate::CSS::GridAreaValue::getConstructor()
{
    return HANDLE_VOID(GridAreaValue);
}
void *HIRMutate::CSS::GridAutoRowsColumnsValue::getConstructor()
{
    return HANDLE_VOID(GridAutoRowsColumnsValue);
}
void *HIRMutate::CSS::GridAutoFlowValue::getConstructor()
{
    return HANDLE_VOID(GridAutoFlowValue);
}
void *HIRMutate::CSS::GridRowValue::getConstructor()
{
    return HANDLE_VOID(GridRowValue);
}
void *HIRMutate::CSS::GridLineValue::getConstructor()
{
    return HANDLE_VOID(GridLineValue);
}
void *HIRMutate::CSS::GridLineGapValue::getConstructor()
{
    return HANDLE_VOID(GridLineGapValue);
}
void *HIRMutate::CSS::GridGapValue::getConstructor()
{
    return HANDLE_VOID(GridGapValue);
}
void *HIRMutate::CSS::GridTemplateValue::getConstructor()
{
    return HANDLE_VOID(GridTemplateValue);
}
void *HIRMutate::CSS::GridTemplateAreasValue::getConstructor()
{
    return HANDLE_VOID(GridTemplateAreasValue);
}
void *HIRMutate::CSS::GridTemplateRowsColumnsValue::getConstructor()
{
    return HANDLE_VOID(GridTemplateRowsColumnsValue);
}
void *HIRMutate::CSS::HeightValue::getConstructor()
{
    return HANDLE_VOID(HeightValue);
}
void *HIRMutate::CSS::HyphensValue::getConstructor()
{
    return HANDLE_VOID(HyphensValue);
}
void *HIRMutate::CSS::ImageOrientationValue::getConstructor()
{
    return HANDLE_VOID(ImageOrientationValue);
}
void *HIRMutate::CSS::ImageRenderingValue::getConstructor()
{
    return HANDLE_VOID(ImageRenderingValue);
}
void *HIRMutate::CSS::IsolationValue::getConstructor()
{
    return HANDLE_VOID(IsolationValue);
}
void *HIRMutate::CSS::JustifyContentValue::getConstructor()
{
    return HANDLE_VOID(JustifyContentValue);
}
void *HIRMutate::CSS::JustifyItemsValue::getConstructor()
{
    return HANDLE_VOID(JustifyItemsValue);
}
void *HIRMutate::CSS::JustifySelfValue::getConstructor()
{
    return HANDLE_VOID(JustifySelfValue);
}
void *HIRMutate::CSS::KerningValue::getConstructor()
{
    return HANDLE_VOID(KerningValue);
}
void *HIRMutate::CSS::LetterSpacingValue::getConstructor()
{
    return HANDLE_VOID(LetterSpacingValue);
}
void *HIRMutate::CSS::LineBreakValue::getConstructor()
{
    return HANDLE_VOID(LineBreakValue);
}
void *HIRMutate::CSS::WebKitLocaleValue::getConstructor()
{
    return HANDLE_VOID(WebKitLocaleValue);
}
void *HIRMutate::CSS::LineHeightValue::getConstructor()
{
    return HANDLE_VOID(LineHeightValue);
}
void *HIRMutate::CSS::ListStyleValue::getConstructor()
{
    return HANDLE_VOID(ListStyleValue);
}
void *HIRMutate::CSS::ListStyleImageValue::getConstructor()
{
    return HANDLE_VOID(ListStyleImageValue);
}
void *HIRMutate::CSS::ListStylePositionValue::getConstructor()
{
    return HANDLE_VOID(ListStylePositionValue);
}
void *HIRMutate::CSS::ListStyleTypeValue::getConstructor()
{
    return HANDLE_VOID(ListStyleTypeValue);
}
void *HIRMutate::CSS::MarginValue::getConstructor()
{
    return HANDLE_VOID(MarginValue);
}
void *HIRMutate::CSS::MaxZoomValue::getConstructor()
{
    return HANDLE_VOID(MaxZoomValue);
}
void *HIRMutate::CSS::ObjectFitValue::getConstructor()
{
    return HANDLE_VOID(ObjectFitValue);
}
void *HIRMutate::CSS::OffsetAnchorValue::getConstructor()
{
    return HANDLE_VOID(OffsetAnchorValue);
}
void *HIRMutate::CSS::OffsetPositionValue::getConstructor()
{
    return HANDLE_VOID(OffsetPositionValue);
}
void *HIRMutate::CSS::OffsetRotateValue::getConstructor()
{
    return HANDLE_VOID(OffsetRotateValue);
}
void *HIRMutate::CSS::OutlineValue::getConstructor()
{
    return HANDLE_VOID(OutlineValue);
}
void *HIRMutate::CSS::OutlineColorValue::getConstructor()
{
    return HANDLE_VOID(OutlineColorValue);
}
void *HIRMutate::CSS::OutlineStyleValue::getConstructor()
{
    return HANDLE_VOID(OutlineStyleValue);
}
void *HIRMutate::CSS::OverflowValue::getConstructor()
{
    return HANDLE_VOID(OverflowValue);
}
void *HIRMutate::CSS::OverflowAnchorValue::getConstructor()
{
    return HANDLE_VOID(OverflowAnchorValue);
}
void *HIRMutate::CSS::OverflowWrapValue::getConstructor()
{
    return HANDLE_VOID(OverflowWrapValue);
}
void *HIRMutate::CSS::OverflowXValue::getConstructor()
{
    return HANDLE_VOID(OverflowXValue);
}
void *HIRMutate::CSS::PaddingValue::getConstructor()
{
    return HANDLE_VOID(PaddingValue);
}
void *HIRMutate::CSS::PerspectiveValue::getConstructor()
{
    return HANDLE_VOID(PerspectiveValue);
}
void *HIRMutate::CSS::PerspectiveOriginValue::getConstructor()
{
    return HANDLE_VOID(PerspectiveOriginValue);
}
void *HIRMutate::CSS::PointerEventsValue::getConstructor()
{
    return HANDLE_VOID(PointerEventsValue);
}
void *HIRMutate::CSS::PositionValue::getConstructor()
{
    return HANDLE_VOID(PositionValue);
}
void *HIRMutate::CSS::PositionWayValue::getConstructor()
{
    return HANDLE_VOID(PositionWayValue);
}
void *HIRMutate::CSS::PrinceHyphensValue::getConstructor()
{
    return HANDLE_VOID(PrinceHyphensValue);
}
void *HIRMutate::CSS::QuotesValue::getConstructor()
{
    return HANDLE_VOID(QuotesValue);
}
void *HIRMutate::CSS::ResizeValue::getConstructor()
{
    return HANDLE_VOID(ResizeValue);
}
void *HIRMutate::CSS::RotateValue::getConstructor()
{
    return HANDLE_VOID(RotateValue);
}
void *HIRMutate::CSS::ScaleValue::getConstructor()
{
    return HANDLE_VOID(ScaleValue);
}
void *HIRMutate::CSS::ScrollBehaviorValue::getConstructor()
{
    return HANDLE_VOID(ScrollBehaviorValue);
}
void *HIRMutate::CSS::ScrollSnapCoordinateValue::getConstructor()
{
    return HANDLE_VOID(ScrollSnapCoordinateValue);
}
void *HIRMutate::CSS::ScrollSnapPointsXValue::getConstructor()
{
    return HANDLE_VOID(ScrollSnapPointsXValue);
}
void *HIRMutate::CSS::ScrollSnapTypeValue::getConstructor()
{
    return HANDLE_VOID(ScrollSnapTypeValue);
}
void *HIRMutate::CSS::ShapeImageThresholdValue::getConstructor()
{
    return HANDLE_VOID(ShapeImageThresholdValue);
}
void *HIRMutate::CSS::ShapeOutsideValue::getConstructor()
{
    return HANDLE_VOID(ShapeOutsideValue);
}
void *HIRMutate::CSS::TableLayoutValue::getConstructor()
{
    return HANDLE_VOID(TableLayoutValue);
}
void *HIRMutate::CSS::TextAlignValue::getConstructor()
{
    return HANDLE_VOID(TextAlignValue);
}
void *HIRMutate::CSS::TextAlignLastValue::getConstructor()
{
    return HANDLE_VOID(TextAlignLastValue);
}
void *HIRMutate::CSS::TextCombineUprightValue::getConstructor()
{
    return HANDLE_VOID(TextCombineUprightValue);
}
void *HIRMutate::CSS::TextDecorationValue::getConstructor()
{
    return HANDLE_VOID(TextDecorationValue);
}
void *HIRMutate::CSS::TextDecorationLineValue::getConstructor()
{
    return HANDLE_VOID(TextDecorationLineValue);
}
void *HIRMutate::CSS::TextDecorationSkipValue::getConstructor()
{
    return HANDLE_VOID(TextDecorationSkipValue);
}
void *HIRMutate::CSS::TextDecorationStyleValue::getConstructor()
{
    return HANDLE_VOID(TextDecorationStyleValue);
}
void *HIRMutate::CSS::TextDecorationThicknessValue::getConstructor()
{
    return HANDLE_VOID(TextDecorationThicknessValue);
}
void *HIRMutate::CSS::TextIndentValue::getConstructor()
{
    return HANDLE_VOID(TextIndentValue);
}
void *HIRMutate::CSS::TextJustifyValue::getConstructor()
{
    return HANDLE_VOID(TextJustifyValue);
}
void *HIRMutate::CSS::TextOrientationValue::getConstructor()
{
    return HANDLE_VOID(TextOrientationValue);
}
void *HIRMutate::CSS::TextOverflowValue::getConstructor()
{
    return HANDLE_VOID(TextOverflowValue);
}
void *HIRMutate::CSS::TextRenderingValue::getConstructor()
{
    return HANDLE_VOID(TextRenderingValue);
}
void *HIRMutate::CSS::TextShadowValue::getConstructor()
{
    return HANDLE_VOID(TextShadowValue);
}
void *HIRMutate::CSS::TextTransformValue::getConstructor()
{
    return HANDLE_VOID(TextTransformValue);
}
void *HIRMutate::CSS::TextUnderlineValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlineValue);
}
void *HIRMutate::CSS::TextUnderlineModeValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlineModeValue);
}
void *HIRMutate::CSS::TextUnderlineStyleValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlineStyleValue);
}
void *HIRMutate::CSS::TextUnderlineWidthValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlineWidthValue);
}
void *HIRMutate::CSS::TextUnderlineOffsetValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlineOffsetValue);
}
void *HIRMutate::CSS::TextUnderlinePositionValue::getConstructor()
{
    return HANDLE_VOID(TextUnderlinePositionValue);
}
void *HIRMutate::CSS::TouchActionValue::getConstructor()
{
    return HANDLE_VOID(TouchActionValue);
}
void *HIRMutate::CSS::TransformValue::getConstructor()
{
    return HANDLE_VOID(TransformValue);
}
void *HIRMutate::CSS::TransformOriginValue::getConstructor()
{
    return HANDLE_VOID(TransformOriginValue);
}
void *HIRMutate::CSS::TransformStyleValue::getConstructor()
{
    return HANDLE_VOID(TransformStyleValue);
}
void *HIRMutate::CSS::TransitionValue::getConstructor()
{
    return HANDLE_VOID(TransitionValue);
}
void *HIRMutate::CSS::TransitionPropertyValue::getConstructor()
{
    return HANDLE_VOID(TransitionPropertyValue);
}
void *HIRMutate::CSS::TransitionTimingFunctionValue::getConstructor()
{
    return HANDLE_VOID(TransitionTimingFunctionValue);
}
void *HIRMutate::CSS::TranslateValue::getConstructor()
{
    return HANDLE_VOID(TranslateValue);
}
void *HIRMutate::CSS::UnicodeBidiValue::getConstructor()
{
    return HANDLE_VOID(UnicodeBidiValue);
}
void *HIRMutate::CSS::UserSelectValue::getConstructor()
{
    return HANDLE_VOID(UserSelectValue);
}
void *HIRMutate::CSS::UserZoomValue::getConstructor()
{
    return HANDLE_VOID(UserZoomValue);
}
void *HIRMutate::CSS::VerticalAlignValue::getConstructor()
{
    return HANDLE_VOID(VerticalAlignValue);
}
void *HIRMutate::CSS::VisibilityValue::getConstructor()
{
    return HANDLE_VOID(VisibilityValue);
}
void *HIRMutate::CSS::WhiteSpaceValue::getConstructor()
{
    return HANDLE_VOID(WhiteSpaceValue);
}
void *HIRMutate::CSS::WillChangeValue::getConstructor()
{
    return HANDLE_VOID(WillChangeValue);
}
void *HIRMutate::CSS::WordBreakValue::getConstructor()
{
    return HANDLE_VOID(WordBreakValue);
}
void *HIRMutate::CSS::WordSpacingValue::getConstructor()
{
    return HANDLE_VOID(WordSpacingValue);
}
void *HIRMutate::CSS::WritingModeValue::getConstructor()
{
    return HANDLE_VOID(WritingModeValue);
}
void *HIRMutate::CSS::ZIndexValue::getConstructor()
{
    return HANDLE_VOID(ZIndexValue);
}
void *HIRMutate::CSS::ZoomValue::getConstructor()
{
    return HANDLE_VOID(ZoomValue);
}
void *HIRMutate::CSS::WebkitTextDecorationInEffectValue::getConstructor()
{
    return HANDLE_VOID(WebkitTextDecorationInEffectValue);
}
void *HIRMutate::CSS::CaretColorValue::getConstructor()
{
    return HANDLE_VOID(CaretColorValue);
}
void *HIRMutate::CSS::FontVariationSettingsValue::getConstructor()
{
    return HANDLE_VOID(FontVariationSettingsValue);
}
void *HIRMutate::CSS::InsetValue::getConstructor()
{
    return HANDLE_VOID(InsetValue);
}
void *HIRMutate::CSS::InsetBlockValue::getConstructor()
{
    return HANDLE_VOID(InsetBlockValue);
}
void *HIRMutate::CSS::InsetInlineValue::getConstructor()
{
    return HANDLE_VOID(InsetInlineValue);
}
void *HIRMutate::CSS::MaskBorderValue::getConstructor()
{
    return HANDLE_VOID(MaskBorderValue);
}
void *HIRMutate::CSS::MaskBorderModeValue::getConstructor()
{
    return HANDLE_VOID(MaskBorderModeValue);
}
void *HIRMutate::CSS::ScrollMarginValue::getConstructor()
{
    return HANDLE_VOID(ScrollMarginValue);
}
void *HIRMutate::CSS::ScrollMarginBlockValue::getConstructor()
{
    return HANDLE_VOID(ScrollMarginBlockValue);
}
void *HIRMutate::CSS::ScrollMarginInlineValue::getConstructor()
{
    return HANDLE_VOID(ScrollMarginInlineValue);
}
void *HIRMutate::CSS::ScrollPaddingValue::getConstructor()
{
    return HANDLE_VOID(ScrollPaddingValue);
}
void *HIRMutate::CSS::ScrollPaddingBlockValue::getConstructor()
{
    return HANDLE_VOID(ScrollPaddingBlockValue);
}
void *HIRMutate::CSS::ScrollPaddingLineValue::getConstructor()
{
    return HANDLE_VOID(ScrollPaddingLineValue);
}
void *HIRMutate::CSS::ScrollPaddingInlineValue::getConstructor()
{
    return HANDLE_VOID(ScrollPaddingInlineValue);
}
void *HIRMutate::CSS::ScrollbarColorValue::getConstructor()
{
    return HANDLE_VOID(ScrollbarColorValue);
}
void *HIRMutate::CSS::AnimationValue::getConstructor()
{
    return HANDLE_VOID(AnimationValue);
}
void *HIRMutate::CSS::AnimationNameValue::getConstructor()
{
    return HANDLE_VOID(AnimationNameValue);
}
void *HIRMutate::CSS::CounterIncrementValue::getConstructor()
{
    return HANDLE_VOID(CounterIncrementValue);
}
void *HIRMutate::CSS::CursorValue::getConstructor()
{
    return HANDLE_VOID(CursorValue);
}
void *HIRMutate::CSS::ClipPathValue::getConstructor()
{
    return HANDLE_VOID(ClipPathValue);
}
void *HIRMutate::CSS::OffsetValue::getConstructor()
{
    return HANDLE_VOID(OffsetValue);
}
void *HIRMutate::CSS::OffsetPathValue::getConstructor()
{
    return HANDLE_VOID(OffsetPathValue);
}
void *HIRMutate::CSS::FilterValue::getConstructor()
{
    return HANDLE_VOID(FilterValue);
}
void *HIRMutate::CSS::MaskValue::getConstructor()
{
    return HANDLE_VOID(MaskValue);
}
void *HIRMutate::CSS::MaskImageValue::getConstructor()
{
    return HANDLE_VOID(MaskImageValue);
}