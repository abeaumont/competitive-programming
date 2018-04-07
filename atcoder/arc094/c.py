#!/usr/bin/env python3
# https://arc094.contest.atcoder.jp/tasks/arc094_a
a, b, c = map(int, input().split())
m = max([a, b, c])
x = [m - i for i in [a, b, c]]
x.sort(reverse=True)
d = x[0] + x[1]
if d % 2 == 0: print(d // 2)
else: print((d + 1) // 2 + 1)

