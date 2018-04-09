open BsReactNative;

let component = ReasonReact.statelessComponent("PullCardReducer");

let isShakeScene = (scene) => scene == Control.Model.Shake;

let make = (~controlAction, ~scene, ~notes, ~noteText, ~selectedNote, ~icon, _children) => {
  ...component, 
  render: (_self) =>
    <View style=Style.(style([
      flex(1.),
      backgroundColor(String("transparent")),
    ]))>
      <PullCardModal
        controlAction=controlAction
        scene=scene
        addNoteAndGoHome=((_event) => controlAction(Control.Action.AddNoteAndToHome(noteText)))
        updateNoteFn=((text) => controlAction(Control.Action.UpdateNote(text)))
        noteText=noteText
        selectedNote=selectedNote
        icon=icon
      />
      <HomeView
        controlAction=controlAction
        notes=notes
        openPullCardModal=(
          (_event) => controlAction((scene |> isShakeScene) ? Control.Action.NoAction : Control.Action.SelectNote))
      />
    </View>
};
