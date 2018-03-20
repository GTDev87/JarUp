open BsReactNative;

let component = ReasonReact.statelessComponent("PullCardModal");

let isNotHome = (scene) => scene !== Control.Home;
let pickScene = (scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome) =>
  switch(scene) {
  | Control.Shake => <ShakeModal controlAction=controlAction pullCardState=pullCardState />
  | Control.Add => <AddModal updateNoteFn=updateNoteFn controlAction=controlAction addNoteAndGoHome=addNoteAndGoHome/>
  | Control.Home => <View />
  | Control.Landing => <LandingModal controlAction=controlAction/>
  };

let make = (~addNoteAndGoHome, ~updateNoteFn, ~controlAction, ~scene, ~pullCardState : PullCardState.state, _children) => {
  ...component, 
  render: (_self) =>
    <Modal2
      isVisible=(scene |> isNotHome)
      animationOut="zoomOutUp"
      animationIn="zoomInDown"
      animationOutTiming=100.
      backdropTransitionInTiming=800.
      backdropTransitionOutTiming=800.
      style=Style.(style([
        flex(1.),
        margin(Pt(0.)),
        marginTop(Pt(Dimension.cardTop)),
      ]))
    >
      { pickScene(scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome) }
    </Modal2>
};