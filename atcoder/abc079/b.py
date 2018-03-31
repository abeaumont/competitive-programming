#!/usr/bin/env python3
# https://abc079.contest.atcoder.jp/tasks/abc079_b
l, m = 2, 1
for i in range(int(input()) - 1):
    l, m = m, l + m
print(m)
