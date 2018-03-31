#!/usr/bin/env python3
# https://abc076.contest.atcoder.jp/tasks/abc076_c
s = input()
t = input()
u = None
for i in range(len(s) - len(t) + 1):
    ok = True
    for j in range(len(t)):
        if s[i + j] != t[j] and s[i + j] != '?':
            ok = False
            break
    if ok:
        v = []
        for j in range(i):
            if s[j] == '?': v.append('a')
            else: v.append(s[j])
        for j in t:
            v.append(j)
        for j in range(i + len(t), len(s)):
            if s[j] == '?': v.append('a')
            else: v.append(s[j])
        v = ''.join(v)
        if u is None or v < u: u = v
if u is None: print('UNRESTORABLE')
else: print(u)
