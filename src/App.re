open BsReactNative;

let iosBarHeight = 20.;

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
        ])
    ) />
    <ControlView />
  </View>;
  