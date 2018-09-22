#!/usr/bin/env python3
# https://www.codechef.com/SEPT18A/problems/TABGAME
# Only for subtask #1
import sys
for _ in range(int(input())):
    m = input()
    n = input()
    a = [[None]*len(n) for _ in range(len(m))]
    a[0][0] = m[0]=='0' or n[0]=='0'
    for i in range(1, len(n)):
        a[0][i] = n[i]=='0' or not a[0][i-1]
    for i in range(1, len(m)):
        a[i][0] = m[i]=='0' or not a[i-1][0]
    for i in range(1, len(m)):
        for j in range(1, len(n)):
            a[i][j] = not a[i-1][j] or not a[i][j-1]
    for _ in range(int(input())):
        x, y = map(int, input().split())
        sys.stdout.write('1' if a[y-1][x-1] else '0')
    print('')
        
