#!/usr/bin/env python3
# https://abc045.contest.atcoder.jp/tasks/arc061_a
def s(d, k, i, c):
	if i == len(d): return c + int(k)
	return s(d, d[i], i + 1, int(k) + c) + s(d, k + d[i], i + 1, c)

d = [x for x in input()]
print(s(d, d[0], 1, 0))
