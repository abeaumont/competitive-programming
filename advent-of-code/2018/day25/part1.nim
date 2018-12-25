import math, sequtils, sugar, streams, strutils
var
  ps = lc[x.split(',').mapIt(it.strip.parseInt) | (x <- stdin.lines), seq[int]]
  c = lc[i | (i <- 0..<ps.len), int]

proc find(x: int): int =
  result = x
  while result != c[result]: result = c[result]

for i in 0..<ps.len-1:
  for j in i+1..<ps.len:
    if sum(lc[abs(ps[i][k] - ps[j][k]) | (k <- 0..3), int]) <= 3:
      c[i.find]=j.find
echo c.mapIt(it.find).deduplicate.len
