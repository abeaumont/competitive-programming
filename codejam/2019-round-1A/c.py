#!/usr/bin/env python3
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104e05
for T in range(int(input())):
    n = int(input())
    ws = [None] * n
    for i in range(n):
        ws[i] = input()[::-1]
    d = dict()
    for i in range(n):
        for k in range(1, len(ws[i])+1):
            s = ws[i][:k]
            d[s] = d.get(s, 0) + 1
    xs = [(k, v) for k, v in d.items()]
    xs.sort(key=lambda x: -len(x[0]))
    c = 0
    for k, _ in xs:
        if d[k] >= 2:
            c += 2
            for i in range(1, len(k)):
                d[k[:i]] -= 2
    print('Case #{}: {}'.format(T + 1, c))
