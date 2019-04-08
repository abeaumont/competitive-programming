#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/000000000008830b
from math import gcd
t=int(input())
for i in range(t):
    n,l=map(int,input().split())
    x=[int(x)for x in input().split()]
    y=set()
    for j in range(l-1):
        if x[j]==x[j+1]:continue
        g=gcd(x[j],x[j+1])
        y.add(g)
        y.add(x[j]//g)
        y.add(x[j+1]//g)
    p=sorted(list(y))
    d={}
    for j,k in enumerate(p):
        d[k]=chr(ord('A')+j)
    r=[None]*(l+1)
    for j in range(l-1):
        if r[j]:
            r[j+1]=x[j]//r[j]
            r[j+2]=x[j+1]//r[j+1]
        elif x[j]!=x[j+1]:
            g=gcd(x[j],x[j+1])
            r[j]=x[j]//g
            r[j+1]=g
            r[j+2]=x[j+1]/g
    for j in range(l-2,-1,-1):
        if r[j+2]:
            r[j+1]=x[j+1]//r[j+2]
            r[j]=x[j]//r[j+1]
        elif x[j]!=x[j+1]:
            g=gcd(x[j],x[j+1])
            r[j]=x[j]//g
            r[j+1]=g
            r[j+2]=x[j+1]/g
    print('Case #{}: {}'.format(i+1,''.join([d[x] for x in r])))
