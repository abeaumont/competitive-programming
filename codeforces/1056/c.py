#!/usr/bin/env python3
# https://codeforces.com/contest/1056/problem/C
import sys
n,m=map(int,input().split())
p=[int(x) for x in input().split()]
ps=[(x,i) for i,x in enumerate(p)]
ps.sort(reverse=True)
x={}
y=[]
s=[False]*(2*n)
for _ in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    x[a]=b
    x[b]=a
    y.append((a,b))
t=int(input())
u=None
if t==2:
    u=int(input())-1
    if u==-2: import sys;sys.exit(0)
    s[u]=True
k=0
l=0
for o in range(n):
    if u is not None and u in x and not s[x[u]]:
        i=x[u]
    elif l<len(y):
        i=None
        while l<len(y):
            a,b=y[l]
            l+=1
            if s[a]: continue
            i = a if p[a]>p[b] else b
            break
        if i is None:
            while True:
                _,i=ps[k]
                if s[i]: k+=1
                else: break
    else:
        while True:
            _,i=ps[k]
            if s[i]: k+=1
            else: break
    s[i]=True
    print(i+1)
    if o==n-1 and t==2: break
    u=int(input())-1
    if u==-2: import sys;sys.exit(0)
    s[u]=True
