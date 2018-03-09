open BsReactNative;

let component = ReasonReact.statelessComponent("NavigationView");

let navigationHeight = 50.;

let make = (_children) /*: ReasonReact.componentSpec(`a, `b, `c, `d, `e)*/ => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          height(Pt(navigationHeight)),
          backgroundColor("red"),
        ])
      )
    />
};
