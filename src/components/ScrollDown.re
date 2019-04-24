let component = ReasonReact.statelessComponent("ScrollDown");

let make = _children => {
  ...component,
  render: _self =>
  <button className="btn btn-light btn-lg" type_="button"><a href="#sign-up">"Get started"->ReasonReact.string</a></button>
}