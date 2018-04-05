open BsReactNative;

let image : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_empty.png");
let jarIconEmpty : Image.imageSource = Image.Required(image);

let image1 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_1.png");
let jarIcon1 : Image.imageSource = Image.Required(image1);

let image2 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_2.png");
let jarIcon2 : Image.imageSource = Image.Required(image2);

let image3 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_3.png");
let jarIcon3 : Image.imageSource = Image.Required(image3);

let image4 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_4.png");
let jarIcon4 : Image.imageSource = Image.Required(image4);

let image5 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_5.png");
let jarIcon5 : Image.imageSource = Image.Required(image5);

let image6 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_6.png");
let jarIcon6 : Image.imageSource = Image.Required(image6);

let image7 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_7.png");
let jarIcon7 : Image.imageSource = Image.Required(image7);

let image8 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_8.png");
let jarIcon8 : Image.imageSource = Image.Required(image8);

let image9 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_9.png");
let jarIcon9 : Image.imageSource = Image.Required(image9);

let image10 : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_10.png");
let jarIcon10 : Image.imageSource = Image.Required(image10);

let imageHalf : Packager.required = Packager.require("../../../../../assets/icons/jar/jar_half.png");
let jarIconHalf : Image.imageSource = Image.Required(imageHalf);

let imageFull : Packager.required = Packager.require(".../../../../../assets/icons/jar/jar_full.png");
let jarIconFull : Image.imageSource = Image.Required(imageFull);

let largeDimension = 30000.;
let distanceFromWindowEdge = 40;

let windowWidth = Dimensions.get(`window)##width;

let jarWidth = float_of_int(windowWidth - distanceFromWindowEdge * 2);

type state = {animationRef: ref(option(ReasonReact.reactRef))};
type action =
  | SetAnimationRef(ref(option(ReasonReact.reactRef)));

let component = ReasonReact.reducerComponent("HomeDisplayView");

let setSectionRef = (theRef, {ReasonReact.state}) => {
  state.animationRef := Js.Nullable.toOption(theRef);
};

let iconFromNumberNotes = (numberOfNotes) =>
  switch(numberOfNotes) {
  | 0 => jarIconEmpty
  | 1 => jarIcon1
  | 2 => jarIcon2
  | 3 => jarIcon3
  | 4 => jarIcon4
  | 5 => jarIcon5
  | 6 => jarIcon6
  | 7 => jarIcon7
  | 8 => jarIcon8
  | 9 => jarIcon9
  | 10 => jarIcon10
  | (11|12|13|14|15) => jarIconHalf
  | _ => jarIconFull
  };

let make = (~openPullCardModal, ~notes, _children) => {
  ...component,
  initialState: () => ({animationRef: ref(None)}),
  reducer: fun (action, _state : state) =>
    switch action {
    | SetAnimationRef(animationRef) =>
        ReasonReact.Update({animationRef: animationRef})
    },
  render: (self) =>
    <View style=Style.(style([margin(Pct(8.5)), flex(1.)]))>
      <AnimatableView
        ref={self.handle(setSectionRef)}
        animation="wobble"
        duration=6000
        style=Style.(style([flex(1.)]))
      >
        <TouchableOpacity
          onPress=openPullCardModal
          style=Style.(style([flex(1.)]))
        >
          <Image
            style=Style.(
              style([
                flex(1.),
                unsafeStyleElement("width", Js.Json.null),
                unsafeStyleElement("height", Js.Json.null),
              ]))
            resizeMode=`contain
            source=iconFromNumberNotes(List.length(notes))
          />
        </TouchableOpacity>
      </AnimatableView>
    </View>
};
