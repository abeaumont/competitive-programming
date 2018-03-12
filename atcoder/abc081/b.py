# https://abc081.contest.atcoder.jp/tasks/abc081_b
n = input()
xs = map(int, raw_input().split())
m = 2000000000
for i in range(n):
    x = xs[i]
    c = 0
    while x % 2 == 0 and c < m:
        x = x / 2
        c += 1
    m = min(c, m)
print m
