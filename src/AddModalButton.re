open BsReactNative;

let component = ReasonReact.statelessComponent("AddModalButton");

let make = (~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(style([
        flex(1.),
        justifyContent(Center),
        alignItems(Center),
      ]))
    >
      <TouchableOpacity onPress=((_event) => controlAction(Control.(ChangeScene(Add))))>
        <Foundation name="pencil" size=30 color="rgb(43, 38, 39)" />
      </TouchableOpacity>
    </View>
};
