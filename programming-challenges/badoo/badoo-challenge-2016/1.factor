USING: kernel io prettyprint formatting math math.parser math.order sorting splitting sequences deques dlists vectors arrays combinators locals syntax accessors ;
IN: 1

TUPLE: node index distance ;

: <node> ( index distance -- node )
    node boa ;

TUPLE: graph to-visit visited edges ;

: <graph> ( to-visit visited edges -- graph )
    graph boa ;

: read-number ( -- n )
    readln string>number ;

: read-contacts ( i -- seq )
    drop readln " " split [ string>number 1 - ] map ;

: read-case ( -- seq )
    read-number iota [ read-contacts ] map ;

: max-distance ( graph -- max )
    visited>> [ distance>> ] map supremum ;

: all-found? ( graph -- ? )
    [ visited>> ] [ edges>> ] bi [ length ] bi@ = ;

:: loop ( graph -- max )
    {
        { [ graph all-found? ] [ graph max-distance ] }
        { [ graph to-visit>> deque-empty? ] [ -1 ] }
        { [ graph [ to-visit>> peek-back index>> ] [ visited>> [ index>> ] map ] bi member? ]
          [ graph to-visit>> pop-back drop graph loop ] }
        [ graph [ to-visit>> pop-back [ distance>> ] [ index>> ] bi ] [ edges>> ] bi
          [ [ swap <node> graph visited>> push ] 2keep ] dip nth
          [ swap 1 + <node> ] with map graph to-visit>> push-all-front
          graph loop ]
    } cond ;
    
: distance ( i seq -- max-distance )
    [ nth [ 1 <node> ] map dlist new [ push-all-front ] keep ] 2keep
    [ 0 <node> 1vector ] dip
    <graph> loop ;

: eval-case ( seq -- newseq )
    [ length iota ] keep [ distance ] curry map
    [ 2array ] map-index
    [ first 0 >= ] filter dup empty?
    [
        drop { 0 }
    ] [
        [ <=> ] sort
        [ first first ] keep [ first = ] with filter
        [ second 1 + ] map
    ] if ;

: print-case ( seq -- )
    [  number>string ] map " " join print ;

: process ( -- )
    read-case eval-case print-case ;

: main ( -- )
    read-number [ process ] times ;

main
