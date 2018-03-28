#!/usr/bin/env python3
# https://abc060.contest.atcoder.jp/tasks/abc060_a
a, b, c = input().split()
if a[-1] == b[0] and b[-1] == c[0]: print('YES')
else: print('NO')
