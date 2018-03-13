open BsReactNative;

let illumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_b.png");
let illumeIcon : Image.imageSource = Image.Required(illumeImage);

let illumeUpArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_up.png");
let illumeUpArrowIcon : Image.imageSource = Image.Required(illumeUpArrowImage);

let illumeDownArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_down.png");
let illumeDownArrowIcon : Image.imageSource = Image.Required(illumeDownArrowImage);

let component = ReasonReact.statelessComponent("HomeNavigationView");

let navigationHeight = 40.;
let largeDimension = 30000.;
let illumeFontHeight = 20.;
let illumeFontWidth = 80.;
let triangleSize = 20.;

let flipUp = false;

let flipIcon = (isUp) => {
  switch (isUp) {
  | true => illumeUpArrowIcon
  | false => illumeDownArrowIcon
  }
};

let make = (_children) => {
  ...component,
  render: (_self) => {

    let arrow =
      <Image
        style=Style.(
          style([
            flex(1.),
            height(Pt(triangleSize)),
            alignSelf(Center),
            maxWidth(Pt(triangleSize)),
            overflow(Hidden),
            marginTop(Pt(10.)),
          ]))
        resizeMode=`contain
        source=flipIcon(flipUp)
      />;

    <View
      style=Style.(
        style([
          flexDirection(Row),
          justifyContent(Center),
          height(Pt(navigationHeight)),
          borderBottomWidth(1.)
        ])
      )
    >
      <Image
        style=Style.(
          style([
            flex(1.),
            height(Pt(illumeFontHeight)),
            alignSelf(Center),
            maxWidth(Pt(illumeFontWidth)),
            overflow(Hidden),
          ]))
        resizeMode=`contain
        source=illumeIcon
      />
      { arrow }
    </View>
  }
};
