# https://atcoder.jp/contests/agc001/tasks/agc001_b
import sequtils, strutils
var
  l = stdin.readLine.split.mapIt(it.parseBiggestInt)
  n = l[0]
  x = l[1]
  c = n

n = n - x
while n mod x > 0:
  c += n div x * x * 2
  let t = x
  x = n - n div x * x
  n = t
echo c + (n div x * 2 - 1) * x
