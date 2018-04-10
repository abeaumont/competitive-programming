#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
# Input generator
import random
t = 100
print(t)
for i in range(t):
    n = random.randint(3, 100)
    print(n)
    print(' '.join([str(random.randint(0, 100)) for j in range(n)]))
