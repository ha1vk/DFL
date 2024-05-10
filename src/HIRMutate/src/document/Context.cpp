#include "Context.h"
#include "factory.h"
#include "docs.h"
#include "serialize_variables.h"
#include <assert.h>

HIRMutate::ObjectPool::ObjectPool(const string &prefix)
{
    count = 0;
    this->prefix = prefix;
#ifdef DEBUG_MEM
    std::cout << "ObjectPool(" << prefix << ")" << std::endl;
#endif
}

HIRMutate::ObjectPool::~ObjectPool()
{
#ifdef DEBUG_MEM
    std::cout << "~ObjectPool(" << prefix << ")" << std::endl;
#endif
    std::for_each(objs_need_to_be_free_at_last.begin(), objs_need_to_be_free_at_last.end(),
                  [](Object *obj)
                  {
                      delete obj;
                  });
}

vector<vector<HIRMutate::Object *> > HIRMutate::ObjectPool::objects()
{
    vector<vector<Object *> > vec;
    std::for_each(pool.begin(), pool.end(),
                  [&vec](map<string, vector<Object *> >::reference i)
                  {
                      vec.push_back(i.second);
                  });
    return vec;
}

vector<HIRMutate::Object *> &HIRMutate::ObjectPool::get(const string &name)
{
    return pool[name];
}

string HIRMutate::ObjectPool::create_id()
{
    count++;
    string ans = prefix;
    ans.append(std::to_string(count));
    return ans;
}

void HIRMutate::ObjectPool::add(Object *o, bool verify_unique)
{
    // add into pool
    string &name = o->name;
    // naming
    if (o->id == "")
        o->id = create_id();
    if (verify_unique) //检查该obj是否已经存在
    {
        vector<Object *> &vec = pool[name];
        int len = vec.size();
        for (int i = 0; i < len; i++)
        {
            Object *obj = vec[i];
            if (o == obj)
            {
                return;
            }
        }
    }
    pool[name].push_back(o);
}

HIRMutate::Context::Context(const string &prefix)
{
    object_pool = new ObjectPool(prefix);
}

HIRMutate::Context::~Context()
{
    delete object_pool;
}

// Object
HIRMutate::Object *HIRMutate::Context::create_object(const string &name)
{
    Object *o = Factory::create_object(name);
    add_object(o);
    return o;
}
void HIRMutate::Context::add_object(Object *o, bool verify_unique)
{
    object_pool->add(o, verify_unique);
}

void HIRMutate::Context::set_object_to_be_handled(Object *obj)
{
    object_pool->objs_need_to_be_free_at_last.push_back(obj);
}

//fixme :maybe null,need return a empty object
HIRMutate::Object *HIRMutate::Context::get_object(vector<string> &names)
{
    vector<Object *> objs = get_objects(names);
    if (objs.size() == 0)
    {
        return nullptr;
    }
    return CHOICE_OBJ(objs);
}

HIRMutate::Object *HIRMutate::Context::get_object(const string &name)
{
    vector<Object *> objs = object_pool->get(name);
    if (objs.size() == 0)
    {
        return nullptr;
    }
    return CHOICE_OBJ(objs);
}

HIRMutate::DOMContext::~DOMContext()
{
#ifdef DEBUG_MEM
    std::cout << "~DOMContext()" << std::endl;
#endif
}
HIRMutate::DOMContext::DOMContext(map<string, int> &token_limit) : Context("x")
{
    this->token_limit = token_limit;
    this->need_update_superset_line_cache = false;
}

vector<HIRMutate::Object *> HIRMutate::DOMContext::in_tree_elements()
{
    vector<Object *> vec;
    vector<vector<Object *> > objects = object_pool->objects();
    std::for_each(objects.begin(), objects.end(),
                  [&vec](vector<Object *> &values)
                  {
                      std::for_each(values.begin(), values.end(),
                                    [&vec](Object *obj)
                                    {
                                        if (obj->is_element())
                                        {
                                            vec.push_back(obj);
                                        }
                                    });
                  });
    return vec;
}
// Token
string HIRMutate::DOMContext::get_token(const string &token)
{
    string ans = token;
    ans.append(std::to_string(Random::selector(token_limit[token])));
    return ans;
}

vector<string> HIRMutate::DOMContext::get_tokens(const string &token)
{
    vector<string> vec;
    string ans;
    for (int i = 0; i < token_limit[token]; i++)
    {
        ans = token;
        ans.append(std::to_string(i));
        vec.push_back(ans);
    }
    return vec;
}

void HIRMutate::DOMContext::add_object(Object *o, bool verify_unique)
{
    Context::add_object(o, verify_unique);

    //update superset
    vector<string> ancestors = DOC::get_object_ancestors(o->name);
    std::for_each(ancestors.begin(), ancestors.end(),
                  [this](string &ancestor)
                  {
                      if (this->superset.find(ancestor) == this->superset.end())
                      {
                          this->superset.insert(ancestor);
                          this->superset_at_line_cache.insert(ancestor);
                      }
                  });
    // update in-tree element
    if (o->is_element())
        in_tree_set.insert(o->name);
}
vector<HIRMutate::Object *> HIRMutate::DOMContext::get_objects(vector<string> &names)
{
    vector<Object *> vec;
    std::for_each(names.begin(), names.end(),
                  [&vec, this](string &name)
                  {
                      vector<Object *> &objs = this->object_pool->get(name);
                      std::for_each(objs.begin(), objs.end(),
                                    [&vec](Object *val)
                                    {
                                        vec.push_back(val);
                                    });
                  });
    return vec;
}

