type papercolor =
  | Red
  | Orange
  | Yellow;

type note = {
  id: int,
  text: string,
  color: papercolor
};

type notes = list(note);

type scene =
  | Home
  | Shake
  | Add;

type state = {scene, notes};

type action =
  | ToHome
  | ToShake
  | ToAdd
  | Rehydrate(state);




