#!/usr/bin/env python3
# https://abc067.contest.atcoder.jp/tasks/arc078_a
n = int(input())
a = [int(x) for x in input().split()]
s = sum(a)
b = a[0]
m = abs(s - 2 * b)
for i in range(1, n - 1):
    b += a[i]
    m = min(m, abs(s - 2 * b))
print(m)
