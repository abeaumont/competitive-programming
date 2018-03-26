#!/usr/bin/env python3
# https://abc053.contest.atcoder.jp/tasks/arc068_a
x = int(input())
print(x // 11 * 2 + int(x % 11 > 6) + int(x % 11 > 0))
