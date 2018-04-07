#!/usr/bin/env python3
m = None
s = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    s += a
    if a == b: continue
    if a > b:
        if m is None or b < m: m = b
print(0 if m is None else s - m)
