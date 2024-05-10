#ifndef HM_JS_HTML_RET_H
#define HM_JS_HTML_RET_H

#include "ret.h"

namespace HIRMutate
{
    namespace JS
    {
        class DocumentRet : public Ret
        {
        public:
            DocumentRet() : Ret("Document") {}
        };

        class WindowRet : public Ret
        {
        public:
            WindowRet() : Ret("Window") {}
        };

        class DOMTokenListRet : public Ret
        {
        public:
            DOMTokenListRet() : Ret("DOMTokenList") {}
        };

        class URLRet : public Ret
        {
        public:
            URLRet() : Ret("URL") {}
        };

        class FormDataRet : public Ret
        {
        public:
            FormDataRet() : Ret("FormData") {}
        };

        class URLSearchParamsRet : public Ret
        {
        public:
            URLSearchParamsRet() : Ret("URLSearchParams") {}
        };

        class DOMStringMapRet : public Ret
        {
        public:
            DOMStringMapRet() : Ret("DOMStringMap") {}
        };

        class AttrRet : public Ret
        {
        public:
            AttrRet() : Ret("Attr") {}
        };

        class DOMImplementationRet : public Ret
        {
        public:
            DOMImplementationRet() : Ret("DOMImplementation") {}
        };

        class NamedNodeMapRet : public Ret
        {
        public:
            NamedNodeMapRet() : Ret("NamedNodeMap") {}
        };

        class ApplicationCacheRet : public Ret
        {
        public:
            ApplicationCacheRet() : Ret("ApplicationCache") {}
        };

        class XPathEvaluatorRet : public Ret
        {
        public:
            XPathEvaluatorRet() : Ret("XPathEvaluator") {}
        };

        class XPathNSResolverRet : public Ret
        {
        public:
            XPathNSResolverRet() : Ret("XPathNSResolver") {}
        };

        class XPathExpressionRet : public Ret
        {
        public:
            XPathExpressionRet() : Ret("XPathExpression") {}
        };

        class XPathResultRet : public Ret
        {
        public:
            XPathResultRet() : Ret("XPathResult") {}
        };

        class XMLSerializerRet : public Ret
        {
        public:
            XMLSerializerRet() : Ret("XMLSerializer") {}
        };

        class DOMParserRet : public Ret
        {
        public:
            DOMParserRet() : Ret("DOMParser") {}
        };

        class XSLTProcessorRet : public Ret
        {
        public:
            XSLTProcessorRet() : Ret("XSLTProcessor") {}
        };

        class DataTransferRet : public Ret
        {
        public:
            DataTransferRet() : Ret("DataTransfer") {}
        };

        class DataTransferItemListRet : public Ret
        {
        public:
            DataTransferItemListRet() : Ret("DataTransferItemList") {}
        };

        class DataTransferItemRet : public Ret
        {
        public:
            DataTransferItemRet() : Ret("DataTransferItem") {}
        };

        class FontFaceSetRet : public Ret
        {
        public:
            FontFaceSetRet() : Ret("FontFaceSet") {}
        };

        class FontFaceRet : public Ret
        {
        public:
            FontFaceRet() : Ret("FontFace") {}
        };

        class EventRet : public Ret
        {
        public:
            EventRet() : Ret("Event") {}
        };

        class EventTargetRet : public Ret
        {
        public:
            EventTargetRet() : Ret("EventTarget") {}
        };

        class EventTargetsRet : public Ret
        {
        public:
            EventTargetsRet() : Ret("EventTargets") {}
        };

        class CustomEventRet : public Ret
        {
        public:
            CustomEventRet() : Ret("CustomEvent") {}
        };

        class MediaQueryListEventRet : public Ret
        {
        public:
            MediaQueryListEventRet() : Ret("MediaQueryListEvent") {}
        };

        class ApplicationCacheErrorEventRet : public Ret
        {
        public:
            ApplicationCacheErrorEventRet() : Ret("ApplicationCacheErrorEvent") {}
        };

        class SecurityPolicyViolationEventRet : public Ret
        {
        public:
            SecurityPolicyViolationEventRet() : Ret("SecurityPolicyViolationEvent") {}
        };

        class BeforeUnloadEventRet : public Ret
        {
        public:
            BeforeUnloadEventRet() : Ret("BeforeUnloadEvent") {}
        };

        class UIEventRet : public Ret
        {
        public:
            UIEventRet() : Ret("UIEvent") {}
        };

        class PointerEventRet : public Ret
        {
        public:
            PointerEventRet() : Ret("PointerEvent") {}
        };

        class PromiseRejectionEventRet : public Ret
        {
        public:
            PromiseRejectionEventRet() : Ret("PromiseRejectionEvent") {}
        };

        class FocusEventRet : public Ret
        {
        public:
            FocusEventRet() : Ret("FocusEvent") {}
        };

        class CompositionEventRet : public Ret
        {
        public:
            CompositionEventRet() : Ret("CompositionEvent") {}
        };

