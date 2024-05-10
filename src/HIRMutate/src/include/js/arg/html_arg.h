#ifndef HM_JS_HTML_ARG_H
#define HM_JS_HTML_ARG_H

#include "random.h"
#include "DomValue.h"
#include "docs.h"
#include "css_properties.h"
#include "css_selector.h"
#include "css_rule.h"
#include "arg.h"
#include "css_declaration.h"

namespace HIRMutate
{
    namespace JS
    {
        /*
        * HTML global objects
        */
        // We confuse Node with Element like domato,
        // which does not matter regarding fuzzing.
        class DocumentArg : public ObjectArg
        {
        public:
            DocumentArg() : ObjectArg("Document") {}
        };

        class WindowArg : public ObjectArg
        {
        public:
            WindowArg() : ObjectArg("Window") {}
        };

        class DOMTokenListArg : public ObjectArg
        {
        public:
            DOMTokenListArg() : ObjectArg("DOMTokenList") {}
        };

        class URLArg : public ObjectArg
        {
        public:
            URLArg() : ObjectArg("URL") {}
        };

        class FormDataArg : public ObjectArg
        {
        public:
            FormDataArg() : ObjectArg("FormData") {}
        };

        class URLSearchParamsArg : public ObjectArg
        {
        public:
            URLSearchParamsArg() : ObjectArg("URLSearchParams") {}
        };

        class DOMStringMapArg : public ObjectArg
        {
        public:
            DOMStringMapArg() : ObjectArg("DOMStringMap") {}
        };

        class AttrArg : public ObjectArg
        {
        public:
            AttrArg() : ObjectArg("Attr") {}
        };

        class NamedNodeMapArg : public ObjectArg
        {
        public:
            NamedNodeMapArg() : ObjectArg("NamedNodeMap") {}
        };

        class DOMImplementationArg : public ObjectArg
        {
        public:
            DOMImplementationArg() : ObjectArg("DOMImplementation") {}
        };

        class ApplicationCacheArg : public ObjectArg
        {
        public:
            ApplicationCacheArg() : ObjectArg("ApplicationCache") {}
        };

        class XPathEvaluatorArg : public ObjectArg
        {
        public:
            XPathEvaluatorArg() : ObjectArg("XPathEvaluator") {}
        };

        class XPathNSResolverArg : public ObjectArg
        {
        public:
            XPathNSResolverArg() : ObjectArg("XPathNSResolver") {}
        };

        class XPathExpressionArg : public ObjectArg
        {
        public:
            XPathExpressionArg() : ObjectArg("XPathExpression") {}
        };

        class XPathResultArg : public ObjectArg
        {
        public:
            XPathResultArg() : ObjectArg("XPathResult") {}
        };

        class XMLSerializerArg : public ObjectArg
        {
        public:
            XMLSerializerArg() : ObjectArg("XMLSerializer") {}
        };

        class XSLTProcessorArg : public ObjectArg
        {
        public:
            XSLTProcessorArg() : ObjectArg("XSLTProcessor") {}
        };

        class DOMParserArg : public ObjectArg
        {
        public:
            DOMParserArg() : ObjectArg("DOMParser") {}
        };

        class DataTransferArg : public ObjectArg
        {
        public:
            DataTransferArg() : ObjectArg("DataTransfer") {}
        };

        class DataTransferItemListArg : public ObjectArg
        {
        public:
            DataTransferItemListArg() : ObjectArg("DataTransferItemList") {}
        };

        class DataTransferItemArg : public ObjectArg
        {
        public:
            DataTransferItemArg() : ObjectArg("DataTransferItem") {}
        };

        class BlobArg : public ObjectArg
        {
        public:
            BlobArg() : ObjectArg("Blob") {}
        };

        class FontFaceSetArg : public ObjectArg
        {
        public:
            FontFaceSetArg() : ObjectArg("FontFaceSet") {}
        };

        class FontFaceArg : public ObjectArg
        {
        public:
            FontFaceArg() : ObjectArg("FontFace") {}
        };

        class EventArg : public ObjectArg
        {
        public:
            EventArg() : ObjectArg("Event") {}
        };

        class EventTargetArg : public ObjectArg
        {
        public:
            EventTargetArg() : ObjectArg("EventTarget") {}
        };

        class EventTargetsArg : public ObjectArg
        {
        public:
            EventTargetsArg() : ObjectArg("EventTargets") {}
        };

        class CustomEventArg : public ObjectArg
        {
        public:
            CustomEventArg() : ObjectArg("CustomEvent") {}
        };

        class MediaQueryListEventArg : public ObjectArg
        {
        public:
            MediaQueryListEventArg() : ObjectArg("MediaQueryListEvent") {}
        };

        class ApplicationCacheErrorEventArg : public ObjectArg
        {
        public:
            ApplicationCacheErrorEventArg() : ObjectArg("ApplicationCacheErrorEvent") {}
        };

        class SecurityPolicyViolationEventArg : public ObjectArg
        {
        public:
            SecurityPolicyViolationEventArg() : ObjectArg("SecurityPolicyViolationEvent") {}
        };

        class BeforeUnloadEventArg : public ObjectArg
        {
        public:
            BeforeUnloadEventArg() : ObjectArg("BeforeUnloadEvent") {}
        };

        class UIEventArg : public ObjectArg
        {
        public:
            UIEventArg() : ObjectArg("UIEvent") {}
        };

        class PointerEventArg : public ObjectArg
        {
        public:
            PointerEventArg() : ObjectArg("PointerEvent") {}
        };

        class PromiseRejectionEventArg : public ObjectArg
        {
        public:
            PromiseRejectionEventArg() : ObjectArg("PromiseRejectionEvent") {}
        };

        class FocusEventArg : public ObjectArg
        {
        public:
            FocusEventArg() : ObjectArg("FocusEvent") {}
        };

        class CompositionEventArg : public ObjectArg
        {
        public:
            CompositionEventArg() : ObjectArg("CompositionEvent") {}
        };

        class InputEventArg : public ObjectArg
        {
        public:
            InputEventArg() : ObjectArg("InputEvent") {}
        };

        class InputDeviceCapabilitiesArg : public ObjectArg
        {
        public:
            InputDeviceCapabilitiesArg() : ObjectArg("InputDeviceCapabilities") {}
        };

