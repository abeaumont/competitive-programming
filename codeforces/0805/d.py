#!/usr/bin/env python3
# https://codeforces.com/contest/805/problem/D
s = input().strip()
l = len(s)
b = 0
op = 0
for i in range(l - 1, -1, -1):
    if s[i] == 'b':
        b += 1
    elif b > 0:
        op += b
        b = b * 2 % (pow(10, 9) + 7)
print(op % (pow(10, 9) + 7))
