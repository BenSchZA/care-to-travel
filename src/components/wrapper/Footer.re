let component = ReasonReact.statelessComponent("Footer");

module Styles = {
  open Css;

  let footer = style([
    padding(px(2)),
  ])
}

let make = _children => {
  ...component,
  render: _self => (
    <footer className=Styles.footer>
      <p>"Copyright 2019 'Care to Travel'"->ReasonReact.string</p>
    </footer>
  )
}