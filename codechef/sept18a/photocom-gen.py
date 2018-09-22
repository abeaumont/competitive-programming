#!/usr/bin/env pypy3
from random import randint

t = 1
m = 10**6
print(t)
for _ in range(t):
    h1, h2 = randint(1, m), randint(1, m)
    w1, w2 = randint(1, m), randint(1, m)
    w1, w2 = m//h1, m//h2
    print('{} {}'.format(h1, w1))
    print(''.join([str(randint(0, 1)) for _ in range(h1*w1)]))
    print('{} {}'.format(h2, w2))
    print(''.join([str(randint(0, 1)) for _ in range(h2*w2)]))
