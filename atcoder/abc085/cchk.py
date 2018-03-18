#!/usr/bin/env python2
[n, y] = map(int, open('c.in').readline().split())
[a, b, c] = map(int, open('c.out').read().split())
if a + b + c == n and a * 10000 + b * 5000 + c * 1000 == y:
    print "OK"
else:
    print "ERROR"
    print open('c.in').read()
    print open('c.out').read()
