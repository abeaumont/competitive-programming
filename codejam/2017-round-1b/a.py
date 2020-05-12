#!/usr/bin/env python2
# https://codingcompetitions.withgoogle.com/codejam/round/000000000020187f/000000000020190e
def c(d, xs):
    return min(map(lambda x: d / (float(d - x[0]) / x[1]), xs))

for i in range(input()):
    [d, n] = map(int, raw_input().split())
    r = c(d, [map(int, raw_input().split()) for _ in range(n)])
    print "Case #{}: {}".format(i + 1, r)
