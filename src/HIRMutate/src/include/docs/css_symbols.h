#ifndef HM_CSS_SYM_H
#define HM_CSS_SYM_H

#include <string>
#include <vector>

using std::string;
using std::vector;

#define CSS_ANIMATABLE_PROPERTIES(v) css_animatable_properties.push_back(v);

namespace HIRMutate
{
    namespace DOC
    {
        namespace CSS
        {
            extern vector<string> css_animatable_properties;
            void initSym();
        }
    }
}

#endif