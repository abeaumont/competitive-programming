# https://abc096.contest.atcoder.jp/tasks/abc096_a
import sequtils, strutils
let
  l = stdin.readLine.split.mapIt(it.parseInt)
  a = l[0]
  b = l[1]
echo if b >= a: a else: a-1
