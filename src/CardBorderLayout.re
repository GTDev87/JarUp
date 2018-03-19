open BsReactNative;

let marginLeftCardContent = 5.;

let headerTextStyle = Style.(style([
  margin(Pct(3.)),
  color("gray"),
  textAlign(Left),
  textAlignVertical(Center),
  fontFamily("Arial Rounded MT Bold"),
  flex(1.),
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
          style=headerTextStyle
          numberOfLines=1
          minimumFontScale=0.5
          allowFontScaling=true
          adjustsFontSizeToFit=true
        />
      </Row>
  };

let getFooterColor = (footerColor) =>
  switch(footerColor) {
  | None => "gray"
  | Some(color) => color
  };

let make = (~backColor, ~footerText, ~headerText=?, ~footerColor=?, children) => {
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
            style=Style.(style([
              margin(Pct(3.)),
              color(getFooterColor(footerColor)),
              textAlign(Left),
              textAlignVertical(Center),
              flex(1.),
              fontFamily("Arial Rounded MT Bold"),
              borderWidth(1.),
            ]))
            numberOfLines=1
            minimumFontScale=0.5
            allowFontScaling=true
            adjustsFontSizeToFit=true
          />
        </Row>
      </Grid>
    </Card2>
};