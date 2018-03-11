open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let plusImage : Packager.required = Packager.require("../../../assets/icons/plus.png");
let plusIcon : Image.imageSource = Image.Required(plusImage);

let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let marginBottomVal = 30.;

let make = (~controlAction, _children) => {
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
      <SceneChangeButton
        onPress=((_event) => {
          Js.log("Add to Jar");
          controlAction(Control.ToAdd);
        })
        icon=plusIcon
      />
      <SceneChangeButton
        onPress=((_event) => {
          Js.log("Shake");
          controlAction(Control.ToShake);
        })
        icon=squiggleIcon
      />
    </View>
};
