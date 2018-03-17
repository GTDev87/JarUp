open BsReactNative;

let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let component = ReasonReact.statelessComponent("ShakeModalButton");

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component, 
  render: (_self) =>
    <View
      style=Style.(style([
        flex(1.),
        justifyContent(Center),
        alignItems(Center),
      ]))
    >
      <PullCard notes=notes scene=scene controlAction=controlAction>
        <Foundation name="shuffle" size=30 color="gray" />
      </PullCard>
    </View>
};
