#!/usr/bin/env python3
# https://www.codechef.com/SNCK1A19/problems/TYPING
cs = {'d': True, 'f': True, 'j': False, 'k': False}
for _ in range(int(input())):
    ws = set()
    s = 0
    for _ in range(int(input())):
        w = input()
        c = 0
        for i, k in enumerate(w):
            c += 2 if i == 0 or cs[w[i-1]] != cs[k] else 4
        if w in ws: c //= 2
        s += c
        ws.add(w)
    print(s)
