let component = ReasonReact.statelessComponent("CardDeck");

let make = _children => {
  ...component,
  render: _self =>
  <div className="card-deck">
    ..._children
  </div>
}