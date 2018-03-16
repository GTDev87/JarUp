[@bs.module "native-base"]
external row : ReasonReact.reactClass = "Row";

let make = (~size=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=row,
    ~props={
      "size": Js.Nullable.fromOption(size),
      "style": Js.Nullable.fromOption(style),
    },
    children
  );