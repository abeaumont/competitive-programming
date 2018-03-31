#!/usr/bin/env python3
# https://abc083.contest.atcoder.jp/tasks/arc088_a
x, y = map(int, input().split())
c = 0
k = x
while k <= y:
    c += 1
    k *= 2
print(c)
