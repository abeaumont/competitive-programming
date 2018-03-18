#!/usr/bin/env python2
# https://open.kattis.com/problems/oddities
for i in range(input()):
    a = input()
    if a % 2 == 0:
        print '{} is even'.format(a)
    else:
        print '{} is odd'.format(a)
