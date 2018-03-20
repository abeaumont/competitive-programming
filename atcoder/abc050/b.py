#!/usr/bin/env python3
# https://abc050.contest.atcoder.jp/tasks/abc050_b
_ = int(input())
t = [int(x) for x in input().split()]
s = sum(t)
for _ in range(int(input())):
	p, x = [int(x) for x in input().split()]
	print(s + x - t[p - 1])
