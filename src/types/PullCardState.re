type icon =
  | Heart
  | Smile
  | Happy;

type state = {selectedNote: Control.note, icon};
type action =
  | SelectNote
  | NoAction;