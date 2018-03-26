(* https://www.hackerrank.com/challenges/simple-array-sum *)
open Core_kernel

let () =
  read_int () |> ignore;
  read_line ()
  |> String.split ~on:' '
  |> List.map Int.of_string
  |> List.fold_left (+) 0
  |> Printf.printf "%d\n"
