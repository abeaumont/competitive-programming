#!/usr/bin/env python3
import sys
from random import randint

m = []
with open(sys.argv[1]) as f:
    for l in f:
        m.append([int(x) for x in l.split()])
n = len(m)
y = randint(0, n - 1)
x = randint(0, n - 1)
y = n - 1
x = 0
print('{} {} {}'.format(n, 0, m[y][x]))
k = 0
while True:
    c, i, j = map(int, input().split())
    i -= 1
    j -= 1
    if c == 2:
        if i == y and x == j:
            if k <= n * 4: print('OK in {}'.format(k))
            else: print('FAIL OK in {}'.format(k))
        else: print('FAIL')
        break
    k += 1
    print(m[i][j])
