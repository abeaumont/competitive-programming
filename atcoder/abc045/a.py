#!/usr/bin/env python3
# https://abc045.contest.atcoder.jp/tasks/abc045_a
[a, b, h] = [int(input()) for _ in range(3)]
print(a * h + (b - a) * h // 2)
