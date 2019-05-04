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

type pushMsg = (msg) => unit;
let pushMsg: pushMsg = (msg) => ();
let pushMsgRef = ref(pushMsg);

type shutdown = (unit) => unit;
let shutdown: shutdown = () => ();

type getHtmlString = (unit) => string;
let getHtmlString: getHtmlString = () => "";

type interface = (unit) => Tea_app.programInterface(msg);

[@bs.obj]
external makeProgramInterface:
  (
    ~pushMsg: 'msg => unit,
    ~shutdown: unit => unit,
    ~getHtmlString: unit => string
  ) =>
  Tea_app.programInterface('msg) =
  "";

let interfaceRef = ref(makeProgramInterface(~pushMsg=(msg)=>(), ~shutdown=()=>(), ~getHtmlString=()=>""));

let id = "Tea";
let component = ReasonReact.reducerComponent(id);
let make = (_children) => {
  ...component,
  initialState: _state => Start,
  reducer: (_action, _state) =>
    switch (_action) {
      | RenderMain => UpdateWithSideEffects(Initialized, (_) => {
        {
          interfaceRef := main(getElementById(doc, id))();
          pushMsgRef := (interfaceRef^)##pushMsg;
          pushMsgRef^(Reset);
        }
      })
    },
  didMount: self => self.send(RenderMain),
  render: _self => <div id=id />
}
