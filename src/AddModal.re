open BsReactNative;

let component = ReasonReact.statelessComponent("AddModal");

let questionStyle = Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  flex(1.),
  fontSize(Float(40.)),
]));

let inputTextStyle = Style.(style([
  fontFamily("Arial"),
  fontSize(Float(28.)),
  flex(1.),
]));

let make = (~addNoteAndGoHome, ~updateNoteFn, ~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <CardBorderLayout
      backColor="white"
      headerText="ILLUME A MEMORY"
      footerText="Keep those good vibes rolling."
    >
      <Grid>
        <Row size=5>
          <TouchableOpacity
            style=Style.(style([flex(1.)]))
            onPress=((_event) => controlAction(Control.(ChangeScene(Home))))
          >
            <Grid>
              <Row size=2 />
              <Row size=3 >
                <Text
                  style=questionStyle
                  value="What awesome thing happend to you today?"
                  numberOfLines=3
                  minimumFontScale=0.5
                  allowFontScaling=true
                  adjustsFontSizeToFit=true
                />
              </Row>
            </Grid>
          </TouchableOpacity>
        </Row>
        <Row size=2 >
          <TextInput
            style=inputTextStyle
            onChangeText=updateNoteFn
            onSubmitEditing=addNoteAndGoHome
            numberOfLines=3
          />
        </Row>
        <Row size=3>
          <TouchableOpacity
            style=Style.(style([flex(1.)]))
            onPress=((_event) => controlAction(Control.(ChangeScene(Home))))
          />
        </Row>
      </Grid>
    </CardBorderLayout>
};