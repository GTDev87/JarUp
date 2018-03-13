[@bs.module "react-native-modal"]
external modal : ReasonReact.reactClass = "default";

let make = (
  ~isVisible,
  ~onBackdropPress,
  ~animationOutTiming,
  ~backdropTransitionInTiming,
  ~backdropTransitionOutTiming,
  ~backdropColor,
  ~backdropOpacity,
  ~animationOut,
  children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "isVisible": isVisible,
      "backdropColor": backdropColor,
      "backdropOpacity": backdropOpacity,
      "onBackdropPress": onBackdropPress,
      "animationOut": animationOut,
      "animationOutTiming": animationOutTiming,
      "backdropTransitionInTiming": backdropTransitionInTiming,
      "backdropTransitionOutTiming": backdropTransitionOutTiming,
    },
    children
  );
