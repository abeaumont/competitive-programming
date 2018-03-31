#!/usr/bin/env python3
# https://abc082.contest.atcoder.jp/tasks/abc082_b
s = sorted(input())
t = sorted(input(), reverse=True)
if s < t: print('Yes')
else: print('No')
