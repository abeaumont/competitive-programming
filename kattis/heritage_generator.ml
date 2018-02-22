open Core_kernel

let random_char () = Char.to_int 'a' + Random.int 26 |> Char.of_int_exn
let random_string len = String.init len (fun _ -> random_char ())
let random_str () = Random.int 32 |> (+) 1 |> random_string

let () =
  Random.self_init();
  let n = Random.int 100000 in
  let s = random_str () in
  printf "%d %s\n" n s;
  for i = 1 to n do
    let s = random_str ()
    and n = Random.int 1000 in
    printf "%s %d\n" s n
  done
