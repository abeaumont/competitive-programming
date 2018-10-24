#!/usr/bin/env pypy3
from sys import stdin
ps = set()
n = 0
for l in stdin:
    n+=1
    x,y=map(int, l.split())
    ps.add((x, y))
while True:
    stable = True
    d={}
    for x,y in ps:
        for k in [(x-1,y+2),(x-1,y-2),(x-2,y-1),(x-2,y+1),(x+1,y-2),(x+1,y+2),(x+2,y-1),(x+2,y+1)]:
            if k in d: d[k]+=1
            else: d[k]=1
    for k, v in d.items():
        if v >= 4:
          if k in ps: continue
          ps.add(k)
          stable = False
    if stable:
        break
print(n, len(ps), n*n//10)
assert(len(ps)>=n*n//10)
