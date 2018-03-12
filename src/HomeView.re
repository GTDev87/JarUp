open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");

let make = (~controlAction, ~scene, _children) => {
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
      <HomeActionView controlAction=controlAction scene=scene />
    </View>
};
