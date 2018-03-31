#!/usr/bin/env python3
# https://abc076.contest.atcoder.jp/tasks/abc076_b
n = int(input())
k = int(input())
a = 1
for _ in range(n):
    if a < k:
        a *= 2
    else:
        a += k
print(a)
