#!/usr/bin/env python3
# https://abc050.contest.atcoder.jp/tasks/arc066_a
n = int(input())
a = [int(x) for x in input().split()]
d = {}
for x in a:
	d[x] = d.get(x, 0) + 1
ok = True
for i in range(1 + n % 2, n, 2):
	if i not in d or d[i] != 2:
		ok = False
		break
if ok: print(pow(2, n//2, 10**9+7))
else: print(0)
