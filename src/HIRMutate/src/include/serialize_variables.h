#ifndef HM_SERIALIZE_VARIABLES_H
#define HM_SERIALIZE_VARIABLES_H

#include "attribute.h"
#include "object.h"
#include "css_selector.h"
#include "arg.h"
#include "ret.h"
#include "api.h"
#include "document_html.h"

namespace HIRMutate
{
    extern map<string, Object *(*)(UnSerializeStream *, Document *)> obj_classes;
    extern map<string, VALUE::Value *(*)(UnSerializeStream *, Document *, Function *)> value_classes;
    extern map<string, CSS::CSSSelector *(*)(UnSerializeStream *, Document *)> css_selector_classes;
    extern map<string, JS::Arg *(*)(UnSerializeStream *, Document *, Function *)> arg_classes;
    extern map<string, JS::Ret *(*)(UnSerializeStream *, Function *)> ret_classes;
    extern map<string, JS::API *(*)(UnSerializeStream *, Document *, Function *)> api_classes;
    void initClasses();
}
#endif