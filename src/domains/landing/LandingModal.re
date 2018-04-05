open BsReactNative;

let component = ReasonReact.statelessComponent("LandingModal");

let image : Packager.required = Packager.require("../../../../../assets/icons/landing_big.png");
let landingIcon : Image.imageSource = Image.Required(image);

let make = (~controlAction, /*~openPullCardModal, */_children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity
      style=Style.(style([
        flex(1.),
        backgroundColor(String("white")),
      ]))
      onPress=(() => controlAction(Control.Model.(ChangeScene(Home))))
    >
      <Image
        style=Style.(
          style([
            flex(1.),
            unsafeStyleElement("width", Js.Json.null),
            unsafeStyleElement("height", Js.Json.null),
          ]))
        resizeMode=`cover
        source=landingIcon
      />
    </TouchableOpacity>
};
