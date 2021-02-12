# https://atcoder.jp/contests/abc058/tasks/arc071_b
import algorithm, sequtils, strutils

let
  M = 1_000_000_007i64
  fs = stdin.readLine.split.mapIt(it.parseInt)
  n = fs[0]
  m = fs[1]
var
  x = 0i64
  y = 0i64
  xs = stdin.readLine.split.mapIt(int64(it.parseInt))
  ys = stdin.readLine.split.mapIt(int64(it.parseInt))
xs.sort()
ys.sort()
var
  x0 = xs[0]
  y0 = ys[0]
for i in 1..<n:
  x = (x + int64(xs[i] - x0) * i mod M * (n - i) mod M) mod M
  x0 = xs[i]
for i in 1..<m:
  y = (y + int64(ys[i] - y0) * i mod M * (m - i) mod M) mod M
  y0 = ys[i]
var ans = x * y mod M
if ans < 0:
  ans += M
echo ans
