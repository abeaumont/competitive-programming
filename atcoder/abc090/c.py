#!/usr/bin/env python2
# https://abc090.contest.atcoder.jp/tasks/arc091_a
n, m = map(int, raw_input().split())
if n + m == 2: print 1
elif n + m == 3: print 0
elif n == 1: print m - 2
elif m == 1: print n - 2
else: print (n - 2) * (m - 2)
