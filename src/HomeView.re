open BsReactNative;

let component = ReasonReact.statelessComponent("HomeView");


let make = (~controlAction, ~openPullCardModal, _children) => {
  ...component,
  render: (_self) =>
    <View style=Style.(style([flex(1.),]))>
      <Container>
        <Grid>
          <Row size=1>
            <HomeNavigationView />
          </Row>
          <Row size=9>
            <HomeDisplayView openPullCardModal=openPullCardModal/>
          </Row>
          <Row size=2>
            <HomeActionView controlAction=controlAction/>
          </Row>
        </Grid>
      </Container>
    </View>
};
