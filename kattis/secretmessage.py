#!/usr/bin/env python2
# https://open.kattis.com/problems/secretmessage
import math

def e(s):
    l = len(s)
    k = int(math.ceil(math.sqrt(l)))
    m = k * k
    s = s + '*' * (m - k)
    M = []
    for i in range(k):
        M.append(s[i*k:(i+1)*k])
    Mt = [None] * k
    for i in range(k):
        Mt[i] = [None] * k
        for j in range(k):
            Mt[i][j] = M[k-j-1][i]
    Mt = map(lambda row: filter(lambda x: x != '*', row), Mt)
    return ''.join(map(lambda x: ''.join(x), Mt))

for i in range(input()):
    print e(raw_input())
