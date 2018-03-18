#!/usr/bin/env python2
# https://open.kattis.com/problems/collatz
def collatz(x):
    hs = []
    while x > 1:
        hs.append(x)
        if x % 2 == 0:
            x /= 2
        else:
            x = x * 3 + 1
    return hs

while True:
    [a, b] = map(int, raw_input().split())
    if a == 0 and b == 0: break
    [hsa, hsb] = map(lambda x: collatz(x), [a, b])
    hsa.reverse()
    hsb.reverse()
    i = 0
    while True:
        if i == len(hsa) or i == len(hsb):
            break
        elif hsa[i] == hsb[i]:
            i += 1
        else:
            break
    print "{} needs {} steps, {} needs {} steps, they meet at {}".format(a, len(hsa) - i, b, len(hsb) - i, hsa[i - 1] if i > 0 else 1)
