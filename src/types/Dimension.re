open BsReactNative;

let topBarHeight =
  (Platform.equals(IOS(Phone))) ? 20. : float_of_int(StatBar.constants##currentHeight);

let cardTop = (Platform.equals(IOS(Phone))) ? 20. : 0.;