        class ResourceProgressEventArg : public ObjectArg
        {
        public:
            ResourceProgressEventArg() : ObjectArg("ResourceProgressEvent") {}
        };

        class TextEventArg : public ObjectArg
        {
        public:
            TextEventArg() : ObjectArg("TextEvent") {}
        };

        class ClipboardEventArg : public ObjectArg
        {
        public:
            ClipboardEventArg() : ObjectArg("ClipboardEvent") {}
        };

        class ProgressEventArg : public ObjectArg
        {
        public:
            ProgressEventArg() : ObjectArg("ProgressEvent") {}
        };

        class WheelEventArg : public ObjectArg
        {
        public:
            WheelEventArg() : ObjectArg("WheelEvent") {}
        };

        class HashChangeEventArg : public ObjectArg
        {
        public:
            HashChangeEventArg() : ObjectArg("HashChangeEvent") {}
        };

        class MouseEventArg : public ObjectArg
        {
        public:
            MouseEventArg() : ObjectArg("MouseEvent") {}
        };

        class TransitionEventArg : public ObjectArg
        {
        public:
            TransitionEventArg() : ObjectArg("TransitionEvent") {}
        };

        class AnimationPlaybackEventArg : public ObjectArg
        {
        public:
            AnimationPlaybackEventArg() : ObjectArg("AnimationPlaybackEvent") {}
        };

        class PopStateEventArg : public ObjectArg
        {
        public:
            PopStateEventArg() : ObjectArg("PopStateEvent") {}
        };

        class DragEventArg : public ObjectArg
        {
        public:
            DragEventArg() : ObjectArg("DragEvent") {}
        };

        class PageTransitionEventArg : public ObjectArg
        {
        public:
            PageTransitionEventArg() : ObjectArg("PageTransitionEvent") {}
        };

        class MessageEventArg : public ObjectArg
        {
        public:
            MessageEventArg() : ObjectArg("MessageEvent") {}
        };

        class MutationEventArg : public ObjectArg
        {
        public:
            MutationEventArg() : ObjectArg("MutationEvent") {}
        };

        class AnimationEventArg : public ObjectArg
        {
        public:
            AnimationEventArg() : ObjectArg("AnimationEvent") {}
        };

        class ErrorEventArg : public ObjectArg
        {
        public:
            ErrorEventArg() : ObjectArg("ErrorEvent") {}
        };

        class KeyboardEventArg : public ObjectArg
        {
        public:
            KeyboardEventArg() : ObjectArg("KeyboardEvent") {}
        };

        class NavigatorArg : public ObjectArg
        {
        public:
            NavigatorArg() : ObjectArg("Navigator") {}
        };

        class CustomElementRegistryArg : public ObjectArg
        {
        public:
            CustomElementRegistryArg() : ObjectArg("CustomElementRegistry") {}
        };

        class BarPropArg : public ObjectArg
        {
        public:
            BarPropArg() : ObjectArg("BarProp") {}
        };

        class ScreenArg : public ObjectArg
        {
        public:
            ScreenArg() : ObjectArg("Screen") {}
        };

        class HistoryArg : public ObjectArg
        {
        public:
            HistoryArg() : ObjectArg("History") {}
        };

        class VisualViewportArg : public ObjectArg
        {
        public:
            VisualViewportArg() : ObjectArg("VisualViewport") {}
        };

        class ShadowRootArg : public ObjectArg
        {
        public:
            ShadowRootArg() : ObjectArg("ShadowRoot") {}
        };

        class DocumentOrShadowRootArg : public ObjectArg
        {
        public:
            DocumentOrShadowRootArg() : ObjectArg("DocumentOrShadowRoot") {}
        };

        class DocumentTypeArg : public ObjectArg
        {
        public:
            DocumentTypeArg() : ObjectArg("DocumentType") {}
        };

        class ElementArg : public ObjectArg
        {
        public:
            ElementArg() : ObjectArg("Element") {}
        };

        class CharacterDataArg : public ObjectArg
        {
        public:
            CharacterDataArg() : ObjectArg("CharacterData") {}
        };

        class DocumentFragmentArg : public ObjectArg
        {
        public:
            DocumentFragmentArg() : ObjectArg("DocumentFragment") {}
        };

        class CommentArg : public ObjectArg
        {
        public:
            CommentArg() : ObjectArg("Comment") {}
        };

        class TextArg : public ObjectArg
        {
        public:
            TextArg() : ObjectArg("Text") {}
        };

        class CDATASectionArg : public ObjectArg
        {
        public:
            CDATASectionArg() : ObjectArg("CDATASection") {}
        };

        class EventHandlerArg : public ObjectArg
        {
        public:
            EventHandlerArg() : ObjectArg("EventHandler") {}
        };

        class SelectionArg : public ObjectArg
        {
        public:
            SelectionArg() : ObjectArg("Selection") {}
        };

        class StyleSheetArg : public ObjectArg
        {
        public:
            StyleSheetArg() : ObjectArg("StyleSheet") {}
        };

        class CSSStyleSheetArg : public ObjectArg
        {
        public:
            CSSStyleSheetArg() : ObjectArg("CSSStyleSheet") {}
        };

        class CSSKeyframesSheetArg : public ObjectArg
        {
        public:
            CSSKeyframesSheetArg() : ObjectArg("CSSKeyframesSheet") {}
        };

        class CSSStyleRuleListArg : public ObjectArg
        {
        public:
            CSSStyleRuleListArg() : ObjectArg("CSSStyleRuleList") {}
        };

        class CSSKeyframesRuleListArg : public ObjectArg
        {
        public:
            CSSKeyframesRuleListArg() : ObjectArg("CSSKeyframesRuleList") {}
        };

        class CSSKeyframeRuleListArg : public ObjectArg
        {
        public:
            CSSKeyframeRuleListArg() : ObjectArg("CSSKeyframeRuleList") {}
        };

        class CSSRuleArg : public ObjectArg
        {
        public:
            CSSRuleArg() : ObjectArg("CSSRule") {}
        };

        class CSSStyleRuleArg : public ObjectArg
        {
        public:
            CSSStyleRuleArg() : ObjectArg("CSSStyleRule") {}
        };

