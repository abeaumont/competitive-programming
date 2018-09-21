#!/usr/bin/env python2
from random import randint

t = 1
n = 10**1
q = 2 * 10**1
p = 104729

print t
for _ in range(t):
    ni = randint(1, n)
    qi = randint(1, q)
    print ni, p, qi
    print ' '.join([str(randint(1, p - 1)) for _ in range(ni)])
    b = qi // 64 + 2
    print ' '.join([str(randint(1, n - 1)) for _ in range(b)])
