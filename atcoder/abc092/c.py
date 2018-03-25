#!/usr/bin/env python3
# https://abc092.contest.atcoder.jp/tasks/arc093_a
n = int(input())
a = [0] + list(map(int, input().split())) + [0]
c = 0
for i in range(1, len(a)): c += abs(a[i] - a[i - 1])
for i in range(1, len(a) - 1):
  print(c - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i - 1]))
