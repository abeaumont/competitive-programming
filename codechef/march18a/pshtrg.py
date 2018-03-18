#!/usr/bin/env python2
# https://www.codechef.com/MARCH18A/problems/PSHTRG
n, q = map(int, raw_input().split())
a = map(int, raw_input().split())
for _ in range(q):
    t, l, r = map(int, raw_input().split())
    l -= 1
    if t == 1:
        a[l] = r
    else:
        x = a[l:r]
        x.sort(reverse=True)
        z = 0
        for i in range(2, len(x)):
            if x[i - 2] < x[i - 1] + x[i]:
                z = sum(x[i - 2:i + 1])
                break
        print z
