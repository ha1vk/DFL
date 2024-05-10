#include "DomValue.h"
#include "random.h"

int HIRMutate::DOMValue::list_size()
{
    if (Random::gbool())
        return Random::range(1, 5);
    else
    {
        // Special sizes that may trigger realloc
        // See ./animations/crash-when-animation-is-running-while-getting-value.html
        static const int arr[] = {7, 8, 9, 15, 16, 17, 31, 32, 33, 63, 64, 65};
        return CHOICE(arr);
    }
}

string HIRMutate::DOMValue::boolean()
{
    if (Random::gbool())
        return "true";
    else
        return "false";
}

string HIRMutate::DOMValue::number_optional_number(bool issigned)
{
    string ans;
    if (issigned)
    {
        ans = Random::signed_number();
        ans.append(",");
        ans.append(Random::signed_number());
    }
    else
    {
        ans = Random::number();
        ans.append(",");
        ans.append(Random::number());
    }
    return ans;
}

string HIRMutate::DOMValue::length(bool relative)
{
    if (!relative || Random::gbool())
    {
        if (Random::gbool())
            return Random::integer().append("px");
        else
            return Random::number().append("em");
    }
    else
    {
        static const char *arr[] = {"vw", "vh", "vmin", "vmax"};
        return Random::integer().append(CHOICE(arr));
    }
}

string HIRMutate::DOMValue::percentage()
{
    if (Random::gbool())
    {
        if (Random::gbool())
            return "0%";
        else
            return "100%";
    }
    else
    {
        return Random::range_s(0, 100).append("%");
    }
}
string HIRMutate::DOMValue::length_percentage(bool relative)
{
    if (Random::gbool())
        return length(relative);
    else
        return percentage();
}

string HIRMutate::DOMValue::number_percentage()
{
    if (Random::gbool())
        return Random::number();
    else
        return percentage();
}
string HIRMutate::DOMValue::angle()
{
    string ans = "";
    static const char *arr[] = {"0", "90", "180", "360"};
    ans.append(CHOICE(arr));
    ans.append("deg");
    return ans;
}

string HIRMutate::DOMValue::angle_nosuffix()
{
    string ans = "";
    static const char *arr[] = {"0", "90", "180", "360"};
    ans.append(CHOICE(arr));
    return ans;
}

string HIRMutate::DOMValue::angle_percentage()
{
    if (Random::gbool())
        return angle();
    else
        return percentage();
}
string HIRMutate::DOMValue::color()
{
    int c = Random::selector(5);
    static const char *arr[] = {"red", "blue", "green", "black", "white"};
    static const int arr_int[] = {6, 8};
    string ans;
    char buf[30];
    switch (c)
    {
    case 0:
        if (Random::gbool())
            return "currentColor";
        else
            return "transparent";
        break;
    case 1:
        return CHOICE(arr);
        break;
    case 2:
        ans = "#";
        ans.append(Random::hex_digits(CHOICE(arr_int)));
        return ans;
        break;
    case 3:
        sprintf(buf, "rgb(%d,%d,%d)", Random::range(0, 255), Random::range(0, 255), Random::range(0, 255));
        return buf;
        break;
    default:
        sprintf(buf, "rgba(%d,%d,%d,%d)", Random::range(0, 255), Random::range(0, 255), Random::range(0, 255), Random::range(0, 255));
        return buf;
        break;
    }
}
string HIRMutate::DOMValue::index()
{
    if (Random::selector(5) == 0)
        return Random::integer();
    else
        return Random::range_s(0, 8);
}

