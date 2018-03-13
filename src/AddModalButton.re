open BsReactNative;

let plusImage : Packager.required = Packager.require("../../../assets/icons/plus.png");
let plusIcon : Image.imageSource = Image.Required(plusImage);

let iconDimension = 30.;

let component = ReasonReact.statelessComponent("AddModalButton");

let make = (~controlAction, ~scene, _children) => {
  ...component,
  render: (_self) =>
    <View>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Add))
        onBackdropPress={(_) => controlAction(Control.ToHome); }
        backdropColor="white"
        backdropOpacity=0.5
        animationIn="zoomInDown"
        animationOut="zoomOutUp"
        animationInTiming=1000.
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
      >
        <Text
          style=Style.(style([color("black")]))
          value="What awesome things happend to you today?"
        />
        <TextInput
          style=Style.(
            style([
              height(Pt(40.)),
              borderColor("black"),
              borderWidth(1.),
              color("white"),
            ]))
          onSubmitEditing=((_) => controlAction(Control.ToHome))
        />
      </Modal2>
      <SceneChangeButton
        onPress=((_event) => {
          controlAction(Control.ToAdd);
        })
        icon=plusIcon
      />
    </View>
};
