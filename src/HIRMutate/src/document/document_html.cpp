#include "document_html.h"
#include "helper.h"
#include "serialize_variables.h"

HIRMutate::Document::Document(int max_element_count)
{
#ifdef DEBUG_MEM
    std::cout << "Document()" << std::endl;
#endif
    dom_tree = new DOMTree(max_element_count);
    dom_context = new DOMContext(token_limit);

    // dummy
    dummy = dom_context->create_object("Dummy");

    // window
    window = Factory::create_object("Window");
    window->id = "window";
    dom_context->add_object(window);

    // document
    document = Factory::create_object("Document");
    document->id = "document";
    dom_context->add_object(document);

    // entry point
    main = (Function *)Factory::create_object("Function");
    main->id = "main";
    dom_context->add_object(main);

    // event handlers
    for (int i = 0; i < JSConfig::callback_count; i++)
    {
        EventHandler *eh = (EventHandler *)Factory::create_object("EventHandler");
        eh->id = "f" + std::to_string(i);
        dom_context->add_object(eh);
        event_handlers.push_back(eh);
    }

    // css
    sheet0 = Factory::create_object("CSSStyleSheet");
    sheet0->id = "sheet0";
    dom_context->add_object(sheet0);
    sheet1 = Factory::create_object("CSSKeyframesSheet");
    sheet1->id = "sheet1";
    dom_context->add_object(sheet1);

    css = new Document_CSS();
    css->init_keyframes(dom_context);
    css->init_css_variables(dom_context);

    // init function context
    main->init(dom_context);
    std::for_each(event_handlers.begin(), event_handlers.end(),
                  [this](EventHandler *eh)
                  {
                      eh->init(this->dom_context);
                  });
}

HIRMutate::Document::~Document()
{
    if (dom_tree)
        delete dom_tree;
    if (window)
        delete window;
    if (document)
        delete document;
    if (main)
        delete main;
    std::for_each(event_handlers.begin(), event_handlers.end(),
                  [](EventHandler *eh)
                  {
                      delete eh;
                  });
    if (sheet0)
        delete sheet0;
    if (sheet1)
        delete sheet1;
    if (css)
        delete css;
    if (dom_context)
        delete dom_context;

    if (dummy)
        delete dummy;

#ifdef DEBUG_MEM
    std::cout << "~Document()" << std::endl;
#endif
}
/*
* For dumb fuzz
*/
void HIRMutate::Document::generate_nodes()
{
    dom_tree->generate_nodes(dom_context);
}

void HIRMutate::Document::generate_attributes()
{
    dom_tree->generate_attributes(dom_context);
}

void HIRMutate::Document::generate_css_rules()
{
    css->generate_css_rules(dom_context);
}

void HIRMutate::Document::generate_js_functions()
{
    main->generate_additional_elements();
    main->generate_apis();
    std::for_each(event_handlers.begin(), event_handlers.end(),
                  [](EventHandler *eh)
                  {
                      eh->generate_additional_elements();
                      eh->generate_apis();
                  });
}

/*
* For cov fuzz
*/
bool HIRMutate::Document::insert_node()
{
    Object *element = nullptr;
    if (Random::selector(dom_tree->element_count + 1) == 0)
        element = dom_tree->insert_root_element(dom_context);
    else
        element = dom_tree->insert_element(dom_context);
    return element != nullptr;
}

namespace HIRMutate
{
    typedef enum DOMTreeMode
    {
        InsertNode = 1,
        AppendAttribute = 2,
        MutateAttribute = 3,
        ReplaceAttribute = 4,
        MutateText = 5
    } DOMTreeMode;
    const int dom_tree_modes[] = {
        InsertNode,
        AppendAttribute,
        MutateAttribute,
        ReplaceAttribute,
        MutateText};
    enum CSSMode
    {
        Mutate = 1,
        Append = 2,
        Replace = 3,
        Misc = 4
    };
    const int css_modes[] = {Mutate, Append, Replace, Misc};
}

bool HIRMutate::Document::fuzz_dom_tree()
{
    vector<int> weights = {3, 3, 2, 5, 1};
    int trial = 0;
    while (trial < 10)
    {
        int c = CHOICE_W(dom_tree_modes, weights);
        bool ok = false;
        switch (c)
        {
        case InsertNode:
            ok = insert_node();
            break;
        case AppendAttribute:
            ok = dom_tree->append_attribute(dom_context);
            break;
        case MutateAttribute:
            ok = dom_tree->mutate_attribute(dom_context);
            break;
        case ReplaceAttribute:
            ok = dom_tree->replace_attribute(dom_context);
            break;
        default:
            ok = dom_tree->mutate_text();
            break;
        }
        if (ok)
            return true;
        trial++;
    }
    return false;
}

bool HIRMutate::Document::fuzz_css()
{
    vector<int> css_weights = {10, 5, 1, 1};
    int trial = 0;
    while (trial < 10)
    {
        int c = CHOICE_W(css_modes, css_weights);
        bool ok = false;
        switch (c)
        {
        case Mutate:
            ok = css->mutate_css_style_rule(dom_context);
            break;
        case Append:
            ok = css->append_css_style_rule(dom_context);
            break;
        case Replace:
            ok = css->replace_css_style_rule(dom_context);
            break;
        default:
            if (Random::gbool())
                ok = css->mutate_css_keyframes_rule(dom_context);
            else
                ok = css->mutate_css_variable(dom_context);
            break;
        }
        if (ok)
            return true;
        trial++;
    }
    return false;
}

