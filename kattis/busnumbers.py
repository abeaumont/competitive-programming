#!/usr/bin/env python2
# https://open.kattis.com/problems/busnumbers
raw_input()
xs = map(int, raw_input().split())
xs.sort()
i = 0
ss = []
while i < len(xs):
    j = 0
    while i + j < len(xs):
        if xs[i + j] == xs[i] + j:
            j += 1
        else:
            break
    if j > 2:
        ss.append('{}-{}'.format(xs[i], xs[i+j-1]))
    else:
        ss.append(' '.join(map(str, xs[i:i+j])))
    i += j
print ' '.join(ss)
