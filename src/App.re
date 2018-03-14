open BsReactNative;

let iosBarHeight =
  (
    Platform.os === Platform.IOS
    ? 20.
    : float_of_int(StatBar.constants##currentHeight)
  );

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
  