bool HIRMutate::Document::fuzz_js_functions()
{
    int trial = 0;
    while (trial < 10)
    {
        Function *target_func;
        if (Random::gbool())
            target_func = main;
        else
            target_func = CHOICE_OBJ(event_handlers);
        int c = Random::selector(4);
        bool ok = false;
        if (c == 0)
            ok = target_func->append_api();
        else if (c == 1)
            ok = target_func->insert_api();
        else if (c == 2)
            ok = target_func->replace_api();
        else
            ok = target_func->mutate_api();
        if (ok)
            return true;
        trial++;
    }
    return false;
}

#define MERGE_MAP(k, v) merge_map[k] = v;

bool HIRMutate::Document::merge(Document *other)
{
    if (!dom_tree->allow_merge())
        return false;
    map<Object *, Object *> merge_map;
    MERGE_MAP(window, window)
    MERGE_MAP(document, document)
    MERGE_MAP(sheet0, sheet0)
    MERGE_MAP(sheet1, sheet1)
    int len = event_handlers.size();
    for (int i = 0; i < len; i++)
    {
        merge_map[other->event_handlers[i]] = event_handlers[i];
    }

    vector<Element *> merge_inserts = dom_tree->merge(dom_context, other->dom_tree, merge_map);
    std::for_each(merge_map.begin(), merge_map.end(),
                  [&merge_map](map<Object *, Object *>::reference i)
                  {
                      Object *element = i.second;
                      if (element->is_element())
                      {
                          Element *ele = (Element *)element;
                          if (ele->is_in_tree())
                              ele->merge_fix(merge_map);
                      }
                  });
    std::for_each(merge_inserts.begin(), merge_inserts.end(),
                  [&merge_map](Element *element)
                  {
                      element->merge_fix(merge_map);
                  });
    if (css->allow_merge())
        css->merge(other->css, merge_map);

    main->merge(other->main, merge_map);

    for (int i = 0; i < len; i++)
    {
        event_handlers[i]->merge(other->event_handlers[i], merge_map);
    }
    return true;
}

HIRMutate::Document::operator string()
{
    string head = "<head>\n";
    head.append(css->operator string());

    head.append("<script>\n");
    head.append(do_nothing);
    head.append("\n");
    head.append(gc);
    head.append("\n");

    head.append("var run_count = { \"main\": 0, ");
    int len = event_handlers.size();
    for (int i = 0; i < len; i++)
    {
        head.append("\"");
        head.append(event_handlers[i]->id);
        head.append("\": 0, ");
    }
    head.append("};\n");
    head.append(main->operator string());
    for (int i = 0; i < len; i++)
    {
        head.append(event_handlers[i]->operator string());
    }
    head.append("</script>\n");
    head.append("</head>\n\n");

    string body = "<body onload=\"";
    body.append(main->id);
    body.append("()\">\n");
    body.append(dom_tree->operator string());
    body.append("</body>\n\n");

    string html = "<!DOCTYPE html>\n<html>\n\n";
    html.append(head);
    html.append(body);
    html.append("</html>\n");
    return html;
}
//对于在object_pool中的对象，在外部都以week形式进行序列化
void HIRMutate::Document::serialize(SerializeStream *stream)
{
    stream->write_string(label);
    dom_context->serialize(stream, dom_context);
    dom_tree->serialize(stream, dom_context);
    dummy->serialize_weak(stream, dom_context);
    window->serialize_weak(stream, dom_context);
    document->serialize_weak(stream, dom_context);
    main->serialize_weak(stream, dom_context);
    stream->write_int(event_handlers.size());
    std::for_each(event_handlers.begin(), event_handlers.end(),
                  [&stream, this](EventHandler *eh)
                  {
                      eh->serialize_weak(stream, this->dom_context);
                  });
    sheet0->serialize_weak(stream, dom_context);
    sheet1->serialize_weak(stream, dom_context);
    css->serialize(stream, dom_context);
}

void HIRMutate::Document::unserialize(UnSerializeStream *stream)
{
    label = stream->read_string();
    dom_context = new DOMContext();
    dom_context->unserialize(stream, this);
    dom_tree = new DOMTree();
    dom_tree->unserialize(stream, this);
    stream->read_obj_ref((size_t)&dummy, this);
    stream->read_obj_ref((size_t)&window, this);
    stream->read_obj_ref((size_t)&document, this);
    stream->read_obj_ref((size_t)&main, this);
    int event_handlers_size = stream->read_int();
    event_handlers.resize(event_handlers_size);
    for (int i = 0; i < event_handlers_size; i++)
    {
        stream->read_obj_ref((size_t)&event_handlers[i], this);
    }
    stream->read_obj_ref((size_t)&sheet0, this);
    stream->read_obj_ref((size_t)&sheet1, this);
    css = new Document_CSS();
    css->unserialize(stream, this);

    //文件反序列化完毕，接下来修复所有引用
    std::for_each(weak_reference_objs.begin(), weak_reference_objs.end(),
                  [this](map<size_t, std::pair<string, int> >::reference i)
                  {
                      size_t *ptr_addr = (size_t *)(i.first);
                      std::pair<string, int> &p = i.second;
                      *ptr_addr = (size_t)(dom_context->object_pool->pool[p.first][p.second]);
                  });
}