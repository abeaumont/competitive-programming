#!/usr/bin/env python2
# https://abc090.contest.atcoder.jp/tasks/abc090_b
a, b = map(int, raw_input().split())
c = 0
for i in range(a, b + 1):
    x = str(i)
    if x == x[::-1]: c += 1
print c
