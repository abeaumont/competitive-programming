#!/usr/bin/env python3
# https://abc065.contest.atcoder.jp/tasks/arc076_a
M = 10**9 + 7
def f(n):
    x = 1
    for i in range(1, n + 1):
        x = x * i % M
    return x

n, m = map(int, input().split())
if n == m:
    x = f(n)
    print(2 * x * x % M)
elif abs(m - n) == 1:
    a = min(m, n)
    x = f(a)
    print(x * x * (a + 1) % M)
else: print(0)
