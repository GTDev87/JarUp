open BsReactNative;

let plusImage : Packager.required = Packager.require("../../../assets/icons/plus.png");
let plusIcon : Image.imageSource = Image.Required(plusImage);

let iconDimension = 30.;

type state = { noteText: string };

type action =
  | UpdateNote(string);

let component = ReasonReact.reducerComponent("AddModalButton");

let make = (~controlAction, ~scene, _children) => {
  ...component,
  initialState: () : state => {noteText: ""},
  reducer: fun (action, _state : state) =>
    switch action {
    | UpdateNote(noteText) => ReasonReact.Update({noteText: noteText})
    },
  render: (self) =>
    <View
      style=Style.(style([
        flex(1.)
      ]))
    >
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Add))
        onBackdropPress={(_) => controlAction(Control.(ChangeScene(Home))); }
        animationOut="zoomOutDown"
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
        style=Style.(style([
          flex(1.),
          margin(Pt(0.)),
          marginTop(Pt(Dimension.topBarHeight)),
        ]))
      >
        <Card2
          style=Style.(style([
            flex(1.),
          ]))
        >
          <Text
            style=Style.(style([color("black")]))
            value="What awesome things happend to you today?"
          />
          <TextInput
            style=Style.(
              style([
                height(Pt(40.)),
                color("black"),
              ]))
            onChangeText=((noteText) => self.send(UpdateNote(noteText)))
            onSubmitEditing=((_event) => {
              Control.AddNoteAndToHome(self.state.noteText) |> controlAction;
            })
          />
        </Card2>
      </Modal2>
      <SceneChangeButton
        onPress=((_event) => {
          controlAction(Control.(ChangeScene(Add)));
        })
        icon=plusIcon
      />
    </View>
};
