module: b
url: https://code.google.com/codejam/contest/1460488/dashboard#s=p1

define function line() => (line :: <string>) read-line(*standard-input*) end;
define function number() => (number :: <integer>) string-to-integer(line()) end;

define function do-case(i) => ()
  let fields = map(string-to-integer, split(line(), " "));
  let n = fields[0];
  let s = fields[1];
  let p = fields[2];
  let t = copy-sequence(fields, start: 3);
  let total = p * 3;
  let set-a = choose(method(x) (total - 4 >= 0) & (x >= total - 4) end, t);
  let set-b = choose(method(x) x >= total - 2 end, t);
  let surprising = size(set-a) - size(set-b);
  let j = max(surprising, 0);
  let k = min(j, s);
  format-out("Case #%d: %d\n", i, size(set-b) + k)
end function do-case;

do(curry(do-case), range(from: 1, to: number()));
