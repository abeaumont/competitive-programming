#!/usr/bin/env python3
# https://agc001.contest.atcoder.jp/tasks/agc001_a
n = int(input())
l = [int(x) for x in input().split()]
l.sort()
print(sum(l[::2]))
