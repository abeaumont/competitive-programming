#!/usr/bin/env python3
# https://www.codechef.com/SEPT18A/problems/TABGAME
import sys
for _ in range(int(input())):
    m = input()
    n = input()
    a = [[None]*min(len(n), 3) for _ in range(len(m))]
    b = [[None]*len(n) for _ in range(min(len(m), 3))]
    s = set()
    a[0][0] = b[0][0] = m[0]=='0' or n[0]=='0'
    if not a[0][0]: s.add(0)
    for i in range(1, len(m)):
        a[i][0] = m[i]=='0' or not a[i-1][0]
        if not a[i][0]: s.add(i)
    for i in range(1, min(len(n), 3)):
        a[0][i] = n[i]=='0' or not a[0][i-1]
        if not a[0][i]: s.add(-i)
    for i in range(1, len(m)):
        for j in range(1, min(len(n), 3)):
            a[i][j] = not a[i-1][j] or not a[i][j-1]
            if not a[i][j]: s.add(i-j)
    for i in range(1, len(n)):
        b[0][i] = n[i]=='0' or not b[0][i-1]
        if not b[0][i]: s.add(-i)
    for i in range(1, min(len(m), 3)):
        b[i][0] = m[i]=='0' or not b[i-1][0]
        if not b[i][0]: s.add(i)
    for i in range(1, min(len(m), 3)):
        for j in range(1, len(n)):
            b[i][j] = not b[i-1][j] or not b[i][j-1]
            if not b[i][j]: s.add(i-j)
    for _ in range(int(input())):
       x, y = map(int, input().split())
       if x <= min(len(n), 3): v = '1' if a[y-1][x-1] else '0'
       elif y <= min(len(m), 3): v = '1' if b[y-1][x-1] else '0'
       else: v = '0' if y-x in s else '1'
       sys.stdout.write(v)
    print('')
