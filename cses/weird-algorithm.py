#!/usr/bin/env python2
n = input()
while n > 1:
    print n,
    n = n * 3 + 1 if n % 2 else n / 2
print 1
