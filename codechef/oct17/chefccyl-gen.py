#!/usr/bin/env python2
import random

t = 1
n = 5
l = 5
q = 50

print(t)
for _ in range(t):
    print n, q
    ls = []
    for _ in range(n):
        s = random.randint(1, l)
        ls.append(s)
        print ' '.join([str(s)] + [str(random.randint(1, 10**4)) for _ in range(s)])
    for i in range(n):
        print random.randint(1, ls[i]), random.randint(1, ls[(i + 1) % n]), random.randint(1, 10**3)
    for _ in range(q):
        c1 = random.randint(1, n)
        c2 = random.randint(1, n)
        while c1 == c2:
            c2 = random.randint(1, n)
        v1 = random.randint(1, random.randint(1, ls[c1 - 1]))
        v2 = random.randint(1, random.randint(1, ls[c2 - 1]))
        print v1, c1, v2, c2
            
            
        
