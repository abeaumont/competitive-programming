#!/usr/bin/env python3
# https://codeforces.com/contest/1/problem/A
m, n, a = map(int, input().split())
print(((m - 1) // a + 1) * ((n - 1) // a + 1))
