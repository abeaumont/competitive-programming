#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/the-minion-game
x = [0, 0]
s = raw_input()
for i, c in enumerate(s):
    x[c in 'AEIOU'] += len(s) - i
if x[0] == x[1]: print 'Draw'
elif x[0] > x[1]: print 'Stuart', x[0]
else: print 'Kevin', x[1]
