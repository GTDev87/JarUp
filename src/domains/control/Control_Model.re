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
  | Landing
  | Faq
  | Add;

type icon =
  | Heart
  | Smile
  | Happy;

type state = {
  scene,
  notes,
  selectedNote: note,
  icon,
  noteText: string
};

let defaultNote : note = {
  id: -1,
  text: "You have not added an awesome moment yet.",
  color: Red,
  time: 0,
};

let defaultState = {
  scene: Landing,
  notes: [],
  noteText: "",
  selectedNote: defaultNote,
  icon: Heart
};
