open Core_kernel

let () =
  Random.self_init();
  let n = 1 + Random.int 100 in
  printf "%d\n" n;
  List.init n (fun _ -> Random.int 100 |> Int.to_string)
  |> String.concat ~sep:" " |> print_endline
