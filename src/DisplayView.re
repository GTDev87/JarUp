open BsReactNative;

let image : Packager.required = Packager.require("../../../assets/icons/jar.png");
let jarIcon : Image.imageSource = Image.Required(image);

let component = ReasonReact.statelessComponent("DisplayView");

let largeDimension = 30000.;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Image
      style=Style.(
        style([
          flex(1.),
          width(Pt(largeDimension)),
          alignSelf(Center),
          maxHeight(Pt(largeDimension)),
          overflow(Hidden),
          backgroundColor("rgb(75, 118, 134)"),
        ]))
      resizeMode=`contain
      source=jarIcon
    />
};
