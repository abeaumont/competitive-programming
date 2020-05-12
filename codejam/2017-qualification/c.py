#!/usr/bin/env python2
# https://codingcompetitions.withgoogle.com/codejam/round/00000000002017f7/0000000000201905
def next(n, k):
    if k == 1:
        return (n / 2, (n - 1) / 2)
    if n % 2 == 0 and k % 2 == 1:
        return next(n / 2 - 1, k / 2)
    return next(n / 2, k / 2)

for i in range(input()):
    [n, k] = map(int, raw_input().split(' '))
    (max, min) = next(n, k)
    print "Case #{}: {} {}".format(i + 1, max, min)
