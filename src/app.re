[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

[@bs.module] external capeTown : string = "./static/cape-town.jpg";
[@bs.module] external london : string = "./static/london.jpg";
[@bs.module] external rome : string = "./static/rome.jpg";

let ste = ReasonReact.string;
open Belt.Option;

type package = {
  id: string,
  destination: string,
  tagLine: option(string),
  description: option(string),
  image: option(string),
  footerText: option(string),
};

type packages = array(package);

module GetPackages = [%graphql {|
  {
    packages {
      id
      destination
      tagLine
      description
      image
      footerText
    }
  }
|}];
module GetPackagesQuery = ReasonApollo.CreateQuery(GetPackages);

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <Menu/>
      <div className="App-header">
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
          {
            let packagesQuery = GetPackages.make();
            <GetPackagesQuery>
              ...{
                ({result}) =>
                  switch (result) {
                  | Loading => <div> {ReasonReact.string("Loading")} </div>
                  | Error(error) => <div> {ReasonReact.string(error##message)} </div>
                  | Data(response) => {
                    response##packages
                    /* Remove Option of type None array entries */
                    |. Belt.Array.keepMap(package => package)
                    /* Map array to DOM elements */
                    |> Array.map(package => {
                      <Package key=package##id destination=package##destination tagLine="Trip of a lifetime" description="Text..." image=capeTown footerText="Footer text..."/>
                    })
                    /* Display array of elements */
                    |> ReasonReact.array;
                    }
                  }
              }
            </GetPackagesQuery>
          }
        </Packages>
      </div>
      <div className="App-footer">
        <Footer/>
      </div>
      /* <Tea/> */
    </div>,
};
