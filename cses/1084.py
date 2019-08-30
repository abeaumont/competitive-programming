#!/usr/bin/env python3
# https://cses.fi/problemset/task/1084
f = lambda: map(int, input().split())
n, m, k = f()
a = sorted(f())
b = sorted(f())
i, j, c = 0, 0, 0
while i < n and j < m:
    if a[i] + k < b[j]: i += 1
    elif a[i] - k > b[j]: j += 1
    else: i += 1; j += 1; c += 1
print(c)
