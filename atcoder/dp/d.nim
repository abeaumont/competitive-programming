# https://atcoder.jp/contests/dp/tasks/dp_d
import sequtils,strutils
let
  l=stdin.readLine.split.mapIt(it.parseInt)
  n=l[0]
  W=l[1]
var
  w=newSeq[int](n)
  v=newSeq[int](n)
  a=newSeq[int](W+1)
for i in 0..<n:
  let l=stdin.readLine.split.mapIt(it.parseInt)
  w[i]=(l[0])
  v[i]=(l[1])
for i in 1..n:
  for j in countdown(W,0,1):
    if j>=w[i-1]:
      a[j]=max(a[j],a[j-w[i-1]]+v[i-1])
echo a[W]
