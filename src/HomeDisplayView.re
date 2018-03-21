open BsReactNative;

let image : Packager.required = Packager.require("../../../assets/icons/jar.png");
let jarIcon : Image.imageSource = Image.Required(image);


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

let make = (~openPullCardModal, _children) => {
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
            source=jarIcon
          />
        </TouchableOpacity>
      </AnimatableView>
    </View>
};
