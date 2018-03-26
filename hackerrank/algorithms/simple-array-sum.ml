(* https://www.hackerrank.com/challenges/simple-array-sum *)
open Core_kernel

let () =
  In_channel.input_line_exn In_channel.stdin |> ignore;
  In_channel.input_line_exn In_channel.stdin
  |> String.split ~on:' '
  |> List.map ~f:Int.of_string
  |> List.fold_left ~f:(+) ~init:0
  |> Printf.printf "%d\n"