HIRMutate::JSContext::JSContext(DOMContext *global_context) : Context("v")
{
    line = 0;
    this->global_context = global_context;
#ifdef DEBUG_MEM
    std::cout << "JSContext()" << std::endl;
#endif
}

HIRMutate::JSContext::~JSContext()
{
#ifdef DEBUG_MEM
    std::cout << "~JSContext()" << std::endl;
#endif
}

set<string> HIRMutate::JSContext::superset_at_line()
{
    set<string> ans = global_context->superset;
    std::for_each(superset.begin(), superset.end(),
                  [&ans, this](map<string, int>::reference i)
                  {
                      if (i.second < this->line)
                      {
                          ans.insert(i.first);
                      }
                  });
    return ans;
}
set<string> &HIRMutate::JSContext::superset_at_line_che()
{
    if (global_context->need_update_superset_line_cache)
    {
        global_context->superset_at_line_cache = superset_at_line();
        global_context->need_update_superset_line_cache = false;
    }
    return global_context->superset_at_line_cache;
}

void HIRMutate::JSContext::add_object(Object *o, bool verify_unique)
{
    Context::add_object(o, verify_unique);

    // update superset
    vector<string> ancestors = DOC::get_object_ancestors(o->name);
    std::for_each(ancestors.begin(), ancestors.end(),
                  [this](string &ancestor)
                  {
                      if (this->superset.find(ancestor) == this->superset.end())
                      {
                          this->superset[ancestor] = this->line;
                          global_context->superset_at_line_cache.insert(ancestor);
                      }
                  });

    //update location
    locations[o->id] = line;
}

vector<HIRMutate::Object *> HIRMutate::JSContext::get_objects(vector<string> &names)
{
    vector<Object *> global_objects = global_context->get_objects(names);
    vector<Object *> local_objects;
    std::for_each(names.begin(), names.end(),
                  [&local_objects, this](string &name)
                  {
                      vector<Object *> &objs = this->object_pool->get(name);
                      std::for_each(objs.begin(), objs.end(),
                                    [&local_objects](Object *val)
                                    {
                                        local_objects.push_back(val);
                                    });
                  });
    std::for_each(local_objects.begin(), local_objects.end(),
                  [&global_objects, this](Object *obj)
                  {
                      if (this->locations[obj->id] < this->line)
                      {
                          global_objects.push_back(obj);
                      }
                  });
    return global_objects;
}
vector<HIRMutate::Object *> HIRMutate::JSContext::get_offsprings(const string &name)
{
    vector<string> names = DOC::get_object_offsprings(name);
    return get_objects(names);
}

HIRMutate::Object *HIRMutate::JSContext::get_offspring(const string &name)
{
    vector<Object *> objs = get_offsprings(name);
    if (objs.size() == 0)
    {
        return nullptr;
    }
    return CHOICE_OBJ(objs);
}

bool HIRMutate::JSContext::contains(const string &name)
{
    return (global_context->superset.find(name) != global_context->superset.end()) ||
           (superset.find(name) != superset.end() && superset[name] < line);
}

void HIRMutate::JSContext::shift_object_location(int begin)
{
    std::for_each(locations.begin(), locations.end(),
                  [&begin, this](map<string, int>::reference i)
                  {
                      if (i.second >= begin)
                      {
                          this->locations[i.first] += 1;
                      }
                  });
    std::for_each(superset.begin(), superset.end(),
                  [&begin, this](map<string, int>::reference i)
                  {
                      if (i.second >= begin)
                      {
                          this->superset[i.first] += 1;
                          global_context->need_update_superset_line_cache = true;
                      }
                  });
}

void HIRMutate::ObjectPool::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string(prefix);
    stream->write_int(count);
    stream->write_int(pool.size());
    std::for_each(pool.begin(), pool.end(),
                  [&stream, &context](map<string, vector<Object *> >::reference i)
                  {
                      stream->write_string(i.first);
                      vector<Object *> &vec = i.second;
                      stream->write_int(vec.size());
                      std::for_each(vec.begin(), vec.end(),
                                    [&stream, &context](Object *obj)
                                    {
                                        obj->serialize(stream, context);
                                    });
                  });
    stream->write_int(objs_need_to_be_free_at_last.size());
    std::for_each(objs_need_to_be_free_at_last.begin(), objs_need_to_be_free_at_last.end(),
                  [&stream, &context](Object *obj)
                  {
                      obj->serialize_weak(stream, context);
                  });
}

