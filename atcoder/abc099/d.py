#!/usr/bin/env pypy3
# https://abc099.contest.atcoder.jp/tasks/abc099_d
n, k = map(int, input().split())
c, d = [0] * n, [0] * k
for i in range(k): d[i] = [int(x) for x in input().split()]
for i in range(n): c[i] = [int(x) - 1 for x in input().split()]
z = {}
def f(k, m):
    if (k, m) in z: return z[(k, m)]
    s = 0
    for i in range(n):
        for j in range(n):
            if (i + j) % 3 == m:
                s += d[c[i][j]][k]
    z[(k, m)] = s
    return s
def g(i, s):
    if i == 3: return 0
    m = None
    for l in range(k):
        if s[l]: continue
        s[l] = True
        r = g(i + 1, s)
        s[l] = False
        if r is None: continue
        r += f(l, i)
        if m is None or r < m: m = r
    return m
print(g(0, [False] * k))
