#!/usr/bin/env python3
# https://abc044.contest.atcoder.jp/tasks/arc060_b
import math

n = int(input())
s = int(input())
f = None
for i in range(2, math.ceil(math.sqrt(n))):
    c = 0
    k = n
    while k > 0:
        c += k % i
        k //= i
    if c == s:
        f = i
        break
if f is None:
    for i in range(int(math.sqrt(n)), 1, -1):
        b = n // i
        k = n
        c = 0
        while k > 0:
            c += k % b
            k //= b
        if s >= c and (s - c) % i == 0 and b - (s - c) // i > n // (i + 1):
            f = b - (s - c) // i
            break
if f is None:
    if s == n: f = n + 1
    elif s <= (n + 1) // 2: f = n - s + 1
    elif s == 1: f = n
if f is None: print(-1)
else: print(f)
