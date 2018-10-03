# https://abc097.contest.atcoder.jp/tasks/arc097_a
import algorithm, sequtils, strutils

let
  s = stdin.readLine
  k = stdin.readLine.parseInt
  m = min(k, s.len)
var a: seq[string] = @[]
for i in 1..m:
  for j in 0..s.len-i:
    a.add(s.substr(j, i+j-1))
a = a.sorted(cmp).deduplicate
echo a[k-1]
