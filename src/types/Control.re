type papercolor =
  | Red
  | Orange
  | Yellow;

let papercolors = [Red, Orange, Yellow];

type note = {
  id: int,
  text: string,
  color: papercolor,
  time: int,
};

type notes = list(note);

type scene =
  | Home
  | Shake
  | Add;

type state = {scene, notes};

type action =
  | ChangeScene(scene)
  | AddNoteAndToHome(string)
  | Rehydrate(notes);
