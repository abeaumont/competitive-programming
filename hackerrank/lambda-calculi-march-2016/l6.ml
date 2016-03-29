open Core.Std

let find_strongest a merges i =
  let f top x =
    match Heap.top a.(x) with
      None -> top
    | Some(top') -> max top top' in
  List.fold_left merges.(i) ~f ~init:Int.min_value
and strongest_died a merges i =
  let rec loop index value = function
    | [] -> Heap.pop_exn a.(index)
    | x::xs -> match Heap.top a.(x) with
        None -> loop index value xs
      | Some(v) ->
        if v > value
        then loop x v xs
        else loop index value xs in
  loop Int.min_value 0 merges.(i)
and recruit a i c = Heap.add a.(i) c
and merge merges i j =
  merges.(i) <- List.append merges.(i) merges.(j);;

let () =
  let (n, q) = Scanf.sscanf (read_line ()) "%d %d" (fun n q -> (n, q)) in
  let a = Array.init n (fun _ -> (Heap.create ~cmp:(Fn.flip compare) ())) in
  let merges = Array.init n (fun i -> [i]) in
  for _ = 1 to q do
    let line = read_line () in
    match line.[0] with
      '1' ->
      let (_, i) = Scanf.sscanf line "%d %d" (fun k i -> (k, i)) in
      print_endline (string_of_int (find_strongest a merges (i - 1)))
    | '2' ->
      let (_, i) = Scanf.sscanf line "%d %d" (fun k i -> (k, i)) in
      ignore (strongest_died a merges (i - 1))
    | '3' ->
      let (_, i, c) = Scanf.sscanf line "%d %d %d" (fun k i c -> (k, i, c)) in
      recruit a (i - 1) c
    | '4' ->
      let (_, i, j) = Scanf.sscanf line "%d %d %d" (fun k i j -> (k, i, j)) in
      merge merges (i - 1) (j - 1)
  done
