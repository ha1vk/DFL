#ifndef HM_COMMON_VALUE_H
#define HM_COMMON_VALUE_H

#include "Value.h"
#include "random.h"
#include "DomValue.h"

using HIRMutate::VALUE::StaticValue;

namespace HIRMutate
{
    namespace COMMON
    {
        class EmptyValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class YesOrNoValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class BooleanValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class StringValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class IntegerValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class IntegerLengthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SignedIntegerValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class NumberValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class NumberOptionalNumberValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class SignedNumberOptionalNumberValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LengthValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LengthPercentageValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class LengthPercentageIntegerValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class AngleValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class IndexValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ClockValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class CharValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class OnOrOffValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class RegexValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };

        class ClockInMsValue : public StaticValue
        {
        public:
            void *getConstructor();
            void generate(Context *context);
            void serialize(SerializeStream *stream, Context *context);
        };
    }
}
#endif