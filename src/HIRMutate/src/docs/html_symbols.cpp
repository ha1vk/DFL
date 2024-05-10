#include "html_symbols.h"

namespace HIRMutate
{
    namespace DOC
    {
        namespace HTML
        {
            map<string, string> html_element_map;
            map<string, string> html_tag_to_elem_map;
            vector<string> html_elements;
            vector<string> html_tags;
            vector<string> html_general_child_elements;
            vector<string> html_other_child_elements;
            vector<string> form_child_elements;
            vector<string> table_child_elements;
            vector<string> media_child_elements;
            vector<string> html_labelable_elements;
            map<string, vector<string> > html_child_elements;
            vector<string> html_empty_elements;
            vector<string> html_raw_text_elements;
            vector<string> html_text_elements;
            vector<string> block_elements;
            vector<string> link_elements;
            vector<string> submittable_elements;
        }
    }
}

void HIRMutate::DOC::HTML::initSym()
{
    HTML_ELEMENT_MAP("HTMLAnchorElement", "a")
    HTML_ELEMENT_MAP("HTMLAbbrElement", "abbr")
    HTML_ELEMENT_MAP("HTMLAcronymElement", "acronym")
    HTML_ELEMENT_MAP("HTMLAddressElement", "address")
    //HTML_ELEMENT_MAP("HTMLAppletElement", "applet")
    HTML_ELEMENT_MAP("HTMLAreaElement", "area")
    HTML_ELEMENT_MAP("HTMLArticleElement", "article")
    HTML_ELEMENT_MAP("HTMLAsideElement", "aside")
    HTML_ELEMENT_MAP("HTMLAudioElement", "audio")
    HTML_ELEMENT_MAP("HTMLBElement", "b")
    //HTML_ELEMENT_MAP("HTMLBaseElement", "base")
    //HTML_ELEMENT_MAP("HTMLBaseFontElement", "basefont")
    HTML_ELEMENT_MAP("HTMLBDIElement", "bdi")
    HTML_ELEMENT_MAP("HTMLBDOElement", "bdo")
    HTML_ELEMENT_MAP("HTMLBgSoundElement", "bgsound")
    HTML_ELEMENT_MAP("HTMLBigElement", "big")
    HTML_ELEMENT_MAP("HTMLBlockQuoteElement", "blockquote")
    HTML_ELEMENT_MAP("HTMLBodyElement", "body")
    HTML_ELEMENT_MAP("HTMLBRElement", "br")
    HTML_ELEMENT_MAP("HTMLButtonElement", "button")
    HTML_ELEMENT_MAP("HTMLCanvasElement", "canvas")
    HTML_ELEMENT_MAP("HTMLTableCaptionElement", "caption")
    HTML_ELEMENT_MAP("HTMLCenterElement", "center")
    HTML_ELEMENT_MAP("HTMLCiteElement", "cite")
    HTML_ELEMENT_MAP("HTMLCodeElement", "code")
    HTML_ELEMENT_MAP("HTMLTableColElement", "col")
    HTML_ELEMENT_MAP("HTMLTableColGroupElement", "colgroup")
    HTML_ELEMENT_MAP("HTMLCommandElement", "command")
    HTML_ELEMENT_MAP("HTMLContentElement", "content")
    HTML_ELEMENT_MAP("HTMLDataElement", "data")
    HTML_ELEMENT_MAP("HTMLDataListElement", "datalist")
    HTML_ELEMENT_MAP("HTMLDDElement", "dd")
    HTML_ELEMENT_MAP("HTMLDelElement", "del")
    HTML_ELEMENT_MAP("HTMLDetailsElement", "details")
    HTML_ELEMENT_MAP("HTMLDFNElement", "dfn")
    HTML_ELEMENT_MAP("HTMLDialogElement", "dialog")
    HTML_ELEMENT_MAP("HTMLDirectoryElement", "dir")
    HTML_ELEMENT_MAP("HTMLDivElement", "div")
    HTML_ELEMENT_MAP("HTMLDListElement", "dl")
    HTML_ELEMENT_MAP("HTMLDTElement", "dt")
    HTML_ELEMENT_MAP("HTMLEMElement", "em")
    HTML_ELEMENT_MAP("HTMLEmbedElement", "embed")
    HTML_ELEMENT_MAP("HTMLFieldSetElement", "fieldset")
    HTML_ELEMENT_MAP("HTMLFigCaptionElement", "figcaption")
    HTML_ELEMENT_MAP("HTMLFigureElement", "figure")
    HTML_ELEMENT_MAP("HTMLFontElement", "font")
    HTML_ELEMENT_MAP("HTMLFooterElement", "footer")
    HTML_ELEMENT_MAP("HTMLFormElement", "form")
    HTML_ELEMENT_MAP("HTMLFrameElement", "frame")
    HTML_ELEMENT_MAP("HTMLFrameSetElement", "frameset")
    HTML_ELEMENT_MAP("HTMLHeading1Element", "h1")
    HTML_ELEMENT_MAP("HTMLHeading2Element", "h2")
    HTML_ELEMENT_MAP("HTMLHeading3Element", "h3")
    HTML_ELEMENT_MAP("HTMLHeading4Element", "h4")
    HTML_ELEMENT_MAP("HTMLHeading5Element", "h5")
    HTML_ELEMENT_MAP("HTMLHeading6Element", "h6")
    //HTML_ELEMENT_MAP("HTMLHeadElement", "head")
    HTML_ELEMENT_MAP("HTMLHeaderElement", "header")
    HTML_ELEMENT_MAP("HTMLHGroupElement", "hgroup")
    HTML_ELEMENT_MAP("HTMLHRElement", "hr")
    //HTML_ELEMENT_MAP("HTMLHtmlElement", "html")
    HTML_ELEMENT_MAP("HTMLIElement", "i")
    HTML_ELEMENT_MAP("HTMLIFrameElement", "iframe")
    //HTML_ELEMENT_MAP("HTMLImageElement", "image")
    HTML_ELEMENT_MAP("HTMLImageElement", "img")
    HTML_ELEMENT_MAP("HTMLInputElement", "input")
    HTML_ELEMENT_MAP("HTMLInsElement", "ins")
    HTML_ELEMENT_MAP("HTMLIsIndexElement", "isindex")
    HTML_ELEMENT_MAP("HTMLKBDElement", "kbd")
    HTML_ELEMENT_MAP("HTMLKeygenElement", "keygen")
    HTML_ELEMENT_MAP("HTMLLabelElement", "label")
    //HTML_ELEMENT_MAP("HTMLLayerElement", "layer")
    HTML_ELEMENT_MAP("HTMLLegendElement", "legend")
    HTML_ELEMENT_MAP("HTMLLIElement", "li")
    HTML_ELEMENT_MAP("HTMLLinkElement", "link")
    HTML_ELEMENT_MAP("HTMLListingElement", "listing")
    HTML_ELEMENT_MAP("HTMLMainElement", "main")
    HTML_ELEMENT_MAP("HTMLMapElement", "map")
    HTML_ELEMENT_MAP("HTMLMarkElement", "mark")
    HTML_ELEMENT_MAP("HTMLMarqueeElement", "marquee")
    HTML_ELEMENT_MAP("HTMLMenuElement", "menu")
    HTML_ELEMENT_MAP("HTMLMenuItemElement", "menuitem")
    HTML_ELEMENT_MAP("HTMLMetaElement", "meta")
    HTML_ELEMENT_MAP("HTMLMeterElement", "meter")
    HTML_ELEMENT_MAP("HTMLNavElement", "nav")
    //HTML_ELEMENT_MAP("HTMLNoBRElement", "nobr")
    //HTML_ELEMENT_MAP("HTMLNoEmbedElement", "noembed")
    //HTML_ELEMENT_MAP("HTMLNoFramesElement", "noframes")
    //HTML_ELEMENT_MAP("HTMLNoLayerElement", "nolayer")
    //HTML_ELEMENT_MAP("HTMLNoScriptElement", "noscript")
    HTML_ELEMENT_MAP("HTMLObjectElement", "object")
    HTML_ELEMENT_MAP("HTMLOListElement", "ol")
    HTML_ELEMENT_MAP("HTMLOptGroupElement", "optgroup")
    HTML_ELEMENT_MAP("HTMLOptionElement", "option")
    HTML_ELEMENT_MAP("HTMLOutputElement", "output")
    HTML_ELEMENT_MAP("HTMLParagraphElement", "p")
    HTML_ELEMENT_MAP("HTMLParamElement", "param")
    HTML_ELEMENT_MAP("HTMLPictureElement", "picture")
    //HTML_ELEMENT_MAP("HTMLPlainTextElement", "plaintext")
    HTML_ELEMENT_MAP("HTMLPreElement", "pre")
    HTML_ELEMENT_MAP("HTMLProgressElement", "progress")
    HTML_ELEMENT_MAP("HTMLQElement", "q")
    HTML_ELEMENT_MAP("HTMLRPElement", "rp")
    HTML_ELEMENT_MAP("HTMLRTElement", "rt")
    HTML_ELEMENT_MAP("HTMLRubyElement", "ruby")
    HTML_ELEMENT_MAP("HTMLSElement", "s")
    HTML_ELEMENT_MAP("HTMLSampElement", "samp")
    HTML_ELEMENT_MAP("HTMLScriptElement", "script")
    HTML_ELEMENT_MAP("HTMLSectionElement", "section")
    HTML_ELEMENT_MAP("HTMLSelectElement", "select")
    HTML_ELEMENT_MAP("HTMLShadowElement", "shadow")
    HTML_ELEMENT_MAP("HTMLSlotElement", "slot")
    HTML_ELEMENT_MAP("HTMLSmallElement", "small")
    HTML_ELEMENT_MAP("HTMLSourceElement", "source")
    HTML_ELEMENT_MAP("HTMLSpanElement", "span")
    HTML_ELEMENT_MAP("HTMLStrikeElement", "strike")
    HTML_ELEMENT_MAP("HTMLStrongElement", "strong")
    HTML_ELEMENT_MAP("HTMLStyleElement", "style")
    HTML_ELEMENT_MAP("HTMLSubElement", "sub")
    HTML_ELEMENT_MAP("HTMLSummaryElement", "summary")
    HTML_ELEMENT_MAP("HTMLSupElement", "sup")
    HTML_ELEMENT_MAP("HTMLTimeElement", "time")
    HTML_ELEMENT_MAP("HTMLTableElement", "table")
    HTML_ELEMENT_MAP("HTMLTBodyElement", "tbody")
    HTML_ELEMENT_MAP("HTMLTableDataCellElement", "td")
    HTML_ELEMENT_MAP("HTMLTemplateElement", "template")
    HTML_ELEMENT_MAP("HTMLTextAreaElement", "textarea")
    HTML_ELEMENT_MAP("HTMLTFootElement", "tfoot")
    HTML_ELEMENT_MAP("HTMLTableHeaderCellElement", "th")
    HTML_ELEMENT_MAP("HTMLTHeadElement", "thead")
    HTML_ELEMENT_MAP("HTMLTitleElement", "title")
    HTML_ELEMENT_MAP("HTMLTableRowElement", "tr")
    HTML_ELEMENT_MAP("HTMLTrackElement", "track")
    HTML_ELEMENT_MAP("HTMLTTElement", "tt")
    HTML_ELEMENT_MAP("HTMLUElement", "u")
    HTML_ELEMENT_MAP("HTMLUListElement", "ul")
    HTML_ELEMENT_MAP("HTMLVarElement", "var")
    HTML_ELEMENT_MAP("HTMLVideoElement", "video")
    HTML_ELEMENT_MAP("HTMLWBRElement", "wbr")
    HTML_ELEMENT_MAP("HTMLXMPElement", "xmp")

    HTML_GENERAL_CHILD_ELEMENTS("HTMLAnchorElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLAreaElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLAudioElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLBlockQuoteElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLBRElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLButtonElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLCanvasElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLContentElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDataElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDataListElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDelElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDetailsElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDialogElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDirectoryElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDivElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLDListElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLEmbedElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLFieldSetElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLFontElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLFormElement")
    //HTML_GENERAL_CHILD_ELEMENTS("HTMLFrameElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLFrameSetElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading1Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading2Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading3Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading4Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading5Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHeading6Element")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLHRElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLIFrameElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLImageElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLInputElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLInsElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLKeygenElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLLabelElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLLinkElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLMapElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLMarqueeElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLMenuElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLMeterElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLObjectElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLOListElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLOutputElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLParagraphElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLPictureElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLPreElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLProgressElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLQElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLSelectElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLShadowElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLSlotElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLSpanElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLStyleElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLTimeElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLTableElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLTemplateElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLTextAreaElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLTitleElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLUListElement")
    HTML_GENERAL_CHILD_ELEMENTS("HTMLVideoElement")

    HTML_OTHER_CHILD_ELEMENTS("HTMLAbbrElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLAcronymElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLAddressElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLArticleElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLAsideElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLBElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLBDIElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLBDOElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLBgSoundElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLBigElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLCenterElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLCiteElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLCodeElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLCommandElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLDFNElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLEMElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLFigureElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLFooterElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLHeaderElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLHGroupElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLIElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLIsIndexElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLKBDElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLListingElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLMainElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLMetaElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLMarkElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLNavElement")
    //HTML_OTHER_CHILD_ELEMENTS("HTMLPlainTextElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLRubyElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSampElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSectionElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSmallElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLStrikeElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLStrongElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSubElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLSupElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLTTElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLUElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLVarElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLWBRElement")
    HTML_OTHER_CHILD_ELEMENTS("HTMLXMPElement")

    FORM_CHILD_ELEMENTS("HTMLLegendElement")
    FORM_CHILD_ELEMENTS("HTMLInputElement")
    FORM_CHILD_ELEMENTS("HTMLTextAreaElement")
    FORM_CHILD_ELEMENTS("HTMLButtonElement")
    FORM_CHILD_ELEMENTS("HTMLKeygenElement")
    FORM_CHILD_ELEMENTS("HTMLObjectElement")
    FORM_CHILD_ELEMENTS("HTMLSelectElement")
    FORM_CHILD_ELEMENTS("HTMLOutputElement")
    FORM_CHILD_ELEMENTS("HTMLLabelElement")
    FORM_CHILD_ELEMENTS("HTMLFieldSetElement")
    FORM_CHILD_ELEMENTS("HTMLOptionElement")
    FORM_CHILD_ELEMENTS("HTMLDataListElement")

    TABLE_CHILD_ELEMENTS("HTMLTableCaptionElement")
    TABLE_CHILD_ELEMENTS("HTMLTBodyElement")
    TABLE_CHILD_ELEMENTS("HTMLTFootElement")
    TABLE_CHILD_ELEMENTS("HTMLTHeadElement")
    TABLE_CHILD_ELEMENTS("HTMLTableColGroupElement")
    TABLE_CHILD_ELEMENTS("HTMLTableRowElement")

    MEDIA_CHILD_ELEMENTS("HTMLSourceElement")
    MEDIA_CHILD_ELEMENTS("HTMLTrackElement")

    HTML_LABELABLE_ELEMENTS("HTMLButtonElement")
    HTML_LABELABLE_ELEMENTS("HTMLInputElement")
    HTML_LABELABLE_ELEMENTS("HTMLKeygenElement")
    HTML_LABELABLE_ELEMENTS("HTMLMeterElement")
    HTML_LABELABLE_ELEMENTS("HTMLOutputElement")
    HTML_LABELABLE_ELEMENTS("HTMLProgressElement")
    HTML_LABELABLE_ELEMENTS("HTMLSelectElement")
    HTML_LABELABLE_ELEMENTS("HTMLTextAreaElement")

    //The elements not here can have any html elements as its children.

    HTML_CHILD_ELEMENTS("HTMLAudioElement", media_child_elements)
    HTML_CHILD_ELEMENTS("HTMLFormElement", form_child_elements)
    HTML_CHILD_ELEMENTS("HTMLFieldSetElement", form_child_elements)
    HTML_CHILD_ELEMENTS_V("HTMLSelectElement", {"HTMLOptionElement", "HTMLOptGroupElement"})
    HTML_CHILD_ELEMENTS_V("HTMLMapElement", {"HTMLAreaElement"})
    HTML_CHILD_ELEMENTS("HTMLTableElement", table_child_elements)
    HTML_CHILD_ELEMENTS_V("HTMLTableColGroupElement", {"HTMLTableColElement"})
    HTML_CHILD_ELEMENTS_V("HTMLTBodyElement", {"HTMLTableRowElement"})
    HTML_CHILD_ELEMENTS_V("HTMLTFootElement", {"HTMLTableRowElement"})
    HTML_CHILD_ELEMENTS_V("HTMLTHeadElement", {"HTMLTableRowElement"})
    HTML_CHILD_ELEMENTS_V("HTMLTableRowElement", {"HTMLTableHeaderCellElement", "HTMLTableDataCellElement"})
    HTML_CHILD_ELEMENTS_V("HTMLDirectoryElement", {"HTMLLIElement"})
    HTML_CHILD_ELEMENTS_V("HTMLDataListElement", {"HTMLOptionElement"})
    HTML_CHILD_ELEMENTS_V("HTMLOListElement", {"HTMLLIElement"})
    HTML_CHILD_ELEMENTS_V("HTMLOptGroupElement", {"HTMLOptionElement"})
    HTML_CHILD_ELEMENTS_V("HTMLUListElement", {"HTMLLIElement"})
    HTML_CHILD_ELEMENTS_V("HTMLDetailsElement", {"HTMLSummaryElement"})
    HTML_CHILD_ELEMENTS_V("HTMLDListElement", {"HTMLDTElement", "HTMLDDElement"})
    HTML_CHILD_ELEMENTS_V("HTMLFigureElement", {"HTMLFigCaptionElement"})
    HTML_CHILD_ELEMENTS_V("HTMLFrameSetElement", {"HTMLFrameElement"})
    HTML_CHILD_ELEMENTS_V("HTMLMenuElement", {"HTMLMenuElement", "HTMLMenuItemElement", "HTMLLIElement"})
    HTML_CHILD_ELEMENTS_V("HTMLObjectElement", {"HTMLParamElement"})
    HTML_CHILD_ELEMENTS_V("HTMLRubyElement", {"HTMLRPElement", "HTMLRTElement"})
    HTML_CHILD_ELEMENTS("HTMLVideoElement", media_child_elements)

    //Empty elements
    HTML_EMPTY_ELEMENTS("HTMLAreaElement")
    //HTMLBaseElement,
    HTML_EMPTY_ELEMENTS("HTMLBRElement")
    HTML_EMPTY_ELEMENTS("HTMLTableColElement")
    HTML_EMPTY_ELEMENTS("HTMLEmbedElement")
    HTML_EMPTY_ELEMENTS("HTMLHRElement")
    HTML_EMPTY_ELEMENTS("HTMLImageElement")
    HTML_EMPTY_ELEMENTS("HTMLInputElement")
    HTML_EMPTY_ELEMENTS("HTMLKeygenElement")
    HTML_EMPTY_ELEMENTS("HTMLLinkElement")
    HTML_EMPTY_ELEMENTS("HTMLMetaElement")
    HTML_EMPTY_ELEMENTS("HTMLParamElement")
    HTML_EMPTY_ELEMENTS("HTMLSourceElement")
    HTML_EMPTY_ELEMENTS("HTMLTrackElement")
    HTML_EMPTY_ELEMENTS("HTMLWBRElement")
    HTML_EMPTY_ELEMENTS("HTMLIsIndexElement")

    HTML_RAW_TEXT_ELEMENTS("HTMLTitleElement")
    HTML_RAW_TEXT_ELEMENTS("HTMLTextAreaElement")
    HTML_RAW_TEXT_ELEMENTS("HTMLIFrameElement")
    HTML_RAW_TEXT_ELEMENTS("HTMLXMPElement")
    HTML_RAW_TEXT_ELEMENTS("HTMLStyleElement")

    HTML_TEXT_ELEMENTS("HTMLAnchorElement")
    HTML_TEXT_ELEMENTS("HTMLAbbrElement")
    HTML_TEXT_ELEMENTS("HTMLAcronymElement")
    HTML_TEXT_ELEMENTS("HTMLAddressElement")
    HTML_TEXT_ELEMENTS("HTMLArticleElement")
    HTML_TEXT_ELEMENTS("HTMLAsideElement")
    HTML_TEXT_ELEMENTS("HTMLAudioElement")
    HTML_TEXT_ELEMENTS("HTMLBElement")
    //HTML_TEXT_ELEMENTS("HTMLBaseFontElement")
    HTML_TEXT_ELEMENTS("HTMLBDIElement")
    HTML_TEXT_ELEMENTS("HTMLBDOElement")
    HTML_TEXT_ELEMENTS("HTMLBgSoundElement")
    HTML_TEXT_ELEMENTS("HTMLBigElement")
    HTML_TEXT_ELEMENTS("HTMLBlockQuoteElement")
    HTML_TEXT_ELEMENTS("HTMLButtonElement")
    HTML_TEXT_ELEMENTS("HTMLCanvasElement")
    HTML_TEXT_ELEMENTS("HTMLTableCaptionElement")
    HTML_TEXT_ELEMENTS("HTMLCenterElement")
    HTML_TEXT_ELEMENTS("HTMLCiteElement")
    HTML_TEXT_ELEMENTS("HTMLCodeElement")
    HTML_TEXT_ELEMENTS("HTMLTableColGroupElement")
    HTML_TEXT_ELEMENTS("HTMLCommandElement")
    HTML_TEXT_ELEMENTS("HTMLContentElement")
    HTML_TEXT_ELEMENTS("HTMLDataElement")
    HTML_TEXT_ELEMENTS("HTMLDataListElement")
    HTML_TEXT_ELEMENTS("HTMLDDElement")
    HTML_TEXT_ELEMENTS("HTMLDelElement")
    HTML_TEXT_ELEMENTS("HTMLDetailsElement")
    HTML_TEXT_ELEMENTS("HTMLDFNElement")
    HTML_TEXT_ELEMENTS("HTMLDialogElement")
    HTML_TEXT_ELEMENTS("HTMLDirectoryElement")
    HTML_TEXT_ELEMENTS("HTMLDivElement")
    HTML_TEXT_ELEMENTS("HTMLDListElement")
    HTML_TEXT_ELEMENTS("HTMLDTElement")
    HTML_TEXT_ELEMENTS("HTMLEMElement")
    HTML_TEXT_ELEMENTS("HTMLFieldSetElement")
    HTML_TEXT_ELEMENTS("HTMLFigCaptionElement")
    HTML_TEXT_ELEMENTS("HTMLFigureElement")
    HTML_TEXT_ELEMENTS("HTMLFontElement")
    HTML_TEXT_ELEMENTS("HTMLFooterElement")
    HTML_TEXT_ELEMENTS("HTMLFormElement")
    HTML_TEXT_ELEMENTS("HTMLFrameElement")
    HTML_TEXT_ELEMENTS("HTMLFrameSetElement")
    HTML_TEXT_ELEMENTS("HTMLHeading1Element")
    HTML_TEXT_ELEMENTS("HTMLHeading2Element")
    HTML_TEXT_ELEMENTS("HTMLHeading3Element")
    HTML_TEXT_ELEMENTS("HTMLHeading4Element")
    HTML_TEXT_ELEMENTS("HTMLHeading5Element")
    HTML_TEXT_ELEMENTS("HTMLHeading6Element")
    HTML_TEXT_ELEMENTS("HTMLHeaderElement")
    HTML_TEXT_ELEMENTS("HTMLHGroupElement")
    HTML_TEXT_ELEMENTS("HTMLIElement")
    HTML_TEXT_ELEMENTS("HTMLIFrameElement")
    HTML_TEXT_ELEMENTS("HTMLInsElement")
    HTML_TEXT_ELEMENTS("HTMLIsIndexElement")
    HTML_TEXT_ELEMENTS("HTMLKBDElement")
    HTML_TEXT_ELEMENTS("HTMLLabelElement")
    HTML_TEXT_ELEMENTS("HTMLLegendElement")
    HTML_TEXT_ELEMENTS("HTMLLIElement")
    HTML_TEXT_ELEMENTS("HTMLListingElement")
    HTML_TEXT_ELEMENTS("HTMLMainElement")
    HTML_TEXT_ELEMENTS("HTMLMapElement")
    HTML_TEXT_ELEMENTS("HTMLMarkElement")
    HTML_TEXT_ELEMENTS("HTMLMarqueeElement")
    HTML_TEXT_ELEMENTS("HTMLMenuElement")
    HTML_TEXT_ELEMENTS("HTMLMenuItemElement")
    HTML_TEXT_ELEMENTS("HTMLMeterElement")
    HTML_TEXT_ELEMENTS("HTMLNavElement")
    HTML_TEXT_ELEMENTS("HTMLObjectElement")
    HTML_TEXT_ELEMENTS("HTMLOListElement")
    HTML_TEXT_ELEMENTS("HTMLOptGroupElement")
    HTML_TEXT_ELEMENTS("HTMLOptionElement")
    HTML_TEXT_ELEMENTS("HTMLOutputElement")
    HTML_TEXT_ELEMENTS("HTMLParagraphElement")
    HTML_TEXT_ELEMENTS("HTMLPictureElement")
    //HTML_TEXT_ELEMENTS("HTMLPlainTextElement")
    HTML_TEXT_ELEMENTS("HTMLPreElement")
    HTML_TEXT_ELEMENTS("HTMLProgressElement")
    HTML_TEXT_ELEMENTS("HTMLQElement")
    HTML_TEXT_ELEMENTS("HTMLRPElement")
    HTML_TEXT_ELEMENTS("HTMLRTElement")
    HTML_TEXT_ELEMENTS("HTMLRubyElement")
    HTML_TEXT_ELEMENTS("HTMLSElement")
    HTML_TEXT_ELEMENTS("HTMLSampElement")
    HTML_TEXT_ELEMENTS("HTMLSectionElement")
    HTML_TEXT_ELEMENTS("HTMLSelectElement")
    HTML_TEXT_ELEMENTS("HTMLShadowElement")
    HTML_TEXT_ELEMENTS("HTMLSmallElement")
    HTML_TEXT_ELEMENTS("HTMLSpanElement")
    HTML_TEXT_ELEMENTS("HTMLStrikeElement")
    HTML_TEXT_ELEMENTS("HTMLStrongElement")
    HTML_TEXT_ELEMENTS("HTMLSubElement")
    HTML_TEXT_ELEMENTS("HTMLSummaryElement")
    HTML_TEXT_ELEMENTS("HTMLSupElement")
    HTML_TEXT_ELEMENTS("HTMLTimeElement")
    HTML_TEXT_ELEMENTS("HTMLTableElement")
    HTML_TEXT_ELEMENTS("HTMLTBodyElement")
    HTML_TEXT_ELEMENTS("HTMLTableDataCellElement")
    HTML_TEXT_ELEMENTS("HTMLTemplateElement")
    HTML_TEXT_ELEMENTS("HTMLTextAreaElement")
    HTML_TEXT_ELEMENTS("HTMLTFootElement")
    HTML_TEXT_ELEMENTS("HTMLTableHeaderCellElement")
    HTML_TEXT_ELEMENTS("HTMLTHeadElement")
    HTML_TEXT_ELEMENTS("HTMLTitleElement")
    HTML_TEXT_ELEMENTS("HTMLTableRowElement")
    HTML_TEXT_ELEMENTS("HTMLTTElement")
    HTML_TEXT_ELEMENTS("HTMLUElement")
    HTML_TEXT_ELEMENTS("HTMLUListElement")
    HTML_TEXT_ELEMENTS("HTMLVarElement")
    HTML_TEXT_ELEMENTS("HTMLVideoElement")
    HTML_TEXT_ELEMENTS("HTMLXMPElement")

    BLOCK_ELEMENTS("HTMLParagraphElement")
    BLOCK_ELEMENTS("HTMLHeading1Element")
    BLOCK_ELEMENTS("HTMLHeading2Element")
    BLOCK_ELEMENTS("HTMLHeading3Element")
    BLOCK_ELEMENTS("HTMLHeading4Element")
    BLOCK_ELEMENTS("HTMLHeading5Element")
    BLOCK_ELEMENTS("HTMLHeading6Element")
    BLOCK_ELEMENTS("HTMLUListElement")
    BLOCK_ELEMENTS("HTMLOListElement")
    BLOCK_ELEMENTS("HTMLDListElement")
    BLOCK_ELEMENTS("HTMLPreElement")
    BLOCK_ELEMENTS("HTMLHRElement")
    BLOCK_ELEMENTS("HTMLBlockQuoteElement")
    BLOCK_ELEMENTS("HTMLAddressElement")

    LINK_ELEMENTS("HTMLAnchorElement")
    LINK_ELEMENTS("HTMLAreaElement")
    LINK_ELEMENTS("HTMLLinkElement")

    SUBMITTABLE_ELEMENTS("HTMLButtonElement")
    SUBMITTABLE_ELEMENTS("HTMLInputElement")
    SUBMITTABLE_ELEMENTS("HTMLObjectElement")
    SUBMITTABLE_ELEMENTS("HTMLSelectElement")
    SUBMITTABLE_ELEMENTS("HTMLTextAreaElement")
}