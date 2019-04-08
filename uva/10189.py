#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/101/10189.pdf
import sys

field = 1
first = True
while True:
    [m, n] = map(int, input().split())
    if m == 0 and n == 0: break
    if first: first = False
    else: print()
    board = [input() for _ in range(m)]
    def count(y, x):
        c = 0
        for i in range(max(y - 1, 0), min(y + 2, m)):
            for j in range(max(x - 1, 0), min(x + 2, n)):
                if board[i][j] == '*':
                    c += 1
        return c

    print('Field #{}:'.format(field))
    field += 1
    for i in range(m):
        for j in range(n):
            if board[i][j] == '*':
                sys.stdout.write('*')
            else:
                sys.stdout.write(str(count(i, j)))
        print()
