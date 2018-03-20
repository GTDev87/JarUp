let component = ReasonReact.statelessComponent("ActionView");

let marginBottomVal = 30.;

let make = (~controlAction, ~openPullCardModal, _children) => {
  ...component,
  render: (_self) =>
    <Grid>
      <Col size=2 />
      <Col size=1>
        <AddModalButton controlAction=controlAction />
      </Col>
      <Col size=2 />
    </Grid>
};
