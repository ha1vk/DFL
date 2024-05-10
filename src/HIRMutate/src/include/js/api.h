#ifndef HM_JS_API_H
#define HM_JS_API_H

#include <map>
#include <string>
#include <vector>
#include "Context.h"
#include "object.h"
#include "ret.h"
#include "arg.h"
#include <memory>

using std::map;
using std::string;
using std::vector;

namespace HIRMutate
{
    namespace JS
    {
        void initSym();
        class APITemplate;
        typedef std::shared_ptr<APITemplate> APITemplate_ptr;
        extern map<string, vector<APITemplate_ptr> > apis;

        class API
        {
        public:
            Ret *ret;
            Arg *this_obj;
            API() {}
            API(Ret *ret, Arg *this_obj);
            virtual ~API();
            virtual void generate(JSContext *context) = 0;
            virtual bool mutate(JSContext *context) = 0;
            virtual void merge_fix(map<Object *, Object *> &merge_map) = 0;
            virtual operator string() = 0;
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class APITemplate
        {
        public:
            typedef std::shared_ptr<APITemplate> ptr;
            Ret *(*ret_class)();
            Arg *(*this_class)();
            APITemplate(Ret *(*ret_class)(), Arg *(*this_class)());
            virtual API *instantiate() = 0;
            virtual bool satiable(JSContext *context) = 0;
        };

        bool is_satiable_arg(Arg *arg, JSContext *context);
        int get_api_count(const string &name);
        void add_api(const APITemplate::ptr &t);
    }
}
#endif