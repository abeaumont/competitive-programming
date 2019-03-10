#!/usr/bin/env python3
# https://abc102.contest.atcoder.jp/tasks/abc102_b
n = int(input())
a = [int(x) for x in input().split()]
a.sort()
print(a[-1] - a[0])
