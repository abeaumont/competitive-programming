# https://abc098.contest.atcoder.jp/tasks/abc098_b
import strutils

let
  n=stdin.readLine.parseInt
  s=stdin.readLine
var m=0
for i in 0..<n:
  var
    u:set[char]={}
    v:set[char]={}
  for j in 0..<i:u.incl(s[j])
  for j in i..<n:v.incl(s[j])
  m=max(m,card(u*v))
echo m
