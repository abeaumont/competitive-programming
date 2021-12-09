#!/usr/bin/env escript
-import(array, [from_list/1]).
-import(io, [format/2, get_line/1]).
-import(lists, [filter/2, map/2, min/1, reverse/1]).
-import(string, [chomp/1, to_graphemes/1]).

get(A, I, J) -> array:get(J, array:get(I, A)).

parse(L) -> from_list(map(fun(C) -> C-48 end, to_graphemes(L))).

read() -> read(get_line(''), []).
read(eof, Ls) -> from_list(reverse(Ls));
read(L, Ls) -> read(get_line(''), [parse(chomp(L))|Ls]).

is_coord(A) ->
    fun({Y, X}) ->
            Y >= 0
                andalso Y < array:size(A)
                andalso X >= 0
                andalso X < array:size(array:get(Y, A))
    end.

coords(A, I, J) ->
    filter(is_coord(A), [{I, J+1}, {I, J-1}, {I+1, J}, {I-1, J}]).

loop(A, I, J) ->
    S = array:size(A),
    if
        I == S -> 0;
        true ->
            SI = array:size(array:get(I, A)),
            if
                J == SI -> loop(A, I+1, 0);
                true ->
                    F = fun({Y, X}) -> get(A, Y, X) end,
                    M = min(map(F, coords(A, I, J))),
                    X = get(A, I, J),
                    if
                        X < M -> X+1 + loop(A, I, J+1);
                        true -> loop(A, I, J+1)
                    end
            end
    end.

main([]) ->
    A = read(),
    format("~B~n", [loop(A, 0, 0)]).
