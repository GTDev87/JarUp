open BsReactNative;

let defaultNote : Control.note = Control.{
  id: -1,
  text: "You have not added an awesome moment yet.",
  color: Control.Red,
  time: 0,
};

let iconChoices = [PullCardState.Heart, PullCardState.Smile, PullCardState.Happy];

let chooseRandomIcon = () => Utils.selectRandomFromList(iconChoices, Heart);

let selectRandomNote = (notes) => Utils.selectRandomFromList(notes, defaultNote);

let component = ReasonReact.reducerComponent("PullCardReducer");

let isShakeScene = (scene) => scene == Control.Shake;

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component, 
  initialState: () : PullCardState.state => (
    {
      noteText: "",
      selectedNote: defaultNote,
      icon: PullCardState.Heart
    }
  ),
  reducer: fun (action, state : PullCardState.state) =>
    switch action {
    | PullCardState.SelectNote =>
      ReasonReact.UpdateWithSideEffects(
        {...state, selectedNote: selectRandomNote(notes), icon: chooseRandomIcon()},
        (_self => controlAction(Control.(ChangeScene(Shake))))
      ) /* investigate this */
    | PullCardState.UpdateNote(noteText) => ReasonReact.Update({...state, noteText})
    | PullCardState.NoAction => ReasonReact.NoUpdate
    },
  render: (self) =>
    <View style=Style.(style([flex(1.)]))>
      <PullCardModal
        controlAction=controlAction
        scene=scene
        pullCardState=self.state
        addNoteAndGoHome=((_event) => controlAction(Control.AddNoteAndToHome(self.state.PullCardState.noteText)))
        updateNoteFn=((text) => self.send(PullCardState.UpdateNote(text)))
      />
      <HomeView
        controlAction=controlAction
        openPullCardModal=(
          (_event) => self.send((scene |> isShakeScene) ? PullCardState.NoAction : PullCardState.SelectNote))
      />
    </View>
};