[@bs.module "native-base"]
external card : ReasonReact.reactClass = "Card";

let make = (
  ~style=?,
  /*~animation,
  ~duration,*/
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=card,
    /*~props=props,*/
    ~props={
      "style": Js.Nullable.fromOption(style),
/*      "animation": animation,
      "duration": duration,
*/  },
    /*~props=Js.Dict.empty,*/
    children
  );