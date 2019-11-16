#!/usr/bin/env python3
# https://codeforces.com/contest/805/problem/B
def f(n):
    return ('aabb' * ((n + 4) // 4))[:n]

print(f(int(input())))
