#include "function.h"
#include "serialize_variables.h"

string HIRMutate::try_catch(const string &s)
{
    // return "try {{ {}; }} catch (e) {{ console.log(e.message); }}\n".format(s)
    string ans = "try {";
    ans.append(s);
    ans.append("; } catch (e) { }\n");
    return ans;
}

HIRMutate::Function::Function(const string &name, bool is_callback) : Object(name)
{
    this->is_callback = is_callback;
    this->context = nullptr;
}

HIRMutate::Function::~Function()
{
    if (context)
    {
        delete context;
        context = nullptr;
    }
    std::for_each(apis.begin(), apis.end(),
                  [](JS::API *api)
                  {
                      delete api;
                  });
}

int HIRMutate::Function::api_count()
{
    return apis.size();
}

bool HIRMutate::Function::full()
{
    return api_count() >= JSConfig::max_api_count;
}

void HIRMutate::Function::init(DOMContext *dom_context)
{
    if (context)
    {
        delete context;
    }
    context = new JSContext(dom_context);
}

void HIRMutate::Function::generate_additional_elements()
{
    for (int i = 0; i < JSConfig::additional_html_var_count; i++)
    {
        apis.push_back(JS::create_interesting_html_element(context));
        context->line++;
    }
}

HIRMutate::JS::API *HIRMutate::Function::generate_api()
{
    // 1. select an alive object (type)
    set<string> &obj_names = context->superset_at_line_che();
    vector<int> weights(obj_names.size());
    int idx = 0;
    std::for_each(obj_names.begin(), obj_names.end(),
                  [&weights, &idx](const string &name)
                  {
                      weights[idx++] = JS::get_api_count(name);
                  });

    // 2. select an api that uses the object name as |this|
    while (true)
    {
        //string &name = CHOICE_W(obj_names, weights);
        const string &name = Random::choice_set(obj_names, &weights);
        JS::APITemplate::ptr a_template = CHOICE_OBJ(JS::apis[name]);
        if (a_template->satiable(context))
        {
            JS::API *api = a_template->instantiate();
            api->generate(context);
            return api;
        }
    }
}

/*
    * For dumb fuzz
    */
void HIRMutate::Function::generate_apis()
{
    int count;
    if (!is_callback)
        count = JSConfig::max_api_count;
    else
        count = JSConfig::max_api_count / 2;
    for (int i = 0; i < count; i++)
        append_api();
}

/*
    * For cov fuzz
    */
// A1
bool HIRMutate::Function::append_api()
{
    if (full())
        return false;
    context->line = apis.size();
    JS::API *api = generate_api();
    apis.push_back(api);
    return true;
}

// A2
bool HIRMutate::Function::insert_api()
{
    int line = Random::selector(api_count() + 1);
    context->shift_object_location(line);
    context->line = line;
    JS::API *api = generate_api();
    apis.insert(apis.begin() + line, api);
    return true;
}

// A3
bool HIRMutate::Function::replace_api()
{
    if (api_count() == 0)
        return false;
    int trial = 0;
    while (trial < api_count())
    {
        int line = Random::selector(api_count());
        context->line = line;
        JS::API *old_api = apis[line];
        if (old_api->ret == nullptr)
        {
            delete old_api;
            JS::API *new_api = generate_api();
            apis[line] = new_api;
            return true;
        }
        trial++;
    }
    return false;
}

// A4
bool HIRMutate::Function::mutate_api()
{
    if (api_count() == 0)
        return false;
    int line = Random::selector(api_count());
    context->line = line;
    JS::API *api = apis[line];
    return api->mutate(context);
}

void HIRMutate::Function::merge_api(JS::API *api, int line)
{
    context->line = line;
    context->shift_object_location(line);
    apis.insert(apis.begin() + line, api);
    if (api->ret != nullptr)
        api->ret->merge_fix(context);
}

void HIRMutate::Function::merge(Function *other, map<Object *, Object *> &merge_map)
{
    int p, q;
    p = q = 0;
    while (p < api_count() && q < other->api_count())
    {
        if (Random::gbool())
        {
            p++;
            continue;
        }

        JS::API *other_api = other->apis[q];
        other_api->merge_fix(merge_map);
        merge_api(other_api, p);
        p++;
        q++;
    }
    int o_c = other->api_count();
    if (q < o_c)
    {
        for (int i = q; i < o_c; i++)
        {
            merge_api(other->apis[i], p);
            p++;
        }
    }
}

HIRMutate::Function::operator string()
{
    string s = "function ";
    s.append(id);
    s.append("() {\n\n");

    s.append("run_count[\"");
    s.append(id);
    s.append("\"]++;\n");
    s.append("if (run_count[\"");
    s.append(id);
    s.append("\"] > 2) return;\n\n");

    vector<Object *> elements = context->global_context->in_tree_elements();
    std::for_each(elements.begin(), elements.end(),
                  [&s](Object *obj)
                  {
                      s.append("var ");
                      s.append(obj->id);
                      s.append(" = document.getElementById(\"");
                      s.append(obj->id);
                      s.append("\");\n");
                  });
    // include all elements from dom tree
    s.append(try_catch("var sheet0 = document.styleSheets[0]"));
    s.append(try_catch("var sheet1 = document.styleSheets[1]"));

    std::for_each(apis.begin(), apis.end(),
                  [&s](JS::API *api)
                  {
                      s.append(try_catch(api->operator string()));
                  });

    s.append("gc();\n");
    s.append("console.log(\"SYNTAX OK\");"); //为了完成有效性实验。
    s.append("}\n");
    return s;
}

HIRMutate::EventHandler::EventHandler() : Function("EventHandler", true) {}

void HIRMutate::Function::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("Function");
    Object::serialize(stream, context);
    stream->write_byte(is_callback);
    stream->write_int(apis.size());
    std::for_each(apis.begin(), apis.end(),
                  [&stream, &context, this](JS::API *api)
                  {
                      api->serialize(stream, this->context);
                  });
    this->context->serialize(stream, this->context);
}

void HIRMutate::Function::unserialize(UnSerializeStream *stream, Document *global_document)
{
    Object::unserialize(stream, global_document, true);
    is_callback = stream->read_byte();
    int apis_size = stream->read_int();
    for (int i = 0; i < apis_size; i++)
    {
        JS::API *api = api_classes[stream->read_string()](stream, global_document, this);
        apis.push_back(api);
    }
    this->context = new JSContext();
    this->context->global_context = global_document->dom_context;
    this->context->unserialize(stream, global_document);
    //文件反序列化完毕，接下来修复所有引用
    std::for_each(weak_reference_objs.begin(), weak_reference_objs.end(),
                  [this](map<size_t, std::pair<string, int> >::reference i)
                  {
                      size_t *ptr_addr = (size_t *)(i.first);
                      std::pair<string, int> &p = i.second;
                      *ptr_addr = (size_t)(context->object_pool->pool[p.first][p.second]);
                  });
}