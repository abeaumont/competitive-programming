#!/usr/bin/env python3
# https://abc061.contest.atcoder.jp/tasks/abc061_c
n, k = map(int, input().split())
c = [0] * (10**5 + 1)
for _ in range(n):
    a, b = map(int, input().split())
    c[a] += b
d = 0
for i in range(10**5 + 1):
    d += c[i]
    if d >= k:
        print(i)
        break
