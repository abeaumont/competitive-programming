# https://abc094.contest.atcoder.jp/tasks/abc094_b
import sequtils, strutils

let
  l1 = stdin.readLine.split
  l = l1.mapIt(it.parseInt)
  (n, m, x) = (l[0], l[1], l[2])
  l2 = stdin.readLine.split
  a = l2.mapIt(it.parseInt)
var left = 0
for i in 0..<m:
  if a[i] > x: break
  left += 1
echo min(left, m - left)
