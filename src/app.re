[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open Routes;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {route: getInitialRoute()},
  reducer: (action, _) =>
    switch (action) {
    | UpdateRoute(route) => ReasonReact.Update({route: route})
  },
  didMount: ({send, onUnmount}) => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.hash) {
        | "sign-up" => SignUp->UpdateRoute->send
        | _ => Landing->UpdateRoute->send
        }
      );
    onUnmount(() => watcherID->ReasonReact.Router.unwatchUrl);
  },
  render: ({state}) =>
    <div className="App">
      <Menu/>
      {switch (state.route) {
        | Landing => <LandingPage />
        | SignUp => <SignUpPage />
      }}
      <div className="App-footer">
        <Footer/>
      </div>
    </div>,
};
