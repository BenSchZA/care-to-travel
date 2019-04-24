let component = ReasonReact.statelessComponent("Footer");

module Styles = {
  open Css;

  let footer = style([
    padding(px(2)),
    backgroundColor(lightgrey)
  ])
}

let make = _children => {
  ...component,
  render: _self => (
    <footer className=Styles.footer>
      <p>"Copyright 2019 'Care To Travel'"->ReasonReact.string</p>
      <p>"Contact "->ReasonReact.string<a href="mailto:someone@example.com">
      "info@caretotravel.com"->ReasonReact.string</a></p>
    </footer>
  )
}