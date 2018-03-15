open BsReactNative;


let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let defaultNote = {
  Control.id: -1,
  Control.text: "You have not added an awesome moment yet.",
  Control.color: Control.Red,
  Control.time: 0,
};

let selectRandomNote = (notes) => Utils.selectRandomFromList(notes, defaultNote);

type state = {selectedNote: Control.note};
type action =
  | SelectNote;

let component = ReasonReact.reducerComponent("ShakeModalButton");

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component, 
  initialState: () => ({selectedNote: defaultNote }),
  reducer: fun (action, _state) =>
    switch action {
    | SelectNote => ReasonReact.UpdateWithSideEffects(
      {selectedNote: selectRandomNote(notes)},
      (_self => controlAction(Control.(ChangeScene(Shake)))) /* investigate this */
    )
    },
  render: (self) => {
    "notes:" |> Js.log;
    notes |> Js.log;
    "state.selectedNote:" |> Js.log;
    self.state.selectedNote |> Js.log;
    <View>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Shake))
        onBackdropPress={(_) => controlAction(Control.(ChangeScene(Home))); }
        backdropColor=Colors.yellowPrimaryString
        backdropOpacity=0.4
        animationOut="zoomOutDown"
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
      >
        <Text
          style=Style.(style([color("black")]))
          value=self.state.selectedNote.text
        />
      </Modal2>
      <SceneChangeButton
        onPress=((_event) => self.send(SelectNote))
        icon=squiggleIcon
      />
    </View>;
  }
};
