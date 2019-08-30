#!/usr/bin/env python3
# https://cses.fi/problemset/task/1083
n = int(input())
print(n * (n + 1) // 2 - sum(map(int, input().split())))
