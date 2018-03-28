#!/usr/bin/env python3
# https://abc060.contest.atcoder.jp/tasks/abc060_b
a, b, c = map(int, input().split())
ok = False
k = a
for _ in range(b):
    if k % b == c:
        ok = True
        break
    k += a
if ok: print('YES')
else: print('NO')
