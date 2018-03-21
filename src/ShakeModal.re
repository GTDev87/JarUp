open BsReactNative;

let component = ReasonReact.statelessComponent("ShakeModal");

let iconFontSize = 80;

let textStyle = (primaryColor) => Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(40.)),
  color(String(Colors.colorToContrastColor(primaryColor))),
]));

let choiceToIcon = (note : Control.note, iconType) =>
  switch (iconType) {
  | PullCardState.Heart => <Entypo name="heart" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  | PullCardState.Smile => <SimpleLineIcons name="emotsmile" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  | PullCardState.Happy => <FontAwesome name="child" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  };

let make = (~pullCardState : PullCardState.state, ~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <TouchableWithoutFeedback
      style=Style.(style([flex(1.),]))
      onPress=(() => controlAction(Control.(ChangeScene(Home))))
      onLongPress=(() =>
        Alert.(alert(
          ~title="Delete",
          ~message="Would you like to delete this note?",
          ~options=({cancelable: Some(true), onDismiss: None}),
          ~buttons=[
            {
              text: Some("Ok"),
              onPress: Some(() => controlAction(Control.RemoveNoteAndToHome(pullCardState.selectedNote.id))),
              style: Some(`default),
            },
            {
              text: Some("Cancel"),
              onPress: None,
              style: None,
            }
          ],
          ()
        )))
    >
      <View style=Style.(style([flex(1.),]))>
        <CardBorderLayout
          backColor=(pullCardState.selectedNote.color |> Colors.colorToActualColor)
          footerText="Goodvibes Everyday"
        >
          <Grid>
            <Row size=4 />
            <Row size=2>
              <View>
                { choiceToIcon(pullCardState.selectedNote, pullCardState.icon) }
              </View>
            </Row>
            <Row size=4>
              <Text
                style=textStyle(pullCardState.selectedNote.color)
                value=pullCardState.selectedNote.text
              />
            </Row>
          </Grid>
        </CardBorderLayout>
      </View>
    </TouchableWithoutFeedback>
};