        class InputEventRet : public Ret
        {
        public:
            InputEventRet() : Ret("InputEvent") {}
        };

        class InputDeviceCapabilitiesRet : public Ret
        {
        public:
            InputDeviceCapabilitiesRet() : Ret("InputDeviceCapabilities") {}
        };

        class ResourceProgressEventRet : public Ret
        {
        public:
            ResourceProgressEventRet() : Ret("ResourceProgressEvent") {}
        };

        class TextEventRet : public Ret
        {
        public:
            TextEventRet() : Ret("TextEvent") {}
        };

        class ClipboardEventRet : public Ret
        {
        public:
            ClipboardEventRet() : Ret("ClipboardEvent") {}
        };

        class ProgressEventRet : public Ret
        {
        public:
            ProgressEventRet() : Ret("ProgressEvent") {}
        };

        class WheelEventRet : public Ret
        {
        public:
            WheelEventRet() : Ret("WheelEvent") {}
        };

        class HashChangeEventRet : public Ret
        {
        public:
            HashChangeEventRet() : Ret("HashChangeEvent") {}
        };

        class MouseEventRet : public Ret
        {
        public:
            MouseEventRet() : Ret("MouseEvent") {}
        };

        class TransitionEventRet : public Ret
        {
        public:
            TransitionEventRet() : Ret("TransitionEvent") {}
        };

        class AnimationPlaybackEventRet : public Ret
        {
        public:
            AnimationPlaybackEventRet() : Ret("AnimationPlaybackEvent") {}
        };

        class PopStateEventRet : public Ret
        {
        public:
            PopStateEventRet() : Ret("PopStateEvent") {}
        };

        class DragEventRet : public Ret
        {
        public:
            DragEventRet() : Ret("DragEvent") {}
        };

        class PageTransitionEventRet : public Ret
        {
        public:
            PageTransitionEventRet() : Ret("PageTransitionEvent") {}
        };

        class MessageEventRet : public Ret
        {
        public:
            MessageEventRet() : Ret("MessageEvent") {}
        };

        class MutationEventRet : public Ret
        {
        public:
            MutationEventRet() : Ret("MutationEvent") {}
        };

        class AnimationEventRet : public Ret
        {
        public:
            AnimationEventRet() : Ret("AnimationEvent") {}
        };

        class ErrorEventRet : public Ret
        {
        public:
            ErrorEventRet() : Ret("ErrorEvent") {}
        };

        class KeyboardEventRet : public Ret
        {
        public:
            KeyboardEventRet() : Ret("KeyboardEvent") {}
        };

        class CustomElementRegistryRet : public Ret
        {
        public:
            CustomElementRegistryRet() : Ret("CustomElementRegistry") {}
        };

        class BarPropRet : public Ret
        {
        public:
            BarPropRet() : Ret("BarProp") {}
        };

        class ScreenRet : public Ret
        {
        public:
            ScreenRet() : Ret("Screen") {}
        };

        class HistoryRet : public Ret
        {
        public:
            HistoryRet() : Ret("History") {}
        };

        class VisualViewportRet : public Ret
        {
        public:
            VisualViewportRet() : Ret("VisualViewport") {}
        };

        class NavigatorRet : public Ret
        {
        public:
            NavigatorRet() : Ret("Navigator") {}
        };

        class BlobRet : public Ret
        {
        public:
            BlobRet() : Ret("Blob") {}
        };

        class StyleSheetRet : public Ret
        {
        public:
            StyleSheetRet() : Ret("StyleSheet") {}
        };

        class CSSStyleSheetRet : public Ret
        {
        public:
            CSSStyleSheetRet() : Ret("CSSStyleSheet") {}
        };

        class CSSKeyframesSheetRet : public Ret
        {
        public:
            CSSKeyframesSheetRet() : Ret("CSSKeyframesSheet") {}
        };

        class CSSStyleRuleListRet : public Ret
        {
        public:
            CSSStyleRuleListRet() : Ret("CSSStyleRuleList") {}
        };

        class CSSKeyframesRuleListRet : public Ret
        {
        public:
            CSSKeyframesRuleListRet() : Ret("CSSKeyframesRuleList") {}
        };

        class CSSKeyframeRuleListRet : public Ret
        {
        public:
            CSSKeyframeRuleListRet() : Ret("CSSKeyframeRuleList") {}
        };

        class CSSRuleRet : public Ret
        {
        public:
            CSSRuleRet() : Ret("CSSRule") {}
        };

        class CSSStyleRuleRet : public Ret
        {
        public:
            CSSStyleRuleRet() : Ret("CSSStyleRule") {}
        };

        class CSSKeyframesRuleRet : public Ret
        {
        public:
            CSSKeyframesRuleRet() : Ret("CSSKeyframesRule") {}
        };

        class CSSKeyframeRuleRet : public Ret
        {
        public:
            CSSKeyframeRuleRet() : Ret("CSSKeyframeRule") {}
        };

