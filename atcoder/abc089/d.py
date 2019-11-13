#!/usr/bin/env python3
# https://atcoder.jp/contests/abc089/tasks/abc089_d
h, w, d = map(int, input().split())
x = [None] * h * w
y = [[0] for _ in range(d)]
for i in range(h):
    r = [int(x) for x in input().split()]
    for j in range(w):
        x[r[j] - 1] = (i, j)
for i in range(d):
    for j in range(i + d, h * w, d):
        y[i].append(abs(x[j][0] - x[j - d][0]) + abs(x[j][1] - x[j - d][1]))
        y[i][-1] += y[i][-2]
for _ in range(int(input())):
    l, r = [int(x) - 1 for x in input().split()]
    m = l % d
    print(y[m][r // d] - y[m][l // d])
