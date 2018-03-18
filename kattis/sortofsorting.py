#!/usr/bin/env python2
# https://open.kattis.com/problems/sortofsorting
init = True
while True:
    n = input()
    if n == 0: break
    s = [raw_input() for _ in range(n)]
    s.sort(cmp=lambda x, y: cmp(x[:2], y[:2]))
    if init: init = False
    else: print ''
    for x in s: print x
