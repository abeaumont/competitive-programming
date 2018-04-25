#!/usr/bin/env python3
for t in range(int(input())):
    n = len(input())
    x = [i for i in range(n)]
    y = list(reversed(x))
    x[0], x[1] = x[1], x[0]
    x = map(lambda k: chr(ord('a') + k - 10) if k > 9 else k, x)
    y = map(lambda k: chr(ord('a') + k - 10) if k > 9 else k, y)
    x = ''.join(map(str, x))
    y = ''.join(map(str, y))
    print('Case #{}: {}'.format(t + 1, int(y, n) - int(x, n)))
