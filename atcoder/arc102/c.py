#!/usr/bin/env python3
# https://arc102.contest.atcoder.jp/tasks/arc102_a
n, k = map(int, input().split())
if k % 2: print((n // k) ** 3)
else: print((n // k) ** 3 + ((n - k //2) // k + 1) ** 3)
