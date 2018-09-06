#!/usr/bin/env python3
import sys
import random

def p(x, y):
    print('{} {}'.format(x, y))
    sys.stdout.flush()

n, k = map(int, input().split())
l, r = 1, n
while True:
    if r - l <= 50:
        x = random.randint(l, r)
        p(x, x)
        a = input()
        if a == 'Yes' or a == 'Bad': break
        l = max(1, l - k)
        r = min(n, r + k)
    else:
        m = (l + r) // 2
        p(l, m)
        a = input()
        if a == 'Bad': break
        if a == 'Yes':
            l = max(1, l - k)
            r = min(n, m + k)
        else:
            l = max(1, m - k)
            r = min(n, r + k)
