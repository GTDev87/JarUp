open BsReactNative;

let app = () : ReasonReact.reactElement =>
  <View style=Style.(style([
    flex(1.),
    backgroundColor(String("transparent")),
  ]))>
    <View style=Style.(style([ height(Pt(Dimension.topBarHeight)), ])) />
    <ControlView />
  </View>;
  