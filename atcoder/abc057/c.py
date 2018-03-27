#!/usr/bin/env python3
# https://abc057.contest.atcoder.jp/tasks/abc057_c
import math

n = int(input())
m = 0
for i in range(1, int(math.sqrt(n) + 1)):
    if n % i == 0:
        m = max(m, i)
m = n // m
c = 0
while m > 0:
    m //= 10
    c += 1
print(c)
