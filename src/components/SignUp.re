[%bs.raw {|require('./pure.css')|}];

let component = ReasonReact.statelessComponent("SignUp");

let make = _children => {
  ...component,
  render: _self => <div/>
  /* <form className="pure-form pure-form-stacked">
    <fieldset>
        <legend>"Legend"->ReasonReact.string</legend>

        <div className="pure-g">
            <div className="pure-u-1 pure-u-md-1-3">
                <label for_="first-name">"First Name"->ReasonReact.string</label>
                <input id="first-name" className="pure-u-23-24" type_="text"/>
            </div>

            <div className="pure-u-1 pure-u-md-1-3">
                <label for_="last-name">"Last Name"->ReasonReact.string</label>
                <input id="last-name" className="pure-u-23-24" type_="text"/>
            </div>

            <div className="pure-u-1 pure-u-md-1-3">
                <label for_="email">"E-Mail"->ReasonReact.string</label>
                <input id="email" className="pure-u-23-24" type_="email" required/>
            </div>

            <div className="pure-u-1 pure-u-md-1-3">
                <label for_="city">"City"->ReasonReact.string</label>
                <input id="city" className="pure-u-23-24" type_="text"/>
            </div>
        </div>

        <label for_="terms" className="pure-checkbox">
            <input id="terms" type_="checkbox"/>"I've read the terms and conditions"->ReasonReact.string
        </label>
        <button type_="submit" className="pure-button pure-button-primary">"Submit"->ReasonReact.string</button>
    </fieldset>
  </form> */
}

