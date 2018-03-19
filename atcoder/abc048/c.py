#!/usr/bin/env python3
# https://abc048.contest.atcoder.jp/tasks/arc064_a
n, x = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
c = 0
for i in range(1, len(a)):
	b = a[i - 1] + a[i]
	d = b - x
	if d > 0:
		c += d
		e = min(a[i], d)
		a[i] -= e
		d -= e
		if d > 0:
			a[i - 1] -= d
print(c)
