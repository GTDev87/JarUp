[@bs.module "react-native-modal"]
external modal : ReasonReact.reactClass = "default";

let make = (
  ~isVisible,
  ~animationOutTiming=?,
  ~backdropTransitionInTiming=?,
  ~backdropTransitionOutTiming=?,
  ~backdropColor=?,
  ~backdropOpacity=?,
  ~animationIn=?,
  ~animationOut=?,
  ~style=?,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "style": Js.Nullable.fromOption(style),
      "isVisible": Js.Boolean.to_js_boolean(isVisible),
      "backdropColor": Js.Nullable.fromOption(backdropColor),
      "backdropOpacity": Js.Nullable.fromOption(backdropOpacity),
      "animationIn": Js.Nullable.fromOption(animationIn),
      "animationOut": Js.Nullable.fromOption(animationOut),
      "animationOutTiming": Js.Nullable.fromOption(animationOutTiming),
      "backdropTransitionInTiming": Js.Nullable.fromOption(backdropTransitionInTiming),
      "backdropTransitionOutTiming": Js.Nullable.fromOption(backdropTransitionOutTiming),
    },
    children
  );
