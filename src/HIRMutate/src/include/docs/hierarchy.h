#ifndef HM_HIERARCHY_H
#define HM_HIERARCHY_H

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

#define OFFSPRINGS(k, v...) offsprings[k] = vector<string>(v);
#define ANCESTORS(k, v...) ancestors[k] = vector<string>(v);

namespace HIRMutate
{
    namespace DOC
    {
        namespace HIERARCHY
        {
            extern map<string, vector<string> > offsprings;
            extern map<string, vector<string> > ancestors;
            void initSym();
        }
    }
}
#endif