string HIRMutate::DOMValue::frame_url()
{
    return "data:text/html,foo";
}
string HIRMutate::DOMValue::image_url()
{
    string ans = "data:image/gif;base64,";
    static const char *arr[] = {"iVBORw0KGgoAAAANSUhEUgAAAGAAAABgCAIAAABt+uBvAAAAAXNSR0IArs4c6QAAAAlwSFlzAAALEwAACxMBAJqcGAAAAAd0SU1FB9wDGhYvCNVA1EIAAAAZdEVYdENvbW1lbnQAQ3JlYXRlZCB3aXRoIEdJTVBXgQ4XAAAAjklEQVR42u3QIQEAMAgAsHNNVspTgARY1BZh0ZWP3VcgSJAgQYIECRKEIEGCBAkSJEgQggQJEiRIkCBBCBIkSJAgQYIECUKQIEGCBAkSJAhBggQJEiRIkCAECRIkSJAgQYIEIUiQIEGCBAkShCBBggQJEiRIEIIECRIkSJAgQYIQJEiQIEGCBAlCkCBBdwaeugIthHvZ+AAAAABJRU5ErkJggg==",
                                "iVBORw0KGgoAAAANSUhEUgAAAGAAAABgCAYAAADimHc4AAAABGdBTUEAALGPC/xhBQAAAAlwSFlzAAAOxAAADsQBlSsOGwAAABh0RVh0U29mdHdhcmUAUGFpbnQuTkVUIHYzLjIyt5EXfQAAAU5JREFUeF7t07ENACAMxMDA/jsDBTtcY6TUlmx+zcx510MGNuKG/QYKgL9CAQqADWB8CygANoDxLaAA2ADGt4ACYAMY3wIKgA1gfAsoADaA8S2gANgAxreAAmADGN8CCoANYHwLKAA2gPEtoADYAMa3gAJgAxjfAgqADWB8CygANoDxLaAA2ADGt4ACYAMY3wIKgA1gfAsoADaA8S2gANgAxreAAmADGN8CCoANYHwLKAA2gPEtoADYAMa3gAJgAxjfAgqADWB8CygANoDxLaAA2ADGt4ACYAMY3wIKgA1gfAsoADaA8S2gANgAxreAAmADGN8CCoANYHwLKAA2gPEtoADYAMa3gAJgAxjfAgqADWB8CygANoDxLaAA2ADGt4ACYAMY3wIKgA1gfAsoADaA8S2gANgAxreAAmADGN8CCoANYHwLKAA2gPEtAAe4i54BvwLfXFAAAAAASUVORK5CYII="};
    return ans.append(CHOICE(arr));
}
string HIRMutate::DOMValue::video_url()
{
    return "data:video/mp4;base64,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 ";
}
string HIRMutate::DOMValue::audio_url()
{
    return "data:audio/mp3;base64,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";
}
string HIRMutate::DOMValue::track_url()
{
    return "data:text/vtt;base64,V0VCVlRUCgowMDowMDowMC4wMDAgLS0+IDAwOjAwOjAxLjAwMApTb21ldGhpbmcuCgowMDowMDowMS4wMDAgLS0+IDAwOjAwOjAyLjAwMApBbm90aGVyLg==";
}
string HIRMutate::DOMValue::move_to()
{
    static const char *cmds[] = {"M", "m"};
    string x = Random::integer();
    string y = Random::integer();
    string ans = CHOICE(cmds);
    ans.append(" ");
    ans.append(x);
    ans.append(",");
    ans.append(y);
    return ans;
}
string HIRMutate::DOMValue::line_to()
{
    if (Random::gbool())
    {
        static const char *cmds[] = {"L", "l"};
        string x = Random::integer();
        string y = Random::integer();
        string ans = CHOICE(cmds);
        ans.append(" ");
        ans.append(x);
        ans.append(",");
        ans.append(y);
        return ans;
    }
    else
    {
        static const char *cmds[] = {"H", "h", "V", "v"};
        string x = Random::integer();
        string ans = CHOICE(cmds);
        ans.append(" ");
        ans.append(x);
        return ans;
    }
}
string HIRMutate::DOMValue::bezier_curve()
{
    int c = Random::selector(3);
    static const char *cmd0[] = {"C", "c"};
    static const char *cmd1[] = {"Q", "q", "S", "s"};
    static const char *cmd2[] = {"T", "t"};
    string ans;
    switch (c)
    {
    case 0:
        ans = CHOICE(cmd0);
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        return ans;
        break;
    case 1:
        ans = CHOICE(cmd1);
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        return ans;
        break;
    default:
        ans = CHOICE(cmd2);
        ans.append(" ");
        ans.append(Random::integer());
        ans.append(",");
        ans.append(Random::integer());
        return ans;
        break;
    }
}
string HIRMutate::DOMValue::arc_curve()
{
    static const char *cmd[] = {"A", "a"};
    string ans = CHOICE(cmd);
    ans.append(" ");
    ans.append(Random::integer());
    ans.append(" ");
    ans.append(Random::integer());
    ans.append(" ");
    ans.append(Random::integer());
    ans.append(" ");
    ans.append(Random::range_s(0, 1));
    ans.append(" ");
    ans.append(Random::range_s(0, 1));
    ans.append(" ");
    ans.append(Random::integer());
    ans.append(",");
    ans.append(Random::integer());
    return ans;
}
string HIRMutate::DOMValue::close_path()
{
    static const char *cmd[] = {"Z", "z"};
    return CHOICE(cmd);
}
string HIRMutate::DOMValue::path_cmd()
{
    int c = Random::selector(5);
    switch (c)
    {
    case 0:
        return move_to();
        break;
    case 1:
        return line_to();
        break;
    case 2:
        return bezier_curve();
        break;
    case 3:
        return arc_curve();
        break;
    default:
        return close_path();
        break;
    }
}
string HIRMutate::DOMValue::path()
{
    int num = list_size();
    if (num == 0)
        return "";
    string ans = move_to();
    string tmp;
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(path_cmd());
    }
    return ans;
}
string HIRMutate::DOMValue::position()
{
    int c = Random::selector(3);
    static const char *values00[] = {"left", "center", "right"};
    static const char *values01[] = {"top", "center", "bottom"};
    static const char *values10[] = {"left", "center", "right"};
    static const char *values11[] = {"top", "center", "bottom"};
    string ans;
    switch (c)
    {
    case 0:
        ans = CHOICE(values00);
        if (Random::gbool())
        {
            ans.append(" ");
            ans.append(CHOICE(values01));
        }
        break;
    case 1:
        ans = CHOICE(values10);
        ans.append(" ");
        ans.append(length_percentage());
        if (Random::gbool())
        {
            ans.append(" ");
            ans.append(CHOICE(values11));
            ans.append(" ");
            ans.append(length_percentage());
        }
        break;
    default:
        ans = length_percentage();
        ans.append(" ");
        ans.append(length_percentage());
        break;
    }
    return ans;
}
/*
* Transform
*/
string HIRMutate::DOMValue::matrix()
{
    string ans = "matrix(";
    ans.append(Random::number());
    for (int i = 0; i < 5; i++)
    {
        ans.append(",");
        ans.append(Random::number());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::translate(bool svg)
{
    int num = Random::range(1, 2);
    string ans = "translate(";
    ans.append(svg ? Random::number() : length_percentage());
    if (num == 2)
    {
        ans.append(",");
        ans.append(svg ? Random::number() : length_percentage());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::translate_x()
{
    string ans = "translateX(";
    ans.append(length_percentage());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::translate_y()
{
    string ans = "translateY(";
    ans.append(length_percentage());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::scale()
{
    int num = Random::range(1, 2);
    string ans = "scale(";
    ans.append(Random::number());
    if (num == 2)
    {
        ans.append(",");
        ans.append(Random::number());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::scale_x()
{
    string ans = "scaleX(";
    ans.append(Random::number());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::scale_y()
{
    string ans = "scaleY(";
    ans.append(Random::number());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::rotate(bool svg)
{
    string ans = "rotate(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::skew(bool svg)
{
    int num = Random::range(1, 2);
    string ans = "skew(";
    ans.append(svg ? angle_nosuffix() : angle());
    if (num == 2)
    {
        ans.append(",");
        ans.append(svg ? angle_nosuffix() : angle());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::skew_x(bool svg)
{
    string ans = "skewX(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::skew_y(bool svg)
{
    string ans = "skewY(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::matrix3d()
{
    string ans = "matrix3d(";
    ans.append(Random::number());
    for (int i = 0; i < 15; i++)
    {
        ans.append(",");
        ans.append(Random::number());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::translate3d()
{
    string ans = "translate3d(";
    ans.append(length_percentage());
    ans.append(",");
    ans.append(length_percentage());
    ans.append(",");
    ans.append(length());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::translate_z()
{
    string ans = "translateZ(";
    ans.append(length());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::scale3d()
{
    string ans = "scale3d(";
    ans.append(Random::number());
    for (int i = 0; i < 2; i++)
    {
        ans.append(",");
        ans.append(Random::number());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::scale_z()
{
    string ans = "scaleZ(";
    ans.append(Random::number());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::rotate3d(bool svg)
{
    string ans = "rotate3d(";
    ans.append(Random::number());
    for (int i = 0; i < 2; i++)
    {
        ans.append(",");
        ans.append(Random::number());
    }
    ans.append(",");
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::rotate_x(bool svg)
{
    string ans = "rotateX(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::rotate_y(bool svg)
{
    string ans = "rotateY(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::rotate_z(bool svg)
{
    string ans = "rotateZ(";
    ans.append(svg ? angle_nosuffix() : angle());
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::perspective()
{
    string ans = "perspective(";
    ans.append(length());
    ans.append(")");
    return ans;
}
/*
* Language
*/
string HIRMutate::DOMValue::lang()
{
    static const char *langs[] = {"ar", "af", "en", "am", "ar-SA", "bg", "bn", "cs", "cy", "da", "de-DE", "el-GR", "en-US", "es-ES", "eu",
                                  "fa", "fi", "fr-fR", "gd", "gu", "he", "hi", "hr", "hu", "hy", "id", "is", "it", "iu", "ja-JP", "jw", "ka",
                                  "kk", "kn", "ko", "ky", "lt", "mk", "mr", "nl", "no", "or", "pl", "pt-PT", "pt-BR", "ro", "ru", "sa", "sr",
                                  "si", "sl", "sq", "sv", "ta", "te", "tg", "th", "tl", "tr", "tt", "uk", "ur-IN", "ur-PK", "uz", "vi", "yi",
                                  "zh-CN", "zh-TW", "fr", "fr-CA"};
    return CHOICE(langs);
}

/*
* TIME
*/
string HIRMutate::DOMValue::clock_in_s()
{
    static const char *strs[] = {"0", "0.5", "1", "1.5", "2"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::clock_in_ms()
{
    return Random::range_s(0, 300);
}
string HIRMutate::DOMValue::clock()
{
    string ans;
    if (Random::gbool())
    {
        ans = clock_in_s();
        ans.append("s");
    }
    else
    {
        ans = clock_in_ms();
        ans.append("ms");
    }
    return ans;
}
/*
* Shapes
*/
string HIRMutate::DOMValue::fill_rule()
{
    static const char *strs[] = {"nonzero", "evenodd"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::border_radius()
{
    int num = Random::range(1, 4);
    string ans = length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(length_percentage());
    }
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append("/");
        num = Random::range(1, 4);

        for (int i = 0; i < num; i++)
        {
            ans.append(" ");
            ans.append(length_percentage());
        }
    }
    return ans;
}
string HIRMutate::DOMValue::shape_radius()
{
    if (Random::gbool())
        return length_percentage();
    else
    {
        static const char *strs[] = {"closest-side", "farthest-side"};
        return CHOICE(strs);
    }
}
string HIRMutate::DOMValue::inset()
{
    int num = Random::range(1, 4);
    string ans = "inset(";
    ans.append(length_percentage());
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(length_percentage());
    }
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append("round ");
        ans.append(border_radius());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::circle()
{
    string ans = "circle(";
    if (Random::gbool())
    {
        ans.append(shape_radius());
        if (Random::gbool())
        {
            ans.append(" at ");
            ans.append(position());
        }
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::ellipse()
{
    string ans = "ellipse(";
    if (Random::gbool())
    {
        ans.append(shape_radius());
        ans.append(" ");
        ans.append(shape_radius());
        if (Random::gbool())
        {
            ans.append(" at ");
            ans.append(position());
        }
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::polygon()
{
    string ans = "polygon(";
    if (Random::gbool())
    {
        ans.append(fill_rule());
        ans.append(",");
    }
    int num = Random::range(2, 5);
    ans.append(length_percentage());
    ans.append(" ");
    ans.append(length_percentage());
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(length_percentage());
        ans.append(" ");
        ans.append(length_percentage());
    }
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::path_shape()
{
    string ans = "path(";
    if (Random::gbool())
    {
        ans.append(fill_rule());
        ans.append(",");
    }
    ans.append("'");
    ans.append(path());
    ans.append("'");
    ans.append(")");
    return ans;
}
/*
* Fonts
*/
string HIRMutate::DOMValue::font()
{
    static const char *strs[] = {"Arial", "Verdana", "serif", "sans-serif", "monospace"};
    return CHOICE(strs);
}
/*
* DateTime
*/
string HIRMutate::DOMValue::date_time()
{
    static const char *strs[] = {"1993-11-01", "1066-10-14", "0571-04-22", "0062-02-05",
                                 "1986-01-28T11:38:00.01", "0170-07-31T22:00:00"};
    return CHOICE(strs);
}
/*
* Charset
*/
string HIRMutate::DOMValue::charset()
{
    static const char *strs[] = {"UTF-7", "UTF-8", "UTF-16", "UTF-32", "EUC-JP",
                                 "ISO-2022-JP", "iso-8859-1", "Big5", "US-ASCII"};
    return CHOICE(strs);
}
/*
* DOM Attribute Value
*/
string HIRMutate::DOMValue::auto_capitalize()
{
    static const char *strs[] = {"none", "sentences", "words", "characters"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::dir_()
{
    static const char *strs[] = {"ltr", "rtl", "auto"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::tab_index()
{
    int c = Random::selector(3);
    switch (c)
    {
    case 0:
        return "-1";
        break;
    case 1:
        return Random::range_s(0, 5);
        break;
    default:
        return Random::integer();
        break;
    }
}
string HIRMutate::DOMValue::drop_zone()
{
    static const char *strs[] = {"copy", "move", "link"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::coords()
{
    int c = Random::selector(3);
    int n;
    switch (c)
    {
    case 0:
        n = 4;
        break;
    case 1:
        n = 3;
        break;
    default:
        n = Random::range(3, 5) * 2;
        break;
    }
    string ans = Random::integer();
    for (int i = 0; i < n - 1; i++)
    {
        ans.append(",");
        ans.append(Random::integer());
    }
    return ans;
}
string HIRMutate::DOMValue::shape()
{
    static const char *strs[] = {"rect", "circle", "poly", "default"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::target()
{
    static const char *strs[] = {"_replace", "_self", "_parent", "_top", "_blank"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::preload()
{
    static const char *strs[] = {"none", "metadata", "auto"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::track_kind()
{
    static const char *strs[] = {"subtitles", "captions", "descriptions", "chapters", "metadata"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::clear()
{
    static const char *strs[] = {"none", "all", "both"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::form_enc_type()
{
    static const char *strs[] = {"application/x-www-form-urlencoded", "multipart/form-data", "text/plain"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::form_method()
{
    static const char *strs[] = {"post", "get"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::button_type()
{
    static const char *strs[] = {"submit", "reset", "button"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::align()
{
    static const char *strs[] = {"left", "right", "center", "justify"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::accept()
{
    static const char *strs[] = {"audio/*", "video/*", "image/*"};
    int selector = Random::selector(4);
    if (selector == 0)
    {
        return Random::gstring();
    }
    else
    {
        return strs[selector - 1];
    }
}
string HIRMutate::DOMValue::caption_align()
{
    static const char *strs[] = {"left", "top", "right", "bottom"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::table_align()
{
    static const char *strs[] = {"left", "right", "center", "justify", "char"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::valign()
{
    static const char *strs[] = {"baseline", "bottom", "middle", "top"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::vtt_cue_align()
{
    static const char *strs[] = {"start", "middle", "end", "left", "right"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::input_mode()
{
    static const char *strs[] = {"text", "decimal", "numeric", "tel", "search", "email", "url"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::play_state()
{
    static const char *strs[] = {"idle", "running", "paused", "finished"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::animation_direction()
{
    static const char *strs[] = {"normal", "reverse", "alternate", "alternate-reverse"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::animation_easing()
{
    static const char *strs[] = {"linear", "ease", "ease-in", "ease-out", "ease-in-out", "cubic-bezier"};
    string ans = CHOICE(strs);
    if (ans == "cubic-bezier")
    {
        ans.append("(");
        ans.append(Random::number());
        for (int i = 0; i < 3; i++)
        {
            ans.append(",");
            ans.append(Random::number());
        }
        ans.append(")");
    }
    return ans;
}
string HIRMutate::DOMValue::animation_fill_mode()
{
    static const char *strs[] = {"forwards", "backwards", "both"};
    return CHOICE(strs);
}

/* iframe, image, object*/
string HIRMutate::DOMValue::object_align()
{
    static const char *strs[] = {"left", "right", "middle", "top", "bottom"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::scrolling()
{
    static const char *strs[] = {"auto", "yes", "no"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::vtt_region_scroll()
{
    static const char *strs[] = {"", "up"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::table_frame()
{
    static const char *strs[] = {"void", "above", "below", "hsides", "vsides", "lhs", "rhs", "box", "border"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::table_rules()
{
    static const char *strs[] = {"none", "groups", "rows", "columns", "all"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::wrap()
{
    static const char *strs[] = {"soft", "hard", "off"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::selection_direction()
{
    static const char *strs[] = {"forward", "backward"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::select_mode()
{
    static const char *strs[] = {"select", "start", "end", "preserve"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::numbering_type()
{
    static const char *strs[] = {"a", "A", "i", "I", "1"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::auto_complete()
{
    static const char *strs0[] = {"on", "off"};
    static const char *strs1[] = {"name", "honorific-prefix", "given-name", "additional-name", "family-name", "honorific-suffix",
                                  "nickname", "email", "username", "new-password", "current-password", "one-time-code",
                                  "organization-title", "organization", "street-address", "address-line1", "address-line2",
                                  "address-line3", "address-level1", "address-level2", "address-level3", "address-level4", "country",
                                  "country-name", "postal-code", "cc-name", "cc-given-name", "cc-additional-name", "cc-family-name",
                                  "cc-number", "cc-exp", "cc-exp-month", "cc-exp-year", "cc-csc", "cc-type", "transaction-currency",
                                  "transaction-amount", "language", "bday", "bday-day", "bday-month", "bday-year", "sex", "tel",
                                  "tel-country-code", "tel-national", "tel-area-code", "tel-local", "tel-extension", "impp", "url",
                                  "photo"};
    if (Random::gbool())
        return CHOICE(strs0);
    else
        return CHOICE(strs1);
}
string HIRMutate::DOMValue::key_type()
{
    static const char *strs[] = {"RSA", "DSA", "EC"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::srcset()
{
    string ans = image_url();
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append(Random::integer());
        ans.append("w");
    }
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append(Random::integer());
        ans.append("x");
    }
    return ans;
}
string HIRMutate::DOMValue::meta_scheme()
{
    static const char *strs[] = {"NIST", "YYYY-MM-DD", "ISBN"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::text_track_mode()
{
    static const char *strs[] = {"disabled", "hidden", "showing"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::vtt_cue_vertical()
{
    static const char *strs[] = {"", "rl", "lr"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::param_value_type()
{
    static const char *strs[] = {"data", "ref", "object"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::ulist_type()
{
    static const char *strs[] = {"circle", "disc", "square"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::link_as()
{
    static const char *strs[] = {"audio", "document", "embed", "fetch", "font", "image",
                                 "object", "script", "style", "track", "video", "worker"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::table_scope()
{
    static const char *strs[] = {"col", "row", "colgroup", "rowgroup"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::menu_type()
{
    static const char *strs[] = {"context", "toolbar"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::regex()
{
    static const char *strs[] = {"^\\d+$", "^[a-zA-Z0-9]*$", ".*"};
    if (Random::gbool())
        return Random::gstring();
    else
        return CHOICE(strs);
}
string HIRMutate::DOMValue::input_type()
{
    static const char *strs[] = {"button", "checkbox", "color", "date", "datetime-local",
                                 "email", "hidden", "image", "month", "number", "password",
                                 "radio", "range", "reset", "search", "submit", "tel", "text",
                                 "time", "url", "week", "datetime", "foo" /* "file"*/};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::menu_item_type()
{
    static const char *strs[] = {"command", "checkbox", "radio"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::marquee_behavior()
{
    static const char *strs[] = {"scroll", "slide", "alternate"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::marquee_direction()
{
    static const char *strs[] = {"left", "right", "up", "down"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::marquee_loop()
{
    if (Random::gbool())
        return "-1";
    else
        return Random::integer();
}
string HIRMutate::DOMValue::rel()
{
    static const char *strs[] = {"alternate", "author", "bookmark", "external", "help",
                                 "license", "next", "nofollow", "noreferrer", "noopener",
                                 "prev", "search", "tag", "stylesheet"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::rev()
{
    static const char *strs[] = {"alternate", "stylesheet", "start", "next", "prev",
                                 "contents", "index", "glossary", "copyright", "chapter",
                                 "section", "subsection", "appendix", "help", "bookmark",
                                 "stylesheet"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::font_weight()
{
    static const char *strs[] = {"normal", "bold", "bolder", "lighter"};
    if (Random::gbool())
        return CHOICE(strs);
    else
        return Random::integer();
}
string HIRMutate::DOMValue::font_stretch_value()
{
    static const char *strs[] = {"normal", "ultra-condensed", "extra-condensed", "condensed", "semi-condensed", "semi-expanded",
                                 "expanded", "extra-expanded", "ultra-expanded"};
    if (Random::gbool())
        return CHOICE(strs);
    else
        return percentage();
}
string HIRMutate::DOMValue::font_stretch()
{
    string ans = font_stretch_value();
    if (Random::gbool())
    {
        ans.append(" ");
        ans.append(font_stretch_value());
    }
    return ans;
}
string HIRMutate::DOMValue::font_variant()
{
    static const char *strs[] = {"normal", "small-caps"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::font_feature_settings()
{
    int num = Random::range(1, 2);
    string ans = single();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(",");
        ans.append(single());
    }
    return ans;
}
string HIRMutate::DOMValue::single()
{
    static const char *strs[] = {"smcp", "c2sc", "zero", "hist", "liga", "tnum", "frac", "swsh", "ss07", "dlig", "vert",
                                 "hwid", "twid", "qwid", "kern", "onum"};
    static const char *strs1[] = {"on", "off"};
    string ans = "'";
    ans.append(CHOICE(strs));
    ans.append("'");
    if (Random::gbool())
    {
        ans.append(" ");
        if (Random::gbool())
        {
            ans.append(CHOICE(strs1));
        }
        else
        {
            ans.append(Random::integer());
        }
    }
    return ans;
}
string HIRMutate::DOMValue::unicode_range()
{
    static const char *strs[] = {"U+0-7F", "U+0590-05FF", "U+2010-2011", "U+21E7", "U+25A0", "U+25E6", "U+FFFD"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::media_query()
{
    static const char *strs[] = {"all", "print", "screen"};
    static const char *strs1[] = {"min-width", "max-width", "min-height", "max-height", "orientation"};
    static const char *strs2[] = {"portrait", "landscape"};
    string ans = CHOICE(strs);
    if (Random::gbool())
        return ans;
    string media_feature = CHOICE(strs1);
    string media_feature_value;
    if (media_feature == "orientation")
    {
        media_feature_value = CHOICE(strs2);
    }
    else
    {
        media_feature_value = Random::integer();
        media_feature_value.append("px");
    }
    ans.append(" and (");
    ans.append(media_feature);
    ans.append(":");
    ans.append(media_feature_value);
    ans.append(")");
    return ans;
}
string HIRMutate::DOMValue::keyframe_name()
{
    static const char *arr[] = {"0", "20", "40", "60", "80", "100"};
    return CHOICE(arr);
}
string HIRMutate::DOMValue::css_type()
{
    return "text/css";
}
string HIRMutate::DOMValue::media_type()
{
    static const char *strs[] = {"image/jpeg", "image/png", "video/mp4", "audio/mp3"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::mime_type()
{
    static const char *strs[] = {"image/jpeg", "image/png", "video/mp4", "audio/mp3", "text/html", "text/css"};
    return CHOICE(strs);
}
string HIRMutate::DOMValue::image_type()
{
    static const char *strs[] = {"image/png", "image/jpeg", "image/webp"};
    return CHOICE(strs);
}