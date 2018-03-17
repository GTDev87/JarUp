open BsReactNative;

let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let component = ReasonReact.statelessComponent("ShakeModalButton");

let make = (~openPullCardModal, _children) => {
  ...component, 
  render: (_self) =>
    <View
      style=Style.(style([
        flex(1.),
        justifyContent(Center),
        alignItems(Center),
      ]))
    >
      <TouchableOpacity onPress=openPullCardModal>
        <Foundation name="shuffle" size=30 color="gray" />
      </TouchableOpacity>
    </View>
};
