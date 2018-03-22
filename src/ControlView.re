open Belt;
open Control;

let navigationHeight = 50.;

let component = ReasonReact.reducerComponent("ControlView");

let textToNote = (text, id) => {
  let color = Utils.selectRandomFromList(Control.papercolors, Control.Red);
  let time = Moment.(moment(None) |> Moment.valueOf());
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

let removeNoteToState = (state, id) =>
  {
    notes: state.notes |> List.keep(_, (note) => note.id != id),
    scene: Control.Home
  };

let make = (_children) => {
  ...component,
  didUpdate: ({newSelf}) => Persistence.persist(newSelf.state.notes),
  didMount: (self) => Persistence.rehydrate(self),
  initialState: () : Control.state => ({scene: Control.Landing, notes: []}),
  reducer: (action, state: Control.state) =>
    switch action {
    | Rehydrate(notes) => ReasonReact.Update({...state, notes})
    | AddNoteAndToHome(text) =>
        text === "" ?
          ReasonReact.Update({...state, scene: Control.Home}) :
          ReasonReact.Update(addNoteToState(state, text))
    | RemoveNoteAndToHome(id) => ReasonReact.Update(removeNoteToState(state, id))
    | ChangeScene(scene) => ReasonReact.Update {...state, scene}
    },
  render: (self) =>
    <PullCardReducer controlAction=self.send scene=self.state.scene notes=self.state.notes />
};
