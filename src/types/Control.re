type action =
  | ToHome
  | ToShake
  | ToAdd;

type scene =
  | Home
  | Shake
  | Add;

type state = {scene: scene};
