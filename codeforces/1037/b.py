#!/usr/bin/env python3
# https://codeforces.com/contest/1037/problem/B
n, s = map(int, input().split())
xs = [int(x) for x in input().split()]
xs.sort()
c = 0
if xs[n//2] < s:
  for i in range(n//2, n): c += max(0, s - xs[i])
elif xs[n//2] > s:
  for i in range(0, n//2+1): c += max(0, xs[i] - s)
print(c)