        class CSSKeyframesRuleArg : public ObjectArg
        {
        public:
            CSSKeyframesRuleArg() : ObjectArg("CSSKeyframesRule") {}
        };

        class CSSKeyframeRuleArg : public ObjectArg
        {
        public:
            CSSKeyframeRuleArg() : ObjectArg("CSSKeyframeRule") {}
        };

        class CSSStyleDeclarationArg : public ObjectArg
        {
        public:
            CSSStyleDeclarationArg() : ObjectArg("CSSStyleDeclaration") {}
        };

        class DocumentTimelineArg : public ObjectArg
        {
        public:
            DocumentTimelineArg() : ObjectArg("DocumentTimeline") {}
        };

        class TreeWalkerArg : public ObjectArg
        {
        public:
            TreeWalkerArg() : ObjectArg("TreeWalker") {}
        };

        class NodeIteratorArg : public ObjectArg
        {
        public:
            NodeIteratorArg() : ObjectArg("NodeIterator") {}
        };

        class NodeFilterArg : public ObjectArg
        {
        public:
            NodeFilterArg() : ObjectArg("NodeFilter") {}
        };

        class RangeArg : public ObjectArg
        {
        public:
            RangeArg() : ObjectArg("Range") {}
        };

        class StaticRangesArg : public ObjectArg
        {
        public:
            StaticRangesArg() : ObjectArg("StaticRanges") {}
        };

        class StaticRangeArg : public ObjectArg
        {
        public:
            StaticRangeArg() : ObjectArg("StaticRange") {}
        };

        class TimeRangesArg : public ObjectArg
        {
        public:
            TimeRangesArg() : ObjectArg("TimeRanges") {}
        };

        class DOMRectArg : public ObjectArg
        {
        public:
            DOMRectArg() : ObjectArg("DOMRect") {}
        };

        class DOMRectListArg : public ObjectArg
        {
        public:
            DOMRectListArg() : ObjectArg("DOMRectList") {}
        };

        class NodeListArg : public ObjectArg
        {
        public:
            NodeListArg() : ObjectArg("NodeList") {}
        };

        class ElementListArg : public ObjectArg
        {
        public:
            ElementListArg() : ObjectArg("ElementList") {}
        };

        class HTMLCollectionArg : public ObjectArg
        {
        public:
            HTMLCollectionArg() : ObjectArg("HTMLCollection") {}
        };

        class HTMLAllCollectionArg : public ObjectArg
        {
        public:
            HTMLAllCollectionArg() : ObjectArg("HTMLAllCollection") {}
        };

        class HTMLOptionsCollectionArg : public ObjectArg
        {
        public:
            HTMLOptionsCollectionArg() : ObjectArg("HTMLOptionsCollection") {}
        };

        class HTMLElementListArg : public ObjectArg
        {
        public:
            HTMLElementListArg() : ObjectArg("HTMLElementList") {}
        };

        class HTMLLabelElementListArg : public ObjectArg
        {
        public:
            HTMLLabelElementListArg() : ObjectArg("HTMLLabelElementList") {}
        };

        class HTMLTableCellsCollectionArg : public ObjectArg
        {
        public:
            HTMLTableCellsCollectionArg() : ObjectArg("HTMLTableCellsCollection") {}
        };

        class HTMLTableRowsCollectionArg : public ObjectArg
        {
        public:
            HTMLTableRowsCollectionArg() : ObjectArg("HTMLTableRowsCollection") {}
        };

        class HTMLTableSectionsCollectionArg : public ObjectArg
        {
        public:
            HTMLTableSectionsCollectionArg() : ObjectArg("HTMLTableSectionsCollection") {}
        };

        class HTMLAreasCollectionArg : public ObjectArg
        {
        public:
            HTMLAreasCollectionArg() : ObjectArg("HTMLAreasCollection") {}
        };

        /*
* Animation
*/
        class AnimationEffectTimingReadOnlyArg : public ObjectArg
        {
        public:
            AnimationEffectTimingReadOnlyArg() : ObjectArg("AnimationEffectTimingReadOnly") {}
        };

        class AnimationEffectReadOnlyArg : public ObjectArg
        {
        public:
            AnimationEffectReadOnlyArg() : ObjectArg("AnimationEffectReadOnly") {}
        };

        class AnimationEffectTimingArg : public ObjectArg
        {
        public:
            AnimationEffectTimingArg() : ObjectArg("AnimationEffectTiming") {}
        };

        class AnimationsArg : public ObjectArg
        {
        public:
            AnimationsArg() : ObjectArg("Animations") {}
        };

        class AnimationArg : public ObjectArg
        {
        public:
            AnimationArg() : ObjectArg("Animation") {}
        };

        class AnimationTimelineArg : public ObjectArg
        {
        public:
            AnimationTimelineArg() : ObjectArg("AnimationTimeline") {}
        };

        class KeyframeEffectArg : public ObjectArg
        {
        public:
            KeyframeEffectArg() : ObjectArg("KeyframeEffect") {}
        };

        class ValidityStateArg : public ObjectArg
        {
        public:
            ValidityStateArg() : ObjectArg("ValidityState") {}
        };

        class MediaErrorArg : public ObjectArg
        {
        public:
            MediaErrorArg() : ObjectArg("MediaError") {}
        };

        class MediaControllerArg : public ObjectArg
        {
        public:
            MediaControllerArg() : ObjectArg("MediaController") {}
        };

        class MediaSessionArg : public ObjectArg
        {
        public:
            MediaSessionArg() : ObjectArg("MediaSession") {}
        };

        class MediaStreamArg : public ObjectArg
        {
        public:
            MediaStreamArg() : ObjectArg("MediaStream") {}
        };

        class VideoPlaybackQualityArg : public ObjectArg
        {
        public:
            VideoPlaybackQualityArg() : ObjectArg("VideoPlaybackQuality") {}
        };

        class TextTrackListArg : public ObjectArg
        {
        public:
            TextTrackListArg() : ObjectArg("TextTrackList") {}
        };

        class TextTrackCueListArg : public ObjectArg
        {
        public:
            TextTrackCueListArg() : ObjectArg("TextTrackCueList") {}
        };

        class TextTrackCueArg : public ObjectArg
        {
        public:
            TextTrackCueArg() : ObjectArg("TextTrackCue") {}
        };

