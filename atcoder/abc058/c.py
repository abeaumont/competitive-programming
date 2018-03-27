#!/usr/bin/env python3
# https://abc058.contest.atcoder.jp/tasks/arc071_a
n = int(input())
s = [0] * n
for i in range(n):
    s[i] = input()
d = [0] * 26
for c in s[0]:
    d[ord(c) - ord('a')] += 1
for i in range(1, n):
    e = [0] * 26
    for c in s[i]:
        e[ord(c) - ord('a')] += 1
    for i in range(26):
        d[i] = min(d[i], e[i])
x = []
for i, k in enumerate(d):
    x.extend(chr(ord('a') + i) * k)
print(''.join(x))
