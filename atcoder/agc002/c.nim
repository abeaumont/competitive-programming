# https://atcoder.jp/contests/agc002/tasks/agc002_c
import sequtils, strutils
let
  f = stdin.readLine.split.mapIt(it.parseInt)
  n = f[0]
  l = f[1]
  a = stdin.readLine.split.mapIt(it.parseInt)
var k = -1
for i in 1..<n:
  if a[i-1] + a[i] >= l:
    k = i
    break
if k == -1:
  echo "Impossible"
else:
  echo "Possible"
  for i in 1..<k:
    echo i
  for i in countdown(n-1,k+1,1):
    echo i
  echo k
