#!/usr/bin/env python3
# https://abc068.contest.atcoder.jp/tasks/arc079_a
n, m = map(int, input().split())
s = set()
e = set()
p = False
for _ in range(m):
    a, b = map(int, input().split())
    if a == 1:
        if b in e:
            p = True
            break
        s.add(b)
    if b == n:
        if a in s:
            p = True
            break
        e.add(a)

if p: print('POSSIBLE')
else: print('IMPOSSIBLE')
