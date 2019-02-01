let component = ReasonReact.statelessComponent("App");

let user: User.user = {name: "Corentin", age: Some(14)};

let make = _children => {...component, render: _self => <User user />};