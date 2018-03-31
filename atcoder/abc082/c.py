#!/usr/bin/env python3
# https://abc082.contest.atcoder.jp/tasks/arc087_a
input()
d = {}
for x in input().split():
    x = int(x)
    d[x] = d.get(x, 0) + 1
c = 0
for k, v in d.items():
    if k > v: c += v
    elif k < v: c += (v - k)
print(c)
