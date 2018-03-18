#!/usr/bin/env python2
i = 1
while True:
    n = input()
    if n == 0: break
    d = {}
    for _ in xrange(n):
        x = raw_input().split()[-1].lower()
        d[x] = d.get(x, 0) + 1
    print 'List {}:'.format(i)
    for k in sorted(d.keys()):
        print '{} | {}'.format(k, d[k])
    i += 1
