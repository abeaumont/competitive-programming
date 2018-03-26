#!/usr/bin/env python3
# https://abc054.contest.atcoder.jp/tasks/abc054_b
n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
f = False
for i in range(n - m + 1):
    for j in range(n - m + 1):
        ok = True
        for k in range(m):
            for l in range(m):
                if a[i + k][j + l] != b[k][l]:
                    ok = False
                    break
            if not ok: break
        if ok:
            f = True
            break
    if f: break
if f: print('Yes')
else: print('No')