        class CSSStyleDeclarationRet : public Ret
        {
        public:
            CSSStyleDeclarationRet() : Ret("CSSStyleDeclaration") {}
        };

        class ShadowRootRet : public Ret
        {
        public:
            ShadowRootRet() : Ret("ShadowRoot") {}
        };

        class DocumentOrShadowRootRet : public Ret
        {
        public:
            DocumentOrShadowRootRet() : Ret("DocumentOrShadowRoot") {}
        };

        class DocumentTypeRet : public Ret
        {
        public:
            DocumentTypeRet() : Ret("DocumentType") {}
        };

        /* class DocumentRet: public Ret {
public:
    DocumentRet():Ret("Document") {} 
};
*/

        class ElementRet : public Ret
        {
        public:
            ElementRet() : Ret("Element") {}
        };

        class CharacterDataRet : public Ret
        {
        public:
            CharacterDataRet() : Ret("CharacterData") {}
        };

        class DocumentFragmentRet : public Ret
        {
        public:
            DocumentFragmentRet() : Ret("DocumentFragment") {}
        };

        class CommentRet : public Ret
        {
        public:
            CommentRet() : Ret("Comment") {}
        };

        class TextRet : public Ret
        {
        public:
            TextRet() : Ret("Text") {}
        };

        class CDATASectionRet : public Ret
        {
        public:
            CDATASectionRet() : Ret("CDATASection") {}
        };

        class EventHandlerRet : public Ret
        {
        public:
            EventHandlerRet() : Ret("EventHandler") {}
        };

        class SelectionRet : public Ret
        {
        public:
            SelectionRet() : Ret("Selection") {}
        };

        class DocumentTimelineRet : public Ret
        {
        public:
            DocumentTimelineRet() : Ret("DocumentTimeline") {}
        };

        class TreeWalkerRet : public Ret
        {
        public:
            TreeWalkerRet() : Ret("TreeWalker") {}
        };

        class NodeIteratorRet : public Ret
        {
        public:
            NodeIteratorRet() : Ret("NodeIterator") {}
        };

        class NodeFilterRet : public Ret
        {
        public:
            NodeFilterRet() : Ret("NodeFilter") {}
        };

        class RangeRet : public Ret
        {
        public:
            RangeRet() : Ret("Range") {}
        };

        class StaticRangesRet : public Ret
        {
        public:
            StaticRangesRet() : Ret("StaticRanges") {}
        };

        class StaticRangeRet : public Ret
        {
        public:
            StaticRangeRet() : Ret("StaticRange") {}
        };

        class TimeRangesRet : public Ret
        {
        public:
            TimeRangesRet() : Ret("TimeRanges") {}
        };

        class DOMRectRet : public Ret
        {
        public:
            DOMRectRet() : Ret("DOMRect") {}
        };

        class NodeListRet : public Ret
        {
        public:
            NodeListRet() : Ret("NodeList") {}
        };

        class ElementListRet : public Ret
        {
        public:
            ElementListRet() : Ret("ElementList") {}
        };

        class DOMRectListRet : public Ret
        {
        public:
            DOMRectListRet() : Ret("DOMRectList") {}
        };

        class HTMLCollectionRet : public Ret
        {
        public:
            HTMLCollectionRet() : Ret("HTMLCollection") {}
        };

        class HTMLAllCollectionRet : public Ret
        {
        public:
            HTMLAllCollectionRet() : Ret("HTMLAllCollection") {}
        };

        class HTMLOptionsCollectionRet : public Ret
        {
        public:
            HTMLOptionsCollectionRet() : Ret("HTMLOptionsCollection") {}
        };

        class HTMLElementListRet : public Ret
        {
        public:
            HTMLElementListRet() : Ret("HTMLElementList") {}
        };

        class HTMLLabelElementListRet : public Ret
        {
        public:
            HTMLLabelElementListRet() : Ret("HTMLLabelElementList") {}
        };

        class HTMLTableCellsCollectionRet : public Ret
        {
        public:
            HTMLTableCellsCollectionRet() : Ret("HTMLTableCellsCollection") {}
        };

        class HTMLTableRowsCollectionRet : public Ret
        {
        public:
            HTMLTableRowsCollectionRet() : Ret("HTMLTableRowsCollection") {}
        };

        class HTMLTableSectionsCollectionRet : public Ret
        {
        public:
            HTMLTableSectionsCollectionRet() : Ret("HTMLTableSectionsCollection") {}
        };

        class HTMLAreasCollectionRet : public Ret
        {
        public:
            HTMLAreasCollectionRet() : Ret("HTMLAreasCollection") {}
        };

        class AnimationEffectTimingReadOnlyRet : public Ret
        {
        public:
            AnimationEffectTimingReadOnlyRet() : Ret("AnimationEffectTimingReadOnly") {}
        };

        class AnimationEffectReadOnlyRet : public Ret
        {
        public:
            AnimationEffectReadOnlyRet() : Ret("AnimationEffectReadOnly") {}
        };

