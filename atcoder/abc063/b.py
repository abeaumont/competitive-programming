#!/usr/bin/env python3
# https://abc063.contest.atcoder.jp/tasks/abc063_b
s = input()
if len(s) == len(set(s)): print('yes')
else: print('no')
