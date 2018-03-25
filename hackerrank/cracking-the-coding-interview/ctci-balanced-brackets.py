#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ctci-balanced-brackets
def is_matched(expression):
    open = []
    for c in expression:
        try:
            index = ['}', ')', ']'].index(c)
            if not open or open.pop() != ['{', '(', '['][index]:
                return False
        except:
            if c in ['{', '(', '[']:
                open.append(c)
    return not open

t = int(raw_input().strip())
for a0 in xrange(t):
    expression = raw_input().strip()
    if is_matched(expression) == True:
        print "YES"
    else:
        print "NO"