        class AnimationEffectTimingRet : public Ret
        {
        public:
            AnimationEffectTimingRet() : Ret("AnimationEffectTiming") {}
        };

        class AnimationsRet : public Ret
        {
        public:
            AnimationsRet() : Ret("Animations") {}
        };

        class AnimationRet : public Ret
        {
        public:
            AnimationRet() : Ret("Animation") {}
        };

        class AnimationTimelineRet : public Ret
        {
        public:
            AnimationTimelineRet() : Ret("AnimationTimeline") {}
        };

        class KeyframeEffectRet : public Ret
        {
        public:
            KeyframeEffectRet() : Ret("KeyframeEffect") {}
        };

        class ValidityStateRet : public Ret
        {
        public:
            ValidityStateRet() : Ret("ValidityState") {}
        };

        class MediaErrorRet : public Ret
        {
        public:
            MediaErrorRet() : Ret("MediaError") {}
        };

        class MediaControllerRet : public Ret
        {
        public:
            MediaControllerRet() : Ret("MediaController") {}
        };

        class MediaSessionRet : public Ret
        {
        public:
            MediaSessionRet() : Ret("MediaSession") {}
        };

        class MediaStreamRet : public Ret
        {
        public:
            MediaStreamRet() : Ret("MediaStream") {}
        };

        class VideoPlaybackQualityRet : public Ret
        {
        public:
            VideoPlaybackQualityRet() : Ret("VideoPlaybackQuality") {}
        };

        class TextTrackListRet : public Ret
        {
        public:
            TextTrackListRet() : Ret("TextTrackList") {}
        };

        class TextTrackCueListRet : public Ret
        {
        public:
            TextTrackCueListRet() : Ret("TextTrackCueList") {}
        };

        class TextTrackCueRet : public Ret
        {
        public:
            TextTrackCueRet() : Ret("TextTrackCue") {}
        };

        class TextTrackRet : public Ret
        {
        public:
            TextTrackRet() : Ret("TextTrack") {}
        };

        class VideoTrackListRet : public Ret
        {
        public:
            VideoTrackListRet() : Ret("VideoTrackList") {}
        };

        class VideoTrackRet : public Ret
        {
        public:
            VideoTrackRet() : Ret("VideoTrack") {}
        };

        class AudioTrackListRet : public Ret
        {
        public:
            AudioTrackListRet() : Ret("AudioTrackList") {}
        };

        class AudioTrackRet : public Ret
        {
        public:
            AudioTrackRet() : Ret("AudioTrack") {}
        };

        class VTTRegionListRet : public Ret
        {
        public:
            VTTRegionListRet() : Ret("VTTRegionList") {}
        };

        class VTTRegionRet : public Ret
        {
        public:
            VTTRegionRet() : Ret("VTTRegion") {}
        };

        class VTTCueRet : public Ret
        {
        public:
            VTTCueRet() : Ret("VTTCue") {}
        };

        class HTMLElementRet : public Ret
        {
        public:
            HTMLElementRet() : Ret("HTMLElement") {}
        };

        class HTMLTableSectionElementRet : public Ret
        {
        public:
            HTMLTableSectionElementRet() : Ret("HTMLTableSectionElement") {}
        };

        class HTMLTableCellElementRet : public Ret
        {
        public:
            HTMLTableCellElementRet() : Ret("HTMLTableCellElement") {}
        };

        class HTMLQuoteElementRet : public Ret
        {
        public:
            HTMLQuoteElementRet() : Ret("HTMLQuoteElement") {}
        };

        class HTMLAnchorElementRet : public Ret
        {
        public:
            HTMLAnchorElementRet() : Ret("HTMLAnchorElement") {}
        };

        class HTMLAbbrElementRet : public Ret
        {
        public:
            HTMLAbbrElementRet() : Ret("HTMLAbbrElement") {}
        };

        class HTMLAcronymElementRet : public Ret
        {
        public:
            HTMLAcronymElementRet() : Ret("HTMLAcronymElement") {}
        };

        class HTMLAddressElementRet : public Ret
        {
        public:
            HTMLAddressElementRet() : Ret("HTMLAddressElement") {}
        };

        class HTMLAreaElementRet : public Ret
        {
        public:
            HTMLAreaElementRet() : Ret("HTMLAreaElement") {}
        };

        class HTMLArticleElementRet : public Ret
        {
        public:
            HTMLArticleElementRet() : Ret("HTMLArticleElement") {}
        };

        class HTMLAsideElementRet : public Ret
        {
        public:
            HTMLAsideElementRet() : Ret("HTMLAsideElement") {}
        };

        class HTMLAudioElementRet : public Ret
        {
        public:
            HTMLAudioElementRet() : Ret("HTMLAudioElement") {}
        };

        class HTMLBElementRet : public Ret
        {
        public:
            HTMLBElementRet() : Ret("HTMLBElement") {}
        };

