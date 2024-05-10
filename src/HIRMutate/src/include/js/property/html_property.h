#ifndef HM_HTML_PROPERTY_H
#define HM_HTML_PROPERTY_H

#include "arg.h"
#include "api.h"
#include "ret.h"
#include "random.h"
#include "object.h"
#include "Context.h"
#include <string>

using std::string;

namespace HIRMutate
{
    namespace JS
    {
        /*
        * var x = y[i % y.length]
        */
        class ArrayLoadIndex : public API
        {
        private:
            Arg *selector;

        public:
            ArrayLoadIndex() {}
            ArrayLoadIndex(Ret *ret, Arg *this_obj, Arg *selector);
            virtual ~ArrayLoadIndex();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ArrayLoadIndexTemplate : public APITemplate
        {
        public:
            ArrayLoadIndexTemplate(Ret *(*ret_class)(), Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x[i] = y
        */
        class ArrayStoreIndex : public API
        {
        private:
            Arg *value;
            Arg *selector;

        public:
            ArrayStoreIndex() {}
            ArrayStoreIndex(Arg *value, Arg *this_obj, Arg *selector);
            virtual ~ArrayStoreIndex();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ArrayStoreIndexTemplate : public APITemplate
        {
        private:
            Arg *(*value_class)();

        public:
            ArrayStoreIndexTemplate(Arg *(*value_class)(), Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * <new DOMString> = <DOMStringMap>[<DOMString>];
        * <DOMStringMap>[<DOMString>] = <DOMString>;
        */
        class DOMStringMapStoreIndex : public API
        {
        private:
            Arg *value;
            Arg *index;

        public:
            DOMStringMapStoreIndex() {}
            DOMStringMapStoreIndex(Arg *value, Arg *this_obj, Arg *index);
            virtual ~DOMStringMapStoreIndex();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DOMStringMapStoreIndexTemplate : public APITemplate
        {
        public:
            DOMStringMapStoreIndexTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        void initialize_html_properties();
    }
}
#endif