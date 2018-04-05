open BsReactNative;

let navigationHeight = 40.;
let largeDimension = 30000.;
let illumeFontHeight = 20.;
let illumeFontWidth = 80.;
let triangleSize = 20.;

/* following are duplicate from HomeDisplayView */
let distanceFromWindowEdge = 30;
let windowWidth = Dimensions.get(`window)##width;
let faqWidth = float_of_int(windowWidth - distanceFromWindowEdge * 2);

type action =
  | Open
  | Close;

let faqTextPart = "illume stores your happy moments and reminds you of them when you are feeling down. By pressing the pen tool a note box will appear. Write down a happy moment and then save it. It can be as simple as a kind gesture from a stranger to a big milestone that fills you with a sense of satisfaction. illume stores your notes as memories in the jar for safe keeping. To view your stored memories press on the jar and a random memory will pop up. You can view several memories by pressing the jar several times. You can also erase a memory by holding down the card and then pressing on the delete option.";

type state = {modalOpen: bool};

let component = ReasonReact.reducerComponent("HomeNavigationView");

type arrowDirection =
  | Up
  | Down;

let make = (_children) => {
  ...component,
  initialState: () => {modalOpen: false},
  reducer: fun (action, _state) =>
    switch action {
    | Open => ReasonReact.Update({modalOpen: true})
    | Close => ReasonReact.Update({modalOpen: false})
  },
  render: (self) =>
    <View
      style=Style.(
        style([
          flex(1.),
        ])
      )
    >
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(self.state.modalOpen))
        onBackdropPress={(_) => self.send(Close); }
        animationIn="slideInDown"
        animationOut="slideOutUp"
        style=Style.(
          style([
            margin(Pt(0.)),
            marginTop(Pt(Dimension.cardTop)),
          ])
        )
      >
        <TouchableOpacity
          style=Style.(style([
            flex(1.),
          ]))
          onPress=(() => self.send(Close))
        >
          <CardBorderLayout
            backColor="white"
            footerText="Goodvibes everyday"
            footerColor="black"
          >
            <Grid>
              <Row size=2 />
              <Row size=6>
                <Text
                  value=faqTextPart
                  style=Style.(
                    style([
                      fontWeight(`_500),
                      color(String("black")),
                      fontSize(Float(20.)),
                      textAlign(Left),
                      textAlignVertical(Top),
                    ])
                  )
                  adjustsFontSizeToFit=true
                />
              </Row>
              <Row size=1 />
            </Grid>
          </CardBorderLayout>
        </TouchableOpacity>
      </Modal2>
      <Grid
        style=Style.(
          style([
            flex(1.),
            backgroundColor(String("transparent")),
          ]))
      > 
        <Col size=1 />
        <Col size=3>
          <TouchableOpacity
            style=Style.(style([flex(1.),]))
            onPress=((_) => self.send(Open))
          >
             <Grid
              style=Style.(
                style([
                  flex(1.),
                  flexDirection(Row),
                ])
              )
            >
              <Col />
              <Col size=3>
                <Grid>
                  <Col size=4>
                    <IllumeImage />
                  </Col>
                  <Col size=1>
                    <View style=Style.(style([flex(1.), justifyContent(FlexEnd)]))>
                      <Entypo name="chevron-down" size=16 color="Black" style=Style.(style([alignSelf(Center),])) />
                    </View>
                  </Col>
                </Grid>
              </Col>
              <Col />
            </Grid>
          </TouchableOpacity>
        </Col>
        <Col size=1 />
      </Grid>
    </View>
  };
