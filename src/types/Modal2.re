[@bs.module "react-native-modal"]
external modal : ReasonReact.reactClass = "default";

let make = (
  ~isVisible,
  ~onBackdropPress,
  ~animationInTiming,
  ~animationOutTiming,
  ~backdropTransitionInTiming,
  ~backdropTransitionOutTiming,
  ~backdropColor,
  ~backdropOpacity,
  ~animationIn,
  ~animationOut,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "isVisible": isVisible,
      "backdropColor": backdropColor,
      "backdropOpacity": backdropOpacity,
      "onBackdropPress": onBackdropPress,
      "animationIn": animationIn,
      "animationOut": animationOut,
      "animationInTiming": animationInTiming,
      "animationOutTiming": animationOutTiming,
      "backdropTransitionInTiming": backdropTransitionInTiming,
      "backdropTransitionOutTiming": backdropTransitionOutTiming,
    },
    children
  );
