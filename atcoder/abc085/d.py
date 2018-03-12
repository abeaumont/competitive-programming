# https://abc085.contest.atcoder.jp/tasks/abc085_d
import sys

[n, h] = map(int, raw_input().split())
xs = []
for _ in range(n):
    [a, b] = map(int, raw_input().split())
    xs.append((a, 1))
    xs.append((b, 0))
xs.sort(reverse=True)
c = 0
for (a, b) in xs:
    if b == 0:
        h -= a
        c += 1
        if h <= 0:
            print c
            sys.exit(0)
    else:
        d = h // a
        c += d
        h -= d * a
        if h > 0: c += 1
        print c
        sys.exit(0)
