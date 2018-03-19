#!/usr/bin/env python3
# https://abc047.contest.atcoder.jp/tasks/abc047_a
[a, b, c] = [int(x) for x in input().split()]
if a == b + c or b == a + c or c == a + b: print('Yes')
else: print('No')
