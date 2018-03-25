#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ctci-array-left-rotation
def array_left_rotation(a, n, k):
    return a[k:] + a[:k]

n, k = map(int, raw_input().strip().split(' '))
a = map(int, raw_input().strip().split(' '))
answer = array_left_rotation(a, n, k);
print ' '.join(map(str,answer))
