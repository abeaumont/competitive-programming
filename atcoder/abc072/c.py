#!/usr/bin/env python3
# https://abc072.contest.atcoder.jp/tasks/arc082_a
n = int(input())
a = [0] * 10**5
for x in input().split():
    a[int(x)] += 1
c = 0
for i in range(1, 10**5 - 1):
    c = max(c, a[i] + a[i - 1] + a[i + 1])
print(c)
