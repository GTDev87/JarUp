open Belt;

let selectRandomFromList = (list, default) => {
  let randomMaybe =
    list
    |> List.length
    |> Random.int
    |> List.get(list, _);

  switch(randomMaybe) {
  | None => default
  | Some(element) => element
  };
}