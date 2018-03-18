#!/usr/bin/env python2
from random import randint
n = randint(1, 2000)
z = randint(1, 10**9)
w = randint(1, 10**9)
print n, z, w
print ' '.join([str(randint(1, 10**9)) for _ in xrange(n)])
