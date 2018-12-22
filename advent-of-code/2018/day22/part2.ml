open Core

let () =
  let (x, y, d) = Scanf.scanf "depth: %i\ntarget: %i,%i\n" (fun d x y -> (x, y, d)) in
  let (m, n) = (1000, 1000) in
  let a = Array.make_matrix ~dimx:(m + 1) ~dimy:(n + 1) 0 in
  for i = 0 to m do a.(i).(0) <- (i * 16807 + d) mod 20183 done;
  for i = 0 to n do a.(0).(i) <- (i * 48271 + d) mod 20183 done;
  for i = 1 to m do
    for j = 1 to n do
      if i = x && j = y then a.(i).(j) <- 0
      else a.(i).(j) <- (a.(i - 1).(j) * a.(i).(j - 1) + d) mod 20183
    done
  done;
  for i = 0 to m do
    for j = 0 to n do
      a.(i).(j) <- a.(i).(j) mod 3
    done
  done;
  let f _ =
    let f _ = Array.create ~len:4 (n*m*7) in
    Array.init (n + 1) ~f in
  let s = Array.init (m + 1) ~f in
  let q = Heap.create ~cmp:compare () in
  let rec loop () =
    let (d, i, j, k) = Heap.pop_exn q in
    if i = x && j = y && k = 1 then d
    else
      let t = 3 - a.(i).(j) - k in
      if s.(i).(j).(t) > d + 7 then
        (s.(i).(j).(t) <- d + 7;
         Heap.add q (d + 7, i, j, t));
      let f (i, j) =
        if i >= 0 && j >= 0 && a.(i).(j) <> k && s.(i).(j).(k) > d + 1 then
          (s.(i).(j).(k) <- d + 1;
           Heap.add q (d + 1, i, j, k)) in
      List.iter ~f [(i - 1, j); (i + 1, j); (i, j - 1); (i, j + 1)];
      loop() in
  Heap.add q (0, 0, 0, 1);
  loop () |> Printf.printf "%d\n"
