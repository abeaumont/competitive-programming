#!/usr/bin/env python3
# https://open.kattis.com/problems/helpaphd
n = int(input())
for _ in range(n):
    x = input()
    if x[0] == 'P':
        print('skipped')
    else:
        print(eval(x))
