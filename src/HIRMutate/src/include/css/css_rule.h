#ifndef HM_CSS_RULE_H
#define HM_CSS_RULE_H

#include <string>
#include "css_selector.h"
#include "css_declaration.h"

using std::string;

namespace HIRMutate
{
    namespace CSS
    {
        class CSSStyleRule
        {
        private:
            CSSGroupSelector *selector;
            CSSStyleDeclaration *declaration;

        public:
            CSSStyleRule();
            ~CSSStyleRule();
            void generate(DOMContext *context);
            void append_selector(DOMContext *context);
            void append_decl(DOMContext *context);
            bool mutate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };
        class CSSAtRule
        {
        public:
            virtual ~CSSAtRule() {}
            virtual void generate(DOMContext *context) = 0;
            virtual operator string() = 0;
            //序列化
            virtual void serialize(SerializeStream *stream, Context *context) = 0;
            virtual void unserialize(UnSerializeStream *stream, Document *global_document) = 0;
        };

        class CSSKeyframeRule
        {
        private:
            CSSStyleDeclaration *declaration;

        public:
            string name;
            CSSKeyframeRule() {}
            CSSKeyframeRule(const string &name);
            ~CSSKeyframeRule();
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            void merge(CSSKeyframeRule *other);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSKeyframesRule : public CSSAtRule
        {
        private:
            string name;
            map<string, CSSKeyframeRule *> keyframe_rules;

        public:
            CSSKeyframesRule(const string &name);
            CSSKeyframesRule() {}
            ~CSSKeyframesRule();
            string generate_keyframe_name();
            void append_keyframe_rule(DOMContext *context);
            bool mutate(DOMContext *context);
            void generate(DOMContext *context);
            void merge(CSSKeyframesRule *other);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            //序列化
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };
        CSSStyleRule *create_css_style_rule();
        CSSKeyframesRule *create_css_keyframes_rule(const string &name);
    }
}

#endif