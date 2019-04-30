// open TeaML;
open TeaRE;

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