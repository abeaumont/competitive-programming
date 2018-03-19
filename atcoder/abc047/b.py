#!/usr/bin/env python3
# https://abc047.contest.atcoder.jp/tasks/abc047_b
w, h, n = [int(x) for x in input().split()]
xm, xM, ym, yM = 0, w, 0, h
for _ in range(n):
	x, y, a = [int(x) for x in input().split()]
	if a == 1: xm = max(xm, x)
	elif a == 2: xM = min(xM, x)
	elif a == 3: ym = max(ym, y)
	else: yM = min(yM, y)
if yM > ym and xM > xm: print((xM - xm) * (yM - ym))
else: print(0)
