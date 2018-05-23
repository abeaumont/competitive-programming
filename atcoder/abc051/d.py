#!/usr/bin/env python3
# https://abc051.contest.atcoder.jp/tasks/abc051_d
INF = 10 ** 9

n, m = map(int, input().split())
a = [[INF] * n for _ in range(n)]
e = [None] * m
for i in range(n): a[i][i] = 0
for i in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    e[i] = (u, v, w)
    a[u][v] = w
    a[v][u] = w
for k in range(n):
    for i in range(n):
        for j in range(n):
            a[i][j] = min(a[i][j], a[i][k] + a[k][j])
c = 0
for u, v, w in e:
    if a[u][v] != w: c += 1
print(c)
