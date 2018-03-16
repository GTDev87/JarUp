open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");

let make = (~controlAction, ~scene, ~notes, _children) => {
  ...component,
  render: (_self) =>
    <View
      style=Style.(
        style([
          flex(1.),
          backgroundColor("transparent"),
        ])
      )
    >
      <Container>
        <Grid>
          <Row size=1>
            <HomeNavigationView />
          </Row>
          <Row size=10>
            <HomeDisplayView  />
          </Row>
          <Row size=1>
            <HomeActionView controlAction=controlAction scene=scene notes=notes />
          </Row>
        </Grid>
      </Container>
    </View>
};
