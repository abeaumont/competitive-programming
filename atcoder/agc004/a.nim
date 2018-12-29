# https://atcoder.jp/contests/agc004/tasks/agc004_a
import algorithm, sequtils, strutils
var a = stdin.readLine.split.mapIt(it.parseInt)
if a.any(proc(x:int):bool=x mod 2==0): echo 0
else:
  a.sort(cmp)
  echo a[0]*a[1]
