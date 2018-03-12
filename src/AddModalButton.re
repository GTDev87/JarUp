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
        /*animationType=`slide*/
        /*transparent=false*/
        isVisible=(scene == Control.Add)
        onBackdropPress={(_) => controlAction(Control.ToHome); }
          /*
          onRequestClose={() => {
          alert('Modal has been closed.');
        }}*/
      >
        <Text value="What awesome things happend to you today?" />
        <TextInput
          style=Style.(
            style([
              height(Pt(40.)),
              borderColor("gray"),
              borderWidth(1.),
            ]))
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
