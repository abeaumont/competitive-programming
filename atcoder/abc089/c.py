#!/usr/bin/env python3
# https://abc089.contest.atcoder.jp/tasks/abc089_c
import itertools

n = int(input())
a = [0] * 26
for _ in range(n):
   a[ord(input()[0]) - ord('A')] += 1
c = []
for x in 'MARCH':
    c.append(a[ord(x) - ord('A')])
s = 0
for x in itertools.combinations(c, 3):
    k = 1
    for i in x: k *= i
    s += k
print(s)
