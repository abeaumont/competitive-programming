#!/usr/bin/env pypy3

M = 10000000
cs = []
for i in range(1, 10):
    cs.append((i, i))
    cs.append((i, i+1))
c = len(cs)
a = [[0] * M for i in range(c)]
a = [[0] * M for i in range(c)]
for i, k in enumerate(cs):
    h, w = k
    a[i][0] = h*w
    x = h+w
    for j in range(1, M):
        a[i][j] = x*2 + 4
        x += 4


def count(ci, h):
    s = [h]
    d = -2
    while True:
        n = s[-1] + d
        s.append(n)
        if n == 1:
            s.append(2)
            break
        d = 1 if d == -2 else -2
    t = 0
    for i, x in enumerate(s):
        t += a[ci][i] * x
    return t


def solve(p):
    if p < 43:
        return 0, 0
    h = 0
    b = 1000000 // 2
    while b >= 1:
        while True:
            r = count(0, h + b)
            if r > p:
                break
            h += b
        b //= 2
    ci = 0
    while count(ci, h) <= p:
        ci += 1
    ci -= 1
    return h, ci


for i in range(int(input())):
    h, ci = solve(int(input()))
    if h < 3:
        print(f'Case #{i+1}: IMPOSSIBLE')
    else:
        print(f'Case #{i+1}: {h} {count(ci, h)}')
