#!/usr/bin/env python2
# https://open.kattis.com/problems/server
def count(xs, t):
    s = 0
    for i, x in enumerate(xs):
        if x + s > t:
            return i
        s += x
    return len(xs)

t = int(raw_input().split()[1])
xs = map(int, raw_input().split())
print count(xs, t)
