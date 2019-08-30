#!/usr/bin/env python3
# https://cses.fi/problemset/task/1643/
i = input
i()
s = m =-2e9
for x in map(int, i().split()):
    s = max(x, s + x)
    m = max(s, m)
print(m)
