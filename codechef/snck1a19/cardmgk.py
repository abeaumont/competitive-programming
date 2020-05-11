#!/usr/bin/env python3
# https://www.codechef.com/SNCK1A19/problems/CARDMGK
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    k = 0
    m = a[0]
    for i in range(n):
        if a[i] < m:
            k = i
            m = a[i]
    p = m
    l = 0
    for i in range(n):
        if a[(i+k)%n] >= p: p = a[(i+k)%n]
        else: break
        l = i
    ok = True
    for i in range(l+1, n):
        if a[(i+k)%n] != m:
            ok = False
            break
    print('YES' if ok else 'NO')
