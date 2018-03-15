let redPrimaryString = "rgb(247, 159, 72)";
let orangePrimaryString = "rgb(246, 233, 104)";
let yellowPrimaryString = "rgb(255, 255, 255)";

/*
colors in the jar are not actual colors
primary 1, 2, 3
*/

let colorToActualColor(color) =
  switch(color) {
  | Control.Red => redPrimaryString
  | Control.Orange => orangePrimaryString
  | Control.Yellow => yellowPrimaryString
};

let colorToString(color) =
  switch(color) {
  | Control.Red => "red"
  | Control.Orange => "orange"
  | Control.Yellow => "yellow"
};

let stringToColor(colorStr) =
  switch(colorStr) {
  | "red" => Control.Red
  | "orange" => Control.Orange
  | "yellow" => Control.Yellow
  | _ => Control.Red
  };

