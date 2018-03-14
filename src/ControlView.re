open Control;

let navigationHeight = 50.;

let component = ReasonReact.reducerComponent("ControlView");

let make = (_children) => {
  ...component,
  didUpdate: ({newSelf}) => Persistence.persist(newSelf.state.notes),
  didMount: (self) => Persistence.rehydrate(self),
  initialState: () : Control.state => {scene: Control.Home, notes: []},
  reducer: fun (action, state: Control.state) =>
    switch action {
    | Rehydrate(notes) => ReasonReact.Update({...state, notes})
    | ToHome => ReasonReact.Update {...state, scene: Control.Home}
    | ToShake => ReasonReact.Update {...state, scene: Control.Shake}
    | ToAdd => ReasonReact.Update {...state, scene: Control.Add}
    },
  render: fun (self) => {
    /*let scene : Control.scene = self.state.scene;*/

    "the state is: " |> Js.log;
    self.state |> Js.log;

    <HomeView controlAction=self.send scene=self.state.scene />;
  }
};
