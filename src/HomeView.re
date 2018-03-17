open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");


let make = (~controlAction, ~scene, ~openPullCardModal, _children) => {
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
            <HomeDisplayView openPullCardModal=openPullCardModal/>
          </Row>
          <Row size=1>
            <HomeActionView controlAction=controlAction scene=scene openPullCardModal=openPullCardModal/>
          </Row>
        </Grid>
      </Container>
    </View>
};
