[@bs.module "native-base"]
external h3 : ReasonReact.reactClass = "H3";

let make = (
  /*props,*/
  /*~style=?,*/
  /*~animation,
  ~duration,*/
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=h3,
    ~props=Js.Obj.empty(),
    /*~props={
      "style": Js.Nullable.fromOption(style),
      "animation": animation,
      "duration": duration,
  },*/
    /*~props=Js.Dict.empty,*/
    children
  );