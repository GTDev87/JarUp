open BsReactNative;

let component = ReasonReact.statelessComponent("PullCardModal");

let isNotHome = (scene) => scene !== Control.Home;
let pickScene = (scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome) =>
  switch(scene) {
  | Control.Shake => <ShakeModal controlAction=controlAction pullCardState=pullCardState />
  | Control.Add => <AddModal updateNoteFn=updateNoteFn controlAction=controlAction addNoteAndGoHome=addNoteAndGoHome/>
  | Control.Home => <View />
  };

let make = (~addNoteAndGoHome, ~updateNoteFn, ~controlAction, ~scene, ~pullCardState : PullCardState.state, _children) => {
  ...component, 
  render: (_self) =>
    <Modal2
      isVisible=(scene |> isNotHome)
      animationOut="zoomOutUp"
      animationIn="zoomInDown"
      animationOutTiming=1000.
      backdropTransitionInTiming=1000.
      backdropTransitionOutTiming=1000.
      style=Style.(style([
        flex(1.),
        margin(Pt(0.)),
        marginTop(Pt(Dimension.cardTop)),
      ]))
    >
      { pickScene(scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome) }
    </Modal2>
};