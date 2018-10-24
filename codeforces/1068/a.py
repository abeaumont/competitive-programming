#!/usr/bin/env python3
# https://codeforces.com/contest/1068/problem/A
n,m,k,l=map(int,input().split())
q=(l+k-1)//m+1
if q*m>n:print(-1)
else:print(q)
