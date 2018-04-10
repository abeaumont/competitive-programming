#!/usr/bin/env python3
# http://codeforces.com/contest/960/problem/C
import math

x, d = map(int, input().split())
a = []
while True:
    k = int(math.log2(x))
    a.append(k)
    x -= 2 ** k - 1
    if x == 1:
        a.append(1)
        break
k = 1
b = []
for x in a:
    for _ in range(x):
        b.append(str(k))
    k += d
print(len(b))
print(' '.join(b))
