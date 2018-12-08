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

fun sum k 0 xs cs = (k, xs)
  | sum k n [] cs = raise Domain
  | sum k n (x :: xs) cs =
    let
        val k' =
            if List.null cs then x
            else if x <= List.length cs then List.nth(cs, x - 1)
            else 0
    in
        sum (k + k') (n - 1) xs cs
    end

fun children 0 xs cs = (xs, List.rev cs)
  | children n xs cs =
    let
        val (k, xs) = tree xs
    in
        children (n - 1) xs (k :: cs)
    end

and tree [] = raise Domain
  | tree [x] = raise Domain
  | tree (c :: m :: tl) =
    let
        val (xs, cs) = children c tl []
    in
        sum 0 m xs cs
    end

val _ =
    read () |> tree |> #1 |> Int.toString |> (op^ /> "\n") |> print
