(* https://www.hackerrank.com/challenges/security-function-ii *)
let () =
  let double x = x * x in read_int () |> double |> Printf.printf "%d\n"
