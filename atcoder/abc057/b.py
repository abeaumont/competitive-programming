#!/usr/bin/env python3
# https://abc057.contest.atcoder.jp/tasks/abc057_b
n, m = map(int, input().split())
a = [None] * n
for i in range(n):
    a[i] = tuple(map(int, input().split()))
b = [None] * m
for i in range(m):
    b[i] = tuple(map(int, input().split()))
for x, y in a:
    z = None
    k = None
    for i in range(m):
        c, d = b[i]
        d = abs(x - c) + abs(y - d)
        if z is None or d < z:
            z = d
            k = i
    print(k + 1)
