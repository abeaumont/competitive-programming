#!/usr/bin/env python2
# https://codeforces.com/contest/796/problem/A
[n, m, k] = map(int, raw_input().split(' '))
m = m - 1
p = map(int, raw_input().split(' '))
i = 1
while True:
    if m + i < len(p) and p[m + i] > 0 and p[m + i] <= k:
        print i * 10
        break
    if m - i >= 0 and p[m - i] > 0 and p[m - i] <= k:
        print i * 10
        break

    i += 1
