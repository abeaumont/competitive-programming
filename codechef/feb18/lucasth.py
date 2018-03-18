#!/usr/bin/env python2
# https://www.codechef.com/FEB18/problems/LUCASTH
def s(n, mod):
    p = [0] * n
    p2 = [0] * n
    p[0] = 1
    for i in range(1, n):
        for j in range(1, i + 1):
            p2[j] = (p[j - 1] + (i - 1) * p[j]) % mod
        p = p2
        p2 = [0] * n
    return p

for _ in range(input()):
    n, p = map(int, raw_input().split())
    c = 0
    for x in s(n, p):
        if x: c += 1
    print c
