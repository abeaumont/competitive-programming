#!/usr/bin/env python2
# https://abc090.contest.atcoder.jp/tasks/arc091_b
n, k = map(int, raw_input().split())
c = 0
for b in range(k + 1, n + 1):
    for i in range((n - k) / b + 1):
        c += min(n + 1, b * (i + 1)) - max((k + b * i), 1)
print c
