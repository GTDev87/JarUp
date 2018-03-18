type icon =
  | Heart
  | Smile
  | Happy;

type state = {
  selectedNote: Control.note,
  icon,
  noteText: string
};

type action =
  | SelectNote
  | UpdateNote(string)
  | NoAction;