open BsReactNative;

let blackIllumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_b.png");
let blackIllumeIcon : Image.imageSource = Image.Required(blackIllumeImage);

let orangeIllumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_y_o.png");
let orangeIllumeIcon : Image.imageSource = Image.Required(orangeIllumeImage);

let illumeUpArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_up.png");
let illumeUpArrowIcon : Image.imageSource = Image.Required(illumeUpArrowImage);

let illumeDownArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_down.png");
let illumeDownArrowIcon : Image.imageSource = Image.Required(illumeDownArrowImage);

let faqBorderImage : Packager.required = Packager.require("../../../assets/icons/faq_border.png");
let faqBorderIcon : Image.imageSource = Image.Required(faqBorderImage);


let navigationHeight = 40.;
let largeDimension = 30000.;
let illumeFontHeight = 20.;
let illumeFontWidth = 80.;
let triangleSize = 20.;

/* following are duplicate from HomeDisplayView */
let distanceFromWindowEdge = 40;
let windowWidth = Dimensions.get(`window)##width;
let faqWidth = float_of_int(windowWidth - distanceFromWindowEdge * 2);

let flipIcon = (isUp) => {
  switch (isUp) {
  | true => illumeUpArrowIcon
  | false => illumeDownArrowIcon
  }
};

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
  | true => Down
  | false => Up
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
        flex(1.),
        height(Pt(triangleSize)),
        alignSelf(Center),
        maxWidth(Pt(triangleSize)),
        overflow(Hidden),
        marginTop(Pt(10.)),
      ]))
    resizeMode=`contain
    source=arrowDirectionToIcon(arrowDirection)
  />;

let illumeImageFn = (imageColor) =>
  <Image
    style=Style.(
      style([
        flex(1.),
        height(Pt(illumeFontHeight)),
        alignSelf(Center),
        maxWidth(Pt(illumeFontWidth)),
        overflow(Hidden),
      ]))
    resizeMode=`contain
    source=colorToImage(imageColor)
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
    <View>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(self.state.modalOpen))
        onBackdropPress={(_) => self.send(Close); }
        animationIn="slideInDown"
        animationOut="slideOutUp"
        style=Style.(
          style([
            justifyContent(FlexStart),
          ])
        )
      >
        <View
          style=Style.(
            style([position(Relative),
            marginTop(Pt(navigationHeight)),
            flex(1.),
            width(Pt(faqWidth)),
            alignSelf(Center),
          ]))
        >
          <Image
            style=Style.(
              style([
                alignSelf(Center),
                maxHeight(Pt(400.)), /* I don't like this value here */
                position(Absolute),
              ]))
            resizeMode=`contain
            source=faqBorderIcon
          />
          <View
            style=Style.(
              style([
                flex(1.),
                position(Absolute),
                marginHorizontal(Pt(25.)),
                marginVertical(Pt(15.)),
                color(Colors.redPrimaryString),
                fontSize(Float(16.)),
              ])
            )
          >
            { illumeImageFn(Orange) }
            <Text
              value=faqText
              style=Style.(
                style([
                  fontWeight(`_500),
                  color(Colors.redPrimaryString),
                  fontSize(Float(16.)),
                ])
              )
            />
          </View>
        </View>
      </Modal2>
      <TouchableOpacity onPress=((_) => self.send(Open))>
        <View
          style=Style.(
            style([
              flexDirection(Row),
              justifyContent(Center),
              height(Pt(navigationHeight)),
            ])
          )
        >
          { illumeImageFn(Black) }
          { self.state.modalOpen |> modalOpenToArrowDirection |> arrowImageFn }
        </View>
      </TouchableOpacity>
    </View>
  };
