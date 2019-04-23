# https://atcoder.jp/contests/agc003/tasks/agc003_c
import algorithm, strutils, tables
let n = stdin.readLine.parseInt
var
  a = newSeq[int](n)
  c = 0
  s = initTable[int,int]()
  t = initTable[int,int]()
for i in 0..<n:
  a[i] = stdin.readLine.parseInt
for i, x in a.pairs:
  s[x] = i
a.sort(cmp)
for i, x in a.pairs:
  t[x] = i
for x in a:
  if s[x] mod 2 != t[x] mod 2:
    c += 1
echo c div 2
