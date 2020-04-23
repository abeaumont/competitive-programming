#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ginorts
print(*sorted(input(), key=lambda c: (-ord(c) >> 5, c in '02468', c)), sep='')
