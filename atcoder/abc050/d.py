#!/usr/bin/env python3
# https://abc050.contest.atcoder.jp/tasks/arc066_b
cache = {}
M = 10**9+7
def f(i):
    if i == 0: return 0
    if i == 1: return 1
    if i in cache: return cache[i]
    k = i//2
    if i % 2 == 0: cache[i] = 2*f(k)%M + f(k-1)%M
    else: cache[i] = 2*f(k)%M + f(k+1)%M
    cache[i] %= M
    return cache[i]
print(f(int(input())+1))
