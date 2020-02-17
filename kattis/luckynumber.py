#!/usr/bin/env python3
# https://open.kattis.com/problems/luckynumber
n = int(input())
a = list(range(1, 10))
b = []
for i in range(2, n+1):
    for x in a:
        y = x * 10
        while y % i != 0: y += 1
        for z in range(y, (x+1)*10, i):
            b.append(z)
    a = b
    b = []
print(len(a))
