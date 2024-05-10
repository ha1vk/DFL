#ifndef HM_CONFIG_H
#define HM_CONFIG_H

#include <map>
#include <string>

using std::map;
using std::string;

#define TOKEN_LIMIT(k, v) token_limit[k] = v;

namespace HIRMutate
{
    extern map<string, int> token_limit;
    void initTokenLimit();
    namespace Config
    {
        void init();
    }
    namespace CSSConfig
    {
        extern int use_css_var;
        extern int max_css_count;
        extern int max_css_selector_count;
        extern int max_css_decl_count;
        extern int max_css_keyframe_count;
        extern int max_css_keyframe_decl_count;
        extern int max_css_internal_decl_count;
    }

    namespace TreeConfig
    {
        extern map<string, int> attribute_weight;

        void init();

        extern int max_attribute_count;
        extern int root_element_count;
        extern int max_element_count;
        extern int min_element_count;
        extern int avg_element_count;
        extern int max_depth;
    }

    namespace JSConfig
    {
        extern int callback_count;
        extern int max_api_count;
        extern int additional_html_var_count;
    }
}
#endif