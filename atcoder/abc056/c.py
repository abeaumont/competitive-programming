#!/usr/bin/env python3
# https://abc056.contest.atcoder.jp/tasks/arc070_a
x = int(input())
i = 1
while i * (i + 1) // 2 < x: i += 1
print(i)
