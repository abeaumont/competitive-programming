#!/usr/bin/env python3
# https://abc073.contest.atcoder.jp/tasks/abc073_b
n = int(input())
s = 0
for _ in range(n):
    l, r = map(int, input().split())
    s += r - l + 1
print(s)
