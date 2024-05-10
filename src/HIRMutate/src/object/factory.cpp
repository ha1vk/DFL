#include "factory.h"
#include <memory>

HIRMutate::Function *HIRMutate::Factory::create_function()
{
    return new Function();
}

HIRMutate::EventHandler *HIRMutate::Factory::create_event_handler()
{
    return new EventHandler();
}

HIRMutate::Object *HIRMutate::Factory::create_object(const string &name)
{
    if (find(DOC::svg_elements.begin(), DOC::svg_elements.end(), name) != DOC::svg_elements.end())
        return SVGElement::create(name);
    else if (find(DOC::html_elements.begin(), DOC::html_elements.end(), name) != DOC::html_elements.end())
        return HTMLElement::create(name);
    else if (name == "Function")
        return create_function();
    else if (name == "EventHandler")
        return create_event_handler();
    else if (name == "Dummy")
        return new Object("Dummy", "dummy");
    else
        return new Object(name);
}