let component = ReasonReact.statelessComponent("Quote");

let make = _children => {
  ...component,
  render: _self =>
  <blockquote className="blockquote">
    <p className="mb-0">"Life is either a daring adventure or nothing at all."->ReasonReact.string</p>
    <footer className="blockquote-footer">"Helen Keller"->ReasonReact.string</footer>
  </blockquote>
}
