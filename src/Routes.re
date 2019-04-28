[@bs.val] external locationHash: string = "window.location.hash";

type route =
  | Landing
  | SignUp;

type state = {route};

type action =
  | UpdateRoute(route); 

let getInitialRoute = () =>
  switch (locationHash) {
  | "#sign-up" => SignUp
  | _ => Landing
};