#!/usr/bin/env python3
# https://arc094.contest.atcoder.jp/tasks/arc094_b
import math
for _ in range(int(input())):
    a, b = map(int, input().split())
    a, b = max(a, b), min(a, b)
    p = a * b
    x = int(math.sqrt(p - 1))
    while x * x >= p:
        x -= 1
    c = x * 2
    if x * (x + 1) >= p:
        c -= 1
    if a <= x:
        c -= 1
    if b <= x:
        c -= 1
    print(c)
