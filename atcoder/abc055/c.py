#!/usr/bin/env python3
# https://abc055.contest.atcoder.jp/tasks/arc069_a
n, m = map(int, input().split())
if n > m // 2: print(m // 2)
else: print((n * 2 + m) // 4)
