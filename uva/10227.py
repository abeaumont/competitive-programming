#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/102/10227.pdf
n=int(input())
input()
for i in range(n):
    if i:print('')
    p,t=map(int,input().split())
    x=[0]*p
    while True:
        try:l=input()
        except:break
        if not l:break
        a,b=[int(k)-1 for k in l.split()]
        x[a]|=1<<b
    print(len(set(x)))
