#!/usr/bin/env python3
# https://codeforces.com/contest/1040/problem/A
n, a, b = map(int, input().split())
p = [a,b,min(a, b)]
c = [int(x) for x in input().split()]
s = 0
d = n // 2
if n % 2:
    s += p[c[d]] if c[d] == 2 else 0
    j = d + 1
else:
    j = d
i = d - 1
while i >= 0:
    if c[i] == c[j]:
        if c[i] == 2: s += 2*p[c[i]]
    elif c[j] == 2: s += p[c[i]]
    elif c[i] == 2: s += p[c[j]]
    else:
        s = -1
        break
    i-=1
    j+=1
print(s)
