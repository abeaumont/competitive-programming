#!/usr/bin/env python3
# https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_c
n, m, d = map(int, input().split())
if d == 0: print('{:.10f}'.format((m - 1) / n))
else:
    t = n * (n - 1) // 2
    print('{:.10f}'.format((m - 1) * (n - 1) * (n - d) / (t * n)))
