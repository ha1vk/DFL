#ifndef CSS_PROP_H
#define CSS_PROP_H

#include <map>
#include <string>
#include "Value.h"
#include "docs.h"
#include <utility>

namespace HIRMutate::VALUE
{
    class Value;
}
using HIRMutate::VALUE::Value;
using std::map;
using std::string;

#define CSS_PROPERTIES(k, v) \
    css_properties[k] = v;   \
    css_properties_key.push_back(k);

namespace HIRMutate
{
    namespace CSS
    {
        extern map<string, Value *(*)(void)> css_properties;
        extern vector<string> css_properties_key;
        void initSym();
        std::pair<string, Value *(*)(void)> get_css_property(bool animatable = false);
        void *get_css_property_value(const string &prop);
        string &get_css_property_name();
        void init();
    }
}

#endif