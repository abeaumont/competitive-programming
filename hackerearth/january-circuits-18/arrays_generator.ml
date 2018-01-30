open Core_kernel

let () =
  Random.self_init();
  let n = 1 + Random.int 10
  and k = 1 + Random.int 100 in
  printf "%d %d\n" n k;
  for i = 1 to n do
    List.init 3 (fun _ -> Random.int k |> Int.to_string)
    |> String.concat ~sep:" " |> print_endline
  done
