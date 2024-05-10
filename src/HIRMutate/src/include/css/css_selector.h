#ifndef HM_CSS_SELECTOR_H
#define HM_CSS_SELECTOR_H

#include <string>
#include <map>
#include <set>
#include "random.h"
#include "Context.h"
#include "object.h"

using std::map;
using std::set;
using std::string;

#define HANDLE_SEL(clazz) ((CSSSelector * (*)(void)) instanceObj<clazz>)
#define CSS_BASIC_SELECTORS(clazz) css_basic_selectors.push_back(HANDLE_SEL(clazz));
#define CSS_SPECIAL_SELECTORS(clazz) css_special_selectors.push_back(HANDLE_SEL(clazz));

namespace HIRMutate
{
    namespace CSS
    {
        string nth();

        class CSSSelector
        {
        protected:
            string value;

        public:
            virtual ~CSSSelector() {}
            virtual void generate(DOMContext *context) = 0;
            virtual bool mutate(DOMContext *context);
            virtual void merge_fix(map<Object *, Object *> &merge_map);
            virtual operator string() = 0;
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSAtRuleSelector : public CSSSelector
        {
        public:
            CSSAtRuleSelector() {}
            CSSAtRuleSelector(const string &value);
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        // element
        // FIXME: we only pick exist element names
        class CSSElementSelector : public CSSSelector
        {
        private:
            set<string> scope;

        public:
            CSSElementSelector(vector<string> *scope = nullptr);
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        // .class
        class CSSClassSelector : public CSSSelector
        {
        private:
            string cla;

        public:
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        // id
        class CSSIDSelector : public CSSSelector
        {
        private:
            vector<string> scope;
            Object *elem;

        public:
            CSSIDSelector(vector<string> *scope = nullptr);
            void generate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        // *
        class CSSUniversalSelector : public CSSSelector
        {
        public:
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        CSSSelector *create_css_basic_selector(vector<string> *scope = nullptr);

        /*
        * Pseudo class selectors
        */
        // :x
        // TODO: blank, has, local-link, is, nth-col, nth-last-col, target-within, user-invalid, where
        class CSSPseudoClassSelector : public CSSSelector
        {
        protected:
            string name;
            CSSSelector *base;

        public:
            CSSPseudoClassSelector() {}
            CSSPseudoClassSelector(const string &name);
            virtual ~CSSPseudoClassSelector();
            virtual void generate(DOMContext *context);
            virtual operator string();
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
        };

        class CSSActiveSelector : public CSSPseudoClassSelector
        {
        public:
            CSSActiveSelector();
        };

        class CSSAnyLinkSelector : public CSSPseudoClassSelector
        {
        public:
            CSSAnyLinkSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSCheckedSelector : public CSSPseudoClassSelector
        {
        public:
            CSSCheckedSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSDefaultSelector : public CSSPseudoClassSelector
        {
        public:
            CSSDefaultSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSDefinedSelector : public CSSPseudoClassSelector
        {
        public:
            CSSDefinedSelector();
        };

        class CSSDirSelector : public CSSPseudoClassSelector
        {
        private:
            string arg;

        public:
            CSSDirSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSDisabledSelector : public CSSPseudoClassSelector
        {
        public:
            CSSDisabledSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSEmptySelector : public CSSPseudoClassSelector
        {
        public:
            CSSEmptySelector();
        };

        class CSSEnabledSelector : public CSSPseudoClassSelector
        {
        public:
            CSSEnabledSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSFirstSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFirstSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSFirstChildSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFirstChildSelector();
        };

        class CSSFirstOfTypeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFirstOfTypeSelector();
        };

        class CSSFullscreenSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFullscreenSelector();
        };

        class CSSFutureSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFutureSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSFocusSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFocusSelector();
        };

        class CSSFocusWithinSelector : public CSSPseudoClassSelector
        {
        public:
            CSSFocusWithinSelector();
        };

        // FIXME: more selectors?; :host(); : host-context()
        class CSSHostSelector : public CSSPseudoClassSelector
        {
        public:
            CSSHostSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSHoverSelector : public CSSPseudoClassSelector
        {
        public:
            CSSHoverSelector();
        };

        class CSSIndeterminateSelector : public CSSPseudoClassSelector
        {
        public:
            CSSIndeterminateSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSInRangeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSInRangeSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSInvalidSelector : public CSSPseudoClassSelector
        {
        public:
            CSSInvalidSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSLangSelector : public CSSPseudoClassSelector
        {
        private:
            string lang;

        public:
            CSSLangSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSLastChildSelector : public CSSPseudoClassSelector
        {
        public:
            CSSLastChildSelector();
        };

        class CSSLastOfTypeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSLastOfTypeSelector();
        };

        class CSSLeftSelector : public CSSPseudoClassSelector
        {
        public:
            CSSLeftSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSLinkSelector : public CSSPseudoClassSelector
        {
        public:
            CSSLinkSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSNotSelector : public CSSPseudoClassSelector
        {
        private:
            CSSSelector *selector;

        public:
            CSSNotSelector();
            virtual ~CSSNotSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSNthChildSelector : public CSSPseudoClassSelector
        {
        private:
            string s_nth;

        public:
            CSSNthChildSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSNthLastChildSelector : public CSSPseudoClassSelector
        {
        private:
            string s_nth;

        public:
            CSSNthLastChildSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSNthLastOfTypeSelector : public CSSPseudoClassSelector
        {
        private:
            string s_nth;

        public:
            CSSNthLastOfTypeSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSNthOfTypeSelector : public CSSPseudoClassSelector
        {
        private:
            string s_nth;

        public:
            CSSNthOfTypeSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSOnlyChildSelector : public CSSPseudoClassSelector
        {
        public:
            CSSOnlyChildSelector();
        };

        class CSSOnlyOfTypeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSOnlyOfTypeSelector();
        };

        class CSSOptionalSelector : public CSSPseudoClassSelector
        {
        public:
            CSSOptionalSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSOutOfRangeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSOutOfRangeSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSPastSelector : public CSSPseudoClassSelector
        {
        public:
            CSSPastSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSPlaceholderShownSelector : public CSSPseudoClassSelector
        {
        public:
            CSSPlaceholderShownSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSReadOnlySelector : public CSSPseudoClassSelector
        {
        public:
            CSSReadOnlySelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSReadWriteSelector : public CSSPseudoClassSelector
        {
        public:
            CSSReadWriteSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSRequiredSelector : public CSSPseudoClassSelector
        {
        public:
            CSSRequiredSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSRightSelector : public CSSPseudoClassSelector
        {
        public:
            CSSRightSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSRootSelector : public CSSPseudoClassSelector
        {
        public:
            CSSRootSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSScopeSelector : public CSSPseudoClassSelector
        {
        public:
            CSSScopeSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSTargetSelector : public CSSPseudoClassSelector
        {
        public:
            CSSTargetSelector();
        };

        class CSSValidSelector : public CSSPseudoClassSelector
        {
        public:
            CSSValidSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSVisitedSelector : public CSSPseudoClassSelector
        {
        public:
            CSSVisitedSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        /*
        * Pseudo element selectors
        */
        // TODO: backdrop, cue-region, grammar-error, slotted, spelling-error
        class CSSPseudoElementSelector : public CSSSelector
        {
        protected:
            string name;
            CSSSelector *base;

        public:
            CSSPseudoElementSelector() {}
            virtual ~CSSPseudoElementSelector();
            CSSPseudoElementSelector(const string &name);
            virtual void generate(DOMContext *context);
            virtual operator string();
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
        };

        class CSSAfterSelector : public CSSPseudoElementSelector
        {
        public:
            CSSAfterSelector();
        };

        class CSSBeforeSelector : public CSSPseudoElementSelector
        {
        public:
            CSSBeforeSelector();
        };

        class CSSCueSelector : public CSSPseudoElementSelector
        {
        public:
            CSSCueSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSFirstLetterSelector : public CSSPseudoElementSelector
        {
        public:
            CSSFirstLetterSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSFirstLineSelector : public CSSPseudoElementSelector
        {
        public:
            CSSFirstLineSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSMarkerSelector : public CSSPseudoElementSelector
        {
        public:
            CSSMarkerSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSPartSelector : public CSSPseudoElementSelector
        {
        private:
            string part;

        public:
            CSSPartSelector();
            void generate(DOMContext *context);
            operator string();
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSPlaceholderSelector : public CSSPseudoElementSelector
        {
        public:
            CSSPlaceholderSelector();
            void generate(DOMContext *context);
            void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        class CSSSelectionSelector : public CSSPseudoElementSelector
        {
        public:
            CSSSelectionSelector();
        };

        /*
        * Group
        */
        class CSSCombinator : public CSSSelector
        {
        private:
            CSSSelector *a;
            CSSSelector *b;
            string op;

        public:
            CSSCombinator() {}
            CSSCombinator(const string &op);
            virtual ~CSSCombinator();
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix = false);
        };

        class CSSDescendantCombinator : public CSSCombinator
        {
        public:
            CSSDescendantCombinator();
        };

        class CSSChildCombinator : public CSSCombinator
        {
        public:
            CSSChildCombinator();
        };

        class CSSGeneralSiblingCombinator : public CSSCombinator
        {
        public:
            CSSGeneralSiblingCombinator();
        };

        class CSSAdjacentSiblingCombinator : public CSSCombinator
        {
        public:
            CSSAdjacentSiblingCombinator();
        };

        extern vector<CSSSelector *(*)(void)> css_basic_selectors;
        extern vector<CSSSelector *(*)(void)> css_special_selectors;

        void initSelector();

        // <selector> = <selector>, <selector>
        class CSSGroupSelector : public CSSSelector
        {
        private:
            vector<CSSSelector *> selectors;

        public:
            CSSGroupSelector();
            virtual ~CSSGroupSelector();
            int selector_count();
            bool append(DOMContext *context);
            void generate(DOMContext *context);
            bool mutate(DOMContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            virtual void serialize(SerializeStream *stream, Context *context);
            void unserialize(UnSerializeStream *stream, Document *global_document);
        };

        enum CSSSelectorType
        {
            Basic = 1,
            Pseudo = 2
        };
        CSSSelector *create_css_simple_selector();
        CSSGroupSelector *create_css_selector();
    }
}
#endif