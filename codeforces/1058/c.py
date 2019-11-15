#!/usr/bin/env python3
# https://codeforces.com/contest/1058/problem/C
n = int(input())
d = [int(x) for x in input()]
s = sum(d)
y = s == 0
for i in range(2,s+1):
    if y == True: break
    if s%i == 0:
        k = s//i
        c = 0
        ok = True
        for x in d:
            c += x
            if c > k:
                ok = False
                break
            if c == k:
                c = 0
        if ok:
            y = True
print('YES' if y else 'NO')
