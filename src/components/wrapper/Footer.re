let copy = [%raw {|'\u00a9'|}];

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
      <p>{copy} " 2019 Care to Travel"->ReasonReact.string</p>
      <div>"Icons made by "->React.string<a href="https://www.flaticon.com/authors/good-ware" title="Good Ware">"Good Ware"->React.string</a>" from "->React.string<a href="https://www.flaticon.com/" title="Flaticon">"www.flaticon.com"->React.string</a>" is licensed by "->React.string<a href="http://creativecommons.org/licenses/by/3.0/" title="Creative Commons BY 3.0" target="_blank">"CC 3.0 BY"->React.string</a></div>
    </footer>
  )
}