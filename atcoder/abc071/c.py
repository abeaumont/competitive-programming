#!/usr/bin/env python3
# https://abc071.contest.atcoder.jp/tasks/arc081_a
d = {}
_ = input()
for x in input().split():
    x = int(x)
    d[x] = d.get(x, 0) + 1
p = []
for k, v in d.items():
    if v >= 4: p.append(k)
    if v >= 2: p.append(k)
if len(p) < 2: print(0)
else:
    p.sort(reverse=True)
    print(p[0] * p[1])
