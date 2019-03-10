#!/usr/bin/env python3
# https://atcoder.jp/contests/arc100/tasks/arc100_a
n = int(input())
a = [int(x) - i - 1 for i, x in enumerate(input().split())]
a.sort()
m = a[(n - 1)//2]
s = 0
for x in a: s += abs(x - m)
print(s)
