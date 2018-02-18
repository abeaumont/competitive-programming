# https://www.hackerrank.com/contests/womenscup/challenges/possible-maximum
for _ in range(input()):
    n, k = map(int, raw_input().split())
    m = 0
    for i in xrange(1, n + 1):
        for j in xrange(i + 1, n + 1):
            if i & j < k:
                m = max(m, i & j)
    print m
