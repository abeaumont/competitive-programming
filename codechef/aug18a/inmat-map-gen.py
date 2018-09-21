#!/usr/bin/env python3
n = 1000
c = 1
for i in range(n//3):
    x = []
    for j in range(n):
        x.append(c)
        c += 1
    print(' '.join([str(i) for i in x]))
    x = []
    for j in range(n):
        x.append(c)
        c += 1
    print(' '.join([str(i) for i in x]))
    x = [0] * n
    for j in range(n - 1, -1, -1):
        x[j] = c
        c += 1
    print(' '.join([str(i) for i in x]))
x = []
for j in range(n):
    x.append(c)
    c += 1
print(' '.join([str(i) for i in x]))
