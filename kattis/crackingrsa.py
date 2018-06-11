#!/usr/bin/env python3
# https://open.kattis.com/problems/crackingrsa
def d(x):
    for i in range(2, x):
        if i * i > x: break
        if x % i == 0: return i
    return None

def modinv(a, b):
    m = b
    if b == 1: return 1
    x0, x1 = 0, 1
    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    while x1 < 0: x1 += m
    return x1

for _ in range(int(input())):
    n, e = map(int, input().split())
    p = d(n)
    q = n // p
    print(modinv(e, (p - 1) * (q - 1)))