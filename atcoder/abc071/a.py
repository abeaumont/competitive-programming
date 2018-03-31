#!/usr/bin/env python3
# https://abc071.contest.atcoder.jp/tasks/abc071_a
x, a, b = map(int, input().split())
if abs(x - a) < abs(x - b): print('A')
else: print('B')
