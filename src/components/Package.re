module Styles = {
  open Css;

  let card = selected => style([
    borderWidth(selected ? `px(3) : `px(0)),
  ])

  let cardBody = selected => style([
    // background(selected ? whitesmoke : white)
  ])
}

let component = ReasonReact.statelessComponent("Card");

let make = (~selected, ~onSelect, ~destination, ~tagLine, ~description, ~image: string, ~footerText, _children) => {
  ...component,
  render: _self =>
  <div onClick=(_event => onSelect()) className={Styles.card(selected) ++ " card border-secondary mb-3"}>
    <h5 className="card-header">{destination->ReasonReact.string}</h5>
    <img src=image className="card-img-top" alt="..."/>
    <div className={Styles.cardBody(selected) ++ " card-body"}>
      <h5 className="card-title">{tagLine->ReasonReact.string}</h5>
      <p className="card-text">{description->ReasonReact.string}</p>
    </div>
    <div className="card-footer">
      <small className="text-muted">
        {footerText->ReasonReact.string}
      </small>
    </div>
  </div>
}
