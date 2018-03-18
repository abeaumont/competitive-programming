#!/usr/bin/env python2
# https://abc081.contest.atcoder.jp/tasks/arc086_a
[n, k] = map(int, raw_input().split())
xs = map(int, raw_input().split())
d = dict()
for x in xs:
    if x in d:
        d[x] += 1
    else:
        d[x] = 1
v = d.values()
v.sort()
if len(v) <= k:
    r = []
else:
    r = v[:len(v)-k]
print sum(r)
