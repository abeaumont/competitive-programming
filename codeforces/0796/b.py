#!/usr/bin/env python3
n,m,k = map(int,input().split())
h = {int(x) for x in input().split()}
x = 1
for _ in range(k):
    if x in h: break
    u,v = map(int,input().split())
    if u == x: x = v
    elif v == x: x = u
print(x)    
