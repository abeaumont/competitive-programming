# https://abc091.contest.atcoder.jp/tasks/abc091_a
import sequtils, strutils

let a = stdin.readLine.split
let b = a.mapIt(it.parseInt)
if b[0] + b[1] >= b[2]: echo "Yes"
else: echo "No"
