#!/usr/bin/env python3
# https://abc056.contest.atcoder.jp/tasks/abc056_b
w, a, b = map(int, input().split())
if a > b: print(max(0, a - (b + w)))
else: print(max(0, b - (a + w)))
