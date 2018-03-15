[@bs.module "react-native-animatable"]
external modal : ReasonReact.reactClass = "View";

let make = (
  ~style=?,
  ~animation,
  ~duration,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "style": Js.Nullable.fromOption(style),
      "animation": animation,
      "duration": duration,
    },
    children
  );