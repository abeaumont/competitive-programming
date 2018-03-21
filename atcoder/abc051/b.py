#!/usr/bin/env python3
# https://abc051.contest.atcoder.jp/tasks/abc051_b
k, s = [int(x) for x in input().split()]
c = 0
for i in range(k + 1):
    for j in range(k + 1):
        z = s - i - j
        if z >= 0 and z <= k: c += 1
print(c)