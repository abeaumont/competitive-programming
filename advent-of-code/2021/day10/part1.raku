#!/bin/raku
my $s = 0;
constant %m = ')', '(', ']', '[', '}', '{', '>', '<';
constant %t = ')', 3, ']', 57, '}', 1197, '>', 25137;
loop (my $a = get; $a; $a = get)  {
    my @s = [];
    for split('', $a, :skip-empty) -> $c {
        given $c {
            when '('|'['|'{'|'<' { @s.push($c) }
            when %m<<$c>> ne @s.pop() { $s += %t<<$c>>; last }
        };
    };
}
say $s;
