#!/usr/bin/env python2
# https://codeforces.com/contest/897/problem/B
k, p = map(int, raw_input().split())
sum = 0
for i in range(1, k + 1):
    s = str(i)
    s = s + s[::-1]
    sum = (sum + int(s)) % p
    i += 1
print sum
