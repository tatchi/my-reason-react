[%%debugger.chrome];
let component = ReasonReact.statelessComponent("App");

let user: User.user = {name: "Corentin", age: Some(14)};

let data = {| {
  "name": "Corentin",
  "age":   14
} |};


let res =
  data
  |> Json.parseOrRaise
  |> (
    json =>
      Json.Decode.{
        User.name: json |> field("name", string),
        User.age: json |> field("age", optional(int)),
      }
  );


Js.log(switch res {
| {age: None} => "empty"
| {age: Some(a)} => string_of_int(a)
});

let make = _children => {...component, render: _self => <User user />};