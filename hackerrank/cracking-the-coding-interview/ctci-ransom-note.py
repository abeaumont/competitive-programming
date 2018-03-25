#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ctci-ransom-note
from collections import Counter

def ransom_note(magazine, ransom):
    m = Counter(magazine)
    for k, v in Counter(ransom).iteritems():
        if m[k] < v: return False
    return True

m, n = map(int, raw_input().strip().split(' '))
magazine = raw_input().strip().split(' ')
ransom = raw_input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
    print "Yes"
else:
    print "No"
