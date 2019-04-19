# https://atcoder.jp/contests/dp/tasks/dp_f
import algorithm

let
  s = stdin.readLine
  t = stdin.readLine
  n = len(s)
  m = len(t)
var a = newSeq[seq[int]](n+1)
for i in 0..n:a[i]=newSeq[int](m+1)
for i in 1..n:
  for j in 1..m:
    a[i][j]=max(max(a[i][j-1],a[i-1][j]),int(s[i-1]==t[j-1])+a[i-1][j-1])
var
  r = ""
  i = n
  j = m
while i > 0 and j > 0:
  if a[i][j] == a[i][j-1]:
    j -= 1
  elif a[i][j] == a[i-1][j]:
    i -= 1
  else:
    r.add(t[j-1])
    i -= 1
    j -= 1
r.reverse()
echo r
