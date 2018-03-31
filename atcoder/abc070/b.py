#!/usr/bin/env python3
# https://abc070.contest.atcoder.jp/tasks/abc070_b
a, b, c, d = map(int, input().split())
print(max(0, min(b, d) - max(a, c)))
