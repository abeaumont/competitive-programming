(* https://www.hackerrank.com/challenges/arrays-ds *)
open Core_kernel

let () =
  read_int () |> ignore;
  read_line ()
  |> String.split ~on:' '
  |> List.rev
  |> String.concat
  |> print_endline
