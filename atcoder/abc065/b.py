#!/usr/bin/env python3
# https://abc065.contest.atcoder.jp/tasks/abc065_b
n = int(input())
a = [0] * n
for i in range(n): a[i] = int(input()) - 1
i = 0
c = 1
ok = False
s = set()
while a[i] != 1:
    c += 1
    if i in s:
        c = -1
        break;
    s.add(i)
    i = a[i]
print(c)
