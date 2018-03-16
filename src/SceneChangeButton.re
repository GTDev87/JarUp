open BsReactNative;

let component = ReasonReact.statelessComponent("SceneChangeButton");

let make = (~onPress, ~icon, _children) => {
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
      <Image
        style=Style.(
          style([
            maxWidth(Pct(100.)),
            maxHeight(Pct(100.)),
          ]))
        resizeMode=`contain
        source=icon
      />
    </TouchableOpacity>
};
