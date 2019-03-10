#!/usr/bin/env python3
# https://abc102.contest.atcoder.jp/tasks/arc100_a
n = int(input())
a = [int(x) - (i + 1) for i, x in enumerate(input().split())]
a.sort()
m = a[n//2]
c = 0
for x in a: c += abs(x - m)
print(c)
