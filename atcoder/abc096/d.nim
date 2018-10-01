# https://abc096.contest.atcoder.jp/tasks/abc096_d
import algorithm, sequtils, strutils

const P = 55555
var p = newSeq[bool](P)
fill(p, 2, P-1, true)
for i in countup(4, P-1, 2): p[i] = false
for i in countup(3, P-1, 2):
  if p[i]:
    for j in countup(2*i, P-1, i): p[j] = false

let n = stdin.readLine.parseInt
var a = newSeq[int]()
for i in 0..<P:
  if p[i] and i mod 5 == 1:
    a.add(i)
    if a.len == n: break
echo a.mapIt($it).join(" ")
