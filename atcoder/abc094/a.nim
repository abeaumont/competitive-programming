# https://abc094.contest.atcoder.jp/tasks/abc094_a
import sequtils, strutils

let
  l = stdin.readLine.split
  s = l.mapIt(it.parseInt())
if s[2] >= s[0] and s[2] <= s[0] + s[1]: echo "YES"
else: echo "NO"
