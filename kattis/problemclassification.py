# https://open.kattis.com/problems/problemclassification
import sys
import collections

d = {}
c = {}
for _ in range(input()):
    fs = raw_input().split()
    c[fs[0]] = 0
    for f in fs[2:]:
        if f in d.keys(): d[f].append(fs[0])
        else: d[f] = [fs[0]]
m = 0
for w in sys.stdin.read().split():
    for f in d.get(w, []):
        c[f] += 1
        m = max(c[f], m)
a = sorted([x for x, i in c.iteritems() if i == m])
for x in a: print x
