#!/usr/bin/env python3
# https://abc052.contest.atcoder.jp/tasks/abc052_b
_ = input()
s = input()
x, m = 0, 0
for c in s:
    if c == 'I':
        x += 1
        m = max(x, m)
    else:
        x -= 1
print(m)