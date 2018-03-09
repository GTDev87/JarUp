open BsReactNative;

let iosBarHeight = 20.;

/*let windowWidth = Dimensions.get(`window)##width;*/

let app = () : ReasonReact.reactElement =>
  <View
    style=Style.(
      style([
        flex(1.),
      ])
  )>
    <View
      style=Style.(
        style([
          height(Pt(iosBarHeight)),
          backgroundColor("green"),
        ])
    ) />
    <NavigationView />
    <DisplayView />
    <ActionView />
  </View>;
  