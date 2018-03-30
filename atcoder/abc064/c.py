#!/usr/bin/env python3
# https://abc064.contest.atcoder.jp/tasks/abc064_c
n = int(input())
a = [0] * 8
b = 0
for x in input().split():
    x = int(x)
    if x >= 3200: b += 1
    else: a[x//400] += 1
m = 0
for x in a:
    if x > 0: m += 1
print(max(m, 1), m + b)
