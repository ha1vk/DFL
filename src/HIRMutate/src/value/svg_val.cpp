#include "svg_val.h"
#include "serialize_variables.h"

string HIRMutate::SVG::coordinate()
{
    string ans = Random::integer();
    ans.append(",");
    ans.append(Random::integer());
    return ans;
}

string HIRMutate::SVG::points()
{
    int num = DOMValue::list_size();
    string ans = coordinate();
    for (int i = 0; i < num - 1; i++)
    {
        ans.append(" ");
        ans.append(coordinate());
    }
    return ans;
}

void HIRMutate::SVG::AlignmentBaselineValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "baseline", "before-edge", "text-before-edge", "middle", "central",
                                 "after-edge", "text-after-edge", "ideographic", "alphabetic", "hanging",
                                 "mathematical", "top", "center", "bottom"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::ClipRuleValue::generate(Context *context)
{
    static const char *strs[] = {"evenodd", "nonzero", "inherit"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::ColorInterpolationValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "linearRGB", "sRGB"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::RenderingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "optimizeSpeed", "optimizeQuality"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::EnableBackgroundValue::generate(Context *context)
{
    if (Random::gbool())
        value = "accumulate";
    else
    {
        value = "new";
        if (Random::gbool())
        {
            for (int i = 0; i < 4; i++)
            {
                value.append(" ");
                value.append(Random::integer());
            }
        }
    }
}

void HIRMutate::SVG::GlyphRefValue::generate(Context *context)
{
    value = "blah";
}

void HIRMutate::SVG::UValue::generate(Context *context)
{
    value = Random::gchar();
}

void HIRMutate::SVG::UnicodeValue::generate(Context *context)
{
    value = Random::gstring();
}

//glyph-orientation-vertical
void HIRMutate::SVG::GlyphOrientationVerticalValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::angle();
}

void HIRMutate::SVG::NameValue::generate(Context *context)
{
    //font-face-name
    static const char *strs[] = {"Courier", "SVGraffiti", "Font", "VeryUnlikelyToExistFont"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::OffsetValue::generate(Context *context)
{
    value = DOMValue::number_percentage();
}

void HIRMutate::SVG::OverflowValue::generate(Context *context)
{
    static const char *strs[] = {"visible", "hidden", "scroll", "auto"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::FeMorphologyOperatorValue::generate(Context *context)
{
    static const char *strs[] = {"erode", "dilate"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::FeCompositeOperatorValue::generate(Context *context)
{
    static const char *strs[] = {"over", "in", "out", "atop", "xor", "lighter", "arithmetic"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::OrderValue::generate(Context *context)
{
    value = Random::range_s(0, 2);
}

void HIRMutate::SVG::PointerEventsValue::generate(Context *context)
{
    static const char *strs[] = {"bounding-box", "visiblePainted", "visibleFill", "visibleStroke", "visible",
                                 "painted", "fill", "stroke", "all"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::ShapeRenderingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "optimizeSpeed", "crispEdges", "geometricPrecision"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::AnimateFillValue::generate(Context *context)
{
    static const char *strs[] = {"freeze", "remove"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::StrokeDasharrayValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = DOMValue::length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length_percentage());
    }
}

void HIRMutate::SVG::StrokeLinecapValue::generate(Context *context)
{
    static const char *strs[] = {"butt", "round", "square"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::StrokeLinejoinValue::generate(Context *context)
{
    static const char *strs[] = {"arcs", "bevel", "miter", "miter-clip", "round"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::TextAnchorValue::generate(Context *context)
{
    static const char *strs[] = {"start", "middle", "end"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::VectorEffectValue::generate(Context *context)
{
    static const char *strs[] = {"non-scaling-stroke", "non-scaling-size", "non-rotation", "fixed-position"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::WordSpacingValue::generate(Context *context)
{
    if (Random::gbool())
        value = "normal";
    else
        value = DOMValue::length_percentage();
}

void HIRMutate::SVG::FilterDxValue::generate(Context *context)
{
    value = Random::number();
}

void HIRMutate::SVG::DxValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = DOMValue::length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length_percentage());
    }
}

void HIRMutate::SVG::FormatValue::generate(Context *context)
{
    static const char *strs[] = {"truedoc-pfr", "embedded-opentype", "type-1", "truetype", "opentype", "truetype-gx", "speedo",
                                 "intellifont"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::AutoWidthValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::length_percentage();
}

void HIRMutate::SVG::BBoxValue::generate(Context *context)
{
    value = Random::number();
    for (int i = 0; i < 3; i++)
    {
        value.append(",");
        value.append(Random::number());
    }
}

void HIRMutate::SVG::OrientValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
    {
        static const char *strs[] = {"auto", "auto-start-reverse"};
        value = CHOICE(strs);
    }
    else if (c == 1)
        value = DOMValue::angle();
    else
        value = Random::number();
}

void HIRMutate::SVG::PanoseValue::generate(Context *context)
{
    value = Random::integer();
    for (int i = 0; i < 9; i++)
    {
        value.append(" ");
        value.append(Random::integer());
    }
}

void HIRMutate::SVG::PointsValue::generate(Context *context)
{
    value = points();
}

void HIRMutate::SVG::PreserveAspectRatioValue::generate(Context *context)
{
    static const char *strs[] = {"xMinYMin", "xMidYMin", "xMaxYMin", "xMinYMid", "xMidYMid", "xMaxYMid",
                                 "xMinYMax", "xMidYMax", "xMaxYMax"};
    value = CHOICE(strs);
    if (Random::gbool())
    {
        value.append(" ");
        static const char *strs2[] = {"meet", "slice"};
        value.append(CHOICE(strs2));
    }
}

// FIXME: SVG 1.1 only
void HIRMutate::SVG::MarkerRefXValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::length_percentage();
    else
        value = Random::number();
}

//FIXME: SVG 1.1 only
void HIRMutate::SVG::SymbolRefXValue::generate(Context *context)
{
    value = DOMValue::length();
}

void HIRMutate::SVG::RXValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::length_percentage();
}

void HIRMutate::SVG::TableValuesValue::generate(Context *context)
{
    int num = Random::range(1, 4);
    value = Random::float01();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(Random::float01());
    }
}

void HIRMutate::SVG::UnicodeRangeValue::generate(Context *context)
{
    value = DOMValue::unicode_range();
}

void HIRMutate::SVG::ViewBoxValue::generate(Context *context)
{
    value = Random::integer();
    for (int i = 0; i < 3; i++)
    {
        value.append(",");
        value.append(Random::integer());
    }
}

void HIRMutate::SVG::AltGlyphXValue::generate(Context *context)
{
    int num = Random::range(1, 5);
    value = DOMValue::length();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length());
    }
}

void HIRMutate::SVG::TextXValue::generate(Context *context)
{
    int num = DOMValue::list_size();
    if (num > 0)
    {
        value = DOMValue::length_percentage();
        for (int i = 0; i < num - 1; i++)
        {
            value.append(",");
            value.append(DOMValue::length_percentage());
        }
    }
    else
        value = "0";
}

void HIRMutate::SVG::SpacingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "exact"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::MethodValue::generate(Context *context)
{
    static const char *strs[] = {"align", "stretch"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::SideValue::generate(Context *context)
{
    static const char *strs[] = {"left", "right"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::UnitsValue::generate(Context *context)
{
    static const char *strs[] = {"userSpaceOnUse", "objectBoundingBox"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::OrientationValue::generate(Context *context)
{
    static const char *strs[] = {"h", "v"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::AltValue::generate(Context *context)
{
    value = "icon";
}

void HIRMutate::SVG::ArabicFormValue::generate(Context *context)
{
    static const char *strs[] = {"isolated", "medial", "terminal", "initial"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::BaseProfileValue::generate(Context *context)
{
    static const char *strs[] = {"tiny", "basic", "full"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::EdgeModeValue::generate(Context *context)
{
    static const char *strs[] = {"duplicate", "wrap"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::LengthAdjustValue::generate(Context *context)
{
    static const char *strs[] = {"spacing", "spacingAndGlyphs"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::MarkerUnitsValue::generate(Context *context)
{
    static const char *strs[] = {"userSpaceOnUse", "strokeWidth"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::SpreadMethodValue::generate(Context *context)
{
    static const char *strs[] = {"pad", "reflect", "repeat"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::StitchTilesValue::generate(Context *context)
{
    static const char *strs[] = {"noStitch", "stitch"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::RenderingIntentValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "perceptual", "relative-colorimetric", "saturation", "absolute-colorimetric"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::RGBAValue::generate(Context *context)
{
    static const char *strs[] = {"R", "G", "B", "A"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::ZoomAndPanValue::generate(Context *context)
{
    static const char *strs[] = {"disable", "magnify"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::DurValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::clock();
    else
        value = "indefinite";
}

void HIRMutate::SVG::RestartValue::generate(Context *context)
{
    static const char *strs[] = {"always", "whenNotActive", "never"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::RepeatCountValue::generate(Context *context)
{
    if (Random::gbool())
        value = Random::integer();
    else
        value = "indefinite";
}

void HIRMutate::SVG::AdditiveValue::generate(Context *context)
{
    static const char *strs[] = {"replace", "sum"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::AccumulateValue::generate(Context *context)
{
    value = "sum";
}

void HIRMutate::SVG::CalcModeValue::generate(Context *context)
{
    static const char *strs[] = {"discrete", "linear", "paced", "spline"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::RotateValue::generate(Context *context)
{
    int c = Random::selector(3);
    if (c == 0)
        value = "auto";
    else if (c == 1)
        value = "auto-reverse";
    else
        value = Random::integer();
}

void HIRMutate::SVG::AnimateTransformTypeValue::generate(Context *context)
{
    static const char *strs[] = {"translate", "scale", "rotate", "skewX", "skewY"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::FeColorMatrixTypeValue::generate(Context *context)
{
    static const char *strs[] = {"matrix", "saturate", "hueRotate", "luminanceToAlpha"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::FeFuncTypeValue::generate(Context *context)
{
    static const char *strs[] = {"identity", "table", "discrete", "linear", "gamma"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::FeTurbulenceValue::generate(Context *context)
{
    static const char *strs[] = {"fractalNoise", "turbulence"};
    value = CHOICE(strs);
}

//type = "translate"
void HIRMutate::SVG::TransformTranslateValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = DOMValue::length_percentage();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(DOMValue::length_percentage());
    }
}

//type = "scale"
void HIRMutate::SVG::TransformScaleValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = Random::number();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(Random::number());
    }
}

//type = "rotate"
void HIRMutate::SVG::TransformRotateValue::generate(Context *context)
{
    value = DOMValue::angle_nosuffix();
    if (Random::gbool())
    {
        value.append(" ");
        value.append(Random::integer());
        value.append(" ");
        value.append(Random::integer());
    }
}

//type = "skewX" / "skewY"
void HIRMutate::SVG::TransformSkewXValue::generate(Context *context)
{
    value = DOMValue::angle_nosuffix();
}

void HIRMutate::SVG::CoordinateValue::generate(Context *context)
{
    value = coordinate();
}

void HIRMutate::SVG::PathValue::generate(Context *context)
{
    value = DOMValue::path();
}

void HIRMutate::SVG::BufferedRenderingValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "dynamic", "static"};
    value = CHOICE(strs);
}

//baseline-shift

void HIRMutate::SVG::BaselineShiftValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::length_percentage();
    else
    {
        static const char *strs[] = {"sub", "super"};
        value = CHOICE(strs);
    }
}

//color-interpolation-filters

void HIRMutate::SVG::ColorInterpolationFiltersValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "linearRGB", "sRGB"};
    value = CHOICE(strs);
}

//color-profile
void HIRMutate::SVG::ColorProfileValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "sRGB"};
    value = CHOICE(strs);
}

//dominant-baseline
void HIRMutate::SVG::DominantBaselineValue::generate(Context *context)
{
    static const char *strs[] = {"auto", "ideographic", "alphabetic", "hanging", "mathematical", "middle",
                                 "text-bottom", "central", "text-top"};
    value = CHOICE(strs);
}

//fill-rule
void HIRMutate::SVG::FillRuleValue::generate(Context *context)
{
    static const char *strs[] = {"nonzero", "evenodd"};
    value = CHOICE(strs);
}

//kerning
void HIRMutate::SVG::KerningValue::generate(Context *context)
{
    if (Random::gbool())
        value = "auto";
    else
        value = DOMValue::length();
}

void HIRMutate::SVG::PaintOrderValue::generate(Context *context)
{
    if (Random::gbool())
        value = "normal";
    else
    {
        string selectors = Random::selectors(3);
        value = "";
        if (selectors[0])
            value.append("fill");
        if (selectors[1])
            value.append(" stroke");
        if (selectors[2])
            value.append(" markers");
    }
}

void HIRMutate::SVG::ImageHrefValue::generate(Context *context)
{
    if (Random::gbool())
        value = DOMValue::image_url();
    else
        value = "x";
}

void HIRMutate::SVG::WhiteSpaceValue::generate(Context *context)
{
    static const char *strs[] = {"normal", "pre", "nowrap", "pre-wrap", "pre-line"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::TextOverflowValue::generate(Context *context)
{
    static const char *strs[] = {"ellipsis", "clip"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::CrossoriginValue::generate(Context *context)
{
    static const char *strs[] = {"anonymous", "use-credentials"};
    value = CHOICE(strs);
}

string HIRMutate::SVG::svg_transform()
{
    int c = Random::selector(6);
    if (c == 0)
        return DOMValue::translate(true);
    else if (c == 1)
        return DOMValue::scale();
    else if (c == 2)
        return DOMValue::rotate(true);
    else if (c == 3)
        return DOMValue::skew_x(true);
    else if (c == 4)
        return DOMValue::skew_y(true);
    else
        return DOMValue::matrix();
}

void HIRMutate::SVG::TransformValue::generate(Context *context)
{
    int num = Random::range(1, 2);
    value = svg_transform();
    for (int i = 0; i < num - 1; i++)
    {
        value.append(" ");
        value.append(svg_transform());
    }
}

HIRMutate::SVG::KeySplinesValue::KeySplinesValue(int value_count)
{
    this->value_count = value_count;
};

string HIRMutate::SVG::KeySplinesValue::control_point()
{
    string ans = Random::float01();
    for (int i = 0; i < 3; i++)
    {
        ans.append(" ");
        ans.append(Random::float01());
    }
    return ans;
}
//TODO : maybe need fix
void HIRMutate::SVG::KeySplinesValue::generate(Context *context)
{
    if (value_count <= 1)
        value = "";
    else
    {
        value = control_point();
        for (int i = 0; i < value_count - 2; i++)
        {
            value.append(";");
            value.append(control_point());
        }
    }
}

HIRMutate::SVG::KeyPointsValue::KeyPointsValue(int value_count)
{
    this->value_count = value_count;
}

void HIRMutate::SVG::KeyPointsValue::generate(Context *context)
{
    value = Random::float01();
    for (int i = 0; i < value_count - 1; i++)
    {
        value.append(";");
        value.append(Random::float01());
    }
}

HIRMutate::SVG::KeyTimesValue::KeyTimesValue(int value_count)
{
    this->value_count = value_count;
}

string HIRMutate::SVG::KeyTimesValue::linear_time_list(int num)
{
    if (num == 1)
        return "0";
    vector<double> values;
    values.push_back(0);
    for (int i = 0; i < num - 2; i++)
    {
        values.push_back(Random::float01_f());
    }
    values.push_back(1);
    sort(values.begin(), values.end());
    string ans = "";
    char buf[20];
    sprintf(buf, "%.2f", values[0]);
    ans.append(buf);
    std::for_each(values.begin() + 1, values.end(),
                  [&buf, &ans](double &val)
                  {
                      ans.append(";");
                      sprintf(buf, "%.2f", val);
                      ans.append(buf);
                  });
    return ans;
}

string HIRMutate::SVG::KeyTimesValue::discrete_time_list(int num)
{
    string ans = "";
    char buf[20];
    for (int i = 0; i < num; i++)
    {
        sprintf(buf, "%d", num);
        ans.append(buf);
        if (i != num - 1)
        {
            ans.append(";");
        }
    }
    return ans;
}

void HIRMutate::SVG::KeyTimesValue::generate(Context *context)
{
    if (Random::gbool())
        value = linear_time_list(value_count);
    else
        value = discrete_time_list(value_count);
}

void HIRMutate::SVG::KernelMatrixValue::generate(Context *context)
{
    int order = Random::range(0, 2);
    int n = order * order;
    value = "";
    for (int i = 0; i < n; i++)
    {
        value.append(Random::integer());
        if (i != n - 1)
        {
            value.append(" ");
        }
    }
}

void HIRMutate::SVG::FeColorMatrixValuesValue::generate(Context *context)
{
    if (Random::gbool())
    {
        value = Random::number();
        for (int i = 0; i < 19; i++)
        {
            value.append(" ");
            value.append(Random::number());
        }
    }
    else
        value = Random::float01();
}

/*
* Dynamic values
*/
HIRMutate::SVG::SVGElementIDValue::SVGElementIDValue()
{
    elem = nullptr;
}

void HIRMutate::SVG::SVGElementIDValue::generate(Context *context)
{
    elem = context->get_object(DOC::svg_elements);
}

void HIRMutate::SVG::SVGElementIDValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
        {
            elem = merge_map[elem];
        }
    }
}
string HIRMutate::SVG::SVGElementIDValue::getValue()
{
    if (elem)
        return elem->id;
    else
        return "foo";
}

HIRMutate::SVG::FillValue::FillValue()
{
    paint_server = nullptr;
}
void HIRMutate::SVG::FillValue::generate_static()
{
    paint_server = nullptr;
    if (Random::gbool())
    {
        static const char *strs[] = {"context-fill", "context-stroke"};
        fill_value = CHOICE(strs);
    }
    else
        fill_value = DOMValue::color();
}
void HIRMutate::SVG::FillValue::generate_dynamic(Context *context)
{
    fill_value = "";

    paint_server = context->get_object(DOC::svg_paint_server_elements);
    if (paint_server == nullptr)
    {
        generate_static();
        return;
    }

    if (Random::gbool())
        color = DOMValue::color();
    else
        color = "";
}
void HIRMutate::SVG::FillValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::SVG::FillValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (paint_server)
    {
        if (merge_map.find(paint_server) != merge_map.end())
        {
            paint_server = merge_map[paint_server];
        }
    }
}
string HIRMutate::SVG::FillValue::getValue()
{
    if (fill_value != "")
        return fill_value;
    string s = "url(#";
    if (paint_server)
        s.append(paint_server->id);
    s.append(")");
    if (color != "")
    {
        s.append(" ");
        s.append(color);
    }
    return s;
}

HIRMutate::SVG::BeginValue::BeginValue()
{
    elem = nullptr;
}
void HIRMutate::SVG::BeginValue::generate_abs()
{
    elem = nullptr;
    action = "";
    repeat_num = "";
    event = "";
    if (Random::gbool())
        abs = DOMValue::clock();
    else
        abs = "indefinite";
}

void HIRMutate::SVG::BeginValue::generate_rel1(Context *context)
{
    abs = "";
    action = "";
    repeat_num = "";
    event = "";
    elem = context->get_object(DOC::svg_animation_elements);
    if (elem == nullptr)
    {
        generate_abs();
        return;
    }
    static const char *strs[] = {"begin", "end", "repeat"};
    action = CHOICE(strs);
    if (action == "repeat")
        repeat_num = Random::integer();
}
void HIRMutate::SVG::BeginValue::generate_rel2(Context *context)
{
    abs = "";
    action = "";
    repeat_num = "";
    event = "";
    elem = context->get_object(DOC::elements);
    if (elem == nullptr)
    {
        generate_abs();
        return;
    }
    event = CHOICE_OBJ(DOC::svg_animation_begin_events);
}

void HIRMutate::SVG::BeginValue::generate(Context *context)
{
    int c = Random::selector(5);
    if (c == 0 || c == 1)
        generate_abs();
    else if (c == 2 || c == 3)
        generate_rel1(context);
    else
        generate_rel2(context);
}

void HIRMutate::SVG::BeginValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
        {
            elem = merge_map[elem];
        }
    }
}

string HIRMutate::SVG::BeginValue::getValue()
{
    if (abs != "")
        return abs;
    if (elem == nullptr)
        return "";
    if (action != "")
    {
        string s = elem->id;
        s.append(".");
        s.append(action);
        if (action == "repeat")
        {
            s.append("(");
            s.append(repeat_num);
            s.append(")");
        }
        return s;
    }
    else
    {
        string s = elem->id;
        s.append(".");
        s.append(event);
        return s;
    }
}

//marker-start/mid/end
HIRMutate::SVG::MarkerValue::MarkerValue()
{
    marker = nullptr;
}
void HIRMutate::SVG::MarkerValue::generate(Context *context)
{
    marker = context->get_object("SVGMarkerElement");
}

void HIRMutate::SVG::MarkerValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (marker)
    {
        if (merge_map.find(marker) != merge_map.end())
        {
            marker = merge_map[marker];
        }
    }
}
string HIRMutate::SVG::MarkerValue::getValue()
{
    if (marker == nullptr)
        return "none";
    string s = "url(";
    s.append("#");
    s.append(marker->id);
    s.append(")");
    return s;
}
HIRMutate::SVG::PatternHrefValue::PatternHrefValue()
{
    pattern = nullptr;
}
void HIRMutate::SVG::PatternHrefValue::generate(Context *context)
{
    pattern = context->get_object("SVGPatternElement");
}

void HIRMutate::SVG::PatternHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (pattern)
    {
        if (merge_map.find(pattern) != merge_map.end())
        {
            pattern = merge_map[pattern];
        }
    }
}
string HIRMutate::SVG::PatternHrefValue::getValue()
{
    if (pattern == nullptr)
        return "none";
    string s = "url(";
    s.append("#");
    s.append(pattern->id);
    s.append(")");
    return s;
}
HIRMutate::SVG::FeImageHrefValue::FeImageHrefValue()
{
    image = nullptr;
}
void HIRMutate::SVG::FeImageHrefValue::generate_static()
{
    image = nullptr;
    if (Random::gbool())
        value = DOMValue::image_url();
    else
        value = "x";
}

void HIRMutate::SVG::FeImageHrefValue::generate_dynamic(Context *context)
{
    value = "";
    image = context->get_object(DOC::image_elements);
    if (image == nullptr)
        generate_static();
}

void HIRMutate::SVG::FeImageHrefValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::SVG::FeImageHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (image)
    {
        if (merge_map.find(image) != merge_map.end())
        {
            image = merge_map[image];
        }
    }
}
string HIRMutate::SVG::FeImageHrefValue::getValue()
{
    if (value != "")
        return value;
    string s = "#";
    if (image)
        s.append(image->id);
    return s;
}
HIRMutate::SVG::UseHrefValue::UseHrefValue()
{
    elem = nullptr;
}
void HIRMutate::SVG::UseHrefValue::generate(Context *context)
{
    elem = context->get_object(DOC::svg_elements);
}

void HIRMutate::SVG::UseHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem)
    {
        if (merge_map.find(elem) != merge_map.end())
        {
            elem = merge_map[elem];
        }
    }
}

string HIRMutate::SVG::UseHrefValue::getValue()
{
    if (elem == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(elem->id);
    return ans;
}
HIRMutate::SVG::GradientHrefValue::GradientHrefValue()
{
    gradient = nullptr;
}
void HIRMutate::SVG::GradientHrefValue::generate(Context *context)
{
    gradient = context->get_object(DOC::svg_gradient_elements);
}

void HIRMutate::SVG::GradientHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (gradient)
    {
        if (merge_map.find(gradient) != merge_map.end())
        {
            gradient = merge_map[gradient];
        }
    }
}

string HIRMutate::SVG::GradientHrefValue::getValue()
{
    if (gradient == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(gradient->id);
    return ans;
}
HIRMutate::SVG::PathHrefValue::PathHrefValue()
{
    path = nullptr;
}
void HIRMutate::SVG::PathHrefValue::generate(Context *context)
{
    path = context->get_object("SVGPathElement");
}

void HIRMutate::SVG::PathHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (path)
    {
        if (merge_map.find(path) != merge_map.end())
        {
            path = merge_map[path];
        }
    }
}

string HIRMutate::SVG::PathHrefValue::getValue()
{
    if (path == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(path->id);
    return ans;
}

HIRMutate::SVG::CursorHrefValue::CursorHrefValue()
{
    image = nullptr;
}
void HIRMutate::SVG::CursorHrefValue::generate_static()
{
    image = nullptr;
    if (Random::gbool())
        value = DOMValue::image_url();
    else
        value = "x";
}

void HIRMutate::SVG::CursorHrefValue::generate_dynamic(Context *context)
{
    value = "";
    image = context->get_object(DOC::image_elements);
    if (image == nullptr)
        generate_static();
}

void HIRMutate::SVG::CursorHrefValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::SVG::CursorHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (image)
    {
        if (merge_map.find(image) != merge_map.end())
        {
            image = merge_map[image];
        }
    }
}
string HIRMutate::SVG::CursorHrefValue::getValue()
{
    if (value != "")
        return value;
    string s = "#";
    if (image)
        s.append(image->id);
    return s;
}

HIRMutate::SVG::TRefXlinkHrefValue::TRefXlinkHrefValue()
{
    text = nullptr;
}
void HIRMutate::SVG::TRefXlinkHrefValue::generate(Context *context)
{
    text = context->get_object(DOC::svg_text_content_elements);
}

void HIRMutate::SVG::TRefXlinkHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (text)
    {
        if (merge_map.find(text) != merge_map.end())
        {
            text = merge_map[text];
        }
    }
}
string HIRMutate::SVG::TRefXlinkHrefValue::getValue()
{
    if (text == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(text->id);
    return ans;
}

HIRMutate::SVG::GlyphRefXlinkHrefValue::GlyphRefXlinkHrefValue()
{
    glyph = nullptr;
}
void HIRMutate::SVG::GlyphRefXlinkHrefValue::generate(Context *context)
{
    glyph = context->get_object("SVGGlyphElement");
}

void HIRMutate::SVG::GlyphRefXlinkHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (glyph)
    {
        if (merge_map.find(glyph) != merge_map.end())
        {
            glyph = merge_map[glyph];
        }
    }
}

string HIRMutate::SVG::GlyphRefXlinkHrefValue::getValue()
{
    if (glyph == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(glyph->id);
    return ans;
}

HIRMutate::SVG::AltGlyphXlinkHrefValue::AltGlyphXlinkHrefValue()
{
    glyph = nullptr;
}
void HIRMutate::SVG::AltGlyphXlinkHrefValue::generate(Context *context)
{
    vector<string> vec = {"SVGGlyphElement", "SVGAltGlyphDefElement"};
    glyph = context->get_object(vec);
}

void HIRMutate::SVG::AltGlyphXlinkHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (glyph)
    {
        if (merge_map.find(glyph) != merge_map.end())
        {
            glyph = merge_map[glyph];
        }
    }
}
string HIRMutate::SVG::AltGlyphXlinkHrefValue::getValue()
{
    if (glyph == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(glyph->id);
    return ans;
}

HIRMutate::SVG::FontFaceUriXlinkHrefValue::FontFaceUriXlinkHrefValue()
{
    font = nullptr;
}
void HIRMutate::SVG::FontFaceUriXlinkHrefValue::generate(Context *context)
{
    font = context->get_object("SVGFontElement");
}

void HIRMutate::SVG::FontFaceUriXlinkHrefValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (font)
    {
        if (merge_map.find(font) != merge_map.end())
        {
            font = merge_map[font];
        }
    }
}
string HIRMutate::SVG::FontFaceUriXlinkHrefValue::getValue()
{
    if (font == nullptr)
        return "#foo";
    string ans = "#";
    ans.append(font->id);
    return ans;
}
HIRMutate::SVG::GValue::GValue()
{
    glyph = nullptr;
}
void HIRMutate::SVG::GValue::generate(Context *context)
{
    glyph = context->get_object("SVGGlyphElement");
}

void HIRMutate::SVG::GValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (glyph)
    {
        if (merge_map.find(glyph) != merge_map.end())
        {
            glyph = merge_map[glyph];
        }
    }
}
string HIRMutate::SVG::GValue::getValue()
{
    if (glyph == nullptr)
        return "#foo";
    return glyph->id;
}

HIRMutate::SVG::InValue::InValue()
{
    filter_primitive = nullptr;
}
void HIRMutate::SVG::InValue::generate_static()
{
    filter_primitive = nullptr;
    static const char *strs[] = {"SourceGraphic", "SourceAlpha", "BackgroundImage", "BackgroundAlpha", "FillPaint", "StrokePaint"};
    value = CHOICE(strs);
}

void HIRMutate::SVG::InValue::generate_dynamic(Context *context)
{
    value = "";
    filter_primitive = context->get_object(DOC::svg_filter_primitives);
    if (filter_primitive == nullptr)
        generate_static();
}

void HIRMutate::SVG::InValue::generate(Context *context)
{
    if (Random::gbool())
        generate_static();
    else
        generate_dynamic(context);
}

void HIRMutate::SVG::InValue::merge_fix(map<Object *, Object *> &merge_map)
{
    if (filter_primitive)
    {
        if (merge_map.find(filter_primitive) != merge_map.end())
        {
            filter_primitive = merge_map[filter_primitive];
        }
    }
}
string HIRMutate::SVG::InValue::getValue()
{
    if (filter_primitive)
        return filter_primitive->id;
    return value;
}

/*
* Animation values
*/

HIRMutate::SVG::FromValue::FromValue(Value *(*value_class)(void))
{
    this->value_obj = nullptr;
    this->value_class = value_class;
}
HIRMutate::SVG::FromValue::~FromValue()
{
    if (value_obj)
        delete value_obj;
}
void HIRMutate::SVG::FromValue::generate(Context *context)
{
    value_obj = value_class();
    value_obj->generate(context);
}

bool HIRMutate::SVG::FromValue::mutate(Context *context)
{
    value_obj->mutate(context);
    return true;
}

void HIRMutate::SVG::FromValue::merge_fix(map<Object *, Object *> &merge_map)
{
    value_obj->merge_fix(merge_map);
}

string HIRMutate::SVG::FromValue::getValue()
{
    return value_obj->getValue();
}

HIRMutate::SVG::AnimationValuesValue::AnimationValuesValue(Value *(*value_class)(void), int value_count)
{
    this->value_class = value_class;
    this->value_count = value_count;
}
HIRMutate::SVG::AnimationValuesValue::~AnimationValuesValue()
{
    std::for_each(value_objs.begin(), value_objs.end(),
                  [](Value *val)
                  {
                      delete val;
                  });
}
void HIRMutate::SVG::AnimationValuesValue::generate(Context *context)
{
    for (int i = 0; i < value_count; i++)
    {
        Value *value_obj = value_class();
        value_obj->generate(context);
        value_objs.push_back(value_obj);
    }
}

bool HIRMutate::SVG::AnimationValuesValue::mutate(Context *context)
{
    Value *value_obj = CHOICE_OBJ(value_objs);
    value_obj->mutate(context);
    return true;
}

void HIRMutate::SVG::AnimationValuesValue::merge_fix(map<Object *, Object *> &merge_map)
{
    std::for_each(value_objs.begin(), value_objs.end(),
                  [&merge_map](Value *val)
                  {
                      val->merge_fix(merge_map);
                  });
}
string HIRMutate::SVG::AnimationValuesValue::getValue()
{
    int size = value_objs.size();
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        ans.append(value_objs[i]->getValue());
        if (i != size - 1)
        {
            ans.append(";");
        }
    }
    return ans;
}

//序列化
void HIRMutate::SVG::AlignmentBaselineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AlignmentBaselineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ClipRuleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ClipRuleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ColorInterpolationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColorInterpolationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RenderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RenderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::EnableBackgroundValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("EnableBackgroundValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::GlyphRefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GlyphRefValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::UValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::UnicodeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UnicodeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::GlyphOrientationVerticalValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GlyphOrientationVerticalValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::NameValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("NameValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::OffsetValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::OffsetValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::OverflowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::OverflowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeMorphologyOperatorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeMorphologyOperatorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeCompositeOperatorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeCompositeOperatorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::OrderValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OrderValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PointerEventsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::PointerEventsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ShapeRenderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ShapeRenderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AnimateFillValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimateFillValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::StrokeDasharrayValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("StrokeDasharrayValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::StrokeLinecapValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("StrokeLinecapValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::StrokeLinejoinValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("StrokeLinejoinValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TextAnchorValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextAnchorValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::VectorEffectValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("VectorEffectValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::WordSpacingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::WordSpacingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FilterDxValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FilterDxValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::DxValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DxValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FormatValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FormatValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AutoWidthValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AutoWidthValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::BBoxValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BBoxValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::OrientValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OrientValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PanoseValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PanoseValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PointsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PointsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PreserveAspectRatioValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PreserveAspectRatioValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::MarkerRefXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarkerRefXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::SymbolRefXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SymbolRefXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TableValuesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TableValuesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::UnicodeRangeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UnicodeRangeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ViewBoxValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ViewBoxValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AltGlyphXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AltGlyphXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TextXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TextXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::SpacingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SpacingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::MethodValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MethodValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::SideValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SideValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::UnitsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UnitsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::OrientationValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("OrientationValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AltValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AltValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ArabicFormValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ArabicFormValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::BaseProfileValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BaseProfileValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::EdgeModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("EdgeModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::LengthAdjustValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("LengthAdjustValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::MarkerUnitsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarkerUnitsValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::SpreadMethodValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SpreadMethodValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::StitchTilesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("StitchTilesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RenderingIntentValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RenderingIntentValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RGBAValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RGBAValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ZoomAndPanValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ZoomAndPanValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::DurValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DurValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RestartValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RestartValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RepeatCountValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("RepeatCountValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AdditiveValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AdditiveValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AccumulateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AccumulateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::CalcModeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CalcModeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::RotateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::RotateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::AnimateTransformTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimateTransformTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeColorMatrixTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeColorMatrixTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeFuncTypeValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeFuncTypeValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeTurbulenceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeTurbulenceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TransformTranslateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformTranslateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TransformScaleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformScaleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TransformRotateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformRotateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TransformSkewXValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TransformSkewXValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::CoordinateValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CoordinateValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PathValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PathValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::BufferedRenderingValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BufferedRenderingValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::BaselineShiftValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BaselineShiftValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ColorInterpolationFiltersValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColorInterpolationFiltersValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ColorProfileValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ColorProfileValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::DominantBaselineValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DominantBaselineValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FillRuleValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FillRuleValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::KerningValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::KerningValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::PaintOrderValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PaintOrderValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::ImageHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("ImageHrefValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::WhiteSpaceValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::WhiteSpaceValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TextOverflowValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::TextOverflowValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::CrossoriginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CrossoriginValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::TransformValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVG::TransformValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::KeySplinesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("KeySplinesValue");
    StaticValue::serialize(stream, context);
    stream->write_int(value_count);
}
void HIRMutate::SVG::KeySplinesValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StaticValue::unserialize(stream, global_document, function);
    value_count = stream->read_int();
}
void HIRMutate::SVG::KeyPointsValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("KeyPointsValue");
    StaticValue::serialize(stream, context);
    stream->write_int(value_count);
}
void HIRMutate::SVG::KeyPointsValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StaticValue::unserialize(stream, global_document, function);
    value_count = stream->read_int();
}
void HIRMutate::SVG::KeyTimesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("KeyTimesValue");
    StaticValue::serialize(stream, context);
    stream->write_int(value_count);
}
void HIRMutate::SVG::KeyTimesValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StaticValue::unserialize(stream, global_document, function);
    value_count = stream->read_int();
}
void HIRMutate::SVG::KernelMatrixValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("KernelMatrixValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::FeColorMatrixValuesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeColorMatrixValuesValue");
    StaticValue::serialize(stream, context);
}

void HIRMutate::SVG::SVGElementIDValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("SVGElementIDValue");
    DynamicValue::serialize(stream, context);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::SVGElementIDValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
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
void HIRMutate::SVG::FillValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FillValue");
    DynamicValue::serialize(stream, context);
    stream->write_string(fill_value);
    if (paint_server)
        paint_server->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
    stream->write_string(color);
}
void HIRMutate::SVG::FillValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    fill_value = stream->read_string();
    if (stream->peek() == "nullptr")
    {
        paint_server = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&paint_server, global_document);
    }
    color = stream->read_string();
}
void HIRMutate::SVG::BeginValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("BeginValue");
    DynamicValue::serialize(stream, context);
    stream->write_string(abs);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
    stream->write_string(action);
    stream->write_string(repeat_num);
    stream->write_string(event);
}
void HIRMutate::SVG::BeginValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    abs = stream->read_string();
    if (stream->peek() == "nullptr")
    {
        elem = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&elem, global_document);
    }
    action = stream->read_string();
    repeat_num = stream->read_string();
    event = stream->read_string();
}
void HIRMutate::SVG::MarkerValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("MarkerValue");
    DynamicValue::serialize(stream, context);
    if (marker)
        marker->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::MarkerValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        marker = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&marker, global_document);
    }
}
void HIRMutate::SVG::PatternHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PatternHrefValue");
    DynamicValue::serialize(stream, context);
    if (pattern)
        pattern->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::PatternHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        pattern = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&pattern, global_document);
    }
}
void HIRMutate::SVG::FeImageHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FeImageHrefValue");
    DynamicValue::serialize(stream, context);
    if (image)
        image->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::FeImageHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        image = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&image, global_document);
    }
}
void HIRMutate::SVG::UseHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("UseHrefValue");
    DynamicValue::serialize(stream, context);
    if (elem)
        elem->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::UseHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
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
void HIRMutate::SVG::GradientHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GradientHrefValue");
    DynamicValue::serialize(stream, context);
    if (gradient)
        gradient->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::GradientHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        gradient = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&gradient, global_document);
    }
}
void HIRMutate::SVG::PathHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("PathHrefValue");
    DynamicValue::serialize(stream, context);
    if (path)
        path->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::PathHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        path = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&path, global_document);
    }
}
void HIRMutate::SVG::CursorHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("CursorHrefValue");
    DynamicValue::serialize(stream, context);
    if (image)
        image->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::CursorHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        image = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&image, global_document);
    }
}
void HIRMutate::SVG::TRefXlinkHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("TRefXlinkHrefValue");
    DynamicValue::serialize(stream, context);
    if (text)
        text->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::TRefXlinkHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        text = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&text, global_document);
    }
}
void HIRMutate::SVG::GlyphRefXlinkHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GlyphRefXlinkHrefValue");
    DynamicValue::serialize(stream, context);
    if (glyph)
        glyph->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::GlyphRefXlinkHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        glyph = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&glyph, global_document);
    }
}
void HIRMutate::SVG::AltGlyphXlinkHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AltGlyphXlinkHrefValue");
    DynamicValue::serialize(stream, context);
    if (glyph)
        glyph->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::AltGlyphXlinkHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        glyph = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&glyph, global_document);
    }
}
void HIRMutate::SVG::FontFaceUriXlinkHrefValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FontFaceUriXlinkHrefValue");
    DynamicValue::serialize(stream, context);
    if (font)
        font->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::FontFaceUriXlinkHrefValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        font = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&font, global_document);
    }
}
void HIRMutate::SVG::GValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("GValue");
    DynamicValue::serialize(stream, context);
    if (glyph)
        glyph->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::GValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        glyph = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&glyph, global_document);
    }
}
void HIRMutate::SVG::InValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("InValue");
    DynamicValue::serialize(stream, context);
    if (filter_primitive)
        filter_primitive->serialize_weak(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::InValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        filter_primitive = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&filter_primitive, global_document);
    }
}
void HIRMutate::SVG::FromValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("FromValue");
    DynamicValue::serialize(stream, context);
    if (value_obj)
        value_obj->serialize(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::SVG::FromValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        value_obj = nullptr;
        stream->skip_string();
    }
    else
    {
        value_obj = value_classes[stream->read_string()](stream, global_document, nullptr);
    }
    value_class = (Value * (*)(void)) value_obj->getConstructor();
}
void HIRMutate::SVG::AnimationValuesValue::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("AnimationValuesValue");
    DynamicValue::serialize(stream, context);
    stream->write_int(value_count);
    std::for_each(value_objs.begin(), value_objs.end(),
                  [&stream, &context](Value *val)
                  {
                      val->serialize(stream, context);
                  });
}
void HIRMutate::SVG::AnimationValuesValue::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    DynamicValue::unserialize(stream, global_document, function);
    int value_count = stream->read_int();
    for (int i = 0; i < value_count; i++)
    {
        Value *val = value_classes[stream->read_string()](stream, global_document, nullptr);
        value_objs.push_back(val);
    }
    value_class = (Value * (*)(void)) value_objs[0]->getConstructor();
}

