type icon =
  | Heart
  | Smile
  | Happy;

type state = {
  selectedNote: Control.Model.note,
  icon,
  noteText: string
};

type action =
  | SelectNote
  | UpdateNote(string)
  | NoAction;