#!/usr/bin/env python3
# https://abc047.contest.atcoder.jp/tasks/arc063_b
n, t = map(int, input().split())
a = [int(x) for x in input().split()]
m = a[0]
d = 0
c = 1
for x in a:
    if x < m: m = x
    elif x - m == d: c += 1
    elif x - m > d:
        d = x - m
        c = 1
print(c)
