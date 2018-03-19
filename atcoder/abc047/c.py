#!/usr/bin/env python3
# https://abc047.contest.atcoder.jp/tasks/arc063_a
s = input()
c = 0
for i in range(len(s) - 1):
	if s[i] != s[i + 1]: c += 1
print(c)
