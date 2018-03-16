open BsReactNative;

let marginLeftCardContent = 5.;

let headerFooterTextStyle = Style.(style([
  marginHorizontal(Pct(marginLeftCardContent)),
  marginVertical(Pct(5.)),
  color("gray"),
  alignItems(Center),
  fontFamily("Arial Rounded MT Bold"),
]));

let childrenContentStyle = Style.(style([
  marginHorizontal(Pct(marginLeftCardContent)),
]));

let component = ReasonReact.statelessComponent("CardBorderLayout");

let make = (~backColor, ~footerText, ~headerText, children) => {
  ...component, 
  render: (_self) =>
    <Card2
      style=Style.(style([
        backgroundColor(backColor),
        flex(1.),
      ]))
    >
      <Grid>
        <Row size=1 >
          <Text
            value=headerText
            style=headerFooterTextStyle
          />
        </Row>
        <Row size=10 style=childrenContentStyle>
          ...children
        </Row>
        <Row size=1>
          <Text style=headerFooterTextStyle value=footerText />
        </Row>
      </Grid>
    </Card2>
};