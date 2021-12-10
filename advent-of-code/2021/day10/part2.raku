#!/bin/raku
constant %m = ')', '(', ']', '[', '}', '{', '>', '<';
constant %t = '(', 1, '[', 2, '{', 3, '<', 4;
my @scores = [];
loop (my $a = get; $a; $a = get)  {
    my @s = [];
    my $s = 0;
    for split('', $a, :skip-empty) -> $c {
        given $c {
            when '('|'['|'{'|'<' { @s.push($c) }
            when %m<<$c>> ne @s.pop() { @s = []; last }
        };
    };
    for @s.reverse -> $c { $s = $s * 5 + %t<<$c>> };
    @scores.push($s) if $s > 0;
}
say @scores.sort[@scores.elems div 2];
