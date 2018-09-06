#!/usr/bin/env python3
# https://codeforces.com/contest/1040/problem/B
n, k = map(int, input().split())
x = 2*k+1
r = (n - 1) // x + 1
d = r*x-n
s = max(1, k+1-d)
print(r)
print(' '.join([str(s+x*i) for i in range(r)]))
