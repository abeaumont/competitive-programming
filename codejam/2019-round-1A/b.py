#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104f1a
from functools import reduce


def chinese_remainder(n, a):
    sum = 0
    prod = reduce(lambda a, b: a*b, n)
    for n_i, a_i in zip(n, a):
        p = prod // n_i
        sum += a_i * mul_inv(p, n_i) * p
    return sum % prod


def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1:
        return 1
    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += b0
    return x1


if __name__ == '__main__':
    t, n, m = map(int, input().split())
    for _ in range(t):
        xs = [3, 4, 5, 7, 11, 13, 17]
        ys = []
        r = '-1'
        for x in xs:
            print(' '.join([str(x)] * 18))
            r = input()
            if r == '-1':
                break
            ys.append(sum(int(x) for x in r.split()) % x)
        if r == '-1':
            break
        print(chinese_remainder(xs, ys))
        if input() == '-1':
            break
