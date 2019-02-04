open Webapi.Dom;

let appendChild' = (elm: Dom.element) => {
  switch (document |> Document.asHtmlDocument) {
  | Some(doc) =>
    HtmlDocument.body(doc)
    |> Belt_Option.map(_, body => Element.appendChild(elm, body))
  | None => None
  };
};

[@bs.val]
external unesafeAppendChild: Dom.element => Dom.element = "document.body.appendChild";

[@bs.get] external unsafeTargetValue: Dom.eventTarget => string = "value";
