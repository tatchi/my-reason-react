type user = {
  name: string,
  age: option(int),
};

let component = ReasonReact.statelessComponent("User");

/* let getUserAge = user =>
   switch (user.age) {
   | Some(a) => string_of_int(a)
   | None => "unknow"
   }; */

let make = (~user, _children) => {
  ...component,
  render: _self =>
    <>
      <div> {ReasonReact.string("name: " ++ user.name)} </div>
      <div>
        {switch (user.age) {
         | Some(a) => ReasonReact.string(string_of_int(a))
         | None => ReasonReact.string("Unknow")
         }}
      </div>
      /* {ReasonReact.string(
           "age: "
           ++ (
             switch (user.age) {
             | Some(a) => string_of_int(a)
             | None => "Unknow"
             }
           ),
         )} */
    </>,
};