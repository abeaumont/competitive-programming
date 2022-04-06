#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45fc0
from random import randint

for _ in range(int(input())):
    n, k = map(int, input().split())
    r, p = map(int, input().split())
    s = p
    x = {}
    for _ in range(k//2):
        print('W')
        r, p = map(int, input().split())
        x[r] = p
        print(f'T {randint(1, n)}')
        r, p = map(int, input().split())
        s += p
    d = s / (k//2)
    ans = d * n
    for v in x.values():
        ans += v - d
    ans = int(ans / 2)
    print(f'E {ans}')
