# https://abc091.contest.atcoder.jp/tasks/abc091_b
import strutils, tables

var t = initCountTable[string]()
let n = stdin.readLine.parseInt
for i in 0..<n:
  t.inc(stdin.readLine)
let m = stdin.readLine.parseInt
for i in 0..<m:
  t.inc(stdin.readLine, -1)
var x = 0
for v in t.values():
  x = max(x, v)
echo x
