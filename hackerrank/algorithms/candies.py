#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/candies
n = int(input())
a = [int(input()) for i in range(n)]
b = [1] * n
c = [1] * n
for i in range(1, n):
    if a[i] > a[i - 1]: b[i] = b[i - 1] + 1
for i in range(n - 2, -1, -1):
    if a[i] > a[i + 1]: c[i] = c[i + 1] + 1
d = 0
for i in range(n):
    d += max(b[i], c[i])
print(d)
