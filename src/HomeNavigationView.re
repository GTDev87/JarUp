open BsReactNative;

let orangeIllumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_y_o.png");
let orangeIllumeIcon : Image.imageSource = Image.Required(orangeIllumeImage);

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

let faqText = "Stores moments that paint a smile on your face and reminds you of them in times when it can be hard to smile. From small acts of kindness to big milestones, by pressing the (+) button a small note box will appear, you can write down the moment and then save it. illume will then store it in the memory jar for Safe keeping. You can view your happy memories by pressing on the (shuffle) button. The shuffle button will randomly select a memory and display it to you so you can be reminded of the wonderful moments small and big that surround you in your life.";

type state = {modalOpen: bool};

let component = ReasonReact.reducerComponent("HomeNavigationView");

type imageColor =
  | Black
  | Orange;

type arrowDirection =
  | Up
  | Down;

let illumeImageFn = () =>
  <Image
    style=Style.(
      style([
        maxHeight(Pct(100.)),
        maxWidth(Pct(100.)),
        marginTop(Pct(5.)),
        alignItems(FlexStart),
      ]))
    resizeMode=`contain
    source=orangeIllumeIcon
  />;

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
            footerText="Keep those good vibes rolling."
            footerColor=Colors.redPrimaryString
          >
            <Grid>
              <Row size=1>
                <Col style=Style.(style([paddingRight(Pct(5.)),]))>
                  { illumeImageFn() }
                </Col>
                <Col size=1 />
              </Row>
              <Row size=1 />
              <Row size=8>
                <Text
                  value=faqText
                  style=Style.(
                    style([
                      fontWeight(`_500),
                      color("black"),
                      fontSize(Float(16.)),
                      textAlign(Justify)
                    ])
                  )
                />
              </Row>
            </Grid>
          </CardBorderLayout>
        </TouchableOpacity>
      </Modal2>
      <Grid
        style=Style.(
          style([
            flex(1.),
            backgroundColor("transparent"),
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
                { illumeImageFn() }
              </Col>
              <Col />
            </Grid>
          </TouchableOpacity>
        </Col>
        <Col size=1 />
      </Grid>
    </View>
  };
