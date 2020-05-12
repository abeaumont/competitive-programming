#!/usr/bin/env python2
# https://codingcompetitions.withgoogle.com/codejam/round/00000000002017f7/0000000000201878
def next(x):
    digits = map(int, str(x))
    for i in range(len(digits) - 1):
        if digits[i] > digits[i + 1]:
            digits[i] -= 1
            for j in range(i + 1, len(digits)):
                digits[j] = 9
            return (False, int(''.join(map(str, digits))))
    return (True, x)

for i in range(input()):
    n = input()
    (valid, n) = next(n)
    while not valid: (valid, n) = next(n)
    print 'Case #{}: {}'.format(i + 1, n)
