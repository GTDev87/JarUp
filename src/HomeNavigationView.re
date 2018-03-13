open BsReactNative;

let illumeImage : Packager.required = Packager.require("../../../assets/icons/illume_type_b.png");
let illumeIcon : Image.imageSource = Image.Required(illumeImage);

let illumeUpArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_up.png");
let illumeUpArrowIcon : Image.imageSource = Image.Required(illumeUpArrowImage);

let illumeDownArrowImage : Packager.required = Packager.require("../../../assets/icons/arrow_down.png");
let illumeDownArrowIcon : Image.imageSource = Image.Required(illumeDownArrowImage);



let navigationHeight = 40.;
let largeDimension = 30000.;
let illumeFontHeight = 20.;
let illumeFontWidth = 80.;
let triangleSize = 20.;

let flipIcon = (isUp) => {
  switch (isUp) {
  | true => illumeUpArrowIcon
  | false => illumeDownArrowIcon
  }
};

type action =
  | Open
  | Close;

let faqText = "stores moments that paint a smile on your face and reminds you of them in times when life tries to knock you down. From small acts of kindness to big milestones, by pressing the (+) button a small note box will appear, you can write down the moment and then save it. illume will then store it in the memory jar for Safe keeping.";

type state = {modalOpen: bool};

let component = ReasonReact.reducerComponent("HomeNavigationView");

let make = (_children) => {
  ...component,
  initialState: () => {modalOpen: false},
  reducer: fun (action, _state) =>
    switch action {
    | Open => ReasonReact.Update({modalOpen: true})
    | Close => ReasonReact.Update({modalOpen: false})
    },
  render: (self) => {
    let arrow =
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
        source=flipIcon(self.state.modalOpen)
      />;

    <View>
      <Modal2
        isVisible=(Js.Boolean.to_js_boolean(self.state.modalOpen))
        onBackdropPress={(_) => self.send(Close); }
        animationIn="slideInDown"
      >
        <Text
          style=Style.(style([color("black")]))
          value="What awesome things happend to you today?"
        />
      </Modal2>
      <TouchableOpacity onPress=((_) => self.send(Open))>
        <View
          style=Style.(
            style([
              flexDirection(Row),
              justifyContent(Center),
              height(Pt(navigationHeight)),
              borderBottomWidth(1.)
            ])
          )
        >
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
            source=illumeIcon
          />
          { arrow }
        </View>
      </TouchableOpacity>
    </View>
  }
};
