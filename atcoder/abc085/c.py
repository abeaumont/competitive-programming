#!/usr/bin/env python2
# https://abc085.contest.atcoder.jp/tasks/abc085_c
import sys

[n, y] = map(int, raw_input().split())
a = 0
b = 0
c = y // 1000
d = c - n
if n > c:
    print -1, -1, -1
    sys.exit(0)
if d >= 4:
    k = d // 4
    k = min(k, c // 5)
    b += k
    c -= k * 5
    d -= k * 4
if d * 2 > b:
    print -1, -1, -1
    sys.exit(0)
b -= 2 * d
a += d
print a, b, c
