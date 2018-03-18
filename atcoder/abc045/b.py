#!/usr/bin/env python3
# https://abc045.contest.atcoder.jp/tasks/abc045_b
x = [input() for _ in range(3)]
l = [0] * 3
k = 0
while l[k] < len(x[k]):
	n = ord(x[k][l[k]]) - ord('a')
	l[k] += 1
	k = n
print(['A', 'B', 'C'][k])
