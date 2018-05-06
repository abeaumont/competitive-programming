#!/usr/bin/env python3
# https://abc093.contest.atcoder.jp/tasks/abc093_b
a, b, k = map(int, input().split())
for i in range(a, min(b + 1, a + k)): print(i)
for i in range(max(a + k, b - k + 1), b + 1): print(i)
