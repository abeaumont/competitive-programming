# https://abc081.contest.atcoder.jp/tasks/arc086_b
import math

def a(xs, m):
    k = xs.index(m) + 1
    ops = []
    a = xs[0];
    for i in range(1, len(xs)):
        b = xs[i]
        if a > b:
            d = a - b
            n = int(math.ceil(d / float(m)))
            d2 = m - b
            n2 = int(math.ceil(d2 / float(m)))
            if n2 > 0 and n2 < n:
                b += n2 * m
                ops.append((k, i + 1, n2))
                k = i + 2
                m = b
                d = b - a
                n = int(math.ceil(d / float(m)))
            b += n * m
            ops.append((k, i + 1, n))
        a = b
    return ops

def b(xs, m):
    k = xs.index(m) + 1
    ops = []
    a = xs[-1]
    for i in range(len(xs) - 2, -1, -1):
        b = xs[i]
        if a < b:
            d = a - b
            n = int(math.ceil(d / float(m)))
            d2 = m - b
            n2 = int(math.ceil(d2 / float(m)))
            if n2 > 0 and n2 < n:
                b += n2 * m
                ops.append(k, i, n2)
                k = i + 1
                m = b
                d = a - b
                n = int(math.ceil(d / float(m)))
            b += n * m
            ops.append((k, i, n))
        a = b
    return ops

n = input()
xs = map(int, raw_input().split())
M = max(xs)
m = min(xs)
if M > 0 and m >= 0:
    ops = a(xs, M)
    c = len(ops)
elif M <= 0 and m < 0:
    ops = b(xs, m)
    c = len(ops)
else:
    ops1 = a(xs, M)
    ops2 = b(xs, m)
    c1 = 0
    for _, _, n in ops1: c1 += n
    c2 = 0
    for _, _, n in ops2: c2 += n
    if c1 <= c2:
        ops = ops1
        c = c1
    else:
        ops = ops2
        c = c2
print c
for a, b, n in ops:
    for _ in range(n):
        print a, b
