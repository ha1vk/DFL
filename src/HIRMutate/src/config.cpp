#include "config.h"

namespace HIRMutate
{
    map<string, int> token_limit;
    void initTokenLimit()
    {
        TOKEN_LIMIT("class", 5)
        TOKEN_LIMIT("part", 2)
        TOKEN_LIMIT("keyframes", 5)
        TOKEN_LIMIT("counter", 2)
        TOKEN_LIMIT("mediagroup", 2)
        TOKEN_LIMIT("radiogroup", 2)
        TOKEN_LIMIT("axis", 2)
    }
}

void HIRMutate::Config::init()
{
    initTokenLimit();
    TreeConfig::init();
}

namespace HIRMutate::CSSConfig
{
    int use_css_var = 10;
    int max_css_count = 50;
    int max_css_selector_count = 3;
    int max_css_decl_count = 20;
    int max_css_keyframe_count = 5;
    int max_css_keyframe_decl_count = 5;
    int max_css_internal_decl_count = 5;
}

namespace HIRMutate::TreeConfig
{
    map<string, int> attribute_weight;

    void init()
    {
        attribute_weight["regular"] = 5;
        attribute_weight["presentation"] = 3;
        attribute_weight["global"] = 2;
        attribute_weight["aria"] = 1;
    }
    int max_attribute_count = 10;
    int root_element_count = 10;
    int max_element_count = 80;
    int min_element_count = 40;
    int avg_element_count = 60;
    int max_depth = 3;
}

namespace HIRMutate::JSConfig
{
    int callback_count = 5;
    int max_api_count = 1000;
    int additional_html_var_count = 5;
}