        class TextTrackArg : public ObjectArg
        {
        public:
            TextTrackArg() : ObjectArg("TextTrack") {}
        };

        class VideoTrackListArg : public ObjectArg
        {
        public:
            VideoTrackListArg() : ObjectArg("VideoTrackList") {}
        };

        class VideoTrackArg : public ObjectArg
        {
        public:
            VideoTrackArg() : ObjectArg("VideoTrack") {}
        };

        class AudioTrackListArg : public ObjectArg
        {
        public:
            AudioTrackListArg() : ObjectArg("AudioTrackList") {}
        };

        class AudioTrackArg : public ObjectArg
        {
        public:
            AudioTrackArg() : ObjectArg("AudioTrack") {}
        };

        class VTTRegionListArg : public ObjectArg
        {
        public:
            VTTRegionListArg() : ObjectArg("VTTRegionList") {}
        };

        class VTTRegionArg : public ObjectArg
        {
        public:
            VTTRegionArg() : ObjectArg("VTTRegion") {}
        };

        class VTTCueArg : public ObjectArg
        {
        public:
            VTTCueArg() : ObjectArg("VTTCue") {}
        };

        class HTMLElementArg : public ObjectArg
        {
        public:
            HTMLElementArg() : ObjectArg("HTMLElement") {}
        };

        class HTMLMediaElementArg : public ObjectArg
        {
        public:
            HTMLMediaElementArg() : ObjectArg("HTMLMediaElement") {}
        };

        class HTMLTableSectionElementArg : public ObjectArg
        {
        public:
            HTMLTableSectionElementArg() : ObjectArg("HTMLTableSectionElement") {}
        };
        class HTMLTableCellElementArg : public ObjectArg
        {
        public:
            HTMLTableCellElementArg() : ObjectArg("HTMLTableCellElement") {}
        };

        class HTMLModElementArg : public ObjectArg
        {
        public:
            HTMLModElementArg() : ObjectArg("HTMLModElement") {}
        };

        class HTMLQuoteElementArg : public ObjectArg
        {
        public:
            HTMLQuoteElementArg() : ObjectArg("HTMLQuoteElement") {}
        };

        class HTMLAnchorElementArg : public ObjectArg
        {
        public:
            HTMLAnchorElementArg() : ObjectArg("HTMLAnchorElement") {}
        };

        class HTMLAbbrElementArg : public ObjectArg
        {
        public:
            HTMLAbbrElementArg() : ObjectArg("HTMLAbbrElement") {}
        };

        class HTMLAcronymElementArg : public ObjectArg
        {
        public:
            HTMLAcronymElementArg() : ObjectArg("HTMLAcronymElement") {}
        };

        class HTMLAddressElementArg : public ObjectArg
        {
        public:
            HTMLAddressElementArg() : ObjectArg("HTMLAddressElement") {}
        };

        class HTMLAreaElementArg : public ObjectArg
        {
        public:
            HTMLAreaElementArg() : ObjectArg("HTMLAreaElement") {}
        };

        class HTMLArticleElementArg : public ObjectArg
        {
        public:
            HTMLArticleElementArg() : ObjectArg("HTMLArticleElement") {}
        };

        class HTMLAsideElementArg : public ObjectArg
        {
        public:
            HTMLAsideElementArg() : ObjectArg("HTMLAsideElement") {}
        };

        class HTMLAudioElementArg : public ObjectArg
        {
        public:
            HTMLAudioElementArg() : ObjectArg("HTMLAudioElement") {}
        };

        class HTMLBElementArg : public ObjectArg
        {
        public:
            HTMLBElementArg() : ObjectArg("HTMLBElement") {}
        };

        class HTMLBaseFontElementArg : public ObjectArg
        {
        public:
            HTMLBaseFontElementArg() : ObjectArg("HTMLBaseFontElement") {}
        };

        class HTMLBDIElementArg : public ObjectArg
        {
        public:
            HTMLBDIElementArg() : ObjectArg("HTMLBDIElement") {}
        };

        class HTMLBDOElementArg : public ObjectArg
        {
        public:
            HTMLBDOElementArg() : ObjectArg("HTMLBDOElement") {}
        };

        class HTMLBgSoundElementArg : public ObjectArg
        {
        public:
            HTMLBgSoundElementArg() : ObjectArg("HTMLBgSoundElement") {}
        };

        class HTMLBigElementArg : public ObjectArg
        {
        public:
            HTMLBigElementArg() : ObjectArg("HTMLBigElement") {}
        };

        class HTMLBlockQuoteElementArg : public ObjectArg
        {
        public:
            HTMLBlockQuoteElementArg() : ObjectArg("HTMLBlockQuoteElement") {}
        };

        class HTMLBRElementArg : public ObjectArg
        {
        public:
            HTMLBRElementArg() : ObjectArg("HTMLBRElement") {}
        };

        class HTMLButtonElementArg : public ObjectArg
        {
        public:
            HTMLButtonElementArg() : ObjectArg("HTMLButtonElement") {}
        };

        class HTMLCanvasElementArg : public ObjectArg
        {
        public:
            HTMLCanvasElementArg() : ObjectArg("HTMLCanvasElement") {}
        };

        class HTMLTableCaptionElementArg : public ObjectArg
        {
        public:
            HTMLTableCaptionElementArg() : ObjectArg("HTMLTableCaptionElement") {}
        };

        class HTMLCenterElementArg : public ObjectArg
        {
        public:
            HTMLCenterElementArg() : ObjectArg("HTMLCenterElement") {}
        };

        class HTMLCiteElementArg : public ObjectArg
        {
        public:
            HTMLCiteElementArg() : ObjectArg("HTMLCiteElement") {}
        };

        class HTMLCodeElementArg : public ObjectArg
        {
        public:
            HTMLCodeElementArg() : ObjectArg("HTMLCodeElement") {}
        };

        class HTMLTableColElementArg : public ObjectArg
        {
        public:
            HTMLTableColElementArg() : ObjectArg("HTMLTableColElement") {}
        };

        class HTMLTableColGroupElementArg : public ObjectArg
        {
        public:
            HTMLTableColGroupElementArg() : ObjectArg("HTMLTableColGroupElement") {}
        };

        class HTMLCommandElementArg : public ObjectArg
        {
        public:
            HTMLCommandElementArg() : ObjectArg("HTMLCommandElement") {}
        };

