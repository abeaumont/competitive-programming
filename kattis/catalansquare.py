#!/usr/bin/env python2
# https://open.kattis.com/problems/catalansquare
def c(n):
    a = 1
    b = 1
    for i in xrange(n + 1, 2 * n + 1): a *= i
    for i in xrange(1, n + 1): b *= i
    return a / b / (n + 1)

print c(input() +1)
