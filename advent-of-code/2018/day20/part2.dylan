module: part2

define constant $n = 251;

let m = make(<vector>, size: $n);
for (i from 0 below $n)
  m[i] := make(<vector>, size: $n, fill: '#')
end;
for (i from 1 below $n - 1 by 2)
  for (j from 1 below $n by 2)
    m[i][j] := '.'
  end
end;

let r = read-line(*standard-input*);

define function f(i, q)
  let pq = q.shallow-copy;
  let s = make(<set>);
  local method move(q, i, j)
          let t = make(<set>);
          for (p in q)
            let (y, x) = values(p.head, p.tail);
            m[y + i][x + j] := ' ';
            add!(t, pair(y + i * 2, x + j * 2))
          end;
          t
        end;
  local method loop(k)
          if (k >= r.size - 1 | r[k] = ')')
            values(k, s)
          else
            select (r[k])
              '(' =>
                let (nk, nq) = f(k + 1, q);
                k := nk;
                q := nq;
              '|' =>
                for (e in q) add!(s, e) end;
                q := pq.shallow-copy;
              'N' => q := move(q, -1, 0);
              'S' => q := move(q, 1, 0);
              'W' => q := move(q, 0, -1);
              'E' => q := move(q, 0, 1);
            end;
            loop(k + 1)
          end;
        end;
  loop(i)
end;


let p = make(<set>);
let (y, x) = values(floor/($n, 2), floor/($n, 2));
f(1, add!(p, pair(y, x)));

let v = make(<vector>, size: $n);
for (i from 0 below $n)
  v[i] := make(<vector>, size: $n, fill: #f);
end;
let q = make(<deque>, size: 1, fill: vector(y, x, 0));
let c = 0;
until (q.empty?)
  let e = pop(q);
  let (y, x, d) = values(e[0], e[1], e[2]);
  v[y][x] := d;
  when (d >= 1000) c := c + 1 end;
  when (m[y - 1][x] = ' ' & ~v[y - 2][x]) push-last(q, vector(y - 2, x, d + 1)) end;
  when (m[y + 1][x] = ' ' & ~v[y + 2][x]) push-last(q, vector(y + 2, x, d + 1)) end;
  when (m[y][x - 1] = ' ' & ~v[y][x - 2]) push-last(q, vector(y, x - 2, d + 1)) end;
  when (m[y][x + 1] = ' ' & ~v[y][x + 2]) push-last(q, vector(y, x + 2, d + 1)) end
end;
format-out("%=\n", c);
