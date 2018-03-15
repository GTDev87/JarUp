open Belt;
open Control;

let navigationHeight = 50.;

let component = ReasonReact.reducerComponent("ControlView");

let textToNote = (text, id) => {
  let randomColorMaybe =
    Control.papercolors
    |> List.length
    |> Random.int
    |> List.get(Control.papercolors, _);

  let color =
    switch(randomColorMaybe) {
    | None => Control.Red
    | Some(color) => color
    };
  {
    id,
    text,
    color,
    time: Js.Date.now() |> int_of_float,
  };
};

let addNoteToState = (state, text) => {
  let highestNoteId =
    state.notes
      |> List.map(_, (note) => note.id)
      |> List.reduce(_, 0, (x, y) =>(x > y ? x : y));
  let note = textToNote(text, highestNoteId + 1);
  {notes: [note, ...state.notes], scene: Control.Home};
};

let make = (_children) => {
  ...component,
  didUpdate: ({newSelf}) => Persistence.persist(newSelf.state.notes),
  didMount: (self) => Persistence.rehydrate(self),
  initialState: () : Control.state => {scene: Control.Home, notes: []},
  reducer: fun (action, state: Control.state) =>
    switch action {
    | Rehydrate(notes) => ReasonReact.Update({...state, notes})
    | AddNoteAndToHome(text) => ReasonReact.Update(addNoteToState(state, text))
    | ChangeScene(scene) => ReasonReact.Update {...state, scene}
    },
  render: fun (self) => {
    "the scene is: " |> Js.log;
    self.state.scene |> Js.log;

    "the notes is: " |> Js.log;
    self.state.notes |> Js.log;
    <HomeView controlAction=self.send scene=self.state.scene />;
  }
};
