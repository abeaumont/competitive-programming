# https://atcoder.jp/contests/dp/tasks/dp_a
import strutils

let n=stdin.readLine.parseInt
var
  h=newSeq[int]()
  r=newSeq[int](n)
for x in stdin.readLine.split:h.add(x.parseInt)
r[0]=0
r[1]=abs(h[1]-h[0])
for i in 2..<n:
  r[i]=min(r[i-2]+abs(h[i]-h[i-2]),r[i-1]+abs(h[i]-h[i-1]))
echo r[n-1]
