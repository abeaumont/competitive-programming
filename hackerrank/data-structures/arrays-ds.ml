(* https://www.hackerrank.com/challenges/arrays-ds *)
open Core_kernel

let () =
  In_channel.input_line_exn In_channel.stdin |> ignore;
  In_channel.input_line_exn In_channel.stdin
  |> String.split ~on:' '
  |> List.rev
  |> String.concat ~sep:" "
  |> print_endline
