#!/usr/bin/env python2
# https://abc078.contest.atcoder.jp/tasks/abc078_a
x, y = raw_input().split()
if x > y:
    print '>'
elif x < y:
    print '<'
else:
    print '='
