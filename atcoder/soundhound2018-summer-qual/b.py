#!/usr/bin/env python3
# https://soundhound2018-summer-qual.contest.atcoder.jp/tasks/soundhound2018_summer_qual_b
s = input()
n = int(input())
print(''.join([s[i] for i in range(0, len(s), n)]))
