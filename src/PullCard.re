open BsReactNative;

let defaultNote : Control.note = Control.{
  id: -1,
  text: "You have not added an awesome moment yet.",
  color: Control.Red,
  time: 0,
};

let iconFontSize = 80;
let marginLeftCardContent = 5.;

type icon =
  | Heart
  | Smile
  | Happy;

let textStyle = Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(40.)),
]));

let choiceToIcon = (iconType) =>
  switch (iconType) {
  | Heart => <Entypo name="heart" size=iconFontSize color="black" />
  | Smile => <SimpleLineIcons name="emotsmile" size=iconFontSize color="black" />
  | Happy => <FontAwesome name="child" size=iconFontSize color="black" />
  };

let iconChoices = [Heart, Smile, Happy];

let chooseRandomIcon = () => Utils.selectRandomFromList(iconChoices, Heart);

let selectRandomNote = (notes) => Utils.selectRandomFromList(notes, defaultNote);

type state = {selectedNote: Control.note, icon};
type action =
  | SelectNote
  | NoAction;

let component = ReasonReact.reducerComponent("PullCard");

let make = (~controlAction, ~scene, ~notes, children) => {
  ...component, 
  initialState: () => ({selectedNote: defaultNote, icon: Heart }),
  reducer: fun (action, _state) =>
    switch action {
    | SelectNote =>
      ReasonReact.UpdateWithSideEffects(
        {selectedNote: selectRandomNote(notes), icon: chooseRandomIcon()},
        (_self => controlAction(Control.(ChangeScene(Shake))))
      ) /* investigate this */
    | NoAction => ReasonReact.NoUpdate
    },
  render: (self) =>
    <View style=Style.(style([flex(1.)]))>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(scene == Control.Shake))
        onBackdropPress={(_) => controlAction(Control.(ChangeScene(Home))); }
        animationOut="zoomOutDown"
        animationOutTiming=1000.
        backdropTransitionInTiming=1000.
        backdropTransitionOutTiming=1000.
        style=Style.(style([
          margin(Pt(0.)),
          marginTop(Pt(Dimension.cardTop)),
        ]))
      >
        <TouchableOpacity
          style=Style.(style([
            flex(1.),
          ]))
          onPress=(() => controlAction(Control.(ChangeScene(Home))))
        >
          <CardBorderLayout
            backColor=(self.state.selectedNote.color |> Colors.colorToActualColor)
            headerText="SHUFFLECARD"
            footerText="Keep those good vibes rolling."
          >
            <Grid>
              <Row size=4 />
              <Row size=2>
                <View>
                  { choiceToIcon(self.state.icon) }
                </View>
              </Row>
              <Row size=4>
                <Text style=textStyle value=self.state.selectedNote.text />
              </Row>
            </Grid>
          </CardBorderLayout>
        </TouchableOpacity>
      </Modal2>
      <TouchableOpacity onPress=((_event) => self.send((scene == Control.Shake) ? NoAction : SelectNote))>
        ...children
      </TouchableOpacity>
    </View>
};
