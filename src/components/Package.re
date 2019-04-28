/* State declaration */
type state = {
  selected: bool,
};

/* Action declaration */
type action =
  | Toggle;

module Styles = {
  open Css;

  let card = selected => style([
    borderWidth(selected ? `px(3) : `px(1))
  ])

  let cardBody = selected => style([
    background(selected ? whitesmoke : white)
  ])
}

let component = ReasonReact.reducerComponent("Card");

let make = (~destination, ~tagLine, ~description, ~image: string, ~footerText, _children) => {
  ...component,

  initialState: () => {selected: false},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({...state, selected: !state.selected})
    },

  render: _self =>
  <div onClick=(_event => _self.send(Toggle)) className={Styles.card(_self.state.selected) ++ " card border-secondary mb-3"}>
    <h5 className="card-header">{destination->ReasonReact.string}</h5>
    <img src=image className="card-img-top" alt="..."/>
    <div className={Styles.cardBody(_self.state.selected) ++ " card-body"}>
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
