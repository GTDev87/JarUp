open BsReactNative;

let marginLeftCardContent = 5.;

let headerFooterTextStyle = Style.(style([
  margin(Pct(3.)),
  color("gray"),
  textAlign(Center),
  textAlignVertical(Center),
  fontFamily("Arial Rounded MT Bold"),
]));

let borderColorDepth = 3.;

let childrenContentStyle = Style.(style([
  marginHorizontal(Pct(marginLeftCardContent)),
]));

let component = ReasonReact.statelessComponent("CardBorderLayout");

let contentRows = (headerText) =>
  switch(headerText) {
  | None => 11
  | Some(_) => 10
  };

let ifNullEmptyString = (headerText) =>
  switch(headerText) {
  | None => ""
  | Some(text) => text
  };

let generateHeader = (headerText) =>
  switch(headerText) {
  | None => <View />
  | Some(_) =>
      <Row size=1>
        <Text
          value=(ifNullEmptyString(headerText))
          style=headerFooterTextStyle
          numberOfLines=1
          minimumFontScale=0.5
          allowFontScaling=true
        />
      </Row>
  };

let make = (~backColor, ~footerText, ~headerText=?, children) => {
  ...component, 
  render: (_self) =>
    <Card2
      style=Style.(style([
        backgroundColor(backColor),
        borderColor("black"),
        borderRadius(borderColorDepth),
        flex(1.),
      ]))
    >
      <Grid
        style=Style.(style([
          borderColor("black"),
          borderWidth(borderColorDepth),
          borderRadius(borderColorDepth),
        ]))
      >
        { generateHeader(headerText) }
        <Row size=contentRows(headerText) style=childrenContentStyle>
          ...children
        </Row>
        <Row size=1>
          <Text
            value=footerText
            style=headerFooterTextStyle
            numberOfLines=1
            minimumFontScale=0.5
            allowFontScaling=true
          />
        </Row>
      </Grid>
    </Card2>
};