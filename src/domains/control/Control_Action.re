type action =
  | ChangeScene(Control_Model.scene)
  | AddNoteAndToHome(string)
  | Rehydrate(Control_Model.notes)
  | RemoveNoteAndToHome(int)
  | SelectNote
  | UpdateNote(string)
  | NoAction;

let textToNote = (text, id) : Control_Model.note => {
  let color = Utils.selectRandomFromList(Control_Model.papercolors, Control_Model.Red);
  let time = Moment.(moment(None) |> Moment.valueOf());
  { id, text, color, time};
};

let max = (list) => Belt.List.reduce(list, 0, (x, y) => (x > y ? x : y));

let addOne = (a) => a + 1;

let addNoteToState = (state : Control_Model.state, text) => {
  let note =
    state.notes
    |> Belt.List.map(_, (note) => note.id)
    |> max
    |> addOne
    |> textToNote(text, _);

  {
    ...state,
    noteText: "",
    notes: [note, ...state.notes],
    scene: Control_Model.Home,
  };
};

let selectRandomNote = (notes : Control_Model.notes) => Utils.selectRandomFromList(notes, Control_Model.defaultNote);

let iconChoices = [Control_Model.Heart, Control_Model.Smile, Control_Model.Happy];

let characterLimit = 80;

let chooseRandomIcon = () => Utils.selectRandomFromList(iconChoices, Heart);

let removeNoteToState = (state : Control_Model.state, id) : Control_Model.state =>
  {
    ...state,
    notes: state.notes |> Belt.List.keep(_, (note) => note.id != id),
    scene: Control_Model.Home
  };

let reduce = (action, state: Control_Model.state) =>
  switch action {
  | Rehydrate(notes) => ReasonReact.Update({...state, notes})
  | AddNoteAndToHome(text) =>
      text === "" ?
        ReasonReact.Update({...state, scene: Control_Model.Home}) :
        ReasonReact.Update(addNoteToState(state, text))
  | RemoveNoteAndToHome(id) => ReasonReact.Update(removeNoteToState(state, id))
  | ChangeScene(scene) => ReasonReact.Update {...state, scene}
  | SelectNote =>
    ReasonReact.Update(
      {
        ...state,
        scene: Control_Model.Shake,
        selectedNote: selectRandomNote(state.notes),
        icon: chooseRandomIcon()
      }
    ) /* investigate this */
  | UpdateNote(noteText) =>
    String.length(noteText) < characterLimit ?
        ReasonReact.Update({...state, noteText}) :
        ReasonReact.NoUpdate
  | NoAction => ReasonReact.NoUpdate
  };