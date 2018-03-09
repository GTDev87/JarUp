open BsReactNative;

let image : Packager.required = Packager.require("../../../assets/icons/icon.png");
let jarIcon : Image.imageSource = Image.Required(image);

let iosBarHeight = 20.;
let marginBottomVal = 30.;

let windowWidth = Dimensions.get(`window)##width;

let navigationHeight = 50.;
let largeDimension = 30000.;


let app = () : ReasonReact.reactElement =>
  <View
    style=Style.(
      style([
        flex(1.),
      ])
  )>
    <View
      style=Style.(
        style([
          height(Pt(iosBarHeight)),
          backgroundColor("green"),
        ])
    ) />
    <View
      style=Style.(
        style([
          height(Pt(navigationHeight)),
          backgroundColor("red"),
        ])
    )>
    </View>
    <Image
      style=Style.(
        style([
          flex(1.),
          width(Pt(largeDimension)),
          alignSelf(Center),
          maxHeight(Pt(largeDimension)),
          overflow(Hidden),
          backgroundColor("rgb(75, 118, 134)"),
        ]))
      resizeMode=`contain
      source=jarIcon
    />
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
  </View>;
  