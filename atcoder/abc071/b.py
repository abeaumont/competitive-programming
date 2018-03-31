#!/usr/bin/env python3
# https://abc071.contest.atcoder.jp/tasks/abc071_b
import string

s = input()
if len(set(s)) == 26: print('None')
else:
    for c in string.ascii_lowercase:
        if c not in s:
            print(c)
            break
