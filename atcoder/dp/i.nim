# https://atcoder.jp/contests/dp/tasks/dp_i
import sequtils, strutils
let
  n = stdin.readLine.parseInt
  p = stdin.readLine.split.mapIt(it.parseFloat)
var
  a = newSeq[float](n+1)
  r = 0.0
a[0] = 1.0
var t = a[0]
for i in 0..<n:
  t = a[0]
  a[0] = a[0] * (1-p[i])
  for j in 1..n:
    let x = a[j]
    a[j] = t*p[i] + a[j]*(1 - p[i])
    t = x
for i in (n div 2+1)..n:
  r += a[i]
echo r
