open Core_kernel

let () =
  Random.self_init();
  let t = 1
  and n = 1 + Random.int 20
  and k = 1 + Random.int 20 in
  printf "%d\n" t;
  printf "%d %d\n" n k;
  List.init n (fun _ -> (-50) + (Random.int 100) |> Int.to_string)
  |> String.concat ~sep:" " |> print_endline