        class HTMLContentElementArg : public ObjectArg
        {
        public:
            HTMLContentElementArg() : ObjectArg("HTMLContentElement") {}
        };

        class HTMLDataElementArg : public ObjectArg
        {
        public:
            HTMLDataElementArg() : ObjectArg("HTMLDataElement") {}
        };

        class HTMLDataListElementArg : public ObjectArg
        {
        public:
            HTMLDataListElementArg() : ObjectArg("HTMLDataListElement") {}
        };

        class HTMLDDElementArg : public ObjectArg
        {
        public:
            HTMLDDElementArg() : ObjectArg("HTMLDDElement") {}
        };

        class HTMLDelElementArg : public ObjectArg
        {
        public:
            HTMLDelElementArg() : ObjectArg("HTMLDelElement") {}
        };

        class HTMLDetailsElementArg : public ObjectArg
        {
        public:
            HTMLDetailsElementArg() : ObjectArg("HTMLDetailsElement") {}
        };

        class HTMLDFNElementArg : public ObjectArg
        {
        public:
            HTMLDFNElementArg() : ObjectArg("HTMLDFNElement") {}
        };

        class HTMLDialogElementArg : public ObjectArg
        {
        public:
            HTMLDialogElementArg() : ObjectArg("HTMLDialogElement") {}
        };

        class HTMLDirectoryElementArg : public ObjectArg
        {
        public:
            HTMLDirectoryElementArg() : ObjectArg("HTMLDirectoryElement") {}
        };

        class HTMLDivElementArg : public ObjectArg
        {
        public:
            HTMLDivElementArg() : ObjectArg("HTMLDivElement") {}
        };

        class HTMLDListElementArg : public ObjectArg
        {
        public:
            HTMLDListElementArg() : ObjectArg("HTMLDListElement") {}
        };

        class HTMLDTElementArg : public ObjectArg
        {
        public:
            HTMLDTElementArg() : ObjectArg("HTMLDTElement") {}
        };

        class HTMLEMElementArg : public ObjectArg
        {
        public:
            HTMLEMElementArg() : ObjectArg("HTMLEMElement") {}
        };

        class HTMLEmbedElementArg : public ObjectArg
        {
        public:
            HTMLEmbedElementArg() : ObjectArg("HTMLEmbedElement") {}
        };

        class HTMLFieldSetElementArg : public ObjectArg
        {
        public:
            HTMLFieldSetElementArg() : ObjectArg("HTMLFieldSetElement") {}
        };

        class HTMLFigCaptionElementArg : public ObjectArg
        {
        public:
            HTMLFigCaptionElementArg() : ObjectArg("HTMLFigCaptionElement") {}
        };

        class HTMLFigureElementArg : public ObjectArg
        {
        public:
            HTMLFigureElementArg() : ObjectArg("HTMLFigureElement") {}
        };

        class HTMLFontElementArg : public ObjectArg
        {
        public:
            HTMLFontElementArg() : ObjectArg("HTMLFontElement") {}
        };

        class HTMLFooterElementArg : public ObjectArg
        {
        public:
            HTMLFooterElementArg() : ObjectArg("HTMLFooterElement") {}
        };

        class HTMLFormElementArg : public ObjectArg
        {
        public:
            HTMLFormElementArg() : ObjectArg("HTMLFormElement") {}
        };

        class HTMLFrameElementArg : public ObjectArg
        {
        public:
            HTMLFrameElementArg() : ObjectArg("HTMLFrameElement") {}
        };

        class HTMLFrameSetElementArg : public ObjectArg
        {
        public:
            HTMLFrameSetElementArg() : ObjectArg("HTMLFrameSetElement") {}
        };

        class HTMLHeadingElementArg : public ObjectArg
        {
        public:
            HTMLHeadingElementArg() : ObjectArg("HTMLHeadingElement") {}
        };

        class HTMLHeading1ElementArg : public ObjectArg
        {
        public:
            HTMLHeading1ElementArg() : ObjectArg("HTMLHeading1Element") {}
        };

        class HTMLHeading2ElementArg : public ObjectArg
        {
        public:
            HTMLHeading2ElementArg() : ObjectArg("HTMLHeading2Element") {}
        };

        class HTMLHeading3ElementArg : public ObjectArg
        {
        public:
            HTMLHeading3ElementArg() : ObjectArg("HTMLHeading3Element") {}
        };

        class HTMLHeading4ElementArg : public ObjectArg
        {
        public:
            HTMLHeading4ElementArg() : ObjectArg("HTMLHeading4Element") {}
        };

        class HTMLHeading5ElementArg : public ObjectArg
        {
        public:
            HTMLHeading5ElementArg() : ObjectArg("HTMLHeading5Element") {}
        };

        class HTMLHeading6ElementArg : public ObjectArg
        {
        public:
            HTMLHeading6ElementArg() : ObjectArg("HTMLHeading6Element") {}
        };

        class HTMLHeaderElementArg : public ObjectArg
        {
        public:
            HTMLHeaderElementArg() : ObjectArg("HTMLHeaderElement") {}
        };

        class HTMLHGroupElementArg : public ObjectArg
        {
        public:
            HTMLHGroupElementArg() : ObjectArg("HTMLHGroupElement") {}
        };
        class HTMLHRElementArg : public ObjectArg
        {
        public:
            HTMLHRElementArg() : ObjectArg("HTMLHRElement") {}
        };
        class HTMLIElementArg : public ObjectArg
        {
        public:
            HTMLIElementArg() : ObjectArg("HTMLIElement") {}
        };

        class HTMLIFrameElementArg : public ObjectArg
        {
        public:
            HTMLIFrameElementArg() : ObjectArg("HTMLIFrameElement") {}
        };

        class HTMLImageElementArg : public ObjectArg
        {
        public:
            HTMLImageElementArg() : ObjectArg("HTMLImageElement") {}
        };

        class HTMLInputElementArg : public ObjectArg
        {
        public:
            HTMLInputElementArg() : ObjectArg("HTMLInputElement") {}
        };

        class HTMLInsElementArg : public ObjectArg
        {
        public:
            HTMLInsElementArg() : ObjectArg("HTMLInsElement") {}
        };

