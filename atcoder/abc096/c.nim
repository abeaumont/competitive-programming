# https://abc096.contest.atcoder.jp/tasks/abc096_c
import sequtils, strutils

let
  l = stdin.readLine.split.mapIt(it.parseInt)
  h = l[0]
  w = l[1]
var m = newSeq[string](h)
for i in 0..<h: m[i] = stdin.readLine
var ok = true
block a:
  for i in 0..<h:
    for j in 0..<w:
      if m[i][j] == '#':
        if i > 0 and m[i-1][j] == '#': continue
        if i < h-1 and m[i+1][j] == '#': continue
        if j > 0 and m[i][j-1] == '#': continue
        if j < w-1 and m[i][j+1] == '#': continue
        ok = false
        break a
echo if ok: "Yes" else: "No"
