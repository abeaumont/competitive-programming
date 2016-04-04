(* ocamlfind ocamlc -package batteries -linkpkg lvl6.ml -o lvl6 *) 
open Batteries

exception Found
    
let check_class n q k =
  let line = Str.split (Str.regexp " ") (read_line ()) in
  let size = int_of_string (List.hd line) in
  let more_than_half = int_of_float (ceil (float_of_int size /. 2.0)) in
  let ss = List.tl line in
  let rec check_answers i =
    if q < (i + k)
    then None
    else
      let h = Hashtbl.create size in
      try 
        List.iter (fun s ->
            let key = String.sub s i k in
            let value = Hashtbl.find_default h key 0 in
            if value == more_than_half - 1
            then raise Found
            else Hashtbl.replace h key (value + 1))
          ss ;
        check_answers (i + 1)
      with
        Found -> Some n in
  check_answers 0

let process () =
  Scanf.sscanf (read_line ()) "%d %d %d %d"
    (fun c q a s ->
       (0 -- (c - 1))
       |> Enum.filter_map (fun i -> (check_class i q s))
       |> Enum.map string_of_int
       |> List.of_enum
       |> String.concat " "
       |> print_endline)

let () =
  for i = 1 to int_of_string (String.strip (read_line ())) do
    process ()
  done
