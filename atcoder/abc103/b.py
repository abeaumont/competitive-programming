#!/usr/bin/env python3
# https://abc103.contest.atcoder.jp/tasks/abc103_b
s = input()
t = input()
l = len(s)
ok = False
for i in range(l):
    if s[l-i:] + s[:l-i] == t:
        ok = True
        break
print('Yes' if ok else 'No')
