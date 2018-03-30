#!/usr/bin/env python3
# https://abc061.contest.atcoder.jp/tasks/abc061_b
n, m = map(int, input().split())
a = [0] * n
for _ in range(m):
    u, v = map(int, input().split())
    a[u - 1] += 1
    a[v - 1] += 1
for x in a: print(x)
