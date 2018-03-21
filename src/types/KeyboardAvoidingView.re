[@bs.module "react-native"]
external view : ReasonReact.reactClass = "KeyboardAvoidingView";

let make = (
  ~style=?,
  ~behavior=?,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props={
      "style": Js.Nullable.fromOption(style),
      "behavior": Js.Nullable.fromOption(behavior),
    },
    children
  );