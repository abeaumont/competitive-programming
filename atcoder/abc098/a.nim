# https://abc098.contest.atcoder.jp/tasks/abc098_a
import sequtils, strutils

let
  f=stdin.readLine.split.mapIt(it.parseInt)
  a=f[0]
  b=f[1]
echo max(max(a+b,a-b),a*b)