        class HTMLIsIndexElementArg : public ObjectArg
        {
        public:
            HTMLIsIndexElementArg() : ObjectArg("HTMLIsIndexElement") {}
        };

        class HTMLKBDElementArg : public ObjectArg
        {
        public:
            HTMLKBDElementArg() : ObjectArg("HTMLKBDElement") {}
        };

        class HTMLKeygenElementArg : public ObjectArg
        {
        public:
            HTMLKeygenElementArg() : ObjectArg("HTMLKeygenElement") {}
        };

        class HTMLLabelElementArg : public ObjectArg
        {
        public:
            HTMLLabelElementArg() : ObjectArg("HTMLLabelElement") {}
        };

        class HTMLLegendElementArg : public ObjectArg
        {
        public:
            HTMLLegendElementArg() : ObjectArg("HTMLLegendElement") {}
        };

        class HTMLLIElementArg : public ObjectArg
        {
        public:
            HTMLLIElementArg() : ObjectArg("HTMLLIElement") {}
        };

        class HTMLLinkElementArg : public ObjectArg
        {
        public:
            HTMLLinkElementArg() : ObjectArg("HTMLLinkElement") {}
        };

        class HTMLStyleElementArg : public ObjectArg
        {
        public:
            HTMLStyleElementArg() : ObjectArg("HTMLStyleElement") {}
        };

        class HTMLListingElementArg : public ObjectArg
        {
        public:
            HTMLListingElementArg() : ObjectArg("HTMLListingElement") {}
        };

        class HTMLMainElementArg : public ObjectArg
        {
        public:
            HTMLMainElementArg() : ObjectArg("HTMLMainElement") {}
        };

        class HTMLMapElementArg : public ObjectArg
        {
        public:
            HTMLMapElementArg() : ObjectArg("HTMLMapElement") {}
        };

        class HTMLMarkElementArg : public ObjectArg
        {
        public:
            HTMLMarkElementArg() : ObjectArg("HTMLMarkElement") {}
        };

        class HTMLMarqueeElementArg : public ObjectArg
        {
        public:
            HTMLMarqueeElementArg() : ObjectArg("HTMLMarqueeElement") {}
        };

        class HTMLMenuElementArg : public ObjectArg
        {
        public:
            HTMLMenuElementArg() : ObjectArg("HTMLMenuElement") {}
        };

        class HTMLMenuItemElementArg : public ObjectArg
        {
        public:
            HTMLMenuItemElementArg() : ObjectArg("HTMLMenuItemElement") {}
        };

        class HTMLMetaElementArg : public ObjectArg
        {
        public:
            HTMLMetaElementArg() : ObjectArg("HTMLMetaElement") {}
        };

        class HTMLMeterElementArg : public ObjectArg
        {
        public:
            HTMLMeterElementArg() : ObjectArg("HTMLMeterElement") {}
        };

        class HTMLNavElementArg : public ObjectArg
        {
        public:
            HTMLNavElementArg() : ObjectArg("HTMLNavElement") {}
        };

        class HTMLObjectElementArg : public ObjectArg
        {
        public:
            HTMLObjectElementArg() : ObjectArg("HTMLObjectElement") {}
        };

        class HTMLOListElementArg : public ObjectArg
        {
        public:
            HTMLOListElementArg() : ObjectArg("HTMLOListElement") {}
        };

        class HTMLOptGroupElementArg : public ObjectArg
        {
        public:
            HTMLOptGroupElementArg() : ObjectArg("HTMLOptGroupElement") {}
        };

        class HTMLOptionElementArg : public ObjectArg
        {
        public:
            HTMLOptionElementArg() : ObjectArg("HTMLOptionElement") {}
        };

        class HTMLOutputElementArg : public ObjectArg
        {
        public:
            HTMLOutputElementArg() : ObjectArg("HTMLOutputElement") {}
        };

        class HTMLParagraphElementArg : public ObjectArg
        {
        public:
            HTMLParagraphElementArg() : ObjectArg("HTMLParagraphElement") {}
        };

        class HTMLParamElementArg : public ObjectArg
        {
        public:
            HTMLParamElementArg() : ObjectArg("HTMLParamElement") {}
        };

        class HTMLPictureElementArg : public ObjectArg
        {
        public:
            HTMLPictureElementArg() : ObjectArg("HTMLPictureElement") {}
        };

        class HTMLPlainTextElementArg : public ObjectArg
        {
        public:
            HTMLPlainTextElementArg() : ObjectArg("HTMLPlainTextElement") {}
        };

        class HTMLPreElementArg : public ObjectArg
        {
        public:
            HTMLPreElementArg() : ObjectArg("HTMLPreElement") {}
        };

        class HTMLProgressElementArg : public ObjectArg
        {
        public:
            HTMLProgressElementArg() : ObjectArg("HTMLProgressElement") {}
        };

        class HTMLQElementArg : public ObjectArg
        {
        public:
            HTMLQElementArg() : ObjectArg("HTMLQElement") {}
        };

        class HTMLRPElementArg : public ObjectArg
        {
        public:
            HTMLRPElementArg() : ObjectArg("HTMLRPElement") {}
        };

        class HTMLRTElementArg : public ObjectArg
        {
        public:
            HTMLRTElementArg() : ObjectArg("HTMLRTElement") {}
        };

        class HTMLRubyElementArg : public ObjectArg
        {
        public:
            HTMLRubyElementArg() : ObjectArg("HTMLRubyElement") {}
        };

        class HTMLSElementArg : public ObjectArg
        {
        public:
            HTMLSElementArg() : ObjectArg("HTMLSElement") {}
        };

        class HTMLSampElementArg : public ObjectArg
        {
        public:
            HTMLSampElementArg() : ObjectArg("HTMLSampElement") {}
        };

        class HTMLScriptElementArg : public ObjectArg
        {
        public:
            HTMLScriptElementArg() : ObjectArg("HTMLScriptElement") {}
        };

        class HTMLSectionElementArg : public ObjectArg
        {
        public:
            HTMLSectionElementArg() : ObjectArg("HTMLSectionElement") {}
        };

        class HTMLSelectElementArg : public ObjectArg
        {
        public:
            HTMLSelectElementArg() : ObjectArg("HTMLSelectElement") {}
        };

