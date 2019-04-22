# https://atcoder.jp/contests/agc002/tasks/agc002_b
import sequtils, strutils
let
  f = stdin.readLine.split.mapIt(it.parseInt)
  n = f[0]
  m = f[1]
var
  a = newSeq[int](n)
  b = newSeq[bool](n)
for i in 0..<n:
  a[i]=1
b[0] = true
for _ in 1..m:
  let
    f = stdin.readLine.split.mapIt(it.parseInt)
    x = f[0] - 1
    y = f[1] - 1
  if b[x]:
    b[y] = true
  a[x] -= 1
  a[y] += 1
  if a[x] == 0:
    b[x] = false
var c = 0
for x in b:
  if x:
    c += 1
echo c
