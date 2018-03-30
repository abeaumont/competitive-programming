#!/usr/bin/env python3
# https://abc068.contest.atcoder.jp/tasks/abc068_b
n = int(input())
k = 1
while k * 2 <= n: k *= 2
print(k)
