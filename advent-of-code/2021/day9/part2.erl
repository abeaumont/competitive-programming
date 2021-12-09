#!/usr/bin/env escript
-import(array, [from_list/1, new/1, new/2, to_list/1]).
-import(io, [format/2, get_line/1]).
-import(lists, [filter/2, flatten/1, map/2, min/1, reverse/1, seq/2, sort/1]).
-import(string, [chomp/1, to_graphemes/1]).

get(A, I, J) -> array:get(J, array:get(I, A)).
set(B, I, J, V) -> array:set(I, array:set(J, V, array:get(I, B)), B).

parse(L) -> from_list(map(fun(X) -> X-48 end, to_graphemes(L))).

read() -> read(get_line(''), []).
read(eof, Ls) -> from_list(reverse(Ls));
read(L, Ls) -> read(get_line(''), [parse(chomp(L))|Ls]).

is_coord(A, B) ->
    fun({Y, X}) ->
            Y >= 0
                andalso Y < array:size(A)
                andalso X >= 0
                andalso X < array:size(array:get(Y, A))
                andalso get(A, Y, X) /= 9
                andalso get(B, Y, X) == 0
    end.

coords(A, B, I, J) ->
    filter(is_coord(A, B), [{I, J+1}, {I, J-1}, {I+1, J}, {I-1, J}]).

cc(_, B, _, []) -> B;
cc(A, B, C, [{I, J}|T]) ->
    X = get(A, I, J),
    Y = get(B, I, J),
    if
        X == 9 andalso Y == 0-> cc(A, set(B, I, J, C), C, T);
        Y == 0 -> B_ = set(B, I, J, C), cc(A, B_, C, T ++ coords(A, B_, I, J));
        true -> cc(A, B, C, T)
    end.

loop(A, B, C, I, J) ->
    S = array:size(A),
    if
        I == S -> B;
        true ->
            SI = array:size(array:get(I, A)),
            if
                J == SI -> loop(A, B, C, I+1, 0);
                true ->
                    X = get(B, I, J),
                    if
                        X == 0 -> loop(A, cc(A, B, C, [{I, J}]), C+1, I, J+1);
                        true -> loop(A, B, C, I, J+1)
                    end
            end
    end.

count(A) ->
    [H|T] = sort(flatten([to_list(X) || X <- to_list(A)])),
    [X|[Y|[Z|_]]] = reverse(sort(count(T, H, 1, []))),
    X * Y * Z.

count([], _, C, Acc) -> [C|Acc];
count([H|T], X, C, Acc) when H == X -> count(T, X, C+1, Acc);
count([H|T], _, C, Acc) -> count(T, H, 1, [C|Acc]).

main([]) ->
    A = read(),
    B = from_list([new(array:size(array:get(I-1, A)), {default,0})
                   || I <- seq(1, array:size(A))]),
    format("~w~n", [count(loop(A, B, 1, 0, 0))]).
