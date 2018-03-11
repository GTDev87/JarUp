open BsReactNative;
open Control;

let navigationHeight = 50.;

let component = ReasonReact.reducerComponent("ControlView");

let make = (_children) => {
  ...component,
  initialState: () : Control.state => {scene: Control.Home},
  reducer: fun (action, _state: Control.state) =>
    switch action {
    | ToHome => ReasonReact.Update {scene: Control.Home}
    | ToShake => ReasonReact.Update {scene: Control.Shake}
    | ToAdd => ReasonReact.Update {scene: Control.Add}
    },
  render: fun (self) => {
    /*let scene : Control.scene = self.state.scene;*/

    "the state is: " |> Js.log;
    self.state |> Js.log;

    switch self.state.scene {
    | Home => <HomeView controlAction=self.send />;
    | Shake => <Text value="SHAKE" />
    | Add => <Text value="ADD" />
    }
  }
};
