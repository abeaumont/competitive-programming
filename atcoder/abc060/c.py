#!/usr/bin/env python3
# https://abc060.contest.atcoder.jp/tasks/arc073_a
n, t = map(int, input().split())
a = [int(x) for x in input().split()]
c = 0
s = 0
e = 0
for k in a:
    if k >= e:
        c += e - s
        s = k
        e = k + t
    else:
        e = k + t
c += e - s
print(c)
