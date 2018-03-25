#!/usr/bin/env python3
# https://abc092.contest.atcoder.jp/tasks/abc092_b
n = int(input())
d, x = map(int, input().split())
for _ in range(n):
  a = int(input())
  x += (d - 1) // a + 1
print(x)