void HIRMutate::ObjectPool::unserialize(UnSerializeStream *stream, Document *global_document)
{
    prefix = stream->read_string();
    count = stream->read_int();
    int pool_size = stream->read_int();
    for (int i = 0; i < pool_size; i++)
    {
        string element = stream->read_string();
        int objs_count = stream->read_int();
        for (int j = 0; j < objs_count; j++)
        {
            //std::cout << objs_count << " " << i << " " << stream->peek() << std::endl;
            pool[element].push_back(obj_classes[stream->read_string()](stream, global_document));
        }
    }
    int h_size = stream->read_int();
    objs_need_to_be_free_at_last.resize(h_size);
    for (int i = 0; i < h_size; i++)
    {
        string name = stream->read_string();
        int idx = stream->read_int();
        objs_need_to_be_free_at_last[i] = pool[name][idx];
    }
}

void HIRMutate::Context::serialize(SerializeStream *stream, Context *context)
{
    object_pool->serialize(stream, context);
}

void HIRMutate::Context::unserialize(UnSerializeStream *stream, Document *global_document)
{
    object_pool = new ObjectPool();
    object_pool->unserialize(stream, global_document);
}

std::pair<string, int> HIRMutate::Context::find_obj_in_pool(Object *obj)
{
    map<string, vector<Object *> > &pool = object_pool->pool;
    string pool_tag = "";
    int idx = -1;
    map<string, vector<Object *> >::iterator m_it = pool.begin();
    vector<Object *>::iterator v_it;
    while (m_it != pool.end())
    {
        map<string, vector<Object *> >::reference i = *m_it;
        pool_tag = i.first;
        idx = -1;
        vector<Object *> &vec = i.second;
        v_it = vec.begin();
        while (v_it != vec.end())
        {
            idx++;
            Object *val = *v_it;
            if (val == obj)
            {
                return std::make_pair(pool_tag, idx);
            }
            v_it++;
        }
        m_it++;
    }
    //not found
    return std::make_pair(pool_tag, -1);
}

void HIRMutate::DOMContext::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("DOMContext");
    Context::serialize(stream, context);
    stream->write_int(superset.size());
    std::for_each(superset.begin(), superset.end(),
                  [&stream](const string &val)
                  {
                      stream->write_string(val);
                  });
    stream->write_int(token_limit.size());
    std::for_each(token_limit.begin(), token_limit.end(),
                  [&stream](map<string, int>::reference i)
                  {
                      stream->write_string(i.first);
                      stream->write_int(i.second);
                  });
    stream->write_int(in_tree_set.size());
    std::for_each(in_tree_set.begin(), in_tree_set.end(),
                  [&stream](const string &val)
                  {
                      stream->write_string(val);
                  });
    stream->write_byte(need_update_superset_line_cache);
    stream->write_int(superset_at_line_cache.size());
    std::for_each(superset_at_line_cache.begin(), superset_at_line_cache.end(),
                  [&stream](const string &val)
                  {
                      stream->write_string(val);
                  });
}

void HIRMutate::DOMContext::unserialize(UnSerializeStream *stream, Document *global_document)
{
    if (stream->read_string() != "DOMContext")
    {
        printf("[DOMContext] unserialize error!\n");
        abort();
    }
    Context::unserialize(stream, global_document);
    int superset_size = stream->read_int();
    for (int i = 0; i < superset_size; i++)
    {
        superset.insert(superset.end(), stream->read_string());
    }
    int tl_sz = stream->read_int();
    for (int i = 0; i < tl_sz; i++)
    {
        token_limit[stream->read_string()] = stream->read_int();
    }
    int its_size = stream->read_int();
    for (int i = 0; i < its_size; i++)
    {
        in_tree_set.insert(in_tree_set.end(), stream->read_string());
    }
    need_update_superset_line_cache = stream->read_byte();
    int s_l = stream->read_int();
    for (int i = 0; i < s_l; i++)
    {
        superset_at_line_cache.insert(stream->read_string());
    }
}

void HIRMutate::JSContext::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("JSContext");
    Context::serialize(stream, context);
    stream->write_int(line);
    stream->write_int(superset.size());
    std::for_each(superset.begin(), superset.end(),
                  [&stream](map<string, int>::reference i)
                  {
                      stream->write_string(i.first);
                      stream->write_int(i.second);
                  });
    stream->write_int(locations.size());
    std::for_each(locations.begin(), locations.end(),
                  [&stream](map<string, int>::reference i)
                  {
                      stream->write_string(i.first);
                      stream->write_int(i.second);
                  });
}

void HIRMutate::JSContext::unserialize(UnSerializeStream *stream, Document *global_document)
{
    if (stream->read_string() != "JSContext")
    {
        puts("JSContext::unserialize Error!");
        abort();
    }
    Context::unserialize(stream, global_document);
    line = stream->read_int();
    int st_size = stream->read_int();
    for (int i = 0; i < st_size; i++)
    {
        superset[stream->read_string()] = stream->read_int();
    }
    int loc_size = stream->read_int();
    for (int i = 0; i < loc_size; i++)
    {
        locations[stream->read_string()] = stream->read_int();
    }
    this->global_context = global_document->dom_context;
}
