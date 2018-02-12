# https://www.hackerrank.com/challenges/ginorts
from __future__ import print_function
import string

def compare(a, b):
    s = string.lowercase
    if a in s and b in s: return cmp(a, b)
    if a in s: return -1
    if b in s: return 1
    s = string.uppercase
    if a in s and b in s: return cmp(a, b)
    if a in s: return -1
    if b in s: return 1
    s = '13579'
    if a in s and b in s: return cmp(a, b)
    if a in s: return -1
    if b in s: return 1
    return cmp(a, b)

print(*sorted(raw_input(), cmp=compare), sep='')
