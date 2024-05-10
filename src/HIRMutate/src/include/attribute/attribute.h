#ifndef HM_ATTRIBUTE_H
#define HM_ATTRIBUTE_H

#include <string>
#include "Value.h"
#include "Context.h"
#include "docs.h"
#include "config.h"
#include <map>
#include <algorithm>
#include <vector>
#include <memory>
#include "serializestream.h"
#include "unserializestream.h"
#include "object.h"

using std::map;
using std::string;
using std::vector;

namespace HIRMutate
{
    class DOMContext;
    class Context;
    //class Object;
    class SVGAnimationElement;
    class Object;
    class Document;
    namespace VALUE
    {
        class Value;
    }
    using HIRMutate::VALUE::Value;
    namespace Attribute
    {
        class Attribute
        {
        public:
            string elem;
            string name;
            Value *value;
            bool mandatory;
            Attribute() {}
            Attribute(const string &elem, const string &name, Value *value);
            ~Attribute();
            void generate(DOMContext *context);
            void mutate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            //反序列化
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class AttributeTemplate
        {
            friend SVGAnimationElement;

        public:
            typedef std::shared_ptr<AttributeTemplate> ptr;
            string elem;
            string attr;

        private:
            Value *(*valueInstance)(void);

        public:
            AttributeTemplate(const char *elem, const char *attr, Value *(*valueInstance)(void));
            Attribute *instantiate();
            ~AttributeTemplate();
        };

        extern map<string, vector<AttributeTemplate::ptr> > regular_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > presentation_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > global_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > aria_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > mandatory_attributes;

        extern map<string, vector<AttributeTemplate::ptr> > svg_animatable_regular_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > svg_animatable_presentation_attributes;
        extern map<string, vector<AttributeTemplate::ptr> > svg_animatable_transform_attributes;

        extern map<string, int> attributes_count;
        extern vector<AttributeTemplate::ptr> empty;

        enum AttributeType
        {
            REGULAR = 1,
            PRESENTATION = 2,
            GLOBAL = 3,
            ARIA = 4
        };
        extern int attribute_types[];

        vector<AttributeTemplate::ptr> &get_attribute_templates(const string &name, bool include_aria = false);
        int get_attribute_count(const string &elem);
        void update_attribute_count(const string &elem);
        void add_regular_attribute(const AttributeTemplate::ptr &at);
        void add_presentation_attribute(const AttributeTemplate::ptr &at);
        void add_global_attribute(const AttributeTemplate::ptr &at);
        void add_aria_attribute(const AttributeTemplate::ptr &at);
        void add_mandatory_attribute(const AttributeTemplate::ptr &at);
        void update_svg_animatable_attribute(const AttributeTemplate::ptr &at, bool is_regular);
        AttributeTemplate::ptr &get_svg_animatable_attribute(const string &elem);
        AttributeTemplate::ptr &get_svg_animatable_transform_attribute(const string &elem);
        void print_attribute_count();
        void init();
    }
}
#endif