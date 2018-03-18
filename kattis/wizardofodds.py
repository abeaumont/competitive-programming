#!/usr/bin/env python2
# https://open.kattis.com/problems/wizardofodds
[n, k] = map(int, raw_input().split())
i = 0
while n > 1:
    i += 1
    n = (n + 1) / 2
if i <= k: print 'Your wish is granted!'
else: print 'You will become a flying monkey!'
