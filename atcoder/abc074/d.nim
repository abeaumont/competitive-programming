# https://atcoder.jp/contests/abc074/tasks/arc083_b
import algorithm, sequtils, strutils

let n = stdin.readLine().parseInt()
var a = newSeq[seq[int]](n)
for i in 0..<n:
  a[i] = stdin.readLine().split().mapIt(it.parseInt())
var
  ok = true
  c = 0i64
for i in 0..<n:
  for j in 0..<n:
    var needed = true
    for k in 0..<n:
      if k == i or k == j: continue
      if a[i][k] + a[k][j] < a[i][j]:
        ok = false
      elif a[i][k] + a[k][j] == a[i][j]:
        needed = false
    if needed:
      c += a[i][j]
echo if ok: c div 2 else: -1