        class HTMLBaseFontElementRet : public Ret
        {
        public:
            HTMLBaseFontElementRet() : Ret("HTMLBaseFontElement") {}
        };

        class HTMLBDIElementRet : public Ret
        {
        public:
            HTMLBDIElementRet() : Ret("HTMLBDIElement") {}
        };

        class HTMLBDOElementRet : public Ret
        {
        public:
            HTMLBDOElementRet() : Ret("HTMLBDOElement") {}
        };

        class HTMLBgSoundElementRet : public Ret
        {
        public:
            HTMLBgSoundElementRet() : Ret("HTMLBgSoundElement") {}
        };

        class HTMLBigElementRet : public Ret
        {
        public:
            HTMLBigElementRet() : Ret("HTMLBigElement") {}
        };

        class HTMLBlockQuoteElementRet : public Ret
        {
        public:
            HTMLBlockQuoteElementRet() : Ret("HTMLBlockQuoteElement") {}
        };

        class HTMLBRElementRet : public Ret
        {
        public:
            HTMLBRElementRet() : Ret("HTMLBRElement") {}
        };

        class HTMLButtonElementRet : public Ret
        {
        public:
            HTMLButtonElementRet() : Ret("HTMLButtonElement") {}
        };

        class HTMLCanvasElementRet : public Ret
        {
        public:
            HTMLCanvasElementRet() : Ret("HTMLCanvasElement") {}
        };

        class HTMLTableCaptionElementRet : public Ret
        {
        public:
            HTMLTableCaptionElementRet() : Ret("HTMLTableCaptionElement") {}
        };

        class HTMLCenterElementRet : public Ret
        {
        public:
            HTMLCenterElementRet() : Ret("HTMLCenterElement") {}
        };

        class HTMLCiteElementRet : public Ret
        {
        public:
            HTMLCiteElementRet() : Ret("HTMLCiteElement") {}
        };

        class HTMLCodeElementRet : public Ret
        {
        public:
            HTMLCodeElementRet() : Ret("HTMLCodeElement") {}
        };

        class HTMLTableColElementRet : public Ret
        {
        public:
            HTMLTableColElementRet() : Ret("HTMLTableColElement") {}
        };

        class HTMLTableColGroupElementRet : public Ret
        {
        public:
            HTMLTableColGroupElementRet() : Ret("HTMLTableColGroupElement") {}
        };

        class HTMLCommandElementRet : public Ret
        {
        public:
            HTMLCommandElementRet() : Ret("HTMLCommandElement") {}
        };

        class HTMLContentElementRet : public Ret
        {
        public:
            HTMLContentElementRet() : Ret("HTMLContentElement") {}
        };

        class HTMLDataElementRet : public Ret
        {
        public:
            HTMLDataElementRet() : Ret("HTMLDataElement") {}
        };

        class HTMLDataListElementRet : public Ret
        {
        public:
            HTMLDataListElementRet() : Ret("HTMLDataListElement") {}
        };

        class HTMLDDElementRet : public Ret
        {
        public:
            HTMLDDElementRet() : Ret("HTMLDDElement") {}
        };

        class HTMLDelElementRet : public Ret
        {
        public:
            HTMLDelElementRet() : Ret("HTMLDelElement") {}
        };

        class HTMLDetailsElementRet : public Ret
        {
        public:
            HTMLDetailsElementRet() : Ret("HTMLDetailsElement") {}
        };

        class HTMLDFNElementRet : public Ret
        {
        public:
            HTMLDFNElementRet() : Ret("HTMLDFNElement") {}
        };

        class HTMLDialogElementRet : public Ret
        {
        public:
            HTMLDialogElementRet() : Ret("HTMLDialogElement") {}
        };

        class HTMLDirectoryElementRet : public Ret
        {
        public:
            HTMLDirectoryElementRet() : Ret("HTMLDirectoryElement") {}
        };

        class HTMLDivElementRet : public Ret
        {
        public:
            HTMLDivElementRet() : Ret("HTMLDivElement") {}
        };

        class HTMLDListElementRet : public Ret
        {
        public:
            HTMLDListElementRet() : Ret("HTMLDListElement") {}
        };

        class HTMLDTElementRet : public Ret
        {
        public:
            HTMLDTElementRet() : Ret("HTMLDTElement") {}
        };

        class HTMLEMElementRet : public Ret
        {
        public:
            HTMLEMElementRet() : Ret("HTMLEMElement") {}
        };

        class HTMLEmbedElementRet : public Ret
        {
        public:
            HTMLEmbedElementRet() : Ret("HTMLEmbedElement") {}
        };

        class HTMLFieldSetElementRet : public Ret
        {
        public:
            HTMLFieldSetElementRet() : Ret("HTMLFieldSetElement") {}
        };

        class HTMLFigCaptionElementRet : public Ret
        {
        public:
            HTMLFigCaptionElementRet() : Ret("HTMLFigCaptionElement") {}
        };

