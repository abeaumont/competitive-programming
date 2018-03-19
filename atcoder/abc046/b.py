#!/usr/bin/env python3
# https://abc046.contest.atcoder.jp/tasks/abc046_b
[n, k] = [int(x) for x in input().split()]
print(k * (k - 1) ** (n - 1))
