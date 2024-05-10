#include "svg_arg.h"
#include "serialize_variables.h"

HIRMutate::JS::SVGQuerySelectorArg::SVGQuerySelectorArg()
{
    selector = nullptr;
}
HIRMutate::JS::SVGQuerySelectorArg::~SVGQuerySelectorArg()
{
    if (selector)
        delete selector;
}

bool HIRMutate::JS::SVGQuerySelectorArg::is_object()
{
    return false;
}

void HIRMutate::JS::SVGQuerySelectorArg::generate(JSContext *context)
{
    if (selector)
        delete selector;
    selector = CSS::create_css_basic_selector(&DOC::svg_elements);
    selector->generate(context->global_context);
}

bool HIRMutate::JS::SVGQuerySelectorArg::mutate(JSContext *context)
{
    if (Random::gbool())
    {
        // 1. mutate selector value
        return selector->mutate(context->global_context);
    }
    else
    {
        // 2. change to another selector
        generate(context);
        return true;
    }
}

void HIRMutate::JS::SVGQuerySelectorArg::merge_fix(map<Object *, Object *> &merge_map)
{
    selector->merge_fix(merge_map);
}

HIRMutate::JS::SVGQuerySelectorArg::operator string()
{
    string s = "\"";
    s.append(selector->operator string());
    s.append("\"");
    return s;
}
void HIRMutate::JS::SVGQuerySelectorArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SVGQuerySelectorArg");
    Arg::serialize(stream, context);
    selector->serialize(stream, context->global_context);
}
void HIRMutate::JS::SVGQuerySelectorArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    selector = css_selector_classes[stream->read_string()](stream, global_document);
}
void HIRMutate::JS::SVGTagArg::generate(JSContext *context)
{
    vector<string> elems;
    std::for_each(context->global_context->in_tree_set.begin(), context->global_context->in_tree_set.end(),
                  [&elems](const string &elem)
                  {
                      if (DOC::is_svg_element(elem))
                      {
                          elems.push_back(elem);
                      }
                  });
    if (elems.size() == 0)
    {
        value = "svg";
    }
    else
    {
        value = DOC::tag_from_element(CHOICE_OBJ(elems));
    }
}
void HIRMutate::JS::SVGTagArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SVGTagArg");
    StringArg::serialize(stream, context);
}
void HIRMutate::JS::SVGTagArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    StringArg::unserialize(stream, global_document, function, true);
}
HIRMutate::JS::SVGElementIDArg::SVGElementIDArg()
{
    elem = nullptr;
}
bool HIRMutate::JS::SVGElementIDArg::is_object()
{
    return false;
}

void HIRMutate::JS::SVGElementIDArg::generate(JSContext *context)
{
    elem = context->global_context->get_object(DOC::svg_elements);
}

void HIRMutate::JS::SVGElementIDArg::merge_fix(map<Object *, Object *> &merge_map)
{
    if (elem != nullptr)
    {
        if (merge_map.find(elem) != merge_map.end())
            elem = merge_map[elem];
    }
}

HIRMutate::JS::SVGElementIDArg::operator string()
{
    string s = "\"";
    if (elem != nullptr)
        s.append(elem->id);
    else
        s.append("foo");
    s.append("\"");
    return s;
}
void HIRMutate::JS::SVGElementIDArg::serialize(SerializeStream *stream, JSContext *context)
{
    stream->write_string("SVGElementIDArg");
    Arg::serialize(stream, context);
    if (elem != nullptr)
        elem->serialize_weak(stream, ((JSContext *)context)->global_context);
    else
        stream->write_string("nullptr");
}

void HIRMutate::JS::SVGElementIDArg::unserialize(UnSerializeStream *stream, Document *global_document, Function *function)
{
    Arg::unserialize(stream, global_document, function);
    if (stream->peek() == "nullptr")
    {
        elem = nullptr;
        stream->skip_string();
    }
    else
    {
        stream->read_obj_ref((size_t)&elem, global_document);
    }
}