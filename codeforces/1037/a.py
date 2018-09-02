#!/usr/bin/env python3
# https://codeforces.com/contest/1037/problem/A
n = int(input())
i = 1
k = 0
x = 0
while x < n:
  x += i
  i *= 2
  k += 1
print(k)
