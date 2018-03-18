open BsReactNative;

let component = ReasonReact.statelessComponent("ActionView");

let marginBottomVal = 30.;

let make = (~controlAction, ~openPullCardModal, _children) => {
  ...component,
  render: (_self) =>
    <Grid>
      <Col size=2>
        <AddModalButton controlAction=controlAction />
      </Col>
      <Col size=1/>
      <Col size=2>
        <ShakeModalButton openPullCardModal=openPullCardModal />
      </Col>
    </Grid>
};
