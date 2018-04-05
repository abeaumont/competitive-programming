#!/usr/bin/env python3
# https://abc044.contest.atcoder.jp/tasks/arc060_a
n, a = map(int, input().split())
x = [int(i) for i in input().split()]
cache = {}
def s(v, k, i):
    if i == n: return int(v > 0 and v == k * a)
    if v > a * n: return 0
    key = (v, k, i)
    if key in cache: return cache[key]
    cache[key] = s(v, k, i + 1) + s(v + x[i], k + 1, i + 1)
    return cache[key]

print(s(0, 0, 0))
