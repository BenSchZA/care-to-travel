let component = ReasonReact.statelessComponent("Packages");

module Styles = {
  open Css;

  let layout = style([
    padding(`px(20))
  ])
}

let make = _children => {
  ...component,
  render: _self =>
  <div className=Styles.layout>
    <CardDeck>
      ..._children
    </CardDeck>
  </div>
};