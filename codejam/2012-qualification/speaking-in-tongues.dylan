// https://code.google.com/codejam/contest/1460488/dashboard#s=p0
module: speaking-in-tongues

define function line() => (line :: <string>) read-line(*standard-input*) end;
define function number() => (number :: <integer>) string-to-integer(line()) end;

define function do-case(i) => ()
  let t = table('a' => 'y', 'b' => 'h', 'c' => 'e', 'd' => 's', 'e' => 'o',
                'f' => 'c', 'g' => 'v', 'h' => 'x', 'i' => 'd', 'j' => 'u',
                'k' => 'i', 'l' => 'g', 'm' => 'l', 'n' => 'b', 'o' => 'k',
                'p' => 'r', 'q' => 'z', 'r' => 't', 's' => 'n', 't' => 'w',
                'u' => 'j', 'v' => 'p', 'w' => 'f', 'x' => 'm', 'y' => 'a',
                'z' => 'q', ' ' => ' ');
  format-out("Case #%d: %s\n", i, map(method(x) t[x] end, line()))
end function do-case;

do(curry(do-case), range(from: 1, to: number()));