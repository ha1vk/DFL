#include "html_obj.h"
#include <assert.h>

HIRMutate::HTMLElement::HTMLElement(const string &name) : Element(name)
{
    tag = DOC::html_tag_from_element(name);
}

HIRMutate::Element *HIRMutate::HTMLElement::create(const string &name)
{
    if (name == "HTMLSlotElement")
        return new HTMLSlotElement(name);
    else if (name == "HTMLMapElement")
        return new HTMLMapElement(name);
    else
        return new HTMLElement(name);
}

HIRMutate::Element *HIRMutate::HTMLElement::generate_child(const string &child_name)
{
    Element *child = HTMLElement::create(child_name);
    add_child(child);
    return child;
}

void HIRMutate::HTMLElement::generate_text()
{
    if (DOC::is_html_text_element(name) && Random::selector(5) == 0)
        last_text = Random::gstring();
    if ((parent == nullptr || DOC::is_html_text_element(parent->name)) && Random::selector(5) == 0)
        ahead_text = Random::gstring();
}

bool HIRMutate::HTMLElement::mutate_text()
{
    if (Random::gbool())
    {
        if (DOC::is_html_text_element(name))
        {
            last_text = Random::gstring();
            return true;
        }
    }
    else
    {
        if (parent == nullptr || DOC::is_html_text_element(parent->name))
        {
            ahead_text = Random::gstring();
            return true;
        }
    }
    return false;
}

HIRMutate::Element *HIRMutate::HTMLElement::insert_child()
{
    if (DOC::is_html_empty_element(name) || DOC::is_html_raw_text_element(name))
        return nullptr;

    vector<string> *children = nullptr;

    if (DOC::html_child_elements.find(name) != DOC::html_child_elements.end())
    {
        if (Random::selector(10) > 0)
            children = &DOC::html_child_elements[name];
    }

    if (children == nullptr || children->size() == 0)
    {
        if (Random::selector(5) > 0)
            children = &DOC::html_general_child_elements;
        else
            children = &DOC::html_other_child_elements;
    }

    if (children->size() == 0)
        return nullptr;

    string &child = CHOICE_OBJ_PTR(children);
    return generate_child(child);
}

void HIRMutate::HTMLElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HTMLElement");
    Element::serialize(stream, context);
}

void HIRMutate::HTMLElement::unserialize(UnSerializeStream *stream, Document *global_document, bool read_prefix)
{
    if (read_prefix)
    {
        if (stream->read_string() != "HTMLElement")
        {
            puts("HTMLElement::unserialize Error!");
            abort();
        }
    }
    Element::unserialize(stream, global_document);
}

string HIRMutate::HTMLSlotElement::additional_label()
{
    string ans = " name=\"";
    ans.append(id);
    ans.append("\"");
    return ans;
}

void HIRMutate::HTMLSlotElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HTMLSlotElement");
    HTMLElement::serialize(stream, context);
}

void HIRMutate::HTMLSlotElement::unserialize(UnSerializeStream *stream, Document *global_document)
{
    HTMLElement::unserialize(stream, global_document, true);
}

string HIRMutate::HTMLMapElement::additional_label()
{
    string ans = " name=\"";
    ans.append(id);
    ans.append("\"");
    return ans;
}

void HIRMutate::HTMLMapElement::serialize(SerializeStream *stream, Context *context)
{
    stream->write_string("HTMLMapElement");
    HTMLElement::serialize(stream, context);
}

void HIRMutate::HTMLMapElement::unserialize(UnSerializeStream *stream, Document *global_document)
{
    HTMLElement::unserialize(stream, global_document, true);
}