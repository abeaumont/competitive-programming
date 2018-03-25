(* https://www.hackerrank.com/challenges/security-bijective-functions *)
open Core.Std

let () =
  let _ = read_int () in
  let dup =
    read_line ()
    |> String.split ~on:' '
    |> List.contains_dup in
  print_endline (if dup then "NO" else "YES")
