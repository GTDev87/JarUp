open BsReactNative;

let component = ReasonReact.statelessComponent("ShakeModalButton");

let make = (~openPullCardModal, _children) => {
  ...component, 
  render: (_self) =>
    <View
      style=Style.(style([
        flex(1.),
        justifyContent(Center),
        alignItems(Center),
      ]))
    >
      <TouchableOpacity onPress=openPullCardModal>
        <Foundation name="shuffle" size=30 color="gray" />
      </TouchableOpacity>
    </View>
};
