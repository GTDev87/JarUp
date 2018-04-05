open BsReactNative;


let windowWidth = Dimensions.get(`window)##width;
let distanceFromWindowEdge = 30;
let faqWidth = float_of_int(windowWidth - distanceFromWindowEdge * 2);
let faqTextPart = "illume stores your happy moments and reminds you of them when you are feeling down. By pressing the pen tool a note box will appear. Write down a happy moment and then save it. It can be as simple as a kind gesture from a stranger to a big milestone that fills you with a sense of satisfaction. illume stores your notes as memories in the jar for safe keeping. To view your stored memories press on the jar and a random memory will pop up. You can view several memories by pressing the jar several times. You can also erase a memory by holding down the card and then pressing on the delete option.";

let component = ReasonReact.statelessComponent("FaqModal");

let make = (~controlAction, _children) => {
  ...component,
  render: (_self) =>
    <TouchableOpacity
      style=Style.(style([
        flex(1.),
      ]))
      onPress=(() => controlAction(Control.Model.(ChangeScene(Home))))
    >
      <CardBorderLayout
        backColor="white"
        footerText="Goodvibes everyday"
        footerColor="black"
      >
        <Grid>
          <Row size=2 />
          <Row size=6>
            <Text
              value=faqTextPart
              style=Style.(
                style([
                  fontWeight(`_500),
                  color(String("black")),
                  fontSize(Float(20.)),
                  textAlign(Left),
                  textAlignVertical(Top),
                ])
              )
              adjustsFontSizeToFit=true
            />
          </Row>
          <Row size=1 />
        </Grid>
      </CardBorderLayout>
    </TouchableOpacity>
};
