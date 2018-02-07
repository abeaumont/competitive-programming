open Core_kernel

let () =
  Random.self_init();
  let t = 1 in printf "%d\n" t;
  let l = 2 + (Random.int 1000000) in
  let d = 1 + (Random.int (l - 1)) in
  let n = 1 + (Random.int 10) in
  printf "%d %d %d\n" l d n
