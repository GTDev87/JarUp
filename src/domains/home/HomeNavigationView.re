open BsReactNative;

let navigationHeight = 40.;
let largeDimension = 30000.;
let illumeFontHeight = 20.;
let illumeFontWidth = 80.;
let triangleSize = 20.;

/* following are duplicate from HomeDisplayView */
let component = ReasonReact.statelessComponent("HomeNavigationView");

let make = (~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <View style=Style.(style([flex(1.),]))>
      <Grid
        style=Style.(
          style([
            flex(1.),
            backgroundColor(String("transparent")),
          ]))
      > 
        <Col size=1 />
        <Col size=3>
          <TouchableOpacity
            style=Style.(style([flex(1.),]))
            onPress=((_) => controlAction(Control.Model.(ChangeScene(Faq))))
          >
             <Grid
              style=Style.(
                style([
                  flex(1.),
                  flexDirection(Row),
                ])
              )
            >
              <Col />
              <Col size=3>
                <Grid>
                  <Col size=4>
                    <IllumeImage />
                  </Col>
                  <Col size=1>
                    <View style=Style.(style([flex(1.), justifyContent(FlexEnd)]))>
                      <Entypo
                        name="chevron-down"
                        size=16
                        color="black"
                        style=Style.(style([alignSelf(Center),]))
                      />
                    </View>
                  </Col>
                </Grid>
              </Col>
              <Col />
            </Grid>
          </TouchableOpacity>
        </Col>
        <Col size=1 />
      </Grid>
    </View>
  };
