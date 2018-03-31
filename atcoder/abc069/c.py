#!/usr/bin/env python3
# https://abc069.contest.atcoder.jp/tasks/arc080_a
n = int(input())
a, b = 0, 0
for x in input().split():
    x = int(x)
    if x % 4 == 0: a += 1
    elif x % 2 == 0: b += 1
if a * 2 + b // 2 * 2 + 1 >= n: print('Yes')
else: print('No')
