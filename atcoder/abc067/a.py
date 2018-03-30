#!/usr/bin/env python3
# https://abc067.contest.atcoder.jp/tasks/abc067_a
a, b = map(int, input().split())
if a % 3 == 0 or b % 3 == 0 or (a + b) % 3 == 0: print('Possible')
else: print('Impossible')
