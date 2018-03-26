#!/usr/bin/env python3
# https://abc054.contest.atcoder.jp/tasks/abc054_a
a, b = map(int, input().split())
if a == b: print('Draw')
elif a == 1: print('Alice')
elif b == 1: print('Bob')
elif a > b: print('Alice')
else: print('Bob')
