open BsReactNative;

let blackIllumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_b.png");
let blackIllumeIcon : Image.imageSource = Image.Required(blackIllumeImage);

let orangeIllumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_y_o.png");
let orangeIllumeIcon : Image.imageSource = Image.Required(orangeIllumeImage);

let illumeUpArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_up.png");
let illumeUpArrowIcon : Image.imageSource = Image.Required(illumeUpArrowImage);

let illumeDownArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_down.png");
let illumeDownArrowIcon : Image.imageSource = Image.Required(illumeDownArrowImage);

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

let modalOpenToArrowDirection = (modalOpen) => {
  switch(modalOpen) {
  | false => Down
  | true => Up
  }
};

let colorToImage = (imageColor) => {
  switch(imageColor) {
  | Black => blackIllumeIcon
  | Orange => orangeIllumeIcon
  }
};

let arrowDirectionToIcon = (imageColor) => {
  switch(imageColor) {
  | Up => illumeUpArrowIcon
  | Down => illumeDownArrowIcon
  }
};

let arrowImageFn = (arrowDirection) =>
  <Image
    style=Style.(
      style([
        maxHeight(Pct(100.)),
        maxWidth(Pct(100.)),
        marginTop(Pct(20.)),
        alignItems(FlexStart),
      ]))
    resizeMode=`contain
    source=arrowDirectionToIcon(arrowDirection)
  />;

let illumeImageFn = (imageColor) =>
  <Image
    style=Style.(
      style([
        maxHeight(Pct(100.)),
        maxWidth(Pct(100.)),
      ]))
    resizeMode=`contain
    source=colorToImage(imageColor)
  />;

let fullIllumeImage = (modalOpen) =>
  <Grid
    style=Style.(
      style([
        flex(1.),
        flexDirection(Row),
      ])
    )
  >
    <Col size=4>
      { illumeImageFn(Black) }
    </Col>
    <Col>
      { modalOpen |> modalOpenToArrowDirection |> arrowImageFn }
    </Col>
  </Grid>;

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
            marginTop(Pt(Dimension.topBarHeight)),
          ])
        )
      >
        <TouchableOpacity
          style=Style.(style([
            flex(1.),
          ]))
          onPress=(() => self.send(Close))
        >
          <Grid>
            <Row size=1 />
            <Row size=11>
              <Card2
                style=Style.(style([
                  backgroundColor("white"),
                  flex(1.),
                ]))
              >
                <Row size=1>
                  { illumeImageFn(Orange) }
                </Row>
                <Row size=10>
                  <Text
                    value=faqText
                    style=Style.(
                      style([
                        fontWeight(`_500),
                        color("black"),
                        fontSize(Float(16.)),
                        margin(Pt(16.)),
                      ])
                    )
                  />
                </Row>
              </Card2>
            </Row>
          </Grid>
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
            style=Style.(
              style([
                flex(1.),
              ])
            )
            onPress=((_) => self.send(Open))
          >
            { fullIllumeImage(self.state.modalOpen) }
          </TouchableOpacity>
        </Col>
        <Col size=1 />
      </Grid>
    </View>
  };
