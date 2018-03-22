(* https://www.hackerrank.com/challenges/arrays-ds *)
let () =
  read_int () |> ignore;
  read_line ()
  |> Str.split (Str.regexp " ")
  |> List.rev
  |> String.concat " "
  |> print_endline
