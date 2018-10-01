# https://abc071.contest.atcoder.jp/tasks/arc081_b
import strutils

const M = 1000_000_007
let
  n = stdin.readLine.parseInt
  s1 = stdin.readLine
  s2 = stdin.readLine
var
  i = 0
  s = 0
  p = 0
while i < n:
  case p
  of 0:
    if s1[i] == s2[i]:
      s = 3
      i.inc
      p = 1
    else:
      s = 6
      i.inc(2)
      p = 2
  of 1:
    s = s * 2 mod M
    if s1[i] == s2[i]:
      i.inc
    else:
      i.inc(2)
      p = 2
  else:
    if s1[i] == s2[i]:
      i.inc
      p = 1
    else:
      s = s * 3 mod M
      i.inc(2)
echo s
