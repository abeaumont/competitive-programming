#!/usr/bin/env python3
# https://abc052.contest.atcoder.jp/tasks/arc067_b
n, a, b = map(int, input().split())
x = [int(x) for x in input().split()]
c = 0
for i in range(n - 1): c += min((x[i + 1] - x[i]) * a, b)
print(c)
