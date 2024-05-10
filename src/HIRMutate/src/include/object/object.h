#ifndef HM_OBJECT_H
#define HM_OBJECT_H

#include <string>
#include <vector>
#include <map>
#include <initializer_list>
#include "attribute.h"
#include "random.h"
#include "Context.h"
#include <memory>
#include <iostream>
#include "serializestream.h"
#include "unserializestream.h"
#include "uncopyable.h"

using std::map;
using std::string;
using std::vector;

namespace HIRMutate
{
    namespace Attribute
    {
        class Attribute;
        class AttributeTemplate;
    }
    class Context;
    class DOMContext;
    class Document;
    typedef std::shared_ptr<Attribute::AttributeTemplate> AttributeTemplate_ptr;
    class Object : public uncopyable
    {
    public:
        string id;
        string name;
        Object() {}
        Object(const string &name);
        Object(const string &name, const string &id);
        virtual ~Object() {}
        virtual bool is_element();
        //序列化
        virtual void serialize(SerializeStream *stream, Context *context);
        virtual void serialize_weak(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
    };
    inline bool Object::is_element()
    {
        return false;
    }
    inline Object::Object(const string &name, const string &id)
    {
        this->name = name;
        this->id = id;
    }
    inline Object::Object(const string &name)
    {
        this->name = name;
        this->id = "";
    }
    class Element : public Object
    {
    public:
    protected:
        map<string, Attribute::Attribute *> attributes;
        vector<string> attribute_names;
        string tag;
        Element *parent;
        string ahead_text;
        string last_text;

    public:
        int tree_depth;
        vector<Element *> children;
        Element() {}
        Element(const string &name);
        virtual ~Element();
        int children_count();
        bool is_element();
        bool is_in_tree();
        bool is_empty();
        int attribute_count();
        virtual string additional_label();
        bool has_attribute(const string &name);
        Attribute::Attribute *get_attribute(const string &name);
        void add_attribute(Attribute::Attribute *attr);
        void del_attribute(const string &name);
        void add_child(Element *child);
        virtual bool mutate_text();
        virtual void generate_text() = 0;
        virtual Element *insert_child() = 0;
        virtual Attribute::Attribute *generate_attribute(DOMContext *context, AttributeTemplate_ptr &a_template);
        void generate_mandatory_attributes(DOMContext *context);
        /*
        * For dumb fuzz
        */
        void generate_attributes(DOMContext *context);
        /*
        * For cov fuzz
        */
        bool append_attribute(DOMContext *context);
        bool mutate_attribute(DOMContext *context);
        bool replace_attribute(DOMContext *context);
        void merge_attributes(Element *other);
        void fix_depth();
        void merge_fix(map<Object *, Object *> &merge_map);
        virtual operator string();
        virtual void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };

    template <class T>
    const T *instanceObj()
    {
        T *obj = new T();
        return obj;
    }
}
#endif