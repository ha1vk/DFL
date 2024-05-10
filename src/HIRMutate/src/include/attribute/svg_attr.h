#ifndef HM_SVG_ATTR_H
#define HM_SVG_ATTR_H

#include <string>
#include <map>
#include "Value.h"

using HIRMutate::VALUE::Value;
using std::map;
using std::string;

namespace HIRMutate
{
    namespace Attribute
    {
        extern map<string, Value *(*)(void)> aria_attribute_values;
        namespace SVG
        {
            void initialize_svg_attributes();
        }
    }
}

#endif