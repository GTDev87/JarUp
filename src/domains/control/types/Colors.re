let redPrimaryString = "rgb(247, 159, 72)";
let orangePrimaryString = "rgb(246, 233, 104)";
let yellowPrimaryString = "rgb(255, 255, 255)";
let blackPrimaryColor = "rgb(0, 0, 0)";

/*
colors in the jar are not actual colors
primary 1, 2, 3
*/

let colorToActualColor(color) =
  switch(color) {
  | Control.Model.Red => redPrimaryString
  | Control.Model.Orange => orangePrimaryString
  | Control.Model.Yellow => yellowPrimaryString
};

let colorToContrastColor(color) =
  switch(color) {
  | Control.Model.Red => orangePrimaryString
  | Control.Model.Orange => blackPrimaryColor
  | Control.Model.Yellow => redPrimaryString
};

let colorToString(color) =
  switch(color) {
  | Control.Model.Red => "red"
  | Control.Model.Orange => "orange"
  | Control.Model.Yellow => "yellow"
};

let stringToColor(colorStr) =
  switch(colorStr) {
  | "red" => Control.Model.Red
  | "orange" => Control.Model.Orange
  | "yellow" => Control.Model.Yellow
  | _ => Control.Model.Red
  };

