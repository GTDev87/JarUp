[@bs.module "react-native-animatable"]
external view : ReasonReact.reactClass = "View";

let make = (
  ~style=?,
  ~animation,
  ~duration,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props={
      "style": Js.Nullable.fromOption(style),
      "animation": animation,
      "duration": duration,
    },
    children
  );