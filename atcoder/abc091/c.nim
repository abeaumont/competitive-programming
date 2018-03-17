# https://abc091.contest.atcoder.jp/tasks/arc092_a
import algorithm, sequtils, sets, strutils

type ii = (int, int)
type sii = seq[ii]

let n = stdin.readLine.parseInt
var s = newSeq[ii](n)
var t = newSeq[ii](n)
for i in 0..<n:
  let l = stdin.readLine
  let a = l.split.mapIt(it.parseInt)
  s[i] = (a[0], a[1])
s.sort do (a, b: ii) -> int: cmp(b[1], a[1])
for i in 0..<n:
  let l = stdin.readLine
  let a = l.split.mapIt(it.parseInt)
  t[i] = (a[0], a[1])
t.sort(cmp)
var p = initSet[ii]()
for x in t:
  let (a, b) = x
  var k = s.lower_bound(x, proc(a, b: ii): int = -cmp(a[1], b[1]))
  while k < s.len and (p.contains(s[k]) or s[k][0] > a): k.inc
  if k < s.len(): p.incl(s[k])
echo p.len
