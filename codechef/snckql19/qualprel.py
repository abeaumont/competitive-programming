#!/usr/bin/env python3
# https://www.codechef.com/SNCKQL19/problems/QUALPREL
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    if n <= k:
        print(n)
        continue
    a.sort(reverse=True)
    b = a[k-1]
    while k < n and a[k] == b: k += 1
    print(k)
