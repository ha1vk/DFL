#ifndef HM_CONTEXT_H
#define HM_CONTEXT_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include "random.h"
#include "object.h"
#include <memory>
#include "serializestream.h"
#include "unserializestream.h"

using std::map;
using std::set;
using std::string;
using std::vector;

namespace HIRMutate
{
    class Object;
    class Context;
    class Document;
    class ObjectPool
    {
    private:
        string prefix;
        int count;

    public:
        map<string, vector<Object *> > pool;
        //对于那些在非全局对象中使用create_object创建的对象，我们需要将其托管，以便最后释放其内存
        //比如ret.cpp中，obj对象不应随着ret对象的消失而消失，因为obj被添加到了全局对象中。
        vector<Object *> objs_need_to_be_free_at_last;

        ~ObjectPool();
        ObjectPool() {}
        ObjectPool(const string &prefix);
        vector<vector<Object *> > objects();
        vector<Object *> &get(const string &name);
        string create_id();
        void add(Object *o, bool verify_unique = false);
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
    class Context
    {
    public:
        ObjectPool *object_pool;
        Context() {}
        Context(const string &prefix);
        virtual ~Context();
        // Object
        Object *create_object(const string &name);
        virtual void add_object(Object *o, bool verify_unique = false);
        void set_object_to_be_handled(Object *obj);
        virtual vector<Object *> get_objects(vector<string> &names) = 0;
        Object *get_object(vector<string> &names);
        Object *get_object(const string &name);
        //序列化
        virtual void serialize(SerializeStream *stream, Context *context);
        std::pair<string, int> find_obj_in_pool(Object *obj);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    class JSContext;
    class DOMContext : public Context
    {
        friend JSContext;

    private:
        set<string> superset;
        map<string, int> token_limit;
        set<string> superset_at_line_cache;
        bool need_update_superset_line_cache;

    public:
        set<string> in_tree_set;
        DOMContext() {}
        DOMContext(map<string, int> &token_limit);
        virtual ~DOMContext();
        vector<Object *> in_tree_elements();
        // Token
        string get_token(const string &token);
        vector<string> get_tokens(const string &token);
        void add_object(Object *o, bool verify_unique = false);
        vector<Object *> get_objects(vector<string> &names);
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
    class JSContext : public Context
    {
    private:
        map<string, int> superset;
        map<string, int> locations;

    public:
        int line;
        DOMContext *global_context;
        JSContext() {}
        JSContext(DOMContext *global_context);
        virtual ~JSContext();
        set<string> superset_at_line();
        set<string> &superset_at_line_che();
        void add_object(Object *o, bool verify_unique = false);
        vector<Object *> get_objects(vector<string> &names);
        vector<Object *> get_offsprings(const string &name);
        Object *get_offspring(const string &name);
        bool contains(const string &name);
        void shift_object_location(int begin);
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
}
#endif