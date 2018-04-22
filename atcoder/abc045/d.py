#!/usr/bin/env pypy3
# https://abc045.contest.atcoder.jp/tasks/arc061_b
h, w, n = map(int, input().split())
a = [None] * n
s = set()
for i in range(n):
    y, x = map(int, input().split())
    a[i] = (y - 1, x - 1)
    s.add((y -1 , x - 1))
t = set()
e = [0] * 10
c = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
d = [-1, 0, 1, -1, 0, 1, -1, 0, 1]
for i in range(n):
    y, x = a[i]
    for j in range(9):
        y2 = y + c[j]
        x2 = x + d[j]
        if y2 <= 0 or x2 <= 0 or y2 >= h - 1 or x2 >= w - 1: continue
        z = 0
        if (y2, x2) in t: continue
        t.add((y2, x2))
        for k in range(9):
            y3 = y2 + c[k]
            x3 = x2 + d[k]
            if (y3, x3) in s: z += 1
        e[z] += 1
print(((h - 2) * (w - 2)) - sum(e))
for i in range(1, 10): print(e[i])
