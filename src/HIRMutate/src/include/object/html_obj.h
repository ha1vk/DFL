#ifndef HM_HTML_OBJ_H
#define HM_HTML_OBJ_H

#include "random.h"
#include "object.h"
#include "docs.h"

namespace HIRMutate
{
    class HTMLElement : public Element
    {
    public:
        HTMLElement() {}
        HTMLElement(const string &name);
        static Element *create(const string &name);
        Element *generate_child(const string &child_name);
        void generate_text();
        bool mutate_text();
        Element *insert_child();
        virtual string additional_label();
        virtual void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
    };

    inline string HTMLElement::additional_label()
    {
        return "";
    }

    class HTMLSlotElement : public HTMLElement
    {
    public:
        HTMLSlotElement() {}
        HTMLSlotElement(const string &name);
        string additional_label();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    inline HTMLSlotElement::HTMLSlotElement(const string &name) : HTMLElement(name) {}

    class HTMLMapElement : public HTMLElement
    {
    public:
        HTMLMapElement() {}
        HTMLMapElement(const string &name);
        string additional_label();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
    inline HTMLMapElement::HTMLMapElement(const string &name) : HTMLElement(name) {}
}

#endif