#!/usr/bin/env python3
# https://abc048.contest.atcoder.jp/tasks/abc048_b
a, b, x = [int(x) for x in input().split()]
print(b // x - (a - 1) // x)
