open Core_kernel

let () =
  Random.self_init();
  let n = 1 + Random.int 5 in
  let m = 1 + Random.int 4 in
  printf "%d %d\n" n m;
  for i = 1 to m do
    let l = 1 + Random.int (n - 1) in
    let r = l + Random.int (n - l + 1) in
    printf "%d %d\n" l r
  done
