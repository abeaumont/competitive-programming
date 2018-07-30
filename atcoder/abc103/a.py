#!/usr/bin/env python3
# https://abc103.contest.atcoder.jp/tasks/abc103_a
a = [int(x) for x in input().split()]
a.sort()
print(a[1] - a[0] + a[2] - a[1])
