(* https://www.hackerrank.com/challenges/simple-array-sum *)
open Core.Std

let () =
  read_int () |> ignore;
  read_line ()
  |> String.split ~on:' '
  |> List.map ~f:Int.of_string
  |> List.fold_left ~f:(+) ~init:0
  |> Printf.printf "%d\n"
