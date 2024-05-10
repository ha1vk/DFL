#ifndef HM_JS_FUNCTION_H
#define HM_JS_FUNCTION_H

#include "api.h"
#include "random.h"
#include "arg.h"

namespace HIRMutate
{
    namespace JS
    {
        class CallFunction : public API
        {
        private:
            string method;
            vector<Arg *> args;

        public:
            CallFunction() {}
            CallFunction(Ret *ret, Arg *arg0, const string &method, vector<Arg *> args);
            virtual ~CallFunction();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FunctionTemplate : public APITemplate
        {
        private:
            vector<Arg *(*)()> arg_classes;
            string method;

        public:
            FunctionTemplate(Ret *(*ret_class)(), Arg *(*this_class)(), const string &method, vector<Arg *(*)()> arg_classes);
            API *instantiate();
            bool satiable(JSContext *context);
        };
        class Construct : public API
        {
        private:
            vector<Arg *> args;
            string ctor;

        public:
            Construct() {}
            Construct(Ret *ret, const string &ctor, vector<Arg *> args);
            virtual ~Construct();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ConstructTemplate : public APITemplate
        {
        private:
            string ctor;
            vector<Arg *(*)()> arg_classes;

        public:
            ConstructTemplate(Ret *(*ret_class)(), const string &ctor, vector<Arg *(*)()> arg_classes);
            API *instantiate();
            bool satiable(JSContext *context);
        };
        class ConstructObject : public API
        {
        private:
            map<string, Arg *> shape;

        public:
            ConstructObject() {}
            ConstructObject(Ret *ret, map<string, Arg *> &shape);
            virtual ~ConstructObject();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ConstructObjectTemplate : public APITemplate
        {
        private:
            map<string, Arg *(*)()> shape_classes;

        public:
            ConstructObjectTemplate(Ret *(*ret_class)(), map<string, Arg *(*)()> &shape_classes);
            API *instantiate();
            bool satiable(JSContext *context);
        };
    }
}
#endif
