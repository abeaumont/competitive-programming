#!/usr/bin/env python3
# https://arc095.contest.atcoder.jp/tasks/arc095_a
n = int(input())
a = [int(x) for x in input().split()]
x = sorted(a)
m1 = x[n // 2]
m2 = x[n // 2 - 1]
for i in range(n):
    if a[i] < m1: print(m1)
    else: print(m2)
