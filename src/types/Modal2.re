[@bs.module "react-native-modal"]
external modal : ReasonReact.reactClass = "default";

let make = (
  ~isVisible,
  ~onBackdropPress,
  ~animationOutTiming=?,
  ~backdropTransitionInTiming=?,
  ~backdropTransitionOutTiming=?,
  ~backdropColor=?,
  ~backdropOpacity=?,
  ~animationIn=?,
  ~animationOut=?,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "isVisible": isVisible,
      "backdropColor": Js.Nullable.from_opt(backdropColor),
      "backdropOpacity": Js.Nullable.from_opt(backdropOpacity),
      "onBackdropPress": onBackdropPress,
      "animationIn": Js.Nullable.from_opt(animationIn),
      "animationOut": Js.Nullable.from_opt(animationOut),
      "animationOutTiming": Js.Nullable.from_opt(animationOutTiming),
      "backdropTransitionInTiming": Js.Nullable.from_opt(backdropTransitionInTiming),
      "backdropTransitionOutTiming": Js.Nullable.from_opt(backdropTransitionOutTiming),
    },
    children
  );
