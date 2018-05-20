#!/usr/bin/env pypy3
import sys
sys.setrecursionlimit(20000)

n, k, l = map(int, input().split())
a = [list() for _ in range(n)]
b = [list() for _ in range(n)]
for _ in range(k):
    p, q = [int(x) - 1 for x in input().split()]
    a[p].append(q)
    a[q].append(p)
for _ in range(l):
    r, s = [int(x) - 1 for x in input().split()]
    b[r].append(s)
    b[s].append(r)

def g(a, b, i, k):
    b[i] = k
    for e in a[i]:
        if b[e] is not None: continue
        g(a, b, e, k)

def f(a, b):
    k = 0
    for i in range(n):
        if b[i] is not None: continue
        g(a, b, i, k)
        k += 1

c = [None] * n
f(a, c)
d = [None] * n
f(b, d)
e = {}
for i in range(n):
    k = (c[i], d[i])
    e[k] = e.get(k, 0) + 1

print(' '.join([str(e[(c[i], d[i])]) for i in range(n)]))
