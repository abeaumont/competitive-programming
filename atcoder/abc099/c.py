#!/usr/bin/env pypy3
# https://abc099.contest.atcoder.jp/tasks/abc099_c
n = int(input())
k = [0] * (n + 1)
for i in range(min(n + 1, 6)): k[i] = i
for i in range(6, n + 1):
    m = k[i - 1] + 1
    for j in range(1, 8):
        l = pow(6, j)
        if l > i: break
        m = min(m, k[i - l] + 1)
    for j in range(1, 8):
        l = pow(9, j)
        if l > i: break
        m = min(m, k[i - l] + 1)
    k[i] = m
print(k[n])
