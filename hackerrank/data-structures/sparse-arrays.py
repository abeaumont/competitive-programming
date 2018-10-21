#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/sparse-arrays
from collections import Counter
c=Counter([input() for _ in range(int(input()))])
for _ in range(int(input())):
    print(c[input()])
