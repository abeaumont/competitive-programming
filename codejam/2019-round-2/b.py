#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/00000000001461c8

for _ in range(int(input())):
    x = [None] * 20
    s = set()
    o = 0
    e = None
    while True:
        d = int(input())
        if d == -1:
            import sys; sys.exit(0)
        if d < 20:
            print('{} 100'.format(d))
        elif d < 90:
            while o in s:
                o = (o + 1) % 20
            v = o + 1
            print('{} {}'.format(v, 0))
            x[o] = len(input().split()) - 1
            if (x[o] >= 5):
                s.add(o)
            o  = (o + 1) % 20
        elif d < 100:
            if e is None:
                m = 101
                for i, v in enumerate(x):
                    if v < m:
                        m = v
                        e = i
                s.add(e)
            m, k = 101, None
            for i, v in enumerate(x):
                if v < m and i != e:
                    m = v
                    k = i
            print('{} {}'.format(k + 1, 100))
            x[k] += 1
            if x[k] >= 5:
                s.add(k)
        else:
            print('{} 100'.format(20))
        if d == 100:
            break
