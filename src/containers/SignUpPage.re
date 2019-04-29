open Belt.Option;

let component = ReasonReact.statelessComponent("SignUpPage");

[@bs.module] external capeTown : string = "../static/cape-town.jpg";
[@bs.module] external london : string = "../static/london.jpg";
[@bs.module] external rome : string = "../static/rome.jpg";

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
let make = _children => {
  ...component,
  render: _self =>
    <div className="App-section">
      <p className="h4" id="sign-up">
        (ReasonReact.string("Sign up and select a travel package"))
      </p>
      <div className="container">
        <div className="row">
          <div className="col">
          </div>
          <div className="col-8">
            <SignUp />
          </div>
          <div className="col">
          </div>
        </div>
        <div className="row">
          <div className="col">
          </div>
          <div className="col-12">
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
          <div className="col">
          </div>
        </div>
      </div>
    </div>
}
