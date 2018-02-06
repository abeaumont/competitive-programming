open Core_kernel

let () =
  Random.self_init();
  let t = 1 in printf "%d\n" t;
  for j = 0 to t do
    let n = 200000 in
    printf "%d\n" n;
    for i = 1 to n do
      let a = 1 + Random.int (n - 1) in
      let b = a + Random.int (n - a + 1) in
      printf "%d %d\n" a b;
    done;
    let q = 100000 in
    printf "%d\n" q;
    for i = 1 to q do
      let m = 20 in
      printf "%d" m;
      for k = 1 to m do
        printf " %d" (1 + Random.int n)
      done;
      printf "\n"
    done
  done
