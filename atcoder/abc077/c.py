#!/usr/bin/env python3
# https://abc077.contest.atcoder.jp/tasks/arc084_a
n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
a.sort(reverse=True)
b.sort(reverse=True)
c.sort(reverse=True)
d = [0] * (n + 1)
j = 0
for i in range(n):
    while j < n and b[i] <= a[j]: j += 1
    d[i] = (n - j)
for i in range(n - 1, 0, -1):
    d[i - 1] += d[i]
j = 0
s = 0
for i in range(n):
    while j < n and c[i] <= b[j]: j += 1
    s += d[j]
print(s)
