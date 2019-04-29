let component = ReasonReact.statelessComponent("SignUp");

module SignupForm = {
  open Formality;

  type field =
    | Email
    | Password
    | PasswordConfirmation;

  type state = {
    email: string,
    password: string,
    passwordConfirmation: string,
  };

  type message = string;
  type submissionError = unit;

  let debounceInterval = Formality.Async.debounceInterval;

  module EmailField = {
    let update = (state, value) => {...state, email: value};

    let validator =
      Async.{
        field: Email,
        strategy: OnFirstSuccessOrFirstBlur,
        dependents: None,
        validate: ({email}) => {
          let emailRegex = [%bs.re {|/.*@.*\..+/|}];
          switch (email) {
          | "" => Error("Email is required")
          | _ as value when !emailRegex->Js.Re.test_(value) =>
            Error("Email is invalid")
          | _ => Ok(Valid)
          };
        },
        validateAsync: None
          /* Some((
            state =>
              Js.Promise.(
                state.email
                ->Api.validateEmail
                ->then_(
                    valid =>
                      Result.(
                        valid
                          ? Ok(Valid)->resolve
                          : Error("Email is already taken")->resolve
                      ),
                    _,
                  )
              ),
            (prev, next) => prev.email == next.email,
          )), */
      };
  };

  module PasswordField = {
    let update = (state, value) => {...state, password: value};

    let validator =
      Async.{
        field: Password,
        strategy: OnFirstSuccessOrFirstBlur,
        dependents: [PasswordConfirmation]->Some,
        validate: ({password}) => {
          let minLength = 4;
          switch (password) {
          | "" => Error("Password is required")
          | _ when password->Js.String.length < minLength =>
            Error({j| $(minLength)+ characters, please|j})
          | _ => Ok(Valid)
          };
        },
        validateAsync: None,
      };
  };

  module PasswordConfirmationField = {
    let update = (state, value) => {...state, passwordConfirmation: value};

    let validator =
      Async.{
        field: PasswordConfirmation,
        strategy: Strategy.OnFirstSuccessOrFirstBlur,
        dependents: None,
        validate: ({password, passwordConfirmation}) =>
          switch (passwordConfirmation) {
          | "" => Error("Confirmation is required")
          | _ when passwordConfirmation !== password =>
            Error("Password doesn't match")
          | _ => Ok(Valid)
          },
        validateAsync: None,
      };
  };

  let validators = [
    EmailField.validator,
    PasswordField.validator,
    PasswordConfirmationField.validator,
  ];
};

module SignupFormContainer = Formality.Async.Make(SignupForm);

let make = _children => {
  ...component,
  render: _self =>
    <SignupFormContainer
      initialState={email: "", password: "", passwordConfirmation: ""}
      onSubmit={(state, form) => {
        Js.log2("Submitted with:", state);
        Js.Global.setTimeout(
          () => {
            form.notifyOnSuccess(None);
            form.reset->Js.Global.setTimeout(3000)->ignore;
          },
          500,
        )
        ->ignore;
      }}>
      ...{form =>
        <form
          onSubmit={form.submit->Formality.Dom.preventDefault}>
          <div className="form-group">
            <label htmlFor="signup--email">"Email address"->React.string</label>
            <input 
              type_="email" 
              className="form-control" 
              id="signup--email" 
              ariaDescribedby="emailHelp" 
              placeholder="Enter email"
              value={form.state.email}
              disabled={form.submitting}
              onBlur={_ => form.blur(Email)}
              onChange={event =>
                form.change(
                  Email,
                  SignupForm.EmailField.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            <small id="emailHelp" className="form-text text-muted">"We'll never share your email with anyone else."->React.string</small>
            {switch (Email->(form.result), Email->(form.validating)) {
              | (_, true) =>
                <div className="form-message">
                  "Checking..."->React.string
                </div>
              | (Some(Error(message)), false) =>
                <div className={Cn.make(["form-message", "failure"])}>
                  message->React.string
                </div>
              | (Some(Ok(Valid)), false) =>
                <div className={Cn.make(["form-message", "success"])}>
                  {j|✓|j}->React.string
                </div>
              | (Some(Ok(NoValue)) | None, false) => React.null
              }}
          </div>
          <div className="form-group">
            <label htmlFor="signup--password">"Password"->React.string</label>
            <input
              id="signup--password"
              className="form-control"
              type_="password"
              value={form.state.password}
              placeholder="Password"
              disabled={form.submitting}
              onBlur={_ => form.blur(Password)}
              onChange={event =>
                form.change(
                  Password,
                  SignupForm.PasswordField.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            {switch (Password->(form.result)) {
              | Some(Error(message)) =>
                <div className={Cn.make(["form-message", "failure"])}>
                  message->React.string
                </div>
              | Some(Ok(Valid)) =>
                <div className={Cn.make(["form-message", "success"])}>
                  {j|✓|j}->React.string
                </div>
              | Some(Ok(NoValue))
              | None => React.null
              }}
          </div>
          <div className="form-group">
            <label
              htmlFor="signup--passwordConfirmation">
              "Confirmation"->React.string
            </label>
            <input
              id="signup--passwordConfirmation"
              className="form-control"
              type_="password"
              value={form.state.passwordConfirmation}
              placeholder="Password"
              disabled={form.submitting}
              onBlur={_ => form.blur(PasswordConfirmation)}
              onChange={event =>
                form.change(
                  PasswordConfirmation,
                  SignupForm.PasswordConfirmationField.update(
                    form.state,
                    event->ReactEvent.Form.target##value,
                  ),
                )
              }
            />
            {switch (PasswordConfirmation->(form.result)) {
              | Some(Error(message)) =>
                <div className={Cn.make(["form-message", "failure"])}>
                  message->React.string
                </div>
              | Some(Ok(Valid)) =>
                <div className={Cn.make(["form-message", "success"])}>
                  {j|✓|j}->React.string
                </div>
              | Some(Ok(NoValue))
              | None => React.null
              }}
          </div>
          <div className="form-group">
            <button type_="submit" className="btn btn-primary" disabled={form.submitting}>
              (form.submitting ? "Submitting..." : "Submit")->React.string
            </button>
            {switch (form.status) {
            | Submitted =>
              <div className={Cn.make(["form-status", "success"])}>
                {j|✓ Signed Up|j}->React.string
              </div>
            | _ => React.null
            }}
          </div>
        </form>
      }
  </SignupFormContainer>
}

