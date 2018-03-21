#!/usr/bin/env python3
import random
t = random.randint(1, 10)
print(t)
for _ in range(t):
    h = random.randint(2, 200)
    c = random.randint(2, h)
    print(h, c)
    x = [random.randint(0, 10**6) for _ in range(h)]
    x.sort()
    print(' '.join([str(k) for k in x]))