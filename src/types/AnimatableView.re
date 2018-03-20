[@bs.module "react-native-animatable"]
external view : ReasonReact.reactClass = "View";

let make = (
  ~style=?,
  ~animation,
  ~duration,
  ~delay=?,
  ~easing=?,
  ~iterationCount=?,
  ~useNativeDriver=?,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props={
      "style": Js.Nullable.fromOption(style),
      "animation": animation,
      "duration": duration,
      "delay": Js.Nullable.fromOption(delay),
      "easing": Js.Nullable.fromOption(easing),
      "iterationCount": Js.Nullable.fromOption(iterationCount),
      "useNativeDriver": Js.Nullable.fromOption(useNativeDriver),
    },
    children
  );
