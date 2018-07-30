#!/usr/bin/env python3
# https://abc103.contest.atcoder.jp/tasks/abc103_d
n, m = map(int, input().split())
a = []
for _ in range(m):
    u, v = map(int, input().split())
    a.append((u, v))
a.sort()
i, c = 0, 0
for u, v in a:
    if u >= i:
        c += 1
        i = v
    else:
        i = min(i, v)
print(c)
