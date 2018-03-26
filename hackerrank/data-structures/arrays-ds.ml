(* https://www.hackerrank.com/challenges/arrays-ds *)
open Core.Std

let () =
  read_int () |> ignore;
  read_line ()
  |> String.split ~on:' '
  |> List.rev
  |> String.concat ~sep:" "
  |> print_endline
