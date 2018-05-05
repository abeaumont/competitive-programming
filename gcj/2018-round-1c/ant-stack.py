#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e0a8
# This solution is too slow even for the small input. Check the C++ solution instead
import sys
sys.setrecursionlimit(10000)

inf = 10**10

dp = None
a = None

def s(i, w):
    if i < 0: return 0
    if (i, w) in dp: return dp[(i, w)]
    m = s(i - 1, w)
    if a[i] <= w: m = max(m, 1 + s(i - 1, min(w - a[i], a[i] * 6)))
    dp[(i, w)] = m
    return m

for T in range(int(input())):
    dp = dict()
    n = int(input())
    a = [int(x) for x in input().split()]
    print('Case #{}: {}'.format(T + 1, s(n - 1, inf)))
