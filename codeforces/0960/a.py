#!/usr/bin/env python3
# http://codeforces.com/contest/960/problem/A
s = input()
a = [0] * 3
k = 0
ok = True
for i in s:
    c = ord(i) - ord('a')
    if c == k:
        a[k] += 1
    elif c == k + 1:
        k += 1
        a[k] += 1
    else:
        ok = False
        break
if a[0] == 0 or a[1] == 0 or (a[0] != a[2] and a[1] != a[2]):
    ok = False
if ok: print('YES')
else: print('NO')
