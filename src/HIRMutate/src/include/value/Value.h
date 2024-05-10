#ifndef HM_VALUE_H
#define HM_VALUE_H

#include <string>
#include "Context.h"
#include <vector>
#include <map>
#include "object.h"
#include <memory>
#include "serializestream.h"
#include "unserializestream.h"

using std::map;
using std::string;
using std::vector;

#define HANDLE(clazz) ((Value * (*)(void)) instanceObj<clazz>)
#define HANDLE_VOID(clazz) ((void *)instanceObj<clazz>)

namespace HIRMutate
{
    class Context;
    class Object;
    class Document;
    class Function;
    namespace VALUE
    {

        class Value
        {
        protected:
            string value;

        public:
            virtual ~Value() {}
            virtual string getValue();
            virtual void *getConstructor() = 0;
            virtual void generate(Context *context){};
            virtual bool mutate(Context *context);
            virtual void merge_fix(map<Object *, Object *> &merge_map) {}
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class StaticValue : public Value
        {
        public:
            virtual void *getConstructor();
            virtual void merge_fix(map<Object *, Object *> &merge_map) {}
            virtual void serialize(SerializeStream *stream, Context *context);
            virtual ~StaticValue() {}
        };

        class ConstValue : public StaticValue
        {
        public:
            ConstValue() {}
            ConstValue(string val);
            virtual ~ConstValue() {}
            virtual void *getConstructor();
            bool mutate(Context *context);
            void generate(Context *context);
            void merge_fix(map<Object *, Object *> &merge_map) {}
            virtual void serialize(SerializeStream *stream, Context *context);
        };
        class DynamicValue : public Value
        {
        public:
            DynamicValue();
            DynamicValue(string val);
            virtual ~DynamicValue() {}
            virtual void *getConstructor() = 0;
            virtual void generate(Context *context) = 0;
            virtual bool mutate(Context *context) { return Value::mutate(context); }
            virtual void merge_fix(map<Object *, Object *> &merge_map) = 0;
            virtual string getValue()
            {
                return value;
            }
            virtual void serialize(SerializeStream *stream, Context *context);
        };
    }
}

#endif