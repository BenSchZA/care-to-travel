[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <Menu/>
      <div className="App-header">
        /* <img src=logo className="App-logo" alt="logo" /> */
        <div className="App-content">
          <h4 className="display-4">(ReasonReact.string(message))</h4>
          <Quote/>
          <ScrollDown/>
        </div>
      </div>
      <div className="App-section">
        <p className="h4" id="sign-up">
          (ReasonReact.string("Sign up and select a travel package"))
        </p>
        <Packages>
          <Package destination="Cape Town" tagLine="Trip of a lifetime" description="Text..." footerText="Footer text..."/>
          <Package destination="Rome" tagLine="Trip of a lifetime" description="Text..." footerText="Footer text..."/>
          <Package destination="London" tagLine="Trip of a lifetime" description="Text..." footerText="Footer text..."/>
        </Packages>
      </div>
      <div className="App-footer">
        <Footer/>
      </div>
      /* <Tea/> */
    </div>,
};
