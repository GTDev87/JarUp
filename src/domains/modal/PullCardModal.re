open BsReactNative;

let component = ReasonReact.statelessComponent("PullCardModal");

let isNotHome = (scene) => scene !== Control.Model.Home;

let pickScene = (scene, controlAction, updateNoteFn, addNoteAndGoHome, noteText, selectedNote, icon) =>
  switch(scene) {
  | Control.Model.Shake =>
      <ShakeModal
        controlAction=controlAction
        selectedNote=selectedNote
        icon=icon
      />
  | Control.Model.Add =>
      <AddModal
        updateNoteFn=updateNoteFn
        addNoteAndGoHome=addNoteAndGoHome
        text=noteText
      />
  | Control.Model.Home => <View />
  | Control.Model.Landing => <LandingModal controlAction=controlAction/>
  | Control.Model.Faq => <FaqModal controlAction=controlAction/>
  };

let make = (
  ~addNoteAndGoHome,
  ~updateNoteFn,
  ~controlAction,
  ~scene,
  ~noteText : string,
  ~selectedNote : Control.Model.note,
  ~icon : Control.Model.icon,
  _children
) => {
  ...component, 
  render: (_self) =>
    <Modal2
      isVisible=(scene |> isNotHome)
      animationOut=(scene === Control.Model.Faq ? "slideOutUp" : "zoomOutUp")
      animationIn=(scene === Control.Model.Faq ? "slideInDown" : "zoomInDown")
      animationOutTiming=(scene === Control.Model.Faq ? 0. : 100.)
      backdropOpacity=0.
      backdropTransitionInTiming=800.
      backdropTransitionOutTiming=800.
      style=Style.(style([
        flex(1.),
        margin(Pt(0.)),
        marginTop(Pt(Dimension.cardTop)),
      ]))
    >
      { pickScene(scene, controlAction, updateNoteFn, addNoteAndGoHome, noteText, selectedNote, icon) }
    </Modal2>
};
