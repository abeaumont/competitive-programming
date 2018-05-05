#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard
def f(a, b, l, t, i):
    if i == l:
        x = ''.join(t)
        if x not in a: return x
        return
    for c in b[i]:
        t.append(c)
        x = f(a, b, l, t, i + 1)
        if x is not None: return x
        t.pop()

for T in range(int(input())):
    n, l = map(int, input().split())
    a = [input() for _ in range(n)]
    b = [set() for _ in range(l)]
    for i in range(l):
        for j in range(n):
            b[i].add(a[j][i])
    p = 1
    for i in range(l): p *= len(b[i])
    if p == n: print('Case #{}: {}'.format(T + 1, '-'))
    else: print('Case #{}: {}'.format(T + 1, f(a, b, l, [], 0)))
