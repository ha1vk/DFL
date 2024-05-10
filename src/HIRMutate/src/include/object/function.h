#ifndef HM_FUNCTION_H
#define HM_FUNCTION_H
#include "random.h"
#include "config.h"
#include "object.h"
#include "api.h"
#include "html_function.h"
#include "uncopyable.h"

namespace HIRMutate
{
    string try_catch(const string &s);
    class Function : public Object
    {
    private:
        bool is_callback;
        vector<JS::API *> apis;
        //由于Context里的object_pool会引用本对象，因此为了避免引用成环，这里用裸指针
        JSContext *context;

    public:
        //反序列化用
        map<size_t, std::pair<string, int> > weak_reference_objs;
        Function(const string &name = "Function", bool is_callback = false);
        virtual ~Function();
        int api_count();
        bool full();
        void init(DOMContext *dom_context);
        void generate_additional_elements();
        JS::API *generate_api();
        /*
        * For dumb fuzz
        */
        void generate_apis();
        /*
        * For cov fuzz
        */
        // A1
        bool append_api();
        // A2
        bool insert_api();
        // A3
        bool replace_api();
        // A4
        bool mutate_api();
        void merge_api(JS::API *api, int line);
        void merge(Function *other, map<Object *, Object *> &merge_map);
        operator string();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    class EventHandler : public Function
    {
    public:
        EventHandler();
    };
}
#endif