        class HTMLFigureElementRet : public Ret
        {
        public:
            HTMLFigureElementRet() : Ret("HTMLFigureElement") {}
        };

        class HTMLFontElementRet : public Ret
        {
        public:
            HTMLFontElementRet() : Ret("HTMLFontElement") {}
        };

        class HTMLFooterElementRet : public Ret
        {
        public:
            HTMLFooterElementRet() : Ret("HTMLFooterElement") {}
        };

        class HTMLFormElementRet : public Ret
        {
        public:
            HTMLFormElementRet() : Ret("HTMLFormElement") {}
        };

        class HTMLFrameElementRet : public Ret
        {
        public:
            HTMLFrameElementRet() : Ret("HTMLFrameElement") {}
        };

        class HTMLFrameSetElementRet : public Ret
        {
        public:
            HTMLFrameSetElementRet() : Ret("HTMLFrameSetElement") {}
        };

        class HTMLHeading1ElementRet : public Ret
        {
        public:
            HTMLHeading1ElementRet() : Ret("HTMLHeading1Element") {}
        };

        class HTMLHeading2ElementRet : public Ret
        {
        public:
            HTMLHeading2ElementRet() : Ret("HTMLHeading2Element") {}
        };

        class HTMLHeading3ElementRet : public Ret
        {
        public:
            HTMLHeading3ElementRet() : Ret("HTMLHeading3Element") {}
        };

        class HTMLHeading4ElementRet : public Ret
        {
        public:
            HTMLHeading4ElementRet() : Ret("HTMLHeading4Element") {}
        };

        class HTMLHeading5ElementRet : public Ret
        {
        public:
            HTMLHeading5ElementRet() : Ret("HTMLHeading5Element") {}
        };

        class HTMLHeading6ElementRet : public Ret
        {
        public:
            HTMLHeading6ElementRet() : Ret("HTMLHeading6Element") {}
        };

        class HTMLHeaderElementRet : public Ret
        {
        public:
            HTMLHeaderElementRet() : Ret("HTMLHeaderElement") {}
        };

        class HTMLHGroupElementRet : public Ret
        {
        public:
            HTMLHGroupElementRet() : Ret("HTMLHGroupElement") {}
        };

        class HTMLHRElementRet : public Ret
        {
        public:
            HTMLHRElementRet() : Ret("HTMLHRElement") {}
        };

        class HTMLIElementRet : public Ret
        {
        public:
            HTMLIElementRet() : Ret("HTMLIElement") {}
        };

        class HTMLIFrameElementRet : public Ret
        {
        public:
            HTMLIFrameElementRet() : Ret("HTMLIFrameElement") {}
        };

        class HTMLImageElementRet : public Ret
        {
        public:
            HTMLImageElementRet() : Ret("HTMLImageElement") {}
        };

        class HTMLInputElementRet : public Ret
        {
        public:
            HTMLInputElementRet() : Ret("HTMLInputElement") {}
        };

        class HTMLInsElementRet : public Ret
        {
        public:
            HTMLInsElementRet() : Ret("HTMLInsElement") {}
        };

        class HTMLIsIndexElementRet : public Ret
        {
        public:
            HTMLIsIndexElementRet() : Ret("HTMLIsIndexElement") {}
        };

        class HTMLKBDElementRet : public Ret
        {
        public:
            HTMLKBDElementRet() : Ret("HTMLKBDElement") {}
        };

        class HTMLKeygenElementRet : public Ret
        {
        public:
            HTMLKeygenElementRet() : Ret("HTMLKeygenElement") {}
        };

        class HTMLLabelElementRet : public Ret
        {
        public:
            HTMLLabelElementRet() : Ret("HTMLLabelElement") {}
        };

        class HTMLLegendElementRet : public Ret
        {
        public:
            HTMLLegendElementRet() : Ret("HTMLLegendElement") {}
        };

        class HTMLLIElementRet : public Ret
        {
        public:
            HTMLLIElementRet() : Ret("HTMLLIElement") {}
        };

        class HTMLLinkElementRet : public Ret
        {
        public:
            HTMLLinkElementRet() : Ret("HTMLLinkElement") {}
        };

        class HTMLStyleElementRet : public Ret
        {
        public:
            HTMLStyleElementRet() : Ret("HTMLStyleElement") {}
        };

        class HTMLListingElementRet : public Ret
        {
        public:
            HTMLListingElementRet() : Ret("HTMLListingElement") {}
        };

        class HTMLMainElementRet : public Ret
        {
        public:
            HTMLMainElementRet() : Ret("HTMLMainElement") {}
        };

        class HTMLMapElementRet : public Ret
        {
        public:
            HTMLMapElementRet() : Ret("HTMLMapElement") {}
        };

        class HTMLMarkElementRet : public Ret
        {
        public:
            HTMLMarkElementRet() : Ret("HTMLMarkElement") {}
        };

