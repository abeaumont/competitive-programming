#!/usr/bin/env python3
# https://abc083.contest.atcoder.jp/tasks/abc083_b
n, a, b, = map(int, input().split())
c = 0
for i in range(1, n + 1):
    d = 0
    k = i
    while k > 0:
        d += k % 10
        k //= 10
    if d >= a and d <= b:
        c += i
print(c)
