#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/dynamic-array
n,q=map(int,input().split())
a=[list() for _ in range(n)]
l = 0
for _ in range(q):
    t,x,y=map(int,input().split())
    if t == 1: a[(x^l)%n].append(y)
    else:
        i=(x^l)%n
        l=a[i][y%len(a[i])]
        print(l)
