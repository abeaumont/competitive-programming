#!/usr/bin/env python3
# https://abc066.contest.atcoder.jp/tasks/arc077_a
n = int(input())
a = input().split()
b = [0] * n
for i in range(n % 2, n, 2):
    b[(n + i) // 2] = a[i]
for i in range(n - 1, -1, -2):
    b[(n - i - 1) // 2] = a[i]
print(' '.join(b))
