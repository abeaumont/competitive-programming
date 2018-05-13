#!/usr/bin/env python3
# https://uva.onlinejudge.org/external/101/10114.pdf
while True:
    [m, d, l, n] = input().split()
    [m, n] = map(int, [m, n])
    if m < 0: break
    dep = dict()
    for i in range(n):
        [a, b] = input().split()
        dep[int(a)] = float(b)
    [d, l] = map(float, [d, l])
    value = d + l
    topay = l
    pay = l / m
    depreciation = dep[0]
    value *= (1.0 - depreciation)
    i = 0
    while value <= topay:
        if i+1 in dep: depreciation = dep[i+1]
        value *= (1.0 - depreciation)
        topay -= pay
        i += 1
    if i == 1:
        print("1 month")
    else:
        print(i, 'months')
