open BsReactNative;

let component = ReasonReact.statelessComponent("ControlView");

let navigationHeight = 50.;

let make = (_children) /*: ReasonReact.componentSpec(`a, `b, `c, `d, `e)*/ => {
  ...component,
  render: (_self) =>
    <View style=Style.(
      style([
        flex(1.),
        backgroundColor("transparent"),
      ]))>
      <NavigationView />
      <DisplayView />
      <ActionView />
    </View>
};
