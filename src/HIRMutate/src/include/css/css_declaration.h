#ifndef CSS_DECLARATION_H
#define CSS_DECLARATION_H

#include "Context.h"
#include "Value.h"
#include "css_properties.h"
#include "serializestream.h"

using HIRMutate::VALUE::DynamicValue;

namespace HIRMutate
{
    class DOMContext;
    namespace CSS
    {
        class CSSDeclaration
        {
        public:
            string prop;
            Value *value;
            CSSDeclaration() {}
            CSSDeclaration(const string &prop, Value *value);
            ~CSSDeclaration();
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        CSSDeclaration *create_css_declaration(bool animatable = false);

        class CSSStyleDeclaration
        {
        private:
            bool animate;
            vector<CSSDeclaration *> declarations;

        public:
            CSSStyleDeclaration(bool animate = false);
            ~CSSStyleDeclaration();
            bool append(DOMContext *context);
            bool mutate(DOMContext *context);
            void generate(DOMContext *context);
            //合并另一个CSS的所有属性
            void merge(CSSStyleDeclaration *other);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSStyleDeclarationValue : public DynamicValue
        {
            CSSStyleDeclaration *style_declaration;

        public:
            CSSStyleDeclarationValue();
            ~CSSStyleDeclarationValue();
            void *getConstructor();
            void generate(Context *context);
            bool mutate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            string getValue();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif