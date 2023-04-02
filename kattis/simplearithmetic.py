#!/usr/bin/env python3
# https://open.kattis.com/problems/simplearithmetic
a, b, c = map(int, input().split())
n = a * b * 10**30
c *= 10
result = str(n//c)
if len(result) < 30:
    result = '0' * (30 - len(result)) + result
result = result[:-29] + '.' + result[-29:]
print(result)
