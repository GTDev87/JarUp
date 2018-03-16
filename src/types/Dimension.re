open BsReactNative;

let topBarHeight =
  (
    Platform.os === Platform.IOS
    ? 20.
    : 0./*float_of_int(StatBar.constants##currentHeight)*/
  );