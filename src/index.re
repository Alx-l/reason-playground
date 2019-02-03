type item = {
  name: string,
  id: int,
};

let items = [{name: "one", id: 1}, {name: "two", id: 2}];

let mapping =
  Belt_List.getBy(items, i => i.name === "two")
  |> Belt_Option.map(_, value => String.uppercase(value.name))
  |> Belt.Option.getWithDefault(_, "not found")
  |> Js.log;

let pmatching =
  (
    switch (Belt_List.getBy(items, i => i.name === "two")) {
    | Some(item) => String.uppercase(item.name)
    | None => "oops"
    }
  )
  |> Js.log;

open Webapi.Dom;

let app = document |> Document.querySelector("#app");

let handleClick = (evt: Dom.mouseEvent) => {
  Js.log(evt);
};

switch (app) {
| Some(elm) =>
  Element.addClickEventListener(handleClick, elm);
  Element.setInnerHTML(elm, "cool");
| None => ()
};
