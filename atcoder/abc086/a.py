#!/usr/bin/env python2
# https://abc086.contest.atcoder.jp/tasks/abc086_a
[a, b] = map(int, raw_input().split())
if (a * b) % 2 == 0:
    print 'Even'
else:
    print 'Odd'
