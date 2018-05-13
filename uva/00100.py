#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/1/100.pdf
from functools import reduce

def collatz(n):
    i = 1
    while n > 1:
        if n % 2: n = n * 3 + 1
        else: n >>= 1
        i += 1
    return i

while True:
    try:
        line = input()
    except:
        break
    a, b = map(int, line.split())
    print(a, b, reduce(lambda x, y: max(x, collatz(y)), range(min(a, b), max(a, b) + 1), collatz(a)))
