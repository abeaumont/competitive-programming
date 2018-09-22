#!/usr/bin/env python3
from random import randint

t,m,n,q = 10,10000,10000,10000
print(t)
for _ in range(t):
    print(''.join([str(randint(0, 1)) for _ in range(m)]))
    print(''.join([str(randint(0, 1)) for _ in range(n)]))
    print(q)
    for _ in range(q):
        print(randint(1, n), randint(1, m))
