open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let squiggleImage : Packager.required = Packager.require("../../../assets/icons/squiggle.png");
let squiggleIcon : Image.imageSource = Image.Required(squiggleImage);

let marginBottomVal = 30.;

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component,
  render: (_self) =>
    <Grid>
      <Col size=1>
        <AddModalButton scene=scene controlAction=controlAction />
      </Col>
      <Col size=3/>
      <Col size=1>
        <ShakeModalButton scene=scene controlAction=controlAction notes=notes />
      </Col>
    </Grid>
};
