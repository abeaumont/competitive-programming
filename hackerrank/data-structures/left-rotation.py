#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/array-left-rotation
n,d=map(int,input().split())
a=input().split()
print(' '.join(a[d:]+a[:d]))
