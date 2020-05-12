(* https://codingcompetitions.withgoogle.com/codejam/round/0000000000201bee/0000000000201d17 *)
let reverse s =
  Bytes.init (Bytes.length s) (fun i -> match s.[i] with '-' -> '+' | _ -> '-')
  
let process () =
  let rec loop s count =
    try
      let pos = Bytes.rindex s '-' in
      let s' = Bytes.sub s 0 (pos + 1) in
      let l = Bytes.length s' in
      if l >= 2 && Bytes.sub s (l - 2) 2 = "+-"
      then let s'' = (reverse s') in s''.[l - 1] <- '-'; loop s'' (count + 1)
      else loop (reverse s') (count + 1)
    with _ -> count in
  loop (read_line ()) 0

let () =
  for i = 1 to read_int () do
    Printf.printf "Case #%d: %d\n" i (process ())
  done
