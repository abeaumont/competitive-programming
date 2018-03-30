#!/usr/bin/env python3
# https://beta.atcoder.jp/contests/abc063/tasks/abc063_b
s = input()
if len(s) == len(set(s)): print('yes')
else: print('no')
