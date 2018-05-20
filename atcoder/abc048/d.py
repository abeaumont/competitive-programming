#!/usr/bin/env python3
# https://abc048.contest.atcoder.jp/tasks/arc064_b
s = input()
if s[0] == s[-1] and len(s) % 2 == 1 or s[0] != s[-1] and len(s) % 2 == 0: print('Second')
else: print('First')
