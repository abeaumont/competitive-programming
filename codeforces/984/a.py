#!/usr/bin/env python3
# http://codeforces.com/contest/984/problem/A
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
print(a[(n-1)//2])
