#ifndef HM_HTML_SYM_H
#define HM_HTML_SYM_H

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

#define HTML_ELEMENT_MAP(k, v)   \
    html_element_map[k] = v;     \
    html_tag_to_elem_map[v] = k; \
    html_elements.push_back(k);  \
    html_tags.push_back(v);

#define HTML_GENERAL_CHILD_ELEMENTS(v) html_general_child_elements.push_back(v);
#define HTML_OTHER_CHILD_ELEMENTS(v) html_other_child_elements.push_back(v);
#define FORM_CHILD_ELEMENTS(v) form_child_elements.push_back(v);
#define TABLE_CHILD_ELEMENTS(v) table_child_elements.push_back(v);
#define MEDIA_CHILD_ELEMENTS(v) media_child_elements.push_back(v);
#define HTML_LABELABLE_ELEMENTS(v) html_labelable_elements.push_back(v);
#define HTML_CHILD_ELEMENTS(k, v) html_child_elements[k] = v;

#define HTML_CHILD_ELEMENTS_V(k, v...) HTML_CHILD_ELEMENTS(k, vector<string>(v))

#define HTML_EMPTY_ELEMENTS(v) html_empty_elements.push_back(v);
#define HTML_RAW_TEXT_ELEMENTS(v) html_raw_text_elements.push_back(v);
#define HTML_TEXT_ELEMENTS(v) html_text_elements.push_back(v);
#define BLOCK_ELEMENTS(v) block_elements.push_back(v);
#define LINK_ELEMENTS(v) link_elements.push_back(v);
#define SUBMITTABLE_ELEMENTS(v) submittable_elements.push_back(v);

namespace HIRMutate
{
    namespace DOC
    {
        namespace HTML
        {
            extern map<string, string> html_element_map;
            extern map<string, string> html_tag_to_elem_map;
            extern vector<string> html_elements;
            extern vector<string> html_tags;
            extern vector<string> html_general_child_elements;
            extern vector<string> html_other_child_elements;
            extern vector<string> form_child_elements;
            extern vector<string> table_child_elements;
            extern vector<string> media_child_elements;
            extern vector<string> html_labelable_elements;
            extern map<string, vector<string> > html_child_elements;
            extern vector<string> html_empty_elements;
            extern vector<string> html_raw_text_elements;
            extern vector<string> html_text_elements;
            extern vector<string> block_elements;
            extern vector<string> link_elements;
            extern vector<string> submittable_elements;
            void initSym();
        }
    }
}

#endif