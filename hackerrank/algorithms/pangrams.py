#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/pangrams
if len(set(raw_input().lower())) == 27:
    print "pangram"
else:
    print "not pangram"
