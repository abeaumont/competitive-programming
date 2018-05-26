#!/usr/bin/env python3
# https://arc098.contest.atcoder.jp/tasks/arc098_a
n = int(input())
s = input()
a = [0] * n
if s[0] == 'W': a[0] = 1
for i in range(1, n):
    c = s[i]
    if c == 'E':
        a[i] = a[i - 1]
    else:
        a[i] = a[i - 1] + 1
b = [0] * n
if s[n - 1] == 'E': b[n - 1] = 1
for i in range(n - 2, -1, -1):
    c = s[i]
    if c == 'W':
        b[i] = b[i + 1]
    else:
        b[i] = b[i + 1] + 1
m = n
for i in range(n):
    m = min(m, a[i] + b[i])
print(m - 1)
