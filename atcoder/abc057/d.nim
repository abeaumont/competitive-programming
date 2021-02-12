# https://atcoder.jp/contests/abc057/tasks/abc057_d
import algorithm, sequtils, strutils

let N = 50
var binom = newSeq[seq[int64]](N+1)
for i in 0..N:
  binom[i] = newSeq[int64](N+1)
  binom[i][0] = 1
  for j in 1..i:
    binom[i][j] = binom[i-1][j-1] + binom[i-1][j]
let
  fs = stdin.readLine.split.mapIt(it.parseInt)
  n = fs[0]
  a = fs[1]
  b = fs[2]
var xs = stdin.readLine.split.mapIt(it.parseInt)
xs.sort(SortOrder.Descending)
var
  s = 0
  c = 0i64
for i in 0..<a:
  s += xs[i]
let x = xs[a-1]
var
  t = 0
  mn = 0
  mx = 0
for i in 0..<n:
  if xs[i] == x:
    t += 1
    if i < a:
      mn += 1
    elif i < b:
      mx += 1
if xs[0] != x:
  mx = 0
for i in mn..mn+mx:
  c += binom[t][i]
echo float64(s) / float64(a)
echo c
