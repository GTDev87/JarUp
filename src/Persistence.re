open BsReactNative;
open Control.Model;

let storageKey = "Illume.state";


let jsonifyNote = ({id, text, color, time}) =>
  Js.Dict.fromList([
    ("id", id |> float_of_int |> Js.Json.number),
    ("text",  Js.Json.string(text)),
    ("color", (color |> Colors.colorToString |> Js.Json.string)),
    ("time", time |> float_of_int |> Js.Json.number),
  ]);

let decodeNote = (json) => {
  Json.Decode.{
    id: json |> field("id", int),
    text: json |> field("text", string),
    color: json |> field("color", string) |> Colors.stringToColor,
    time: json |> field("time", int),
  }
};

let persist = (notes) => {
  /* convert state to JSON */
  let stateAsJson =
    notes
    |> Array.of_list
    |> Array.map (jsonifyNote)
    |> Js.Json.objectArray
    |> Js.Json.stringify;

  /* set it in RN's AsyncStorage */
  AsyncStorage.setItem(
    storageKey, stateAsJson,
    ~callback=
      (e) =>
        switch e {
        | None => ()
        | Some(err) => Js.log(err)
        },
    ()
  )
  |> ignore
};

let rehydrate = (self) => {
  Js.Promise.(
    /* begin call to AsyncStorage */
    AsyncStorage.getItem(storageKey, ())
    |> then_(
         (json) =>
           (
             switch json {
             | None => ()
             | Some(s) =>
                /* parse JSON, decode it into a ReasonML Record, and reset the state */
                let parsedJson = Js.Json.parseExn(s);
                let hydratedNotes = parsedJson |> Json.Decode.list(decodeNote);
                self.ReasonReact.reduce(() => Rehydrate(hydratedNotes), ());
                ()
             }
           )
           |> resolve
       )
    |> ignore
  );
  ReasonReact.NoUpdate
};
