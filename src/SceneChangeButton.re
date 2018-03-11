open BsReactNative;

let component = ReasonReact.statelessComponent("SceneChangeButton");

let iconDimension = 30.;

let make = (~onPress, ~icon, _children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity onPress=onPress>
      <Image
        style=Style.(
          style([
            height(Pt(iconDimension)),
            width(Pt(iconDimension)),
            alignSelf(Center),
            maxHeight(Pt(iconDimension)),
          ]))
        resizeMode=`cover
        source=icon
      />
    </TouchableOpacity>
};
