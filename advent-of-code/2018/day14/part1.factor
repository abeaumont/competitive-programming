#! /usr/bin/factor-vm -script
USING: io kernel locals math math.functions math.parser sequences ;
IN: part1

:: push-recipe ( xs i j -- )
    i j [ xs nth ] bi@ + [
        10 / floor dup zero? [ drop ] [ xs push ] if
    ] [
        10 mod xs push
    ] bi ;

:: recipe ( xs i j -- ys k l )
    xs i j [
        [ xs nth ] [ 1 + ] bi + xs length mod
    ] bi@ [ push-recipe ] 3keep ;

:: recipe-loop ( n xs i j -- ys )
    xs i j [
        recipe xs length n <
    ] loop 2drop ;

: main ( -- )
    readln string>number dup 10 + dup
    V{ 3 7 } 0 1
    recipe-loop subseq [ number>string ] map "" join print ;

MAIN: main
