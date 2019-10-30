# https://atcoder.jp/contests/abc079/tasks/abc079_d
import sequtils, strutils

let
  l = stdin.readLine.split.mapIt(it.parseInt)
  h = l[0]
  w = l[1]
var
  cs = newSeqWith(10, newSeq[int](10))
  s = 0
for i in 0..9:
  let l = stdin.readLine.split.mapIt(it.parseInt)
  for j in 0..9:
    cs[i][j] = l[j]
for k in 0..9:
  for i in 0..9:
    for j in 0..9:
      cs[i][j] = min(cs[i][j], cs[i][k] + cs[k][j])
for i in 0..<h:
  let l = stdin.readLine().split().mapIt(it.parseInt)
  for j in 0..<w:
    if l[j] != -1:
      s += cs[l[j]][1]
echo s
