#ifndef HM_DOM_TREE_H
#define HM_DOM_TREE_H

#include "object.h"
#include "factory.h"
#include "Context.h"
#include "docs.h"
#include <iostream>
#include "serializestream.h"

#define MERGE_BLACKLIST(v) merge_blacklist.push_back(v);

namespace HIRMutate
{
    extern vector<string> merge_blacklist;
    void initMerge_blacklist();

    class DOMTree
    {
    private:
        SVGElement *root_svg;
        vector<Element *> root_elements;
        int max_element_count;

    public:
        int element_count;
        DOMTree() {}
        DOMTree(int max_element_count);
        ~DOMTree();
        vector<Element *> get_elements();
        bool full();
        void add_root_element(Element *element);
        void add_root_svg_element(DOMContext *context);
        void init_element(DOMContext *context, Element *element);
        /*
        * For dumb fuzz
        */
        void generate_html_elements(DOMContext *context, int count);
        void generate_svg_elements(DOMContext *context, int count);
        void generate_nodes(DOMContext *context);
        void generate_attributes(DOMContext *context);
        /*
        * For cov fuzz
        */
        // T1
        Element *insert_element(DOMContext *context);
        // T2
        Element *insert_root_element(DOMContext *context);
        // T3
        bool append_attribute(DOMContext *context);
        // T4
        bool mutate_attribute(DOMContext *context);
        // T5
        bool replace_attribute(DOMContext *context);
        // T6
        bool mutate_text();
        bool allow_merge();
        void get_child(Element *element, vector<Element *> &all_childs);
        void do_merge(Element *element, DOMContext *context, Element *other_element, map<Object *, Object *> &merge_map, vector<Object *> &merge_map_values, vector<Element *> &merge_inserts);
        vector<Element *> merge(DOMContext *context, DOMTree *other, map<Object *, Object *> &merge_map);
        operator string();
        //序列化
        void serialize(SerializeStream *stream, Context *context);
        void unserialize(UnSerializeStream *stream, Document *global_document);
    };
}
#endif