#!/usr/bin/env python3
# https://open.kattis.com/problems/trip
import math

while True:
    n = int(input())
    if n == 0:
        break
    values = [float(input()) for _ in range(n)]
    s = sum(values)
    t1 = math.ceil(100 * s / n) / 100
    t2 = int(100 * s / n) / 100
    z1, z2 = 0, 0
    for v in values:
        if v >= t1:
            z1 += v - t1
        else:
            z2 += t2 - v
    print('${:.2f}'.format(max(z1, z2)))
