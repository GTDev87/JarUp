open BsReactNative;

let image : Packager.required = Packager.require("../../../assets/icons/jar.png");
let jarIcon : Image.imageSource = Image.Required(image);

let component = ReasonReact.statelessComponent("HomeDisplayView");

let largeDimension = 30000.;
let distanceFromWindowEdge = 40;

let windowWidth = Dimensions.get(`window)##width;

let jarWidth = float_of_int(windowWidth - distanceFromWindowEdge * 2);

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Image
      style=Style.(
        style([
          flex(1.),
          width(Pt(jarWidth)),
          alignSelf(Center),
          maxHeight(Pt(largeDimension)),
          overflow(Hidden),
        ]))
      resizeMode=`contain
      source=jarIcon
    />
};
