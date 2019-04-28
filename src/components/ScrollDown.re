let component = ReasonReact.statelessComponent("ScrollDown");

module Styles = {
  open Css;

  let button = style([
    textDecoration(`none)
  ])
}

let make = _children => {
  ...component,
  render: _self =>
  <button className={Styles.button ++ " btn btn-light btn-lg"} type_="button"><a href="#sign-up">"Get started"->ReasonReact.string</a></button>
}