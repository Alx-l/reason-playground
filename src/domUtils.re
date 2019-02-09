open Webapi.Dom;

let appendChild = (~child: Dom.element, ~target = ?, ()) => {
  switch (document |> Document.asHtmlDocument) {
  | Some(doc) =>
    switch (target) {
    | Some(target) => Some(Element.appendChild(child, target))
    | None =>
      HtmlDocument.body(doc)
      |> Belt_Option.map(_, body => Element.appendChild(child, body))
    }
  | None => None
  };
};

[@bs.val]
external unsafeAppendChild: Dom.element => Dom.element =
  "document.body.appendChild";

[@bs.get] external unsafeTargetValue: Dom.eventTarget => string = "value";
