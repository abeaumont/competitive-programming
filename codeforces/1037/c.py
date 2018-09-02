#!/usr/bin/env python3
# https://codeforces.com/contest/1037/problem/C
n = int(input())
a = input()
b = input()
i = 0
c = 0
while i < n - 1:
  if a[i] == b[i]: i += 1
  elif a[i+1] == b[i+1]:
    c += 1
    i += 2
  elif a[i] != a[i+1]:
    c += 1
    i += 2
  else:
    c += 1
    i += 1
if i == n - 1 and a[i] != b[i]: c += 1
print(c)
