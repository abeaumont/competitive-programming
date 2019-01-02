(* https://www.hackerrank.com/contests/lambda-calculi-march-2016/challenges/fighting-armies *)
(* Pairing heap with merge support *)
type heap = Empty | Node of int * heap list
exception EmptyHeap

let merge heap1 heap2 = match (heap1, heap2) with
    (Empty, x) | (x, Empty) -> x
  | (Node(i1, s1), Node(i2, s2)) ->
    if i1 > i2
    then Node(i1, heap2 :: s1)
    else Node(i2, heap1 :: s2)

let top = function
    Empty -> raise EmptyHeap
  | Node(i, _) -> i

let push heap value =
  merge (Node(value, [])) heap

let pop = function
    Empty -> raise EmptyHeap
  | Node(i, s) ->
    let rec merge_pairs = function
        [] -> Empty
      | [x] -> x
      | x::y::xs -> merge (merge x y) (merge_pairs xs) in
    merge_pairs s

let find_strongest a i = top a.(i)
and strongest_died a i = a.(i) <- pop a.(i)
and recruit a i c = a.(i) <- push a.(i) c
and merge_heaps a i j = a.(i) <- merge a.(i) a.(j)

let () =
  let (n, q) = Scanf.sscanf (read_line ()) "%d %d" (fun n q -> (n, q)) in
  let a = Array.init n (fun _ -> Empty) in
  for _ = 1 to q do
    let line = read_line () in
    match line.[0] with
      '1' ->
      let (_, i) = Scanf.sscanf line "%d %d" (fun k i -> (k, i)) in
      print_endline (string_of_int (find_strongest a (i - 1)))
    | '2' ->
      let (_, i) = Scanf.sscanf line "%d %d" (fun k i -> (k, i)) in
      ignore (strongest_died a (i - 1))
    | '3' ->
      let (_, i, c) = Scanf.sscanf line "%d %d %d" (fun k i c -> (k, i, c)) in
      ignore (recruit a (i - 1) c)
    | _ ->
      let (_, i, j) = Scanf.sscanf line "%d %d %d" (fun k i j -> (k, i, j)) in
      merge_heaps a (i - 1) (j - 1)
  done
