#include "api.h"
#include "html_function.h"
#include "svg_function.h"
#include "html_property.h"
#include "svg_property.h"
#include "serialize_variables.h"

namespace HIRMutate::JS
{
    map<string, vector<APITemplate::ptr> > apis;
}

void HIRMutate::JS::initSym()
{
    initHTMLSym();
    initialize_html_functions();
    initSVGSym();
    initialize_svg_functions();
    initialize_html_properties();
    initialize_svg_properties();
}

HIRMutate::JS::API::API(Ret *ret, Arg *this_obj)
{
    this->ret = ret;
    this->this_obj = this_obj;
#ifdef DEBUG_MEM
    std::cout << "API()" << std::endl;
#endif
}

HIRMutate::JS::API::~API()
{
    if (ret)
        delete ret;
    if (this_obj)
        delete this_obj;
#ifdef DEBUG_MEM
    std::cout << "~API()" << std::endl;
#endif
}

void HIRMutate::JS::API::serialize(SerializeStream *stream, JSContext *context)
{
    if (ret)
        ret->serialize(stream, context);
    else
        stream->write_string("nullptr");
    if (this_obj)
        this_obj->serialize(stream, context);
    else
        stream->write_string("nullptr");
}
void HIRMutate::JS::API::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    if (stream->peek() == "nullptr")
    {
        ret = nullptr;
        stream->skip_string();
    }
    else
    {
        ret = ret_classes[stream->read_string()](stream, function);
    }
    if (stream->peek() == "nullptr")
    {
        this_obj = nullptr;
        stream->skip_string();
    }
    else
    {
        this_obj = arg_classes[stream->read_string()](stream, global_document, function);
    }
}
HIRMutate::JS::APITemplate::APITemplate(Ret *(*ret_class)(), Arg *(*this_class)())
{
    this->ret_class = ret_class;
    this->this_class = this_class;
}

//TODO 优化内存问题
bool HIRMutate::JS::is_satiable_arg(Arg *arg, JSContext *context)
{
    if (arg->name == "")
    {
        return true;
    }
    return context->contains(arg->name);
}

int HIRMutate::JS::get_api_count(const string &name)
{
    return apis[name].size();
}

void HIRMutate::JS::add_api(const APITemplate::ptr &t)
{
    Arg *this_obj = t->this_class();
    string &name = this_obj->name;
    apis[name].push_back(t);
    delete this_obj;
}