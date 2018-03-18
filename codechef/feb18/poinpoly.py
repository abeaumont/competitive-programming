#!/usr/bin/env python2
# https://www.codechef.com/FEB18/problems/POINPOLY
for _ in range(input()):
    n = input()
    p = [None] * n
    par = {
        (0, 0): [],
        (0, 1): [],
        (1, 0): [],
        (1, 1): []
    }
    for i in range(n):
        x, y = map(int, raw_input().split())
        p[i] = (x, y)
        par[(abs(x) % 2, abs(y) % 2)].append(i)
    m = par[(0, 1)]
    for v in par.values():
        if len(v) > len(m): m = v
    i = 0
    r = set()
    for i, a in enumerate(m):
        for j in range(i + 1, len(m)):
            b = m[j]
            if a + 1 == b: continue
            if a == 0 and b == n - 1: continue
            r.add(((p[a][0] + p[b][0]) / 2, (p[a][1] + p[b][1]) / 2))
            if len(r) == n / 10: break
        if len(r) == n / 10: break
    for x, y in r:
        print x, y
