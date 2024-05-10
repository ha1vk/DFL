#ifndef HM_DOCUMENT_CSS_H
#define HM_DOCUMENT_CSS_H

#include "Context.h"
#include "css_rule.h"
#include "css_var.h"

namespace HIRMutate
{
    class Document_CSS
    {
    private:
        CSS::CSSVariables *css_variables;
        vector<CSS::CSSStyleRule *> css_style_rules;
        vector<CSS::CSSKeyframesRule *> css_keyframes_rules;

    public:
        Document_CSS();
        ~Document_CSS();
        void init_keyframes(DOMContext *context);
        void init_css_variables(DOMContext *context);
        /*
        * For dumb fuzz
        */
        void generate_css_rules(DOMContext *context);
        /*
        * For cov fuzz
        */
        bool append_css_style_rule(DOMContext *context);
        bool replace_css_style_rule(DOMContext *context);
        bool mutate_css_style_rule(DOMContext *context);
        bool mutate_css_keyframes_rule(DOMContext *context);
        bool mutate_css_variable(DOMContext *context);
        bool allow_merge();
        void merge(Document_CSS *other, map<Object *, Object *> &merge_map);
        operator string();
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
}
#endif
