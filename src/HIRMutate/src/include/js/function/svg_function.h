#ifndef HM_JS_SVG_FUNC_H
#define HM_JS_SVG_FUNC_H

#include "api.h"
#include "random.h"
#include "arg.h"
#include "svg_ret.h"
#include "js_property.h"

#define SVG_ELEMENT_RETS(k, v) svg_element_rets[k] = HANDLE_RET(v);

namespace HIRMutate
{
    namespace JS
    {
        /*
        * x.getItem(i % x.numberOfItems)
        */
        class GetItem : public API
        {
        private:
            Arg *selector;

        public:
            GetItem() {}
            GetItem(Ret *ret, Arg *this_obj, Arg *selector);
            virtual ~GetItem();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class GetItemTemplate : public APITemplate
        {
        public:
            GetItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.removeItem(i % x.numberOfItems)
        */
        class RemoveItem : public API
        {
        private:
            Arg *selector;

        public:
            RemoveItem() {}
            RemoveItem(Arg *this_obj, Arg *selector);
            virtual ~RemoveItem();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RemoveItemTemplate : public APITemplate
        {
        public:
            RemoveItemTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.insertItemBefore(y, i % x.numberOfItems)
        */
        class InsertItemBefore : public API
        {
        private:
            Arg *arg;
            Arg *selector;

        public:
            InsertItemBefore() {}
            InsertItemBefore(Arg *this_obj, Arg *arg, Arg *selector);
            virtual ~InsertItemBefore();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InsertItemBeforeTemplate : public APITemplate
        {
        private:
            Arg *(*arg_class)();

        public:
            InsertItemBeforeTemplate(Arg *(*this_class)(), Arg *(*arg_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.replaceItem(y, i % x.numberOfItems)
        */
        class ReplaceItem : public API
        {
        private:
            Arg *arg;
            Arg *selector;

        public:
            ReplaceItem() {}
            ReplaceItem(Arg *this_obj, Arg *arg, Arg *selector);
            virtual ~ReplaceItem();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ReplaceItemTemplate : public APITemplate
        {
        private:
            Arg *(*arg_class)();

        public:
            ReplaceItemTemplate(Arg *(*this_class)(), Arg *(*arg_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        extern map<string, Ret *(*)()> svg_element_rets;

        void initSVGSym();
        class CreateElementNS : public API
        {
        private:
            string tag;

        public:
            CreateElementNS() {}
            CreateElementNS(Arg *this_obj);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CreateElementNSTemplate : public APITemplate
        {
        public:
            CreateElementNSTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        void initialize_svg_functions();
    }
}
#endif
