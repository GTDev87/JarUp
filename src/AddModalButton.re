open BsReactNative;

type state = { noteText: string };

type action =
  | UpdateNote(string);

let component = ReasonReact.reducerComponent("AddModalButton");

let questionStyle = Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(40.)),
]));

let inputTextStyle = Style.(style([
  fontFamily("Arial"),
  fontSize(Float(28.)),
  flex(1.),
]));

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
        flex(1.),
        justifyContent(Center),
        alignItems(Center),
      ]))
    >
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Add))
        animationOut="zoomOutDown"
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
        style=Style.(style([
          flex(1.),
          margin(Pt(0.)),
          marginTop(Pt(Dimension.cardTop)),
        ]))
      >
        <CardBorderLayout
          backColor="white"
          headerText="ILLUME A MEMORY"
          footerText="Keep those good vibes rolling."
        >
          <Grid>
            <Row size=2 />
            <Row size=3>
              <Text
                style=questionStyle
                value="What awesome thing happend to you today?"
              />
            </Row>
            <Row size=2>
              <TextInput
                style=inputTextStyle
                onChangeText=((noteText) => self.send(UpdateNote(noteText)))
                onSubmitEditing=((_event) => {
                  Control.AddNoteAndToHome(self.state.noteText) |> controlAction;
                })
              />
            </Row>
            <Row size=3 />
          </Grid>
        </CardBorderLayout>
      </Modal2>
      <SceneChangeButton onPress=((_event) => controlAction(Control.(ChangeScene(Add))))>
        <Foundation name="pencil" size=30 color="gray" />
      </SceneChangeButton>
    </View>
};
