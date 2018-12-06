# https://abc098.contest.atcoder.jp/tasks/arc098_a
import strutils

let
  n=stdin.readLine.parseInt
  s=stdin.readLine
var
  u=newSeq[int](n)
  v=newSeq[int](n)
u[0]=if s[0]=='E': 0 else: 1
v[n-1]=if s[n-1]=='W': 0 else: 1
for i in 1..<n:
  u[i]=u[i-1]+(if s[i]=='E': 0 else: 1)
  v[n-i-1]=v[n-i]+(if s[n-i-1]=='W': 0 else: 1)
var m=min(v[1],u[n-2])
for i in 1..<n-1: m=min(m,u[i-1]+v[i+1])
echo m
