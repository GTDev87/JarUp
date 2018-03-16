[@bs.module "native-base"]
external grid : ReasonReact.reactClass = "Grid";

let make = (~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=grid,
    ~props={
      "style": Js.Nullable.fromOption(style),
    },
    children
  );