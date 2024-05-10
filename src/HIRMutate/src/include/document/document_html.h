#ifndef HM_DOCUMENT_HTML_H
#define HM_DOCUMENT_HTML_H

#include "dom_tree.h"
#include "factory.h"
#include "js_function.h"
#include "function.h"
#include "random.h"
#include "document_css.h"
#include "uncopyable.h"
#include "serializestream.h"
#include "unserializestream.h"

namespace HIRMutate
{
    class Document : public uncopyable
    {
    private:
        string label;
        DOMTree *dom_tree;
        Object *window;
        Object *document;
        Function *main;
        vector<EventHandler *> event_handlers;
        Object *sheet0;
        Object *sheet1;
        Document_CSS *css;
        Object *dummy;

    public:
        DOMContext *dom_context;
        //反序列化用
        map<size_t, std::pair<string, int> > weak_reference_objs;

        typedef std::shared_ptr<Document> ptr;
        Document() {}
        Document(int max_element_count);
        ~Document();
        /*
        * For dumb fuzz
        */
        void generate_nodes();
        void generate_attributes();
        void generate_css_rules();
        void generate_js_functions();
        /*
        * For cov fuzz
        */
        bool insert_node();
        bool fuzz_dom_tree();
        bool fuzz_css();
        bool fuzz_js_functions();
        bool merge(Document *other);
        operator string();
        //序列化
        void serialize(SerializeStream *stream);
        //反序列化
        void unserialize(UnSerializeStream *stream);
    };
}
#endif