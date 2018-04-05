open Control.Model;

let component = ReasonReact.reducerComponent("ControlView");

let make = (_children) => {
  ...component,
  didUpdate: ({newSelf}) => Persistence.persist(newSelf.state.notes),
  didMount: (self) => Persistence.rehydrate(self),
  initialState: () : Control.Model.state => Control.Model.defaultState,
  reducer: Control.Action.reduce,
  render: (self) =>
    <PullCardReducer
      controlAction=self.send
      scene=self.state.scene
      notes=self.state.notes
      noteText=self.state.noteText
      selectedNote=self.state.selectedNote
      icon=self.state.icon
    />
};
