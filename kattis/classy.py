#!/usr/bin/env python3
# https://open.kattis.com/problems/classy
m={'upper':2,'middle':1,'lower':0}
for _ in range(int(input())):
    n=int(input())
    a=[0]*n
    k=0
    for i in range(n):
        w,c,_=input().split()
        f=[-m[x] for x in c.split('-')]
        f.reverse()
        k=max(k,len(f))
        a[i]=(f, w[:-1])
    for i in range(n):
        f=a[i][0]
        f.extend([-1]*(k-len(f)))
    a.sort()
    for i in range(n): print(a[i][1])
    print('='*30)
