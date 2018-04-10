#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
# Bruteforce solution
for t in range(1, int(input()) + 1):
    n = int(input())
    l = [int(x) for x in input().split()]
    d = False
    while not d:
        d = True
        for i in range(len(l) - 2):
            if l[i] > l[i + 2]:
                l[i], l[i + 2] = l[i + 2], l[i]
                d = False
    k = None
    for i in range(len(l) - 1):
        if l[i] > l[i + 1]:
            k = i
            break
    print('Case #{}: {}'.format(t, 'OK' if k is None else k))