void *HIRMutate::SVG::XMLNSValue::getConstructor()
{
    return HANDLE_VOID(XMLNSValue);
}
void *HIRMutate::SVG::AlignmentBaselineValue::getConstructor()
{
    return HANDLE_VOID(AlignmentBaselineValue);
}
void *HIRMutate::SVG::ClipRuleValue::getConstructor()
{
    return HANDLE_VOID(ClipRuleValue);
}
void *HIRMutate::SVG::ColorInterpolationValue::getConstructor()
{
    return HANDLE_VOID(ColorInterpolationValue);
}
void *HIRMutate::SVG::RenderingValue::getConstructor()
{
    return HANDLE_VOID(RenderingValue);
}
void *HIRMutate::SVG::EnableBackgroundValue::getConstructor()
{
    return HANDLE_VOID(EnableBackgroundValue);
}
void *HIRMutate::SVG::GlyphRefValue::getConstructor()
{
    return HANDLE_VOID(GlyphRefValue);
}
void *HIRMutate::SVG::UValue::getConstructor()
{
    return HANDLE_VOID(UValue);
}
void *HIRMutate::SVG::UnicodeValue::getConstructor()
{
    return HANDLE_VOID(UnicodeValue);
}
void *HIRMutate::SVG::GlyphOrientationVerticalValue::getConstructor()
{
    return HANDLE_VOID(GlyphOrientationVerticalValue);
}
void *HIRMutate::SVG::NameValue::getConstructor()
{
    return HANDLE_VOID(NameValue);
}
void *HIRMutate::SVG::OffsetValue::getConstructor()
{
    return HANDLE_VOID(OffsetValue);
}
void *HIRMutate::SVG::OverflowValue::getConstructor()
{
    return HANDLE_VOID(OverflowValue);
}
void *HIRMutate::SVG::FeMorphologyOperatorValue::getConstructor()
{
    return HANDLE_VOID(FeMorphologyOperatorValue);
}
void *HIRMutate::SVG::FeCompositeOperatorValue::getConstructor()
{
    return HANDLE_VOID(FeCompositeOperatorValue);
}
void *HIRMutate::SVG::OrderValue::getConstructor()
{
    return HANDLE_VOID(OrderValue);
}
void *HIRMutate::SVG::PointerEventsValue::getConstructor()
{
    return HANDLE_VOID(PointerEventsValue);
}
void *HIRMutate::SVG::ShapeRenderingValue::getConstructor()
{
    return HANDLE_VOID(ShapeRenderingValue);
}
void *HIRMutate::SVG::AnimateFillValue::getConstructor()
{
    return HANDLE_VOID(AnimateFillValue);
}
void *HIRMutate::SVG::StrokeDasharrayValue::getConstructor()
{
    return HANDLE_VOID(StrokeDasharrayValue);
}
void *HIRMutate::SVG::StrokeLinecapValue::getConstructor()
{
    return HANDLE_VOID(StrokeLinecapValue);
}
void *HIRMutate::SVG::StrokeLinejoinValue::getConstructor()
{
    return HANDLE_VOID(StrokeLinejoinValue);
}
void *HIRMutate::SVG::TextAnchorValue::getConstructor()
{
    return HANDLE_VOID(TextAnchorValue);
}
void *HIRMutate::SVG::VectorEffectValue::getConstructor()
{
    return HANDLE_VOID(VectorEffectValue);
}
void *HIRMutate::SVG::WordSpacingValue::getConstructor()
{
    return HANDLE_VOID(WordSpacingValue);
}
void *HIRMutate::SVG::FilterDxValue::getConstructor()
{
    return HANDLE_VOID(FilterDxValue);
}
void *HIRMutate::SVG::DxValue::getConstructor()
{
    return HANDLE_VOID(DxValue);
}
void *HIRMutate::SVG::FormatValue::getConstructor()
{
    return HANDLE_VOID(FormatValue);
}
void *HIRMutate::SVG::AutoWidthValue::getConstructor()
{
    return HANDLE_VOID(AutoWidthValue);
}
void *HIRMutate::SVG::BBoxValue::getConstructor()
{
    return HANDLE_VOID(BBoxValue);
}
void *HIRMutate::SVG::OrientValue::getConstructor()
{
    return HANDLE_VOID(OrientValue);
}
void *HIRMutate::SVG::PanoseValue::getConstructor()
{
    return HANDLE_VOID(PanoseValue);
}
void *HIRMutate::SVG::PointsValue::getConstructor()
{
    return HANDLE_VOID(PointsValue);
}
void *HIRMutate::SVG::PreserveAspectRatioValue::getConstructor()
{
    return HANDLE_VOID(PreserveAspectRatioValue);
}
void *HIRMutate::SVG::MarkerRefXValue::getConstructor()
{
    return HANDLE_VOID(MarkerRefXValue);
}
void *HIRMutate::SVG::SymbolRefXValue::getConstructor()
{
    return HANDLE_VOID(SymbolRefXValue);
}
void *HIRMutate::SVG::RXValue::getConstructor()
{
    return HANDLE_VOID(RXValue);
}
void *HIRMutate::SVG::TableValuesValue::getConstructor()
{
    return HANDLE_VOID(TableValuesValue);
}
void *HIRMutate::SVG::UnicodeRangeValue::getConstructor()
{
    return HANDLE_VOID(UnicodeRangeValue);
}
void *HIRMutate::SVG::ViewBoxValue::getConstructor()
{
    return HANDLE_VOID(ViewBoxValue);
}
void *HIRMutate::SVG::AltGlyphXValue::getConstructor()
{
    return HANDLE_VOID(AltGlyphXValue);
}
void *HIRMutate::SVG::TextXValue::getConstructor()
{
    return HANDLE_VOID(TextXValue);
}
void *HIRMutate::SVG::SpacingValue::getConstructor()
{
    return HANDLE_VOID(SpacingValue);
}
void *HIRMutate::SVG::MethodValue::getConstructor()
{
    return HANDLE_VOID(MethodValue);
}
void *HIRMutate::SVG::SideValue::getConstructor()
{
    return HANDLE_VOID(SideValue);
}
void *HIRMutate::SVG::UnitsValue::getConstructor()
{
    return HANDLE_VOID(UnitsValue);
}
void *HIRMutate::SVG::OrientationValue::getConstructor()
{
    return HANDLE_VOID(OrientationValue);
}
void *HIRMutate::SVG::AltValue::getConstructor()
{
    return HANDLE_VOID(AltValue);
}
void *HIRMutate::SVG::ArabicFormValue::getConstructor()
{
    return HANDLE_VOID(ArabicFormValue);
}
void *HIRMutate::SVG::BaseProfileValue::getConstructor()
{
    return HANDLE_VOID(BaseProfileValue);
}
void *HIRMutate::SVG::EdgeModeValue::getConstructor()
{
    return HANDLE_VOID(EdgeModeValue);
}
void *HIRMutate::SVG::LengthAdjustValue::getConstructor()
{
    return HANDLE_VOID(LengthAdjustValue);
}
void *HIRMutate::SVG::MarkerUnitsValue::getConstructor()
{
    return HANDLE_VOID(MarkerUnitsValue);
}
void *HIRMutate::SVG::SpreadMethodValue::getConstructor()
{
    return HANDLE_VOID(SpreadMethodValue);
}
void *HIRMutate::SVG::StitchTilesValue::getConstructor()
{
    return HANDLE_VOID(StitchTilesValue);
}
void *HIRMutate::SVG::RenderingIntentValue::getConstructor()
{
    return HANDLE_VOID(RenderingIntentValue);
}
void *HIRMutate::SVG::RGBAValue::getConstructor()
{
    return HANDLE_VOID(RGBAValue);
}
void *HIRMutate::SVG::ZoomAndPanValue::getConstructor()
{
    return HANDLE_VOID(ZoomAndPanValue);
}
void *HIRMutate::SVG::DurValue::getConstructor()
{
    return HANDLE_VOID(DurValue);
}
void *HIRMutate::SVG::RestartValue::getConstructor()
{
    return HANDLE_VOID(RestartValue);
}
void *HIRMutate::SVG::RepeatCountValue::getConstructor()
{
    return HANDLE_VOID(RepeatCountValue);
}
void *HIRMutate::SVG::AdditiveValue::getConstructor()
{
    return HANDLE_VOID(AdditiveValue);
}
void *HIRMutate::SVG::AccumulateValue::getConstructor()
{
    return HANDLE_VOID(AccumulateValue);
}
void *HIRMutate::SVG::CalcModeValue::getConstructor()
{
    return HANDLE_VOID(CalcModeValue);
}
void *HIRMutate::SVG::RotateValue::getConstructor()
{
    return HANDLE_VOID(RotateValue);
}
void *HIRMutate::SVG::AnimateTransformTypeValue::getConstructor()
{
    return HANDLE_VOID(AnimateTransformTypeValue);
}
void *HIRMutate::SVG::FeColorMatrixTypeValue::getConstructor()
{
    return HANDLE_VOID(FeColorMatrixTypeValue);
}
void *HIRMutate::SVG::FeFuncTypeValue::getConstructor()
{
    return HANDLE_VOID(FeFuncTypeValue);
}
void *HIRMutate::SVG::FeTurbulenceValue::getConstructor()
{
    return HANDLE_VOID(FeTurbulenceValue);
}
void *HIRMutate::SVG::TransformTranslateValue::getConstructor()
{
    return HANDLE_VOID(TransformTranslateValue);
}
void *HIRMutate::SVG::TransformScaleValue::getConstructor()
{
    return HANDLE_VOID(TransformScaleValue);
}
void *HIRMutate::SVG::TransformRotateValue::getConstructor()
{
    return HANDLE_VOID(TransformRotateValue);
}
void *HIRMutate::SVG::TransformSkewXValue::getConstructor()
{
    return HANDLE_VOID(TransformSkewXValue);
}
void *HIRMutate::SVG::CoordinateValue::getConstructor()
{
    return HANDLE_VOID(CoordinateValue);
}
void *HIRMutate::SVG::PathValue::getConstructor()
{
    return HANDLE_VOID(PathValue);
}
void *HIRMutate::SVG::BufferedRenderingValue::getConstructor()
{
    return HANDLE_VOID(BufferedRenderingValue);
}
void *HIRMutate::SVG::BaselineShiftValue::getConstructor()
{
    return HANDLE_VOID(BaselineShiftValue);
}
void *HIRMutate::SVG::ColorInterpolationFiltersValue::getConstructor()
{
    return HANDLE_VOID(ColorInterpolationFiltersValue);
}
void *HIRMutate::SVG::ColorProfileValue::getConstructor()
{
    return HANDLE_VOID(ColorProfileValue);
}
void *HIRMutate::SVG::DominantBaselineValue::getConstructor()
{
    return HANDLE_VOID(DominantBaselineValue);
}
void *HIRMutate::SVG::FillRuleValue::getConstructor()
{
    return HANDLE_VOID(FillRuleValue);
}
void *HIRMutate::SVG::KerningValue::getConstructor()
{
    return HANDLE_VOID(KerningValue);
}
void *HIRMutate::SVG::PaintOrderValue::getConstructor()
{
    return HANDLE_VOID(PaintOrderValue);
}
void *HIRMutate::SVG::ImageHrefValue::getConstructor()
{
    return HANDLE_VOID(ImageHrefValue);
}
void *HIRMutate::SVG::WhiteSpaceValue::getConstructor()
{
    return HANDLE_VOID(WhiteSpaceValue);
}
void *HIRMutate::SVG::TextOverflowValue::getConstructor()
{
    return HANDLE_VOID(TextOverflowValue);
}
void *HIRMutate::SVG::CrossoriginValue::getConstructor()
{
    return HANDLE_VOID(CrossoriginValue);
}
void *HIRMutate::SVG::TransformValue::getConstructor()
{
    return HANDLE_VOID(TransformValue);
}
void *HIRMutate::SVG::KernelMatrixValue::getConstructor()
{
    return HANDLE_VOID(KernelMatrixValue);
}
void *HIRMutate::SVG::FeColorMatrixValuesValue::getConstructor()
{
    return HANDLE_VOID(FeColorMatrixValuesValue);
}
void *HIRMutate::SVG::SVGElementIDValue::getConstructor()
{
    return HANDLE_VOID(SVGElementIDValue);
}
void *HIRMutate::SVG::FillValue::getConstructor()
{
    return HANDLE_VOID(FillValue);
}
void *HIRMutate::SVG::BeginValue::getConstructor()
{
    return HANDLE_VOID(BeginValue);
}
void *HIRMutate::SVG::MarkerValue::getConstructor()
{
    return HANDLE_VOID(MarkerValue);
}
void *HIRMutate::SVG::PatternHrefValue::getConstructor()
{
    return HANDLE_VOID(PatternHrefValue);
}
void *HIRMutate::SVG::FeImageHrefValue::getConstructor()
{
    return HANDLE_VOID(FeImageHrefValue);
}
void *HIRMutate::SVG::UseHrefValue::getConstructor()
{
    return HANDLE_VOID(UseHrefValue);
}
void *HIRMutate::SVG::GradientHrefValue::getConstructor()
{
    return HANDLE_VOID(GradientHrefValue);
}
void *HIRMutate::SVG::PathHrefValue::getConstructor()
{
    return HANDLE_VOID(PathHrefValue);
}
void *HIRMutate::SVG::CursorHrefValue::getConstructor()
{
    return HANDLE_VOID(CursorHrefValue);
}
void *HIRMutate::SVG::TRefXlinkHrefValue::getConstructor()
{
    return HANDLE_VOID(TRefXlinkHrefValue);
}
void *HIRMutate::SVG::GlyphRefXlinkHrefValue::getConstructor()
{
    return HANDLE_VOID(GlyphRefXlinkHrefValue);
}
void *HIRMutate::SVG::AltGlyphXlinkHrefValue::getConstructor()
{
    return HANDLE_VOID(AltGlyphXlinkHrefValue);
}
void *HIRMutate::SVG::FontFaceUriXlinkHrefValue::getConstructor()
{
    return HANDLE_VOID(FontFaceUriXlinkHrefValue);
}
void *HIRMutate::SVG::GValue::getConstructor()
{
    return HANDLE_VOID(GValue);
}
void *HIRMutate::SVG::InValue::getConstructor()
{
    return HANDLE_VOID(InValue);
}