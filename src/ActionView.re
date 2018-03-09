open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let marginBottomVal = 30.;

let make = (_children) /*: ReasonReact.componentSpec(`a, `b, `c, `d, `e)*/ => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          padding(Pt(marginBottomVal)),
          backgroundColor("purple"),
          flexDirection(Row),
          justifyContent(SpaceBetween),
        ])
    )>
      <TouchableOpacity
        onPress=((_) => Js.log("Add to Jar"))
      >
        <Text value="Add to Jar" />
      </TouchableOpacity>
      <TouchableOpacity
        onPress=((_) => Js.log("Shake"))
      >
        <Text value="Shake it up!" />
      </TouchableOpacity>
    </View>
};
