open BsReactNative;

let image : Packager.required = Packager.require("../../../assets/icons/roundedjar.png");
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
    <Grid>
      <Col size=1/>
      <Col size=3>
        <View
          style=Style.(
            style([
              flex(1.),
              position(Relative),
              borderWidth(3.),
            ])
          )
        >
          <FallingPaperStage />
          <AnimatableView
            ref={self.handle(setSectionRef)}
            animation="wobble"
            duration=6000
            style=Style.(style([
              /*flex(1.),*/
              position(Absolute),
              borderWidth(2.),
              borderColor("blue"),
              width(Pct(100.)),
              height(Pct(100.)),
            ]))
          >
            <TouchableOpacity
              onPress=openPullCardModal
              style=Style.(style([
                flex(1.),
                borderColor("green"),
                borderWidth(3.),
                maxWidth(Pct(100.)),
                maxHeight(Pct(100.)),
              ]))
            >
              <Image
                style=Style.(
                  style([
                    /*flex(1.),*/
                    maxWidth(Pct(100.)),
                    maxHeight(Pct(100.)),
                    borderWidth(1.),
                    borderColor("cyan"),
                  ]))
                resizeMode=`contain
                source=jarIcon
              />
            </TouchableOpacity>
          </AnimatableView>
        </View>
      </Col>
      <Col size=1/>
    </Grid>
};
