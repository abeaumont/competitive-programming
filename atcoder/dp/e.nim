# https://atcoder.jp/contests/dp/tasks/dp_e
import sequtils,strutils
let
  l=stdin.readLine.split.mapIt(it.parseInt)
  n=l[0]
  W=l[1]
  V=n*1000+1
var
  w=newSeq[int](n)
  v=newSeq[int](n)
  a=newSeq[int](V)
for i in 0..<V:a[i]=n*W+1
for i in 0..<n:
  let l=stdin.readLine.split.mapIt(it.parseInt)
  w[i]=(l[0])
  v[i]=(l[1])
for i in 0..<n:
  for j in countdown(V-v[i]-1,0,1):
    a[j+v[i]]=min(a[j+v[i]],a[j]+w[i])
  a[v[i]] = min(a[v[i]],w[i])
for j in countdown(V-1,0,1):
  if a[j] >= 0 and a[j] <= W:
    echo j
    break
