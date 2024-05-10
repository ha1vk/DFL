#ifndef HM_HTML_ATTR_H
#define HM_HTML_ATTR_H

#include <string>
#include <map>
#include "Value.h"

using HIRMutate::VALUE::Value;
using std::map;
using std::string;

#define ARIA_ATTRIBUTE_VALUES(k, v) aria_attribute_values[k] = v;

namespace HIRMutate
{
    namespace Attribute
    {
        extern map<string, Value *(*)(void)> aria_attribute_values;
        namespace HTML
        {
            void initialize_html_attributes();
        }
    }
}
#endif
