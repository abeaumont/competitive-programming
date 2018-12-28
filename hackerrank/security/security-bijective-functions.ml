(* https://www.hackerrank.com/challenges/security-bijective-functions *)
open Core

let () =
  let _ = In_channel.(input_line_exn stdin) in
  let dup =
    In_channel.(input_line_exn stdin)
    |> String.split ~on:' '
    |> List.contains_dup ~compare in
  print_endline (if dup then "NO" else "YES")
