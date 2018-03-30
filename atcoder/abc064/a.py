#!/usr/bin/env python3
# https://abc064.contest.atcoder.jp/tasks/abc064_a
r, g, b = map(int, input().split())
if (r * 100 + g * 10 + b) % 4 == 0: print('YES')
else: print('NO')
