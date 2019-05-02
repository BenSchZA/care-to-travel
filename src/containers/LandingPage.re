let component = React.statelessComponent("SignUpPage");

module Styles = {
  open Css;

  let content = style([
    width(`vw(100.0)),
    maxWidth(`px(500))
  ])
}

let make = _children => {
  ...component,
  render: _self =>
    <div className="App-header">
      <div className=(Styles.content ++ " shadow p-3 mb-5 bg-white rounded")>
        <div className="globe" />
        <h1 className="display-4">(React.string("Welcome to"))</h1>
        <h1 className="display-3">(React.string("Care to Travel"))</h1>
        <h3>(React.string("Harnessing the collective buying power of the caring community to curate more affordable travel, while bringing people together."))</h3>
        // <Quote/>
        // <Tea />
        <ScrollDown/>
      </div>
    </div>
}


