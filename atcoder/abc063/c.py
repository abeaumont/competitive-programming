#!/usr/bin/env python3
# https://abc063.contest.atcoder.jp/tasks/arc075_a
n = int(input())
a = [0] * n
ok = False
for i in range(n):
    a[i] = int(input())
    if a[i] % 10 != 0:
        ok = True
a.sort()
s = sum(a)
if s % 10 != 0: print(s)
elif not ok: print(0)
else:
    for x in a:
        if x % 10 != 0:
            print(s - x)
            break
