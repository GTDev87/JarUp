open BsReactNative;

let iconFontSize = 80;

let textStyle = Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  fontSize(Float(40.)),
]));

let choiceToIcon = (iconType) =>
  switch (iconType) {
  | PullCardState.Heart => <Entypo name="heart" size=iconFontSize color="black" />
  | PullCardState.Smile => <SimpleLineIcons name="emotsmile" size=iconFontSize color="black" />
  | PullCardState.Happy => <FontAwesome name="child" size=iconFontSize color="black" />
  };

let component = ReasonReact.statelessComponent("PullCardModal");

let isShakeScene = (scene) => scene == Control.Shake;

let make = (~controlAction, ~scene, ~pullCardState : PullCardState.state, _children) => {
  ...component, 
  render: (_self) =>
    <Modal2
      isVisible=(scene |> isShakeScene |> Js.Boolean.to_js_boolean)
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
          backColor=(pullCardState.selectedNote.color |> Colors.colorToActualColor)
          headerText="SHUFFLECARD"
          footerText="Keep those good vibes rolling."
        >
          <Grid>
            <Row size=4 />
            <Row size=2>
              <View>
                { choiceToIcon(pullCardState.icon) }
              </View>
            </Row>
            <Row size=4>
              <Text style=textStyle value=pullCardState.selectedNote.text />
            </Row>
          </Grid>
        </CardBorderLayout>
      </TouchableOpacity>
    </Modal2>
};