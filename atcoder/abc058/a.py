#!/usr/bin/env python3
# https://abc058.contest.atcoder.jp/tasks/abc058_a
a, b, c= map(int, input().split())
if b - a == c - b: print('YES')
else: print('NO')
