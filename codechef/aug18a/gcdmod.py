#!/usr/bin/env python3
# https://www.codechef.com/AUG18A/problems/GCDMOD
import math

M = 10**9+7

for _ in range(int(input())):
    a, b, n = map(int, input().split())
    if a == b: print(pow(a, n) * 2 % M)
    else: print(math.gcd(pow(a, n, a - b) + pow(b, n, a - b), (a - b)) % M)
