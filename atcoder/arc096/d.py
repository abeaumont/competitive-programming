#!/usr/bin/env python3
# https://arc096.contest.atcoder.jp/tasks/arc096_b
n, c = map(int, input().split())
a = [None] * n
for i in range(n):
    x, v = map(int, input().split())
    a[i] = (x, v)
l1 = [None] * n
l2 = [None] * n
r1 = [None] * n
r2 = [None] * n
b = 0
m = 0
for i in range(n):
    x, v = a[i]
    b += v - x
    m = max(m, b)
    r1[i] = m
    r2[i] = max(0, b - x)
    b += x
b = 0
m = 0
for i in range(n - 1, -1, -1):
    x, v = a[i]
    x = c - x
    b += v - x
    m = max(m, b)
    l1[n - i - 1] = m
    l2[n - i - 1] = max(0, b - x)
    b += x
m = max(r1[n - 1], l1[n - 1])
for i in range(n - 1): m = max(m, max(r2[n - i - 2] + l1[i], l2[n - i - 2] + r1[i]))
print(m)
