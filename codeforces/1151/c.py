#!/usr/bin/env python3
# https://codeforces.com/contest/1151/problem/C
a = [i*2+1 for i in range(1000)]
b = [i*2+2 for i in range(1000)]
x = [a, b]
y = [0, 0]
s = [0, 1]
t = [0, 1]
for i in range(2,70):
    s.append(s[i-1]+s[i-2]*2)
    t.append(2*t[i-1]+int(i%2==1))
s = s[2:]
l, r = map(int, input().split())
l -= 1
k = 0
i = 0
while True:
    if k + s[i] > l:
        break
    k += s[i]
    i += 1
c = l - k
if c > t[i] + 1:
    c -= t[i] + 1
    c = t[i] - c + 1
c -= 1
c = c*(c+1)//2
k = 0
i = 0
while True:
    if k + s[i] > r:
        break
    k += s[i]
    i += 1
d = r - k
if d > t[i] + 1:
    d -= t[i] + 1
    d = t[i] - d + 1
d -= 1
d = d*(d+1)//2
l += 1
x = ((l + r)*(r - l + 1)//2 + d - c) % (10**9+7)
print(x)
