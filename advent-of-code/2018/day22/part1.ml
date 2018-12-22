open Core

let () =
  let (x, y, d) = Scanf.scanf "depth: %i\ntarget: %i,%i\n" (fun d x y -> (x, y, d)) in
  let a = Array.make_matrix ~dimx:(x + 1) ~dimy:(y + 1) 0 in
  for i = 0 to x do a.(i).(0) <- (i * 16807 + d) mod 20183 done;
  for i = 0 to y do a.(0).(i) <- (i * 48271 + d) mod 20183 done;
  for i = 1 to x do
    for j = 1 to y do
      a.(i).(j) <- (a.(i - 1).(j) * a.(i).(j - 1) + d) mod 20183
    done
  done;
  let f r =
    let f e = (e + d) mod 3 |> (+) in
    r |> Array.fold_right ~f ~init:0 |> (+) in
  a |> Array.fold_right ~init:0 ~f |> Printf.printf "%d\n"
