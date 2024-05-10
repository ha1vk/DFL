#ifndef HM_JS_RET_H
#define HM_JS_RET_H

#include "Context.h"
#include "object.h"
#include <string>

using std::string;

namespace HIRMutate
{
    namespace JS
    {
        class Ret
        {
        private:
            string name;
            Object *obj;

        public:
            Ret();
            Ret(const string &name);
            virtual ~Ret();
            virtual void generate(JSContext *context);
            virtual void merge_fix(JSContext *context);
            virtual operator string();
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Function *function);
        };
    }
}
#endif
