#ifndef HM_JS_HTML_FUNC_H
#define HM_JS_HTML_FUNC_H

#include "attribute.h"
#include "arg.h"
#include "ret.h"
#include "Context.h"
#include "api.h"
#include "attribute.h"
#include "css_declaration.h"
#include "html_ret.h"
#include "html_arg.h"
#include "object.h"

#define INTERESTING_HTML_ELEMENT_RETS(k, v)           \
    interesting_html_element_rets[k] = HANDLE_RET(v); \
    interesting_html_element_tag.push_back(k);

#define HTML_EVENT_RETS(k, v) html_event_rets[k] = HANDLE_RET(v);
#define HTML_ELEMENT_RETS(k, v) html_element_rets[k] = HANDLE_RET(v);

namespace HIRMutate
{
    namespace JS
    {
        /*
        * x.removeAttribute(x.attributes[i % x.attributes.length].name)
        */
        class RemoveAttribute : public API
        {
        private:
            Arg *selector;

        public:
            RemoveAttribute() {}
            RemoveAttribute(Arg *this_obj, Arg *selector);
            virtual ~RemoveAttribute();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RemoveAttributeTemplate : public APITemplate
        {
        public:
            RemoveAttributeTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.insertBefore(y, x.childNodes[i % x.childNodes.length])
        */
        class InsertBefore : public API
        {
        private:
            Arg *new_node;
            Arg *selector;

        public:
            InsertBefore() {}
            InsertBefore(Arg *this_obj, Arg *new_node, Arg *selector);
            virtual ~InsertBefore();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InsertBeforeTemplate : public APITemplate
        {
        private:
            Arg *(*new_node_class)();

        public:
            InsertBeforeTemplate(Arg *(*this_class)(), Arg *(*new_node_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.removeChild(x.childNodes[i % x.childNodes.length])
        */
        class RemoveChild : public API
        {
        private:
            Arg *selector;

        public:
            RemoveChild() {}
            RemoveChild(Arg *this_obj, Arg *selector);
            virtual ~RemoveChild();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RemoveChildTemplate : public APITemplate
        {
        public:
            RemoveChildTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.replaceChild(y, x.childNodes[i % x.childNodes.length])
        */
        class ReplaceChild : public API
        {
        private:
            Arg *new_node;
            Arg *selector;

        public:
            ReplaceChild() {}
            ReplaceChild(Arg *this_obj, Arg *new_node, Arg *selector);
            virtual ~ReplaceChild();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ReplaceChildTemplate : public APITemplate
        {
            Arg *(*new_node_class)();

        public:
            ReplaceChildTemplate(Arg *(*this_class)(), Arg *(*new_node_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * NodeList.remove(): x.remove(i % x.length)
        */
        class ListRemove : public API
        {
        private:
            Arg *selector;

        public:
            ListRemove() {}
            ListRemove(Arg *this_obj, Arg *selector);
            virtual ~ListRemove();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ListRemoveTemplate : public APITemplate
        {
        public:
            ListRemoveTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * List.item(): item = x.item(i % x.length)
        */
        class ListItem : public API
        {
        private:
            Arg *selector;

        public:
            ListItem() {}
            ListItem(Ret *ret, Arg *this_obj, Arg *selector);
            virtual ~ListItem();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ListItemTemplate : public APITemplate
        {
        public:
            ListItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * List.add(): x.add(y, i % x.length)
        */
        class ListAdd : public API
        {
        private:
            Arg *item;
            Arg *selector;

        public:
            ListAdd() {}
            ListAdd(Arg *this_obj, Arg *item, Arg *selector);
            virtual ~ListAdd();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ListAddTemplate : public APITemplate
        {
            Arg *(*item_class)();

        public:
            ListAddTemplate(Arg *(*this_class)(), Arg *(*item_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * snapshotItem()
        */
        class SnapshotItem : public API
        {
            Arg *selector;

        public:
            SnapshotItem() {}
            SnapshotItem(Ret *ret, Arg *this_obj, Arg *selector);
            virtual ~SnapshotItem();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SnapshotItemTemplate : public APITemplate
        {
        public:
            SnapshotItemTemplate(Ret *(*ret_class)(), Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * x.deleteRow(i % x.rows.length)
        */
        class TableSectionDeleteRow : public API
        {
        private:
            Arg *selector;

        public:
            TableSectionDeleteRow() {}
            TableSectionDeleteRow(Arg *this_obj, Arg *selector);
            virtual ~TableSectionDeleteRow();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableSectionDeleteRowTemplate : public APITemplate
        {
        public:
            TableSectionDeleteRowTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * setAttribute
        */
        class SetAttribute : public API
        {
        private:
            Attribute::Attribute *attr;

        public:
            SetAttribute() {}
            SetAttribute(ObjectArg *this_obj);
            virtual ~SetAttribute();
            void generate_attr(DOMContext *context);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SetAttributeTemplate : public APITemplate
        {
        public:
            SetAttributeTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * style.setProperty(propertyName, value);
        */
        class SetProperty : public API
        {
        private:
            CSS::CSSDeclaration *decl;

        public:
            SetProperty() {}
            SetProperty(Arg *this_obj);
            virtual ~SetProperty();
            void generate_decl(DOMContext *context);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SetPropertyTemplate : public APITemplate
        {
        public:
            SetPropertyTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * style.removeProperty(style.item(i % style.length));
        */
        class RemoveProperty : public API
        {
        private:
            Arg *selector;

        public:
            RemoveProperty() {}
            RemoveProperty(Arg *this_obj, Arg *selector);
            virtual ~RemoveProperty();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RemovePropertyTemplate : public APITemplate
        {
        public:
            RemovePropertyTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        extern map<string, Ret *(*)()> interesting_html_element_rets;
        extern vector<string> interesting_html_element_tag;

        extern map<string, Ret *(*)()> html_element_rets;

        extern map<string, Ret *(*)()> html_event_rets;

        void initHTMLSym();

        /*
        * document.createElement(tag); -- interesting
        */
        class CreateInterestingElement : public API
        {
        private:
            string tag;

        public:
            CreateInterestingElement() {}
            CreateInterestingElement(Arg *this_obj);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CreateInterestingElementTemplate : public APITemplate
        {
        public:
            CreateInterestingElementTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        API *create_interesting_html_element(JSContext *context);

        /*
        * document.createElement(tag);
        */
        class CreateElement : public API
        {
        private:
            string tag;

        public:
            CreateElement() {}
            CreateElement(Arg *this_obj);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CreateElementTemplate : public APITemplate
        {
        public:
            CreateElementTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        API *create_html_element(JSContext *context);

        /*
        * document.createEvent(event_name);
        */
        class CreateEvent : public API
        {
        private:
            string event_type;

        public:
            CreateEvent() {}
            CreateEvent(Arg *this_obj);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CreateEventTemplate : public APITemplate
        {
        public:
            CreateEventTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * document.all[<int min=0 max=100>%document.all.length].appendChild(<Element>);
        */
        class DocumentAppendChild : public API
        {
        private:
            Arg *element;
            Arg *selector;

        public:
            DocumentAppendChild() {}
            DocumentAppendChild(Arg *this_obj, Arg *element, Arg *selector);
            virtual ~DocumentAppendChild();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DocumentAppendChildTemplate : public APITemplate
        {
        private:
            Arg *(*element_class)();

        public:
            DocumentAppendChildTemplate(Arg *(*this_class)(), Arg *(*element_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };

        /*
        * cssStyleSheet.deleteRule(index)
        */
        class DeleteRule : public API
        {
        private:
            Arg *selector;

        public:
            DeleteRule() {}
            DeleteRule(Arg *this_obj, Arg *selector);
            virtual ~DeleteRule();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DeleteRuleTemplate : public APITemplate
        {
        public:
            DeleteRuleTemplate(Arg *(*this_class)());
            API *instantiate();
            bool satiable(JSContext *context);
        };
        void initialize_html_functions();
    }
}

#endif