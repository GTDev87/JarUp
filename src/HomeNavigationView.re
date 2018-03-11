open BsReactNative;

let component = ReasonReact.statelessComponent("HomeNavigationView");

let navigationHeight = 50.;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          height(Pt(navigationHeight)),
        ])
      )
    />
};
