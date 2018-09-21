#!/usr/bin/env python2
# https://www.codechef.com/NOV17/problems/SEGPROD/
for _ in range(input()):
    n, p, q = map(int, raw_input().split())
    v = map(int, raw_input().split())
    b = q // 64 + 2
    w = map(int, raw_input().split())
    x = 0
    for i in range(q):
        if i % 64 == 0:
            l = (w[i // 64] + x) % n
            r = (w[i // 64 + 1] + x) % n
        else:
            l = (l + x) % n
            r = (r + x) % n
        if l > r: l, r = r, l
        x = 1
        for j in range(l, r + 1):
            x *= v[j]
        x += 1
        x = x % p
    print x
