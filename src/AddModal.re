open BsReactNative;

let component = ReasonReact.statelessComponent("AddModal");

let questionStyle = Style.(style([
  fontFamily("Arial Rounded MT Bold"),
  flex(1.),
  fontSize(Float(30.)),
]));

let inputTextStyle = Style.(style([
  fontFamily("Arial"),
  fontSize(Float(22.)),
  flex(1.),
]));

let make = (~addNoteAndGoHome, ~updateNoteFn, ~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <KeyboardAvoidingView
      style=Style.(style([flex(1.)]))
      behavior=(Platform.equals(IOS(Phone)) ? "padding" : "")
    >
      <CardBorderLayout
        backColor="white"
        footerText="Goodvibes everyday"
        footerColor="black"
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
                    value="What awesome thing happened to you today?"
                    numberOfLines=3
                    allowFontScaling=true
                    adjustsFontSizeToFit=true
                  />
                </Row>
              </Grid>
            </TouchableOpacity>
          </Row>
          <Row size=3 >
            <TextInput
              style=inputTextStyle
              onChangeText=updateNoteFn
              onSubmitEditing=(addNoteAndGoHome)
              numberOfLines=3
              multiline=true
              blurOnSubmit=true
              placeholder="Insert moment here"
            />
          </Row>
          <Row size=2>
            <TouchableOpacity
              style=Style.(style([flex(1.)]))
              onPress=((_event) => controlAction(Control.(ChangeScene(Home))))
            />
          </Row>
        </Grid>
      </CardBorderLayout>
    </KeyboardAvoidingView>
};