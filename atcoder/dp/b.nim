# https://atcoder.jp/contests/dp/tasks/dp_b
import sequtils,strutils
let
  l=stdin.readLine.split.mapIt(it.parseInt)
  n=l[0]
  k=l[1]
var
  h=newSeq[int]()
  r=newSeq[int](n)
for x in stdin.readLine.split:h.add(x.parseInt)
r[0]=0
for i in 1..<n:
  r[i]=r[i-1]+abs(h[i]-h[i-1])
  for j in 2..min(i,k):r[i]=min(r[i],r[i-j]+abs(h[i]-h[i-j]))
echo r[n-1]
