#!/usr/bin/env python3
# https://codeforces.com/contest/1058/problem/D
from math import gcd

n, m, k = map(int, input().split())
if k == 2:
    print('YES')
    print('0 0')
    print('{} 0'.format(n))
    print('0 {}'.format(m))
elif n*m*2%k==0:
    if k%2==0:
        k //= 2
        g = gcd(n,k)
        a = n//g
        b = m*g//k
    else:
        g = gcd(n,k)
        a = n//g
        b = m*g//k
        if a < n: a*=2
        else: b*=2
    print('YES')
    print('0 0')
    print('{} 0'.format(a))
    print('0 {}'.format(b))
else: print('NO')
