#!/usr/bin/env python3
# https://abc059.contest.atcoder.jp/tasks/arc072_a
def k(n, a, p):
    x = 0
    c = 0
    for i in range(n):
        s = x + a[i]
        if p and s > 0 or not p and s < 0: x = s
        else:
            c += abs(s) + 1
            if p: x = 1
            else: x = -1
        p = not p
    return c

n = int(input())
a = [int(x) for x in input().split()]
print(min(k(n, a, True), k(n, a, False)))
