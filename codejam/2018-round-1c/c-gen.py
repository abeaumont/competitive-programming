#!/usr/bin/env python3
import random

t = 100
print(t)
for _ in range(t):
    n = 10000
    print(n)
    print(' '.join([str(random.randint(1, 1000)) for _ in range(n)]))
