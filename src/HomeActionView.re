open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let marginBottomVal = 30.;

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          padding(Pt(marginBottomVal)),
          flexDirection(Row),
          justifyContent(SpaceBetween),
        ])
    )>
      <AddModalButton scene=scene controlAction=controlAction />
      <ShakeModalButton scene=scene controlAction=controlAction notes=notes />
    </View>
};
