[@bs.module "native-base"]
external col : ReasonReact.reactClass = "Col";

let make = (~size=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=col,
    ~props={
      "size": Js.Nullable.fromOption(size),
      "style": Js.Nullable.fromOption(style),
    },
    children
  );