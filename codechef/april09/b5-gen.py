#!/usr/bin/env python3
from random import randint
n = 1000
k = 100
print('{} {}'.format(n, k))
for _ in range(n):
    print(' '.join([str(randint(0, 2**32)) for _ in range(n)]))
