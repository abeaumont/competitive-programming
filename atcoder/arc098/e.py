#!/usr/bin/env python3
# https://arc098.contest.atcoder.jp/tasks/arc098_c
n, k, q = map(int, input().split())
a = [int(x) for x in input().split()]
m = None
for x in a:
    b = []
    c = []
    for y in a:
        if y < x:
            if len(c) >= k:
                c.sort()
                b.extend(c[:len(c) - k + 1])
            c = []
        else:
            c.append(y)
    if len(c) >= k:
        c.sort()
        b.extend(c[:len(c) - k + 1])
    if len(b) >= q:
        b.sort()
        if m is None or m > b[q - 1] - x: m = b[q - 1] - x
print(m)
