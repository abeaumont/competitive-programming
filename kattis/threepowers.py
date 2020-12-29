#!/usr/bin/env python3
# https://open.kattis.com/problems/threepowers
while True:
    n = int(input())
    if n == 0:
        break
    if n == 1:
        print('{ }')
    else:
        print('{ ' + ', '.join(str(3 ** i) for i in range(64) if (n - 1) & (1 << i)) + ' }')
