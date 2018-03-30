#!/usr/bin/env python3
# https://abc066.contest.atcoder.jp/tasks/abc066_b
s = input()
for i in range((len(s) - 1) // 2 , -1, -1):
    if s[:i] == s[i:2*i]:
        print(2*i)
        break