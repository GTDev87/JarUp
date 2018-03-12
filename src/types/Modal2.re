[@bs.module "react-native-modal"]
external modal : ReasonReact.reactClass = "default";

let make = (~isVisible, ~onBackdropPress, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=modal,
    ~props={
      "isVisible": isVisible,
      "onBackdropPress": onBackdropPress
    },
    children
  );
