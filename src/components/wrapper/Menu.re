let component = ReasonReact.statelessComponent("Menu");

let make = _children => {
    ...component,
    render: _self =>
    <div className="pure-menu pure-menu-horizontal">
        <ul className="pure-menu-list">
            <li className="pure-menu-item pure-menu-selected"><a href="#" className="pure-menu-link">"Home"->ReasonReact.string</a></li>
            <li className="pure-menu-item pure-menu-has-children pure-menu-allow-hover">
                <a href="#" id="menuLink1" className="pure-menu-link">"Contact"->ReasonReact.string</a>
                <ul className="pure-menu-children">
                    <li className="pure-menu-item"><a href="#" className="pure-menu-link">"Email"->ReasonReact.string</a></li>
                </ul>
            </li>
        </ul>
    </div>
}