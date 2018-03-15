open Belt;
open Control;

let navigationHeight = 50.;

let component = ReasonReact.reducerComponent("ControlView");

let textToNote = (text, id) => {
  let color = Utils.selectRandomFromList(Control.papercolors, Control.Red);
  let time = Js.Date.now() |> int_of_float;
  { id, text, color, time};
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
  initialState: () : Control.state => ({scene: Control.Home, notes: []}),
  reducer: (action, state: Control.state) =>
    switch action {
    | Rehydrate(notes) => ReasonReact.Update({...state, notes})
    | AddNoteAndToHome(text) => ReasonReact.Update(addNoteToState(state, text))
    | ChangeScene(scene) => ReasonReact.Update {...state, scene}
    },
  render: (self) =>
    <HomeView controlAction=self.send scene=self.state.scene notes=self.state.notes />
};
