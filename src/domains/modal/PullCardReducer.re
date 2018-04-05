open BsReactNative;

let defaultNote : Control.Model.note = Control.Model.{
  id: -1,
  text: "You have not added an awesome moment yet.",
  color: Control.Model.Red,
  time: 0,
};

let iconChoices = [PullCardState.Heart, PullCardState.Smile, PullCardState.Happy];

let chooseRandomIcon = () => Utils.selectRandomFromList(iconChoices, Heart);

let selectRandomNote = (notes) => Utils.selectRandomFromList(notes, defaultNote);

let component = ReasonReact.reducerComponent("PullCardReducer");

let isShakeScene = (scene) => scene == Control.Model.Shake;

let characterLimit = 60;

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
        (_self => controlAction(Control.Model.(ChangeScene(Shake))))
      ) /* investigate this */
    | PullCardState.UpdateNote(noteText) =>
      String.length(noteText) < characterLimit ?
          ReasonReact.Update({...state, noteText}) :
          ReasonReact.NoUpdate
    | PullCardState.NoAction => ReasonReact.NoUpdate
    },
  render: (self) =>
    <View style=Style.(style([flex(1.)]))>
      <PullCardModal
        controlAction=controlAction
        scene=scene
        pullCardState=self.state
        addNoteAndGoHome=((_event) => controlAction(Control.Model.AddNoteAndToHome(self.state.PullCardState.noteText)))
        updateNoteFn=((text) => self.send(PullCardState.UpdateNote(text)))
        text=self.state.noteText
      />
      <HomeView
        controlAction=controlAction
        notes=notes
        openPullCardModal=(
          (_event) => self.send((scene |> isShakeScene) ? PullCardState.NoAction : PullCardState.SelectNote))
      />
    </View>
};