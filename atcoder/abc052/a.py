#!/usr/bin/env python3
# https://abc052.contest.atcoder.jp/tasks/abc052_a
a, b, c, d = [int(x) for x in input().split()]
print(max(a*b, c*d))