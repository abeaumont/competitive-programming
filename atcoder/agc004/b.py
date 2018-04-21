#!/usr/bin/env python3
# https://agc004.contest.atcoder.jp/tasks/agc004_b
n, x = map(int, input().split())
a = [int(x) for x in input().split()]
b = [None] * n
for i, c in enumerate(a):
    b[i] = [None] * n
    b[i][0] = a[i]
    for j in range(1, n): b[i][j] = min(b[i][j - 1], a[(i - j) % n])
d = None
for i in range(n):
    c = i * x
    for j in range(n): c += b[j][i]
    if d is None or c < d: d = c
print(d)
