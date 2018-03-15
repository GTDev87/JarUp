open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          flex(1.),
          backgroundColor("transparent"),
        ])
      )
    >
      <HomeNavigationView />
      <HomeDisplayView  />
      <HomeActionView controlAction=controlAction scene=scene notes=notes />
    </View>
};
