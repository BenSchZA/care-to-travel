open Tea_app;
open Tea_html;

/*
 MODEL
  */
let init = () => 4;

/*
 UPDATE
 */
[@bs.deriving {accessors: accessors}]
type msg =
  | Increment
  | Decrement
  | Reset
  | Set(int);

let update = model =>
  fun
  | Increment => model + 1
  | Decrement => model - 1
  | Reset => 0
  | Set(v) => v;

/*
 VIEW
  */
/* Global Style Example */
Css.(
  global(
    "body",
    [padding(px(0)), margin(px(0)), backgroundColor(white)],
  )
);

/* Styles Definition Example */
module Styles = {
  open Css;

  let header =
    Css.style([
      padding(px(20)),
      margin(px(0)),
      backgroundColor(black),
      textAlign(center),
    ]);

  let headline = Css.style([margin(px(0)), color(rgb(230, 230, 230))]);

  let container =
    Css.style([
      display(flexBox),
      justifyContent(center),
      backgroundColor(white),
      margin(px(20)),
    ]);

  let number = Css.style([fontSize(px(100))]);
};

let view_button = (title, msg) => button([onClick(msg)], [text(title)]);

let view = model =>
  div(
    [],
    [
      header(
        [class'(Styles.header)],
        [
          h1(
            [class'(Styles.headline)],
            [text("BuckleScript Tea Starter Kit")],
          ),
        ],
      ),
      nav(
        [class'(Styles.container)],
        [
          br([]),
          view_button("Increment", Increment),
          br([]),
          view_button("Decrement", Decrement),
          br([]),
          view_button("Set to 42", Set(42)),
          br([]),
          if (model != 0) {
            view_button("Reset", Reset);
          } else {
            noNode;
          },
        ],
      ),
      div(
        [class'(Styles.container)],
        [span([class'(Styles.number)], [text(string_of_int(model))])],
      ),
    ],
  );

/*
 MAIN
 */
let main = beginnerProgram({model: init(), update, view});

/*
 EXAMPLE CONSOLE LOG (using BuckleScripts Js module)
  */
Js.log("Hello, from BuckleScript and Reason!");

type document; /* abstract type for a document object */
[@bs.send] external getElementById: (document, string) => Js.null_undefined(Web.Node.t) = "getElementById";
[@bs.val] external doc: document = "document";

type action = RenderMain;
type state = Start | Initialized;

let id = "Tea";
let component = ReasonReact.reducerComponent(id);
let make = _children => {
  ...component,
  initialState: _state => Start,
  reducer: (action, _state) =>
    switch (action) {
      | RenderMain => {
        let interface = main(getElementById(doc, id));
        let pushMsg = interface()##pushMsg;
        pushMsg(Reset);
        ReasonReact.Update(Initialized);
      }
    },
  didMount: self => self.send(RenderMain),
  render: _self => <div id=id />
}