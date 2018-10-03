# https://abc097.contest.atcoder.jp/tasks/arc097_b
import algorithm, sequtils, strutils
let
  l = stdin.readLine.split.mapIt(it.parseInt)
  n = l[0]
  m = l[1]
  p = stdin.readLine.split.mapIt(it.parseInt-1)
var g = newSeq[seq[int]](n)
fill(g, newSeq[int]())
for i in 1..m:
  let l = stdin.readLine.split.mapIt(it.parseInt-1)
  g[l[0]].add(l[1])
  g[l[1]].add(l[0])
var
  c = newSeq[int](n)
  k = 1
  s = 0

proc dfs(u, k: int) =
  c[u] = k
  for v in g[u]:
    if c[v] > 0: continue
    dfs(v, k)

for i in 0..<n:
  if c[i] == 0:
    dfs(i, k)
    k.inc
for i in 0..<n:
  if c[i] == c[p[i]]: s.inc
echo s
