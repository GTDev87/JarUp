open BsReactNative;

let component = ReasonReact.statelessComponent("ShakeModal");

let iconFontSize = 80;

let textStyle = (primaryColor) => Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(40.)),
  color(Colors.colorToContrastColor(primaryColor)),
]));

let choiceToIcon = (iconType) =>
  switch (iconType) {
  | PullCardState.Heart => <Entypo name="heart" size=iconFontSize color="black" />
  | PullCardState.Smile => <SimpleLineIcons name="emotsmile" size=iconFontSize color="black" />
  | PullCardState.Happy => <FontAwesome name="child" size=iconFontSize color="black" />
  };

let make = (~pullCardState : PullCardState.state, ~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity
      style=Style.(style([
        flex(1.),
      ]))
      onPress=(() => controlAction(Control.(ChangeScene(Home))))
    >
      <CardBorderLayout
        backColor=(pullCardState.selectedNote.color |> Colors.colorToActualColor)
        footerText="Goodvibes Everyday"
      >
        <Grid>
          <Row size=4 />
          <Row size=2>
            <View>
              { choiceToIcon(pullCardState.icon) }
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
    </TouchableOpacity>
};
