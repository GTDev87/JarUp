[@bs.module "native-base"]
external h3 : ReasonReact.reactClass = "H3";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=h3,
    ~props=Js.Obj.empty(),
    children
  );