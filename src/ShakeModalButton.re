open BsReactNative;


let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let defaultNote : Control.note = Control.{
  id: -1,
  text: "You have not added an awesome moment yet.",
  color: Control.Red,
  time: 0,
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
    | SelectNote =>
      ReasonReact.UpdateWithSideEffects(
        {selectedNote: selectRandomNote(notes)},
        (_self => controlAction(Control.(ChangeScene(Shake))))
      ) /* investigate this */
    },
  render: (self) =>
    <View>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Shake))
        onBackdropPress={(_) => controlAction(Control.(ChangeScene(Home))); }
        animationOut="zoomOutDown"
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
        style=Style.(style([
          /*borderWidth(4.),*/
          margin(Pt(0.)),
          marginTop(Pt(Dimension.topBarHeight)),
        ]))
      >
        <TouchableOpacity
          style=Style.(style([
            flex(1.),
          ]))
          onPress=(() => controlAction(Control.(ChangeScene(Home))))
        >
          <Card2
            style=Style.(style([
              backgroundColor(self.state.selectedNote.color |> Colors.colorToActualColor),
              flex(1.),
            ]))
          >
          
            <View
              style=Style.(style([
                marginHorizontal(Pt(50.)), /* raw number wrong!!!*/
                marginTop(Pt(200.)), /* raw number wrong!!!*/
              ]))
            >
              <H3>(self.state.selectedNote.text)</H3>
            </View>
          </Card2>
        </TouchableOpacity>
      </Modal2>
      <SceneChangeButton
        onPress=((_event) => self.send(SelectNote))
        icon=squiggleIcon
      />
    </View>
};