        class HTMLShadowElementArg : public ObjectArg
        {
        public:
            HTMLShadowElementArg() : ObjectArg("HTMLShadowElement") {}
        };

        class HTMLSlotElementArg : public ObjectArg
        {
        public:
            HTMLSlotElementArg() : ObjectArg("HTMLSlotElement") {}
        };

        class HTMLSmallElementArg : public ObjectArg
        {
        public:
            HTMLSmallElementArg() : ObjectArg("HTMLSmallElement") {}
        };

        class HTMLSourceElementArg : public ObjectArg
        {
        public:
            HTMLSourceElementArg() : ObjectArg("HTMLSourceElement") {}
        };

        class HTMLSpanElementArg : public ObjectArg
        {
        public:
            HTMLSpanElementArg() : ObjectArg("HTMLSpanElement") {}
        };

        class HTMLStrikeElementArg : public ObjectArg
        {
        public:
            HTMLStrikeElementArg() : ObjectArg("HTMLStrikeElement") {}
        };

        class HTMLStrongElementArg : public ObjectArg
        {
        public:
            HTMLStrongElementArg() : ObjectArg("HTMLStrongElement") {}
        };

        class HTMLSubElementArg : public ObjectArg
        {
        public:
            HTMLSubElementArg() : ObjectArg("HTMLSubElement") {}
        };

        class HTMLSummaryElementArg : public ObjectArg
        {
        public:
            HTMLSummaryElementArg() : ObjectArg("HTMLSummaryElement") {}
        };

        class HTMLSupElementArg : public ObjectArg
        {
        public:
            HTMLSupElementArg() : ObjectArg("HTMLSupElement") {}
        };

        class HTMLTimeElementArg : public ObjectArg
        {
        public:
            HTMLTimeElementArg() : ObjectArg("HTMLTimeElement") {}
        };

        class HTMLTableElementArg : public ObjectArg
        {
        public:
            HTMLTableElementArg() : ObjectArg("HTMLTableElement") {}
        };

        class HTMLTBodyElementArg : public ObjectArg
        {
        public:
            HTMLTBodyElementArg() : ObjectArg("HTMLTBodyElement") {}
        };

        class HTMLTableDataCellElementArg : public ObjectArg
        {
        public:
            HTMLTableDataCellElementArg() : ObjectArg("HTMLTableDataCellElement") {}
        };

        class HTMLTemplateElementArg : public ObjectArg
        {
        public:
            HTMLTemplateElementArg() : ObjectArg("HTMLTemplateElement") {}
        };

        class HTMLTextAreaElementArg : public ObjectArg
        {
        public:
            HTMLTextAreaElementArg() : ObjectArg("HTMLTextAreaElement") {}
        };

        class HTMLTFootElementArg : public ObjectArg
        {
        public:
            HTMLTFootElementArg() : ObjectArg("HTMLTFootElement") {}
        };

        class HTMLTableHeaderCellElementArg : public ObjectArg
        {
        public:
            HTMLTableHeaderCellElementArg() : ObjectArg("HTMLTableHeaderCellElement") {}
        };

        class HTMLTHeadElementArg : public ObjectArg
        {
        public:
            HTMLTHeadElementArg() : ObjectArg("HTMLTHeadElement") {}
        };

        class HTMLTitleElementArg : public ObjectArg
        {
        public:
            HTMLTitleElementArg() : ObjectArg("HTMLTitleElement") {}
        };

        class HTMLTableRowElementArg : public ObjectArg
        {
        public:
            HTMLTableRowElementArg() : ObjectArg("HTMLTableRowElement") {}
        };

        class HTMLTrackElementArg : public ObjectArg
        {
        public:
            HTMLTrackElementArg() : ObjectArg("HTMLTrackElement") {}
        };

        class HTMLTTElementArg : public ObjectArg
        {
        public:
            HTMLTTElementArg() : ObjectArg("HTMLTTElement") {}
        };

        class HTMLUElementArg : public ObjectArg
        {
        public:
            HTMLUElementArg() : ObjectArg("HTMLUElement") {}
        };

        class HTMLUListElementArg : public ObjectArg
        {
        public:
            HTMLUListElementArg() : ObjectArg("HTMLUListElement") {}
        };

        class HTMLVarElementArg : public ObjectArg
        {
        public:
            HTMLVarElementArg() : ObjectArg("HTMLVarElement") {}
        };

        class HTMLVideoElementArg : public ObjectArg
        {
        public:
            HTMLVideoElementArg() : ObjectArg("HTMLVideoElement") {}
        };

        class HTMLWBRElementArg : public ObjectArg
        {
        public:
            HTMLWBRElementArg() : ObjectArg("HTMLWBRElement") {}
        };

        class HTMLXMPElementArg : public ObjectArg
        {
        public:
            HTMLXMPElementArg() : ObjectArg("HTMLXMPElement") {}
        };

        class HTMLStringArg : public ObjectArg
        {
        public:
            HTMLStringArg() : ObjectArg("HTMLString") {}
        };

        class ShadowHostArg : public ObjectArg
        {
        public:
            ShadowHostArg() : ObjectArg("ShadowHost") {}
        };

        class MutationObserverArg : public ObjectArg
        {
        public:
            MutationObserverArg() : ObjectArg("MutationObserver") {}
        };

        class MutationRecordsArg : public ObjectArg
        {
        public:
            MutationRecordsArg() : ObjectArg("MutationRecords") {}
        };

        class MutationRecordArg : public ObjectArg
        {
        public:
            MutationRecordArg() : ObjectArg("MutationRecord") {}
        };

        class ProcessingInstructionArg : public ObjectArg
        {
        public:
            ProcessingInstructionArg() : ObjectArg("ProcessingInstruction") {}
        };

        class MessageChannelArg : public ObjectArg
        {
        public:
            MessageChannelArg() : ObjectArg("MessageChannel") {}
        };

        class MessagePortArg : public ObjectArg
        {
        public:
            MessagePortArg() : ObjectArg("MessagePort") {}
        };

        class RequestIDArg : public ObjectArg
        {
        public:
            RequestIDArg() : ObjectArg("RequestID") {}
        };

        class MediaQueryListArg : public ObjectArg
        {
        public:
            MediaQueryListArg() : ObjectArg("MediaQueryList") {}
        };

