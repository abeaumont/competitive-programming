# https://atcoder.jp/contests/agc003/tasks/agc003_b
import strutils
let n = stdin.readLine.parseInt
var a = newSeq[int](n)
for i in 0..<n:
  a[i] = stdin.readLine.parseInt
var
  c = 0
  d = 0
for i in 0..<n:
  d += a[i] mod 2
  c += a[i] div 2 + d div 2
  d = if a[i] > 0: d mod 2 else: 0
echo c
