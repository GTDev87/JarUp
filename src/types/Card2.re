[@bs.module "native-base"]
external card : ReasonReact.reactClass = "Card";

let make = (~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=card,
    ~props={
      "style": Js.Nullable.fromOption(style),
    },
    children
  );