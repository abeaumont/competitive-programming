#! /usr/bin/factor-vm -script
USING: io kernel locals math math.functions math.order math.parser prettyprint sequences ;
IN: part2

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

: find-index ( ts xs -- n/f )
    2dup [ length ] bi@ - neg 1 - subseq-start-from ;

:: recipe-loop ( ts xs i j -- m )
    xs i j [
        recipe ts xs find-index not
    ] loop 3drop ts xs find-index ;

: main ( -- )
    readln string>digits BV{ 3 7 } 0 1 recipe-loop . ;

MAIN: main
