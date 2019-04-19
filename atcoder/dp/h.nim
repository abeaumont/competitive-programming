# https://atcoder.jp/contests/dp/tasks/dp_h
import math, sequtils, strutils
let
  f = stdin.readLine.split.mapIt(it.parseInt)
  h = f[0]
  w = f[1]
  m = 10^9+7
var
  a = newSeq[string](h)
  b = newSeq[seq[int]](h)
for i in 0..<h:
  a[i] = stdin.readLine
  b[i] = newSeq[int](w)
for i in 0..<h:
  for j in 0..<w:
    if a[i][j] == '#':
      b[i][j] = 0
    elif i > 0 and j > 0:
      b[i][j] = (b[i-1][j] + b[i][j-1]) mod m
    elif i > 0:
      b[i][j] = b[i-1][j]
    elif j > 0:
      b[i][j] = b[i][j-1]
    else:
      b[i][j] = 1
echo b[h-1][w-1]
