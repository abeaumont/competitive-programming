#!/usr/bin/env python2
# https://codingcompetitions.withgoogle.com/codejam/round/00000000002017f7/0000000000201847
swap = lambda s: ''.join(('+' if i == ord('-') else '-') for i in s)

for z in range(input()):
    [s, k] = raw_input().split(' ')
    s = bytearray(s)
    k = int(k)
    c = 0
    for i in range(len(s) - k + 1):
        if s[i] == ord('-'):
            s[i:i+k] = swap(s[i:i+k])
            c += 1
    if s[-k:] == '+' * k:
        print "Case #{}: {}".format(z + 1, c)
    else:
        print "Case #{}: IMPOSSIBLE".format(z + 1)
