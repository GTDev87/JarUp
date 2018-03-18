open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let marginBottomVal = 30.;

let make = (~controlAction, ~scene, ~openPullCardModal, _children) => {
  ...component,
  render: (_self) =>
    <Grid>
      <Col size=1>
        <AddModalButton scene=scene controlAction=controlAction />
      </Col>
      <Col size=3/>
      <Col size=1>
        <ShakeModalButton openPullCardModal=openPullCardModal/>
      </Col>
    </Grid>
};
