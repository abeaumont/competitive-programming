# https://atcoder.jp/contests/abc139/tasks/abc139_f
import algorithm, math, sequtils, strutils

type Point[T] = tuple[x: T, y: T]

proc half[T](p: Point[T]): bool = p.y > 0 or p.y == 0 and p.x < 0
proc `-`[T](p: Point[T]): Point[T] = (x: -p.x, y: -p.y)
proc `+`[T](p, q: Point[T]): Point[T] = (x: p.x + q.x, y: p.y + q.y)
proc `*`[T](p, q: Point[T]): T = p.x * q.x + p.y * q.y
proc `^`[T](p, q: Point[T]): T = p.x * q.y - p.y * q.x
proc `~`[T](p: Point[T]): T = p.x * p.x + p.y * p.y
proc `+=`[T](p: var Point[T], q: Point[T]) =
  p.x += q.x
  p.y += q.y

var n = stdin.readLine().parseInt()
var ps = newSeq[Point[int64]]()
for i in 0..<n:
  let l = stdin.readLine().split().mapIt(int64(it.parseInt()))
  if l[0] != 0 or l[1] != 0:
    ps.add((x: l[0], y: l[1]))
n = ps.len
ps.sort do (x, y: Point[int64]) -> int:
  let
    hx = half(x)
    hy = half(y)
  if hx < hy: -1
  elif hx > hy: 1
  else: system.cmp(x^y, 0)
var m: int64
for i in 0..<n:
  var p: Point[int64]
  for j in 0..<n:
    let p2 = p + ps[(i+j)mod n]
    if ~p2 > ~p: p = p2
    else: break
  m = max(m, ~p)
echo $sqrt(float64(m))
