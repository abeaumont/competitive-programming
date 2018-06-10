#!/usr/bin/env python3
# https://abc099.contest.atcoder.jp/tasks/abc099_b
a, b = map(int, input().split())
d = b - a
k = d * (d - 1) // 2
print(k - a)
