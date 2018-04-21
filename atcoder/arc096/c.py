#!/usr/bin/env python3
# https://arc096.contest.atcoder.jp/tasks/arc096_a
a, b, c, x, y = map(int, input().split())
d = min(x, y)
e = max(x, y) - d
s = 0
if a + b <= 2 * c: s += d * (a + b)
else: s += d * c * 2
if x > y:
    if a <= 2 * c: s += e * a
    else: s += e * 2 * c
else:
    if b <= 2 * c: s += e * b
    else: s += e * 2 * c
print(s)
