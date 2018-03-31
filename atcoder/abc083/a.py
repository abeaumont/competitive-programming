#!/usr/bin/env python3
# https://abc083.contest.atcoder.jp/tasks/abc083_a
a, b, c, d = map(int, input().split())
if a + b < c + d: print('Right')
elif a + b > c + d: print('Left')
else: print('Balanced')
