#ifndef HM_JS_ARG_H
#define HM_JS_ARG_H

#include "Context.h"
#include "Random.h"
#include "DomValue.h"
#include "object.h"

namespace HIRMutate
{
    class JSContext;
    class Document;

    namespace JS
    {
        class Arg
        {
        public:
            string name;
            virtual ~Arg() {}
            virtual bool is_object() = 0;
            virtual void generate(JSContext *context) = 0;
            virtual bool mutate(JSContext *context);
            virtual void merge_fix(map<Object *, Object *> &merge_map);
            virtual operator string() = 0;
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        // ObjectArg has a name which indicates the object type
        class ObjectArg : public Arg
        {
        public:
            Object *obj;
            ObjectArg();
            ObjectArg(const char *name);
            virtual bool is_object();
            virtual void generate(JSContext *context);
            virtual void merge_fix(map<Object *, Object *> &merge_map);
            virtual bool mutate(JSContext *context);
            virtual operator string();
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix = false);
        };
        inline bool ObjectArg::mutate(JSContext *context)
        {
            return false;
        }
        // For misc apis that do not require a real object
        class DummyArg : public ObjectArg
        {
        public:
            DummyArg();
        };

        class ValueArg : public Arg
        {
        protected:
            string value;

        public:
            ValueArg();
            virtual void generate(JSContext *context) = 0;
            virtual bool is_object();
            virtual operator string();
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix = false);
        };
        class ConstValueArg : public ValueArg
        {
        public:
            ConstValueArg() {}
            ConstValueArg(const string &value);
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class StringSetArg : public ValueArg
        {
        private:
            vector<string> strings;

        public:
            StringSetArg() {}
            StringSetArg(const vector<string> &strings);
            void generate(JSContext *context);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix = false);
        };

        class Float01Arg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FloatArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class StringArg : public ValueArg
        {
        public:
            virtual void generate(JSContext *context);
            operator string();
            virtual void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function, bool read_prefix = false);
        };

        class StringArrayArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FloatStringArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class LengthPercentageArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CharArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ColorArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ConstStringArg : public StringArg
        {
        public:
            ConstStringArg() {}
            ConstStringArg(const string &value);
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ConstStringArgStar : public ConstStringArg
        {
        public:
            ConstStringArgStar() : ConstStringArg("*") {}
        };
        class ConstStringArgXhtml : public ConstStringArg
        {
        public:
            ConstStringArgXhtml() : ConstStringArg("http://www.w3.org/1999/xhtml") {}
        };
        class ConstStringArgSvg : public ConstStringArg
        {
        public:
            ConstStringArgSvg() : ConstStringArg("http://www.w3.org/2000/svg") {}
        };
        class ConstStringEmpty : public ConstStringArg
        {
        public:
            ConstStringEmpty() : ConstStringArg("") {}
        };
        class ConstStringTextOrHtml : public ConstStringArg
        {
        public:
            ConstStringTextOrHtml() : ConstStringArg("text/html") {}
        };
        class ConstStringURLFOO : public ConstStringArg
        {
        public:
            ConstStringURLFOO() : ConstStringArg("http://foo/bar") {}
        };
        class DoNothingArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class BooleanArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class IntegerArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RangedIntegerArg : public ValueArg
        {
        private:
            int low;
            int high;

        public:
            RangedIntegerArg() {}
            RangedIntegerArg(int low, int high);
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RandomSelectorArg : public RangedIntegerArg
        {
        public:
            RandomSelectorArg();
        };

        class NullArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class IndexArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        // ENUM
        class EnumArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ClockArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ClockInMsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RegexArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif