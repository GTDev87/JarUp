open BsReactNative;

let component = ReasonReact.statelessComponent("LandingModal");

let image : Packager.required = Packager.require("../../../assets/icons/landing_big.png");
let landingIcon : Image.imageSource = Image.Required(image);

let make = (~controlAction, /*~openPullCardModal, */_children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity
      style=Style.(style([
        flex(1.),
        backgroundColor("white"),
      ]))
      onPress=(() => controlAction(Control.(ChangeScene(Home))))
    >
      <Image
        style=Style.(
          style([
            flex(1.),
            maxWidth(Pct(100.)),
            maxHeight(Pct(100.)),
          ]))
        resizeMode=`contain
        source=landingIcon
      />
    </TouchableOpacity>
};
