open BsReactNative;

let component = ReasonReact.statelessComponent("ShakeModal");

let iconFontSize = 80;

let bigSize = 30.;
let smallSize = 16.;

let textStyle = (primaryColor, size) => Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(size)),
  color(String(Colors.colorToContrastColor(primaryColor))),
]));

let dateStyle = (primaryColor, size) => Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(size)),
  color(String(Colors.colorToContrastColor(primaryColor))),
  alignSelf(FlexEnd),
  marginBottom(Pct(20.)),
  marginRight(Pct(8.)),
  flexDirection(Row),
]));

let choiceToIcon = (note : Control.Model.note, iconType) =>
  switch (iconType) {
  | Control.Model.Heart => <Entypo name="heart" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  | Control.Model.Smile => <SimpleLineIcons name="emotsmile" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  | Control.Model.Happy => <FontAwesome name="child" size=iconFontSize color=Colors.colorToContrastColor(note.color) />
  };

let make = (
  ~selectedNote : Control.Model.note,
  ~icon : Control.Model.icon,
  ~controlAction,
  _children
) => {
  ...component,
  render: (_self) =>
    <TouchableWithoutFeedback
      style=Style.(style([flex(1.),]))
      onPress=(() => controlAction(Control.Model.(ChangeScene(Home))))
      onLongPress=(() =>
        Alert.(alert(
          ~title="Delete",
          ~message="Would you like to delete this note?",
          ~options=({cancelable: Some(true), onDismiss: None}),
          ~buttons=[
            {
              text: Some("Ok"),
              onPress: Some(() => controlAction(Control.Action.RemoveNoteAndToHome(selectedNote.id))),
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
          backColor=(selectedNote.color |> Colors.colorToActualColor)
          footerText="Goodvibes everyday"
          footerColor="black"
        >
          <Grid>
            <Row size=4 />
            <Row size=2>
              <Col size=2>
                { choiceToIcon(selectedNote, icon) }
              </Col>
              <Col size=1 />
              <Col size=2>
                <View style=Style.(style([
                  flex(1.),
                  flexDirection(Row),
                  alignItems(FlexEnd),
                  justifyContent(FlexEnd),
                ]))>
                  <Text
                    style=dateStyle(selectedNote.color, smallSize)
                    value=Moment.(
                      Some(selectedNote.time |> float_of_int) 
                      |> moment(_)
                      |> Moment.format("MM/DD/YY")
                    )
                  />
                </View>
              </Col>
            </Row>
            <Row size=4>
              <Text
                style=textStyle(selectedNote.color, bigSize)
                value=selectedNote.text
              />
            </Row>
          </Grid>
        </CardBorderLayout>
      </View>
    </TouchableWithoutFeedback>
};
