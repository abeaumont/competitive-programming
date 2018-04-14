#!/usr/bin/env python3
# https://arc095.contest.atcoder.jp/tasks/arc095_b
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
y = a[-1]
m = None
x = None
for i in range(n - 1):
    k = a[i]
    l = max(k, y - k)
    if m is None or m > l:
        m = l
        x = k
print(y, x)
