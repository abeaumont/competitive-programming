# https://abc096.contest.atcoder.jp/tasks/abc096_b
import math, sequtils, strutils
let
  l = stdin.readLine.split.mapIt(it.parseInt)
  a = l[0]
  b = l[1]
  c = l[2]
  k = stdin.readLine.parseInt
  m = l.max
echo a+b+c+(2^k-1)*m
