#ifndef HM_SVG_OBJ_H
#define HM_SVG_OBJ_H

#include "random.h"
#include "object.h"
#include "docs.h"
#include "DomValue.h"
#include "attribute.h"
#include "svg_val.h"
#include "html_obj.h"

namespace HIRMutate
{
    class SVGElement : public Element
    {
    public:
        SVGElement() {}
        SVGElement(const string &name);
        static Element *create(const string &name);
        virtual Element *generate_child(const string &child_name);
        virtual void generate_text();
        virtual bool mutate_text();
        virtual Element *insert_child();
        virtual string additional_label()
        {
            return Element::additional_label();
        }
        virtual operator string()
        {
            return Element::operator string();
        }
        virtual void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
    };
    class SVGAnimationElement : public SVGElement
    {
    private:
        int value_count;
        Value *(*value_class)(void);
        string type;

    public:
        SVGAnimationElement() {}
        SVGAnimationElement(const string &name);

        // SVGSetElement / SVGAnimateElement / SVGAnimateTransformElement
        // FIXME: Now only mutate parent node
        // FIXME: Now do not change mandatory attribute values when generating setAttribute()
        Attribute::Attribute *generate_attribute_name(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        // SVGAnimateTransformElement
        Attribute::Attribute *generate_type(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_value(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_values(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_key_splines(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_key_points(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_key_times(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        Attribute::Attribute *generate_attribute(DOMContext *context, Attribute::AttributeTemplate::ptr &a_template);
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    class SVGFilterPrimitive : public SVGElement
    {
    public:
        SVGFilterPrimitive() {}
        SVGFilterPrimitive(const string &name);
        string additional_label();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    class SVGForeignObjectElement : public SVGElement
    {
    public:
        SVGForeignObjectElement() {}
        SVGForeignObjectElement(const string &name);
        Element *generate_child(const string &child_name);
        Element *insert_child();
        operator string();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    class SVGGlyphElement : public SVGElement
    {
    public:
        SVGGlyphElement() {}
        SVGGlyphElement(const string &name);
        string additional_label();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
}
#endif