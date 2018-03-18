#!/usr/bin/env python2
# https://open.kattis.com/problems/natrij
xs = [raw_input() for _ in range(2)]
xs = map(lambda x: map(int, x.split(':')), xs)
[a, b] = map(lambda x: x[0] * 3600 + x[1] * 60 + x[2], xs)
if a >= b:
    b += 24 * 60 * 60
d = b - a
h = d / (60 * 60)
ms = d - (h * 60 * 60)
m = ms / 60
s = ms % 60
print '{}:{}:{}'.format(str(h).zfill(2), str(m).zfill(2), str(s).zfill(2))
