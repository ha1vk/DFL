#ifndef HM_JS_PROPERTY_H
#define HM_JS_PROPERTY_H

#include <string>
#include "arg.h"
#include "ret.h"
#include "api.h"
#include "Value.h"
#include "object.h"

using HIRMutate::VALUE::Value;
using std::string;

#define HANDLE_ARG(clazz) ((Arg * (*)()) instanceObj<clazz>)
#define HANDLE_RET(clazz) ((Ret * (*)()) instanceObj<clazz>)

namespace HIRMutate
{
    namespace JS
    {
        class LoadProperty : public API
        {
        private:
            string prop;

        public:
            LoadProperty() {}
            LoadProperty(Ret *ret, Arg *this_obj, string &prop);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class StoreProperty : public API
        {
        private:
            Arg *value;
            string prop;

        public:
            StoreProperty() {}
            StoreProperty(Arg *value, Arg *this_obj, string &prop);
            virtual ~StoreProperty();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class LoadPropertyTemplate : public APITemplate
        {
        private:
            string prop;

        public:
            LoadPropertyTemplate(Ret *(*ret_class)(), Arg *(*this_class)(), const string &prop);
            API *instantiate();
            bool satiable(JSContext *context);
        };

        class StorePropertyTemplate : public APITemplate
        {
        private:
            Arg *(*value_class)();
            string prop;

        public:
            StorePropertyTemplate(Arg *(*value_class)(), Arg *(*this_class)(), const string &prop);
            API *instantiate();
            bool satiable(JSContext *context);
        };
    }
}
#endif