        class MediaListArg : public ObjectArg
        {
        public:
            MediaListArg() : ObjectArg("MediaList") {}
        };

        class StyleMediaArg : public ObjectArg
        {
        public:
            StyleMediaArg() : ObjectArg("StyleMedia") {}
        };

        /*
        * HTML values
        */
        class ShadowRootInitArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MutationObserverInitArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ScrollToOptionsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ScrollIntoViewOptionsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class HeadingArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InsertPositionArg : public StringSetArg
        {
        public:
            InsertPositionArg();
        };

        class DesignModeArg : public StringSetArg
        {
        public:
            DesignModeArg();
        };
        class AutoCapitalizeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ContentEditableArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DirArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class LangArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TabIndexArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DropZoneArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CharsetArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CoordsArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ShapeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TargetArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class PreloadArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MediaSrcArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TrackSrcArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class VolumeArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ClearArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TrackKindArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FormEncTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class FormMethodArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ButtonTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class WhatToShowArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class PlayStateArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class AnimateOptionsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AnimationDirectionArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AnimationEasingArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AnimationFillArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AssignedNodesOptionArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AddEventListenerOptionsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ObjectAlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ScrollingArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableFrameArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableRulesArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableAlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class VAlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InputModeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class WrapArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SelectionDirectionArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SelectModeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class NumberingTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AutoCompleteArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CaptionAlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class KeyTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ImageSrcArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class SrcSetArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class MetaSchemeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class TextTrackModeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class VTTRegionScrollArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class VTTCueVerticalArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class VTTCueLineArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class VTTCuePositionArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class VTTCueAlignArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class DateTimeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class ParamValueTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class LinkAsArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UListTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
        class TableScopeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MenuTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AcceptArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class InputTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MenuItemTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MarqueeBehaviorArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MarqueeDirectionArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MarqueeLoopArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SelectionModifyAlterArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SelectionModifyDirectionArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class SelectionModifyGranularityArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class GetRootNodeOptionsArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RangeCompareArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSFloatArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ContentTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RelArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RevArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FrameSrcArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MediaQueryArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ImageTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MediaTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MIMETypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class DropEffectArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class EffectAllowedArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontWeightArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontStretchArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontVariantArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class FontFeatureSettingsArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UnicodeRangeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ScrollRestorationArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class HistoryStateArg : public ValueArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSPropertyNameArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CustomElementNameArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        /*
        * Context-aware arg
        */
        class MediaGroupArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TagArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class HTMLTagArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ClassArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class KeyFramesArg : public Arg
        {
        private:
            map<string, vector<Value *> > props;
            vector<string> prop_keys;

        public:
            KeyFramesArg();
            virtual ~KeyFramesArg();
            bool is_object();
            void append_prop(JSContext *context);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);

            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableAxisArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class RadioGroupArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class XPathArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class XPathResultTypeArg : public RangedIntegerArg
        {
        public:
            XPathResultTypeArg() : RangedIntegerArg(0, 9) {}
        };

        class MouseButtonTypeArg : public RangedIntegerArg
        {
        public:
            MouseButtonTypeArg() : RangedIntegerArg(0, 5) {}
        };

        class TextEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MouseEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CompositionEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UIEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MessageEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class EventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class MutationEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class AttrChangeTypeArg : public RangedIntegerArg
        {
        public:
            AttrChangeTypeArg() : RangedIntegerArg(0, 3) {}
        };

        class KeyboardEventTypeArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class KeyLocationTypeArg : public RangedIntegerArg
        {
        public:
            KeyLocationTypeArg() : RangedIntegerArg(0, 5) {}
        };

        class DummyUrlArg : public ConstStringArg
        {
        public:
            DummyUrlArg() : ConstStringArg("x") {}
        };

        /*
        * Dynamic arg
        */
        class SlotArg : public Arg
        {
        private:
            Object *slot;

        public:
            SlotArg();
            bool is_object();
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class UseMapArg : public Arg
        {
        private:
            Object *m_map;

        public:
            UseMapArg();
            bool is_object();
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class ContentSelectArg : public Arg
        {
        private:
            string cla;
            Object *elem;

        public:
            ContentSelectArg();
            bool is_object();
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class LabelForArg : public Arg
        {
        private:
            Object *elem;

        public:
            LabelForArg();
            bool is_object();
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class TableHeadersArg : public Arg
        {
        private:
            vector<Object *> ths;

        public:
            bool is_object();

            void append_th(JSContext *context);
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSSelectorValueArg : public Arg
        {
        private:
            CSS::CSSSelector *selector;

        public:
            CSSSelectorValueArg();
            virtual ~CSSSelectorValueArg();
            bool is_object();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSStyleDeclarationValueArg : public Arg
        {
        private:
            CSS::CSSStyleDeclaration *style_declaration;

        public:
            CSSStyleDeclarationValueArg();
            virtual ~CSSStyleDeclarationValueArg();
            bool is_object();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSStyleRuleValueArg : public Arg
        {
        private:
            CSS::CSSStyleRule *rule;

        public:
            CSSStyleRuleValueArg();
            virtual ~CSSStyleRuleValueArg();
            bool is_object();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSStyleRuleValueTextArg : public Arg
        {
        private:
            CSS::CSSStyleRule *rule;

        public:
            CSSStyleRuleValueTextArg();
            virtual ~CSSStyleRuleValueTextArg();
            bool is_object();
            void generate(JSContext *context);
            bool mutate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSKeyframeNameArg : public StringArg
        {
        public:
            void generate(JSContext *context);
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };

        class CSSKeyframeRuleValueArg : public Arg
        {
        private:
            CSS::CSSKeyframeRule *keyframe_rule;

        public:
            CSSKeyframeRuleValueArg(bool is_serialize = false);
            virtual ~CSSKeyframeRuleValueArg();
            bool is_object();
            bool mutate(JSContext *context);
            void generate(JSContext *context);
            void merge_fix(map<Object *, Object *> &merge_map);
            operator string();
            void serialize(SerializeStream *stream, JSContext *context);
            void unserialize(UnSerializeStream *stream, Document *global_document, Function *function);
        };
    }
}
#endif