#!/usr/bin/env python3
# https://www.codechef.com/JAN20A/problems/DYNAMO
for _ in range(int(input())):
    n = int(input())
    a = int(input())
    p = 10**n
    s = 2*p+a
    print(2*p+a)
    b = int(input())
    print(p-b)
    d = int(input())
    print(p-d)
    r = int(input())
    if r == -1:
        quit()
