#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard/000000000003e068
for _ in range(int(input())):
    n = int(input())
    if n == -1: break
    p = [0] * n
    b = [False] * n
    for _ in range(n):
        a = [int(x) for x in input().split()]
        k = None
        c = None
        for x in a[1:]:
            p[x] += 1
            if b[x]: continue
            if k is None or p[x] < c:
                k = x
                c = p[x]
        if k is None: print(-1)
        else:
            b[k] = True
            print(k)
