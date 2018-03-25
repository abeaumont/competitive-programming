#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ctci-making-anagrams
def number_needed(a, b):
    a = sorted(a)
    b = sorted(b)
    i = j = n = 0
    while True:
        if i == len(a): return n + len(b) - j
        if j == len(b): return n + len(a) - i
        if a[i] == b[j]:
            i += 1
            j += 1
        elif a[i] < b[j]:
            n += 1
            i += 1
        else:
            n += 1
            j += 1

a = raw_input().strip()
b = raw_input().strip()

print number_needed(a, b)
