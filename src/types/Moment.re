module Moment = {
  type t;
  [@bs.send.pipe : t] external format : string => string = "";
  [@bs.send.pipe : t] external valueOf : unit => int = "";
};

/*Moment.(moment(date) |> Moment.format("dddd, MMMM Do"))*/

[@bs.module] external _moment : unit => Moment.t = "moment";
[@bs.module] external _moment2 : float => Moment.t = "moment";

let moment = (value) =>
  switch(value) {
    | None => _moment()
    | Some(value) => _moment2(value)
  };
