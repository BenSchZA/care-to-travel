open Belt.Option;

type package = {
  .
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

/* State declaration */
type state = {
  selectedPackageId: string,
};

/* Action declaration */
type action =
  | SelectPackage(string);

let component = ReasonReact.reducerComponent("SignUpPage");

let make = _children => {
  ...component,
  
  initialState: () => {selectedPackageId: ""},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | SelectPackage(id) => ReasonReact.Update({selectedPackageId: id})
    },

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
                          <Package
                            key=package##id
                            onSelect=(() => {_self.send(SelectPackage(package##id))})
                            selected=(_self.state.selectedPackageId == package##id)
                            destination=package##destination
                            tagLine=getWithDefault(package##tagLine, "")
                            description=getWithDefault(package##description, "")
                            image=getWithDefault(package##image, "")
                            footerText=getWithDefault(package##footerText, "")
                            />
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
