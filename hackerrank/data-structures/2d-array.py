#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/2d-array
a=[0]*6
for i in range(6): a[i]=[int(x) for x in input().split()]
c=-9*9
for i in range(1,5):
    for j in range(1,5):
        c=max(c,a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1])
print(c)
