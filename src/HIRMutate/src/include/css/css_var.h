#ifndef HM_CSS_VAR_H
#define HM_CSS_VAR_H

#include <string>
#include <vector>
#include "Context.h"
#include "object.h"
#include "Value.h"

using std::string;
using std::vector;

namespace HIRMutate
{
    namespace CSS
    {
        class CSSVariableDeclaration
        {
        private:
            string name;
            VALUE::Value *value;

        public:
            CSSVariableDeclaration(const string &name, VALUE::Value *value);
            ~CSSVariableDeclaration();
            bool mutate(DOMContext *context);
            void generate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSVariables
        {
        private:
            vector<CSSVariableDeclaration *> variables;

        public:
            CSSVariables();
            ~CSSVariables();
            bool mutate(DOMContext *context);
            void generate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };
    }
}

#endif