open Belt.Option;

let component = ReasonReact.statelessComponent("SignUpPage");

let make = _children => {
  ...component,
  render: _self =>
    <div className="App-header">
      <div className="App-content">
        <h4 className="display-4">(ReasonReact.string("Welcome to Care to Travel"))</h4>
        <Quote/>
        <ScrollDown/>
      </div>
    </div>
}