        class HTMLMarqueeElementRet : public Ret
        {
        public:
            HTMLMarqueeElementRet() : Ret("HTMLMarqueeElement") {}
        };

        class HTMLMenuElementRet : public Ret
        {
        public:
            HTMLMenuElementRet() : Ret("HTMLMenuElement") {}
        };

        class HTMLMenuItemElementRet : public Ret
        {
        public:
            HTMLMenuItemElementRet() : Ret("HTMLMenuItemElement") {}
        };

        class HTMLMetaElementRet : public Ret
        {
        public:
            HTMLMetaElementRet() : Ret("HTMLMetaElement") {}
        };

        class HTMLMeterElementRet : public Ret
        {
        public:
            HTMLMeterElementRet() : Ret("HTMLMeterElement") {}
        };

        class HTMLNavElementRet : public Ret
        {
        public:
            HTMLNavElementRet() : Ret("HTMLNavElement") {}
        };

        class HTMLObjectElementRet : public Ret
        {
        public:
            HTMLObjectElementRet() : Ret("HTMLObjectElement") {}
        };

        class HTMLOListElementRet : public Ret
        {
        public:
            HTMLOListElementRet() : Ret("HTMLOListElement") {}
        };

        class HTMLOptGroupElementRet : public Ret
        {
        public:
            HTMLOptGroupElementRet() : Ret("HTMLOptGroupElement") {}
        };

        class HTMLOptionElementRet : public Ret
        {
        public:
            HTMLOptionElementRet() : Ret("HTMLOptionElement") {}
        };

        class HTMLOutputElementRet : public Ret
        {
        public:
            HTMLOutputElementRet() : Ret("HTMLOutputElement") {}
        };

        class HTMLParagraphElementRet : public Ret
        {
        public:
            HTMLParagraphElementRet() : Ret("HTMLParagraphElement") {}
        };

        class HTMLParamElementRet : public Ret
        {
        public:
            HTMLParamElementRet() : Ret("HTMLParamElement") {}
        };

        class HTMLPictureElementRet : public Ret
        {
        public:
            HTMLPictureElementRet() : Ret("HTMLPictureElement") {}
        };

        class HTMLPlainTextElementRet : public Ret
        {
        public:
            HTMLPlainTextElementRet() : Ret("HTMLPlainTextElement") {}
        };

        class HTMLPreElementRet : public Ret
        {
        public:
            HTMLPreElementRet() : Ret("HTMLPreElement") {}
        };

        class HTMLProgressElementRet : public Ret
        {
        public:
            HTMLProgressElementRet() : Ret("HTMLProgressElement") {}
        };

        class HTMLQElementRet : public Ret
        {
        public:
            HTMLQElementRet() : Ret("HTMLQElement") {}
        };

        class HTMLRPElementRet : public Ret
        {
        public:
            HTMLRPElementRet() : Ret("HTMLRPElement") {}
        };

        class HTMLRTElementRet : public Ret
        {
        public:
            HTMLRTElementRet() : Ret("HTMLRTElement") {}
        };

        class HTMLRubyElementRet : public Ret
        {
        public:
            HTMLRubyElementRet() : Ret("HTMLRubyElement") {}
        };

        class HTMLSElementRet : public Ret
        {
        public:
            HTMLSElementRet() : Ret("HTMLSElement") {}
        };

        class HTMLSampElementRet : public Ret
        {
        public:
            HTMLSampElementRet() : Ret("HTMLSampElement") {}
        };

        class HTMLScriptElementRet : public Ret
        {
        public:
            HTMLScriptElementRet() : Ret("HTMLScriptElement") {}
        };

        class HTMLSectionElementRet : public Ret
        {
        public:
            HTMLSectionElementRet() : Ret("HTMLSectionElement") {}
        };

        class HTMLSelectElementRet : public Ret
        {
        public:
            HTMLSelectElementRet() : Ret("HTMLSelectElement") {}
        };

        class HTMLShadowElementRet : public Ret
        {
        public:
            HTMLShadowElementRet() : Ret("HTMLShadowElement") {}
        };

        class HTMLSlotElementRet : public Ret
        {
        public:
            HTMLSlotElementRet() : Ret("HTMLSlotElement") {}
        };

        class HTMLSmallElementRet : public Ret
        {
        public:
            HTMLSmallElementRet() : Ret("HTMLSmallElement") {}
        };

        class HTMLSourceElementRet : public Ret
        {
        public:
            HTMLSourceElementRet() : Ret("HTMLSourceElement") {}
        };

        class HTMLSpanElementRet : public Ret
        {
        public:
            HTMLSpanElementRet() : Ret("HTMLSpanElement") {}
        };

        class HTMLStrikeElementRet : public Ret
        {
        public:
            HTMLStrikeElementRet() : Ret("HTMLStrikeElement") {}
        };

        class HTMLStrongElementRet : public Ret
        {
        public:
            HTMLStrongElementRet() : Ret("HTMLStrongElement") {}
        };

