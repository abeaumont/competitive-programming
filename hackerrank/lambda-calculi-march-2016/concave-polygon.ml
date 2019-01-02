(* https://www.hackerrank.com/contests/lambda-calculi-march-2016/challenges/lambda-march-concave-polygon *)
(* Graham Convex Hull algorithm from http://www.cs.cmu.edu/afs/cs/academic/class/15451-s15/LectureNotes/lecture15/geometry.pdf *)
let (--) (x1,y1) (x2,y2) = (x1-x2, y1-y2)
let (++) (x1,y1) (x2,y2) = (x1+x2, y1+y2)
let cross (x1,y1) (x2,y2) = (x1*y2) - (y1*x2)
let dot (x1,y1) (x2,y2) = (x1*x2) + (y1*y2)
let sign x = compare x 0

let line_side_test p1 p2 p3 = sign (cross (p2--p1) (p3--p1))

let len (x,y) =
  let sq a = a*.a in
  let (x,y) = (float x, float y) in
  sqrt ((sq x) +. (sq y))

let diff = ref 0
let graham_convex_hull points =
  let inf = max_int in
  let base = List.fold_left min (inf,inf) points in

  let points = List.sort (
      fun pi pj ->
        if pi=pj then 0
        else if pi=base then 1
        else if pj=base then -1
        else line_side_test base pj pi
    ) points in

  let rec scan chain points =
    let (c1,c2,chainx) = match chain with
      | c1::((c2::_) as chainx) -> (c1,c2,chainx)
      | _ -> failwith "chain must have length at least 2"
    in
    match points with [] -> chain
                    | pt::tail ->
                      begin
                      match line_side_test c2 c1 pt with
                      | 1 -> scan (pt::chain) tail
                      | -1 -> scan chainx points
                      | _ ->
                        diff := !diff + 1;
                        if len (pt--c2) > len (c1--c2)
                        then scan (pt::chainx) tail
                        else scan chain tail
                      end
  in

  match points with
  | (p1::((_::(_::_)) as rest)) -> List.tl(scan [p1;base] rest);
  | _ -> points

let read_pair () = Scanf.sscanf (read_line ()) "%d %d" (fun x y -> (x, y))
let read_size () = Scanf.sscanf (read_line ()) "%d" (fun x -> x)

let () =
  let size = read_size () in
  let rec loop = function
      0 -> []
    | i -> read_pair () :: (loop (i - 1))
  in
  let points = loop size in
  let convex_hull = graham_convex_hull points in
  if List.length convex_hull + !diff = size then
    print_endline "NO"
  else
    print_endline "YES";
