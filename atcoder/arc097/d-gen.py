#!/usr/bin/env python3
import random

n = 10**5
m = 10**5
print(n, m)
x = list(range(1, n + 1))
random.shuffle(x)
print(' '.join([str(i) for i in x]))
s = set()
for _ in range(m):
    x = random.randint(1, n)
    y = random.randint(1, n)
    while x == y: y = random.randint(1, n)
    while (x, y) in s:
        x = random.randint(1, n)
        y = random.randint(1, n)
        while x == y: y = random.randint(1, n)
    s.add((x, y))
    print(x, y)
