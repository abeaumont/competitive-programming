#!/usr/bin/env python3
# https://abc075.contest.atcoder.jp/tasks/abc075_a
a, b, c = map(int, input().split())
if a == b: print(c)
elif a == c: print(b)
else: print(a)
