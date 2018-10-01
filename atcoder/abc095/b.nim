# https://abc095.contest.atcoder.jp/tasks/abc095_b
import algorithm, sequtils, strutils
let
  xs = stdin.readLine.split.mapIt(it.parseInt)
  n = xs[0]
  x = xs[1]
var
  a = newSeq[int](n)
  s = 0
for i in 0..<n:
  a[i] = stdin.readLine.parseInt
  s += a[i]
a.sort(cmp)
if x < s:
  var
    i = 0
    c = 0
  while c < s:
    c += a[i]
    i.inc
  echo i
else:
  echo(n + (x - s) div a[0])
