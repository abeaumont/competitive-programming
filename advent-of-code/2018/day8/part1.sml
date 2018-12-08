infix 3 <\
fun x <\ f = fn y => f (x, y)
infixr 3 />
fun f /> y = fn x => f (x, y)
infix 2 |>
fun x |> f = f x

fun read () =
    TextIO.inputLine TextIO.stdIn
    |> valOf
    |> String.tokens (#" " <\ op=)
    |> List.map (fn x => Int.fromString x |> valOf)

fun sum k 0 xs = (k, xs)
  | sum k n [] = raise Domain
  | sum k n (x :: xs) = sum (k + x) (n - 1) xs

fun children k 0 xs = (k, xs)
  | children k n xs =
    let
        val (k, xs) = tree k xs
    in
        children k (n - 1) xs
    end

and tree k [] = (k, [])
  | tree k [x] = raise Domain
  | tree k (c :: m :: tl) =
    let
        val (k, xs) = children k c tl
    in
        sum k m xs
    end

val _ =
    read () |> tree 0 |> #1 |> Int.toString |> (op^ /> "\n") |> print
