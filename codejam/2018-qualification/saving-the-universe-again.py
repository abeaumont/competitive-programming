#!/usr/bin/env python3
# https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
for t in range(1, int(input()) + 1):
    d, s = input().split()
    s = [c for c in s]
    d = int(d)
    n = len(s)
    a = [1] * (n + 1)
    c = 0
    for i in range(1, n + 1):
        if s[i - 1] == 'C': a[i] *= 2
        else: c += a[i - 1]
        a[i] *= a[i - 1]
    k = n - 1
    e = 0
    while c > d and k > 0:
        if s[k] == 'S' and s[k - 1] == 'C':
            s[k], s[k - 1] = s[k - 1], s[k]
            c -= a[k] // 2
            a[k] //= 2
            e += 1
            k = n - 1
        else:
            k -= 1
    if c > d: e = 'IMPOSSIBLE'        
    print("Case #{}: {}".format(t, e))
