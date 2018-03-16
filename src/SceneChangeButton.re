open BsReactNative;

let component = ReasonReact.statelessComponent("SceneChangeButton");

let make = (~onPress, children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity
      onPress=onPress
      style=Style.(
        style([
          flex(1.),
          margin(Pt(10.))
        ]))
    >
      ...children
    </TouchableOpacity>
};
