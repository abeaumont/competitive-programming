#!/usr/bin/env python3
# https://abc046.contest.atcoder.jp/tasks/arc062_a
n = int(input())
a, b = [int(x) for x in input().split()]
for _ in range(n - 1):
	c, d = [int(x) for x in input().split()]
	k = max((a - 1) // c + 1, (b - 1) // d + 1)
	a, b = c * k, d * k
print(a + b)
