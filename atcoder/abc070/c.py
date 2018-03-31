#!/usr/bin/env python3
# https://abc070.contest.atcoder.jp/tasks/abc070_c
import fractions

n = int(input())
a = 1
for _ in range(n):
    x = int(input())
    a = (a * x) // fractions.gcd(a, x)
print(a)
