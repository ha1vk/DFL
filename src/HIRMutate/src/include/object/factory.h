#ifndef HM_FACTORY_H
#define HM_FACTORY_H

#include "object.h"
#include "function.h"
#include "docs.h"
#include "svg_obj.h"

namespace HIRMutate
{
    namespace Factory
    {
        Function *create_function();
        EventHandler *create_event_handler();
        Object *create_object(const string &name);
    }

}
#endif