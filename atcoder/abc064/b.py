#!/usr/bin/env python3
# https://abc064.contest.atcoder.jp/tasks/abc064_b
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
c = 0
for i in range(n - 1):
    c += a[i + 1] - a[i]
print(c)
