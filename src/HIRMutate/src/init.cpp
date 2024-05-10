#include "random.h"
#include "config.h"
#include "docs.h"
#include "css_properties.h"
#include "api.h"
#include "dom_tree.h"
#include "serialize_variables.h"
#include "init.h"

using namespace HIRMutate;

void HIRMutate::init()
{
    Random::init();
    Config::init();
    //顺序不能变
    DOC::init();
    CSS::init();
    Attribute::init();
    JS::initSym();
    initMerge_blacklist();
    initClasses();
}