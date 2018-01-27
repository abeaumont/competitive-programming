open Core_kernel

let () =
  Random.self_init();
  let h = 2 + Random.int 99999 in
  let w = 2 + Random.int 99999 in
  let a = 1 + Random.int (h - 1) in
  let b = 1 + Random.int (w - 1) in
  printf "%d %d %d %d\n" h w a b