        class HTMLSubElementRet : public Ret
        {
        public:
            HTMLSubElementRet() : Ret("HTMLSubElement") {}
        };

        class HTMLSummaryElementRet : public Ret
        {
        public:
            HTMLSummaryElementRet() : Ret("HTMLSummaryElement") {}
        };

        class HTMLSupElementRet : public Ret
        {
        public:
            HTMLSupElementRet() : Ret("HTMLSupElement") {}
        };

        class HTMLTimeElementRet : public Ret
        {
        public:
            HTMLTimeElementRet() : Ret("HTMLTimeElement") {}
        };

        class HTMLTableElementRet : public Ret
        {
        public:
            HTMLTableElementRet() : Ret("HTMLTableElement") {}
        };

        class HTMLTBodyElementRet : public Ret
        {
        public:
            HTMLTBodyElementRet() : Ret("HTMLTBodyElement") {}
        };

        class HTMLTableDataCellElementRet : public Ret
        {
        public:
            HTMLTableDataCellElementRet() : Ret("HTMLTableDataCellElement") {}
        };

        class HTMLTemplateElementRet : public Ret
        {
        public:
            HTMLTemplateElementRet() : Ret("HTMLTemplateElement") {}
        };

        class HTMLTextAreaElementRet : public Ret
        {
        public:
            HTMLTextAreaElementRet() : Ret("HTMLTextAreaElement") {}
        };

        class HTMLTFootElementRet : public Ret
        {
        public:
            HTMLTFootElementRet() : Ret("HTMLTFootElement") {}
        };

        class HTMLTableHeaderCellElementRet : public Ret
        {
        public:
            HTMLTableHeaderCellElementRet() : Ret("HTMLTableHeaderCellElement") {}
        };

        class HTMLTHeadElementRet : public Ret
        {
        public:
            HTMLTHeadElementRet() : Ret("HTMLTHeadElement") {}
        };

        class HTMLTitleElementRet : public Ret
        {
        public:
            HTMLTitleElementRet() : Ret("HTMLTitleElement") {}
        };

        class HTMLTableRowElementRet : public Ret
        {
        public:
            HTMLTableRowElementRet() : Ret("HTMLTableRowElement") {}
        };

        class HTMLTrackElementRet : public Ret
        {
        public:
            HTMLTrackElementRet() : Ret("HTMLTrackElement") {}
        };

        class HTMLTTElementRet : public Ret
        {
        public:
            HTMLTTElementRet() : Ret("HTMLTTElement") {}
        };

        class HTMLUElementRet : public Ret
        {
        public:
            HTMLUElementRet() : Ret("HTMLUElement") {}
        };

        class HTMLUListElementRet : public Ret
        {
        public:
            HTMLUListElementRet() : Ret("HTMLUListElement") {}
        };

        class HTMLVarElementRet : public Ret
        {
        public:
            HTMLVarElementRet() : Ret("HTMLVarElement") {}
        };

        class HTMLVideoElementRet : public Ret
        {
        public:
            HTMLVideoElementRet() : Ret("HTMLVideoElement") {}
        };

        class HTMLWBRElementRet : public Ret
        {
        public:
            HTMLWBRElementRet() : Ret("HTMLWBRElement") {}
        };

        class HTMLXMPElementRet : public Ret
        {
        public:
            HTMLXMPElementRet() : Ret("HTMLXMPElement") {}
        };

        class HTMLStringRet : public Ret
        {
        public:
            HTMLStringRet() : Ret("HTMLString") {}
        };

        class ShadowHostRet : public Ret
        {
        public:
            ShadowHostRet() : Ret("ShadowHost") {}
        };

        class MutationObserverRet : public Ret
        {
        public:
            MutationObserverRet() : Ret("MutationObserver") {}
        };

        class MutationRecordsRet : public Ret
        {
        public:
            MutationRecordsRet() : Ret("MutationRecords") {}
        };

        class MutationRecordRet : public Ret
        {
        public:
            MutationRecordRet() : Ret("MutationRecord") {}
        };

        class ProcessingInstructionRet : public Ret
        {
        public:
            ProcessingInstructionRet() : Ret("ProcessingInstruction") {}
        };

        class MessageChannelRet : public Ret
        {
        public:
            MessageChannelRet() : Ret("MessageChannel") {}
        };

        class MessagePortRet : public Ret
        {
        public:
            MessagePortRet() : Ret("MessagePort") {}
        };

        class RequestIDRet : public Ret
        {
        public:
            RequestIDRet() : Ret("RequestID") {}
        };

        class MediaQueryListRet : public Ret
        {
        public:
            MediaQueryListRet() : Ret("MediaQueryList") {}
        };

        class MediaListRet : public Ret
        {
        public:
            MediaListRet() : Ret("MediaList") {}
        };

        class StyleMediaRet : public Ret
        {
        public:
            StyleMediaRet() : Ret("StyleMedia") {}
        };
    }
}

#endif
