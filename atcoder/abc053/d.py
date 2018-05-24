#!/usr/bin/env python3
# https://abc053.contest.atcoder.jp/tasks/arc068_b
n = int(input())
c = len(set([int(x) for x in input().split()]))
if (n - c) % 2 == 1: c -= 1
print(c)
