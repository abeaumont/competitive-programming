#!/usr/bin/env python3
# https://abc067.contest.atcoder.jp/tasks/abc067_b
n, k = map(int, input().split())
l = [int(x) for x in input().split()]
l.sort(reverse=True)
print(sum(l[:k]))
