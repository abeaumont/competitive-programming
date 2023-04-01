#!/usr/bin/env python3
# https://open.kattis.com/problems/temperatureconfusion
from math import gcd

a, b = map(int, input().split('/'))
a -= b * 32
a *= 5
b *= 9
g = gcd(a, b)
a //= g
b //= g
print(f'{a}/{b}')
