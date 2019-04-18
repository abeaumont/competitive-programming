# https://atcoder.jp/contests/dp/tasks/dp_c
import sequtils,strutils
let n=stdin.readLine.parseInt
var
  a=newSeq[int](n)
  b=newSeq[int](n)
  c=newSeq[int](n)
  r=newSeq[array[3,int]](n+1)
for i in 0..<n:
  let l=stdin.readLine.split.mapIt(it.parseInt)
  a[i]=l[0]
  b[i]=l[1]
  c[i]=l[2]
for i in 1..n:
  r[i][0]=max(r[i-1][1],r[i-1][2])+a[i-1]
  r[i][1]=max(r[i-1][0],r[i-1][2])+b[i-1]
  r[i][2]=max(r[i-1][0],r[i-1][1])+c[i-1]
echo max(r[n])
