let component = React.statelessComponent("SignUpPage");

module Styles = {
  open Css;

  let content = style([
    width(`vw(100.0)),
    maxWidth(`px(500)),
  ])

  let imageDivLeft = style([
    transform(rotate(deg(Js.Math.random_int(-10, 10))))
  ])

  let imageDivRight = style([
    transform(rotate(deg(Js.Math.random_int(-10, 10))))
  ])

  let image = style([
    maxWidth(`px(200)),
    width(`vw(10.0)),
  ])
}

let make = _children => {
  ...component,
  render: _self =>
    <div className="App-header">
      <div className="container">
        <div className="row">
          <div className="col align-self-start">
            <div className=(Styles.imageDivLeft ++ " shadow p-3 mb-5 bg-white rounded")>
              <img className=Styles.image src="https://i.imgur.com/9U1w5wx.jpg?1" />
            </div>
          </div>
          <div className="col align-self-center">
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
          <div className="col align-self-end">
            <div className=(Styles.imageDivRight ++ " shadow p-3 mb-5 bg-white rounded")>
              <img className=Styles.image src="https://i.imgur.com/uZUUsRZ.jpg?1" />
            </div>
          </div>
        </div>
      </div>
    </div>
}


