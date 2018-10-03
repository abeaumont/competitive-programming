# https://abc097.contest.atcoder.jp/tasks/abc097_b
import strutils
let x = stdin.readLine.parseInt
var
  i = 2
  m = 1
while i*i <= x:
  var p = i*i
  while p*i <= x:
    p *= i
  m = max(m, p)
  i.inc
echo m
