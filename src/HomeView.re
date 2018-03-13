open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");
let borderWidthSize = 5.;

let make = (~controlAction, ~scene, _children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          flex(1.),
          borderWidth(borderWidthSize),
          backgroundColor("transparent"),
        ])
      )
    >
      <HomeNavigationView />
      <HomeDisplayView  />
      <HomeActionView controlAction=controlAction scene=scene />
    </View>
};
