#!/usr/bin/env python3
# https://open.kattis.com/problems/crackingthecode
def check(x, d):
    if len(x) != len(d):
        return False
    m = dict()
    mi = dict()
    for a, b in zip(x, d):
        if a not in m:
            if b in mi:
                return False
            m[a] = b
            mi[b] = a
        elif m[a] != b:
            return False
    return True


def decrypt(xs, d):
    m = dict()
    mi = dict()
    for i in range(len(xs[0])):
        c = xs[0][i]
        for j in range(1, len(xs)):
            if xs[j][i] != c:
                c = None
                break
        if c is not None:
            m[c] = d[i]
            mi[d[i]] = m[c]
    if len(m) == 25:
        for i in range(26):
            c = chr(ord('a') + i)
            if c not in m:
                break
        for i in range(26):
            t = chr(ord('a') + i)
            if t not in mi:
                break
        m[c] = t
    return m


for _ in range(int(input())):
    n = int(input())
    xs = [input() for _ in range(n)]
    d = input()
    e = input()
    xs = [x for x in xs if check(x, d)]
    if len(xs) == 0:
        print('IMPOSSIBLE')
        continue
    m = decrypt(xs, d)
    print(''.join([m.get(c, '?') for c in e]))
