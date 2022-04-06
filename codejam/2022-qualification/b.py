#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
for t in range(int(input())):
    c, m, y, k = map(int, input().split())
    for _ in range(2):
        c2, m2, y2, k2 = map(int, input().split())
        c = min(c, c2)
        m = min(m, m2)
        y = min(y, y2)
        k = min(k, k2)
    if c + m + y + k < 10**6:
        print(f'Case #{t+1}: IMPOSSIBLE')
    else:
        sum = 0
        if sum + c > 10**6:
            c = 10**6 - sum
            m, y, k = 0, 0, 0
        else:
            sum += c
            if sum + m > 10**6:
                m = 10**6 - sum
                y, k = 0, 0
            else:
                sum += m
                if sum + y > 10**6:
                    y = 10**6 - sum
                    k = 0
                else:
                    sum += y
                    if sum + k > 10**6:
                        k = 10**6 - sum
        print(f'Case #{t+1}: {c} {m} {y} {k}')
