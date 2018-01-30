open Core_kernel

let () =
  Random.self_init();
  let n = 1 + Random.int 10
  and k = Random.int 51 in
  printf "%d %d\n" n k;
  List.init n (fun _ -> Random.int 51 |> Int.to_string)
  |> String.concat ~sep:" " |> print_endline
