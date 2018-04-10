#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30
import sys

for _ in range(int(input())):
    a = int(input())
    b = (a - 1) // 3 + 1
    m = [None] * 3
    for i in range(3): m[i] = [False] * b
    i = 1
    while True:
        print(i + 1, 2)
        sys.stdout.flush()
        x, y = map(int, input().split())
        if x == -1 and y == -1: sys.exit(0)
        if x == 0 and y == 0: break
        m[y - 1][x - 1] = True
        while i < b - 2:
            ok = True
            for j in range(3):
                if not m[j][i - 1]:
                    ok = False
                    break
            if ok: i += 1
            else: break
