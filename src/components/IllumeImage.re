open BsReactNative;

let orangeIllumeImage : Packager.required = Packager.require("../../../../assets/icons/illume_type_y_o.png");
let orangeIllumeIcon : Image.imageSource = Image.Required(orangeIllumeImage);

let component = ReasonReact.statelessComponent("IllumeImage");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Image
      style=Style.(
        style([
          maxHeight(Pct(100.)),
          maxWidth(Pct(100.)),
          marginTop(Pct(5.)),
          alignItems(FlexStart),
        ]))
      resizeMode=`contain
      source=orangeIllumeIcon
    />
};
