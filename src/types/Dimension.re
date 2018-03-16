open BsReactNative;

let topBarHeight =
  (Platform.os === Platform.IOS ? 20. : float_of_int(StatBar.constants##currentHeight));

let cardTop = (Platform.os === Platform.IOS ? 20. : 0.);