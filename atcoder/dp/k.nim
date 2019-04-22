# https://atcoder.jp/contests/dp/tasks/dp_k
import sequtils, strutils
let
  f = stdin.readLine.split.mapIt(it.parseInt)
  n = f[0]
  k = f[1]
  a = stdin.readLine.split.mapIt(it.parseInt)
var b = newSeq[bool](k+1)
for i in 0..k:
  for x in a:
    if i >= x and not b[i - x]:
      b[i] = true
if b[k]: echo "First"
else: echo "Second"
