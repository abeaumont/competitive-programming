(* https://www.hackerrank.com/challenges/simple-array-sum *)
let () =
  read_int () |> ignore;
  read_line ()
  |> Str.split (Str.regexp " ")
  |> List.map int_of_string
  |> List.fold_left (+) 0
  |> Printf.printf "%d\n"
