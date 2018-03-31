#!/usr/bin/env python3
# https://abc073.contest.atcoder.jp/tasks/abc073_c
d = {}
for _ in range(int(input())):
    x = int(input())
    d[x] = d.get(x, 0) + 1
c = 0
for v in d.values():
    if v % 2: c += 1
print(c)
