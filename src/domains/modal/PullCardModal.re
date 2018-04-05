open BsReactNative;

let component = ReasonReact.statelessComponent("PullCardModal");

let isNotHome = (scene) => scene !== Control.Model.Home;
let pickScene = (scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome, text) =>
  switch(scene) {
  | Control.Model.Shake => <ShakeModal controlAction=controlAction pullCardState=pullCardState />
  | Control.Model.Add => <AddModal updateNoteFn=updateNoteFn controlAction=controlAction addNoteAndGoHome=addNoteAndGoHome text=text/>
  | Control.Model.Home => <View />
  | Control.Model.Landing => <LandingModal controlAction=controlAction/>
  };

let make = (~addNoteAndGoHome, ~updateNoteFn, ~controlAction, ~scene, ~pullCardState : PullCardState.state, ~text : string, _children) => {
  ...component, 
  render: (_self) =>
    <Modal2
      isVisible=(scene |> isNotHome)
      animationOut="zoomOutUp"
      animationIn="zoomInDown"
      animationOutTiming=100.
      backdropOpacity=0.
      backdropTransitionInTiming=800.
      backdropTransitionOutTiming=800.
      style=Style.(style([
        flex(1.),
        margin(Pt(0.)),
        marginTop(Pt(Dimension.cardTop)),
      ]))
    >
      { pickScene(scene, controlAction, pullCardState, updateNoteFn, addNoteAndGoHome, text) }
    </Modal2>
};