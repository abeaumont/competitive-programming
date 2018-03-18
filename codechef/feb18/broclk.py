#!/usr/bin/env python2
# https://www.codechef.com/FEB18/problems/BROCLK
mod = 1000000007

def modinv(a):
    b, x0, x1 = mod, 0, 1
    while a > 1:
	q, a, b = a / b, b, a % b
        x0, x1 = x1 - q * x0, x0
    return x1

def chevyshev(n, p):
    a, b = 1, p
    for _ in xrange(n - 1): b, a = 2 * p * b - a, b
    return b

for _ in range(input()):
    l, d, t = map(int, raw_input().split())
    x = d * modinv(l)
    print chevyshev(t, x) * l % mod
