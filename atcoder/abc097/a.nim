# https://abc097.contest.atcoder.jp/tasks/abc097_a
import sequtils, strutils
let l = stdin.readLine.split.mapIt(it.parseInt)
if abs(l[0]-l[2]) <= l[3] or (abs(l[0]-l[1]) <= l[3] and abs(l[1]-l[2]) <= l[3]):
  echo "Yes"
else:
  echo "No"
